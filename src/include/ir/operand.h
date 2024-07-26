#pragma once // 防止头文件被重复包含
#include <vector> // 引入std::vector类型
#include <string> // 引入std::string类型
#include <fstream> // 引入文件操作类型
#include <map> // 引入std::map类型
#include "../analysis/type.h" // 包含type.h头文件
#include <map> // 重复引入std::map类型
#include "../asm/rvGen.h" // 包含rvGen.h头文件

class LifetimeInfo; // 声明LifetimeInfo类
class IntermediateCode; // 声明IntermediateCode类
class FuncSymbol; // 声明FuncSymbol类

class IROperand { // IROperand类的定义
    public:
    bool zero = false; // 是否为零
    Type opDataType; // 操作数的数据类型
    std::set<IntermediateCode*> def; // 定义此操作数的中间代码集合
    
    virtual IROperand *getSrc() {return this;} // 获取源操作数，默认为自身
    virtual IROperand *getDisplace() {return nullptr;} // 获取位移操作数，默认为空
    virtual std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {} // 转换为寄存器
    virtual void argReg(AssemblyCodeGenerator *AssemblyGenerator, int num, std::string srcReg); // 转换为参数寄存器
    virtual void assignReg(AssemblyCodeGenerator *AssemblyGenerator, int num) {} // 转换为分配寄存器
    virtual void toMem(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo, std::string srcReg) {}; // 转换为内存
    virtual void logIR(std::ofstream &irCodeFile) = 0; // 打印中间代码
    virtual LifetimeInfo *setLifetimeInfo(BasicBlock *basicBlock); // 设置生命周期信息
    virtual void calculateLiveness(BasicBlock *basicBlock, bool liveness, IntermediateCode *usedInfo); // 计算活跃度
};

class IRVar { // IRVar类的定义
    public:
    Type dataType; // 数据类型
    int len; // 长度
    int name; // 名称
    
    IRVar(Type dataType, int len) : dataType(dataType), len(len) {} // 构造函数
};

class IrGlobalVariable : public IRVar, public IROperand { // IrGlobalVariable类，继承自IRVar和IROperand
    public:
    static int globlVarNum; // 全局变量计数
    std::vector<IROperand*> initVal; // 初始化值向量
    bool alloc = false; // 是否已分配

    IrGlobalVariable(Type dataType, int len, std::vector<IROperand*> &initVal) : IRVar(dataType, len), initVal(initVal) {opDataType = dataType;} // 构造函数，初始化数据类型和初始化值
    virtual void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数
};

class IRGloblScalar : public IrGlobalVariable { // IRGloblScalar类，继承自IrGlobalVariable
    public:
    IRGloblScalar(Type dataType, std::vector<IROperand*> &initVal) : IrGlobalVariable(dataType, 1, initVal) {name = globlVarNum++;} // 构造函数，初始化数据类型和初始化值

    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
    std::string toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为整数寄存器
    std::string toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为浮点寄存器
    std::string toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为双精度寄存器
    void toMem(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo, std::string srcReg) override; // 重写转换为内存函数
};

class IRGloblArray : public IrGlobalVariable { // IRGloblArray类，继承自IrGlobalVariable
    public:
    IRGloblArray(Type dataType, int len, std::vector<IROperand*> &initVal) : IrGlobalVariable(dataType, len, initVal) {name = globlVarNum++;} // 构造函数，初始化数据类型、长度和初始化值

    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
};

class IRLocalVar : public IRVar, public IROperand { // IRLocalVar类，继承自IRVar和IROperand
    public:
    static int localVarNum; // 局部变量计数
    std::vector<IROperand*> initVal; // 初始化值向量
    bool alloc = false; // 是否已分配
    int offset; // 位移

    IRLocalVar(Type dataType, int len, std::vector<IROperand*> &initVal) : IRVar(dataType, len), initVal(initVal) {opDataType = dataType;} // 构造函数，初始化数据类型、长度和初始化值
    virtual void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数
};

class IRLocalScalar : public IRLocalVar { // IRLocalScalar类，继承自IRLocalVar
    public:
    IRLocalScalar(Type dataType, std::vector<IROperand*> &initVal) : IRLocalVar(dataType, 1, initVal) {name = localVarNum++;} // 构造函数，初始化数据类型和初始化值

