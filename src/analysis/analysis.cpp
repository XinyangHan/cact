#include <iostream>
#include <any>
#include <numeric>
#include "include/analysis/analysis.h"
using namespace antlr4;

std::any Analysis::visitBegin(CACTParser::StartContext *ctx) {
    // 添加库函数
    std::string emptyName;  // 空字符串名称
    std::vector<int> emptyDimArr;  // 空维度数组
    ctx->valSymbolList.push_back(new ValSymbol(Type::INT, emptyName, 0, emptyDimArr, false));  // 添加int类型的ValSymbol
    ctx->valSymbolList.push_back(new ValSymbol(Type::FLOAT, emptyName, 0, emptyDimArr, false));  // 添加float类型的ValSymbol
    ctx->valSymbolList.push_back(new ValSymbol(Type::DOUBLE, emptyName, 0, emptyDimArr, false));  // 添加double类型的ValSymbol
    ctx->valSymbolList.push_back(new ValSymbol(Type::BOOL, emptyName, 0, emptyDimArr, false));  // 添加bool类型的ValSymbol

    // 添加库函数符号到环境中
    for (int i = 0; i < ctx->libFuncType.size(); i++) {
        FuncSymbol *funcSymbol = env->addFuncSymbol(ctx->libFuncType[i], ctx->libFuncName[i]);
        if (i < ctx->valSymbolList.size()) {
            funcSymbol->addParam(ctx->valSymbolList[i]);
        }
    }

    // 访问子节点
    visitChildren(ctx);

    // 检查main函数
    std::string mainFunc = "main";
    FuncSymbol *funcSymbol = env->searchFuncSymbol(mainFunc);
    if (funcSymbol == nullptr) {
        throw runtime_error("无法找到main函数。");
    } else if (funcSymbol->getParams().size() != 0) {
        throw runtime_error("main函数不能有参数。");
    }

    return std::any();
}


std::any Analysis::visitBType(CACTParser::BTypeContext *ctx) {
    if (ctx->BOOL() != nullptr) {
        ctx->btype = Type::BOOL;
    }
    else if (ctx->INT() != nullptr) {
        ctx->btype = Type::INT;
    }
    else if (ctx->FLOAT() != nullptr) {
        ctx->btype = Type::FLOAT;
    }
    else if (ctx->DOUBLE() != nullptr) {
        ctx->btype = Type::DOUBLE;
    }
    return std::any();
}

std::any Analysis::visitFuncType(CACTParser::FuncTypeContext *ctx) {
    if (ctx->BOOL() != nullptr) {
        ctx->functype = Type::BOOL;
    }
    else if (ctx->INT() != nullptr) {
        ctx->functype = Type::INT;
    }
    else if (ctx->FLOAT() != nullptr) {
        ctx->functype = Type::FLOAT;
    }
    else if (ctx->DOUBLE() != nullptr) {
        ctx->functype = Type::DOUBLE;
    }
    else if (ctx->VOID() != nullptr) {
        ctx->functype = Type::VOID;
    }
    return std::any();
}

std::any Analysis::visitConstDecl(CACTParser::ConstDeclContext *ctx) {
    ctx->bType()->accept(this);
    for (const auto & constdef : ctx->constDef()) {
        constdef->datatype = ctx->bType()->btype;
        constdef->accept(this);
    }
    return std::any();
}

std::any Analysis::visitVarDecl(CACTParser::VarDeclContext *ctx) {
    ctx->bType()->accept(this);
    for (const auto & vardef : ctx->varDef()) {
        vardef->datatype = ctx->bType()->btype;
        vardef->accept(this);
    }
    return std::any();
}

std::any Analysis::visitConstDef(CACTParser::ConstDefContext *ctx) {
    ctx->symbolname = ctx->IDENT()->getText();
    ctx->dimsize = ctx->LBRACKET().size();
    
    //get dimSize and dimArray of this const
    for (const auto & intconst : ctx->INTCONST()) {
        if (std::stoi(intconst->getText()) < 0) {
            throw std::runtime_error("the array index cannot be negative.");
        }
        else {
            ctx->dimarr.push_back(std::stoi(intconst->getText()));
        }
    }
    
    //check if const definition matches initval
    if (ctx->dimsize != 0 && dynamic_cast<CACTParser::ConstInitValBasicContext*>(ctx->constInitVal()) != nullptr) {
        throw std::runtime_error("variable define does not match initval.");
    }
    else {
        ctx->constInitVal()->datatype = ctx->datatype;
        ctx->constInitVal()->dimsize = ctx->dimsize;
        ctx->constInitVal()->dimarr  = ctx->dimarr;
        ctx->constInitVal()->accept(this);
    }
    
    //add const to IRCode
    IROperand *dst;
    if (env->getCurrBlock()->getPre() == nullptr) {
        if (ctx->dimsize == 0) {
            dst = irGenerator->addIrGlobalVariable(ctx->datatype, ctx->constInitVal()->initval);
            irGenerator->addIRCode(ctx->datatype, IR_G_ALLOC, dst, nullptr, nullptr);
        }
        else {
            int len = accumulate(ctx->dimarr.begin(), ctx->dimarr.end(), 1, std::multiplies<int>());
            dst = irGenerator->addIrGlobalVariable(ctx->datatype, len, ctx->constInitVal()->initval);
            irGenerator->addIRCode(ctx->datatype, IR_G_ALLOC, dst, nullptr, nullptr);
        }
    }
    else {
        if (ctx->dimsize == 0) {
            dst = irGenerator->addIRLocalVar(ctx->datatype, ctx->constInitVal()->initval);
            irGenerator->addIRCode(ctx->datatype, IR_L_ALLOC, dst, nullptr, nullptr);
        }
        else {
            int len = accumulate(ctx->dimarr.begin(), ctx->dimarr.end(), 1, std::multiplies<int>());
            dst = irGenerator->addIRLocalVar(ctx->datatype, len, ctx->constInitVal()->initval);
            irGenerator->addIRCode(ctx->datatype, IR_L_ALLOC, dst, nullptr, nullptr);
        }
    }
    
    //add const allocation to symbolTable
    ValSymbol *valSymbol = env->getCurrBlock()->addValSymbol(ctx->datatype, ctx->symbolname, ctx->dimsize, ctx->dimarr, true);
    valSymbol->setIROperand(dst);
    return std::any();
}

