#include "include/ir/optimizer.h"
#include "include/ir/code.h"
#include <cassert>
#include "include/ir/generator.h"

// 将中间代码分割成基本块
void IROptimizer::splitIntoBasicBlocks(std::vector<IntermediateCode*> &irCodeList) {
    int basicBlockSeq = -1;
    bool blockEnd = false;
    //basicBlockList.push_back(new BasicBlock());
    
    for (auto irCode : irCodeList) {
        switch (irCode->opCode) {
            case IR_FUNC_START:
                basicBlockSeq++;
                basicBlockList.push_back(new BasicBlock());
                basicBlockList[basicBlockSeq]->partitionedIR.push_back(irCode);
                blockEnd = false;
                funcBeginSeq.push_back(basicBlockSeq);
                break;
            case IR_LABEL:
                basicBlockSeq++;
                basicBlockList.push_back(new BasicBlock());
                basicBlockList[basicBlockSeq]->partitionedIR.push_back(irCode);
                blockEnd = false;
                label2Block[irCode->dst] = basicBlockList[basicBlockSeq];
                break;
            case IR_GOTO: case IR_BLT: case IR_BLE: case IR_BGT:
            case IR_BGE: case IR_BEQ: case IR_BNE: //case IR_RETURN:
                if (blockEnd) {
                    basicBlockSeq++;
                    basicBlockList.push_back(new BasicBlock());
                }
                basicBlockList[basicBlockSeq]->partitionedIR.push_back(irCode);
                blockEnd = true;
                break;
            default:
                if (blockEnd) {
                    basicBlockSeq++;
                    basicBlockList.push_back(new BasicBlock());
                }
                if (basicBlockSeq == -1) {
                    basicBlockSeq++;
                    basicBlockList.push_back(new BasicBlock());
                }
                basicBlockList[basicBlockSeq]->partitionedIR.push_back(irCode);
                blockEnd = false;

                switch(irCode->opCode) {
                    case IR_ASSIGN: case IR_NEG: case IR_NOT:
                    case IR_ADD: case IR_SUB: case IR_MUL:
                    case IR_DIV: case IR_MOD: case IR_L_ALLOC:
                        irCode->dst->def.insert(irCode);
                        break;
                    case IR_FUNC_END:
                        funcEndSeq.push_back(basicBlockSeq);
                        break;
                }
                break;
        }
    }

    for (int i = 0; i < basicBlockList.size(); i++){
        auto block = basicBlockList[i];
        IntermediateCode *lastIR = block->partitionedIR[block->partitionedIR.size()-1];
        switch (lastIR->opCode) {
            case IR_GOTO:
                assert(label2Block[lastIR->dst]->partitionedIR.size()>0);
                lastIR->succ.push_back(label2Block[lastIR->dst]->partitionedIR[0]);
                label2Block[lastIR->dst]->partitionedIR[0]->pred.push_back(lastIR);
                break;
            case IR_BLT: case IR_BLE: case IR_BGT:
            case IR_BGE: case IR_BEQ: case IR_BNE:
                assert(label2Block[lastIR->dst]->partitionedIR.size()>0);
                lastIR->succ.push_back(label2Block[lastIR->dst]->partitionedIR[0]);
                label2Block[lastIR->dst]->partitionedIR[0]->pred.push_back(lastIR);
                lastIR->succ.push_back(basicBlockList[i+1]->partitionedIR[0]);
                basicBlockList[i+1]->partitionedIR[0]->pred.push_back(lastIR);
                break;
            case IR_FUNC_END:
                break;
            default:
                lastIR->succ.push_back(basicBlockList[i+1]->partitionedIR[0]);
                basicBlockList[i+1]->partitionedIR[0]->pred.push_back(lastIR);
                break;
        }
    }
}

// 消除基本块中的公共子表达式
void IROptimizer::eliminateCommonSubexp() {
    for (auto basicBlock : basicBlockList) {
        basicBlock->eliminateCommonSubexp();
    }
}

// 计算基本块中的变量活跃度
void IROptimizer::calculateLiveness() {
    for (auto basicBlock : basicBlockList) {
        basicBlock->calculateLiveness();
    }
}

// 重建中间代码列表
void IROptimizer::rebuildIR() {
    for (auto basicBlock : basicBlockList) {
        for (auto rebuidIR : basicBlock->rebuildIR) {
            optIrCodeList.push_back(rebuidIR);
        }
    }
}

// 消除当前基本块中的公共子表达式
void BasicBlock::eliminateCommonSubexp() {
    for (auto irCode : partitionedIR) {
        irCode->createDAG(this);
    }
    for (auto dagNode : dagNodeList) {
        dagNode->initElem();
    }

    for (int i = 0; i < dagNodeList.size(); i++) {
        IntermediateCode *irCode = dagNodeList[i]->rebuildIR(rebuildIR);
        if (irCode != nullptr)
            rebuildIR.push_back(irCode);
    }

}

