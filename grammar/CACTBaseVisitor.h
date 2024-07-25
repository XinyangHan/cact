
    #include "irOperand.h"
    #include "symbolTable.h"


// Generated from CACT.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CACTVisitor.h"


/**
 * This class provides an empty implementation of CACTVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CACTBaseVisitor : public CACTVisitor {
public:

  virtual std::any visitStart(CACTParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompUnit(CACTParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(CACTParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(CACTParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(CACTParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(CACTParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(CACTParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(CACTParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitValBasic(CACTParser::ConstInitValBasicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitValNested(CACTParser::ConstInitValNestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExp(CACTParser::ConstExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitNum(CACTParser::InitNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum(CACTParser::NumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(CACTParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(CACTParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParams(CACTParser::FuncFParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParam(CACTParser::FuncFParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncBlock(CACTParser::FuncBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(CACTParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItemDecl(CACTParser::BlockItemDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItemStmt(CACTParser::BlockItemStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtAssign(CACTParser::StmtAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtExp(CACTParser::StmtExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtBlock(CACTParser::StmtBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtReturn(CACTParser::StmtReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtIf(CACTParser::StmtIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtIfElse(CACTParser::StmtIfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtWhile(CACTParser::StmtWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtBreak(CACTParser::StmtBreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtContinue(CACTParser::StmtContinueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLVal(CACTParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp(CACTParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpadd(CACTParser::AddExpaddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpmul(CACTParser::AddExpmulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExpmul(CACTParser::MulExpmulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExpuna(CACTParser::MulExpunaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExppri(CACTParser::UnaryExppriContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpuna(CACTParser::UnaryExpunaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpfun(CACTParser::UnaryExpfunContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPriExpNum(CACTParser::PriExpNumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPriExpNested(CACTParser::PriExpNestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPriExpLval(CACTParser::PriExpLvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRParams(CACTParser::FuncRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrExpand(CACTParser::LOrExpandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrExpor(CACTParser::LOrExporContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndExpeq(CACTParser::LAndExpeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndExpand(CACTParser::LAndExpandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExprel(CACTParser::EqExprelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExpeq(CACTParser::EqExpeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelExpadd(CACTParser::RelExpaddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelExprel(CACTParser::RelExprelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelExpbool(CACTParser::RelExpboolContext *ctx) override {
    return visitChildren(ctx);
  }


};