std::any Analysis::visitVarDef(CACTParser::VarDefContext *ctx) {
    bool zero = false;
    ctx->symbolname = ctx->IDENT()->getText();
    ctx->dimsize = ctx->LBRACKET().size();
    
    //get dimSize and dimArray of this var
    for (const auto & intconst : ctx->INTCONST()) {
        if (std::stoi(intconst->getText()) < 0) {
            throw std::runtime_error("the array index cannot be negative.");
        }
        else {
            ctx->dimarr.push_back(std::stoi(intconst->getText()));
        }
    }
    
    //check if var definition matches initval
    if (ctx->EQUALS() != nullptr) {
        if (ctx->dimsize != 0 && dynamic_cast<CACTParser::ConstInitValBasicContext*>(ctx->constInitVal()) != nullptr) {
            throw std::runtime_error("variable define does not match initval.");
        }
        ctx->constInitVal()->datatype = ctx->datatype;
        ctx->constInitVal()->dimsize = ctx->dimsize;
        ctx->constInitVal()->dimarr  = ctx->dimarr;
        ctx->constInitVal()->accept(this);
        for (auto val : ctx->constInitVal()->initval) {
            ctx->initval.push_back(val);
        }
    }
    else {
        int len = accumulate(ctx->dimarr.begin(), ctx->dimarr.end(), 1, std::multiplies<int>());
        IROperand *newinitval;
        if (ctx->datatype == INT)
            newinitval = irGenerator->addIRImmediate(ctx->datatype, std::to_string(0));
        else if (ctx->datatype == FLOAT)
            newinitval = irGenerator->addIRImmediate(ctx->datatype, std::to_string(0.0f));
        else if (ctx->datatype == DOUBLE)
            newinitval = irGenerator->addIRImmediate(ctx->datatype, std::to_string(0.0));
        else
            newinitval = irGenerator->addIRImmediate(ctx->datatype, std::string("false"));

        for (int i = 0; i < len; i++) {
            ctx->initval.push_back(newinitval);
        }
        zero = true;
    }
    
    //add var to IRCode
    IROperand *dst;
    if (env->getCurrBlock()->getPre() == nullptr) {
        if (ctx->dimsize == 0) {
            dst = irGenerator->addIrGlobalVariable(ctx->datatype, ctx->initval);
            irGenerator->addIRCode(ctx->datatype, IR_G_ALLOC, dst, nullptr, nullptr);
        }
        else {
            int len = accumulate(ctx->dimarr.begin(), ctx->dimarr.end(), 1, std::multiplies<int>());
            dst = irGenerator->addIrGlobalVariable(ctx->datatype, len, ctx->initval);
            irGenerator->addIRCode(ctx->datatype, IR_G_ALLOC, dst, nullptr, nullptr);
        }
    }
    else {
        if (ctx->dimsize == 0) {
            dst = irGenerator->addIRLocalVar(ctx->datatype, ctx->initval);
            irGenerator->addIRCode(ctx->datatype, IR_L_ALLOC, dst, nullptr, nullptr);
        }
        else {
            int len = accumulate(ctx->dimarr.begin(), ctx->dimarr.end(), 1, std::multiplies<int>());
            dst = irGenerator->addIRLocalVar(ctx->datatype, len, ctx->initval);
            irGenerator->addIRCode(ctx->datatype, IR_L_ALLOC, dst, nullptr, nullptr);
        }
    }
    if (zero) 
        dst->zero = true;
    
    //add var to symboltable
    ValSymbol *valSymbol = env->getCurrBlock()->addValSymbol(ctx->datatype, ctx->symbolname, ctx->dimsize, ctx->dimarr, false);
    valSymbol->setIROperand(dst); 
    return std::any();
}

std::any Analysis::visitConstInitValBasic(CACTParser::ConstInitValBasicContext *ctx) {
    ctx->constExp()->accept(this);
    if (ctx->constExp()->datatype != ctx->datatype) {
        throw std::runtime_error("variable define does not match initval.");
    }
    else {
        IROperand *newInitVal = irGenerator->addIRImmediate(ctx->constExp()->datatype, ctx->constExp()->value);
        ctx->initval.push_back(newInitVal);
    }
    return std::any();
}

std::any Analysis::visitConstInitValNested(CACTParser::ConstInitValNestedContext *ctx) {
    if (ctx->dimsize == 0) {
        //error occurs
        throw std::runtime_error("variable define does not match initval.");
    }
    else {
        int nestedNum = accumulate(ctx->dimarr.begin()+1, ctx->dimarr.end(), 1, std::multiplies<int>());
        int totalNum  = ctx->dimarr[0] * nestedNum;
        int vecSize   = ctx->constInitVal().size();
        int numCounter = 0;
        
        for (int i = 0; i < vecSize; ) {
            if (dynamic_cast<CACTParser::ConstInitValBasicContext*>(ctx->constInitVal()[i]) != nullptr) {
                int j = 0;
                for ( ; j < nestedNum && i + j < vecSize; j++) {
                    if (dynamic_cast<CACTParser::ConstInitValBasicContext*>(ctx->constInitVal()[i+j]) == nullptr) {
                        //error occurs
                        throw std::runtime_error("variable define does not match initval.");
                        return std::any();
                    }
                    else {
                        ctx->constInitVal()[i+j]->datatype = ctx->datatype;
                        ctx->constInitVal()[i+j]->accept(this);
                        for (auto newinitval : ctx->constInitVal()[i+j]->initval) {
                            ctx->initval.push_back(newinitval);
                        }
                    }
                }
                i += j;
                numCounter += j;
            }
            else {
                ctx->constInitVal()[i]->dimsize  = ctx->dimsize-1;
                ctx->constInitVal()[i]->datatype = ctx->datatype; 
                for (int j = 0; j < ctx->dimsize-1; j++) {
                    ctx->constInitVal()[i]->dimarr.push_back(ctx->dimarr[j+1]);
                }
                ctx->constInitVal()[i]->accept(this);
                for (auto newinitval : ctx->constInitVal()[i]->initval) {
                    ctx->initval.push_back(newinitval);
                }
                i += 1;
                numCounter += nestedNum;
            }
            if (numCounter > totalNum) {
                //error occurs
                throw std::runtime_error("variable define does not match initval.");
            }
        }
        if (numCounter < totalNum) {
            IROperand *newinitval;
            for (int i = 0; i < totalNum-numCounter; i++) {
                if (ctx->datatype == INT)
                    newinitval = irGenerator->addIRImmediate(ctx->datatype, std::to_string(0));
                else if (ctx->datatype == FLOAT)
                    newinitval = irGenerator->addIRImmediate(ctx->datatype, std::to_string(0.0f));
                else if (ctx->datatype == DOUBLE)
                    newinitval = irGenerator->addIRImmediate(ctx->datatype, std::to_string(0.0));
                else
                    newinitval = irGenerator->addIRImmediate(ctx->datatype, std::string("false"));
                ctx->initval.push_back(newinitval);
            }
        }
    }
    return std::any();
}

