
    #include "irOperand.h"
    #include "symbolTable.h"


// Generated from CACT.g4 by ANTLR 4.13.1


#include "CACTLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CACTLexerStaticData final {
  CACTLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CACTLexerStaticData(const CACTLexerStaticData&) = delete;
  CACTLexerStaticData(CACTLexerStaticData&&) = delete;
  CACTLexerStaticData& operator=(const CACTLexerStaticData&) = delete;
  CACTLexerStaticData& operator=(CACTLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cactlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CACTLexerStaticData *cactlexerLexerStaticData = nullptr;

void cactlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cactlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(cactlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CACTLexerStaticData>(
    std::vector<std::string>{
      "CONST", "COMMA", "SEMICOLON", "VOID", "BOOL", "INT", "FLOAT", "DOUBLE", 
      "EQUALS", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPARENTHESE", 
      "RPARENTHESE", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
      "ADD", "SUB", "MUL", "DIV", "MOD", "EQ", "NE", "LE", "GE", "LT", "GT", 
      "OR", "AND", "NOT", "BOOLCONST", "IDENT", "DOUBLECONST", "DIGITS", 
      "FLOATCONST", "FLOATPRE", "INTCONST", "DECCONST", "OCTCONST", "HEXCONST", 
      "HEXPRE", "WS", "BLOCKCOMM", "LINECOMM"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'const'", "','", "';'", "'void'", "'bool'", "'int'", "'float'", 
      "'double'", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'return'", 
      "'if'", "'else'", "'while'", "'break'", "'continue'", "'+'", "'-'", 
      "'*'", "'/'", "'%'", "'=='", "'!='", "'<='", "'>='", "'<'", "'>'", 
      "'||'", "'&&'", "'!'"
    },
    std::vector<std::string>{
      "", "CONST", "COMMA", "SEMICOLON", "VOID", "BOOL", "INT", "FLOAT", 
      "DOUBLE", "EQUALS", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPARENTHESE", 
      "RPARENTHESE", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
      "ADD", "SUB", "MUL", "DIV", "MOD", "EQ", "NE", "LE", "GE", "LT", "GT", 
      "OR", "AND", "NOT", "BOOLCONST", "IDENT", "DOUBLECONST", "FLOATCONST", 
      "INTCONST", "WS", "BLOCKCOMM", "LINECOMM"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,43,346,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,17,
  	1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,
  	1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,29,
  	1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,33,1,34,1,34,
  	1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,3,35,230,8,35,1,36,1,36,
  	5,36,234,8,36,10,36,12,36,237,9,36,1,37,1,37,1,37,1,37,3,37,243,8,37,
  	1,37,1,37,3,37,247,8,37,1,37,1,37,3,37,251,8,37,1,37,3,37,254,8,37,1,
  	37,1,37,3,37,258,8,37,1,37,1,37,1,37,1,37,1,37,1,37,3,37,266,8,37,1,37,
  	1,37,3,37,270,8,37,1,38,4,38,273,8,38,11,38,12,38,274,1,39,1,39,1,39,
  	1,40,1,40,1,41,1,41,1,41,3,41,285,8,41,1,42,1,42,1,42,5,42,290,8,42,10,
  	42,12,42,293,9,42,3,42,295,8,42,1,43,1,43,4,43,299,8,43,11,43,12,43,300,
  	1,44,1,44,4,44,305,8,44,11,44,12,44,306,1,45,1,45,1,45,1,45,3,45,313,
  	8,45,1,46,4,46,316,8,46,11,46,12,46,317,1,46,1,46,1,47,1,47,1,47,1,47,
  	5,47,326,8,47,10,47,12,47,329,9,47,1,47,1,47,1,47,1,47,1,47,1,48,1,48,
  	1,48,1,48,5,48,340,8,48,10,48,12,48,343,9,48,1,48,1,48,1,327,0,49,1,1,
  	3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,
  	15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,
  	53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,
  	38,77,0,79,39,81,0,83,40,85,0,87,0,89,0,91,0,93,41,95,42,97,43,1,0,11,
  	3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,2,0,69,69,101,101,
  	2,0,43,43,45,45,1,0,48,57,2,0,70,70,102,102,1,0,49,57,1,0,48,55,3,0,48,
  	57,65,70,97,102,3,0,9,10,13,13,32,32,2,0,10,10,13,13,360,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,
  	1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,
  	0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,
  	0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,
  	1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,79,1,0,
  	0,0,0,83,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,1,99,1,0,0,0,
  	3,105,1,0,0,0,5,107,1,0,0,0,7,109,1,0,0,0,9,114,1,0,0,0,11,119,1,0,0,
  	0,13,123,1,0,0,0,15,129,1,0,0,0,17,136,1,0,0,0,19,138,1,0,0,0,21,140,
  	1,0,0,0,23,142,1,0,0,0,25,144,1,0,0,0,27,146,1,0,0,0,29,148,1,0,0,0,31,
  	150,1,0,0,0,33,157,1,0,0,0,35,160,1,0,0,0,37,165,1,0,0,0,39,171,1,0,0,
  	0,41,177,1,0,0,0,43,186,1,0,0,0,45,188,1,0,0,0,47,190,1,0,0,0,49,192,
  	1,0,0,0,51,194,1,0,0,0,53,196,1,0,0,0,55,199,1,0,0,0,57,202,1,0,0,0,59,
  	205,1,0,0,0,61,208,1,0,0,0,63,210,1,0,0,0,65,212,1,0,0,0,67,215,1,0,0,
  	0,69,218,1,0,0,0,71,229,1,0,0,0,73,231,1,0,0,0,75,269,1,0,0,0,77,272,
  	1,0,0,0,79,276,1,0,0,0,81,279,1,0,0,0,83,284,1,0,0,0,85,294,1,0,0,0,87,
  	296,1,0,0,0,89,302,1,0,0,0,91,312,1,0,0,0,93,315,1,0,0,0,95,321,1,0,0,
  	0,97,335,1,0,0,0,99,100,5,99,0,0,100,101,5,111,0,0,101,102,5,110,0,0,
  	102,103,5,115,0,0,103,104,5,116,0,0,104,2,1,0,0,0,105,106,5,44,0,0,106,
  	4,1,0,0,0,107,108,5,59,0,0,108,6,1,0,0,0,109,110,5,118,0,0,110,111,5,
  	111,0,0,111,112,5,105,0,0,112,113,5,100,0,0,113,8,1,0,0,0,114,115,5,98,
  	0,0,115,116,5,111,0,0,116,117,5,111,0,0,117,118,5,108,0,0,118,10,1,0,
  	0,0,119,120,5,105,0,0,120,121,5,110,0,0,121,122,5,116,0,0,122,12,1,0,
  	0,0,123,124,5,102,0,0,124,125,5,108,0,0,125,126,5,111,0,0,126,127,5,97,
  	0,0,127,128,5,116,0,0,128,14,1,0,0,0,129,130,5,100,0,0,130,131,5,111,
  	0,0,131,132,5,117,0,0,132,133,5,98,0,0,133,134,5,108,0,0,134,135,5,101,
  	0,0,135,16,1,0,0,0,136,137,5,61,0,0,137,18,1,0,0,0,138,139,5,91,0,0,139,
  	20,1,0,0,0,140,141,5,93,0,0,141,22,1,0,0,0,142,143,5,123,0,0,143,24,1,
  	0,0,0,144,145,5,125,0,0,145,26,1,0,0,0,146,147,5,40,0,0,147,28,1,0,0,
  	0,148,149,5,41,0,0,149,30,1,0,0,0,150,151,5,114,0,0,151,152,5,101,0,0,
  	152,153,5,116,0,0,153,154,5,117,0,0,154,155,5,114,0,0,155,156,5,110,0,
  	0,156,32,1,0,0,0,157,158,5,105,0,0,158,159,5,102,0,0,159,34,1,0,0,0,160,
  	161,5,101,0,0,161,162,5,108,0,0,162,163,5,115,0,0,163,164,5,101,0,0,164,
  	36,1,0,0,0,165,166,5,119,0,0,166,167,5,104,0,0,167,168,5,105,0,0,168,
  	169,5,108,0,0,169,170,5,101,0,0,170,38,1,0,0,0,171,172,5,98,0,0,172,173,
  	5,114,0,0,173,174,5,101,0,0,174,175,5,97,0,0,175,176,5,107,0,0,176,40,
  	1,0,0,0,177,178,5,99,0,0,178,179,5,111,0,0,179,180,5,110,0,0,180,181,
  	5,116,0,0,181,182,5,105,0,0,182,183,5,110,0,0,183,184,5,117,0,0,184,185,
  	5,101,0,0,185,42,1,0,0,0,186,187,5,43,0,0,187,44,1,0,0,0,188,189,5,45,
  	0,0,189,46,1,0,0,0,190,191,5,42,0,0,191,48,1,0,0,0,192,193,5,47,0,0,193,
  	50,1,0,0,0,194,195,5,37,0,0,195,52,1,0,0,0,196,197,5,61,0,0,197,198,5,
  	61,0,0,198,54,1,0,0,0,199,200,5,33,0,0,200,201,5,61,0,0,201,56,1,0,0,
  	0,202,203,5,60,0,0,203,204,5,61,0,0,204,58,1,0,0,0,205,206,5,62,0,0,206,
  	207,5,61,0,0,207,60,1,0,0,0,208,209,5,60,0,0,209,62,1,0,0,0,210,211,5,
  	62,0,0,211,64,1,0,0,0,212,213,5,124,0,0,213,214,5,124,0,0,214,66,1,0,
  	0,0,215,216,5,38,0,0,216,217,5,38,0,0,217,68,1,0,0,0,218,219,5,33,0,0,
  	219,70,1,0,0,0,220,221,5,116,0,0,221,222,5,114,0,0,222,223,5,117,0,0,
  	223,230,5,101,0,0,224,225,5,102,0,0,225,226,5,97,0,0,226,227,5,108,0,
  	0,227,228,5,115,0,0,228,230,5,101,0,0,229,220,1,0,0,0,229,224,1,0,0,0,
  	230,72,1,0,0,0,231,235,7,0,0,0,232,234,7,1,0,0,233,232,1,0,0,0,234,237,
  	1,0,0,0,235,233,1,0,0,0,235,236,1,0,0,0,236,74,1,0,0,0,237,235,1,0,0,
  	0,238,239,3,77,38,0,239,240,5,46,0,0,240,247,1,0,0,0,241,243,3,77,38,
  	0,242,241,1,0,0,0,242,243,1,0,0,0,243,244,1,0,0,0,244,245,5,46,0,0,245,
  	247,3,77,38,0,246,238,1,0,0,0,246,242,1,0,0,0,247,270,1,0,0,0,248,250,
  	3,77,38,0,249,251,5,46,0,0,250,249,1,0,0,0,250,251,1,0,0,0,251,253,1,
  	0,0,0,252,254,3,77,38,0,253,252,1,0,0,0,253,254,1,0,0,0,254,255,1,0,0,
  	0,255,257,7,2,0,0,256,258,7,3,0,0,257,256,1,0,0,0,257,258,1,0,0,0,258,
  	259,1,0,0,0,259,260,3,77,38,0,260,270,1,0,0,0,261,262,5,46,0,0,262,263,
  	3,77,38,0,263,265,7,2,0,0,264,266,7,3,0,0,265,264,1,0,0,0,265,266,1,0,
  	0,0,266,267,1,0,0,0,267,268,3,77,38,0,268,270,1,0,0,0,269,246,1,0,0,0,
  	269,248,1,0,0,0,269,261,1,0,0,0,270,76,1,0,0,0,271,273,7,4,0,0,272,271,
  	1,0,0,0,273,274,1,0,0,0,274,272,1,0,0,0,274,275,1,0,0,0,275,78,1,0,0,
  	0,276,277,3,75,37,0,277,278,3,81,40,0,278,80,1,0,0,0,279,280,7,5,0,0,
  	280,82,1,0,0,0,281,285,3,85,42,0,282,285,3,87,43,0,283,285,3,89,44,0,
  	284,281,1,0,0,0,284,282,1,0,0,0,284,283,1,0,0,0,285,84,1,0,0,0,286,295,
  	5,48,0,0,287,291,7,6,0,0,288,290,7,4,0,0,289,288,1,0,0,0,290,293,1,0,
  	0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,0,294,
  	286,1,0,0,0,294,287,1,0,0,0,295,86,1,0,0,0,296,298,5,48,0,0,297,299,7,
  	7,0,0,298,297,1,0,0,0,299,300,1,0,0,0,300,298,1,0,0,0,300,301,1,0,0,0,
  	301,88,1,0,0,0,302,304,3,91,45,0,303,305,7,8,0,0,304,303,1,0,0,0,305,
  	306,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,0,307,90,1,0,0,0,308,309,5,
  	48,0,0,309,313,5,120,0,0,310,311,5,48,0,0,311,313,5,88,0,0,312,308,1,
  	0,0,0,312,310,1,0,0,0,313,92,1,0,0,0,314,316,7,9,0,0,315,314,1,0,0,0,
  	316,317,1,0,0,0,317,315,1,0,0,0,317,318,1,0,0,0,318,319,1,0,0,0,319,320,
  	6,46,0,0,320,94,1,0,0,0,321,322,5,47,0,0,322,323,5,42,0,0,323,327,1,0,
  	0,0,324,326,9,0,0,0,325,324,1,0,0,0,326,329,1,0,0,0,327,328,1,0,0,0,327,
  	325,1,0,0,0,328,330,1,0,0,0,329,327,1,0,0,0,330,331,5,42,0,0,331,332,
  	5,47,0,0,332,333,1,0,0,0,333,334,6,47,0,0,334,96,1,0,0,0,335,336,5,47,
  	0,0,336,337,5,47,0,0,337,341,1,0,0,0,338,340,8,10,0,0,339,338,1,0,0,0,
  	340,343,1,0,0,0,341,339,1,0,0,0,341,342,1,0,0,0,342,344,1,0,0,0,343,341,
  	1,0,0,0,344,345,6,48,0,0,345,98,1,0,0,0,20,0,229,235,242,246,250,253,
  	257,265,269,274,284,291,294,300,306,312,317,327,341,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cactlexerLexerStaticData = staticData.release();
}

}

CACTLexer::CACTLexer(CharStream *input) : Lexer(input) {
  CACTLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *cactlexerLexerStaticData->atn, cactlexerLexerStaticData->decisionToDFA, cactlexerLexerStaticData->sharedContextCache);
}

CACTLexer::~CACTLexer() {
  delete _interpreter;
}

std::string CACTLexer::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTLexer::getRuleNames() const {
  return cactlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CACTLexer::getChannelNames() const {
  return cactlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CACTLexer::getModeNames() const {
  return cactlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CACTLexer::getVocabulary() const {
  return cactlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CACTLexer::getSerializedATN() const {
  return cactlexerLexerStaticData->serializedATN;
}

const atn::ATN& CACTLexer::getATN() const {
  return *cactlexerLexerStaticData->atn;
}




void CACTLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cactlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(cactlexerLexerOnceFlag, cactlexerLexerInitialize);
#endif
}