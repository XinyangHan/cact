#pragma once // 防止头文件被重复包含
#include "include/ir/operand.h" // 包含操作数的头文件
#include "optimizer.h" // 包含优化器的头文件
#include <any> // 引入std::any类型
class IntermediateInterpreter; // 声明IntermediateInterpreter类

class IntermediateCode { // IntermediateCode类的定义
    public:
    Type dataType; // 数据类型
    IROpCode opCode; // 中间表示操作码
    IROperand *dst; // 目标操作数指针
    IROperand *src1; // 源操作数1指针
    IROperand *src2; // 源操作数2指针
    LifetimeInfo* dstInfo; // 目标操作数的活跃信息
    LifetimeInfo* src1Info; // 源操作数1的活跃信息
    LifetimeInfo* src2Info; // 源操作数2的活跃信息
    IntermediateCode *nextIR; // 下一条中间代码
    std::vector<IntermediateCode*> pred; // 前驱中间代码列表
    std::vector<IntermediateCode*> succ; // 后继中间代码列表
    std::set<IntermediateCode*> reachIn; // 到达入口的中间代码集合
    std::set<IntermediateCode*> reachOut; // 到达出口的中间代码集合
    std::set<IntermediateCode*> src1Use; // 使用源操作数1的中间代码集合
    std::set<IntermediateCode*> src2Use; // 使用源操作数2的中间代码集合
    std::set<IntermediateCode*> def1; // 定义源操作数1的中间代码集合
    std::set<IntermediateCode*> def2; // 定义源操作数2的中间代码集合

    // 构造函数，初始化中间代码对象
    IntermediateCode(Type dataType, IROpCode opCode, IROperand *dst, IROperand *src1, IROperand *src2) 
        : dataType(dataType), opCode(opCode), dst(dst), src1(src1), src2(src2) {}

    // 打印中间代码到文件
    void print(std::ofstream &irCodeFile);

    // 创建DAG（有向无环图）
    void createDAG(BasicBlock *basicBlock);

    // 计算活跃度
    void calculateLiveness(BasicBlock *basicBlock);

    // 计算栈偏移量
    void calculateStackOffset(AssemblyCodeGenerator *AssemblyGenerator);

    // 生成汇编代码
    void generateAssembly(AssemblyCodeGenerator *AssemblyGenerator);

    // 定位主函数
    void locateMainFunction(IntermediateInterpreter *irInterpretor, IntermediateCode **entryPoint);

    // 解释执行中间代码
    IntermediateCode *interpretIntermediateCode(std::ofstream &interpretFile, IntermediateInterpreter *irInterpretor);
};