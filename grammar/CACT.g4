grammar CACT;

@header {
    #include "irOperand.h"
    #include "symbolTable.h"
}

/****** parser ******/
start
    locals [
      std::vector<Type> libFuncType = {Type::VOID, Type::VOID, Type::VOID, Type::VOID, Type::INT, Type::FLOAT, Type::DOUBLE},
      std::vector<std::string> libFuncName = {"print_int", "print_float", "print_double", "print_bool", "get_int", "get_float", "get_double"},
      std::vector<ValSymbol*> valSymbolList
    ]
    : compUnit;
    
compUnit  
       : (decl | funcDef)* EOF;

decl
   : constDecl
   | varDecl;
   
constDecl
        : CONST bType constDef (COMMA constDef)* SEMICOLON;

varDecl
      : bType varDef (COMMA varDef)* SEMICOLON;
        
bType
    locals [
      Type btype
    ]
    : BOOL
    | INT
    | FLOAT
    | DOUBLE;
    
constDef
       locals [
         Type datatype,
         std::string symbolname, 
         int dimsize,
         std::vector<int> dimarr
       ]
       : IDENT (LBRACKET INTCONST RBRACKET)* EQUALS constInitVal;
       
varDef
     locals [
       Type datatype,
       std::string symbolname, 
       int dimsize,
       std::vector<int> dimarr,
       std::vector<IROperand*> initval
     ]
     : IDENT (LBRACKET INTCONST RBRACKET)* (EQUALS constInitVal)?;
     
constInitVal
           locals [
             Type datatype,
             int dimsize,
             std::vector<int> dimarr,
             std::vector<IROperand*> initval
           ]
           : constExp                                               #constInitValBasic
           | LBRACE (constInitVal (COMMA constInitVal)*)? RBRACE    #constInitValNested
           ;
constExp
       locals [
         Type datatype,
         std::string value,
         IROperand *result
       ]
       : initNum
       | BOOLCONST;
       
initNum
      locals [
        Type datatype,
        std::string value
      ]
   : (ADD|SUB)? num;
       
num
  locals [
    Type datatype,
    int dimsize,
    std::vector<int> dimarr,
    std::string value 
  ]
  : INTCONST
  | FLOATCONST
  | DOUBLECONST;
  
funcDef
      locals [
        std::string symbolname
      ]
      : funcType IDENT LPARENTHESE (funcFParams)? RPARENTHESE funcBlock;
      
funcType
       locals [
         Type functype
       ]
       : VOID
       | BOOL
       | INT
       | FLOAT
       | DOUBLE;
      
funcFParams
         : funcFParam (COMMA funcFParam)*;
     
funcFParam
         locals [
           Type datatype,
           std::string symbolname,
           int dimsize,
           std::vector<int> dimarr 
         ]
        : bType IDENT (LBRACKET (INTCONST)? RBRACKET (LBRACKET INTCONST RBRACKET)*)?;
        
funcBlock
        : LBRACE (blockItem)* RBRACE;
        
block
    locals [
      bool returnCheck = false,
      IROperand *before = nullptr,
      IROperand *next = nullptr,
      IROperand *newLabel
    ]
    : LBRACE (blockItem)* RBRACE;
    
blockItem
        locals [
          bool returnCheck = false,
          IROperand *newLabel,
          IROperand *next = nullptr
        ]
        : decl  #blockItemDecl
        | stmt  #blockItemStmt
        ;
        
stmt
   locals [
     bool returnCheck = false,
     IROperand *before = nullptr,
     IROperand *next = nullptr,
     IROperand *newLabel
   ]
   : lVal EQUALS exp SEMICOLON                        #stmtAssign
   | (exp)? SEMICOLON                                 #stmtExp
   | block                                            #stmtBlock
   | RETURN (exp)? SEMICOLON                          #stmtReturn
   | IF LPARENTHESE lOrExp RPARENTHESE stmt           #stmtIf
   | IF LPARENTHESE lOrExp RPARENTHESE stmt ELSE stmt #stmtIfElse
   | WHILE LPARENTHESE lOrExp RPARENTHESE stmt        #stmtWhile
   | BREAK SEMICOLON                                  #stmtBreak
   | CONTINUE SEMICOLON                               #stmtContinue
   ;

lVal
   locals [
     Type datatype,
     int dimsize,
     std::vector<int> dimarr,
     IROperand *result,
     bool isConst
   ]
   : IDENT (LBRACKET exp RBRACKET)*;
   
