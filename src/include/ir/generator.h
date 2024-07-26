#pragma once // 防止头文件被重复包含
#include "code.h" // 包含code.h头文件
#include <map> // 引入std::map类型
using namespace std; // 使用标准命名空间

class IntermediateCodeGenerator { // IntermediateCodeGenerator类的定义
    private:
    IROptimizer *irOptimizer; // 优化器指针

    public:
    std::vector<IntermediateCode*> irCodeList; // 中间代码列表
    std::vector<IntermediateCode*> newCodeList; // 新生成的中间代码列表
    std::map<std::string, IROperand*> immediatePool; // 立即数池
    
    // 构造函数，初始化优化器指针
    IntermediateCodeGenerator() {irOptimizer = new IROptimizer();}

    // 添加全局变量的中间代码（带初始化值）
    IROperand *addIrGlobalVariable(Type dataType, std::vector<IROperand*> &initVal);

    // 添加全局变量的中间代码（带长度和初始化值）
    IROperand *addIrGlobalVariable(Type dataType, int len, std::vector<IROperand*> &initVal);

    // 添加局部变量的中间代码（带初始化值）
    IROperand *addIRLocalVar(Type dataType, std::vector<IROperand*> &initVal);

    // 添加局部变量的中间代码（带长度和初始化值）
    IROperand *addIRLocalVar(Type dataType, int len, std::vector<IROperand*> &initVal);

    // 添加立即数值的中间代码
    IROperand *addIRImmediateValue(Type dataType, const std::string &val);

    // 添加临时变量的中间代码
    IROperand *addTemporaryValue(Type dataType);

    // 添加数组元素的中间代码
    IROperand *addArrayElement(IROperand *arrayPtr, IROperand *tempPtr);

    // 添加数组地址的中间代码
    IROperand *addIRArrayAddr(IROperand *arrayPtr, IROperand *tempPtr);

    // 创建标签的中间代码
    IROperand *createLabel();

    // 添加函数的中间代码
    IROperand *addIRFunc(FuncSymbol *funcSymbol);

    // 添加中间代码
    void addIntermediateCode(Type dataType, IROpCode opCode, IROperand *dst, IROperand *src1, IROperand *src2);

    // 记录中间代码到文件
    void logIrCode(std::ofstream &irCodeFile, int);

    // 优化中间代码
    std::vector<BasicBlock*>& optimize(std::ofstream &irCodeFile);

    // 优化等级O0
    std::vector<BasicBlock*>& O0();

    // 优化等级O1
    std::vector<BasicBlock*>& O1();

    // 获取优化后的中间代码
    std::vector<IntermediateCode*>& getOptIntermediateCode();
};