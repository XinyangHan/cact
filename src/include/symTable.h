#pragma once
#include <map>
#include <stdexcept>
#include "include/irOperand.h"

class Symbol {
    private:
    Type dataType;
    std::string symbolName;
    
    public:
    Symbol(Type dataType, std::string &symbolName) : dataType(dataType), symbolName(symbolName) {}
    Type getDataType() {return dataType;}
    std::string &getSymbolName() {return symbolName;}
};

class ValSymbol : public Symbol {
    private:
    int dimSize;
    std::vector<int> dimArray;
    bool isConst;
    IROperand *operand;
    
    public:
    ValSymbol(Type dataType, std::string &symbolName, int dimSize, std::vector<int> &dimArray, bool isConst) : Symbol(dataType, symbolName), dimSize(dimSize), dimArray(dimArray), isConst(isConst) {}
    int getDimSize() {return dimSize;}
    std::vector<int> &getDimArray() {return dimArray;}
    bool getIsConst() {return isConst;}
    void setIROperand(IROperand *operand) {this->operand = operand;}
    IROperand *getIROperand() {return operand;}
};

class FuncSymbol : public Symbol {
    private:
    std::vector<ValSymbol *> params;
    
    public:
    FuncSymbol(Type dataType, std::string &symbolName) : Symbol(dataType, symbolName) {}
    std::vector<ValSymbol *> &getParams() {return params;}
    void addParam(ValSymbol *valSymbol);
};

class Block {
    private:
    Block *pre;
    std::map<std::string, ValSymbol *> valSymbolTable;
    
    public:
    Block(Block *pre) : pre(pre) {}
    ValSymbol *addValSymbol(Type dataType, std::string &symbolName, int dimSize, std::vector<int> &dimArray, bool isConst);
    ValSymbol *searchValSymbol(std::string &symbolName);
    Block *getPre() {return pre;}
};

class Env {
    private:
    static Env *instance;
    Block topBlock;
    Block *currBlock;
    FuncSymbol *currFunc;
    std::map<std::string, FuncSymbol *> funcSymbolTable;
    
    Env() : topBlock(nullptr), currBlock(&topBlock), currFunc(nullptr) {}
    
    public:
    static Env* getInstance() {
        if (!instance) {
            instance = new Env();
        }
        return instance;
    }
    Env(const Env& other) = delete;
    void setCurrBlock(Block *currBlock) {this->currBlock = currBlock;}
    Block *getCurrBlock() {return currBlock;}
    void setCurrFunc(FuncSymbol *currFunc) {this->currFunc = currFunc;}
    FuncSymbol *getCurrFunc() {return currFunc;}
    FuncSymbol *addFuncSymbol(Type dataType, std::string &symbolName);
    FuncSymbol *searchFuncSymbol(std::string &symbolName);
};