    void assignReg(AssemblyCodeGenerator *AssemblyGenerator, int num) override; // 重写转换为分配寄存器函数
    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
    std::string toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为整数寄存器
    std::string toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为浮点寄存器
    std::string toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为双精度寄存器
    void toMem(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo, std::string srcReg) override; // 重写转换为内存函数
};

class IRLocalArray : public IRLocalVar { // IRLocalArray类，继承自IRLocalVar
    public:
    IRLocalArray(Type dataType, int len, std::vector<IROperand*> &initVal) : IRLocalVar(dataType, len, initVal) {name = localVarNum++;} // 构造函数，初始化数据类型、长度和初始化值

    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
};

class IRImmediateValue : public IRVar, public IROperand { // IRImmediateValue类，继承自IRVar和IROperand
    public:
    static int immediateNum; // 立即数计数
    std::string val; // 值

    IRImmediateValue(Type dataType, std::string val) : IRVar(dataType, 1), val(val) {name = immediateNum++; opDataType = dataType;} // 构造函数，初始化数据类型和值
    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
    std::string toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为整数寄存器
    std::string toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为浮点寄存器
    std::string toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为双精度寄存器
    void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数
};

class TemporaryValue : public IRVar, public IROperand { // TemporaryValue类，继承自IRVar和IROperand
    public:
    static int tempNum; // 临时变量计数
    int offset; // 位移

    TemporaryValue(Type dataType) : IRVar(dataType, 1) {name = tempNum++; opDataType = dataType;} // 构造函数，初始化数据类型
    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
    std::string toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为整数寄存器
    std::string toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为浮点寄存器
    void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数
};

class IRArrayElem : public IROperand { // IRArrayElem类，继承自IROperand
    public:
    IROperand *arrayPtr; // 数组指针
    IROperand *tempPtr; // 临时指针

    IRArrayElem(IROperand *arrayPtr, IROperand *tempPtr) : arrayPtr(arrayPtr), tempPtr(tempPtr) {} // 构造函数，初始化数组指针和临时指针
    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
    std::string toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为整数寄存器
    std::string toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为浮点寄存器
    std::string toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo); // 转换为双精度寄存器
    void toMem(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo, std::string srcReg) override; // 重写转换为内存函数
    void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数
    LifetimeInfo *setLifetimeInfo(BasicBlock *basicBlock) override; // 重写设置生命周期信息函数
    void calculateLiveness(BasicBlock *basicBlock, bool liveness, IntermediateCode *usedInfo) override; // 重写计算活跃度函数
    IROperand *getSrc() override; // 重写获取源操作数函数
    IROperand *getDisplace() override; // 重写获取位移操作数函数
};

class IRArrayAddr : public IROperand { // IRArrayAddr类，继承自IROperand
    public:
    IROperand *arrayPtr; // 数组指针
    IROperand *tempPtr; // 临时指针
    IRArrayAddr(IROperand *arrayPtr, IROperand *tempPtr) : arrayPtr(arrayPtr), tempPtr(tempPtr) {} // 构造函数，初始化数组指针和临时指针
    std::string toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) override; // 重写转换为寄存器函数
    void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数

    LifetimeInfo *setLifetimeInfo(BasicBlock *basicBlock) override; // 重写设置生命周期信息函数
    void calculateLiveness(BasicBlock *basicBlock, bool liveness, IntermediateCode *usedInfo) override; // 重写计算活跃度函数
    IROperand *getSrc() override; // 重写获取源操作数函数
    IROperand *getDisplace() override; // 重写获取位移操作数函数
};

class IRLabel : public IROperand { // IRLabel类，继承自IROperand
    public:
    static int labelNum; // 标签计数
    int name; // 名称
    IRLabel() {name = labelNum++;} // 构造函数，初始化名称
    void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数
};

class IRFunc : public IROperand { // IRFunc类，继承自IROperand
    public:
    int stackSize; // 栈大小
    FuncSymbol *funcSymbol; // 函数符号
    IRFunc(FuncSymbol *funcSymbol) : funcSymbol(funcSymbol) {} // 构造函数，初始化函数符号
    void logIR(std::ofstream &irCodeFile) override; // 重写打印中间代码函数
}; 
