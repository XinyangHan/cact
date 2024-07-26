#pragma once // 防止头文件被重复包含
#include <set> // 引入std::set类型
#include <vector> // 引入std::vector类型
#include <map> // 引入std::map类型
#include <fstream> // 引入文件操作类型
#include "../analysis/type.h" // 包含type.h头文件

class IntermediateCode; // 声明IntermediateCode类
class IROperand; // 声明IROperand类
class BasicBlock; // 声明BasicBlock类
class IntermediateCodeGenerator; // 声明IntermediateCodeGenerator类

class LifetimeInfo { // LifetimeInfo类的定义
    public:
    bool liveness; // 活跃状态
    IntermediateCode *usedInfo; // 使用信息
    LifetimeInfo *arrayInfo; // 数组信息
    LifetimeInfo *tempInfo; // 临时信息
        
    // 构造函数，初始化活跃状态和使用信息
    LifetimeInfo(bool liveness, IntermediateCode *usedInfo) {
        this->liveness = liveness;
        this->usedInfo = usedInfo;
    }
    // 构造函数，初始化数组信息和临时信息
    LifetimeInfo(LifetimeInfo *arrayInfo, LifetimeInfo *tempInfo) {
        this->arrayInfo = arrayInfo;
        this->tempInfo = tempInfo;
    }
};

class DagNode { // DagNode类的定义
    public:
    Type dataType; // 数据类型
    IROpCode opCode; // 操作码
    DagNode *lchild; // 左子节点
    DagNode *rchild; // 右子节点
    std::set<IROperand*> relatedSet; // 相关操作数集合
    BasicBlock *basicBlock; // 基本块
        
    DagNode() {} // 默认构造函数
    // 构造函数，初始化数据类型、操作码、左子节点和右子节点
    DagNode(Type dataType, IROpCode opCode, DagNode *lchild, DagNode *rchild) 
        : dataType(dataType), opCode(opCode), lchild(lchild), rchild(rchild) {}
    virtual IROperand *getIROperand() {} // 获取IROperand的虚函数
    virtual IntermediateCode *rebuildIR(std::vector<IntermediateCode*>&) {} // 重建中间代码的虚函数
    virtual void initElem() {} // 初始化代表元素的虚函数
};

class DagTermNode : public DagNode { // DagTermNode类，继承自DagNode
    public:
    IROperand *notTemp; // 非临时操作数
        
    DagTermNode(Type dataType) : DagNode(dataType, IROpCode::IR_UNKNOWN, nullptr, nullptr) {} // 构造函数，初始化数据类型
    IROperand *getIROperand() override; // 重写获取IROperand函数
};

class DagInnerNode : public DagNode { // DagInnerNode类，继承自DagNode
    public:
    IROperand *representElem = nullptr; // 代表元素
    bool isArray = false; // 是否为数组
    IROperand *label = nullptr; // 标签
        
    // 构造函数，初始化数据类型、操作码、左子节点和右子节点
    DagInnerNode(Type dataType, IROpCode opCode, DagNode *lchild, DagNode *rchild) 
        : DagNode(dataType, opCode, lchild, rchild) {}
    IROperand *getIROperand() override; // 重写获取IROperand函数
    void initElem(); // 初始化代表元素函数
    IntermediateCode *rebuildIR(std::vector<IntermediateCode*>&); // 重建中间代码函数
};

class DagOtherNode : public DagNode { // DagOtherNode类，继承自DagNode
    public:
    IntermediateCode *irCode; // 中间代码
        
    // 构造函数，初始化中间代码、操作码和基本块
    DagOtherNode(IntermediateCode *irCode, IROpCode opCode, BasicBlock *basicBlock) 
        : irCode(irCode) {
        this->opCode = opCode;
        this->basicBlock = basicBlock;
    }
    IntermediateCode *rebuildIR(std::vector<IntermediateCode*>&); // 重建中间代码函数
};

class BasicBlock { // BasicBlock类的定义
    public:
    std::vector<IntermediateCode*> partitionedIR; // 分区的中间代码
    std::vector<IntermediateCode*> rebuildIR; // 重建的中间代码
    std::map<IROperand*, DagNode*> operand2DagNode; // 操作数到DagNode的映射
    std::vector<DagNode*> dagNodeList; // DagNode列表
    std::map<IROperand*, LifetimeInfo*> livenessMap; // 操作数到生命周期信息的映射
        
    BasicBlock() {} // 默认构造函数
    void eliminateCommonSubexp(); // 公共子表达式消除
    void calculateLiveness(); // 计算活跃度
    DagNode *findDagNode(IROperand *src); // 查找操作数对应的DagNode
    LifetimeInfo *findLiveInfo(IROperand* operand); // 查找操作数对应的生命周期信息
};

class IROptimizer { // IROptimizer类的定义
    public:
    std::vector<BasicBlock*> basicBlockList; // 基本块列表
    std::map<IROperand*, BasicBlock*> label2Block; // 标签到基本块的映射
    std::vector<int> funcBeginSeq; // 函数开始序列
    std::vector<int> funcEndSeq; // 函数结束序列
    std::vector<IntermediateCode*> optIrCodeList; // 优化后的中间代码列表
    
    IROptimizer() {} // 默认构造函数
    void splitIntoBasicBlocks(std::vector<IntermediateCode*> &irCodeList); // 基本块分区
    void refineJumpInstructions(std::vector<IntermediateCode*> &irCodeList); // 跳转优化
    void executeConstantPropagation(IntermediateCodeGenerator*); // 常量传播优化
    void eliminateCommonSubexp(); // 公共子表达式消除
    void calculateLiveness(); // 计算活跃度
    void rebuildIR(); // 重建中间代码
    void printOptIntermediateCode(std::ofstream &irCodeFile); // 打印优化后的中间代码
    void printBlocks(); // 打印基本块
};