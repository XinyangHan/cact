// Generated from /home/stu/Documents/CP/cact_cp/cact/grammar/CACT.g4 by ANTLR 4.13.1

    #include <vector>

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class CACTLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		CONST=1, COMMA=2, SEMICOLON=3, VOID=4, BOOL=5, INT=6, FLOAT=7, DOUBLE=8, 
		EQUALS=9, LBRACKET=10, RBRACKET=11, LBRACE=12, RBRACE=13, LPARENTHESE=14, 
		RPARENTHESE=15, RETURN=16, IF=17, ELSE=18, WHILE=19, BREAK=20, CONTINUE=21, 
		ADD=22, SUB=23, MUL=24, DIV=25, MOD=26, EQ=27, NE=28, LT=29, GT=30, LE=31, 
		GE=32, OR=33, AND=34, NOT=35, BOOLCONST=36, IDENT=37, DOUBLECONST=38, 
		FLOATCONST=39, INTCONST=40, WS=41, BLOCKCOMM=42, LINECOMM=43;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"CONST", "COMMA", "SEMICOLON", "VOID", "BOOL", "INT", "FLOAT", "DOUBLE", 
			"EQUALS", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPARENTHESE", 
			"RPARENTHESE", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
			"ADD", "SUB", "MUL", "DIV", "MOD", "EQ", "NE", "LT", "GT", "LE", "GE", 
			"OR", "AND", "NOT", "BOOLCONST", "IDENT", "DOUBLECONST", "DIGITS", "FLOATCONST", 
			"FLOATPRE", "INTCONST", "DECCONST", "OCTCONST", "HEXCONST", "HEXPRE", 
			"WS", "BLOCKCOMM", "LINECOMM"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'const'", "','", "';'", "'void'", "'bool'", "'int'", "'float'", 
			"'double'", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'return'", 
			"'if'", "'else'", "'while'", "'break'", "'continue'", "'+'", "'-'", "'*'", 
			"'/'", "'%'", "'=='", "'!='", "'<'", "'>'", "'<='", "'>='", "'||'", "'&&'", 
			"'!'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "CONST", "COMMA", "SEMICOLON", "VOID", "BOOL", "INT", "FLOAT", 
			"DOUBLE", "EQUALS", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPARENTHESE", 
			"RPARENTHESE", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", 
			"ADD", "SUB", "MUL", "DIV", "MOD", "EQ", "NE", "LT", "GT", "LE", "GE", 
			"OR", "AND", "NOT", "BOOLCONST", "IDENT", "DOUBLECONST", "FLOATCONST", 
			"INTCONST", "WS", "BLOCKCOMM", "LINECOMM"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public CACTLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "CACT.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000+\u0152\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002"+
		"\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002"+
		"\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002"+
		"\u001b\u0007\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002"+
		"\u001e\u0007\u001e\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007"+
		"!\u0002\"\u0007\"\u0002#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007"+
		"&\u0002\'\u0007\'\u0002(\u0007(\u0002)\u0007)\u0002*\u0007*\u0002+\u0007"+
		"+\u0002,\u0007,\u0002-\u0007-\u0002.\u0007.\u0002/\u0007/\u00020\u0007"+
		"0\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\n\u0001\n\u0001\u000b"+
		"\u0001\u000b\u0001\f\u0001\f\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0017\u0001\u0017\u0001"+
		"\u0018\u0001\u0018\u0001\u0019\u0001\u0019\u0001\u001a\u0001\u001a\u0001"+
		"\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001c\u0001\u001c\u0001"+
		"\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001f\u0001"+
		"\u001f\u0001\u001f\u0001 \u0001 \u0001 \u0001!\u0001!\u0001!\u0001\"\u0001"+
		"\"\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0003"+
		"#\u00e6\b#\u0001$\u0001$\u0005$\u00ea\b$\n$\f$\u00ed\t$\u0001%\u0001%"+
		"\u0001%\u0001%\u0003%\u00f3\b%\u0001%\u0001%\u0003%\u00f7\b%\u0001%\u0001"+
		"%\u0003%\u00fb\b%\u0001%\u0003%\u00fe\b%\u0001%\u0001%\u0003%\u0102\b"+
		"%\u0001%\u0001%\u0003%\u0106\b%\u0001&\u0004&\u0109\b&\u000b&\f&\u010a"+
		"\u0001\'\u0001\'\u0001\'\u0001(\u0001(\u0001)\u0001)\u0001)\u0003)\u0115"+
		"\b)\u0001*\u0001*\u0001*\u0005*\u011a\b*\n*\f*\u011d\t*\u0003*\u011f\b"+
		"*\u0001+\u0001+\u0004+\u0123\b+\u000b+\f+\u0124\u0001,\u0001,\u0004,\u0129"+
		"\b,\u000b,\f,\u012a\u0001-\u0001-\u0001-\u0001-\u0003-\u0131\b-\u0001"+
		".\u0004.\u0134\b.\u000b.\f.\u0135\u0001.\u0001.\u0001/\u0001/\u0001/\u0001"+
		"/\u0005/\u013e\b/\n/\f/\u0141\t/\u0001/\u0001/\u0001/\u0001/\u0001/\u0001"+
		"0\u00010\u00010\u00010\u00050\u014c\b0\n0\f0\u014f\t0\u00010\u00010\u0001"+
		"\u013f\u00001\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005"+
		"\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019"+
		"\r\u001b\u000e\u001d\u000f\u001f\u0010!\u0011#\u0012%\u0013\'\u0014)\u0015"+
		"+\u0016-\u0017/\u00181\u00193\u001a5\u001b7\u001c9\u001d;\u001e=\u001f"+
		"? A!C\"E#G$I%K&M\u0000O\'Q\u0000S(U\u0000W\u0000Y\u0000[\u0000])_*a+\u0001"+
		"\u0000\u000b\u0003\u0000AZ__az\u0004\u000009AZ__az\u0002\u0000EEee\u0002"+
		"\u0000++--\u0001\u000009\u0002\u0000FFff\u0001\u000019\u0001\u000007\u0003"+
		"\u000009AFaf\u0003\u0000\t\n\r\r  \u0002\u0000\n\n\r\r\u015e\u0000\u0001"+
		"\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005"+
		"\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001"+
		"\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000"+
		"\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000"+
		"\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000"+
		"\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019\u0001\u0000"+
		"\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d\u0001\u0000"+
		"\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001\u0000\u0000"+
		"\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001\u0000\u0000\u0000\u0000"+
		"\'\u0001\u0000\u0000\u0000\u0000)\u0001\u0000\u0000\u0000\u0000+\u0001"+
		"\u0000\u0000\u0000\u0000-\u0001\u0000\u0000\u0000\u0000/\u0001\u0000\u0000"+
		"\u0000\u00001\u0001\u0000\u0000\u0000\u00003\u0001\u0000\u0000\u0000\u0000"+
		"5\u0001\u0000\u0000\u0000\u00007\u0001\u0000\u0000\u0000\u00009\u0001"+
		"\u0000\u0000\u0000\u0000;\u0001\u0000\u0000\u0000\u0000=\u0001\u0000\u0000"+
		"\u0000\u0000?\u0001\u0000\u0000\u0000\u0000A\u0001\u0000\u0000\u0000\u0000"+
		"C\u0001\u0000\u0000\u0000\u0000E\u0001\u0000\u0000\u0000\u0000G\u0001"+
		"\u0000\u0000\u0000\u0000I\u0001\u0000\u0000\u0000\u0000K\u0001\u0000\u0000"+
		"\u0000\u0000O\u0001\u0000\u0000\u0000\u0000S\u0001\u0000\u0000\u0000\u0000"+
		"]\u0001\u0000\u0000\u0000\u0000_\u0001\u0000\u0000\u0000\u0000a\u0001"+
		"\u0000\u0000\u0000\u0001c\u0001\u0000\u0000\u0000\u0003i\u0001\u0000\u0000"+
		"\u0000\u0005k\u0001\u0000\u0000\u0000\u0007m\u0001\u0000\u0000\u0000\t"+
		"r\u0001\u0000\u0000\u0000\u000bw\u0001\u0000\u0000\u0000\r{\u0001\u0000"+
		"\u0000\u0000\u000f\u0081\u0001\u0000\u0000\u0000\u0011\u0088\u0001\u0000"+
		"\u0000\u0000\u0013\u008a\u0001\u0000\u0000\u0000\u0015\u008c\u0001\u0000"+
		"\u0000\u0000\u0017\u008e\u0001\u0000\u0000\u0000\u0019\u0090\u0001\u0000"+
		"\u0000\u0000\u001b\u0092\u0001\u0000\u0000\u0000\u001d\u0094\u0001\u0000"+
		"\u0000\u0000\u001f\u0096\u0001\u0000\u0000\u0000!\u009d\u0001\u0000\u0000"+
		"\u0000#\u00a0\u0001\u0000\u0000\u0000%\u00a5\u0001\u0000\u0000\u0000\'"+
		"\u00ab\u0001\u0000\u0000\u0000)\u00b1\u0001\u0000\u0000\u0000+\u00ba\u0001"+
		"\u0000\u0000\u0000-\u00bc\u0001\u0000\u0000\u0000/\u00be\u0001\u0000\u0000"+
		"\u00001\u00c0\u0001\u0000\u0000\u00003\u00c2\u0001\u0000\u0000\u00005"+
		"\u00c4\u0001\u0000\u0000\u00007\u00c7\u0001\u0000\u0000\u00009\u00ca\u0001"+
		"\u0000\u0000\u0000;\u00cc\u0001\u0000\u0000\u0000=\u00ce\u0001\u0000\u0000"+
		"\u0000?\u00d1\u0001\u0000\u0000\u0000A\u00d4\u0001\u0000\u0000\u0000C"+
		"\u00d7\u0001\u0000\u0000\u0000E\u00da\u0001\u0000\u0000\u0000G\u00e5\u0001"+
		"\u0000\u0000\u0000I\u00e7\u0001\u0000\u0000\u0000K\u0105\u0001\u0000\u0000"+
		"\u0000M\u0108\u0001\u0000\u0000\u0000O\u010c\u0001\u0000\u0000\u0000Q"+
		"\u010f\u0001\u0000\u0000\u0000S\u0114\u0001\u0000\u0000\u0000U\u011e\u0001"+
		"\u0000\u0000\u0000W\u0120\u0001\u0000\u0000\u0000Y\u0126\u0001\u0000\u0000"+
		"\u0000[\u0130\u0001\u0000\u0000\u0000]\u0133\u0001\u0000\u0000\u0000_"+
		"\u0139\u0001\u0000\u0000\u0000a\u0147\u0001\u0000\u0000\u0000cd\u0005"+
		"c\u0000\u0000de\u0005o\u0000\u0000ef\u0005n\u0000\u0000fg\u0005s\u0000"+
		"\u0000gh\u0005t\u0000\u0000h\u0002\u0001\u0000\u0000\u0000ij\u0005,\u0000"+
		"\u0000j\u0004\u0001\u0000\u0000\u0000kl\u0005;\u0000\u0000l\u0006\u0001"+
		"\u0000\u0000\u0000mn\u0005v\u0000\u0000no\u0005o\u0000\u0000op\u0005i"+
		"\u0000\u0000pq\u0005d\u0000\u0000q\b\u0001\u0000\u0000\u0000rs\u0005b"+
		"\u0000\u0000st\u0005o\u0000\u0000tu\u0005o\u0000\u0000uv\u0005l\u0000"+
		"\u0000v\n\u0001\u0000\u0000\u0000wx\u0005i\u0000\u0000xy\u0005n\u0000"+
		"\u0000yz\u0005t\u0000\u0000z\f\u0001\u0000\u0000\u0000{|\u0005f\u0000"+
		"\u0000|}\u0005l\u0000\u0000}~\u0005o\u0000\u0000~\u007f\u0005a\u0000\u0000"+
		"\u007f\u0080\u0005t\u0000\u0000\u0080\u000e\u0001\u0000\u0000\u0000\u0081"+
		"\u0082\u0005d\u0000\u0000\u0082\u0083\u0005o\u0000\u0000\u0083\u0084\u0005"+
		"u\u0000\u0000\u0084\u0085\u0005b\u0000\u0000\u0085\u0086\u0005l\u0000"+
		"\u0000\u0086\u0087\u0005e\u0000\u0000\u0087\u0010\u0001\u0000\u0000\u0000"+
		"\u0088\u0089\u0005=\u0000\u0000\u0089\u0012\u0001\u0000\u0000\u0000\u008a"+
		"\u008b\u0005[\u0000\u0000\u008b\u0014\u0001\u0000\u0000\u0000\u008c\u008d"+
		"\u0005]\u0000\u0000\u008d\u0016\u0001\u0000\u0000\u0000\u008e\u008f\u0005"+
		"{\u0000\u0000\u008f\u0018\u0001\u0000\u0000\u0000\u0090\u0091\u0005}\u0000"+
		"\u0000\u0091\u001a\u0001\u0000\u0000\u0000\u0092\u0093\u0005(\u0000\u0000"+
		"\u0093\u001c\u0001\u0000\u0000\u0000\u0094\u0095\u0005)\u0000\u0000\u0095"+
		"\u001e\u0001\u0000\u0000\u0000\u0096\u0097\u0005r\u0000\u0000\u0097\u0098"+
		"\u0005e\u0000\u0000\u0098\u0099\u0005t\u0000\u0000\u0099\u009a\u0005u"+
		"\u0000\u0000\u009a\u009b\u0005r\u0000\u0000\u009b\u009c\u0005n\u0000\u0000"+
		"\u009c \u0001\u0000\u0000\u0000\u009d\u009e\u0005i\u0000\u0000\u009e\u009f"+
		"\u0005f\u0000\u0000\u009f\"\u0001\u0000\u0000\u0000\u00a0\u00a1\u0005"+
		"e\u0000\u0000\u00a1\u00a2\u0005l\u0000\u0000\u00a2\u00a3\u0005s\u0000"+
		"\u0000\u00a3\u00a4\u0005e\u0000\u0000\u00a4$\u0001\u0000\u0000\u0000\u00a5"+
		"\u00a6\u0005w\u0000\u0000\u00a6\u00a7\u0005h\u0000\u0000\u00a7\u00a8\u0005"+
		"i\u0000\u0000\u00a8\u00a9\u0005l\u0000\u0000\u00a9\u00aa\u0005e\u0000"+
		"\u0000\u00aa&\u0001\u0000\u0000\u0000\u00ab\u00ac\u0005b\u0000\u0000\u00ac"+
		"\u00ad\u0005r\u0000\u0000\u00ad\u00ae\u0005e\u0000\u0000\u00ae\u00af\u0005"+
		"a\u0000\u0000\u00af\u00b0\u0005k\u0000\u0000\u00b0(\u0001\u0000\u0000"+
		"\u0000\u00b1\u00b2\u0005c\u0000\u0000\u00b2\u00b3\u0005o\u0000\u0000\u00b3"+
		"\u00b4\u0005n\u0000\u0000\u00b4\u00b5\u0005t\u0000\u0000\u00b5\u00b6\u0005"+
		"i\u0000\u0000\u00b6\u00b7\u0005n\u0000\u0000\u00b7\u00b8\u0005u\u0000"+
		"\u0000\u00b8\u00b9\u0005e\u0000\u0000\u00b9*\u0001\u0000\u0000\u0000\u00ba"+
		"\u00bb\u0005+\u0000\u0000\u00bb,\u0001\u0000\u0000\u0000\u00bc\u00bd\u0005"+
		"-\u0000\u0000\u00bd.\u0001\u0000\u0000\u0000\u00be\u00bf\u0005*\u0000"+
		"\u0000\u00bf0\u0001\u0000\u0000\u0000\u00c0\u00c1\u0005/\u0000\u0000\u00c1"+
		"2\u0001\u0000\u0000\u0000\u00c2\u00c3\u0005%\u0000\u0000\u00c34\u0001"+
		"\u0000\u0000\u0000\u00c4\u00c5\u0005=\u0000\u0000\u00c5\u00c6\u0005=\u0000"+
		"\u0000\u00c66\u0001\u0000\u0000\u0000\u00c7\u00c8\u0005!\u0000\u0000\u00c8"+
		"\u00c9\u0005=\u0000\u0000\u00c98\u0001\u0000\u0000\u0000\u00ca\u00cb\u0005"+
		"<\u0000\u0000\u00cb:\u0001\u0000\u0000\u0000\u00cc\u00cd\u0005>\u0000"+
		"\u0000\u00cd<\u0001\u0000\u0000\u0000\u00ce\u00cf\u0005<\u0000\u0000\u00cf"+
		"\u00d0\u0005=\u0000\u0000\u00d0>\u0001\u0000\u0000\u0000\u00d1\u00d2\u0005"+
		">\u0000\u0000\u00d2\u00d3\u0005=\u0000\u0000\u00d3@\u0001\u0000\u0000"+
		"\u0000\u00d4\u00d5\u0005|\u0000\u0000\u00d5\u00d6\u0005|\u0000\u0000\u00d6"+
		"B\u0001\u0000\u0000\u0000\u00d7\u00d8\u0005&\u0000\u0000\u00d8\u00d9\u0005"+
		"&\u0000\u0000\u00d9D\u0001\u0000\u0000\u0000\u00da\u00db\u0005!\u0000"+
		"\u0000\u00dbF\u0001\u0000\u0000\u0000\u00dc\u00dd\u0005t\u0000\u0000\u00dd"+
		"\u00de\u0005r\u0000\u0000\u00de\u00df\u0005u\u0000\u0000\u00df\u00e6\u0005"+
		"e\u0000\u0000\u00e0\u00e1\u0005f\u0000\u0000\u00e1\u00e2\u0005a\u0000"+
		"\u0000\u00e2\u00e3\u0005l\u0000\u0000\u00e3\u00e4\u0005s\u0000\u0000\u00e4"+
		"\u00e6\u0005e\u0000\u0000\u00e5\u00dc\u0001\u0000\u0000\u0000\u00e5\u00e0"+
		"\u0001\u0000\u0000\u0000\u00e6H\u0001\u0000\u0000\u0000\u00e7\u00eb\u0007"+
		"\u0000\u0000\u0000\u00e8\u00ea\u0007\u0001\u0000\u0000\u00e9\u00e8\u0001"+
		"\u0000\u0000\u0000\u00ea\u00ed\u0001\u0000\u0000\u0000\u00eb\u00e9\u0001"+
		"\u0000\u0000\u0000\u00eb\u00ec\u0001\u0000\u0000\u0000\u00ecJ\u0001\u0000"+
		"\u0000\u0000\u00ed\u00eb\u0001\u0000\u0000\u0000\u00ee\u00ef\u0003M&\u0000"+
		"\u00ef\u00f0\u0005.\u0000\u0000\u00f0\u00f7\u0001\u0000\u0000\u0000\u00f1"+
		"\u00f3\u0003M&\u0000\u00f2\u00f1\u0001\u0000\u0000\u0000\u00f2\u00f3\u0001"+
		"\u0000\u0000\u0000\u00f3\u00f4\u0001\u0000\u0000\u0000\u00f4\u00f5\u0005"+
		".\u0000\u0000\u00f5\u00f7\u0003M&\u0000\u00f6\u00ee\u0001\u0000\u0000"+
		"\u0000\u00f6\u00f2\u0001\u0000\u0000\u0000\u00f7\u0106\u0001\u0000\u0000"+
		"\u0000\u00f8\u00fa\u0003M&\u0000\u00f9\u00fb\u0005.\u0000\u0000\u00fa"+
		"\u00f9\u0001\u0000\u0000\u0000\u00fa\u00fb\u0001\u0000\u0000\u0000\u00fb"+
		"\u00fd\u0001\u0000\u0000\u0000\u00fc\u00fe\u0003M&\u0000\u00fd\u00fc\u0001"+
		"\u0000\u0000\u0000\u00fd\u00fe\u0001\u0000\u0000\u0000\u00fe\u00ff\u0001"+
		"\u0000\u0000\u0000\u00ff\u0101\u0007\u0002\u0000\u0000\u0100\u0102\u0007"+
		"\u0003\u0000\u0000\u0101\u0100\u0001\u0000\u0000\u0000\u0101\u0102\u0001"+
		"\u0000\u0000\u0000\u0102\u0103\u0001\u0000\u0000\u0000\u0103\u0104\u0003"+
		"M&\u0000\u0104\u0106\u0001\u0000\u0000\u0000\u0105\u00f6\u0001\u0000\u0000"+
		"\u0000\u0105\u00f8\u0001\u0000\u0000\u0000\u0106L\u0001\u0000\u0000\u0000"+
		"\u0107\u0109\u0007\u0004\u0000\u0000\u0108\u0107\u0001\u0000\u0000\u0000"+
		"\u0109\u010a\u0001\u0000\u0000\u0000\u010a\u0108\u0001\u0000\u0000\u0000"+
		"\u010a\u010b\u0001\u0000\u0000\u0000\u010bN\u0001\u0000\u0000\u0000\u010c"+
		"\u010d\u0003K%\u0000\u010d\u010e\u0003Q(\u0000\u010eP\u0001\u0000\u0000"+
		"\u0000\u010f\u0110\u0007\u0005\u0000\u0000\u0110R\u0001\u0000\u0000\u0000"+
		"\u0111\u0115\u0003U*\u0000\u0112\u0115\u0003W+\u0000\u0113\u0115\u0003"+
		"Y,\u0000\u0114\u0111\u0001\u0000\u0000\u0000\u0114\u0112\u0001\u0000\u0000"+
		"\u0000\u0114\u0113\u0001\u0000\u0000\u0000\u0115T\u0001\u0000\u0000\u0000"+
		"\u0116\u011f\u00050\u0000\u0000\u0117\u011b\u0007\u0006\u0000\u0000\u0118"+
		"\u011a\u0007\u0004\u0000\u0000\u0119\u0118\u0001\u0000\u0000\u0000\u011a"+
		"\u011d\u0001\u0000\u0000\u0000\u011b\u0119\u0001\u0000\u0000\u0000\u011b"+
		"\u011c\u0001\u0000\u0000\u0000\u011c\u011f\u0001\u0000\u0000\u0000\u011d"+
		"\u011b\u0001\u0000\u0000\u0000\u011e\u0116\u0001\u0000\u0000\u0000\u011e"+
		"\u0117\u0001\u0000\u0000\u0000\u011fV\u0001\u0000\u0000\u0000\u0120\u0122"+
		"\u00050\u0000\u0000\u0121\u0123\u0007\u0007\u0000\u0000\u0122\u0121\u0001"+
		"\u0000\u0000\u0000\u0123\u0124\u0001\u0000\u0000\u0000\u0124\u0122\u0001"+
		"\u0000\u0000\u0000\u0124\u0125\u0001\u0000\u0000\u0000\u0125X\u0001\u0000"+
		"\u0000\u0000\u0126\u0128\u0003[-\u0000\u0127\u0129\u0007\b\u0000\u0000"+
		"\u0128\u0127\u0001\u0000\u0000\u0000\u0129\u012a\u0001\u0000\u0000\u0000"+
		"\u012a\u0128\u0001\u0000\u0000\u0000\u012a\u012b\u0001\u0000\u0000\u0000"+
		"\u012bZ\u0001\u0000\u0000\u0000\u012c\u012d\u00050\u0000\u0000\u012d\u0131"+
		"\u0005x\u0000\u0000\u012e\u012f\u00050\u0000\u0000\u012f\u0131\u0005X"+
		"\u0000\u0000\u0130\u012c\u0001\u0000\u0000\u0000\u0130\u012e\u0001\u0000"+
		"\u0000\u0000\u0131\\\u0001\u0000\u0000\u0000\u0132\u0134\u0007\t\u0000"+
		"\u0000\u0133\u0132\u0001\u0000\u0000\u0000\u0134\u0135\u0001\u0000\u0000"+
		"\u0000\u0135\u0133\u0001\u0000\u0000\u0000\u0135\u0136\u0001\u0000\u0000"+
		"\u0000\u0136\u0137\u0001\u0000\u0000\u0000\u0137\u0138\u0006.\u0000\u0000"+
		"\u0138^\u0001\u0000\u0000\u0000\u0139\u013a\u0005/\u0000\u0000\u013a\u013b"+
		"\u0005*\u0000\u0000\u013b\u013f\u0001\u0000\u0000\u0000\u013c\u013e\t"+
		"\u0000\u0000\u0000\u013d\u013c\u0001\u0000\u0000\u0000\u013e\u0141\u0001"+
		"\u0000\u0000\u0000\u013f\u0140\u0001\u0000\u0000\u0000\u013f\u013d\u0001"+
		"\u0000\u0000\u0000\u0140\u0142\u0001\u0000\u0000\u0000\u0141\u013f\u0001"+
		"\u0000\u0000\u0000\u0142\u0143\u0005*\u0000\u0000\u0143\u0144\u0005/\u0000"+
		"\u0000\u0144\u0145\u0001\u0000\u0000\u0000\u0145\u0146\u0006/\u0000\u0000"+
		"\u0146`\u0001\u0000\u0000\u0000\u0147\u0148\u0005/\u0000\u0000\u0148\u0149"+
		"\u0005/\u0000\u0000\u0149\u014d\u0001\u0000\u0000\u0000\u014a\u014c\b"+
		"\n\u0000\u0000\u014b\u014a\u0001\u0000\u0000\u0000\u014c\u014f\u0001\u0000"+
		"\u0000\u0000\u014d\u014b\u0001\u0000\u0000\u0000\u014d\u014e\u0001\u0000"+
		"\u0000\u0000\u014e\u0150\u0001\u0000\u0000\u0000\u014f\u014d\u0001\u0000"+
		"\u0000\u0000\u0150\u0151\u00060\u0000\u0000\u0151b\u0001\u0000\u0000\u0000"+
		"\u0013\u0000\u00e5\u00eb\u00f2\u00f6\u00fa\u00fd\u0101\u0105\u010a\u0114"+
		"\u011b\u011e\u0124\u012a\u0130\u0135\u013f\u014d\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}