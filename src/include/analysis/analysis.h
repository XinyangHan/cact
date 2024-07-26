#include "CACTBaseVisitor.h" // 包含CACTBaseVisitor头文件
#include "symTable.h" // 包含symTable头文件
#include "include/ir/generator.h" // 包含IR生成器头文件
using namespace antlr4; // 使用antlr4命名空间

class IntermediateInterpreter; // 声明IntermediateInterpreter类

class Analyzer : public CACTBaseVisitor { // Analyzer类，继承自CACTBaseVisitor
    public:
    class WhileCtx { // WhileCtx类的定义
        public:
        WhileCtx *preWhileCtx; // 上一个While上下文指针
        IROperand *breakDst; // 终止目标操作数
        IROperand *contDst; // 继续目标操作数
        
        // 构造函数，初始化上一个While上下文指针、终止目标操作数和继续目标操作数
        WhileCtx(WhileCtx *preWhileCtx, IROperand *breakDst, IROperand *contDst) {
            this->preWhileCtx = preWhileCtx;
            this->breakDst = breakDst;
            this->contDst = contDst;
        }
    };
    
    WhileCtx *currWhile = nullptr; // 当前While上下文指针
    Environment *env; // 环境指针
    IntermediateCodeGenerator *irGenerator; // IR生成器指针
    IntermediateInterpreter *irInterpretor; // IR解释器指针
    AssemblyCodeGenerator *AssemblyGenerator; // 汇编代码生成器指针
    
    std::any visitBegin(CACTParser::StartContext *ctx) override; // 访问起始节点
    std::any visitConstDecl(CACTParser::ConstDeclContext *ctx) override; // 访问常量声明节点
    std::any visitConstDef(CACTParser::ConstDefContext *ctx) override; // 访问常量定义节点
    std::any visitVarDecl(CACTParser::VarDeclContext *ctx) override; // 访问变量声明节点
    std::any visitVarDef(CACTParser::VarDefContext *ctx) override; // 访问变量定义节点
    std::any visitConstInitValBasic(CACTParser::ConstInitValBasicContext *ctx) override; // 访问基本常量初始化值节点
    std::any visitConstInitValNested(CACTParser::ConstInitValNestedContext *ctx) override; // 访问嵌套常量初始化值节点
    std::any visitConstExp(CACTParser::ConstExpContext *ctx) override; // 访问常量表达式节点
    std::any visitInitNum(CACTParser::InitNumContext *ctx) override; // 访问初始化数值节点
    std::any visitFuncType(CACTParser::FuncTypeContext *ctx) override; // 访问函数类型节点
    std::any visitFuncDef(CACTParser::FuncDefContext *ctx) override; // 访问函数定义节点
    std::any visitFuncFParam(CACTParser::FuncFParamContext *ctx) override; // 访问函数形式参数节点
    std::any visitBType(CACTParser::BTypeContext *ctx) override; // 访问基本类型节点
    std::any visitFuncBlock(CACTParser::FuncBlockContext *ctx) override; // 访问函数代码块节点
    std::any visitBlock(CACTParser::BlockContext *ctx) override; // 访问代码块节点
    std::any visitBlockItemDecl(CACTParser::BlockItemDeclContext *ctx) override; // 访问代码块项声明节点
    std::any visitBlockItemStmt(CACTParser::BlockItemStmtContext *ctx) override; // 访问代码块项语句节点
    std::any visitNum(CACTParser::NumContext *ctx) override; // 访问数值节点
    std::any visitPriExpNum(CACTParser::PriExpNumContext *ctx) override; // 访问数值主表达式节点
    std::any visitPriExpNested(CACTParser::PriExpNestedContext *ctx) override; // 访问嵌套主表达式节点
    std::any visitPriExpLval(CACTParser::PriExpLvalContext *ctx) override; // 访问左值主表达式节点
    std::any visitLVal(CACTParser::LValContext *ctx) override; // 访问左值节点
    std::any visitUnaryExppri(CACTParser::UnaryExppriContext *ctx) override; // 访问一元表达式节点（主表达式）
    std::any visitUnaryExpuna(CACTParser::UnaryExpunaContext *ctx) override; // 访问一元表达式节点（取反）
    std::any visitUnaryExpfun(CACTParser::UnaryExpfunContext *ctx) override; // 访问一元表达式节点（函数调用）
    std::any visitFuncRParams(CACTParser::FuncRParamsContext *ctx) override; // 访问函数实参节点
    std::any visitMulExpmul(CACTParser::MulExpmulContext *ctx) override; // 访问乘法表达式节点
    std::any visitMulExpuna(CACTParser::MulExpunaContext *ctx) override; // 访问乘法表达式节点（取反）
    std::any visitAddExpadd(CACTParser::AddExpaddContext *ctx) override; // 访问加法表达式节点
    std::any visitAddExpmul(CACTParser::AddExpmulContext *ctx) override; // 访问加法表达式节点（乘法）
    std::any visitExp(CACTParser::ExpContext *ctx) override; // 访问表达式节点
    std::any visitStmtAssign(CACTParser::StmtAssignContext *ctx) override; // 访问赋值语句节点
    std::any visitStmtExp(CACTParser::StmtExpContext *ctx) override; // 访问表达式语句节点
    std::any visitStmtBlock(CACTParser::StmtBlockContext *ctx) override; // 访问代码块语句节点
    std::any visitStmtReturn(CACTParser::StmtReturnContext *ctx) override; // 访问返回语句节点
    std::any visitStmtIf(CACTParser::StmtIfContext *ctx) override; // 访问if语句节点
    std::any visitStmtIfElse(CACTParser::StmtIfElseContext *ctx) override; // 访问if-else语句节点
    std::any visitStmtWhile(CACTParser::StmtWhileContext *ctx) override; // 访问while语句节点
    std::any visitStmtBreak(CACTParser::StmtBreakContext *ctx) override; // 访问break语句节点
    std::any visitStmtContinue(CACTParser::StmtContinueContext *ctx) override; // 访问continue语句节点
    std::any visitLOrExpand(CACTParser::LOrExpandContext *ctx) override; // 访问逻辑或扩展表达式节点
    std::any visitLOrExpor(CACTParser::LOrExporContext *ctx) override; // 访问逻辑或表达式节点
    std::any visitLAndExpeq(CACTParser::LAndExpeqContext *ctx) override; // 访问逻辑与表达式节点
    std::any visitLAndExpand(CACTParser::LAndExpandContext *ctx) override; // 访问逻辑与扩展表达式节点
    std::any visitEqExprel(CACTParser::EqExprelContext *ctx) override; // 访问相等表达式节点
    std::any visitEqExpeq(CACTParser::EqExpeqContext *ctx) override; // 访问相等扩展表达式节点
    std::any visitRelExpadd(CACTParser::RelExpaddContext *ctx) override; // 访问关系表达式节点
    std::any visitRelExprel(CACTParser::RelExprelContext *ctx) override; // 访问关系扩展表达式节点
    std::any visitRelExpbool(CACTParser::RelExpboolContext *ctx) override; // 访问关系布尔表达式节点
};
