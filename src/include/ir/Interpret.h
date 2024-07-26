#pragma once
#include "code.h"
#include <any>
class IRStack;
class FuncSymbol;

class InterpretOperand {
    public:
    int len;
        
    InterpretOperand() {}
    virtual std::any getValue(int displacement, int base) {}
    virtual void setValue(std::any result, int displacement, int base) {}
};
    
class InterpretBool : public InterpretOperand {
    public:
    std::vector<bool> value;
        
    InterpretBool(int len) {this->len = len;}
    InterpretBool(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<bool>(value));}
    std::any getValue(int displacement, int base) override;
    void setValue(std::any result, int displacement, int base) override;
};
    
class InterpretInt : public InterpretOperand {
    public:
    std::vector<int> value;
        
    InterpretInt(int len) {this->len = len;}
    InterpretInt(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<int>(value));}
    std::any getValue(int displacement, int base) override;
    void setValue(std::any result, int displacement, int base) override;
};
    
class InterpretFloat : public InterpretOperand {
    public:
    std::vector<float> value;
        
    InterpretFloat(int len) {this->len = len;}
    InterpretFloat(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<float>(value));}
    std::any getValue(int displacement, int base) override;
    void setValue(std::any result, int displacement, int base) override;
};
    
class InterpretDouble : public InterpretOperand {
    public:
    std::vector<double> value;
        
    InterpretDouble(int len) {this->len = len;}
    InterpretDouble(int len, std::any value) {this->len = len; this->value.push_back(std::any_cast<double>(value));}
    std::any getValue(int displacement, int base) override;
    void setValue(std::any result, int displacement, int base) override;
};

class InterpretTemp : public InterpretOperand {
    public:
    std::any value;
        
    InterpretTemp(std::any value) {this->value = value;}
    std::any getValue(int displacement, int base) override;
};

class InterpretImm : public InterpretOperand {
    public:
    std::any value;
    
    InterpretImm(std::any value) {this->value = value;}
    std::any getValue() {return value;}
};

class IRStack {
        public:
        IRStack *preStack;
        IRCode  *nextIRCode;
        std::map<IROperand*, InterpretOperand*> interpretMap;
        std::map<IROperand*, int> baseMap;
        std::vector<std::any> realParamList;
        InterpretOperand *calleeReturnVal;
        IRCode *calleeReturnAddr = nullptr;
        
        IRStack(IRStack *preStack) {this->preStack = preStack;}
};

class IRInterpretor {
    public:
    IRStack *currStack = nullptr;
    std::map<IROperand*, InterpretOperand*> globlMap;
    std::map<IROperand*, InterpretOperand*> immMap;
    std::map<FuncSymbol*, IRCode*> funcMap;
    std::map<IROperand*, IRCode*> labelMap;
    
    void interpretIRCode(std::ofstream &interpretFile, std::vector<IRCode*> &irCodeList, std::map<std::string, IROperand*> &immediatePool);
    std::any getImmediateVal(IRImmediate* immediate);
};