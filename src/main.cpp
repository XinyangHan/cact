#include <iostream>
#include <fstream>
#include "include/analysis/symTable.h"
#include "CACTLexer.h"
#include "CACTParser.h"
#include "include/analysis/analysis.h"
#include "include/ir/generator.h"
#include "include/ir/Interpret.h"
#include "include/asm/rvGen.h"

using namespace antlr4;
Environment *Environment::instance = nullptr;
int IrGlobalVariable::globlVarNum = 0;
int IRLocalVar::localVarNum = 0;
int IRImmediateValue::immediateNum = 0;
int TemporaryValue::tempNum = 0;
int IRLabel::labelNum = 0;
char *asmFileName;
char *irFileName;
char *verboseFileName;
int optVersion;

template<typename T>
bool isNotNull(T* ptr) {
    return ptr != nullptr;
}

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    // 打开输入文件
    if (argc == 2)
        stream.open(argv[1]);
    else
        stream.open(argv[2]);

    ANTLRInputStream input(stream);  // 创建输入流
    CACTLexer lexer(&input);         // 创建词法分析器
    CommonTokenStream tokens(&lexer); // 创建词法符号流
    CACTParser parser(&tokens);      // 创建语法分析器

    Analyzer visitor;                // 创建分析器访问者
    antlr4::tree::ParseTree *root = parser.start(); // 解析输入并生成语法树

    // 检查词法和语法错误
    if (lexer.getNumberOfSyntaxErrors() || parser.getNumberOfSyntaxErrors() > 0) {
        std::cerr << "syntax error!" << std::endl;
        return 1;
    }

    Environment *env = Environment::getInstance();  // 获取环境实例
    visitor.env = env;              // 设置访问者的环境
    visitor.irGenerator = new IntermediateCodeGenerator();  // 创建IR生成器
    visitor.irInterpretor = new IntermediateInterpreter(); // 创建IR解释器
    visitor.AssemblyGenerator = new AssemblyCodeGenerator(); // 创建汇编生成器

    // 处理命令行参数
    for (int i = 0; i < argc; i++) {
        if (std::strcmp(argv[i], "-emit-IR") == 0) {
            // 处理IR输出文件名
            if (i+1 < argc && argv[i+1][0] != '-') {
                std::string str = std::string(argv[i+1]);
                irFileName = new char[str.length() + 1];
                std::strcpy(irFileName, str.c_str());
                i++;
            }
            else {
                std::string oriStr = std::string(argv[1]);
                std::string str = oriStr.substr(0, oriStr.find('.')) + std::string("_IR.txt");
                irFileName = new char[str.length() + 1];
                std::strcpy(irFileName, str.c_str());
            }
        }
        else if (std::strcmp(argv[i], "-simulate") == 0) {
            // 处理模拟文件名
            std::string str = std::string("interpret.txt");
            verboseFileName = new char[str.length() + 1];
            std::strcpy(verboseFileName, str.c_str());
        }
        else if (std::strcmp(argv[i], "-verbose") == 0) {
            // 处理详细输出文件名
            if (i+1 < argc && argv[i+1][0] != '-') {
                std::string str = std::string(argv[i+1]);
                verboseFileName = new char[str.length() + 1];
                std::strcpy(verboseFileName, str.c_str());
                i++;
            }
            else {
                std::string oriStr = std::string(argv[1]);
                std::string str = oriStr.substr(0, oriStr.find('.')) + std::string("_verbose.txt");
                verboseFileName = new char[str.length() + 1];
                std::strcpy(verboseFileName, str.c_str());
            }
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'O') {
            // 处理优化级别
            optVersion = argv[i][2] - '0';
        }
    }

    std::string oriStr;
    if (argc == 2)
        oriStr = std::string(argv[1]);
    else
        oriStr = std::string(argv[2]);

    // 处理汇编文件名
    if (oriStr.find('/') != std::string::npos) {
        int posBegin = oriStr.find_last_of('/')+1;
        int posEnd = oriStr.find_last_of('.');
        std::string str = oriStr.substr(posBegin, posEnd-posBegin) + std::string(".s");
        asmFileName = new char[str.length() + 1];
        std::strcpy(asmFileName, str.c_str());
    }
    else {
        std::string oriStr = std::string(argv[1]);
        std::string str = oriStr.substr(0, oriStr.find('.')) + std::string(".s");
        asmFileName = new char[str.length() + 1];
        std::strcpy(asmFileName, str.c_str());
    }

    try {
        visitor.visit(root); // 访问语法树
    }
    catch (std::runtime_error &e) {
        std::cerr << "semantics error!" << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::vector<BasicBlock*> basicBlockList;
    if (optVersion == 0) {
        visitor.AssemblyGenerator->opt = 0;
        basicBlockList = visitor.irGenerator->O0(); // 无优化生成IR
    }
    else {
        visitor.AssemblyGenerator->opt = 1;
        basicBlockList = visitor.irGenerator->O1(); // 优化生成IR
    }

    // 输出IR代码
    if (isNotNull(irFileName)) {
        std::ofstream irCodeFile;
        irCodeFile.open(irFileName);
        visitor.irGenerator->logIrCode(irCodeFile, optVersion);
        irCodeFile.close();
    }

    // 输出解释结果
    if (isNotNull(verboseFileName)) {
        std::ofstream interpretFile;
        interpretFile.open(verboseFileName);
        visitor.irInterpretor->interpretIntermediateCode(interpretFile, visitor.irGenerator->irCodeList, visitor.irGenerator->immediatePool);
        interpretFile.close();
    }

    // 输出汇编代码
    if (isNotNull(asmFileName)) {
        std::ofstream asmFile;
        asmFile.open(asmFileName);
        visitor.AssemblyGenerator->executeAssemblyGene(asmFile, basicBlockList);
        asmFile.close();
    } 

    return 0; 
}