std::any Analysis::visitConstExp(CACTParser::ConstExpContext *ctx) {
    if (ctx->BOOLCONST() != nullptr) {
        ctx->datatype = Type::BOOL;
        ctx->value = ctx->BOOLCONST()->getText();
        ctx->result   = irGenerator->addIRImmediate(ctx->datatype, ctx->value);
    }
    else {
        ctx->initNum()->accept(this);
        ctx->datatype = ctx->initNum()->datatype;
        ctx->value = ctx->initNum()->value;
        ctx->result   = irGenerator->addIRImmediate(ctx->datatype, ctx->value);
    }
    return std::any();
}

std::any Analysis::visitInitNum(CACTParser::InitNumContext *ctx) {
    if (ctx->SUB() != nullptr) {
        ctx->value = "-";
    }
    ctx->num()->accept(this);
    ctx->datatype = ctx->num()->datatype;
    ctx->value = ctx->value + ctx->num()->value;
    return std::any();
}

std::any Analysis::visitFuncDef(CACTParser::FuncDefContext *ctx) {
    ctx->funcType()->accept(this);
    ctx->symbolname = ctx->IDENT()->getText();
    
    //add to symboltable, add FUNC_START IRCode
    FuncSymbol *funcSymbol = env->addFuncSymbol(ctx->funcType()->functype, ctx->symbolname);
    env->setCurrFunc(funcSymbol);
    IROperand *newOperand = irGenerator->addIRFunc(funcSymbol);
    irGenerator->addIRCode(ctx->funcType()->functype, IR_FUNC_START, newOperand, nullptr, nullptr);
    
    //create a new block for current func
    Block *newBlock = new Block(env->getCurrBlock());
    env->setCurrBlock(newBlock);
    if (ctx->funcFParams() != nullptr) {
        ctx->funcFParams()->accept(this);
    }
    ctx->funcBlock()->accept(this);
    env->setCurrBlock(env->getCurrBlock()->getPre());
    
    //add FUNC_END IRCode
    irGenerator->addIRCode(ctx->funcType()->functype, IR_FUNC_END, newOperand, nullptr, nullptr);
    return std::any();
}

std::any Analysis::visitFuncFParam(CACTParser::FuncFParamContext *ctx) {
    ctx->bType()->accept(this);
    ctx->datatype = ctx->bType()->btype;
    ctx->symbolname = ctx->IDENT()->getText();
    ctx->dimsize = ctx->LBRACKET().size();
    std::vector<antlr4::tree::TerminalNode *> indexes  = ctx->INTCONST();
    
    if (ctx->dimsize != indexes.size()) {
        ctx->dimarr.push_back(-1);
    }
    for (auto index : indexes) {
        if (std::stoi(index->getText()) < 0) {
            throw std::runtime_error("the array index cannot be negative.");
        }
        else {
            ctx->dimarr.push_back(std::stoi(index->getText()));
        }
    }
    
    //create new IROperand
    IROperand *newOperand;
    std::vector<IROperand*> emptyVector;
    if (ctx->dimsize > 0) {
        if (ctx->datatype == Type::INT) {
            newOperand = irGenerator->addIRLocalVar(Type::INT_PTR, emptyVector);
        }
        else if (ctx->datatype == Type::FLOAT) {
            newOperand = irGenerator->addIRLocalVar(Type::FLOAT_PTR, emptyVector);
        }
        else {
            newOperand = irGenerator->addIRLocalVar(Type::DOUBLE_PTR, emptyVector);
        }
    } 
    else {
        newOperand = irGenerator->addIRLocalVar(ctx->datatype, emptyVector);
    }
    
    //add formal parameter to symboltable
    ValSymbol *valSymbol = env->getCurrBlock()->addValSymbol(ctx->datatype, ctx->symbolname, ctx->dimsize, ctx->dimarr, false);
    valSymbol->setIROperand(newOperand);
    env->getCurrFunc()->addParam(valSymbol);
    return std::any();
}

std::any Analysis::visitFuncBlock(CACTParser::FuncBlockContext *ctx) {
    IROperand *newLabel = nullptr;
    int i = 0;
    for (auto blockItem : ctx->blockItem()) {
        i++;
        blockItem->newLabel = newLabel;
        if (i == ctx->blockItem().size() && env->getCurrFunc()->getDataType() != Type::VOID) {
            blockItem->returnCheck = true;
        }
        blockItem->accept(this);
        if (dynamic_cast<CACTParser::BlockItemStmtContext*>(blockItem) != nullptr) {
            newLabel = blockItem->newLabel;
        }
    }
    return std::any();
}

std::any Analysis::visitBlock(CACTParser::BlockContext *ctx) {
    Block *newBlock = new Block(env->getCurrBlock());
    env->setCurrBlock(newBlock);
    
    CACTParser::BlockItemStmtContext* lastBlockItemStmt  = nullptr;
    for (auto blockItem : ctx->blockItem()) {
        if (dynamic_cast<CACTParser::BlockItemStmtContext*>(blockItem) != nullptr) {
            lastBlockItemStmt = reinterpret_cast<CACTParser::BlockItemStmtContext*>(blockItem);
        }
    }
    
    if (lastBlockItemStmt != nullptr) {
        lastBlockItemStmt->next = ctx->next;
    }
    
    int i = 0;
    ctx->newLabel = ctx->before;
    for (auto blockItem : ctx->blockItem()) {
        i++;
        blockItem->newLabel = ctx->newLabel;
        if (ctx->returnCheck && i == ctx->blockItem().size()) {
            blockItem->returnCheck = true;
        }
        blockItem->accept(this);
        if (dynamic_cast<CACTParser::BlockItemStmtContext*>(blockItem) != nullptr) {
            ctx->newLabel = blockItem->newLabel;
        }
    }
    
    env->setCurrBlock(env->getCurrBlock()->getPre());
    return std::any();
}

std::any Analysis::visitBlockItemDecl(CACTParser::BlockItemDeclContext *ctx) {
    if (ctx->returnCheck) {
        throw runtime_error("missing return in function " + env->getCurrFunc()->getSymbolName() + ".");
    }
    visitChildren(ctx);
    return std::any();
}

std::any Analysis::visitBlockItemStmt(CACTParser::BlockItemStmtContext *ctx) {
    if (ctx->returnCheck) {
        ctx->stmt()->returnCheck = true;
    }
    ctx->stmt()->before = ctx->newLabel;
    ctx->stmt()->next = ctx->next;
    ctx->stmt()->accept(this);
    return std::any();
}

