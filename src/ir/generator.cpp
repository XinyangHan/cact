#include "include/ir/generator.h" // 包含IR生成器头文件
using namespace std; // 使用标准命名空间

// 添加全局变量的中间代码（标量）
IROperand *IntermediateCodeGenerator::addIrGlobalVariable(Type dataType, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRGloblScalar(dataType, initVal);
    return newIROperand;
}

// 添加全局变量的中间代码（数组）
IROperand *IntermediateCodeGenerator::addIrGlobalVariable(Type dataType, int len, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRGloblArray(dataType, len, initVal);
    return newIROperand;
}

// 添加局部变量的中间代码（标量）
IROperand *IntermediateCodeGenerator::addIRLocalVar(Type dataType, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRLocalScalar(dataType, initVal);
    return newIROperand;
}

// 添加局部变量的中间代码（数组）
IROperand *IntermediateCodeGenerator::addIRLocalVar(Type dataType, int len, std::vector<IROperand*> &initVal) {
    IROperand *newIROperand = new IRLocalArray(dataType, len, initVal);
    return newIROperand;
}

// 添加立即数值的中间代码
IROperand *IntermediateCodeGenerator::addIRImmediateValue(Type dataType, const std::string &val) {
    auto it = immediatePool.find(val);
    if (it != this->immediatePool.end()) {
        return it->second;
    } else {
        IROperand *newIROperand = new IRImmediateValue(dataType, val);
        immediatePool[val] = newIROperand;
        return newIROperand;
    }
}

// 添加临时变量的中间代码
IROperand *IntermediateCodeGenerator::addTemporaryValue(Type dataType) {
    IROperand *newIROperand = new TemporaryValue(dataType);
    return newIROperand;
}

// 添加数组元素的中间代码
IROperand *IntermediateCodeGenerator::addArrayElement(IROperand *arrayPtr, IROperand *tempPtr) {
    IROperand *newIROperand = new IRArrayElem(arrayPtr, tempPtr);
    return newIROperand;
}

// 添加数组地址的中间代码
IROperand *IntermediateCodeGenerator::addIRArrayAddr(IROperand *arrayPtr, IROperand *tempPtr) {
    IROperand *newIROperand = new IRArrayAddr(arrayPtr, tempPtr);
    return newIROperand;
}

// 创建标签的中间代码
IROperand *IntermediateCodeGenerator::createLabel() {
    IROperand *newIROperand = new IRLabel();
    return newIROperand;
}

// 添加函数的中间代码
IROperand *IntermediateCodeGenerator::addIRFunc(FuncSymbol *funcSymbol) {
    IROperand *newIROperand = new IRFunc(funcSymbol);
    return newIROperand;
}

// 添加中间代码
void IntermediateCodeGenerator::addIntermediateCode(Type dataType, IROpCode opCode, IROperand *dst, IROperand *src1, IROperand *src2) {
    irCodeList.push_back(new IntermediateCode(dataType, opCode, dst, src1, src2));  
}

// 记录中间代码到文件
void IntermediateCodeGenerator::logIrCode(std::ofstream &irCodeFile, int optVersion) {
    if (optVersion == 1) {
        irOptimizer->printOptIntermediateCode(irCodeFile);
        return;
    }

    for (auto const & irCode : newCodeList) {
        irCode->print(irCodeFile);
    }
}

// 优化中间代码
std::vector<BasicBlock*>& IntermediateCodeGenerator::optimize(std::ofstream &irCodeFile) {
    irOptimizer->splitIntoBasicBlocks(irCodeList); // 将原始中间代码分区为基本块
    irOptimizer->printBlocks(); // 打印基本块
    irOptimizer->eliminateCommonSubexp(); // 消除公共子表达式
    irOptimizer->calculateLiveness(); // 计算活跃度
    irOptimizer->rebuildIR(); // 重建中间代码
    irOptimizer->printOptIntermediateCode(irCodeFile); // 打印优化后的中间代码
    return irOptimizer->basicBlockList;
}

// 优化级别O0
std::vector<BasicBlock*>& IntermediateCodeGenerator::O0() {
    for (auto irCode : irCodeList) {
        switch(irCode->opCode) {
            case IR_ASSIGN: {
                TemporaryValue *newTemp = new TemporaryValue(irCode->dataType);
                newCodeList.push_back(new IntermediateCode(irCode->dataType, irCode->opCode, newTemp, irCode->src1, irCode->src2));
                newCodeList.push_back(new IntermediateCode(irCode->dataType, IR_ASSIGN, irCode->dst, newTemp, nullptr));
                break;
            }
            default:
                newCodeList.push_back(irCode); 
        }
    }
    irOptimizer->splitIntoBasicBlocks(newCodeList); // 将新代码列表分区为基本块
    for (auto basicBlock : irOptimizer->basicBlockList)
        for (auto irCode : basicBlock->partitionedIR)
            basicBlock->rebuildIR.push_back(irCode);
    irOptimizer->calculateLiveness(); // 计算活跃度
    return irOptimizer->basicBlockList;
}

// 优化级别O1
std::vector<BasicBlock*>& IntermediateCodeGenerator::O1() {
    irOptimizer->splitIntoBasicBlocks(irCodeList); // 将原始中间代码分区为基本块
    irOptimizer->executeConstantPropagation(this); // 传播常量
    irOptimizer->eliminateCommonSubexp(); // 消除公共子表达式
    irOptimizer->calculateLiveness(); // 计算活跃度
    irOptimizer->rebuildIR(); // 重建中间代码
    return irOptimizer->basicBlockList;
}

// 获取优化后的中间代码
std::vector<IntermediateCode*>& IntermediateCodeGenerator::getOptIntermediateCode() {
    return irOptimizer->optIrCodeList;
}