// 计算当前基本块中的变量活跃度
void BasicBlock::calculateLiveness() {
    for (int i = rebuildIR.size()-1; i >= 0; i--) {
        rebuildIR[i]->calculateLiveness(this);
    }
}

// 查找或创建操作数对应的DAG节点
DagNode *BasicBlock::findDagNode(IROperand *src) {
    auto it = this->operand2DagNode.find(src);
    if (it == this->operand2DagNode.end()) {
        DagNode *newDagNode = new DagTermNode(reinterpret_cast<IRVar*>(src)->dataType);
        newDagNode->basicBlock = this;
        operand2DagNode[src] = newDagNode;
        reinterpret_cast<DagTermNode*>(newDagNode)->notTemp = src;
        newDagNode->relatedSet.insert(src);
        return newDagNode;
    }
    else {
        return it->second;
    }
}

// 查找或创建操作数的生命周期信息
LifetimeInfo *BasicBlock::findLiveInfo(IROperand* operand) {
    LifetimeInfo *newLifetimeInfo;
    auto it = livenessMap.find(operand);
    if (it == livenessMap.end()) {
        if (dynamic_cast<TemporaryValue*>(operand) != nullptr) {
            newLifetimeInfo = new LifetimeInfo(false, nullptr);
            livenessMap[operand] = newLifetimeInfo;
        }
        else {
            newLifetimeInfo = new LifetimeInfo(true, nullptr);
            livenessMap[operand] = newLifetimeInfo;
        }
        return newLifetimeInfo;
    }
    else {
        return it->second;
    }
}

// 获取终端DAG节点的操作数
IROperand *DagTermNode::getIROperand() {
    if (dynamic_cast<IRArrayElem*>(notTemp) != nullptr) {
        DagNode *dagNode = basicBlock->findDagNode(reinterpret_cast<IRArrayElem*>(notTemp)->tempPtr);
        return new IRArrayElem(reinterpret_cast<IRArrayElem*>(notTemp)->arrayPtr, dagNode->getIROperand());
    }
    else if (dynamic_cast<IRArrayAddr*>(notTemp) != nullptr) {
        DagNode *dagNode = basicBlock->findDagNode(reinterpret_cast<IRArrayAddr*>(notTemp)->tempPtr);
        return new IRArrayAddr(reinterpret_cast<IRArrayAddr*>(notTemp)->arrayPtr, dagNode->getIROperand());
    }
    else {
        return notTemp;
    }
}

// 获取内部DAG节点的操作数
IROperand *DagInnerNode::getIROperand() {
    if (isArray) {
        auto it = relatedSet.begin();
        DagNode *dagNode = basicBlock->findDagNode(reinterpret_cast<IRArrayElem*>(*it)->tempPtr);
        return new IRArrayElem(reinterpret_cast<IRArrayElem*>(*it)->arrayPtr, dagNode->getIROperand());
    }
    else {
        return representElem;
    }
}

// 初始化内部DAG节点的代表元素
void DagInnerNode::initElem() {
    if (!isArray) {
        if (label != nullptr) {
            representElem = label;
            return ;
        }
        representElem = new TemporaryValue(dataType);
    }
}

// 重建内部DAG节点的中间代码
IntermediateCode *DagInnerNode::rebuildIR(std::vector<IntermediateCode*>& rebuildIR) {
    IROperand *src1 = lchild->getIROperand();
    IROperand *src2 = nullptr;
    if (rchild != nullptr) {
        src2 = rchild->getIROperand();
    }

    rebuildIR.push_back(new IntermediateCode(dataType, opCode, getIROperand(), src1, src2));

    if (!reinterpret_cast<DagInnerNode*>(this)->isArray) {
        auto it = this->relatedSet.begin();
        if (dynamic_cast<TemporaryValue*>(*it) == nullptr) {
            for (auto related : this->relatedSet) {
                rebuildIR.push_back(new IntermediateCode(this->dataType, IR_ASSIGN, related, this->getIROperand(), nullptr));
            }
        }
    }

    return nullptr;
}

// 重建其他DAG节点的中间代码
IntermediateCode *DagOtherNode::rebuildIR(std::vector<IntermediateCode*>& rebuildIR) {
    if (opCode != IR_PARAM && opCode != IR_RETURN) {
        return irCode;
    }
    else {
        if (irCode->dst != nullptr) {
            DagNode *dagNode = basicBlock->findDagNode(irCode->dst);
            //rebuildIR.push_back(new IntermediateCode(irCode->dataType, irCode->opCode, dagNode->getIROperand(), nullptr, nullptr));
            return new IntermediateCode(irCode->dataType, irCode->opCode, dagNode->getIROperand(), nullptr, nullptr);
        }
        else {
            //rebuildIR.push_back(new IntermediateCode(irCode->dataType, irCode->opCode, nullptr, nullptr, nullptr));
            return new IntermediateCode(irCode->dataType, irCode->opCode, nullptr, nullptr, nullptr);
        }
    }
}