std::any Analysis::visitNum(CACTParser::NumContext *ctx) {
    if (ctx->INTCONST() != nullptr) {
        ctx->datatype = Type::INT;
        ctx->value = ctx->INTCONST()->getText();
    }
    else if (ctx->FLOATCONST() != nullptr) {
        ctx->datatype = Type::FLOAT;
        ctx->value = ctx->FLOATCONST()->getText();
    }
    else {
        ctx->datatype = Type::DOUBLE;
        ctx->value = ctx->DOUBLECONST()->getText();
    }
    ctx->dimsize = 0;
    return std::any();
}

std::any Analysis::visitPriExpNum(CACTParser::PriExpNumContext *ctx) {
    ctx->num()->accept(this);
    ctx->datatype = ctx->num()->datatype;
    ctx->dimsize  = ctx->num()->dimsize;
    ctx->dimarr   = ctx->num()->dimarr;
    ctx->result   = irGenerator->addIRImmediate(ctx->datatype, ctx->num()->value);
    return std::any();
}

std::any Analysis::visitPriExpNested(CACTParser::PriExpNestedContext *ctx) {
    ctx->exp()->accept(this);
    ctx->datatype = ctx->exp()->datatype;
    ctx->dimsize  = ctx->exp()->dimsize;
    ctx->dimarr   = ctx->exp()->dimarr;
    ctx->result = ctx->exp()->result;
    return std::any();
}

std::any Analysis::visitPriExpLval(CACTParser::PriExpLvalContext *ctx) {
    ctx->lVal()->accept(this);
    ctx->datatype = ctx->lVal()->datatype;
    ctx->dimsize  = ctx->lVal()->dimsize;
    ctx->dimarr   = ctx->lVal()->dimarr;
    ctx->result   = ctx->lVal()->result;
    return std::any();
}

std::any Analysis::visitLVal(CACTParser::LValContext *ctx) {
    std::string symbolName = ctx->IDENT()->getText();
    ValSymbol *valSymbol = env->getCurrBlock()->searchValSymbol(symbolName);
    if (valSymbol == nullptr) {
        throw std::runtime_error("variable " + symbolName + " is used before declaration.");
    }
    else if (ctx->LBRACKET().size() > valSymbol->getDimSize()){
        throw std::runtime_error("the type of left value can only be basic and array.");
    }
    
    ctx->isConst = valSymbol->getIsConst();
    ctx->datatype = valSymbol->getDataType();
    ctx->dimsize  = valSymbol->getDimSize() - ctx->LBRACKET().size();
    for (int i = ctx->LBRACKET().size(); i < valSymbol->getDimSize(); i++) {
        ctx->dimarr.push_back(valSymbol->getDimArray()[i]);
    }
    
    //generate IR for lVal
    int byteNum;
    switch(ctx->datatype) {
        case Type::BOOL: 
            byteNum = 4; 
            break;
        case Type::INT: case Type::FLOAT:  
            byteNum = 4; 
            break;
        case Type::DOUBLE: 
            byteNum = 8; 
            break;
        default: 
            break;
    }
    
    if (valSymbol->getDimSize() == 0) {
        ctx->result = valSymbol->getIROperand();   
    }
    else {
        IROperand *newTempSum = irGenerator->addIRTemp(Type::INT);
        IROperand *newTempSum1;
        IROperand *newTempProduct;
        IROperand *newImmediate = irGenerator->addIRImmediate(Type::INT, std::to_string(0));
        irGenerator->addIRCode(Type::INT, IR_ADD, newTempSum, newImmediate, newImmediate);
        for (int i = 0; i < ctx->LBRACKET().size(); i++) {
            int nestedNum = 1;
            if (i < valSymbol->getDimSize()-1) {
                nestedNum = accumulate(valSymbol->getDimArray().begin()+i+1, valSymbol->getDimArray().end(), 1, std::multiplies<int>());
            }
            newImmediate = irGenerator->addIRImmediate(Type::INT, std::to_string(nestedNum * byteNum));
            ctx->exp(i)->accept(this);
            if (ctx->exp(i)->datatype != Type::INT || ctx->exp(i)->dimsize > 0) {
                throw runtime_error("The array index can only be int type.");
            }
            newTempProduct = irGenerator->addIRTemp(Type::INT);
            newTempSum1 = irGenerator->addIRTemp(Type::INT);
            irGenerator->addIRCode(Type::INT, IR_MUL, newTempProduct, ctx->exp(i)->result, newImmediate);
            irGenerator->addIRCode(Type::INT, IR_ADD, newTempSum1, newTempSum, newTempProduct);
            newTempSum = newTempSum1;
        }    
        if (ctx->dimsize == 0) {
            ctx->result = irGenerator->addIRArrayElem(valSymbol->getIROperand(), newTempSum);
        }
        else {
            ctx->result = irGenerator->addIRArrayAddr(valSymbol->getIROperand(), newTempSum);
        }
    }
    return std::any();
}

std::any Analysis::visitUnaryExppri(CACTParser::UnaryExppriContext *ctx) {
    ctx->priExp()->accept(this);
    ctx->datatype = ctx->priExp()->datatype;
    ctx->dimsize  = ctx->priExp()->dimsize;
    ctx->dimarr   = ctx->priExp()->dimarr;
    ctx->result   = ctx->priExp()->result;
    return std::any();
}

std::any Analysis::visitUnaryExpuna(CACTParser::UnaryExpunaContext *ctx) {
    ctx->unaryExp()->accept(this);
    if (ctx->NOT() != nullptr && ctx->unaryExp()->datatype != Type::BOOL) {
        throw std::runtime_error("logical not cannot be applied to non-boolean type variable.");
    }
    else if (ctx->unaryExp()->dimsize != 0) {
        throw std::runtime_error("unary operator cannot be applied to array.");
    }
    ctx->datatype = ctx->unaryExp()->datatype;
    ctx->dimsize  = 0;
    
    if (ctx->ADD()) {
        ctx->result = ctx->unaryExp()->result;
    }
    else {
        ctx->result   = irGenerator->addIRTemp(ctx->datatype);
        if (ctx->SUB()) {
            irGenerator->addIRCode(ctx->datatype, IR_NEG, ctx->result, ctx->unaryExp()->result, nullptr);
        }
        else {
            irGenerator->addIRCode(ctx->datatype, IR_NOT, ctx->result, ctx->unaryExp()->result, nullptr);
        }
    }
    return std::any();
}

