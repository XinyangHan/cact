#pragma once // 防止头文件被重复包含
#include <string> // 引入std::string类型
#include <map> // 引入std::map类型
#include <fstream> // 引入文件操作类型
#include <vector> // 引入std::vector类型
#include <set> // 引入std::set类型

class IROperand; // 声明IROperand类
class BasicBlock; // 声明BasicBlock类

class AddrDescriptor { // AddrDescriptor类的定义
    public:
    bool inMem; // 是否在内存中
    bool isArg = false; // 是否为参数
    std::vector<std::string> atReg; // 寄存器列表
        
    AddrDescriptor(bool inMem) {this->inMem = inMem;} // 构造函数，初始化是否在内存中
};

class RegDescriptor { // RegDescriptor类的定义
    public:
    std::string regName; // 寄存器名称
    std::set<IROperand*> ops; // 操作数集合
        
    RegDescriptor(std::string regName) {this->regName = regName;} // 构造函数，初始化寄存器名称
};

class AssemblyCodeGenerator { // AssemblyCodeGenerator类的定义
    public:
    std::vector<std::string> generalRegList = {"s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", \
                                           "t0", "t1", "t2", "t3", "t4", "t5", "t6"}; // 通用寄存器列表
    std::vector<std::string> fpRegs = {"ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7"}; // 浮点寄存器列表
    std::vector<std::string> asmCodeList; // 汇编代码列表
    std::vector<std::string> asmDataList; // 汇编数据列表
    std::vector<IROperand*> paramList; // 参数列表
    std::map<std::string, RegDescriptor*> regDescriptorMap; // 寄存器描述符映射
    std::map<IROperand*, AddrDescriptor*> addrDescriptorMap; // 地址描述符映射
    int stackFrame; // 栈帧
    int paramCount; // 参数数量
    int calleeParamNum = 0; // 被调用者参数数量
    int stackSize; // 栈大小
    bool regConfig = false; // 寄存器配置状态
    std::string configReg; // 配置的寄存器
    int opt; // 优化选项
    
    AssemblyCodeGenerator() {} // 默认构造函数

    // 执行汇编代码生成
    void executeAssemblyGene(std::ofstream &asmFile, std::vector<BasicBlock*> &basicBlockList);  
    // 初始化寄存器描述符
    void initRegDescriptor();
    // 获取寄存器
    std::string getReg(bool fP);
    // 查找地址描述符映射
    AddrDescriptor *searchAddrDescriptorMap(IROperand *operand);
    // 向上取整
    int roundUp(int frameSize, int alignSize);
    // 打印汇编代码
    void printAssemblycode(std::ofstream &irCodeFile);
};