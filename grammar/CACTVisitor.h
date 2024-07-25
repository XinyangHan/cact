
    #include "include/irOperand.h"
    #include "include/symTable.h"


// Generated from CACT.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CACTParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CACTParser.
 */
class  CACTVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CACTParser.
   */
    virtual std::any visitBegin(CACTParser::StartContext *context) = 0;

    virtual std::any visitCompUnit(CACTParser::CompUnitContext *context) = 0;

    virtual std::any visitDecl(CACTParser::DeclContext *context) = 0;

    virtual std::any visitConstDecl(CACTParser::ConstDeclContext *context) = 0;

    virtual std::any visitVarDecl(CACTParser::VarDeclContext *context) = 0;

    virtual std::any visitBType(CACTParser::BTypeContext *context) = 0;

    virtual std::any visitConstDef(CACTParser::ConstDefContext *context) = 0;

    virtual std::any visitVarDef(CACTParser::VarDefContext *context) = 0;

    virtual std::any visitConstInitValBasic(CACTParser::ConstInitValBasicContext *context) = 0;

    virtual std::any visitConstInitValNested(CACTParser::ConstInitValNestedContext *context) = 0;

    virtual std::any visitConstExp(CACTParser::ConstExpContext *context) = 0;

    virtual std::any visitInitNum(CACTParser::InitNumContext *context) = 0;

    virtual std::any visitNum(CACTParser::NumContext *context) = 0;

    virtual std::any visitFuncDef(CACTParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncType(CACTParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFParams(CACTParser::FuncFParamsContext *context) = 0;

    virtual std::any visitFuncFParam(CACTParser::FuncFParamContext *context) = 0;

    virtual std::any visitFuncBlock(CACTParser::FuncBlockContext *context) = 0;

    virtual std::any visitBlock(CACTParser::BlockContext *context) = 0;

    virtual std::any visitBlockItemDecl(CACTParser::BlockItemDeclContext *context) = 0;

    virtual std::any visitBlockItemStmt(CACTParser::BlockItemStmtContext *context) = 0;

    virtual std::any visitStmtAssign(CACTParser::StmtAssignContext *context) = 0;

    virtual std::any visitStmtExp(CACTParser::StmtExpContext *context) = 0;

    virtual std::any visitStmtBlock(CACTParser::StmtBlockContext *context) = 0;

    virtual std::any visitStmtReturn(CACTParser::StmtReturnContext *context) = 0;

    virtual std::any visitStmtIf(CACTParser::StmtIfContext *context) = 0;

    virtual std::any visitStmtIfElse(CACTParser::StmtIfElseContext *context) = 0;

    virtual std::any visitStmtWhile(CACTParser::StmtWhileContext *context) = 0;

    virtual std::any visitStmtBreak(CACTParser::StmtBreakContext *context) = 0;

    virtual std::any visitStmtContinue(CACTParser::StmtContinueContext *context) = 0;

    virtual std::any visitLVal(CACTParser::LValContext *context) = 0;

    virtual std::any visitExp(CACTParser::ExpContext *context) = 0;

    virtual std::any visitAddExpadd(CACTParser::AddExpaddContext *context) = 0;

    virtual std::any visitAddExpmul(CACTParser::AddExpmulContext *context) = 0;

    virtual std::any visitMulExpmul(CACTParser::MulExpmulContext *context) = 0;

    virtual std::any visitMulExpuna(CACTParser::MulExpunaContext *context) = 0;

    virtual std::any visitUnaryExppri(CACTParser::UnaryExppriContext *context) = 0;

    virtual std::any visitUnaryExpuna(CACTParser::UnaryExpunaContext *context) = 0;

    virtual std::any visitUnaryExpfun(CACTParser::UnaryExpfunContext *context) = 0;

    virtual std::any visitPriExpNum(CACTParser::PriExpNumContext *context) = 0;

    virtual std::any visitPriExpNested(CACTParser::PriExpNestedContext *context) = 0;

    virtual std::any visitPriExpLval(CACTParser::PriExpLvalContext *context) = 0;

    virtual std::any visitFuncRParams(CACTParser::FuncRParamsContext *context) = 0;

    virtual std::any visitLOrExpand(CACTParser::LOrExpandContext *context) = 0;

    virtual std::any visitLOrExpor(CACTParser::LOrExporContext *context) = 0;

    virtual std::any visitLAndExpeq(CACTParser::LAndExpeqContext *context) = 0;

    virtual std::any visitLAndExpand(CACTParser::LAndExpandContext *context) = 0;

    virtual std::any visitEqExprel(CACTParser::EqExprelContext *context) = 0;

    virtual std::any visitEqExpeq(CACTParser::EqExpeqContext *context) = 0;

    virtual std::any visitRelExpadd(CACTParser::RelExpaddContext *context) = 0;

    virtual std::any visitRelExprel(CACTParser::RelExprelContext *context) = 0;

    virtual std::any visitRelExpbool(CACTParser::RelExpboolContext *context) = 0;


};

