#include "include/symTable.h"

// 为函数符号添加参数
void FuncSymbol::addParam(ValSymbol *valSymbol) {
    params.push_back(valSymbol);
}

// 在块中添加变量符号
ValSymbol *Block::addValSymbol(Type dataType, std::string &symbolName, int dimSize, std::vector<int> &dimArray, bool isConst) {
    auto it = this->valSymbolTable.find(symbolName);
    if (it != this->valSymbolTable.end()) {
        // 如果符号表中已经存在同名符号，则抛出重定义错误
        throw std::runtime_error("redeclaration of " + symbolName);
    }
    else {
        // 否则创建一个新的变量符号并添加到符号表中
        ValSymbol *valSymbol = new ValSymbol(dataType, symbolName, dimSize, dimArray, isConst);
        this->valSymbolTable[symbolName] = valSymbol;
        return valSymbol;
    }
}

// 在当前块及其前置块中搜索变量符号
ValSymbol *Block::searchValSymbol(std::string &symbolName) {
    auto it = this->valSymbolTable.find(symbolName);
    if (it != this->valSymbolTable.end()) {
        // 如果在当前块中找到符号，则返回
        return it->second;
    }
    else if (this->pre != nullptr) {
        // 否则在前置块中递归搜索
        return this->pre->searchValSymbol(symbolName);
    }
    return nullptr;  // 如果在所有块中都未找到，则返回空指针
}

// 在环境中添加函数符号
FuncSymbol *Env::addFuncSymbol(Type dataType, std::string &symbolName) {
    auto it = this->funcSymbolTable.find(symbolName);
    if (it != this->funcSymbolTable.end()) {
        // 如果符号表中已经存在同名符号，则抛出重定义错误
        throw std::runtime_error("redeclaration of " + symbolName);
    }
    else {
        // 否则创建一个新的函数符号并添加到符号表中
        FuncSymbol *funcSymbol = new FuncSymbol(dataType, symbolName);
        this->funcSymbolTable[symbolName] = funcSymbol;
        return funcSymbol;
    }
}

// 在环境中搜索函数符号
FuncSymbol *Env::searchFuncSymbol(std::string &symbolName) {
    auto it = this->funcSymbolTable.find(symbolName);
    if (it == this->funcSymbolTable.end()) {
        // 如果在符号表中未找到符号，则返回空指针
        return nullptr;
    }
    else {
        // 如果找到符号，则返回
        return it->second;
    }
}