std::any Analysis::visitUnaryExpfun(CACTParser::UnaryExpfunContext *ctx) {
    std::string symbolName = ctx->IDENT()->getText();
    FuncSymbol *funcSymbol = env->searchFuncSymbol(symbolName);
    if (funcSymbol == nullptr) {
        throw std::runtime_error("invoke undefined function.");
    }

    //function invoke type checking...
    if (funcSymbol->getParams().size() != 0) {
        if (ctx->funcRParams() != nullptr) {
            ctx->funcRParams()->funcsymbol = funcSymbol;
            ctx->funcRParams()->accept(this);
        }
        else {
            throw std::runtime_error("The number of formal parameters in function " + funcSymbol->getSymbolName() + " does not match the number of actual arguments.");
        }
    }
    else {
        if (ctx->funcRParams() != nullptr) {
            throw std::runtime_error("The number of formal parameters in function " + funcSymbol->getSymbolName() + " does not match the number of actual arguments.");
        }
    }
    //time for function invoke
    IROperand *newIRFunc = irGenerator->addIRFunc(funcSymbol);
    IROperand *newIRTemp;
    if (funcSymbol->getDataType() != Type::VOID) {
        newIRTemp = irGenerator->addIRTemp(funcSymbol->getDataType());
    }
    else {
        newIRTemp = nullptr;
    }
    irGenerator->addIRCode(funcSymbol->getDataType(), IR_CALL, newIRFunc, newIRTemp, nullptr);
    ctx->datatype = funcSymbol->getDataType();
    ctx->dimsize  = 0;
    ctx->result = newIRTemp;
    return std::any();
}

std::any Analysis::visitFuncRParams(CACTParser::FuncRParamsContext *ctx) {
    std::vector<ValSymbol *> params = ctx->funcsymbol->getParams();
    std::vector<CACTParser::ExpContext *> exps = ctx->exp();
    if (params.size() != exps.size()) {
        throw std::runtime_error("The number of formal parameters in function" + ctx->funcsymbol->getSymbolName() + "does not match the number of actual arguments.");
    }
    for (int i = 0; i < params.size(); i++) {
        exps[i]->accept(this);
        if (exps[i]->datatype != params[i]->getDataType()) {
            throw std::runtime_error("the parameter types of function "+ ctx->funcsymbol->getSymbolName() +" do not match the argument types.");
        }
        else if (params[i]->getDimSize() != exps[i]->dimsize) {
            throw std::runtime_error("the parameter dimensions of function "+ ctx->funcsymbol->getSymbolName() +" do not match the argument dimensions.");
            std::vector<int> dimArray = params[i]->getDimArray();
            for (int j = 0; j < params[i]->getDimSize(); j++) {
                if (dimArray[j] != exps[i]->dimarr[j] && dimArray[j] != -1) {
                    throw std::runtime_error("the parameter dimArray of function "+ ctx->funcsymbol->getSymbolName() +" do not match the argument dimArray.");
                }
            }
        }
        irGenerator->addIRCode(exps[i]->datatype, IR_PARAM, exps[i]->result, nullptr, nullptr);
    }
    return std::any();
}

std::any Analysis::visitMulExpmul(CACTParser::MulExpmulContext *ctx) {
    ctx->mulExp()->accept(this);
    if (ctx->mulExp()->datatype == Type::BOOL) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " cannot be applied to operands of boolean types.");
    }
    else if ((ctx->mulExp()->datatype == Type::FLOAT || ctx->mulExp()->datatype == Type::DOUBLE) && ctx->MOD() != nullptr) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " cannot be applied to operands of float or double types.");
    }
    else if (ctx->mulExp()->dimsize != 0) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " can only be applied to operands of basic types.");
    }
    
    ctx->unaryExp()->accept(this);
    if (ctx->unaryExp()->datatype != ctx->mulExp()->datatype) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " cannot be applied to operands of different types.");
    }
    else if (ctx->unaryExp()->dimsize != 0) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " can only be applied to operands of basic types.");
    }
    ctx->datatype = ctx->mulExp()->datatype;
    ctx->dimsize  = 0;

    if (dynamic_cast<IRImmediate*>(ctx->mulExp()->result) == nullptr || dynamic_cast<IRImmediate*>(ctx->unaryExp()->result) == nullptr) {
        ctx->result = irGenerator->addIRTemp(ctx->datatype);
        if (ctx->MUL() != nullptr) {
            irGenerator->addIRCode(ctx->datatype, IR_MUL, ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result);
        }
        else if (ctx->DIV() != nullptr) {
            irGenerator->addIRCode(ctx->datatype, IR_DIV, ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result);
        }
        else {
            irGenerator->addIRCode(ctx->datatype, IR_MOD, ctx->result, ctx->mulExp()->result, ctx->unaryExp()->result);
        }
    }
    else {
        if (ctx->datatype == INT) {
            int op1 = stoi(reinterpret_cast<IRImmediate*>(ctx->mulExp()->result)->val);
            int op2 = stoi(reinterpret_cast<IRImmediate*>(ctx->unaryExp()->result)->val);
            if (ctx->MUL() != nullptr)
                ctx->result = irGenerator->addIRImmediate(INT, std::to_string(op1 * op2));
            else if (ctx->DIV() != nullptr)
                ctx->result = irGenerator->addIRImmediate(INT, std::to_string(op1 / op2));
            else
                ctx->result = irGenerator->addIRImmediate(INT, std::to_string(op1 % op2));
        }
        else if (ctx->datatype == FLOAT) {
            float op1 = stof(reinterpret_cast<IRImmediate*>(ctx->mulExp()->result)->val);
            float op2 = stof(reinterpret_cast<IRImmediate*>(ctx->unaryExp()->result)->val);
            if (ctx->MUL() != nullptr)
                ctx->result = irGenerator->addIRImmediate(FLOAT, std::to_string(op1 * op2));
            else if (ctx->DIV() != nullptr)
                ctx->result = irGenerator->addIRImmediate(FLOAT, std::to_string(op1 / op2));
        }
        else{
            double op1 = stod(reinterpret_cast<IRImmediate*>(ctx->mulExp()->result)->val);
            double op2 = stod(reinterpret_cast<IRImmediate*>(ctx->unaryExp()->result)->val);
            if (ctx->MUL() != nullptr)
                ctx->result = irGenerator->addIRImmediate(DOUBLE, std::to_string(op1 * op2));
            else if (ctx->DIV() != nullptr)
                ctx->result = irGenerator->addIRImmediate(DOUBLE, std::to_string(op1 / op2));
        }
    }
    return std::any();
}

