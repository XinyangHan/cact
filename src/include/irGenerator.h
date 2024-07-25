#pragma once 
#include "irCode.h"
#include <map>
using namespace std;

class IRGenerator {
    private:
    IROptimizer *irOptimizer;
    public:
    std::vector<IRCode*> irCodeList;
    std::vector<IRCode*> newCodeList;
    std::map<std::string, IROperand*> immediatePool;
    
    IRGenerator() {irOptimizer = new IROptimizer();}
    IROperand *addIRGloblVar(Type dataType, std::vector<IROperand*> &initVal);
    IROperand *addIRGloblVar(Type dataType, int len, std::vector<IROperand*> &initVal);
    IROperand *addIRLocalVar(Type dataType, std::vector<IROperand*> &initVal);
    IROperand *addIRLocalVar(Type dataType, int len, std::vector<IROperand*> &initVal);
    IROperand *addIRImmediate(Type dataType, const std::string &val);
    IROperand *addIRTemp(Type dataType);
    IROperand *addIRArrayElem(IROperand *arrayPtr, IROperand *tempPtr);
    IROperand *addIRArrayAddr(IROperand *arrayPtr, IROperand *tempPtr);
    IROperand *addIRLabel();
    IROperand *addIRFunc(FuncSymbol *funcSymbol);
    void addIRCode(Type dataType, IROpCode opCode, IROperand *dst, IROperand *src1, IROperand *src2);
    void printIRCode(std::ofstream &irCodeFile, int);
    std::vector<BasicBlock*>& invokeOpt(std::ofstream &irCodeFile);
    std::vector<BasicBlock*>& O0();
    std::vector<BasicBlock*>& O1();
    std::vector<IRCode*>& getOptIRCode();
};

