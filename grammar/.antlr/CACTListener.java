// Generated from /home/stu/Documents/CP/cact_cp/cact/grammar/CACT.g4 by ANTLR 4.13.1

    #include <vector>

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CACTParser}.
 */
public interface CACTListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CACTParser#compUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompUnit(CACTParser.CompUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#compUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompUnit(CACTParser.CompUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#decl}.
	 * @param ctx the parse tree
	 */
	void enterDecl(CACTParser.DeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#decl}.
	 * @param ctx the parse tree
	 */
	void exitDecl(CACTParser.DeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#constDecl}.
	 * @param ctx the parse tree
	 */
	void enterConstDecl(CACTParser.ConstDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#constDecl}.
	 * @param ctx the parse tree
	 */
	void exitConstDecl(CACTParser.ConstDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#varDecl}.
	 * @param ctx the parse tree
	 */
	void enterVarDecl(CACTParser.VarDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#varDecl}.
	 * @param ctx the parse tree
	 */
	void exitVarDecl(CACTParser.VarDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#bType}.
	 * @param ctx the parse tree
	 */
	void enterBType(CACTParser.BTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#bType}.
	 * @param ctx the parse tree
	 */
	void exitBType(CACTParser.BTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#constDef}.
	 * @param ctx the parse tree
	 */
	void enterConstDef(CACTParser.ConstDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#constDef}.
	 * @param ctx the parse tree
	 */
	void exitConstDef(CACTParser.ConstDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#varDef}.
	 * @param ctx the parse tree
	 */
	void enterVarDef(CACTParser.VarDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#varDef}.
	 * @param ctx the parse tree
	 */
	void exitVarDef(CACTParser.VarDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#constInitVal}.
	 * @param ctx the parse tree
	 */
	void enterConstInitVal(CACTParser.ConstInitValContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#constInitVal}.
	 * @param ctx the parse tree
	 */
	void exitConstInitVal(CACTParser.ConstInitValContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#constExp}.
	 * @param ctx the parse tree
	 */
	void enterConstExp(CACTParser.ConstExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#constExp}.
	 * @param ctx the parse tree
	 */
	void exitConstExp(CACTParser.ConstExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#initNum}.
	 * @param ctx the parse tree
	 */
	void enterInitNum(CACTParser.InitNumContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#initNum}.
	 * @param ctx the parse tree
	 */
	void exitInitNum(CACTParser.InitNumContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#num}.
	 * @param ctx the parse tree
	 */
	void enterNum(CACTParser.NumContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#num}.
	 * @param ctx the parse tree
	 */
	void exitNum(CACTParser.NumContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#funcDef}.
	 * @param ctx the parse tree
	 */
	void enterFuncDef(CACTParser.FuncDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#funcDef}.
	 * @param ctx the parse tree
	 */
	void exitFuncDef(CACTParser.FuncDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#funcType}.
	 * @param ctx the parse tree
	 */
	void enterFuncType(CACTParser.FuncTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#funcType}.
	 * @param ctx the parse tree
	 */
	void exitFuncType(CACTParser.FuncTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#funcFParams}.
	 * @param ctx the parse tree
	 */
	void enterFuncFParams(CACTParser.FuncFParamsContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#funcFParams}.
	 * @param ctx the parse tree
	 */
	void exitFuncFParams(CACTParser.FuncFParamsContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#funcFParam}.
	 * @param ctx the parse tree
	 */
	void enterFuncFParam(CACTParser.FuncFParamContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#funcFParam}.
	 * @param ctx the parse tree
	 */
	void exitFuncFParam(CACTParser.FuncFParamContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(CACTParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(CACTParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#blockItem}.
	 * @param ctx the parse tree
	 */
	void enterBlockItem(CACTParser.BlockItemContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#blockItem}.
	 * @param ctx the parse tree
	 */
	void exitBlockItem(CACTParser.BlockItemContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(CACTParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(CACTParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#lVal}.
	 * @param ctx the parse tree
	 */
	void enterLVal(CACTParser.LValContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#lVal}.
	 * @param ctx the parse tree
	 */
	void exitLVal(CACTParser.LValContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#exp}.
	 * @param ctx the parse tree
	 */
	void enterExp(CACTParser.ExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#exp}.
	 * @param ctx the parse tree
	 */
	void exitExp(CACTParser.ExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#addExp}.
	 * @param ctx the parse tree
	 */
	void enterAddExp(CACTParser.AddExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#addExp}.
	 * @param ctx the parse tree
	 */
	void exitAddExp(CACTParser.AddExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#mulExp}.
	 * @param ctx the parse tree
	 */
	void enterMulExp(CACTParser.MulExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#mulExp}.
	 * @param ctx the parse tree
	 */
	void exitMulExp(CACTParser.MulExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#unaryExp}.
	 * @param ctx the parse tree
	 */
	void enterUnaryExp(CACTParser.UnaryExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#unaryExp}.
	 * @param ctx the parse tree
	 */
	void exitUnaryExp(CACTParser.UnaryExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#priExp}.
	 * @param ctx the parse tree
	 */
	void enterPriExp(CACTParser.PriExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#priExp}.
	 * @param ctx the parse tree
	 */
	void exitPriExp(CACTParser.PriExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#funcRParams}.
	 * @param ctx the parse tree
	 */
	void enterFuncRParams(CACTParser.FuncRParamsContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#funcRParams}.
	 * @param ctx the parse tree
	 */
	void exitFuncRParams(CACTParser.FuncRParamsContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#cond}.
	 * @param ctx the parse tree
	 */
	void enterCond(CACTParser.CondContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#cond}.
	 * @param ctx the parse tree
	 */
	void exitCond(CACTParser.CondContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#lOrExp}.
	 * @param ctx the parse tree
	 */
	void enterLOrExp(CACTParser.LOrExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#lOrExp}.
	 * @param ctx the parse tree
	 */
	void exitLOrExp(CACTParser.LOrExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#lAndExp}.
	 * @param ctx the parse tree
	 */
	void enterLAndExp(CACTParser.LAndExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#lAndExp}.
	 * @param ctx the parse tree
	 */
	void exitLAndExp(CACTParser.LAndExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#eqExp}.
	 * @param ctx the parse tree
	 */
	void enterEqExp(CACTParser.EqExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#eqExp}.
	 * @param ctx the parse tree
	 */
	void exitEqExp(CACTParser.EqExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link CACTParser#relExp}.
	 * @param ctx the parse tree
	 */
	void enterRelExp(CACTParser.RelExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link CACTParser#relExp}.
	 * @param ctx the parse tree
	 */
	void exitRelExp(CACTParser.RelExpContext ctx);
}