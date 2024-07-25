#include "irGenerator.h"
using namespace std;

IROperand *IRGenerator::addIRGloblVar(Type dataType, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRGloblScalar(dataType, initVal);
    return newIROperand;
}

IROperand *IRGenerator::addIRGloblVar(Type dataType, int len, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRGloblArray(dataType, len, initVal);
    return newIROperand;
}

IROperand *IRGenerator::addIRLocalVar(Type dataType, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRLocalScalar(dataType, initVal);
    return newIROperand;
}

IROperand *IRGenerator::addIRLocalVar(Type dataType, int len, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRLocalArray(dataType, len, initVal);
    return newIROperand;
}

IROperand *IRGenerator::addIRImmediate(Type dataType, const std::string &val) {
    auto it = immediatePool.find(val);
    if (it != this->immediatePool.end()) {
        return it->second;
    }
    else {
        IROperand *newIROperand = new IRImmediate(dataType, val);
        immediatePool[val] = newIROperand;
        return newIROperand;
    }
}

IROperand *IRGenerator::addIRTemp(Type dataType) {
    IROperand *newIROperand = new IRTemp(dataType);
    return newIROperand;
}

IROperand *IRGenerator::addIRArrayElem(IROperand *arrayPtr, IROperand *tempPtr) {
    IROperand *newIROperand = new IRArrayElem(arrayPtr, tempPtr);
    return newIROperand;
}

IROperand *IRGenerator::addIRArrayAddr(IROperand *arrayPtr, IROperand *tempPtr) {
    IROperand *newIROperand = new IRArrayAddr(arrayPtr, tempPtr);
    return newIROperand;
}

IROperand *IRGenerator::addIRLabel() {
    IROperand *newIROperand = new IRLabel();
    return newIROperand;
}

IROperand *IRGenerator::addIRFunc(FuncSymbol *funcSymbol) {
    IROperand *newIROperand = new IRFunc(funcSymbol);
    return newIROperand;
}

void IRGenerator::addIRCode(Type dataType, IROpCode opCode, IROperand *dst, IROperand *src1, IROperand *src2) {
    irCodeList.push_back(new IRCode(dataType, opCode, dst, src1, src2));  
    //std::ofstream debug;
    //debug.open("./debug.txt");
    //printIRCode(debug);
    //debug << std::endl << std::endl;
    //debug.close();
}

void IRGenerator::printIRCode(std::ofstream &irCodeFile, int optVersion) {
    if (optVersion == 1) {
        irOptimizer->printOptIRCode(irCodeFile);
        return;
    }

    for (auto const & irCode : newCodeList) {
        irCode->print(irCodeFile);
    }
}

std::vector<BasicBlock*>& IRGenerator::invokeOpt(std::ofstream &irCodeFile) {
    //partition the original IRcode into seperate basic blocks 
    irOptimizer->basicBlockPartition(irCodeList);
    irOptimizer->printBasicBlock();
    //for each basic block, eliminate any redundant subexpression
    irOptimizer->commonSubexpssionEliminate();
    irOptimizer->calLiveInfo();
    irOptimizer->irRebuild();
    irOptimizer->printOptIRCode(irCodeFile);
    return irOptimizer->basicBlockList;
}

std::vector<BasicBlock*>& IRGenerator::O0() {
    //partition the original IRcode into seperate basic blocks 
    for (auto irCode : irCodeList){
        switch(irCode->opCode){
            case IR_ASSIGN:
            {
                IRTemp *newTemp = new IRTemp(irCode->dataType);
                newCodeList.push_back(new IRCode(irCode->dataType, irCode->opCode, newTemp, irCode->src1, irCode->src2));
                newCodeList.push_back(new IRCode(irCode->dataType, IR_ASSIGN, irCode->dst, newTemp, nullptr));
                break;
            }
            default:
                newCodeList.push_back(irCode); 
        }
    }
    irOptimizer->basicBlockPartition(newCodeList);
    //irOptimizer->constPass(this);
    for (auto basicBlock : irOptimizer->basicBlockList)
        for (auto irCode : basicBlock->partitionedIR)
            basicBlock->rebuildIR.push_back(irCode);
    irOptimizer->calLiveInfo();
    return irOptimizer->basicBlockList;
}

std::vector<BasicBlock*>& IRGenerator::O1() {
    //partition the original IRcode into seperate basic blocks 
    //irOptimizer->jumpPass(irCodeList);
    irOptimizer->basicBlockPartition(irCodeList);
    irOptimizer->constPass(this);
    //for each basic block, eliminate any redundant subexpression
    irOptimizer->commonSubexpssionEliminate();
    irOptimizer->calLiveInfo();
    irOptimizer->irRebuild();
    //irOptimizer->printOptIRCode(irCodeFile);
    return irOptimizer->basicBlockList;
}

std::vector<IRCode*>& IRGenerator::getOptIRCode() {
    return irOptimizer->optIrCodeList;
}

