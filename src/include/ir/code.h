#pragma once
#include "include/ir/operand.h"
#include "optimizer.h"
#include <any>
class IRInterpretor;

class IRCode {
    public:
    Type dataType;
    IROpCode opCode;
    IROperand *dst;
    IROperand *src1;
    IROperand *src2;
    LiveInfo* dstInfo;
    LiveInfo* src1Info;
    LiveInfo* src2Info;
    IRCode    *nextIR;
    std::vector<IRCode*> pred;
    std::vector<IRCode*> succ;
    std::set<IRCode*> reachIn;
    std::set<IRCode*> reachOut;
    std::set<IRCode*> src1Use;
    std::set<IRCode*> src2Use;
    std::set<IRCode*> def1;
    std::set<IRCode*> def2;

    
    IRCode(Type dataType, IROpCode opCode, IROperand *dst, IROperand *src1, IROperand *src2) : dataType(dataType), opCode(opCode), dst(dst), src1(src1), src2(src2) {}
    void print(std::ofstream &irCodeFile);
    void generateDag(BasicBlock *basicBlock);
    void calLiveInfo(BasicBlock *basicBlock);
    void calStackDisplacement(AsmGenerator *asmGenerator);
    void genAsmCode(AsmGenerator *asmGenerator);
    void findMain(IRInterpretor *irInterpretor, IRCode **entryPoint);
    IRCode *interpretIRCode(std::ofstream &interpretFile, IRInterpretor *irInterpretor);
};