// 打印优化后的中间代码
void IROptimizer::printOptIntermediateCode(std::ofstream &irCodeFile) {
    for (auto const & irCode : optIrCodeList) {
        irCode->print(irCodeFile);
    }
}

// 打印基本块信息
void IROptimizer::printBlocks() {
    std::ofstream debug;
    debug.open("./basicBlock.txt");
    for (auto basicBlock : basicBlockList) {
        for (auto irCode : basicBlock->partitionedIR) {
            irCode->print(debug);
        }
        debug << std::endl << std::endl;
    }
    debug.close();
}

// 将前驱节点的出口集合添加到当前节点的入口集合
void addReachOut(std::set<IntermediateCode*> &in, std::set<IntermediateCode*> &predOut) {
    for (auto irCode : predOut)
        in.insert(irCode);
}

// 更新活跃度信息，处理杀死和生成的中间代码
bool updateLivenessInfo(std::set<IntermediateCode*> &in, std::set<IntermediateCode*> &out, std::set<IntermediateCode*> &kill, IntermediateCode *self) {
    std::set<IntermediateCode*> tmp;
    for (auto irCode : out)
        tmp.insert(irCode);

    for (auto irCode : in)
        out.insert(irCode);
    for (auto irCode : kill)
        out.erase(irCode);
    out.insert(self);

    if (tmp.size() == out.size()) {
        for (auto irCode : tmp)
            if (out.find(irCode) == out.end())
                return true;
        return false;
    }
    return true;
}

