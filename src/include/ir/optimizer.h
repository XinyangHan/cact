#pragma once
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include "../analysis/type.h"
class IRCode;
class IROperand;
class BasicBlock;
class IRGenerator;

class LiveInfo {
    public:
    bool liveness;
    IRCode *usedInfo;
    LiveInfo *arrayInfo;
    LiveInfo *tempInfo;
        
    LiveInfo(bool liveness, IRCode *usedInfo) {this->liveness = liveness; this->usedInfo = usedInfo;}
    LiveInfo(LiveInfo *arrayInfo, LiveInfo *tempInfo) {this->arrayInfo = arrayInfo; this->tempInfo = tempInfo;}
};

class DagNode {
    public:
    Type dataType;
    IROpCode opCode;
    DagNode *lchild;
    DagNode *rchild;
    std::set<IROperand*> relatedSet;
    BasicBlock *basicBlock;
        
    DagNode() {}
    DagNode(Type dataType, IROpCode opCode, DagNode *lchild, DagNode *rchild) : dataType(dataType), opCode(opCode), lchild(lchild), rchild(rchild) {}
    virtual IROperand *getIROperand() {}
    virtual IRCode *irRebuild(std::vector<IRCode*>&) {}
    virtual void initRepresentElem() {}
};

class DagTerminalNode : public DagNode {
    public:
    IROperand *notTemp;
        
    DagTerminalNode(Type dataType) : DagNode(dataType, IROpCode::IR_UNKNOWN, nullptr, nullptr) {}
    IROperand *getIROperand() override;
};

class DagInnerNode : public DagNode {
    public:
    IROperand *representElem = nullptr;
    bool isArray  = false;
    IROperand *label = nullptr;
       
    DagInnerNode(Type dataType, IROpCode opCode, DagNode *lchild, DagNode *rchild) : DagNode(dataType, opCode, lchild, rchild) {}
    IROperand *getIROperand() override;
    void initRepresentElem();
    IRCode *irRebuild(std::vector<IRCode*>&);
};

class DagOtherNode : public DagNode {
    public:
    IRCode *irCode;
        
    DagOtherNode(IRCode *irCode, IROpCode opCode, BasicBlock *basicBlock) : irCode(irCode) {this->opCode = opCode; this->basicBlock = basicBlock;}
    IRCode *irRebuild(std::vector<IRCode*>&);
};

class BasicBlock {
    public:
    std::vector<IRCode*> partitionedIR;
    std::vector<IRCode*> rebuildIR;
    std::map<IROperand*, DagNode*> operand2DagNode;
    std::vector<DagNode*> dagNodeList;
    std::map<IROperand*, LiveInfo*> livenessMap;
        
    BasicBlock() {}
    void commonSubexpssionEliminate();
    void calLiveInfo();
    DagNode *searchOperand2DagNode(IROperand *src);
    LiveInfo *searchLivenessMap(IROperand* operand);
};

class IROptimizer {
    public:
    std::vector<BasicBlock*> basicBlockList;
    std::map<IROperand*, BasicBlock*> label2Block;
    std::vector<int> funcBeginSeq;
    std::vector<int> funcEndSeq;
    std::vector<IRCode*> optIrCodeList;
    
    IROptimizer() {}
    void basicBlockPartition(std::vector<IRCode*> &irCodeList);
    void jumpPass(std::vector<IRCode*> &irCodeList);
    void constPass(IRGenerator*);
    void commonSubexpssionEliminate();
    void calLiveInfo();
    void irRebuild();
    void printOptIRCode(std::ofstream &irCodeFile);
    void printBasicBlock();
};