exp
  locals [
    Type datatype,
    int dimsize,
    std::vector<int> dimarr,
    IROperand *result
  ]
  : addExp 
  | BOOLCONST;
  
addExp
     locals [
       Type datatype,
       int dimsize,
       std::vector<int> dimarr,
       IROperand *result
     ]
     : mulExp                       #addExpmul
     | addExp op=(ADD|SUB) mulExp   #addExpadd
     ;
     
mulExp
     locals [
       Type datatype,
       int dimsize,
       std::vector<int> dimarr,
       IROperand *result
     ]
     : unaryExp                           #mulExpuna
     | mulExp op=(MUL|DIV|MOD) unaryExp   #mulExpmul
     ;
     
unaryExp
       locals [
         Type datatype,
         int dimsize,
         std::vector<int> dimarr,
         IROperand *result
       ]
       : priExp                                        #unaryExppri 
       | (ADD|SUB|NOT) unaryExp                        #unaryExpuna 
       | IDENT LPARENTHESE (funcRParams)? RPARENTHESE  #unaryExpfun
       ;
       
priExp
     locals [
       Type datatype,
       int dimsize,
       std::vector<int> dimarr,
       IROperand *result
     ]
     : num                          #priExpNum 
     | LPARENTHESE exp RPARENTHESE  #priExpNested
     | lVal                         #priExpLval
     ;

funcRParams
          locals [
            FuncSymbol *funcsymbol
          ]
          : exp (COMMA exp)*;
   
lOrExp
     locals [
       IROperand *True,
       IROperand *False,
       bool first = true,
       IROperand *newLabel
     ]
     : lAndExp             #lOrExpand
     | lOrExp OR lAndExp   #lOrExpor
     ; 
     
lAndExp
      locals [
        IROperand *True,
        IROperand *False,
        bool first = true,
        IROperand *newLabel
      ]
      : eqExp              #lAndExpeq
      | lAndExp AND eqExp  #lAndExpand
      ;
      
eqExp
    locals [
        IROperand *True,
        IROperand *False
    ]
    : relExp                  #eqExprel
    | relExp (EQ|NE) relExp   #eqExpeq
    ;
    
relExp
     locals [
        IROperand *True,
        IROperand *False,
        bool jump = true,
        Type datatype,
        IROperand *result
     ]
     : addExp                       #relExpadd
     | addExp (LT|GT|LE|GE) addExp  #relExprel
     | BOOLCONST                    #relExpbool
     ;         


/****** lexer  ******/
CONST : 'const';
COMMA : ',';
SEMICOLON : ';';
VOID : 'void';
BOOL : 'bool';
INT : 'int';
FLOAT : 'float';
DOUBLE : 'double';
EQUALS : '=';
LBRACKET : '[';
RBRACKET : ']';
LBRACE : '{';
RBRACE : '}';
LPARENTHESE : '(';
RPARENTHESE : ')';
RETURN : 'return';
IF : 'if';
ELSE : 'else';
WHILE : 'while';
BREAK : 'break';
CONTINUE : 'continue';
ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
MOD : '%';
EQ  : '==';
NE  : '!=';
LE  : '<=';
GE  : '>=';
LT  : '<';
GT  : '>';
OR  : '||';
AND : '&&';
NOT : '!';

BOOLCONST : 'true' | 'false';

IDENT : [a-zA-Z_] [a-zA-Z_0-9]*;
  
DOUBLECONST : (DIGITS '.' | DIGITS? '.' DIGITS)
            | DIGITS '.'? DIGITS? ('E'|'e') ('+'|'-')? DIGITS
            | '.' DIGITS ('E'|'e') ('+'|'-')? DIGITS;
fragment
DIGITS : [0-9]+;

FLOATCONST : DOUBLECONST FLOATPRE;
fragment
FLOATPRE : 'f' | 'F';

INTCONST : DECCONST | OCTCONST | HEXCONST;
fragment
DECCONST : '0' | [1-9][0-9]*;
fragment
OCTCONST : '0' [0-7]+;
fragment
HEXCONST : HEXPRE [0-9a-fA-F]+;
fragment 
HEXPRE : '0x' | '0X';

/****** skips  ******/
WS : [ \t\r\n]+ -> skip; 
BLOCKCOMM : '/*' .*? '*/'-> skip;
LINECOMM : '//' ~[\r\n]* -> skip;