// 执行常量传播优化
void IROptimizer::executeConstantPropagation(IntermediateCodeGenerator *irGenerator) {
    for (int i = 0; i < funcBeginSeq.size(); i++) {
        bool flag = false;

        //求到达定值
        do {
        flag = false;
        for (int j = funcBeginSeq[i]; j <= funcEndSeq[i]; j++) {
            for (int k = 0; k < basicBlockList[j]->partitionedIR.size(); k++) {

                if (basicBlockList[j]->partitionedIR[k]->pred.size() == 0) {
                    if (k != 0) 
                        addReachOut(basicBlockList[j]->partitionedIR[k]->reachIn, basicBlockList[j]->partitionedIR[k-1]->reachOut);
                }
                else {
                    for (auto irCode : basicBlockList[j]->partitionedIR[k]->pred) 
                        addReachOut(basicBlockList[j]->partitionedIR[k]->reachIn, irCode->reachOut);
                }

                switch(basicBlockList[j]->partitionedIR[k]->opCode) {
                    case IR_ASSIGN: case IR_NEG: case IR_NOT:
                    case IR_ADD: case IR_SUB: case IR_MUL:
                    case IR_DIV: case IR_MOD: case IR_L_ALLOC:
                        if (updateLivenessInfo(basicBlockList[j]->partitionedIR[k]->reachIn, basicBlockList[j]->partitionedIR[k]->reachOut, basicBlockList[j]->partitionedIR[k]->dst->def, basicBlockList[j]->partitionedIR[k]))
                            flag = true;
                        break; 
                    default:
                        for (auto irCode : basicBlockList[j]->partitionedIR[k]->reachIn)
                            basicBlockList[j]->partitionedIR[k]->reachOut.insert(irCode);
                            break;
                }
            }
        }
        }
        while (flag);

        std::ofstream tmp;
        tmp.open("./tmp.txt");
         for (int j = funcBeginSeq[i]; j <= funcEndSeq[i]; j++) {
            int m=0;
            for (int k = 0; k < basicBlockList[j]->partitionedIR.size(); k++) {
                m++;
                tmp << m << "in" << "\n";
                for (auto irCode : basicBlockList[j]->partitionedIR[k]->reachIn)
                    irCode->print(tmp);
                tmp << m << "out" << "\n";
                for (auto irCode : basicBlockList[j]->partitionedIR[k]->reachOut)
                    irCode->print(tmp);
            }
         }
         tmp.close();

        //完善ud链和du链
        for (int j = funcBeginSeq[i]; j <= funcEndSeq[i]; j++) {
            for (int k = 0; k < basicBlockList[j]->partitionedIR.size(); k++) {
                switch (basicBlockList[j]->partitionedIR[k]->opCode) {
                    case IR_ADD: case IR_SUB: case IR_MUL:
                    case IR_DIV: case IR_MOD:
                        for (auto irCode : basicBlockList[j]->partitionedIR[k]->reachIn) {
                            if (basicBlockList[j]->partitionedIR[k]->src1->def.find(irCode) != basicBlockList[j]->partitionedIR[k]->src1->def.end()) {
                                basicBlockList[j]->partitionedIR[k]->src1Use.insert(irCode);
                                irCode->def1.insert(basicBlockList[j]->partitionedIR[k]);
                            }
                            if (basicBlockList[j]->partitionedIR[k]->src2->def.find(irCode) != basicBlockList[j]->partitionedIR[k]->src2->def.end()) {
                                basicBlockList[j]->partitionedIR[k]->src2Use.insert(irCode);
                                irCode->def2.insert(basicBlockList[j]->partitionedIR[k]);
                            }
                        }
                        break;
                    case IR_ASSIGN: case IR_NEG: case IR_NOT:
                        for (auto irCode : basicBlockList[j]->partitionedIR[k]->reachIn) {
                            if (basicBlockList[j]->partitionedIR[k]->src1->def.find(irCode) != basicBlockList[j]->partitionedIR[k]->src1->def.end()) {
                                basicBlockList[j]->partitionedIR[k]->src1Use.insert(irCode);
                                irCode->def1.insert(basicBlockList[j]->partitionedIR[k]);
                            }
                        }
                        break;
                }
            }
        }

        //常量传播
        bool flag1;
        do {
            flag1 = false;
            for (int j = funcBeginSeq[i]; j <= funcEndSeq[i]; j++) {
                for (int k = 0; k < basicBlockList[j]->partitionedIR.size(); k++) {
                    if (basicBlockList[j]->partitionedIR[k]->opCode == IR_ASSIGN && dynamic_cast<IRImmediateValue*>(basicBlockList[j]->partitionedIR[k]->src1) != nullptr && dynamic_cast<IRLocalScalar*>(basicBlockList[j]->partitionedIR[k]->dst) != nullptr || basicBlockList[j]->partitionedIR[k]->opCode == IR_L_ALLOC) {
                        for (auto irCode : basicBlockList[j]->partitionedIR[k]->def1) {
                            if (irCode->src1Use.size() == 1) {
                                if (basicBlockList[j]->partitionedIR[k]->opCode == IR_ASSIGN)
                                    irCode->src1 = basicBlockList[j]->partitionedIR[k]->src1;
                                else
                                    irCode->src1 = reinterpret_cast<IRLocalVar*>(basicBlockList[j]->partitionedIR[k]->dst)->initVal[0];
                                basicBlockList[j]->partitionedIR[k]->def1.erase(irCode);
                                flag1 = true;
                                if (dynamic_cast<IRImmediateValue*>(irCode->src1) != nullptr && dynamic_cast<IRImmediateValue*>(irCode->src2) != nullptr) {
                                    if (irCode->opCode == IR_ADD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1+op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_SUB) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1-op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_DIV) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1/op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_MOD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1%op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                }
                            }
                        }
                        for (auto irCode : basicBlockList[j]->partitionedIR[k]->def2) {
                            if (irCode->src2Use.size() == 1) {
                                if (basicBlockList[j]->partitionedIR[k]->opCode == IR_ASSIGN)
                                    irCode->src2 = basicBlockList[j]->partitionedIR[k]->src1;
                                else 
                                    irCode->src2 = reinterpret_cast<IRLocalVar*>(basicBlockList[j]->partitionedIR[k]->dst)->initVal[0];
                                basicBlockList[j]->partitionedIR[k]->def2.erase(irCode);
                                flag1 = true;
                                if (dynamic_cast<IRImmediateValue*>(irCode->src1) != nullptr && dynamic_cast<IRImmediateValue*>(irCode->src2) != nullptr) {
                                    if (irCode->opCode == IR_ADD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1+op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_SUB) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1-op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_DIV) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1/op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_MOD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediateValue*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediateValue(INT, std::to_string(op1%op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } while(flag1); 

        std::ofstream debug;
        debug.open("de.txt");
        for (int j = funcBeginSeq[i]; j <= funcEndSeq[i]; j++) 
            for (int k = 0; k < basicBlockList[j]->partitionedIR.size(); k++) 
                basicBlockList[j]->partitionedIR[k]->print(debug);
        debug.close();
    }
} 

// 优化跳转指令
void IROptimizer::refineJumpInstructions(std::vector<IntermediateCode*> &irCodeList) {
    for (auto irCode : irCodeList){
        switch(irCode->opCode){
            case IR_GOTO:
            for (int i = 0; i < irCodeList.size(); i++){
                if (irCodeList[i]->opCode == IR_LABEL && irCodeList[i]->dst == irCode->dst) {
                    switch(irCodeList[i+1]->opCode){
                        case IR_GOTO:
                        irCode->dst = irCodeList[i+1]->dst;
                    }
                }
            }
        }
    }
}