std::any Analysis::visitMulExpuna(CACTParser::MulExpunaContext *ctx) {
    ctx->unaryExp()->accept(this);
    ctx->datatype = ctx->unaryExp()->datatype;
    ctx->dimsize  = ctx->unaryExp()->dimsize;
    ctx->dimarr   = ctx->unaryExp()->dimarr;
    ctx->result = ctx->unaryExp()->result;
    return std::any();
}

std::any Analysis::visitAddExpadd(CACTParser::AddExpaddContext *ctx) {
    ctx->addExp()->accept(this);
    if (ctx->addExp()->datatype == Type::BOOL) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " cannot be applied to operands of boolean types.");
    }
    else if (ctx->addExp()->dimsize != 0) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " can only be applied to operands of basic types.");
    }
    
    ctx->mulExp()->accept(this);
    if (ctx->mulExp()->datatype != ctx->addExp()->datatype) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " cannot be applied to operands of different types.");
    }
    else if (ctx->mulExp()->dimsize != 0) {
        throw std::runtime_error("the operator " + ctx->op->getText() + " can only be applied to operands of basic types.");
    }
    ctx->datatype = ctx->addExp()->datatype;
    ctx->dimsize  = 0;

    if (dynamic_cast<IRImmediate*>(ctx->addExp()->result) == nullptr || dynamic_cast<IRImmediate*>(ctx->mulExp()->result) == nullptr) {
        ctx->result = irGenerator->addIRTemp(ctx->datatype);
        if (ctx->ADD() != nullptr) {
            irGenerator->addIRCode(ctx->datatype, IR_ADD, ctx->result, ctx->addExp()->result, ctx->mulExp()->result);
        }
        else {
            irGenerator->addIRCode(ctx->datatype, IR_SUB, ctx->result, ctx->addExp()->result, ctx->mulExp()->result);
        }
    }
    else {
        if (ctx->datatype == INT) {
            int op1 = stoi(reinterpret_cast<IRImmediate*>(ctx->addExp()->result)->val);
            int op2 = stoi(reinterpret_cast<IRImmediate*>(ctx->mulExp()->result)->val);
            if (ctx->ADD() != nullptr)
                ctx->result = irGenerator->addIRImmediate(INT, std::to_string(op1 + op2));
            else
                ctx->result = irGenerator->addIRImmediate(INT, std::to_string(op1 - op2));
        }
        else if (ctx->datatype == FLOAT) {
            float op1 = stof(reinterpret_cast<IRImmediate*>(ctx->addExp()->result)->val);
            float op2 = stof(reinterpret_cast<IRImmediate*>(ctx->mulExp()->result)->val);
            if (ctx->ADD() != nullptr)
                ctx->result = irGenerator->addIRImmediate(FLOAT, std::to_string(op1 + op2));
            else
                ctx->result = irGenerator->addIRImmediate(FLOAT, std::to_string(op1 - op2));
        }
        else{
            double op1 = stod(reinterpret_cast<IRImmediate*>(ctx->addExp()->result)->val);
            double op2 = stod(reinterpret_cast<IRImmediate*>(ctx->mulExp()->result)->val);
            if (ctx->ADD() != nullptr)
                ctx->result = irGenerator->addIRImmediate(DOUBLE, std::to_string(op1 + op2));
            else
                ctx->result = irGenerator->addIRImmediate(DOUBLE, std::to_string(op1 - op2));
        }
    }
    return std::any();
}

std::any Analysis::visitAddExpmul(CACTParser::AddExpmulContext *ctx) {
    ctx->mulExp()->accept(this);
    ctx->datatype = ctx->mulExp()->datatype;
    ctx->dimsize  = ctx->mulExp()->dimsize;
    ctx->dimarr   = ctx->mulExp()->dimarr;
    ctx->result = ctx->mulExp()->result;
    return std::any();
}

std::any Analysis::visitExp(CACTParser::ExpContext *ctx) {
    if (ctx->BOOLCONST() != nullptr) {
        ctx->datatype = Type::BOOL;
        ctx->dimsize  = 0;
        ctx->result = irGenerator->addIRImmediate(Type::BOOL, ctx->BOOLCONST()->getText());
    }
    else {
        ctx->addExp()->accept(this);
        ctx->datatype = ctx->addExp()->datatype;
        ctx->dimsize  = ctx->addExp()->dimsize;
        ctx->dimarr   = ctx->addExp()->dimarr;
        ctx->result   = ctx->addExp()->result;
    }
    return std::any();
}

std::any Analysis::visitStmtAssign(CACTParser::StmtAssignContext *ctx) {
    if (ctx->returnCheck) {
        throw runtime_error("missing return in function " + env->getCurrFunc()->getSymbolName() + ".");
    }
    ctx->lVal()->accept(this);
    if (ctx->lVal()->isConst) {
        throw std::runtime_error("lvalue in assign statement cannot be a const.");
    }
    ctx->exp()->accept(this);
    if (ctx->lVal()->dimsize > 0) {
        throw std::runtime_error("lvalue in assign statement cannot be an array.");
    }
    else if (ctx->lVal()->datatype != ctx->exp()->datatype) {
        throw std::runtime_error("data type mismatched in assign statement.");
    }
    else if (ctx->exp()->dimsize != 0) {
        throw std::runtime_error("expression in assign statement cannot be an array.");
    }
    irGenerator->addIRCode(ctx->lVal()->datatype, IR_ASSIGN, ctx->lVal()->result, ctx->exp()->result, nullptr);
    if (ctx->next == nullptr) {
        reinterpret_cast<CACTParser::BlockItemStmtContext*>(ctx->parent)->newLabel = nullptr;
    }
    return std::any();
}

std::any Analysis::visitStmtExp(CACTParser::StmtExpContext *ctx) {
    if (ctx->returnCheck) {
        throw runtime_error("missing return in function " + env->getCurrFunc()->getSymbolName() + ".");
    }
    ctx->exp()->accept(this);
    if (ctx->next == nullptr) {
        reinterpret_cast<CACTParser::BlockItemStmtContext*>(ctx->parent)->newLabel = nullptr;
    }
    return std::any();
}

std::any Analysis::visitStmtBlock(CACTParser::StmtBlockContext *ctx) {
    if (ctx->returnCheck) {
        ctx->block()->returnCheck = true;
    }
    ctx->block()->before = ctx->before;
    ctx->block()->next = ctx->next;
    ctx->block()->accept(this);
    if (ctx->next == nullptr) {
        reinterpret_cast<CACTParser::BlockItemStmtContext*>(ctx->parent)->newLabel = ctx->block()->newLabel;
    }
    return std::any();
}

