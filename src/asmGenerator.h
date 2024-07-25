#pragma once
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <set>
class IROperand;
class BasicBlock;

class AddrDescriptor {
    public:
    bool atMemory;
    bool isArg = false;
    std::vector<std::string> atReg;
        
    AddrDescriptor(bool atMemory) {this->atMemory = atMemory;}
};

class RegDescriptor {
    public:
    std::string regName;
    std::set<IROperand*> operandList;
        
    RegDescriptor(std::string regName) {this->regName = regName;}  
};                            
                                    
class AsmGenerator {
    public:
    std::vector<std::string> generalRegList = {"s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", \
                                           "t0", "t1", "t2", "t3", "t4", "t5", "t6"};
    std::vector<std::string> fpRegList = {"ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7"};
    std::vector<std::string> asmCodeList;
    std::vector<std::string> asmDataList;
    std::vector<IROperand*> paramList;
    std::map<std::string, RegDescriptor*> regDescriptorMap;
    std::map<IROperand*, AddrDescriptor*> addrDescriptorMap;
    int stackFrame;
    int paramNum;
    int calleeParamNum = 0;
    int stackSize;
    bool regConfig = false;
    std::string configReg;
    int opt;
    
    AsmGenerator() {}
    void invokeAsmGene(std::ofstream &asmCodeFile, std::vector<BasicBlock*> &basicBlockList);  
    void initRegDescriptor();
    std::string getReg(bool fP);
    AddrDescriptor *searchAddrDescriptorMap(IROperand *operand);
    int roundUp(int frameSize, int alignSize);
    void printAsmcode(std::ofstream &irCodeFile);
};