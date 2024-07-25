#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "type.h"
#include <map>
#include "asmGenerator.h"
class LiveInfo;
class IRCode;

class FuncSymbol;

class IROperand {
    public:
    bool zero = false;
    Type opDataType;
    std::set<IRCode*> def;
    
    virtual IROperand *getSrc() {return this;}
    virtual IROperand *getDisplace() {return nullptr;}
    virtual std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {}
    virtual void toArgReg(AsmGenerator *asmGenerator, int num, std::string srcReg);
    virtual void toAssignReg(AsmGenerator *asmGenerator, int num) {}  
    virtual void toMem(AsmGenerator *asmGenerator, LiveInfo *liveInfo, std::string srcReg) {};
    virtual void printIR(std::ofstream &irCodeFile) = 0;
    virtual LiveInfo *setLiveInfo(BasicBlock *basicBlock);
    virtual void calLiveInfo(BasicBlock *basicBlock, bool liveness, IRCode *usedInfo);
};

class IRVar {
    public:
    Type dataType;
    int len;
    int name;
    
    IRVar(Type dataType, int len) : dataType(dataType), len(len) {}
};

class IRGloblVar : public IRVar, public IROperand {
    public:
    static int globlVarNum;
    std::vector<IROperand*> initVal;
    bool alloc = false;

    IRGloblVar(Type dataType, int len, std::vector<IROperand*> &initVal) : IRVar(dataType, len), initVal(initVal) {opDataType = dataType;}
    virtual void printIR(std::ofstream &irCodeFile) override;
};

class IRGloblScalar : public IRGloblVar {
    public:
    IRGloblScalar(Type dataType, std::vector<IROperand*> &initVal) : IRGloblVar(dataType, 1, initVal) {name = globlVarNum++;}

    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;
    std::string toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    void toMem(AsmGenerator *asmGenerator, LiveInfo *liveInfo, std::string srcReg) override;
};

class IRGloblArray : public IRGloblVar {
    public:
    IRGloblArray(Type dataType, int len, std::vector<IROperand*> &initVal) : IRGloblVar(dataType, len, initVal) {name = globlVarNum++;}

    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;
};

class IRLocalVar : public IRVar, public IROperand {
    public:
    static int localVarNum;
    std::vector<IROperand*> initVal;
    bool alloc = false;
    int displacement;

    IRLocalVar(Type dataType, int len, std::vector<IROperand*> &initVal) : IRVar(dataType, len), initVal(initVal) {opDataType = dataType;}
    virtual void printIR(std::ofstream &irCodeFile) override;
};

class IRLocalScalar : public IRLocalVar {
    public:
    IRLocalScalar(Type dataType, std::vector<IROperand*> &initVal) : IRLocalVar(dataType, 1, initVal) {name = localVarNum++;}

    void toAssignReg(AsmGenerator *asmGenerator, int num) override;
    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;
    std::string toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    void toMem(AsmGenerator *asmGenerator, LiveInfo *liveInfo, std::string srcReg) override;
};

class IRLocalArray : public IRLocalVar {
    public:
    IRLocalArray(Type dataType, int len, std::vector<IROperand*> &initVal) : IRLocalVar(dataType, len, initVal) {name = localVarNum++;}

    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;
};

class IRImmediate : public IRVar, public IROperand {
    public:
    static int immediateNum;
    std::string val;

    IRImmediate(Type dataType, std::string val) : IRVar(dataType, 1), val(val) {name = immediateNum++; opDataType = dataType;}
    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;
    std::string toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    void printIR(std::ofstream &irCodeFile) override;
};

class IRTemp : public IRVar, public IROperand {
    public:
    static int tempNum;
    int displacement;

    IRTemp(Type dataType) : IRVar(dataType, 1) {name = tempNum++; opDataType = dataType;}
    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;
    std::string toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    void printIR(std::ofstream &irCodeFile) override;
};

class IRArrayElem : public IROperand {
    public:
    IROperand *arrayPtr;
    IROperand *tempPtr;

    IRArrayElem(IROperand *arrayPtr, IROperand *tempPtr) : arrayPtr(arrayPtr), tempPtr(tempPtr) {}
    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;  
    std::string toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    std::string toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo);
    void toMem(AsmGenerator *asmGenerator, LiveInfo *liveInfo, std::string srcReg) override;
    void printIR(std::ofstream &irCodeFile) override;
    LiveInfo *setLiveInfo(BasicBlock *basicBlock) override;
    void calLiveInfo(BasicBlock *basicBlock, bool liveness, IRCode *usedInfo) override;
    IROperand *getSrc() override;
    IROperand *getDisplace() override;
};

class IRArrayAddr : public IROperand {
    public:
    IROperand *arrayPtr;
    IROperand *tempPtr;
    IRArrayAddr(IROperand *arrayPtr, IROperand *tempPtr) : arrayPtr(arrayPtr), tempPtr(tempPtr) {}
    std::string toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) override;
    void printIR(std::ofstream &irCodeFile) override;

    LiveInfo *setLiveInfo(BasicBlock *basicBlock) override;
    void calLiveInfo(BasicBlock *basicBlock, bool liveness, IRCode *usedInfo) override;
    IROperand *getSrc() override;
    IROperand *getDisplace() override;
};

class IRLabel : public IROperand {
    public:
    static int labelNum;
    int name;
    IRLabel() {name = labelNum++;}
    void printIR(std::ofstream &irCodeFile) override;
};

class IRFunc : public IROperand {
    public:
    int stackSize;
    FuncSymbol *funcSymbol;
    IRFunc(FuncSymbol *funcSymbol) : funcSymbol(funcSymbol) {}
    void printIR(std::ofstream &irCodeFile) override;
}; 

