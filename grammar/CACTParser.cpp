
    #include "include/ir/operand.h"
    #include "include/analysis/symTable.h"


// Generated from CACT.g4 by ANTLR 4.13.1


#include "CACTVisitor.h"

#include "CACTParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CACTParserStaticData final {
  CACTParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CACTParserStaticData(const CACTParserStaticData&) = delete;
  CACTParserStaticData(CACTParserStaticData&&) = delete;
  CACTParserStaticData& operator=(const CACTParserStaticData&) = delete;
  CACTParserStaticData& operator=(CACTParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cactParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CACTParserStaticData *cactParserStaticData = nullptr;

void cactParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cactParserStaticData != nullptr) {
    return;
  }
#else
  assert(cactParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CACTParserStaticData>(
    std::vector<std::string>{
      "start", "compUnit", "decl", "constDecl", "varDecl", "bType", "constDef", 
      "varDef", "constInitVal", "constExp", "initNum", "num", "funcDef", 
      "funcType", "funcFParams", "funcFParam", "funcBlock", "block", "blockItem", 
      "stmt", "lVal", "exp", "addExp", "mulExp", "unaryExp", "priExp", "funcRParams", 
      "lOrExp", "lAndExp", "eqExp", "relExp"
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
  	4,1,43,353,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,1,0,1,0,1,1,1,1,5,1,67,8,1,10,1,12,1,70,9,1,1,
  	1,1,1,1,2,1,2,3,2,76,8,2,1,3,1,3,1,3,1,3,1,3,5,3,83,8,3,10,3,12,3,86,
  	9,3,1,3,1,3,1,4,1,4,1,4,1,4,5,4,94,8,4,10,4,12,4,97,9,4,1,4,1,4,1,5,1,
  	5,1,6,1,6,1,6,1,6,5,6,107,8,6,10,6,12,6,110,9,6,1,6,1,6,1,6,1,7,1,7,1,
  	7,1,7,5,7,119,8,7,10,7,12,7,122,9,7,1,7,1,7,3,7,126,8,7,1,8,1,8,1,8,1,
  	8,1,8,5,8,133,8,8,10,8,12,8,136,9,8,3,8,138,8,8,1,8,3,8,141,8,8,1,9,1,
  	9,3,9,145,8,9,1,10,3,10,148,8,10,1,10,1,10,1,11,1,11,1,12,1,12,1,12,1,
  	12,3,12,158,8,12,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,14,5,14,168,8,14,
  	10,14,12,14,171,9,14,1,15,1,15,1,15,1,15,3,15,177,8,15,1,15,1,15,1,15,
  	1,15,5,15,183,8,15,10,15,12,15,186,9,15,3,15,188,8,15,1,16,1,16,5,16,
  	192,8,16,10,16,12,16,195,9,16,1,16,1,16,1,17,1,17,5,17,201,8,17,10,17,
  	12,17,204,9,17,1,17,1,17,1,18,1,18,3,18,210,8,18,1,19,1,19,1,19,1,19,
  	1,19,1,19,3,19,218,8,19,1,19,1,19,1,19,1,19,3,19,224,8,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,251,8,19,1,20,1,20,1,
  	20,1,20,1,20,5,20,258,8,20,10,20,12,20,261,9,20,1,21,1,21,3,21,265,8,
  	21,1,22,1,22,1,22,1,22,1,22,1,22,5,22,273,8,22,10,22,12,22,276,9,22,1,
  	23,1,23,1,23,1,23,1,23,1,23,5,23,284,8,23,10,23,12,23,287,9,23,1,24,1,
  	24,1,24,1,24,1,24,1,24,3,24,295,8,24,1,24,3,24,298,8,24,1,25,1,25,1,25,
  	1,25,1,25,1,25,3,25,306,8,25,1,26,1,26,1,26,5,26,311,8,26,10,26,12,26,
  	314,9,26,1,27,1,27,1,27,1,27,1,27,1,27,5,27,322,8,27,10,27,12,27,325,
  	9,27,1,28,1,28,1,28,1,28,1,28,1,28,5,28,333,8,28,10,28,12,28,336,9,28,
  	1,29,1,29,1,29,1,29,1,29,3,29,343,8,29,1,30,1,30,1,30,1,30,1,30,1,30,
  	3,30,351,8,30,1,30,0,4,44,46,54,56,31,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,0,8,1,0,5,8,
  	1,0,22,23,1,0,38,40,1,0,4,8,1,0,24,26,2,0,22,23,35,35,1,0,27,28,1,0,29,
  	32,367,0,62,1,0,0,0,2,68,1,0,0,0,4,75,1,0,0,0,6,77,1,0,0,0,8,89,1,0,0,
  	0,10,100,1,0,0,0,12,102,1,0,0,0,14,114,1,0,0,0,16,140,1,0,0,0,18,144,
  	1,0,0,0,20,147,1,0,0,0,22,151,1,0,0,0,24,153,1,0,0,0,26,162,1,0,0,0,28,
  	164,1,0,0,0,30,172,1,0,0,0,32,189,1,0,0,0,34,198,1,0,0,0,36,209,1,0,0,
  	0,38,250,1,0,0,0,40,252,1,0,0,0,42,264,1,0,0,0,44,266,1,0,0,0,46,277,
  	1,0,0,0,48,297,1,0,0,0,50,305,1,0,0,0,52,307,1,0,0,0,54,315,1,0,0,0,56,
  	326,1,0,0,0,58,342,1,0,0,0,60,350,1,0,0,0,62,63,3,2,1,0,63,1,1,0,0,0,
  	64,67,3,4,2,0,65,67,3,24,12,0,66,64,1,0,0,0,66,65,1,0,0,0,67,70,1,0,0,
  	0,68,66,1,0,0,0,68,69,1,0,0,0,69,71,1,0,0,0,70,68,1,0,0,0,71,72,5,0,0,
  	1,72,3,1,0,0,0,73,76,3,6,3,0,74,76,3,8,4,0,75,73,1,0,0,0,75,74,1,0,0,
  	0,76,5,1,0,0,0,77,78,5,1,0,0,78,79,3,10,5,0,79,84,3,12,6,0,80,81,5,2,
  	0,0,81,83,3,12,6,0,82,80,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,84,85,1,
  	0,0,0,85,87,1,0,0,0,86,84,1,0,0,0,87,88,5,3,0,0,88,7,1,0,0,0,89,90,3,
  	10,5,0,90,95,3,14,7,0,91,92,5,2,0,0,92,94,3,14,7,0,93,91,1,0,0,0,94,97,
  	1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,98,1,0,0,0,97,95,1,0,0,0,98,99,
  	5,3,0,0,99,9,1,0,0,0,100,101,7,0,0,0,101,11,1,0,0,0,102,108,5,37,0,0,
  	103,104,5,10,0,0,104,105,5,40,0,0,105,107,5,11,0,0,106,103,1,0,0,0,107,
  	110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,111,1,0,0,0,110,108,1,
  	0,0,0,111,112,5,9,0,0,112,113,3,16,8,0,113,13,1,0,0,0,114,120,5,37,0,
  	0,115,116,5,10,0,0,116,117,5,40,0,0,117,119,5,11,0,0,118,115,1,0,0,0,
  	119,122,1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,0,121,125,1,0,0,0,122,120,
  	1,0,0,0,123,124,5,9,0,0,124,126,3,16,8,0,125,123,1,0,0,0,125,126,1,0,
  	0,0,126,15,1,0,0,0,127,141,3,18,9,0,128,137,5,12,0,0,129,134,3,16,8,0,
  	130,131,5,2,0,0,131,133,3,16,8,0,132,130,1,0,0,0,133,136,1,0,0,0,134,
  	132,1,0,0,0,134,135,1,0,0,0,135,138,1,0,0,0,136,134,1,0,0,0,137,129,1,
  	0,0,0,137,138,1,0,0,0,138,139,1,0,0,0,139,141,5,13,0,0,140,127,1,0,0,
  	0,140,128,1,0,0,0,141,17,1,0,0,0,142,145,3,20,10,0,143,145,5,36,0,0,144,
  	142,1,0,0,0,144,143,1,0,0,0,145,19,1,0,0,0,146,148,7,1,0,0,147,146,1,
  	0,0,0,147,148,1,0,0,0,148,149,1,0,0,0,149,150,3,22,11,0,150,21,1,0,0,
  	0,151,152,7,2,0,0,152,23,1,0,0,0,153,154,3,26,13,0,154,155,5,37,0,0,155,
  	157,5,14,0,0,156,158,3,28,14,0,157,156,1,0,0,0,157,158,1,0,0,0,158,159,
  	1,0,0,0,159,160,5,15,0,0,160,161,3,32,16,0,161,25,1,0,0,0,162,163,7,3,
  	0,0,163,27,1,0,0,0,164,169,3,30,15,0,165,166,5,2,0,0,166,168,3,30,15,
  	0,167,165,1,0,0,0,168,171,1,0,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,
  	29,1,0,0,0,171,169,1,0,0,0,172,173,3,10,5,0,173,187,5,37,0,0,174,176,
  	5,10,0,0,175,177,5,40,0,0,176,175,1,0,0,0,176,177,1,0,0,0,177,178,1,0,
  	0,0,178,184,5,11,0,0,179,180,5,10,0,0,180,181,5,40,0,0,181,183,5,11,0,
  	0,182,179,1,0,0,0,183,186,1,0,0,0,184,182,1,0,0,0,184,185,1,0,0,0,185,
  	188,1,0,0,0,186,184,1,0,0,0,187,174,1,0,0,0,187,188,1,0,0,0,188,31,1,
  	0,0,0,189,193,5,12,0,0,190,192,3,36,18,0,191,190,1,0,0,0,192,195,1,0,
  	0,0,193,191,1,0,0,0,193,194,1,0,0,0,194,196,1,0,0,0,195,193,1,0,0,0,196,
  	197,5,13,0,0,197,33,1,0,0,0,198,202,5,12,0,0,199,201,3,36,18,0,200,199,
  	1,0,0,0,201,204,1,0,0,0,202,200,1,0,0,0,202,203,1,0,0,0,203,205,1,0,0,
  	0,204,202,1,0,0,0,205,206,5,13,0,0,206,35,1,0,0,0,207,210,3,4,2,0,208,
  	210,3,38,19,0,209,207,1,0,0,0,209,208,1,0,0,0,210,37,1,0,0,0,211,212,
  	3,40,20,0,212,213,5,9,0,0,213,214,3,42,21,0,214,215,5,3,0,0,215,251,1,
  	0,0,0,216,218,3,42,21,0,217,216,1,0,0,0,217,218,1,0,0,0,218,219,1,0,0,
  	0,219,251,5,3,0,0,220,251,3,34,17,0,221,223,5,16,0,0,222,224,3,42,21,
  	0,223,222,1,0,0,0,223,224,1,0,0,0,224,225,1,0,0,0,225,251,5,3,0,0,226,
  	227,5,17,0,0,227,228,5,14,0,0,228,229,3,54,27,0,229,230,5,15,0,0,230,
  	231,3,38,19,0,231,251,1,0,0,0,232,233,5,17,0,0,233,234,5,14,0,0,234,235,
  	3,54,27,0,235,236,5,15,0,0,236,237,3,38,19,0,237,238,5,18,0,0,238,239,
  	3,38,19,0,239,251,1,0,0,0,240,241,5,19,0,0,241,242,5,14,0,0,242,243,3,
  	54,27,0,243,244,5,15,0,0,244,245,3,38,19,0,245,251,1,0,0,0,246,247,5,
  	20,0,0,247,251,5,3,0,0,248,249,5,21,0,0,249,251,5,3,0,0,250,211,1,0,0,
  	0,250,217,1,0,0,0,250,220,1,0,0,0,250,221,1,0,0,0,250,226,1,0,0,0,250,
  	232,1,0,0,0,250,240,1,0,0,0,250,246,1,0,0,0,250,248,1,0,0,0,251,39,1,
  	0,0,0,252,259,5,37,0,0,253,254,5,10,0,0,254,255,3,42,21,0,255,256,5,11,
  	0,0,256,258,1,0,0,0,257,253,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,0,259,
  	260,1,0,0,0,260,41,1,0,0,0,261,259,1,0,0,0,262,265,3,44,22,0,263,265,
  	5,36,0,0,264,262,1,0,0,0,264,263,1,0,0,0,265,43,1,0,0,0,266,267,6,22,
  	-1,0,267,268,3,46,23,0,268,274,1,0,0,0,269,270,10,1,0,0,270,271,7,1,0,
  	0,271,273,3,46,23,0,272,269,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,274,
  	275,1,0,0,0,275,45,1,0,0,0,276,274,1,0,0,0,277,278,6,23,-1,0,278,279,
  	3,48,24,0,279,285,1,0,0,0,280,281,10,1,0,0,281,282,7,4,0,0,282,284,3,
  	48,24,0,283,280,1,0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,
  	0,286,47,1,0,0,0,287,285,1,0,0,0,288,298,3,50,25,0,289,290,7,5,0,0,290,
  	298,3,48,24,0,291,292,5,37,0,0,292,294,5,14,0,0,293,295,3,52,26,0,294,
  	293,1,0,0,0,294,295,1,0,0,0,295,296,1,0,0,0,296,298,5,15,0,0,297,288,
  	1,0,0,0,297,289,1,0,0,0,297,291,1,0,0,0,298,49,1,0,0,0,299,306,3,22,11,
  	0,300,301,5,14,0,0,301,302,3,42,21,0,302,303,5,15,0,0,303,306,1,0,0,0,
  	304,306,3,40,20,0,305,299,1,0,0,0,305,300,1,0,0,0,305,304,1,0,0,0,306,
  	51,1,0,0,0,307,312,3,42,21,0,308,309,5,2,0,0,309,311,3,42,21,0,310,308,
  	1,0,0,0,311,314,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,53,1,0,0,
  	0,314,312,1,0,0,0,315,316,6,27,-1,0,316,317,3,56,28,0,317,323,1,0,0,0,
  	318,319,10,1,0,0,319,320,5,33,0,0,320,322,3,56,28,0,321,318,1,0,0,0,322,
  	325,1,0,0,0,323,321,1,0,0,0,323,324,1,0,0,0,324,55,1,0,0,0,325,323,1,
  	0,0,0,326,327,6,28,-1,0,327,328,3,58,29,0,328,334,1,0,0,0,329,330,10,
  	1,0,0,330,331,5,34,0,0,331,333,3,58,29,0,332,329,1,0,0,0,333,336,1,0,
  	0,0,334,332,1,0,0,0,334,335,1,0,0,0,335,57,1,0,0,0,336,334,1,0,0,0,337,
  	343,3,60,30,0,338,339,3,60,30,0,339,340,7,6,0,0,340,341,3,60,30,0,341,
  	343,1,0,0,0,342,337,1,0,0,0,342,338,1,0,0,0,343,59,1,0,0,0,344,351,3,
  	44,22,0,345,346,3,44,22,0,346,347,7,7,0,0,347,348,3,44,22,0,348,351,1,
  	0,0,0,349,351,5,36,0,0,350,344,1,0,0,0,350,345,1,0,0,0,350,349,1,0,0,
  	0,351,61,1,0,0,0,36,66,68,75,84,95,108,120,125,134,137,140,144,147,157,
  	169,176,184,187,193,202,209,217,223,250,259,264,274,285,294,297,305,312,
  	323,334,342,350
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cactParserStaticData = staticData.release();
}

}

CACTParser::CACTParser(TokenStream *input) : CACTParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CACTParser::CACTParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CACTParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *cactParserStaticData->atn, cactParserStaticData->decisionToDFA, cactParserStaticData->sharedContextCache, options);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

