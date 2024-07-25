#include "include/symTable.h"

void FuncSymbol::addParam(ValSymbol *valSymbol) {
    params.push_back(valSymbol);
}

ValSymbol *Block::addValSymbol(Type dataType, std::string &symbolName, int dimSize, std::vector<int> &dimArray, bool isConst) {
    auto it = this->valSymbolTable.find(symbolName);
    if (it != this->valSymbolTable.end()) {
        throw std::runtime_error("redeclaration of " + symbolName);
    }
    else {
        ValSymbol *valSymbol = new ValSymbol(dataType, symbolName, dimSize, dimArray, isConst);
        this->valSymbolTable[symbolName] = valSymbol;
        return valSymbol;
    }
}

ValSymbol *Block::searchValSymbol(std::string &symbolName) {
    auto it = this->valSymbolTable.find(symbolName);
    if (it != this->valSymbolTable.end()) {
        return it->second;
    }
    else if (this->pre != nullptr) {
        return this->pre->searchValSymbol(symbolName);
    }
    return nullptr;
}

FuncSymbol *Env::addFuncSymbol(Type dataType, std::string &symbolName) {
    auto it = this->funcSymbolTable.find(symbolName);
    if (it != this->funcSymbolTable.end()) {
        throw std::runtime_error("redeclaration of " + symbolName);
    }
    else {
        FuncSymbol *funcSymbol = new FuncSymbol(dataType, symbolName);
        this->funcSymbolTable[symbolName] = funcSymbol;
        return funcSymbol;
    }
}

FuncSymbol *Env::searchFuncSymbol(std::string &symbolName) {
    auto it = this->funcSymbolTable.find(symbolName);
    if (it == this->funcSymbolTable.end()) {
        return nullptr;
    }
    else {
        return it->second;
    }
}

