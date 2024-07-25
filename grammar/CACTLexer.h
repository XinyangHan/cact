
    #include "include/irOperand.h"
    #include "include/symTable.h"


// Generated from CACT.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  CACTLexer : public antlr4::Lexer {
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

  explicit CACTLexer(antlr4::CharStream *input);

  ~CACTLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

