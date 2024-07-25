
    #include "irOperand.h"
    #include "symbolTable.h"


// Generated from CACT.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  CACTParser : public antlr4::Parser {
public:
  enum {
    CONST = 1, COMMA = 2, SEMICOLON = 3, VOID = 4, BOOL = 5, INT = 6, FLOAT = 7, 
    DOUBLE = 8, EQUALS = 9, LBRACKET = 10, RBRACKET = 11, LBRACE = 12, RBRACE = 13, 
    LPARENTHESE = 14, RPARENTHESE = 15, RETURN = 16, IF = 17, ELSE = 18, 
    WHILE = 19, BREAK = 20, CONTINUE = 21, ADD = 22, SUB = 23, MUL = 24, 
    DIV = 25, MOD = 26, EQ = 27, NE = 28, LE = 29, GE = 30, LT = 31, GT = 32, 
    OR = 33, AND = 34, NOT = 35, BOOLCONST = 36, IDENT = 37, DOUBLECONST = 38, 
    FLOATCONST = 39, INTCONST = 40, WS = 41, BLOCKCOMM = 42, LINECOMM = 43
  };

  enum {
    RuleStart = 0, RuleCompUnit = 1, RuleDecl = 2, RuleConstDecl = 3, RuleVarDecl = 4, 
    RuleBType = 5, RuleConstDef = 6, RuleVarDef = 7, RuleConstInitVal = 8, 
    RuleConstExp = 9, RuleInitNum = 10, RuleNum = 11, RuleFuncDef = 12, 
    RuleFuncType = 13, RuleFuncFParams = 14, RuleFuncFParam = 15, RuleFuncBlock = 16, 
    RuleBlock = 17, RuleBlockItem = 18, RuleStmt = 19, RuleLVal = 20, RuleExp = 21, 
    RuleAddExp = 22, RuleMulExp = 23, RuleUnaryExp = 24, RulePriExp = 25, 
    RuleFuncRParams = 26, RuleLOrExp = 27, RuleLAndExp = 28, RuleEqExp = 29, 
    RuleRelExp = 30
  };

  explicit CACTParser(antlr4::TokenStream *input);

  CACTParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CACTParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class VarDeclContext;
  class BTypeContext;
  class ConstDefContext;
  class VarDefContext;
  class ConstInitValContext;
  class ConstExpContext;
  class InitNumContext;
  class NumContext;
  class FuncDefContext;
  class FuncTypeContext;
  class FuncFParamsContext;
  class FuncFParamContext;
  class FuncBlockContext;
  class BlockContext;
  class BlockItemContext;
  class StmtContext;
  class LValContext;
  class ExpContext;
  class AddExpContext;
  class MulExpContext;
  class UnaryExpContext;
  class PriExpContext;
  class FuncRParamsContext;
  class LOrExpContext;
  class LAndExpContext;
  class EqExpContext;
  class RelExpContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    std::vector<Type> libFuncType = {Type::VOID, Type::VOID, Type::VOID, Type::VOID, Type::INT, Type::FLOAT, Type::DOUBLE};
    std::vector<std::string> libFuncName = {"print_int", "print_float", "print_double", "print_bool", "get_int", "get_float", "get_double"};
    std::vector<ValSymbol*> valSymbolList;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompUnitContext *compUnit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclContext* constDecl();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    Type btype;
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BTypeContext* bType();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    std::string symbolname;
    int dimsize;
    std::vector<int> dimarr;
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *EQUALS();
    ConstInitValContext *constInitVal();
    std::vector<antlr4::tree::TerminalNode *> LBRACKET();
    antlr4::tree::TerminalNode* LBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INTCONST();
    antlr4::tree::TerminalNode* INTCONST(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET();
    antlr4::tree::TerminalNode* RBRACKET(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDefContext* constDef();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    std::string symbolname;
    int dimsize;
    std::vector<int> dimarr;
    std::vector<IROperand*> initval;
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    std::vector<antlr4::tree::TerminalNode *> LBRACKET();
    antlr4::tree::TerminalNode* LBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INTCONST();
    antlr4::tree::TerminalNode* INTCONST(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET();
    antlr4::tree::TerminalNode* RBRACKET(size_t i);
    antlr4::tree::TerminalNode *EQUALS();
    ConstInitValContext *constInitVal();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDefContext* varDef();

  class  ConstInitValContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    std::vector<IROperand*> initval;
    ConstInitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstInitValContext() = default;
    void copyFrom(ConstInitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstInitValNestedContext : public ConstInitValContext {
  public:
    ConstInitValNestedContext(ConstInitValContext *ctx);

    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ConstInitValContext *> constInitVal();
    ConstInitValContext* constInitVal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstInitValBasicContext : public ConstInitValContext {
  public:
    ConstInitValBasicContext(ConstInitValContext *ctx);

    ConstExpContext *constExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConstInitValContext* constInitVal();

  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    std::string value;
    IROperand * result;
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InitNumContext *initNum();
    antlr4::tree::TerminalNode *BOOLCONST();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstExpContext* constExp();

  class  InitNumContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    std::string value;
    InitNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumContext *num();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitNumContext* initNum();

  class  NumContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    std::string value;
    NumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTCONST();
    antlr4::tree::TerminalNode *FLOATCONST();
    antlr4::tree::TerminalNode *DOUBLECONST();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumContext* num();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    std::string symbolname;
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *LPARENTHESE();
    antlr4::tree::TerminalNode *RPARENTHESE();
    FuncBlockContext *funcBlock();
    FuncFParamsContext *funcFParams();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    Type functype;
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VOID();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncTypeContext* funcType();

  class  FuncFParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncFParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncFParamsContext* funcFParams();

  class  FuncFParamContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    std::string symbolname;
    int dimsize;
    std::vector<int> dimarr;
    FuncFParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *IDENT();
    std::vector<antlr4::tree::TerminalNode *> LBRACKET();
    antlr4::tree::TerminalNode* LBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET();
    antlr4::tree::TerminalNode* RBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INTCONST();
    antlr4::tree::TerminalNode* INTCONST(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncFParamContext* funcFParam();

  class  FuncBlockContext : public antlr4::ParserRuleContext {
  public:
    FuncBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncBlockContext* funcBlock();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    bool returnCheck = false;
    IROperand * before = nullptr;
    IROperand * next = nullptr;
    IROperand * newLabel;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    bool returnCheck = false;
    IROperand * newLabel;
    IROperand * next = nullptr;
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BlockItemContext() = default;
    void copyFrom(BlockItemContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BlockItemStmtContext : public BlockItemContext {
  public:
    BlockItemStmtContext(BlockItemContext *ctx);

    StmtContext *stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BlockItemDeclContext : public BlockItemContext {
  public:
    BlockItemDeclContext(BlockItemContext *ctx);

    DeclContext *decl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BlockItemContext* blockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    bool returnCheck = false;
    IROperand * before = nullptr;
    IROperand * next = nullptr;
    IROperand * newLabel;
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StmtExpContext : public StmtContext {
  public:
    StmtExpContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *SEMICOLON();
    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtBlockContext : public StmtContext {
  public:
    StmtBlockContext(StmtContext *ctx);

    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtBreakContext : public StmtContext {
  public:
    StmtBreakContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtWhileContext : public StmtContext {
  public:
    StmtWhileContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPARENTHESE();
    LOrExpContext *lOrExp();
    antlr4::tree::TerminalNode *RPARENTHESE();
    StmtContext *stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtIfContext : public StmtContext {
  public:
    StmtIfContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPARENTHESE();
    LOrExpContext *lOrExp();
    antlr4::tree::TerminalNode *RPARENTHESE();
    StmtContext *stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtIfElseContext : public StmtContext {
  public:
    StmtIfElseContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPARENTHESE();
    LOrExpContext *lOrExp();
    antlr4::tree::TerminalNode *RPARENTHESE();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtReturnContext : public StmtContext {
  public:
    StmtReturnContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtContinueContext : public StmtContext {
  public:
    StmtContinueContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtAssignContext : public StmtContext {
  public:
    StmtAssignContext(StmtContext *ctx);

    LValContext *lVal();
    antlr4::tree::TerminalNode *EQUALS();
    ExpContext *exp();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    IROperand * result;
    bool isConst;
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    std::vector<antlr4::tree::TerminalNode *> LBRACKET();
    antlr4::tree::TerminalNode* LBRACKET(size_t i);
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET();
    antlr4::tree::TerminalNode* RBRACKET(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LValContext* lVal();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    IROperand * result;
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();
    antlr4::tree::TerminalNode *BOOLCONST();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpContext* exp();

  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    IROperand * result;
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AddExpContext() = default;
    void copyFrom(AddExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddExpaddContext : public AddExpContext {
  public:
    AddExpaddContext(AddExpContext *ctx);

    antlr4::Token *op = nullptr;
    AddExpContext *addExp();
    MulExpContext *mulExp();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddExpmulContext : public AddExpContext {
  public:
    AddExpmulContext(AddExpContext *ctx);

    MulExpContext *mulExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    IROperand * result;
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MulExpContext() = default;
    void copyFrom(MulExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MulExpmulContext : public MulExpContext {
  public:
    MulExpmulContext(MulExpContext *ctx);

    antlr4::Token *op = nullptr;
    MulExpContext *mulExp();
    UnaryExpContext *unaryExp();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulExpunaContext : public MulExpContext {
  public:
    MulExpunaContext(MulExpContext *ctx);

    UnaryExpContext *unaryExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    IROperand * result;
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryExppriContext : public UnaryExpContext {
  public:
    UnaryExppriContext(UnaryExpContext *ctx);

    PriExpContext *priExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExpunaContext : public UnaryExpContext {
  public:
    UnaryExpunaContext(UnaryExpContext *ctx);

    UnaryExpContext *unaryExp();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *NOT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExpfunContext : public UnaryExpContext {
  public:
    UnaryExpfunContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *IDENT();
    antlr4::tree::TerminalNode *LPARENTHESE();
    antlr4::tree::TerminalNode *RPARENTHESE();
    FuncRParamsContext *funcRParams();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnaryExpContext* unaryExp();

  class  PriExpContext : public antlr4::ParserRuleContext {
  public:
    Type datatype;
    int dimsize;
    std::vector<int> dimarr;
    IROperand * result;
    PriExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PriExpContext() = default;
    void copyFrom(PriExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PriExpNumContext : public PriExpContext {
  public:
    PriExpNumContext(PriExpContext *ctx);

    NumContext *num();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PriExpLvalContext : public PriExpContext {
  public:
    PriExpLvalContext(PriExpContext *ctx);

    LValContext *lVal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PriExpNestedContext : public PriExpContext {
  public:
    PriExpNestedContext(PriExpContext *ctx);

    antlr4::tree::TerminalNode *LPARENTHESE();
    ExpContext *exp();
    antlr4::tree::TerminalNode *RPARENTHESE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PriExpContext* priExp();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncSymbol * funcsymbol;
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncRParamsContext* funcRParams();

  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    IROperand * True;
    IROperand * False;
    bool first = true;
    IROperand * newLabel;
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LOrExpContext() = default;
    void copyFrom(LOrExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LOrExpandContext : public LOrExpContext {
  public:
    LOrExpandContext(LOrExpContext *ctx);

    LAndExpContext *lAndExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LOrExporContext : public LOrExpContext {
  public:
    LOrExporContext(LOrExpContext *ctx);

    LOrExpContext *lOrExp();
    antlr4::tree::TerminalNode *OR();
    LAndExpContext *lAndExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);
  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    IROperand * True;
    IROperand * False;
    bool first = true;
    IROperand * newLabel;
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LAndExpContext() = default;
    void copyFrom(LAndExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LAndExpeqContext : public LAndExpContext {
  public:
    LAndExpeqContext(LAndExpContext *ctx);

    EqExpContext *eqExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LAndExpandContext : public LAndExpContext {
  public:
    LAndExpandContext(LAndExpContext *ctx);

    LAndExpContext *lAndExp();
    antlr4::tree::TerminalNode *AND();
    EqExpContext *eqExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    IROperand * True;
    IROperand * False;
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EqExpContext() = default;
    void copyFrom(EqExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EqExpeqContext : public EqExpContext {
  public:
    EqExpeqContext(EqExpContext *ctx);

    std::vector<RelExpContext *> relExp();
    RelExpContext* relExp(size_t i);
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqExprelContext : public EqExpContext {
  public:
    EqExprelContext(EqExpContext *ctx);

    RelExpContext *relExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EqExpContext* eqExp();

  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    IROperand * True;
    IROperand * False;
    bool jump = true;
    Type datatype;
    IROperand * result;
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RelExpContext() = default;
    void copyFrom(RelExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RelExpboolContext : public RelExpContext {
  public:
    RelExpboolContext(RelExpContext *ctx);

    antlr4::tree::TerminalNode *BOOLCONST();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RelExpaddContext : public RelExpContext {
  public:
    RelExpaddContext(RelExpContext *ctx);

    AddExpContext *addExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RelExprelContext : public RelExpContext {
  public:
    RelExprelContext(RelExpContext *ctx);

    std::vector<AddExpContext *> addExp();
    AddExpContext* addExp(size_t i);
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RelExpContext* relExp();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool addExpSempred(AddExpContext *_localctx, size_t predicateIndex);
  bool mulExpSempred(MulExpContext *_localctx, size_t predicateIndex);
  bool lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex);
  bool lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

