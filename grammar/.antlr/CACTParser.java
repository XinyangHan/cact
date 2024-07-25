// Generated from /home/stu/Documents/CP/cact_cp/cact/grammar/CACT.g4 by ANTLR 4.13.1

    #include <vector>

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class CACTParser extends Parser {
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
	public static final int
		RULE_compUnit = 0, RULE_decl = 1, RULE_constDecl = 2, RULE_varDecl = 3, 
		RULE_bType = 4, RULE_constDef = 5, RULE_varDef = 6, RULE_constInitVal = 7, 
		RULE_constExp = 8, RULE_initNum = 9, RULE_num = 10, RULE_funcDef = 11, 
		RULE_funcType = 12, RULE_funcFParams = 13, RULE_funcFParam = 14, RULE_block = 15, 
		RULE_blockItem = 16, RULE_stmt = 17, RULE_lVal = 18, RULE_exp = 19, RULE_addExp = 20, 
		RULE_mulExp = 21, RULE_unaryExp = 22, RULE_priExp = 23, RULE_funcRParams = 24, 
		RULE_cond = 25, RULE_lOrExp = 26, RULE_lAndExp = 27, RULE_eqExp = 28, 
		RULE_relExp = 29;
	private static String[] makeRuleNames() {
		return new String[] {
			"compUnit", "decl", "constDecl", "varDecl", "bType", "constDef", "varDef", 
			"constInitVal", "constExp", "initNum", "num", "funcDef", "funcType", 
			"funcFParams", "funcFParam", "block", "blockItem", "stmt", "lVal", "exp", 
			"addExp", "mulExp", "unaryExp", "priExp", "funcRParams", "cond", "lOrExp", 
			"lAndExp", "eqExp", "relExp"
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

	@Override
	public String getGrammarFileName() { return "CACT.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public CACTParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CompUnitContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(CACTParser.EOF, 0); }
		public List<DeclContext> decl() {
			return getRuleContexts(DeclContext.class);
		}
		public DeclContext decl(int i) {
			return getRuleContext(DeclContext.class,i);
		}
		public List<FuncDefContext> funcDef() {
			return getRuleContexts(FuncDefContext.class);
		}
		public FuncDefContext funcDef(int i) {
			return getRuleContext(FuncDefContext.class,i);
		}
		public CompUnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compUnit; }
	}

	public final CompUnitContext compUnit() throws RecognitionException {
		CompUnitContext _localctx = new CompUnitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_compUnit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 498L) != 0)) {
				{
				setState(62);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(60);
					decl();
					}
					break;
				case 2:
					{
					setState(61);
					funcDef();
					}
					break;
				}
				}
				setState(66);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(67);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DeclContext extends ParserRuleContext {
		public ConstDeclContext constDecl() {
			return getRuleContext(ConstDeclContext.class,0);
		}
		public VarDeclContext varDecl() {
			return getRuleContext(VarDeclContext.class,0);
		}
		public DeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl; }
	}

	public final DeclContext decl() throws RecognitionException {
		DeclContext _localctx = new DeclContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_decl);
		try {
			setState(71);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CONST:
				enterOuterAlt(_localctx, 1);
				{
				setState(69);
				constDecl();
				}
				break;
			case BOOL:
			case INT:
			case FLOAT:
			case DOUBLE:
				enterOuterAlt(_localctx, 2);
				{
				setState(70);
				varDecl();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConstDeclContext extends ParserRuleContext {
		public TerminalNode CONST() { return getToken(CACTParser.CONST, 0); }
		public BTypeContext bType() {
			return getRuleContext(BTypeContext.class,0);
		}
		public List<ConstDefContext> constDef() {
			return getRuleContexts(ConstDefContext.class);
		}
		public ConstDefContext constDef(int i) {
			return getRuleContext(ConstDefContext.class,i);
		}
		public TerminalNode SEMICOLON() { return getToken(CACTParser.SEMICOLON, 0); }
		public List<TerminalNode> COMMA() { return getTokens(CACTParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CACTParser.COMMA, i);
		}
		public ConstDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constDecl; }
	}

	public final ConstDeclContext constDecl() throws RecognitionException {
		ConstDeclContext _localctx = new ConstDeclContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_constDecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(73);
			match(CONST);
			setState(74);
			bType();
			setState(75);
			constDef();
			setState(80);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(76);
				match(COMMA);
				setState(77);
				constDef();
				}
				}
				setState(82);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(83);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarDeclContext extends ParserRuleContext {
		public BTypeContext bType() {
			return getRuleContext(BTypeContext.class,0);
		}
		public List<VarDefContext> varDef() {
			return getRuleContexts(VarDefContext.class);
		}
		public VarDefContext varDef(int i) {
			return getRuleContext(VarDefContext.class,i);
		}
		public TerminalNode SEMICOLON() { return getToken(CACTParser.SEMICOLON, 0); }
		public List<TerminalNode> COMMA() { return getTokens(CACTParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CACTParser.COMMA, i);
		}
		public VarDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDecl; }
	}

	public final VarDeclContext varDecl() throws RecognitionException {
		VarDeclContext _localctx = new VarDeclContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_varDecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			bType();
			setState(86);
			varDef();
			setState(91);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(87);
				match(COMMA);
				setState(88);
				varDef();
				}
				}
				setState(93);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(94);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BTypeContext extends ParserRuleContext {
		public TerminalNode BOOL() { return getToken(CACTParser.BOOL, 0); }
		public TerminalNode INT() { return getToken(CACTParser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(CACTParser.FLOAT, 0); }
		public TerminalNode DOUBLE() { return getToken(CACTParser.DOUBLE, 0); }
		public BTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bType; }
	}

	public final BTypeContext bType() throws RecognitionException {
		BTypeContext _localctx = new BTypeContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_bType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(96);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 480L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConstDefContext extends ParserRuleContext {
		public TerminalNode IDENT() { return getToken(CACTParser.IDENT, 0); }
		public TerminalNode EQUALS() { return getToken(CACTParser.EQUALS, 0); }
		public ConstInitValContext constInitVal() {
			return getRuleContext(ConstInitValContext.class,0);
		}
		public List<TerminalNode> LBRACKET() { return getTokens(CACTParser.LBRACKET); }
		public TerminalNode LBRACKET(int i) {
			return getToken(CACTParser.LBRACKET, i);
		}
		public List<TerminalNode> INTCONST() { return getTokens(CACTParser.INTCONST); }
		public TerminalNode INTCONST(int i) {
			return getToken(CACTParser.INTCONST, i);
		}
		public List<TerminalNode> RBRACKET() { return getTokens(CACTParser.RBRACKET); }
		public TerminalNode RBRACKET(int i) {
			return getToken(CACTParser.RBRACKET, i);
		}
		public ConstDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constDef; }
	}

	public final ConstDefContext constDef() throws RecognitionException {
		ConstDefContext _localctx = new ConstDefContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_constDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(98);
			match(IDENT);
			setState(104);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LBRACKET) {
				{
				{
				setState(99);
				match(LBRACKET);
				setState(100);
				match(INTCONST);
				setState(101);
				match(RBRACKET);
				}
				}
				setState(106);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(107);
			match(EQUALS);
			setState(108);
			constInitVal();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarDefContext extends ParserRuleContext {
		public TerminalNode IDENT() { return getToken(CACTParser.IDENT, 0); }
		public List<TerminalNode> LBRACKET() { return getTokens(CACTParser.LBRACKET); }
		public TerminalNode LBRACKET(int i) {
			return getToken(CACTParser.LBRACKET, i);
		}
		public List<TerminalNode> INTCONST() { return getTokens(CACTParser.INTCONST); }
		public TerminalNode INTCONST(int i) {
			return getToken(CACTParser.INTCONST, i);
		}
		public List<TerminalNode> RBRACKET() { return getTokens(CACTParser.RBRACKET); }
		public TerminalNode RBRACKET(int i) {
			return getToken(CACTParser.RBRACKET, i);
		}
		public TerminalNode EQUALS() { return getToken(CACTParser.EQUALS, 0); }
		public ConstInitValContext constInitVal() {
			return getRuleContext(ConstInitValContext.class,0);
		}
		public VarDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDef; }
	}

	public final VarDefContext varDef() throws RecognitionException {
		VarDefContext _localctx = new VarDefContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_varDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			match(IDENT);
			setState(116);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LBRACKET) {
				{
				{
				setState(111);
				match(LBRACKET);
				setState(112);
				match(INTCONST);
				setState(113);
				match(RBRACKET);
				}
				}
				setState(118);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(121);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EQUALS) {
				{
				setState(119);
				match(EQUALS);
				setState(120);
				constInitVal();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConstInitValContext extends ParserRuleContext {
		public ConstExpContext constExp() {
			return getRuleContext(ConstExpContext.class,0);
		}
		public TerminalNode LBRACE() { return getToken(CACTParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(CACTParser.RBRACE, 0); }
		public List<ConstInitValContext> constInitVal() {
			return getRuleContexts(ConstInitValContext.class);
		}
		public ConstInitValContext constInitVal(int i) {
			return getRuleContext(ConstInitValContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(CACTParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CACTParser.COMMA, i);
		}
		public ConstInitValContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constInitVal; }
	}

	public final ConstInitValContext constInitVal() throws RecognitionException {
		ConstInitValContext _localctx = new ConstInitValContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_constInitVal);
		int _la;
		try {
			setState(136);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADD:
			case SUB:
			case BOOLCONST:
			case DOUBLECONST:
			case FLOATCONST:
			case INTCONST:
				enterOuterAlt(_localctx, 1);
				{
				setState(123);
				constExp();
				}
				break;
			case LBRACE:
				enterOuterAlt(_localctx, 2);
				{
				setState(124);
				match(LBRACE);
				setState(133);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1992877412352L) != 0)) {
					{
					setState(125);
					constInitVal();
					setState(130);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==COMMA) {
						{
						{
						setState(126);
						match(COMMA);
						setState(127);
						constInitVal();
						}
						}
						setState(132);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				setState(135);
				match(RBRACE);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConstExpContext extends ParserRuleContext {
		public InitNumContext initNum() {
			return getRuleContext(InitNumContext.class,0);
		}
		public TerminalNode BOOLCONST() { return getToken(CACTParser.BOOLCONST, 0); }
		public ConstExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constExp; }
	}

	public final ConstExpContext constExp() throws RecognitionException {
		ConstExpContext _localctx = new ConstExpContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_constExp);
		try {
			setState(140);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADD:
			case SUB:
			case DOUBLECONST:
			case FLOATCONST:
			case INTCONST:
				enterOuterAlt(_localctx, 1);
				{
				setState(138);
				initNum();
				}
				break;
			case BOOLCONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(139);
				match(BOOLCONST);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class InitNumContext extends ParserRuleContext {
		public NumContext num() {
			return getRuleContext(NumContext.class,0);
		}
		public TerminalNode ADD() { return getToken(CACTParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(CACTParser.SUB, 0); }
		public InitNumContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initNum; }
	}

	public final InitNumContext initNum() throws RecognitionException {
		InitNumContext _localctx = new InitNumContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_initNum);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(143);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ADD || _la==SUB) {
				{
				setState(142);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==SUB) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(145);
			num();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NumContext extends ParserRuleContext {
		public TerminalNode INTCONST() { return getToken(CACTParser.INTCONST, 0); }
		public TerminalNode FLOATCONST() { return getToken(CACTParser.FLOATCONST, 0); }
		public TerminalNode DOUBLECONST() { return getToken(CACTParser.DOUBLECONST, 0); }
		public NumContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_num; }
	}

	public final NumContext num() throws RecognitionException {
		NumContext _localctx = new NumContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_num);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(147);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 1924145348608L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FuncDefContext extends ParserRuleContext {
		public FuncTypeContext funcType() {
			return getRuleContext(FuncTypeContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(CACTParser.IDENT, 0); }
		public TerminalNode LPARENTHESE() { return getToken(CACTParser.LPARENTHESE, 0); }
		public TerminalNode RPARENTHESE() { return getToken(CACTParser.RPARENTHESE, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FuncFParamsContext funcFParams() {
			return getRuleContext(FuncFParamsContext.class,0);
		}
		public FuncDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcDef; }
	}

	public final FuncDefContext funcDef() throws RecognitionException {
		FuncDefContext _localctx = new FuncDefContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_funcDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(149);
			funcType();
			setState(150);
			match(IDENT);
			setState(151);
			match(LPARENTHESE);
			setState(153);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 480L) != 0)) {
				{
				setState(152);
				funcFParams();
				}
			}

			setState(155);
			match(RPARENTHESE);
			setState(156);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FuncTypeContext extends ParserRuleContext {
		public TerminalNode VOID() { return getToken(CACTParser.VOID, 0); }
		public TerminalNode BOOL() { return getToken(CACTParser.BOOL, 0); }
		public TerminalNode INT() { return getToken(CACTParser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(CACTParser.FLOAT, 0); }
		public TerminalNode DOUBLE() { return getToken(CACTParser.DOUBLE, 0); }
		public FuncTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcType; }
	}

	public final FuncTypeContext funcType() throws RecognitionException {
		FuncTypeContext _localctx = new FuncTypeContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_funcType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 496L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FuncFParamsContext extends ParserRuleContext {
		public List<FuncFParamContext> funcFParam() {
			return getRuleContexts(FuncFParamContext.class);
		}
		public FuncFParamContext funcFParam(int i) {
			return getRuleContext(FuncFParamContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(CACTParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CACTParser.COMMA, i);
		}
		public FuncFParamsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcFParams; }
	}

	public final FuncFParamsContext funcFParams() throws RecognitionException {
		FuncFParamsContext _localctx = new FuncFParamsContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_funcFParams);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(160);
			funcFParam();
			setState(165);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(161);
				match(COMMA);
				setState(162);
				funcFParam();
				}
				}
				setState(167);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FuncFParamContext extends ParserRuleContext {
		public BTypeContext bType() {
			return getRuleContext(BTypeContext.class,0);
		}
		public TerminalNode IDENT() { return getToken(CACTParser.IDENT, 0); }
		public List<TerminalNode> LBRACKET() { return getTokens(CACTParser.LBRACKET); }
		public TerminalNode LBRACKET(int i) {
			return getToken(CACTParser.LBRACKET, i);
		}
		public List<TerminalNode> RBRACKET() { return getTokens(CACTParser.RBRACKET); }
		public TerminalNode RBRACKET(int i) {
			return getToken(CACTParser.RBRACKET, i);
		}
		public List<TerminalNode> INTCONST() { return getTokens(CACTParser.INTCONST); }
		public TerminalNode INTCONST(int i) {
			return getToken(CACTParser.INTCONST, i);
		}
		public FuncFParamContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcFParam; }
	}

	public final FuncFParamContext funcFParam() throws RecognitionException {
		FuncFParamContext _localctx = new FuncFParamContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_funcFParam);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(168);
			bType();
			setState(169);
			match(IDENT);
			setState(183);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LBRACKET) {
				{
				setState(170);
				match(LBRACKET);
				setState(172);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==INTCONST) {
					{
					setState(171);
					match(INTCONST);
					}
				}

				setState(174);
				match(RBRACKET);
				setState(180);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==LBRACKET) {
					{
					{
					setState(175);
					match(LBRACKET);
					setState(176);
					match(INTCONST);
					setState(177);
					match(RBRACKET);
					}
					}
					setState(182);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(CACTParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(CACTParser.RBRACE, 0); }
		public List<BlockItemContext> blockItem() {
			return getRuleContexts(BlockItemContext.class);
		}
		public BlockItemContext blockItem(int i) {
			return getRuleContext(BlockItemContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(185);
			match(LBRACE);
			setState(189);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2164679987690L) != 0)) {
				{
				{
				setState(186);
				blockItem();
				}
				}
				setState(191);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(192);
			match(RBRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BlockItemContext extends ParserRuleContext {
		public DeclContext decl() {
			return getRuleContext(DeclContext.class,0);
		}
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public BlockItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockItem; }
	}

	public final BlockItemContext blockItem() throws RecognitionException {
		BlockItemContext _localctx = new BlockItemContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_blockItem);
		try {
			setState(196);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CONST:
			case BOOL:
			case INT:
			case FLOAT:
			case DOUBLE:
				enterOuterAlt(_localctx, 1);
				{
				setState(194);
				decl();
				}
				break;
			case SEMICOLON:
			case LBRACE:
			case LPARENTHESE:
			case RETURN:
			case IF:
			case WHILE:
			case BREAK:
			case CONTINUE:
			case ADD:
			case SUB:
			case NOT:
			case BOOLCONST:
			case IDENT:
			case DOUBLECONST:
			case FLOATCONST:
			case INTCONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(195);
				stmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StmtContext extends ParserRuleContext {
		public LValContext lVal() {
			return getRuleContext(LValContext.class,0);
		}
		public TerminalNode EQUALS() { return getToken(CACTParser.EQUALS, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(CACTParser.SEMICOLON, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode RETURN() { return getToken(CACTParser.RETURN, 0); }
		public TerminalNode IF() { return getToken(CACTParser.IF, 0); }
		public TerminalNode LPARENTHESE() { return getToken(CACTParser.LPARENTHESE, 0); }
		public CondContext cond() {
			return getRuleContext(CondContext.class,0);
		}
		public TerminalNode RPARENTHESE() { return getToken(CACTParser.RPARENTHESE, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(CACTParser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(CACTParser.WHILE, 0); }
		public TerminalNode BREAK() { return getToken(CACTParser.BREAK, 0); }
		public TerminalNode CONTINUE() { return getToken(CACTParser.CONTINUE, 0); }
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_stmt);
		int _la;
		try {
			setState(237);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(198);
				lVal();
				setState(199);
				match(EQUALS);
				setState(200);
				exp();
				setState(201);
				match(SEMICOLON);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(204);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2164676116480L) != 0)) {
					{
					setState(203);
					exp();
					}
				}

				setState(206);
				match(SEMICOLON);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(207);
				block();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(208);
				match(RETURN);
				setState(210);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2164676116480L) != 0)) {
					{
					setState(209);
					exp();
					}
				}

				setState(212);
				match(SEMICOLON);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(213);
				match(IF);
				setState(214);
				match(LPARENTHESE);
				setState(215);
				cond();
				setState(216);
				match(RPARENTHESE);
				setState(217);
				stmt();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(219);
				match(IF);
				setState(220);
				match(LPARENTHESE);
				setState(221);
				cond();
				setState(222);
				match(RPARENTHESE);
				setState(223);
				stmt();
				setState(224);
				match(ELSE);
				setState(225);
				stmt();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(227);
				match(WHILE);
				setState(228);
				match(LPARENTHESE);
				setState(229);
				cond();
				setState(230);
				match(RPARENTHESE);
				setState(231);
				stmt();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(233);
				match(BREAK);
				setState(234);
				match(SEMICOLON);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(235);
				match(CONTINUE);
				setState(236);
				match(SEMICOLON);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LValContext extends ParserRuleContext {
		public TerminalNode IDENT() { return getToken(CACTParser.IDENT, 0); }
		public List<TerminalNode> LBRACKET() { return getTokens(CACTParser.LBRACKET); }
		public TerminalNode LBRACKET(int i) {
			return getToken(CACTParser.LBRACKET, i);
		}
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public List<TerminalNode> RBRACKET() { return getTokens(CACTParser.RBRACKET); }
		public TerminalNode RBRACKET(int i) {
			return getToken(CACTParser.RBRACKET, i);
		}
		public LValContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lVal; }
	}

	public final LValContext lVal() throws RecognitionException {
		LValContext _localctx = new LValContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_lVal);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(239);
			match(IDENT);
			setState(246);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(240);
					match(LBRACKET);
					setState(241);
					exp();
					setState(242);
					match(RBRACKET);
					}
					} 
				}
				setState(248);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpContext extends ParserRuleContext {
		public AddExpContext addExp() {
			return getRuleContext(AddExpContext.class,0);
		}
		public TerminalNode BOOLCONST() { return getToken(CACTParser.BOOLCONST, 0); }
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
	}

	public final ExpContext exp() throws RecognitionException {
		ExpContext _localctx = new ExpContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_exp);
		try {
			setState(251);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPARENTHESE:
			case ADD:
			case SUB:
			case NOT:
			case IDENT:
			case DOUBLECONST:
			case FLOATCONST:
			case INTCONST:
				enterOuterAlt(_localctx, 1);
				{
				setState(249);
				addExp(0);
				}
				break;
			case BOOLCONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(250);
				match(BOOLCONST);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AddExpContext extends ParserRuleContext {
		public Token op;
		public MulExpContext mulExp() {
			return getRuleContext(MulExpContext.class,0);
		}
		public AddExpContext addExp() {
			return getRuleContext(AddExpContext.class,0);
		}
		public TerminalNode ADD() { return getToken(CACTParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(CACTParser.SUB, 0); }
		public AddExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_addExp; }
	}

	public final AddExpContext addExp() throws RecognitionException {
		return addExp(0);
	}

	private AddExpContext addExp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		AddExpContext _localctx = new AddExpContext(_ctx, _parentState);
		AddExpContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_addExp, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(254);
			mulExp(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(261);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new AddExpContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_addExp);
					setState(256);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(257);
					((AddExpContext)_localctx).op = _input.LT(1);
					_la = _input.LA(1);
					if ( !(_la==ADD || _la==SUB) ) {
						((AddExpContext)_localctx).op = (Token)_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(258);
					mulExp(0);
					}
					} 
				}
				setState(263);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class MulExpContext extends ParserRuleContext {
		public Token op;
		public UnaryExpContext unaryExp() {
			return getRuleContext(UnaryExpContext.class,0);
		}
		public MulExpContext mulExp() {
			return getRuleContext(MulExpContext.class,0);
		}
		public TerminalNode MUL() { return getToken(CACTParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(CACTParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(CACTParser.MOD, 0); }
		public MulExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mulExp; }
	}

	public final MulExpContext mulExp() throws RecognitionException {
		return mulExp(0);
	}

	private MulExpContext mulExp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		MulExpContext _localctx = new MulExpContext(_ctx, _parentState);
		MulExpContext _prevctx = _localctx;
		int _startState = 42;
		enterRecursionRule(_localctx, 42, RULE_mulExp, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(265);
			unaryExp();
			}
			_ctx.stop = _input.LT(-1);
			setState(272);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new MulExpContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_mulExp);
					setState(267);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(268);
					((MulExpContext)_localctx).op = _input.LT(1);
					_la = _input.LA(1);
					if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 117440512L) != 0)) ) {
						((MulExpContext)_localctx).op = (Token)_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(269);
					unaryExp();
					}
					} 
				}
				setState(274);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnaryExpContext extends ParserRuleContext {
		public PriExpContext priExp() {
			return getRuleContext(PriExpContext.class,0);
		}
		public UnaryExpContext unaryExp() {
			return getRuleContext(UnaryExpContext.class,0);
		}
		public TerminalNode ADD() { return getToken(CACTParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(CACTParser.SUB, 0); }
		public TerminalNode NOT() { return getToken(CACTParser.NOT, 0); }
		public TerminalNode IDENT() { return getToken(CACTParser.IDENT, 0); }
		public TerminalNode LPARENTHESE() { return getToken(CACTParser.LPARENTHESE, 0); }
		public TerminalNode RPARENTHESE() { return getToken(CACTParser.RPARENTHESE, 0); }
		public FuncRParamsContext funcRParams() {
			return getRuleContext(FuncRParamsContext.class,0);
		}
		public UnaryExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unaryExp; }
	}

	public final UnaryExpContext unaryExp() throws RecognitionException {
		UnaryExpContext _localctx = new UnaryExpContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_unaryExp);
		int _la;
		try {
			setState(284);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(275);
				priExp();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(276);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 34372321280L) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(277);
				unaryExp();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(278);
				match(IDENT);
				setState(279);
				match(LPARENTHESE);
				setState(281);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2164676116480L) != 0)) {
					{
					setState(280);
					funcRParams();
					}
				}

				setState(283);
				match(RPARENTHESE);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PriExpContext extends ParserRuleContext {
		public NumContext num() {
			return getRuleContext(NumContext.class,0);
		}
		public TerminalNode LPARENTHESE() { return getToken(CACTParser.LPARENTHESE, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode RPARENTHESE() { return getToken(CACTParser.RPARENTHESE, 0); }
		public LValContext lVal() {
			return getRuleContext(LValContext.class,0);
		}
		public PriExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_priExp; }
	}

	public final PriExpContext priExp() throws RecognitionException {
		PriExpContext _localctx = new PriExpContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_priExp);
		try {
			setState(292);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DOUBLECONST:
			case FLOATCONST:
			case INTCONST:
				enterOuterAlt(_localctx, 1);
				{
				setState(286);
				num();
				}
				break;
			case LPARENTHESE:
				enterOuterAlt(_localctx, 2);
				{
				setState(287);
				match(LPARENTHESE);
				setState(288);
				exp();
				setState(289);
				match(RPARENTHESE);
				}
				break;
			case IDENT:
				enterOuterAlt(_localctx, 3);
				{
				setState(291);
				lVal();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FuncRParamsContext extends ParserRuleContext {
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(CACTParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CACTParser.COMMA, i);
		}
		public FuncRParamsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcRParams; }
	}

	public final FuncRParamsContext funcRParams() throws RecognitionException {
		FuncRParamsContext _localctx = new FuncRParamsContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_funcRParams);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(294);
			exp();
			setState(299);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(295);
				match(COMMA);
				setState(296);
				exp();
				}
				}
				setState(301);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CondContext extends ParserRuleContext {
		public LOrExpContext lOrExp() {
			return getRuleContext(LOrExpContext.class,0);
		}
		public CondContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cond; }
	}

	public final CondContext cond() throws RecognitionException {
		CondContext _localctx = new CondContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_cond);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(302);
			lOrExp(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LOrExpContext extends ParserRuleContext {
		public LAndExpContext lAndExp() {
			return getRuleContext(LAndExpContext.class,0);
		}
		public LOrExpContext lOrExp() {
			return getRuleContext(LOrExpContext.class,0);
		}
		public TerminalNode OR() { return getToken(CACTParser.OR, 0); }
		public LOrExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lOrExp; }
	}

	public final LOrExpContext lOrExp() throws RecognitionException {
		return lOrExp(0);
	}

	private LOrExpContext lOrExp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LOrExpContext _localctx = new LOrExpContext(_ctx, _parentState);
		LOrExpContext _prevctx = _localctx;
		int _startState = 52;
		enterRecursionRule(_localctx, 52, RULE_lOrExp, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(305);
			lAndExp(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(312);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new LOrExpContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_lOrExp);
					setState(307);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(308);
					match(OR);
					setState(309);
					lAndExp(0);
					}
					} 
				}
				setState(314);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LAndExpContext extends ParserRuleContext {
		public EqExpContext eqExp() {
			return getRuleContext(EqExpContext.class,0);
		}
		public LAndExpContext lAndExp() {
			return getRuleContext(LAndExpContext.class,0);
		}
		public TerminalNode AND() { return getToken(CACTParser.AND, 0); }
		public LAndExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lAndExp; }
	}

	public final LAndExpContext lAndExp() throws RecognitionException {
		return lAndExp(0);
	}

	private LAndExpContext lAndExp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LAndExpContext _localctx = new LAndExpContext(_ctx, _parentState);
		LAndExpContext _prevctx = _localctx;
		int _startState = 54;
		enterRecursionRule(_localctx, 54, RULE_lAndExp, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(316);
			eqExp();
			}
			_ctx.stop = _input.LT(-1);
			setState(323);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new LAndExpContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_lAndExp);
					setState(318);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(319);
					match(AND);
					setState(320);
					eqExp();
					}
					} 
				}
				setState(325);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class EqExpContext extends ParserRuleContext {
		public List<RelExpContext> relExp() {
			return getRuleContexts(RelExpContext.class);
		}
		public RelExpContext relExp(int i) {
			return getRuleContext(RelExpContext.class,i);
		}
		public TerminalNode EQ() { return getToken(CACTParser.EQ, 0); }
		public TerminalNode NE() { return getToken(CACTParser.NE, 0); }
		public EqExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_eqExp; }
	}

	public final EqExpContext eqExp() throws RecognitionException {
		EqExpContext _localctx = new EqExpContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_eqExp);
		int _la;
		try {
			setState(331);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(326);
				relExp();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(327);
				relExp();
				setState(328);
				_la = _input.LA(1);
				if ( !(_la==EQ || _la==NE) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(329);
				relExp();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RelExpContext extends ParserRuleContext {
		public List<AddExpContext> addExp() {
			return getRuleContexts(AddExpContext.class);
		}
		public AddExpContext addExp(int i) {
			return getRuleContext(AddExpContext.class,i);
		}
		public TerminalNode LT() { return getToken(CACTParser.LT, 0); }
		public TerminalNode GE() { return getToken(CACTParser.GE, 0); }
		public TerminalNode LE() { return getToken(CACTParser.LE, 0); }
		public TerminalNode BOOLCONST() { return getToken(CACTParser.BOOLCONST, 0); }
		public RelExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relExp; }
	}

	public final RelExpContext relExp() throws RecognitionException {
		RelExpContext _localctx = new RelExpContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_relExp);
		int _la;
		try {
			setState(339);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,34,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(333);
				addExp(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(334);
				addExp(0);
				setState(335);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 6979321856L) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(336);
				addExp(0);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(338);
				match(BOOLCONST);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 20:
			return addExp_sempred((AddExpContext)_localctx, predIndex);
		case 21:
			return mulExp_sempred((MulExpContext)_localctx, predIndex);
		case 26:
			return lOrExp_sempred((LOrExpContext)_localctx, predIndex);
		case 27:
			return lAndExp_sempred((LAndExpContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean addExp_sempred(AddExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean mulExp_sempred(MulExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean lOrExp_sempred(LOrExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean lAndExp_sempred(LAndExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001+\u0156\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0001\u0000\u0001\u0000"+
		"\u0005\u0000?\b\u0000\n\u0000\f\u0000B\t\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0003\u0001H\b\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002O\b\u0002\n\u0002\f\u0002"+
		"R\t\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0005\u0003Z\b\u0003\n\u0003\f\u0003]\t\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0005\u0005g\b\u0005\n\u0005\f\u0005j\t\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0005\u0006s\b\u0006\n\u0006\f\u0006v\t\u0006\u0001\u0006\u0001\u0006"+
		"\u0003\u0006z\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0005\u0007\u0081\b\u0007\n\u0007\f\u0007\u0084\t\u0007\u0003"+
		"\u0007\u0086\b\u0007\u0001\u0007\u0003\u0007\u0089\b\u0007\u0001\b\u0001"+
		"\b\u0003\b\u008d\b\b\u0001\t\u0003\t\u0090\b\t\u0001\t\u0001\t\u0001\n"+
		"\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u009a"+
		"\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\r\u0001"+
		"\r\u0001\r\u0005\r\u00a4\b\r\n\r\f\r\u00a7\t\r\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0003\u000e\u00ad\b\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0005\u000e\u00b3\b\u000e\n\u000e\f\u000e\u00b6"+
		"\t\u000e\u0003\u000e\u00b8\b\u000e\u0001\u000f\u0001\u000f\u0005\u000f"+
		"\u00bc\b\u000f\n\u000f\f\u000f\u00bf\t\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u0010\u0001\u0010\u0003\u0010\u00c5\b\u0010\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u00cd\b\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u00d3\b\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0003\u0011\u00ee\b\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0005\u0012\u00f5\b\u0012\n\u0012\f\u0012\u00f8\t\u0012"+
		"\u0001\u0013\u0001\u0013\u0003\u0013\u00fc\b\u0013\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0005\u0014\u0104\b\u0014"+
		"\n\u0014\f\u0014\u0107\t\u0014\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0005\u0015\u010f\b\u0015\n\u0015\f\u0015"+
		"\u0112\t\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0003\u0016\u011a\b\u0016\u0001\u0016\u0003\u0016\u011d\b"+
		"\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001"+
		"\u0017\u0003\u0017\u0125\b\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0005"+
		"\u0018\u012a\b\u0018\n\u0018\f\u0018\u012d\t\u0018\u0001\u0019\u0001\u0019"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0005\u001a\u0137\b\u001a\n\u001a\f\u001a\u013a\t\u001a\u0001\u001b\u0001"+
		"\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0005\u001b\u0142"+
		"\b\u001b\n\u001b\f\u001b\u0145\t\u001b\u0001\u001c\u0001\u001c\u0001\u001c"+
		"\u0001\u001c\u0001\u001c\u0003\u001c\u014c\b\u001c\u0001\u001d\u0001\u001d"+
		"\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0003\u001d\u0154\b\u001d"+
		"\u0001\u001d\u0000\u0004(*46\u001e\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.02468:\u0000"+
		"\b\u0001\u0000\u0005\b\u0001\u0000\u0016\u0017\u0001\u0000&(\u0001\u0000"+
		"\u0004\b\u0001\u0000\u0018\u001a\u0002\u0000\u0016\u0017##\u0001\u0000"+
		"\u001b\u001c\u0002\u0000\u001d\u001d\u001f \u0164\u0000@\u0001\u0000\u0000"+
		"\u0000\u0002G\u0001\u0000\u0000\u0000\u0004I\u0001\u0000\u0000\u0000\u0006"+
		"U\u0001\u0000\u0000\u0000\b`\u0001\u0000\u0000\u0000\nb\u0001\u0000\u0000"+
		"\u0000\fn\u0001\u0000\u0000\u0000\u000e\u0088\u0001\u0000\u0000\u0000"+
		"\u0010\u008c\u0001\u0000\u0000\u0000\u0012\u008f\u0001\u0000\u0000\u0000"+
		"\u0014\u0093\u0001\u0000\u0000\u0000\u0016\u0095\u0001\u0000\u0000\u0000"+
		"\u0018\u009e\u0001\u0000\u0000\u0000\u001a\u00a0\u0001\u0000\u0000\u0000"+
		"\u001c\u00a8\u0001\u0000\u0000\u0000\u001e\u00b9\u0001\u0000\u0000\u0000"+
		" \u00c4\u0001\u0000\u0000\u0000\"\u00ed\u0001\u0000\u0000\u0000$\u00ef"+
		"\u0001\u0000\u0000\u0000&\u00fb\u0001\u0000\u0000\u0000(\u00fd\u0001\u0000"+
		"\u0000\u0000*\u0108\u0001\u0000\u0000\u0000,\u011c\u0001\u0000\u0000\u0000"+
		".\u0124\u0001\u0000\u0000\u00000\u0126\u0001\u0000\u0000\u00002\u012e"+
		"\u0001\u0000\u0000\u00004\u0130\u0001\u0000\u0000\u00006\u013b\u0001\u0000"+
		"\u0000\u00008\u014b\u0001\u0000\u0000\u0000:\u0153\u0001\u0000\u0000\u0000"+
		"<?\u0003\u0002\u0001\u0000=?\u0003\u0016\u000b\u0000><\u0001\u0000\u0000"+
		"\u0000>=\u0001\u0000\u0000\u0000?B\u0001\u0000\u0000\u0000@>\u0001\u0000"+
		"\u0000\u0000@A\u0001\u0000\u0000\u0000AC\u0001\u0000\u0000\u0000B@\u0001"+
		"\u0000\u0000\u0000CD\u0005\u0000\u0000\u0001D\u0001\u0001\u0000\u0000"+
		"\u0000EH\u0003\u0004\u0002\u0000FH\u0003\u0006\u0003\u0000GE\u0001\u0000"+
		"\u0000\u0000GF\u0001\u0000\u0000\u0000H\u0003\u0001\u0000\u0000\u0000"+
		"IJ\u0005\u0001\u0000\u0000JK\u0003\b\u0004\u0000KP\u0003\n\u0005\u0000"+
		"LM\u0005\u0002\u0000\u0000MO\u0003\n\u0005\u0000NL\u0001\u0000\u0000\u0000"+
		"OR\u0001\u0000\u0000\u0000PN\u0001\u0000\u0000\u0000PQ\u0001\u0000\u0000"+
		"\u0000QS\u0001\u0000\u0000\u0000RP\u0001\u0000\u0000\u0000ST\u0005\u0003"+
		"\u0000\u0000T\u0005\u0001\u0000\u0000\u0000UV\u0003\b\u0004\u0000V[\u0003"+
		"\f\u0006\u0000WX\u0005\u0002\u0000\u0000XZ\u0003\f\u0006\u0000YW\u0001"+
		"\u0000\u0000\u0000Z]\u0001\u0000\u0000\u0000[Y\u0001\u0000\u0000\u0000"+
		"[\\\u0001\u0000\u0000\u0000\\^\u0001\u0000\u0000\u0000][\u0001\u0000\u0000"+
		"\u0000^_\u0005\u0003\u0000\u0000_\u0007\u0001\u0000\u0000\u0000`a\u0007"+
		"\u0000\u0000\u0000a\t\u0001\u0000\u0000\u0000bh\u0005%\u0000\u0000cd\u0005"+
		"\n\u0000\u0000de\u0005(\u0000\u0000eg\u0005\u000b\u0000\u0000fc\u0001"+
		"\u0000\u0000\u0000gj\u0001\u0000\u0000\u0000hf\u0001\u0000\u0000\u0000"+
		"hi\u0001\u0000\u0000\u0000ik\u0001\u0000\u0000\u0000jh\u0001\u0000\u0000"+
		"\u0000kl\u0005\t\u0000\u0000lm\u0003\u000e\u0007\u0000m\u000b\u0001\u0000"+
		"\u0000\u0000nt\u0005%\u0000\u0000op\u0005\n\u0000\u0000pq\u0005(\u0000"+
		"\u0000qs\u0005\u000b\u0000\u0000ro\u0001\u0000\u0000\u0000sv\u0001\u0000"+
		"\u0000\u0000tr\u0001\u0000\u0000\u0000tu\u0001\u0000\u0000\u0000uy\u0001"+
		"\u0000\u0000\u0000vt\u0001\u0000\u0000\u0000wx\u0005\t\u0000\u0000xz\u0003"+
		"\u000e\u0007\u0000yw\u0001\u0000\u0000\u0000yz\u0001\u0000\u0000\u0000"+
		"z\r\u0001\u0000\u0000\u0000{\u0089\u0003\u0010\b\u0000|\u0085\u0005\f"+
		"\u0000\u0000}\u0082\u0003\u000e\u0007\u0000~\u007f\u0005\u0002\u0000\u0000"+
		"\u007f\u0081\u0003\u000e\u0007\u0000\u0080~\u0001\u0000\u0000\u0000\u0081"+
		"\u0084\u0001\u0000\u0000\u0000\u0082\u0080\u0001\u0000\u0000\u0000\u0082"+
		"\u0083\u0001\u0000\u0000\u0000\u0083\u0086\u0001\u0000\u0000\u0000\u0084"+
		"\u0082\u0001\u0000\u0000\u0000\u0085}\u0001\u0000\u0000\u0000\u0085\u0086"+
		"\u0001\u0000\u0000\u0000\u0086\u0087\u0001\u0000\u0000\u0000\u0087\u0089"+
		"\u0005\r\u0000\u0000\u0088{\u0001\u0000\u0000\u0000\u0088|\u0001\u0000"+
		"\u0000\u0000\u0089\u000f\u0001\u0000\u0000\u0000\u008a\u008d\u0003\u0012"+
		"\t\u0000\u008b\u008d\u0005$\u0000\u0000\u008c\u008a\u0001\u0000\u0000"+
		"\u0000\u008c\u008b\u0001\u0000\u0000\u0000\u008d\u0011\u0001\u0000\u0000"+
		"\u0000\u008e\u0090\u0007\u0001\u0000\u0000\u008f\u008e\u0001\u0000\u0000"+
		"\u0000\u008f\u0090\u0001\u0000\u0000\u0000\u0090\u0091\u0001\u0000\u0000"+
		"\u0000\u0091\u0092\u0003\u0014\n\u0000\u0092\u0013\u0001\u0000\u0000\u0000"+
		"\u0093\u0094\u0007\u0002\u0000\u0000\u0094\u0015\u0001\u0000\u0000\u0000"+
		"\u0095\u0096\u0003\u0018\f\u0000\u0096\u0097\u0005%\u0000\u0000\u0097"+
		"\u0099\u0005\u000e\u0000\u0000\u0098\u009a\u0003\u001a\r\u0000\u0099\u0098"+
		"\u0001\u0000\u0000\u0000\u0099\u009a\u0001\u0000\u0000\u0000\u009a\u009b"+
		"\u0001\u0000\u0000\u0000\u009b\u009c\u0005\u000f\u0000\u0000\u009c\u009d"+
		"\u0003\u001e\u000f\u0000\u009d\u0017\u0001\u0000\u0000\u0000\u009e\u009f"+
		"\u0007\u0003\u0000\u0000\u009f\u0019\u0001\u0000\u0000\u0000\u00a0\u00a5"+
		"\u0003\u001c\u000e\u0000\u00a1\u00a2\u0005\u0002\u0000\u0000\u00a2\u00a4"+
		"\u0003\u001c\u000e\u0000\u00a3\u00a1\u0001\u0000\u0000\u0000\u00a4\u00a7"+
		"\u0001\u0000\u0000\u0000\u00a5\u00a3\u0001\u0000\u0000\u0000\u00a5\u00a6"+
		"\u0001\u0000\u0000\u0000\u00a6\u001b\u0001\u0000\u0000\u0000\u00a7\u00a5"+
		"\u0001\u0000\u0000\u0000\u00a8\u00a9\u0003\b\u0004\u0000\u00a9\u00b7\u0005"+
		"%\u0000\u0000\u00aa\u00ac\u0005\n\u0000\u0000\u00ab\u00ad\u0005(\u0000"+
		"\u0000\u00ac\u00ab\u0001\u0000\u0000\u0000\u00ac\u00ad\u0001\u0000\u0000"+
		"\u0000\u00ad\u00ae\u0001\u0000\u0000\u0000\u00ae\u00b4\u0005\u000b\u0000"+
		"\u0000\u00af\u00b0\u0005\n\u0000\u0000\u00b0\u00b1\u0005(\u0000\u0000"+
		"\u00b1\u00b3\u0005\u000b\u0000\u0000\u00b2\u00af\u0001\u0000\u0000\u0000"+
		"\u00b3\u00b6\u0001\u0000\u0000\u0000\u00b4\u00b2\u0001\u0000\u0000\u0000"+
		"\u00b4\u00b5\u0001\u0000\u0000\u0000\u00b5\u00b8\u0001\u0000\u0000\u0000"+
		"\u00b6\u00b4\u0001\u0000\u0000\u0000\u00b7\u00aa\u0001\u0000\u0000\u0000"+
		"\u00b7\u00b8\u0001\u0000\u0000\u0000\u00b8\u001d\u0001\u0000\u0000\u0000"+
		"\u00b9\u00bd\u0005\f\u0000\u0000\u00ba\u00bc\u0003 \u0010\u0000\u00bb"+
		"\u00ba\u0001\u0000\u0000\u0000\u00bc\u00bf\u0001\u0000\u0000\u0000\u00bd"+
		"\u00bb\u0001\u0000\u0000\u0000\u00bd\u00be\u0001\u0000\u0000\u0000\u00be"+
		"\u00c0\u0001\u0000\u0000\u0000\u00bf\u00bd\u0001\u0000\u0000\u0000\u00c0"+
		"\u00c1\u0005\r\u0000\u0000\u00c1\u001f\u0001\u0000\u0000\u0000\u00c2\u00c5"+
		"\u0003\u0002\u0001\u0000\u00c3\u00c5\u0003\"\u0011\u0000\u00c4\u00c2\u0001"+
		"\u0000\u0000\u0000\u00c4\u00c3\u0001\u0000\u0000\u0000\u00c5!\u0001\u0000"+
		"\u0000\u0000\u00c6\u00c7\u0003$\u0012\u0000\u00c7\u00c8\u0005\t\u0000"+
		"\u0000\u00c8\u00c9\u0003&\u0013\u0000\u00c9\u00ca\u0005\u0003\u0000\u0000"+
		"\u00ca\u00ee\u0001\u0000\u0000\u0000\u00cb\u00cd\u0003&\u0013\u0000\u00cc"+
		"\u00cb\u0001\u0000\u0000\u0000\u00cc\u00cd\u0001\u0000\u0000\u0000\u00cd"+
		"\u00ce\u0001\u0000\u0000\u0000\u00ce\u00ee\u0005\u0003\u0000\u0000\u00cf"+
		"\u00ee\u0003\u001e\u000f\u0000\u00d0\u00d2\u0005\u0010\u0000\u0000\u00d1"+
		"\u00d3\u0003&\u0013\u0000\u00d2\u00d1\u0001\u0000\u0000\u0000\u00d2\u00d3"+
		"\u0001\u0000\u0000\u0000\u00d3\u00d4\u0001\u0000\u0000\u0000\u00d4\u00ee"+
		"\u0005\u0003\u0000\u0000\u00d5\u00d6\u0005\u0011\u0000\u0000\u00d6\u00d7"+
		"\u0005\u000e\u0000\u0000\u00d7\u00d8\u00032\u0019\u0000\u00d8\u00d9\u0005"+
		"\u000f\u0000\u0000\u00d9\u00da\u0003\"\u0011\u0000\u00da\u00ee\u0001\u0000"+
		"\u0000\u0000\u00db\u00dc\u0005\u0011\u0000\u0000\u00dc\u00dd\u0005\u000e"+
		"\u0000\u0000\u00dd\u00de\u00032\u0019\u0000\u00de\u00df\u0005\u000f\u0000"+
		"\u0000\u00df\u00e0\u0003\"\u0011\u0000\u00e0\u00e1\u0005\u0012\u0000\u0000"+
		"\u00e1\u00e2\u0003\"\u0011\u0000\u00e2\u00ee\u0001\u0000\u0000\u0000\u00e3"+
		"\u00e4\u0005\u0013\u0000\u0000\u00e4\u00e5\u0005\u000e\u0000\u0000\u00e5"+
		"\u00e6\u00032\u0019\u0000\u00e6\u00e7\u0005\u000f\u0000\u0000\u00e7\u00e8"+
		"\u0003\"\u0011\u0000\u00e8\u00ee\u0001\u0000\u0000\u0000\u00e9\u00ea\u0005"+
		"\u0014\u0000\u0000\u00ea\u00ee\u0005\u0003\u0000\u0000\u00eb\u00ec\u0005"+
		"\u0015\u0000\u0000\u00ec\u00ee\u0005\u0003\u0000\u0000\u00ed\u00c6\u0001"+
		"\u0000\u0000\u0000\u00ed\u00cc\u0001\u0000\u0000\u0000\u00ed\u00cf\u0001"+
		"\u0000\u0000\u0000\u00ed\u00d0\u0001\u0000\u0000\u0000\u00ed\u00d5\u0001"+
		"\u0000\u0000\u0000\u00ed\u00db\u0001\u0000\u0000\u0000\u00ed\u00e3\u0001"+
		"\u0000\u0000\u0000\u00ed\u00e9\u0001\u0000\u0000\u0000\u00ed\u00eb\u0001"+
		"\u0000\u0000\u0000\u00ee#\u0001\u0000\u0000\u0000\u00ef\u00f6\u0005%\u0000"+
		"\u0000\u00f0\u00f1\u0005\n\u0000\u0000\u00f1\u00f2\u0003&\u0013\u0000"+
		"\u00f2\u00f3\u0005\u000b\u0000\u0000\u00f3\u00f5\u0001\u0000\u0000\u0000"+
		"\u00f4\u00f0\u0001\u0000\u0000\u0000\u00f5\u00f8\u0001\u0000\u0000\u0000"+
		"\u00f6\u00f4\u0001\u0000\u0000\u0000\u00f6\u00f7\u0001\u0000\u0000\u0000"+
		"\u00f7%\u0001\u0000\u0000\u0000\u00f8\u00f6\u0001\u0000\u0000\u0000\u00f9"+
		"\u00fc\u0003(\u0014\u0000\u00fa\u00fc\u0005$\u0000\u0000\u00fb\u00f9\u0001"+
		"\u0000\u0000\u0000\u00fb\u00fa\u0001\u0000\u0000\u0000\u00fc\'\u0001\u0000"+
		"\u0000\u0000\u00fd\u00fe\u0006\u0014\uffff\uffff\u0000\u00fe\u00ff\u0003"+
		"*\u0015\u0000\u00ff\u0105\u0001\u0000\u0000\u0000\u0100\u0101\n\u0001"+
		"\u0000\u0000\u0101\u0102\u0007\u0001\u0000\u0000\u0102\u0104\u0003*\u0015"+
		"\u0000\u0103\u0100\u0001\u0000\u0000\u0000\u0104\u0107\u0001\u0000\u0000"+
		"\u0000\u0105\u0103\u0001\u0000\u0000\u0000\u0105\u0106\u0001\u0000\u0000"+
		"\u0000\u0106)\u0001\u0000\u0000\u0000\u0107\u0105\u0001\u0000\u0000\u0000"+
		"\u0108\u0109\u0006\u0015\uffff\uffff\u0000\u0109\u010a\u0003,\u0016\u0000"+
		"\u010a\u0110\u0001\u0000\u0000\u0000\u010b\u010c\n\u0001\u0000\u0000\u010c"+
		"\u010d\u0007\u0004\u0000\u0000\u010d\u010f\u0003,\u0016\u0000\u010e\u010b"+
		"\u0001\u0000\u0000\u0000\u010f\u0112\u0001\u0000\u0000\u0000\u0110\u010e"+
		"\u0001\u0000\u0000\u0000\u0110\u0111\u0001\u0000\u0000\u0000\u0111+\u0001"+
		"\u0000\u0000\u0000\u0112\u0110\u0001\u0000\u0000\u0000\u0113\u011d\u0003"+
		".\u0017\u0000\u0114\u0115\u0007\u0005\u0000\u0000\u0115\u011d\u0003,\u0016"+
		"\u0000\u0116\u0117\u0005%\u0000\u0000\u0117\u0119\u0005\u000e\u0000\u0000"+
		"\u0118\u011a\u00030\u0018\u0000\u0119\u0118\u0001\u0000\u0000\u0000\u0119"+
		"\u011a\u0001\u0000\u0000\u0000\u011a\u011b\u0001\u0000\u0000\u0000\u011b"+
		"\u011d\u0005\u000f\u0000\u0000\u011c\u0113\u0001\u0000\u0000\u0000\u011c"+
		"\u0114\u0001\u0000\u0000\u0000\u011c\u0116\u0001\u0000\u0000\u0000\u011d"+
		"-\u0001\u0000\u0000\u0000\u011e\u0125\u0003\u0014\n\u0000\u011f\u0120"+
		"\u0005\u000e\u0000\u0000\u0120\u0121\u0003&\u0013\u0000\u0121\u0122\u0005"+
		"\u000f\u0000\u0000\u0122\u0125\u0001\u0000\u0000\u0000\u0123\u0125\u0003"+
		"$\u0012\u0000\u0124\u011e\u0001\u0000\u0000\u0000\u0124\u011f\u0001\u0000"+
		"\u0000\u0000\u0124\u0123\u0001\u0000\u0000\u0000\u0125/\u0001\u0000\u0000"+
		"\u0000\u0126\u012b\u0003&\u0013\u0000\u0127\u0128\u0005\u0002\u0000\u0000"+
		"\u0128\u012a\u0003&\u0013\u0000\u0129\u0127\u0001\u0000\u0000\u0000\u012a"+
		"\u012d\u0001\u0000\u0000\u0000\u012b\u0129\u0001\u0000\u0000\u0000\u012b"+
		"\u012c\u0001\u0000\u0000\u0000\u012c1\u0001\u0000\u0000\u0000\u012d\u012b"+
		"\u0001\u0000\u0000\u0000\u012e\u012f\u00034\u001a\u0000\u012f3\u0001\u0000"+
		"\u0000\u0000\u0130\u0131\u0006\u001a\uffff\uffff\u0000\u0131\u0132\u0003"+
		"6\u001b\u0000\u0132\u0138\u0001\u0000\u0000\u0000\u0133\u0134\n\u0001"+
		"\u0000\u0000\u0134\u0135\u0005!\u0000\u0000\u0135\u0137\u00036\u001b\u0000"+
		"\u0136\u0133\u0001\u0000\u0000\u0000\u0137\u013a\u0001\u0000\u0000\u0000"+
		"\u0138\u0136\u0001\u0000\u0000\u0000\u0138\u0139\u0001\u0000\u0000\u0000"+
		"\u01395\u0001\u0000\u0000\u0000\u013a\u0138\u0001\u0000\u0000\u0000\u013b"+
		"\u013c\u0006\u001b\uffff\uffff\u0000\u013c\u013d\u00038\u001c\u0000\u013d"+
		"\u0143\u0001\u0000\u0000\u0000\u013e\u013f\n\u0001\u0000\u0000\u013f\u0140"+
		"\u0005\"\u0000\u0000\u0140\u0142\u00038\u001c\u0000\u0141\u013e\u0001"+
		"\u0000\u0000\u0000\u0142\u0145\u0001\u0000\u0000\u0000\u0143\u0141\u0001"+
		"\u0000\u0000\u0000\u0143\u0144\u0001\u0000\u0000\u0000\u01447\u0001\u0000"+
		"\u0000\u0000\u0145\u0143\u0001\u0000\u0000\u0000\u0146\u014c\u0003:\u001d"+
		"\u0000\u0147\u0148\u0003:\u001d\u0000\u0148\u0149\u0007\u0006\u0000\u0000"+
		"\u0149\u014a\u0003:\u001d\u0000\u014a\u014c\u0001\u0000\u0000\u0000\u014b"+
		"\u0146\u0001\u0000\u0000\u0000\u014b\u0147\u0001\u0000\u0000\u0000\u014c"+
		"9\u0001\u0000\u0000\u0000\u014d\u0154\u0003(\u0014\u0000\u014e\u014f\u0003"+
		"(\u0014\u0000\u014f\u0150\u0007\u0007\u0000\u0000\u0150\u0151\u0003(\u0014"+
		"\u0000\u0151\u0154\u0001\u0000\u0000\u0000\u0152\u0154\u0005$\u0000\u0000"+
		"\u0153\u014d\u0001\u0000\u0000\u0000\u0153\u014e\u0001\u0000\u0000\u0000"+
		"\u0153\u0152\u0001\u0000\u0000\u0000\u0154;\u0001\u0000\u0000\u0000#>"+
		"@GP[hty\u0082\u0085\u0088\u008c\u008f\u0099\u00a5\u00ac\u00b4\u00b7\u00bd"+
		"\u00c4\u00cc\u00d2\u00ed\u00f6\u00fb\u0105\u0110\u0119\u011c\u0124\u012b"+
		"\u0138\u0143\u014b\u0153";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}