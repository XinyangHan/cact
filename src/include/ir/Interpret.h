#pragma once // 防止头文件被重复包含
#include "code.h" // 包含code.h头文件
#include <any> // 引入std::any类型

class IntermediateStack; // 声明IntermediateStack类
class FuncSymbol; // 声明FuncSymbol类

class InterpretOperand { // InterpretOperand类的定义
    public:
    int len; // 操作数长度
        
    InterpretOperand() {} // 构造函数
    virtual std::any getValue(int offset, int base) {} // 获取操作数值的虚函数
    virtual void setValue(std::any result, int offset, int base) {} // 设置操作数值的虚函数
};
    
class InterpretBool : public InterpretOperand { // InterpretBool类，继承自InterpretOperand
    public:
    std::vector<bool> value; // 布尔值向量
        
    InterpretBool(int len) {this->len = len;} // 构造函数，初始化长度
    InterpretBool(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<bool>(value));} // 构造函数，初始化长度和值
    std::any getValue(int offset, int base) override; // 重写获取值的函数
    void setValue(std::any result, int offset, int base) override; // 重写设置值的函数
};
    
class InterpretInt : public InterpretOperand { // InterpretInt类，继承自InterpretOperand
    public:
    std::vector<int> value; // 整数值向量
        
    InterpretInt(int len) {this->len = len;} // 构造函数，初始化长度
    InterpretInt(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<int>(value));} // 构造函数，初始化长度和值
    std::any getValue(int offset, int base) override; // 重写获取值的函数
    void setValue(std::any result, int offset, int base) override; // 重写设置值的函数
};
    
class InterpretFloat : public InterpretOperand { // InterpretFloat类，继承自InterpretOperand
    public:
    std::vector<float> value; // 浮点数值向量
        
    InterpretFloat(int len) {this->len = len;} // 构造函数，初始化长度
    InterpretFloat(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<float>(value));} // 构造函数，初始化长度和值
    std::any getValue(int offset, int base) override; // 重写获取值的函数
    void setValue(std::any result, int offset, int base) override; // 重写设置值的函数
};
    
class InterpretDouble : public InterpretOperand { // InterpretDouble类，继承自InterpretOperand
    public:
    std::vector<double> value; // 双精度浮点数值向量
        
    InterpretDouble(int len) {this->len = len;} // 构造函数，初始化长度
    InterpretDouble(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<double>(value));} // 构造函数，初始化长度和值
    std::any getValue(int offset, int base) override; // 重写获取值的函数
    void setValue(std::any result, int offset, int base) override; // 重写设置值的函数
};

class InterpretTemp : public InterpretOperand { // InterpretTemp类，继承自InterpretOperand
    public:
    std::any value; // 临时值
        
    InterpretTemp(std::any value) {this->value = value;} // 构造函数，初始化值
    std::any getValue(int offset, int base) override; // 重写获取值的函数
};

class InterpretImm : public InterpretOperand { // InterpretImm类，继承自InterpretOperand
    public:
    std::any value; // 立即数值
    
    InterpretImm(std::any value) {this->value = value;} // 构造函数，初始化值
    std::any getValue() {return value;} // 获取立即数值
};

class IntermediateStack { // IntermediateStack类的定义
    public:
    IntermediateStack *preStack; // 上一个栈帧指针
    IntermediateCode *nextIntermediateCode; // 下一条中间代码指针
    std::map<IROperand*, InterpretOperand*> interpretMap; // 操作数到解释操作数的映射
    std::map<IROperand*, int> baseMap; // 操作数到基址的映射
    std::vector<std::any> realParamList; // 实参列表
    InterpretOperand *calleeReturnVal; // 被调用者的返回值
    IntermediateCode *calleeReturnAddr = nullptr; // 被调用者的返回地址
        
    IntermediateStack(IntermediateStack *preStack) {this->preStack = preStack;} // 构造函数，初始化上一个栈帧指针
};

class IntermediateInterpreter { // IntermediateInterpreter类的定义
    public:
    IntermediateStack *currStack = nullptr; // 当前栈帧指针
    std::map<IROperand*, InterpretOperand*> globlMap; // 全局变量映射
    std::map<IROperand*, InterpretOperand*> immMap; // 立即数映射
    std::map<FuncSymbol*, IntermediateCode*> funcMap; // 函数符号到中间代码的映射
    std::map<IROperand*, IntermediateCode*> labelMap; // 标签到中间代码的映射
    
    // 解释执行中间代码
    void interpretIntermediateCode(std::ofstream &interpretFile, std::vector<IntermediateCode*> &irCodeList, std::map<std::string, IROperand*> &immediatePool);
    
    // 获取立即数值
    std::any fetchImmediateValue(IRImmediateValue* immediate);
};