std::any Analysis::visitStmtReturn(CACTParser::StmtReturnContext *ctx) {
    if (ctx->exp() != nullptr) {
        ctx->exp()->accept(this);
        if (ctx->exp()->datatype != env->getCurrFunc()->getDataType()) {
            throw std::runtime_error("the data type of return value mismatched with funtion definition.");
        }
        else if (ctx->exp()->dimsize > 0) {
            throw std::runtime_error("the return value cannot be an array.");
        }
        irGenerator->addIRCode(ctx->exp()->datatype, IR_RETURN, ctx->exp()->result, nullptr, nullptr);
    }
    else {
        if (env->getCurrFunc()->getDataType() != Type::VOID) {
            throw std::runtime_error("the data type of return value mismatched with funtion definition.");
        }
        irGenerator->addIRCode(Type::VOID, IR_RETURN, nullptr, nullptr, nullptr);
    }
    if (ctx->next == nullptr) {
        reinterpret_cast<CACTParser::BlockItemStmtContext*>(ctx->parent)->newLabel = nullptr;
    }
    return std::any();
}

std::any Analysis::visitStmtIf(CACTParser::StmtIfContext *ctx) {
    if (ctx->returnCheck) {
        throw runtime_error("missing return in function " + env->getCurrFunc()->getSymbolName() + ".");
    }
    bool addNewLabel = false;
    if (ctx->next == nullptr) {
        ctx->next = irGenerator->addIRLabel();
        reinterpret_cast<CACTParser::BlockItemStmtContext*>(ctx->parent)->newLabel = ctx->next;
        addNewLabel = true;
    }
    ctx->stmt()->next = ctx->next;
    ctx->lOrExp()->True  = nullptr; //fall
    ctx->lOrExp()->False = ctx->next;
    ctx->lOrExp()->accept(this);
    ctx->stmt()->accept(this);
    if (addNewLabel) {
        irGenerator->addIRCode(Type::VOID, IR_LABEL, ctx->next, nullptr, nullptr);
    }
    return std::any();
}

std::any Analysis::visitStmtIfElse(CACTParser::StmtIfElseContext *ctx) {
    if (ctx->returnCheck) {
        ctx->stmt(0)->returnCheck = true;
        ctx->stmt(1)->returnCheck = true;
    }
    bool addNewLabel = false;
    if (ctx->next == nullptr) {
        ctx->next = irGenerator->addIRLabel();
        reinterpret_cast<CACTParser::BlockItemStmtContext*>(ctx->parent)->newLabel = ctx->next;
        addNewLabel = true;
    }
    ctx->stmt(0)->next = ctx->next;
    ctx->stmt(1)->next = ctx->next;
    ctx->lOrExp()->True  = nullptr; //fall
    ctx->lOrExp()->False = irGenerator->addIRLabel();
    ctx->stmt(1)->before = ctx->lOrExp()->False;
    ctx->lOrExp()->accept(this);
    ctx->stmt(0)->accept(this);
    irGenerator->addIRCode(Type::VOID, IR_GOTO, ctx->next, nullptr, nullptr);
    irGenerator->addIRCode(Type::VOID, IR_LABEL, ctx->lOrExp()->False, nullptr, nullptr);
    ctx->stmt(1)->accept(this);
    if (addNewLabel) {
        irGenerator->addIRCode(Type::VOID, IR_LABEL, ctx->next, nullptr, nullptr);
    }
    return std::any();
}

std::any Analysis::visitStmtWhile(CACTParser::StmtWhileContext *ctx) {
    if (ctx->returnCheck) {
        throw runtime_error("missing return in function " + env->getCurrFunc()->getSymbolName() + ".");
    }
    if (ctx->before == nullptr) {
        ctx->before = irGenerator->addIRLabel();
        irGenerator->addIRCode(Type::VOID, IR_LABEL, ctx->before, nullptr, nullptr);
    }
    ctx->stmt()->next = ctx->before;
    
    bool addNewLabel = false;
    if (ctx->next == nullptr) {
        ctx->next = irGenerator->addIRLabel();
        reinterpret_cast<CACTParser::BlockItemStmtContext*>(ctx->parent)->newLabel = ctx->next;
        addNewLabel = true;
    }
    
    WhileCtx *newWhile = new WhileCtx(currWhile, ctx->next, ctx->before);
    currWhile = newWhile;
    
    ctx->lOrExp()->True  = nullptr; //fall
    ctx->lOrExp()->False = ctx->next;
    ctx->stmt()->next  = ctx->before;
    ctx->lOrExp()->accept(this);
    ctx->stmt()->accept(this);
    irGenerator->addIRCode(Type::VOID, IR_GOTO, ctx->before, nullptr, nullptr);
    if (addNewLabel) {
        irGenerator->addIRCode(Type::VOID, IR_LABEL, ctx->next, nullptr, nullptr);
    }
    currWhile = currWhile->preWhileCtx;
    return std::any();
}

std::any Analysis::visitStmtBreak(CACTParser::StmtBreakContext *ctx) {
    if (ctx->returnCheck) {
        throw runtime_error("missing return in function " + env->getCurrFunc()->getSymbolName() + ".");
    }
    if (currWhile == nullptr) {
        return std::any();
    }
    irGenerator->addIRCode(Type::VOID, IR_GOTO, currWhile->breakDst, nullptr, nullptr);
    return std::any();
}

std::any Analysis::visitStmtContinue(CACTParser::StmtContinueContext *ctx) {
    if (ctx->returnCheck) {
        throw runtime_error("missing return in function " + env->getCurrFunc()->getSymbolName() + ".");
    }
    if (currWhile == nullptr) {
        return std::any();
    }
    irGenerator->addIRCode(Type::VOID, IR_GOTO, currWhile->contDst, nullptr, nullptr);
    return std::any();
}

std::any Analysis::visitLOrExpand(CACTParser::LOrExpandContext *ctx) {
    if (ctx->first) {
        ctx->lAndExp()->True  = nullptr;
        ctx->lAndExp()->False = ctx->False;
    }
    else {
        ctx->lAndExp()->True  = irGenerator->addIRLabel();
        ctx->lAndExp()->False = nullptr; //fall
        reinterpret_cast<CACTParser::LOrExporContext*>(ctx->parent)->newLabel = ctx->lAndExp()->True;
    }
    ctx->lAndExp()->accept(this);
    return std::any();
}

