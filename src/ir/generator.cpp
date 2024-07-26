#include "include/ir/generator.h"
using namespace std;

IROperand *IntermediateCodeGenerator::addIrGlobalVariable(Type dataType, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRGloblScalar(dataType, initVal);
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::addIrGlobalVariable(Type dataType, int len, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRGloblArray(dataType, len, initVal);
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::addIRLocalVar(Type dataType, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRLocalScalar(dataType, initVal);
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::addIRLocalVar(Type dataType, int len, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRLocalArray(dataType, len, initVal);
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::addIRImmediateValue(Type dataType, const std::string &val) {
    auto it = immediatePool.find(val);
    if (it != this->immediatePool.end()) {
        return it->second;
    }
    else {
        IROperand *newIROperand = new IRImmediateValue(dataType, val);
        immediatePool[val] = newIROperand;
        return newIROperand;
    }
}

IROperand *IntermediateCodeGenerator::addTemporaryValue(Type dataType) {
    IROperand *newIROperand = new TemporaryValue(dataType);
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::addArrayElement(IROperand *arrayPtr, IROperand *tempPtr) {
    IROperand *newIROperand = new IRArrayElem(arrayPtr, tempPtr);
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::addIRArrayAddr(IROperand *arrayPtr, IROperand *tempPtr) {
    IROperand *newIROperand = new IRArrayAddr(arrayPtr, tempPtr);
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::createLabel() {
    IROperand *newIROperand = new IRLabel();
    return newIROperand;
}

IROperand *IntermediateCodeGenerator::addIRFunc(FuncSymbol *funcSymbol) {
    IROperand *newIROperand = new IRFunc(funcSymbol);
    return newIROperand;
}

void IntermediateCodeGenerator::addIntermediateCode(Type dataType, IROpCode opCode, IROperand *dst, IROperand *src1, IROperand *src2) {
    irCodeList.push_back(new IntermediateCode(dataType, opCode, dst, src1, src2));  
}

void IntermediateCodeGenerator::logIrCode(std::ofstream &irCodeFile, int optVersion) {
    if (optVersion == 1) {
        irOptimizer->printOptIntermediateCode(irCodeFile);
        return;
    }

    for (auto const & irCode : newCodeList) {
        irCode->print(irCodeFile);
    }
}

std::vector<BasicBlock*>& IntermediateCodeGenerator::optimize(std::ofstream &irCodeFile) {
    //partition the original IRcode into seperate basic blocks 
    irOptimizer->partitionBlocks(irCodeList);
    irOptimizer->printBlocks();
    //for each basic block, eliminate any redundant subexpression
    irOptimizer->eliminateCommonSubexp();
    irOptimizer->calculateLiveness();
    irOptimizer->rebuildIR();
    irOptimizer->printOptIntermediateCode(irCodeFile);
    return irOptimizer->basicBlockList;
}

std::vector<BasicBlock*>& IntermediateCodeGenerator::O0() {
    //partition the original IRcode into seperate basic blocks 
    for (auto irCode : irCodeList){
        switch(irCode->opCode){
            case IR_ASSIGN:
            {
                TemporaryValue *newTemp = new TemporaryValue(irCode->dataType);
                newCodeList.push_back(new IntermediateCode(irCode->dataType, irCode->opCode, newTemp, irCode->src1, irCode->src2));
                newCodeList.push_back(new IntermediateCode(irCode->dataType, IR_ASSIGN, irCode->dst, newTemp, nullptr));
                break;
            }
            default:
                newCodeList.push_back(irCode); 
        }
    }
    irOptimizer->partitionBlocks(newCodeList);
    //irOptimizer->propagateConsts(this);
    for (auto basicBlock : irOptimizer->basicBlockList)
        for (auto irCode : basicBlock->partitionedIR)
            basicBlock->rebuildIR.push_back(irCode);
    irOptimizer->calculateLiveness();
    return irOptimizer->basicBlockList;
}

std::vector<BasicBlock*>& IntermediateCodeGenerator::O1() {
    //partition the original IRcode into seperate basic blocks 
    //irOptimizer->optimizeJumps(irCodeList);
    irOptimizer->partitionBlocks(irCodeList);
    irOptimizer->propagateConsts(this);
    //for each basic block, eliminate any redundant subexpression
    irOptimizer->eliminateCommonSubexp();
    irOptimizer->calculateLiveness();
    irOptimizer->rebuildIR();
    //irOptimizer->printOptIntermediateCode(irCodeFile);
    return irOptimizer->basicBlockList;
}

std::vector<IntermediateCode*>& IntermediateCodeGenerator::getOptIntermediateCode() {
    return irOptimizer->optIrCodeList;
}

