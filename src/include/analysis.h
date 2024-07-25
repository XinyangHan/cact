#include "CACTBaseVisitor.h"
#include "symTable.h"
#include "irGenerator.h"
using namespace antlr4;
class IRInterpretor;

class Analysis : public CACTBaseVisitor{
    public:
    class WhileCtx {
        public:
        WhileCtx  *preWhileCtx;
        IROperand *breakDst;
        IROperand *contDst;
        
        WhileCtx(WhileCtx *preWhileCtx, IROperand *breakDst, IROperand *contDst) {this->preWhileCtx = preWhileCtx; this->breakDst = breakDst; this->contDst = contDst;}
    };
    WhileCtx *currWhile = nullptr;
    Env *env;
    IRGenerator  *irGenerator;
    IRInterpretor *irInterpretor;
    AsmGenerator *asmGenerator;
    
    std::any visitStart(CACTParser::StartContext *ctx) override;
    
    std::any visitConstDecl(CACTParser::ConstDeclContext *ctx) override;
    
    std::any visitConstDef(CACTParser::ConstDefContext *ctx) override;
    
    std::any visitVarDecl(CACTParser::VarDeclContext *ctx) override;

    std::any visitVarDef(CACTParser::VarDefContext *ctx) override;
    
    std::any visitConstInitValBasic(CACTParser::ConstInitValBasicContext *ctx) override;
    
    std::any visitConstInitValNested(CACTParser::ConstInitValNestedContext *ctx) override;
    
    std::any visitConstExp(CACTParser::ConstExpContext *ctx) override;
    
    std::any visitInitNum(CACTParser::InitNumContext *ctx) override;
    
    std::any visitFuncType(CACTParser::FuncTypeContext *ctx) override;
    
    std::any visitFuncDef(CACTParser::FuncDefContext *ctx) override;
    
    std::any visitFuncFParam(CACTParser::FuncFParamContext *ctx) override;
    
    std::any visitBType(CACTParser::BTypeContext *ctx) override;
    
    std::any visitFuncBlock(CACTParser::FuncBlockContext *ctx) override;
    
    std::any visitBlock(CACTParser::BlockContext *ctx) override;
    
    std::any visitBlockItemDecl(CACTParser::BlockItemDeclContext *ctx) override;
    
    std::any visitBlockItemStmt(CACTParser::BlockItemStmtContext *ctx) override;
    
    std::any visitNum(CACTParser::NumContext *ctx) override;
    
    std::any visitPriExpNum(CACTParser::PriExpNumContext *ctx) override;
    
    std::any visitPriExpNested(CACTParser::PriExpNestedContext *ctx) override;
    
    std::any visitPriExpLval(CACTParser::PriExpLvalContext *ctx) override;
    
    std::any visitLVal(CACTParser::LValContext *ctx) override;
    
    std::any visitUnaryExppri(CACTParser::UnaryExppriContext *ctx) override;
    
    std::any visitUnaryExpuna(CACTParser::UnaryExpunaContext *ctx) override;
    
    std::any visitUnaryExpfun(CACTParser::UnaryExpfunContext *ctx) override;
    
    std::any visitFuncRParams(CACTParser::FuncRParamsContext *ctx) override;
    
    std::any visitMulExpmul(CACTParser::MulExpmulContext *ctx) override;
    
    std::any visitMulExpuna(CACTParser::MulExpunaContext *ctx) override;
    
    std::any visitAddExpadd(CACTParser::AddExpaddContext *ctx) override;
    
    std::any visitAddExpmul(CACTParser::AddExpmulContext *ctx) override;
    
    std::any visitExp(CACTParser::ExpContext *ctx) override;
    
    std::any visitStmtAssign(CACTParser::StmtAssignContext *ctx) override;
    
    std::any visitStmtExp(CACTParser::StmtExpContext *ctx) override;
    
    std::any visitStmtBlock(CACTParser::StmtBlockContext *ctx) override;
    
    std::any visitStmtReturn(CACTParser::StmtReturnContext *ctx) override;
    
    std::any visitStmtIf(CACTParser::StmtIfContext *ctx) override;
    
    std::any visitStmtIfElse(CACTParser::StmtIfElseContext *ctx) override;
    
    std::any visitStmtWhile(CACTParser::StmtWhileContext *ctx) override;
    
    std::any visitStmtBreak(CACTParser::StmtBreakContext *ctx) override;
    
    std::any visitStmtContinue(CACTParser::StmtContinueContext *ctx) override;
    
    std::any visitLOrExpand(CACTParser::LOrExpandContext *ctx) override;
    
    std::any visitLOrExpor(CACTParser::LOrExporContext *ctx) override;
    
    std::any visitLAndExpeq(CACTParser::LAndExpeqContext *ctx) override;
    
    std::any visitLAndExpand(CACTParser::LAndExpandContext *ctx) override;
    
    std::any visitEqExprel(CACTParser::EqExprelContext *ctx) override;
    
    std::any visitEqExpeq(CACTParser::EqExpeqContext *ctx) override;
    
    std::any visitRelExpadd(CACTParser::RelExpaddContext *ctx) override;
    
    std::any visitRelExprel(CACTParser::RelExprelContext *ctx) override;
    
    std::any visitRelExpbool(CACTParser::RelExpboolContext *ctx) override;
};