std::any Analysis::visitLOrExpor(CACTParser::LOrExporContext *ctx) {
    ctx->lOrExp()->first = false;
    
    ctx->lOrExp()->accept(this);
    if (ctx->first) {
        ctx->lAndExp()->True = nullptr;
        ctx->lAndExp()->False = ctx->False;
    }
    else {
        ctx->lAndExp()->True = ctx->newLabel;
        ctx->lAndExp()->False = nullptr;
        reinterpret_cast<CACTParser::LOrExporContext*>(ctx->parent)->newLabel = ctx->newLabel;
    }
    ctx->lAndExp()->accept(this);
    if (ctx->first) {
        irGenerator->addIRCode(Type::VOID, IR_LABEL, ctx->newLabel, nullptr, nullptr);
    }
    return std::any();
}

std::any Analysis::visitLAndExpeq(CACTParser::LAndExpeqContext *ctx) {
    if (ctx->first) {
        ctx->eqExp()->True  = ctx->True;
        ctx->eqExp()->False = ctx->False;
    }
    else {
        if (ctx->True == nullptr) {
            ctx->eqExp()->True  = nullptr;
            ctx->eqExp()->False = ctx->False; 
        }
        else {
            ctx->eqExp()->True  = nullptr;
            ctx->eqExp()->False = irGenerator->addIRLabel();
            reinterpret_cast<CACTParser::LAndExpandContext*>(ctx->parent)->newLabel = ctx->eqExp()->False; 
        }
    }
    ctx->eqExp()->accept(this);
    return std::any();
}

std::any Analysis::visitLAndExpand(CACTParser::LAndExpandContext *ctx) {
    ctx->lAndExp()->first = false;
    ctx->lAndExp()->True  = ctx->True;
    ctx->lAndExp()->False = ctx->False;
    
    ctx->lAndExp()->accept(this);
    if (ctx->first) {
        if (ctx->True == nullptr) {
            ctx->eqExp()->True  = nullptr;
            ctx->eqExp()->False = ctx->False; 
        }
        else {
            ctx->eqExp()->True  = ctx->True;
            ctx->eqExp()->False = nullptr; 
        }
    }
    else {
        if (ctx->True == nullptr) {
            ctx->eqExp()->True  = nullptr;
            ctx->eqExp()->False = ctx->False; 
        }
        else {
            ctx->eqExp()->True  = nullptr;
            ctx->eqExp()->False = ctx->newLabel; 
            reinterpret_cast<CACTParser::LAndExpandContext*>(ctx->parent)->newLabel = ctx->newLabel;
        }
    }
    ctx->eqExp()->accept(this);
    if (ctx->first && ctx->True != nullptr) {
        irGenerator->addIRCode(Type::VOID, IR_LABEL, ctx->newLabel, nullptr, nullptr);
    }
    return std::any();
}

std::any Analysis::visitEqExprel(CACTParser::EqExprelContext *ctx) {
    if (dynamic_cast<CACTParser::RelExpaddContext*>(ctx->relExp()) != nullptr) {
        throw std::runtime_error("illegal conditional expression.");
    }
    ctx->relExp()->True  = ctx->True;
    ctx->relExp()->False = ctx->False;
    ctx->relExp()->accept(this);
    return std::any();
}

std::any Analysis::visitEqExpeq(CACTParser::EqExpeqContext *ctx) {
    ctx->relExp(0)->jump = false;
    ctx->relExp(1)->jump = false;
    ctx->relExp(0)->accept(this);
    ctx->relExp(1)->accept(this);
    if (ctx->relExp(0)->datatype != ctx->relExp(1)->datatype) {
        throw std::runtime_error("cannot compare data of different types.");
    }
    if (ctx->EQ()) {
        if (ctx->True == nullptr) {
            irGenerator->addIRCode(ctx->relExp(0)->datatype, IR_BNE, ctx->False, ctx->relExp(0)->result, ctx->relExp(1)->result);
        }
        else {
            irGenerator->addIRCode(ctx->relExp(0)->datatype, IR_BEQ, ctx->True, ctx->relExp(0)->result, ctx->relExp(1)->result);
        }
    }
    else {
        if (ctx->True == nullptr) {
            irGenerator->addIRCode(ctx->relExp(0)->datatype, IR_BEQ, ctx->False, ctx->relExp(0)->result, ctx->relExp(1)->result);
        }
        else {
            irGenerator->addIRCode(ctx->relExp(0)->datatype, IR_BNE, ctx->True, ctx->relExp(0)->result, ctx->relExp(1)->result);
        }
    }
    return std::any();
}

std::any Analysis::visitRelExpadd(CACTParser::RelExpaddContext *ctx) {
    ctx->addExp()->accept(this);
    ctx->datatype = ctx->addExp()->datatype;
    ctx->result = ctx->addExp()->result;
    return std::any();
}

std::any Analysis::visitRelExprel(CACTParser::RelExprelContext *ctx) {
    ctx->addExp(0)->accept(this);
    ctx->addExp(1)->accept(this);
    if (ctx->addExp(0)->datatype != ctx->addExp(1)->datatype) {
        throw std::runtime_error("cannot compare data of different types.");
    }
    ctx->datatype = Type::BOOL;
    if (ctx->jump) {
        if (ctx->LT()) {
            if (ctx->True == nullptr) {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BGE, ctx->False, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
            else {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BLT, ctx->True, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
        }
        else if (ctx->GT()) {
            if (ctx->True == nullptr) {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BLE, ctx->False, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
            else {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BGT, ctx->True, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
        }
        else if (ctx->LE()) {
            if (ctx->True == nullptr) {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BGT, ctx->False, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
            else {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BLE, ctx->True, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
        }
        else {
            if (ctx->True == nullptr) {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BLT, ctx->False, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
            else {
                irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_BGE, ctx->True, ctx->addExp(0)->result, ctx->addExp(1)->result);
            }
        }
    }
    else {
        ctx->result = irGenerator->addIRTemp(Type::BOOL);
        if (ctx->LT()) {
            irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_SLT, ctx->result, ctx->addExp(0)->result, ctx->addExp(1)->result);
        }
        else if (ctx->GT()) {
            irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_SLT, ctx->result, ctx->addExp(1)->result, ctx->addExp(0)->result);
        }
        else if (ctx->LE()) {
            irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_SLTE, ctx->result, ctx->addExp(0)->result, ctx->addExp(1)->result);
        }
        else if (ctx->GE()) {
            irGenerator->addIRCode(ctx->addExp(0)->datatype, IR_SLTE, ctx->result, ctx->addExp(1)->result, ctx->addExp(0)->result);
        }
    }
    return std::any();
}

std::any Analysis::visitRelExpbool(CACTParser::RelExpboolContext *ctx) {
    ctx->datatype = Type::BOOL;
    ctx->result = irGenerator->addIRImmediate(Type::BOOL, ctx->BOOLCONST()->getText());
    return std::any();
}

