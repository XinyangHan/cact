#include <iostream>
#include <fstream>
#include "symbolTable.h"
#include "CACTLexer.h"
#include "CACTParser.h"
#include "analysis.h"
#include "irGenerator.h"
#include "irInterpret.h"
#include "asmGenerator.h"

using namespace antlr4;
Env *Env::instance = nullptr;
int IRGloblVar::globlVarNum = 0;
int IRLocalVar::localVarNum = 0;
int IRImmediate::immediateNum = 0;
int IRTemp::tempNum = 0;
int IRLabel::labelNum = 0;
char *asmFileName;
char *irFileName;
char *verboseFileName;
int optVersion;

int main(int argc, const char* argv[]) {
  std::ifstream stream;
  if  (argc == 2)
    stream.open(argv[1]);
  else
    stream.open(argv[2]);

  ANTLRInputStream   input(stream);
  CACTLexer         lexer(&input);
  CommonTokenStream  tokens(&lexer);
  CACTParser        parser(&tokens);

  Analysis visitor;
  antlr4::tree::ParseTree *root = parser.start();
  
  if (lexer.getNumberOfSyntaxErrors() || parser.getNumberOfSyntaxErrors() > 0) {
      std::cerr << "syntax error!" << std::endl;
      return 1;
  }

  Env *env = Env::getInstance();
  visitor.env = env;
  visitor.irGenerator  = new IRGenerator();
  visitor.irInterpretor = new IRInterpretor();
  visitor.asmGenerator = new AsmGenerator();

  for (int i = 0; i < argc; i++) {
    if (std::strcmp(argv[i], "-emit-IR") == 0) {
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
      std::string str = std::string("interpret.txt");
      verboseFileName = new char[str.length() + 1];
      std::strcpy(verboseFileName, str.c_str()); 
    }
    else if (std::strcmp(argv[i], "-verbose") == 0) {
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
      optVersion = argv[i][2] - '0';
    }
  }
  std::string oriStr;
  if  (argc == 2)
    oriStr = std::string(argv[1]);
  else
    oriStr = std::string(argv[2]);
  if (oriStr.find('/') != std::string::npos) {
    int posBegin = oriStr.find_last_of('/')+1;
    int posEnd   = oriStr.find_last_of('.');
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
      visitor.visit( root );
  }
  catch (std::runtime_error &e){
      std::cerr << "semantics error!" << std::endl;
      std::cerr << e.what() << std::endl;
      return 1;
  }

  std::vector<BasicBlock*> basicBlockList;
  if (optVersion == 0) {
    visitor.asmGenerator->opt = 0;
    basicBlockList = visitor.irGenerator->O0();
  }
  else {
    visitor.asmGenerator->opt = 1;
    basicBlockList = visitor.irGenerator->O1();
  }

  if (irFileName != nullptr) {
    std::ofstream irCodeFile;
    irCodeFile.open(irFileName);
    visitor.irGenerator->printIRCode(irCodeFile, optVersion);
    irCodeFile.close();
  }
  
  if (verboseFileName != nullptr) {
    std::ofstream interpretFile;
    interpretFile.open(verboseFileName);
    visitor.irInterpretor->interpretIRCode(interpretFile, visitor.irGenerator->irCodeList, visitor.irGenerator->immediatePool);
    interpretFile.close();
  }

  if (asmFileName != nullptr) {
    std::ofstream asmCodeFile;
    asmCodeFile.open(asmFileName);
    visitor.asmGenerator->invokeAsmGene(asmCodeFile, basicBlockList);
    asmCodeFile.close();
  }
  return 0;
}