const atn::ATN& CACTParser::getATN() const {
  return *cactParserStaticData->atn;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return cactParserStaticData->ruleNames;
}

const dfa::Vocabulary& CACTParser::getVocabulary() const {
  return cactParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CACTParser::getSerializedATN() const {
  return cactParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CACTParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::CompUnitContext* CACTParser::StartContext::compUnit() {
  return getRuleContext<CACTParser::CompUnitContext>(0);
}


size_t CACTParser::StartContext::getRuleIndex() const {
  return CACTParser::RuleStart;
}


std::any CACTParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitBegin(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::StartContext* CACTParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    compUnit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}


std::any CACTParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 498) != 0)) {
      setState(66);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(64);
        decl();
        break;
      }

      case 2: {
        setState(65);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(71);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}


std::any CACTParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        constDecl();
        break;
      }

      case CACTParser::BOOL:
      case CACTParser::INT:
      case CACTParser::FLOAT:
      case CACTParser::DOUBLE: {
        enterOuterAlt(_localctx, 2);
        setState(74);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ConstDeclContext::CONST() {
  return getToken(CACTParser::CONST, 0);
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}

tree::TerminalNode* CACTParser::ConstDeclContext::SEMICOLON() {
  return getToken(CACTParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> CACTParser::ConstDeclContext::COMMA() {
  return getTokens(CACTParser::COMMA);
}

tree::TerminalNode* CACTParser::ConstDeclContext::COMMA(size_t i) {
  return getToken(CACTParser::COMMA, i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}


std::any CACTParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(CACTParser::CONST);
    setState(78);
    bType();
    setState(79);
    constDef();
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::COMMA) {
      setState(80);
      match(CACTParser::COMMA);
      setState(81);
      constDef();
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(87);
    match(CACTParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}

tree::TerminalNode* CACTParser::VarDeclContext::SEMICOLON() {
  return getToken(CACTParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> CACTParser::VarDeclContext::COMMA() {
  return getTokens(CACTParser::COMMA);
}

tree::TerminalNode* CACTParser::VarDeclContext::COMMA(size_t i) {
  return getToken(CACTParser::COMMA, i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}


std::any CACTParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    bType();
    setState(90);
    varDef();
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::COMMA) {
      setState(91);
      match(CACTParser::COMMA);
      setState(92);
      varDef();
      setState(97);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98);
    match(CACTParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::BTypeContext::BOOL() {
  return getToken(CACTParser::BOOL, 0);
}

tree::TerminalNode* CACTParser::BTypeContext::INT() {
  return getToken(CACTParser::INT, 0);
}

tree::TerminalNode* CACTParser::BTypeContext::FLOAT() {
  return getToken(CACTParser::FLOAT, 0);
}

tree::TerminalNode* CACTParser::BTypeContext::DOUBLE() {
  return getToken(CACTParser::DOUBLE, 0);
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}


std::any CACTParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleBType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 480) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ConstDefContext::IDENT() {
  return getToken(CACTParser::IDENT, 0);
}

tree::TerminalNode* CACTParser::ConstDefContext::EQUALS() {
  return getToken(CACTParser::EQUALS, 0);
}

CACTParser::ConstInitValContext* CACTParser::ConstDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}

std::vector<tree::TerminalNode *> CACTParser::ConstDefContext::LBRACKET() {
  return getTokens(CACTParser::LBRACKET);
}

tree::TerminalNode* CACTParser::ConstDefContext::LBRACKET(size_t i) {
  return getToken(CACTParser::LBRACKET, i);
}

std::vector<tree::TerminalNode *> CACTParser::ConstDefContext::INTCONST() {
  return getTokens(CACTParser::INTCONST);
}

tree::TerminalNode* CACTParser::ConstDefContext::INTCONST(size_t i) {
  return getToken(CACTParser::INTCONST, i);
}

std::vector<tree::TerminalNode *> CACTParser::ConstDefContext::RBRACKET() {
  return getTokens(CACTParser::RBRACKET);
}

tree::TerminalNode* CACTParser::ConstDefContext::RBRACKET(size_t i) {
  return getToken(CACTParser::RBRACKET, i);
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}


std::any CACTParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    match(CACTParser::IDENT);
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::LBRACKET) {
      setState(103);
      match(CACTParser::LBRACKET);
      setState(104);
      match(CACTParser::INTCONST);
      setState(105);
      match(CACTParser::RBRACKET);
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(111);
    match(CACTParser::EQUALS);
    setState(112);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::VarDefContext::IDENT() {
  return getToken(CACTParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> CACTParser::VarDefContext::LBRACKET() {
  return getTokens(CACTParser::LBRACKET);
}

tree::TerminalNode* CACTParser::VarDefContext::LBRACKET(size_t i) {
  return getToken(CACTParser::LBRACKET, i);
}

std::vector<tree::TerminalNode *> CACTParser::VarDefContext::INTCONST() {
  return getTokens(CACTParser::INTCONST);
}

tree::TerminalNode* CACTParser::VarDefContext::INTCONST(size_t i) {
  return getToken(CACTParser::INTCONST, i);
}

std::vector<tree::TerminalNode *> CACTParser::VarDefContext::RBRACKET() {
  return getTokens(CACTParser::RBRACKET);
}

tree::TerminalNode* CACTParser::VarDefContext::RBRACKET(size_t i) {
  return getToken(CACTParser::RBRACKET, i);
}

tree::TerminalNode* CACTParser::VarDefContext::EQUALS() {
  return getToken(CACTParser::EQUALS, 0);
}

CACTParser::ConstInitValContext* CACTParser::VarDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}


std::any CACTParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(CACTParser::IDENT);
    setState(120);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::LBRACKET) {
      setState(115);
      match(CACTParser::LBRACKET);
      setState(116);
      match(CACTParser::INTCONST);
      setState(117);
      match(CACTParser::RBRACKET);
      setState(122);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::EQUALS) {
      setState(123);
      match(CACTParser::EQUALS);
      setState(124);
      constInitVal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

CACTParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstInitValContext::getRuleIndex() const {
  return CACTParser::RuleConstInitVal;
}

void CACTParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->datatype = ctx->datatype;
  this->dimsize = ctx->dimsize;
  this->dimarr = ctx->dimarr;
  this->initval = ctx->initval;
}

//----------------- ConstInitValNestedContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstInitValNestedContext::LBRACE() {
  return getToken(CACTParser::LBRACE, 0);
}

tree::TerminalNode* CACTParser::ConstInitValNestedContext::RBRACE() {
  return getToken(CACTParser::RBRACE, 0);
}

std::vector<CACTParser::ConstInitValContext *> CACTParser::ConstInitValNestedContext::constInitVal() {
  return getRuleContexts<CACTParser::ConstInitValContext>();
}

CACTParser::ConstInitValContext* CACTParser::ConstInitValNestedContext::constInitVal(size_t i) {
  return getRuleContext<CACTParser::ConstInitValContext>(i);
}

std::vector<tree::TerminalNode *> CACTParser::ConstInitValNestedContext::COMMA() {
  return getTokens(CACTParser::COMMA);
}

tree::TerminalNode* CACTParser::ConstInitValNestedContext::COMMA(size_t i) {
  return getToken(CACTParser::COMMA, i);
}

CACTParser::ConstInitValNestedContext::ConstInitValNestedContext(ConstInitValContext *ctx) { copyFrom(ctx); }


std::any CACTParser::ConstInitValNestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitConstInitValNested(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstInitValBasicContext ------------------------------------------------------------------

CACTParser::ConstExpContext* CACTParser::ConstInitValBasicContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstInitValBasicContext::ConstInitValBasicContext(ConstInitValContext *ctx) { copyFrom(ctx); }


std::any CACTParser::ConstInitValBasicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitConstInitValBasic(this);
  else
    return visitor->visitChildren(this);
}
CACTParser::ConstInitValContext* CACTParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(140);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::BOOLCONST:
      case CACTParser::DOUBLECONST:
      case CACTParser::FLOATCONST:
      case CACTParser::INTCONST: {
        _localctx = _tracker.createInstance<CACTParser::ConstInitValBasicContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(127);
        constExp();
        break;
      }

      case CACTParser::LBRACE: {
        _localctx = _tracker.createInstance<CACTParser::ConstInitValNestedContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(128);
        match(CACTParser::LBRACE);
        setState(137);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1992877412352) != 0)) {
          setState(129);
          constInitVal();
          setState(134);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CACTParser::COMMA) {
            setState(130);
            match(CACTParser::COMMA);
            setState(131);
            constInitVal();
            setState(136);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(139);
        match(CACTParser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::InitNumContext* CACTParser::ConstExpContext::initNum() {
  return getRuleContext<CACTParser::InitNumContext>(0);
}

tree::TerminalNode* CACTParser::ConstExpContext::BOOLCONST() {
  return getToken(CACTParser::BOOLCONST, 0);
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}


std::any CACTParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::DOUBLECONST:
      case CACTParser::FLOATCONST:
      case CACTParser::INTCONST: {
        enterOuterAlt(_localctx, 1);
        setState(142);
        initNum();
        break;
      }

      case CACTParser::BOOLCONST: {
        enterOuterAlt(_localctx, 2);
        setState(143);
        match(CACTParser::BOOLCONST);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitNumContext ------------------------------------------------------------------

CACTParser::InitNumContext::InitNumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::NumContext* CACTParser::InitNumContext::num() {
  return getRuleContext<CACTParser::NumContext>(0);
}

tree::TerminalNode* CACTParser::InitNumContext::ADD() {
  return getToken(CACTParser::ADD, 0);
}

tree::TerminalNode* CACTParser::InitNumContext::SUB() {
  return getToken(CACTParser::SUB, 0);
}


size_t CACTParser::InitNumContext::getRuleIndex() const {
  return CACTParser::RuleInitNum;
}


std::any CACTParser::InitNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitInitNum(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::InitNumContext* CACTParser::initNum() {
  InitNumContext *_localctx = _tracker.createInstance<InitNumContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleInitNum);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::ADD

    || _la == CACTParser::SUB) {
      setState(146);
      _la = _input->LA(1);
      if (!(_la == CACTParser::ADD

      || _la == CACTParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(149);
    num();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

CACTParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::NumContext::INTCONST() {
  return getToken(CACTParser::INTCONST, 0);
}

tree::TerminalNode* CACTParser::NumContext::FLOATCONST() {
  return getToken(CACTParser::FLOATCONST, 0);
}

tree::TerminalNode* CACTParser::NumContext::DOUBLECONST() {
  return getToken(CACTParser::DOUBLECONST, 0);
}


size_t CACTParser::NumContext::getRuleIndex() const {
  return CACTParser::RuleNum;
}


std::any CACTParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::NumContext* CACTParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleNum);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1924145348608) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::IDENT() {
  return getToken(CACTParser::IDENT, 0);
}

tree::TerminalNode* CACTParser::FuncDefContext::LPARENTHESE() {
  return getToken(CACTParser::LPARENTHESE, 0);
}

tree::TerminalNode* CACTParser::FuncDefContext::RPARENTHESE() {
  return getToken(CACTParser::RPARENTHESE, 0);
}

CACTParser::FuncBlockContext* CACTParser::FuncDefContext::funcBlock() {
  return getRuleContext<CACTParser::FuncBlockContext>(0);
}

CACTParser::FuncFParamsContext* CACTParser::FuncDefContext::funcFParams() {
  return getRuleContext<CACTParser::FuncFParamsContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}


std::any CACTParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    funcType();
    setState(154);
    match(CACTParser::IDENT);
    setState(155);
    match(CACTParser::LPARENTHESE);
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 480) != 0)) {
      setState(156);
      funcFParams();
    }
    setState(159);
    match(CACTParser::RPARENTHESE);
    setState(160);
    funcBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::FuncTypeContext::VOID() {
  return getToken(CACTParser::VOID, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::BOOL() {
  return getToken(CACTParser::BOOL, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::INT() {
  return getToken(CACTParser::INT, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::FLOAT() {
  return getToken(CACTParser::FLOAT, 0);
}

tree::TerminalNode* CACTParser::FuncTypeContext::DOUBLE() {
  return getToken(CACTParser::DOUBLE, 0);
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}


std::any CACTParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 496) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

CACTParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}

std::vector<tree::TerminalNode *> CACTParser::FuncFParamsContext::COMMA() {
  return getTokens(CACTParser::COMMA);
}

tree::TerminalNode* CACTParser::FuncFParamsContext::COMMA(size_t i) {
  return getToken(CACTParser::COMMA, i);
}


size_t CACTParser::FuncFParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParams;
}


std::any CACTParser::FuncFParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitFuncFParams(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::FuncFParamsContext* CACTParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleFuncFParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    funcFParam();
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::COMMA) {
      setState(165);
      match(CACTParser::COMMA);
      setState(166);
      funcFParam();
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::IDENT() {
  return getToken(CACTParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> CACTParser::FuncFParamContext::LBRACKET() {
  return getTokens(CACTParser::LBRACKET);
}

tree::TerminalNode* CACTParser::FuncFParamContext::LBRACKET(size_t i) {
  return getToken(CACTParser::LBRACKET, i);
}

std::vector<tree::TerminalNode *> CACTParser::FuncFParamContext::RBRACKET() {
  return getTokens(CACTParser::RBRACKET);
}

tree::TerminalNode* CACTParser::FuncFParamContext::RBRACKET(size_t i) {
  return getToken(CACTParser::RBRACKET, i);
}

std::vector<tree::TerminalNode *> CACTParser::FuncFParamContext::INTCONST() {
  return getTokens(CACTParser::INTCONST);
}

tree::TerminalNode* CACTParser::FuncFParamContext::INTCONST(size_t i) {
  return getToken(CACTParser::INTCONST, i);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}


std::any CACTParser::FuncFParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitFuncFParam(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleFuncFParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    bType();
    setState(173);
    match(CACTParser::IDENT);
    setState(187);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::LBRACKET) {
      setState(174);
      match(CACTParser::LBRACKET);
      setState(176);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::INTCONST) {
        setState(175);
        match(CACTParser::INTCONST);
      }
      setState(178);
      match(CACTParser::RBRACKET);
      setState(184);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CACTParser::LBRACKET) {
        setState(179);
        match(CACTParser::LBRACKET);
        setState(180);
        match(CACTParser::INTCONST);
        setState(181);
        match(CACTParser::RBRACKET);
        setState(186);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBlockContext ------------------------------------------------------------------

CACTParser::FuncBlockContext::FuncBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::FuncBlockContext::LBRACE() {
  return getToken(CACTParser::LBRACE, 0);
}

tree::TerminalNode* CACTParser::FuncBlockContext::RBRACE() {
  return getToken(CACTParser::RBRACE, 0);
}

std::vector<CACTParser::BlockItemContext *> CACTParser::FuncBlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::FuncBlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::FuncBlockContext::getRuleIndex() const {
  return CACTParser::RuleFuncBlock;
}


std::any CACTParser::FuncBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitFuncBlock(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::FuncBlockContext* CACTParser::funcBlock() {
  FuncBlockContext *_localctx = _tracker.createInstance<FuncBlockContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleFuncBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(CACTParser::LBRACE);
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2164679987690) != 0)) {
      setState(190);
      blockItem();
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(196);
    match(CACTParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::BlockContext::LBRACE() {
  return getToken(CACTParser::LBRACE, 0);
}

tree::TerminalNode* CACTParser::BlockContext::RBRACE() {
  return getToken(CACTParser::RBRACE, 0);
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}


std::any CACTParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(CACTParser::LBRACE);
    setState(202);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2164679987690) != 0)) {
      setState(199);
      blockItem();
      setState(204);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(205);
    match(CACTParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}

void CACTParser::BlockItemContext::copyFrom(BlockItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->returnCheck = ctx->returnCheck;
  this->newLabel = ctx->newLabel;
  this->next = ctx->next;
}

//----------------- BlockItemStmtContext ------------------------------------------------------------------

CACTParser::StmtContext* CACTParser::BlockItemStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::BlockItemStmtContext::BlockItemStmtContext(BlockItemContext *ctx) { copyFrom(ctx); }


std::any CACTParser::BlockItemStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitBlockItemStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockItemDeclContext ------------------------------------------------------------------

CACTParser::DeclContext* CACTParser::BlockItemDeclContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::BlockItemDeclContext::BlockItemDeclContext(BlockItemContext *ctx) { copyFrom(ctx); }


std::any CACTParser::BlockItemDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitBlockItemDecl(this);
  else
    return visitor->visitChildren(this);
}
CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::CONST:
      case CACTParser::BOOL:
      case CACTParser::INT:
      case CACTParser::FLOAT:
      case CACTParser::DOUBLE: {
        _localctx = _tracker.createInstance<CACTParser::BlockItemDeclContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(207);
        decl();
        break;
      }

      case CACTParser::SEMICOLON:
      case CACTParser::LBRACE:
      case CACTParser::LPARENTHESE:
      case CACTParser::RETURN:
      case CACTParser::IF:
      case CACTParser::WHILE:
      case CACTParser::BREAK:
      case CACTParser::CONTINUE:
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::NOT:
      case CACTParser::BOOLCONST:
      case CACTParser::IDENT:
      case CACTParser::DOUBLECONST:
      case CACTParser::FLOATCONST:
      case CACTParser::INTCONST: {
        _localctx = _tracker.createInstance<CACTParser::BlockItemStmtContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(208);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->returnCheck = ctx->returnCheck;
  this->before = ctx->before;
  this->next = ctx->next;
  this->newLabel = ctx->newLabel;
}

//----------------- StmtExpContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::StmtExpContext::SEMICOLON() {
  return getToken(CACTParser::SEMICOLON, 0);
}

CACTParser::ExpContext* CACTParser::StmtExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtExpContext::StmtExpContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtBlockContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::StmtBlockContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtBreakContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::StmtBreakContext::BREAK() {
  return getToken(CACTParser::BREAK, 0);
}

tree::TerminalNode* CACTParser::StmtBreakContext::SEMICOLON() {
  return getToken(CACTParser::SEMICOLON, 0);
}

CACTParser::StmtBreakContext::StmtBreakContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtBreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtBreak(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtWhileContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::StmtWhileContext::WHILE() {
  return getToken(CACTParser::WHILE, 0);
}

tree::TerminalNode* CACTParser::StmtWhileContext::LPARENTHESE() {
  return getToken(CACTParser::LPARENTHESE, 0);
}

CACTParser::LOrExpContext* CACTParser::StmtWhileContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

tree::TerminalNode* CACTParser::StmtWhileContext::RPARENTHESE() {
  return getToken(CACTParser::RPARENTHESE, 0);
}

CACTParser::StmtContext* CACTParser::StmtWhileContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::StmtWhileContext::StmtWhileContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtIfContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::StmtIfContext::IF() {
  return getToken(CACTParser::IF, 0);
}

tree::TerminalNode* CACTParser::StmtIfContext::LPARENTHESE() {
  return getToken(CACTParser::LPARENTHESE, 0);
}

CACTParser::LOrExpContext* CACTParser::StmtIfContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

tree::TerminalNode* CACTParser::StmtIfContext::RPARENTHESE() {
  return getToken(CACTParser::RPARENTHESE, 0);
}

CACTParser::StmtContext* CACTParser::StmtIfContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::StmtIfContext::StmtIfContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtIfElseContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::StmtIfElseContext::IF() {
  return getToken(CACTParser::IF, 0);
}

tree::TerminalNode* CACTParser::StmtIfElseContext::LPARENTHESE() {
  return getToken(CACTParser::LPARENTHESE, 0);
}

CACTParser::LOrExpContext* CACTParser::StmtIfElseContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

tree::TerminalNode* CACTParser::StmtIfElseContext::RPARENTHESE() {
  return getToken(CACTParser::RPARENTHESE, 0);
}

std::vector<CACTParser::StmtContext *> CACTParser::StmtIfElseContext::stmt() {
  return getRuleContexts<CACTParser::StmtContext>();
}

CACTParser::StmtContext* CACTParser::StmtIfElseContext::stmt(size_t i) {
  return getRuleContext<CACTParser::StmtContext>(i);
}

tree::TerminalNode* CACTParser::StmtIfElseContext::ELSE() {
  return getToken(CACTParser::ELSE, 0);
}

CACTParser::StmtIfElseContext::StmtIfElseContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtIfElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtIfElse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtReturnContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::StmtReturnContext::RETURN() {
  return getToken(CACTParser::RETURN, 0);
}

tree::TerminalNode* CACTParser::StmtReturnContext::SEMICOLON() {
  return getToken(CACTParser::SEMICOLON, 0);
}

CACTParser::ExpContext* CACTParser::StmtReturnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtContinueContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::StmtContinueContext::CONTINUE() {
  return getToken(CACTParser::CONTINUE, 0);
}

tree::TerminalNode* CACTParser::StmtContinueContext::SEMICOLON() {
  return getToken(CACTParser::SEMICOLON, 0);
}

CACTParser::StmtContinueContext::StmtContinueContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtContinueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtContinue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtAssignContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::StmtAssignContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

tree::TerminalNode* CACTParser::StmtAssignContext::EQUALS() {
  return getToken(CACTParser::EQUALS, 0);
}

CACTParser::ExpContext* CACTParser::StmtAssignContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

tree::TerminalNode* CACTParser::StmtAssignContext::SEMICOLON() {
  return getToken(CACTParser::SEMICOLON, 0);
}

CACTParser::StmtAssignContext::StmtAssignContext(StmtContext *ctx) { copyFrom(ctx); }


std::any CACTParser::StmtAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitStmtAssign(this);
  else
    return visitor->visitChildren(this);
}
CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(250);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::StmtAssignContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(211);
      lVal();
      setState(212);
      match(CACTParser::EQUALS);
      setState(213);
      exp();
      setState(214);
      match(CACTParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::StmtExpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(217);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2164676116480) != 0)) {
        setState(216);
        exp();
      }
      setState(219);
      match(CACTParser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CACTParser::StmtBlockContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(220);
      block();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CACTParser::StmtReturnContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(221);
      match(CACTParser::RETURN);
      setState(223);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2164676116480) != 0)) {
        setState(222);
        exp();
      }
      setState(225);
      match(CACTParser::SEMICOLON);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CACTParser::StmtIfContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(226);
      match(CACTParser::IF);
      setState(227);
      match(CACTParser::LPARENTHESE);
      setState(228);
      lOrExp(0);
      setState(229);
      match(CACTParser::RPARENTHESE);
      setState(230);
      stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CACTParser::StmtIfElseContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(232);
      match(CACTParser::IF);
      setState(233);
      match(CACTParser::LPARENTHESE);
      setState(234);
      lOrExp(0);
      setState(235);
      match(CACTParser::RPARENTHESE);
      setState(236);
      stmt();
      setState(237);
      match(CACTParser::ELSE);
      setState(238);
      stmt();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CACTParser::StmtWhileContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(240);
      match(CACTParser::WHILE);
      setState(241);
      match(CACTParser::LPARENTHESE);
      setState(242);
      lOrExp(0);
      setState(243);
      match(CACTParser::RPARENTHESE);
      setState(244);
      stmt();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CACTParser::StmtBreakContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(246);
      match(CACTParser::BREAK);
      setState(247);
      match(CACTParser::SEMICOLON);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CACTParser::StmtContinueContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(248);
      match(CACTParser::CONTINUE);
      setState(249);
      match(CACTParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::LValContext::IDENT() {
  return getToken(CACTParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> CACTParser::LValContext::LBRACKET() {
  return getTokens(CACTParser::LBRACKET);
}

tree::TerminalNode* CACTParser::LValContext::LBRACKET(size_t i) {
  return getToken(CACTParser::LBRACKET, i);
}

std::vector<CACTParser::ExpContext *> CACTParser::LValContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::LValContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> CACTParser::LValContext::RBRACKET() {
  return getTokens(CACTParser::RBRACKET);
}

tree::TerminalNode* CACTParser::LValContext::RBRACKET(size_t i) {
  return getToken(CACTParser::RBRACKET, i);
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}


std::any CACTParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(CACTParser::IDENT);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(253);
        match(CACTParser::LBRACKET);
        setState(254);
        exp();
        setState(255);
        match(CACTParser::RBRACKET); 
      }
      setState(261);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::AddExpContext* CACTParser::ExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::ExpContext::BOOLCONST() {
  return getToken(CACTParser::BOOLCONST, 0);
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}


std::any CACTParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::LPARENTHESE:
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::NOT:
      case CACTParser::IDENT:
      case CACTParser::DOUBLECONST:
      case CACTParser::FLOATCONST:
      case CACTParser::INTCONST: {
        enterOuterAlt(_localctx, 1);
        setState(262);
        addExp(0);
        break;
      }

      case CACTParser::BOOLCONST: {
        enterOuterAlt(_localctx, 2);
        setState(263);
        match(CACTParser::BOOLCONST);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->datatype = ctx->datatype;
  this->dimsize = ctx->dimsize;
  this->dimarr = ctx->dimarr;
  this->result = ctx->result;
}

//----------------- AddExpaddContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::AddExpaddContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::MulExpContext* CACTParser::AddExpaddContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

tree::TerminalNode* CACTParser::AddExpaddContext::ADD() {
  return getToken(CACTParser::ADD, 0);
}

tree::TerminalNode* CACTParser::AddExpaddContext::SUB() {
  return getToken(CACTParser::SUB, 0);
}

CACTParser::AddExpaddContext::AddExpaddContext(AddExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::AddExpaddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitAddExpadd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddExpmulContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::AddExpmulContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpmulContext::AddExpmulContext(AddExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::AddExpmulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitAddExpmul(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CACTParser::RuleAddExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AddExpmulContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(267);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(274);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddExpaddContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(269);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(270);
        antlrcpp::downCast<AddExpaddContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CACTParser::ADD

        || _la == CACTParser::SUB)) {
          antlrcpp::downCast<AddExpaddContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(271);
        mulExp(0); 
      }
      setState(276);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->datatype = ctx->datatype;
  this->dimsize = ctx->dimsize;
  this->dimarr = ctx->dimarr;
  this->result = ctx->result;
}

//----------------- MulExpmulContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::MulExpmulContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::MulExpmulContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

tree::TerminalNode* CACTParser::MulExpmulContext::MUL() {
  return getToken(CACTParser::MUL, 0);
}

tree::TerminalNode* CACTParser::MulExpmulContext::DIV() {
  return getToken(CACTParser::DIV, 0);
}

tree::TerminalNode* CACTParser::MulExpmulContext::MOD() {
  return getToken(CACTParser::MOD, 0);
}

CACTParser::MulExpmulContext::MulExpmulContext(MulExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::MulExpmulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitMulExpmul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulExpunaContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::MulExpunaContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpunaContext::MulExpunaContext(MulExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::MulExpunaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitMulExpuna(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CACTParser::RuleMulExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulExpunaContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(278);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(285);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulExpmulContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(280);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(281);
        antlrcpp::downCast<MulExpmulContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 117440512) != 0))) {
          antlrcpp::downCast<MulExpmulContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(282);
        unaryExp(); 
      }
      setState(287);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->datatype = ctx->datatype;
  this->dimsize = ctx->dimsize;
  this->dimarr = ctx->dimarr;
  this->result = ctx->result;
}

//----------------- UnaryExppriContext ------------------------------------------------------------------

CACTParser::PriExpContext* CACTParser::UnaryExppriContext::priExp() {
  return getRuleContext<CACTParser::PriExpContext>(0);
}

CACTParser::UnaryExppriContext::UnaryExppriContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::UnaryExppriContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitUnaryExppri(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExpunaContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::UnaryExpunaContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

tree::TerminalNode* CACTParser::UnaryExpunaContext::ADD() {
  return getToken(CACTParser::ADD, 0);
}

tree::TerminalNode* CACTParser::UnaryExpunaContext::SUB() {
  return getToken(CACTParser::SUB, 0);
}

tree::TerminalNode* CACTParser::UnaryExpunaContext::NOT() {
  return getToken(CACTParser::NOT, 0);
}

CACTParser::UnaryExpunaContext::UnaryExpunaContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::UnaryExpunaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitUnaryExpuna(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExpfunContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::UnaryExpfunContext::IDENT() {
  return getToken(CACTParser::IDENT, 0);
}

tree::TerminalNode* CACTParser::UnaryExpfunContext::LPARENTHESE() {
  return getToken(CACTParser::LPARENTHESE, 0);
}

tree::TerminalNode* CACTParser::UnaryExpfunContext::RPARENTHESE() {
  return getToken(CACTParser::RPARENTHESE, 0);
}

CACTParser::FuncRParamsContext* CACTParser::UnaryExpfunContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::UnaryExpfunContext::UnaryExpfunContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::UnaryExpfunContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitUnaryExpfun(this);
  else
    return visitor->visitChildren(this);
}
CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 48, CACTParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::UnaryExppriContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(288);
      priExp();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::UnaryExpunaContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(289);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 34372321280) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(290);
      unaryExp();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CACTParser::UnaryExpfunContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(291);
      match(CACTParser::IDENT);
      setState(292);
      match(CACTParser::LPARENTHESE);
      setState(294);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2164676116480) != 0)) {
        setState(293);
        funcRParams();
      }
      setState(296);
      match(CACTParser::RPARENTHESE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PriExpContext ------------------------------------------------------------------

CACTParser::PriExpContext::PriExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::PriExpContext::getRuleIndex() const {
  return CACTParser::RulePriExp;
}

void CACTParser::PriExpContext::copyFrom(PriExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->datatype = ctx->datatype;
  this->dimsize = ctx->dimsize;
  this->dimarr = ctx->dimarr;
  this->result = ctx->result;
}

//----------------- PriExpNumContext ------------------------------------------------------------------

CACTParser::NumContext* CACTParser::PriExpNumContext::num() {
  return getRuleContext<CACTParser::NumContext>(0);
}

CACTParser::PriExpNumContext::PriExpNumContext(PriExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::PriExpNumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitPriExpNum(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PriExpLvalContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::PriExpLvalContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::PriExpLvalContext::PriExpLvalContext(PriExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::PriExpLvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitPriExpLval(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PriExpNestedContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::PriExpNestedContext::LPARENTHESE() {
  return getToken(CACTParser::LPARENTHESE, 0);
}

CACTParser::ExpContext* CACTParser::PriExpNestedContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

tree::TerminalNode* CACTParser::PriExpNestedContext::RPARENTHESE() {
  return getToken(CACTParser::RPARENTHESE, 0);
}

CACTParser::PriExpNestedContext::PriExpNestedContext(PriExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::PriExpNestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitPriExpNested(this);
  else
    return visitor->visitChildren(this);
}
CACTParser::PriExpContext* CACTParser::priExp() {
  PriExpContext *_localctx = _tracker.createInstance<PriExpContext>(_ctx, getState());
  enterRule(_localctx, 50, CACTParser::RulePriExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::DOUBLECONST:
      case CACTParser::FLOATCONST:
      case CACTParser::INTCONST: {
        _localctx = _tracker.createInstance<CACTParser::PriExpNumContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(299);
        num();
        break;
      }

      case CACTParser::LPARENTHESE: {
        _localctx = _tracker.createInstance<CACTParser::PriExpNestedContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(300);
        match(CACTParser::LPARENTHESE);
        setState(301);
        exp();
        setState(302);
        match(CACTParser::RPARENTHESE);
        break;
      }

      case CACTParser::IDENT: {
        _localctx = _tracker.createInstance<CACTParser::PriExpLvalContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(304);
        lVal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> CACTParser::FuncRParamsContext::COMMA() {
  return getTokens(CACTParser::COMMA);
}

tree::TerminalNode* CACTParser::FuncRParamsContext::COMMA(size_t i) {
  return getToken(CACTParser::COMMA, i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}


std::any CACTParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 52, CACTParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    exp();
    setState(312);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::COMMA) {
      setState(308);
      match(CACTParser::COMMA);
      setState(309);
      exp();
      setState(314);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->True = ctx->True;
  this->False = ctx->False;
  this->first = ctx->first;
  this->newLabel = ctx->newLabel;
}

//----------------- LOrExpandContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LOrExpandContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpandContext::LOrExpandContext(LOrExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::LOrExpandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitLOrExpand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LOrExporContext ------------------------------------------------------------------

CACTParser::LOrExpContext* CACTParser::LOrExporContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

tree::TerminalNode* CACTParser::LOrExporContext::OR() {
  return getToken(CACTParser::OR, 0);
}

CACTParser::LAndExpContext* CACTParser::LOrExporContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExporContext::LOrExporContext(LOrExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::LOrExporContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitLOrExpor(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, CACTParser::RuleLOrExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LOrExpandContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(316);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(323);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LOrExporContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(318);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(319);
        match(CACTParser::OR);
        setState(320);
        lAndExp(0); 
      }
      setState(325);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->True = ctx->True;
  this->False = ctx->False;
  this->first = ctx->first;
  this->newLabel = ctx->newLabel;
}

//----------------- LAndExpeqContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::LAndExpeqContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpeqContext::LAndExpeqContext(LAndExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::LAndExpeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitLAndExpeq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LAndExpandContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LAndExpandContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

tree::TerminalNode* CACTParser::LAndExpandContext::AND() {
  return getToken(CACTParser::AND, 0);
}

CACTParser::EqExpContext* CACTParser::LAndExpandContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpandContext::LAndExpandContext(LAndExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::LAndExpandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitLAndExpand(this);
  else
    return visitor->visitChildren(this);
}

CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleLAndExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LAndExpeqContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(327);
    eqExp();
    _ctx->stop = _input->LT(-1);
    setState(334);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LAndExpandContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(329);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(330);
        match(CACTParser::AND);
        setState(331);
        eqExp(); 
      }
      setState(336);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->True = ctx->True;
  this->False = ctx->False;
}

//----------------- EqExpeqContext ------------------------------------------------------------------

std::vector<CACTParser::RelExpContext *> CACTParser::EqExpeqContext::relExp() {
  return getRuleContexts<CACTParser::RelExpContext>();
}

CACTParser::RelExpContext* CACTParser::EqExpeqContext::relExp(size_t i) {
  return getRuleContext<CACTParser::RelExpContext>(i);
}

tree::TerminalNode* CACTParser::EqExpeqContext::EQ() {
  return getToken(CACTParser::EQ, 0);
}

tree::TerminalNode* CACTParser::EqExpeqContext::NE() {
  return getToken(CACTParser::NE, 0);
}

CACTParser::EqExpeqContext::EqExpeqContext(EqExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::EqExpeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitEqExpeq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqExprelContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::EqExprelContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExprelContext::EqExprelContext(EqExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::EqExprelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitEqExprel(this);
  else
    return visitor->visitChildren(this);
}
CACTParser::EqExpContext* CACTParser::eqExp() {
  EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, getState());
  enterRule(_localctx, 58, CACTParser::RuleEqExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(342);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::EqExprelContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(337);
      relExp();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::EqExpeqContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(338);
      relExp();
      setState(339);
      _la = _input->LA(1);
      if (!(_la == CACTParser::EQ

      || _la == CACTParser::NE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(340);
      relExp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->True = ctx->True;
  this->False = ctx->False;
  this->jump = ctx->jump;
  this->datatype = ctx->datatype;
  this->result = ctx->result;
}

//----------------- RelExpboolContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RelExpboolContext::BOOLCONST() {
  return getToken(CACTParser::BOOLCONST, 0);
}

CACTParser::RelExpboolContext::RelExpboolContext(RelExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::RelExpboolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitRelExpbool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelExpaddContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::RelExpaddContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpaddContext::RelExpaddContext(RelExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::RelExpaddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitRelExpadd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelExprelContext ------------------------------------------------------------------

std::vector<CACTParser::AddExpContext *> CACTParser::RelExprelContext::addExp() {
  return getRuleContexts<CACTParser::AddExpContext>();
}

CACTParser::AddExpContext* CACTParser::RelExprelContext::addExp(size_t i) {
  return getRuleContext<CACTParser::AddExpContext>(i);
}

tree::TerminalNode* CACTParser::RelExprelContext::LT() {
  return getToken(CACTParser::LT, 0);
}

tree::TerminalNode* CACTParser::RelExprelContext::GT() {
  return getToken(CACTParser::GT, 0);
}

tree::TerminalNode* CACTParser::RelExprelContext::LE() {
  return getToken(CACTParser::LE, 0);
}

tree::TerminalNode* CACTParser::RelExprelContext::GE() {
  return getToken(CACTParser::GE, 0);
}

CACTParser::RelExprelContext::RelExprelContext(RelExpContext *ctx) { copyFrom(ctx); }


std::any CACTParser::RelExprelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CACTVisitor*>(visitor))
    return parserVisitor->visitRelExprel(this);
  else
    return visitor->visitChildren(this);
}
CACTParser::RelExpContext* CACTParser::relExp() {
  RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, getState());
  enterRule(_localctx, 60, CACTParser::RuleRelExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(350);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::RelExpaddContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(344);
      addExp(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::RelExprelContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(345);
      addExp(0);
      setState(346);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8053063680) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(347);
      addExp(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CACTParser::RelExpboolContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(349);
      match(CACTParser::BOOLCONST);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 22: return addExpSempred(antlrcpp::downCast<AddExpContext *>(context), predicateIndex);
    case 23: return mulExpSempred(antlrcpp::downCast<MulExpContext *>(context), predicateIndex);
    case 27: return lOrExpSempred(antlrcpp::downCast<LOrExpContext *>(context), predicateIndex);
    case 28: return lAndExpSempred(antlrcpp::downCast<LAndExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void CACTParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cactParserInitialize();
#else
  ::antlr4::internal::call_once(cactParserOnceFlag, cactParserInitialize);
#endif
}
