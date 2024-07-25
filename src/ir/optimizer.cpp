#include "include/irOptimizer.h"
#include "include/irCode.h"
#include <cassert>
#include "include/irGenerator.h"

void IROptimizer::basicBlockPartition(std::vector<IRCode*> &irCodeList) {
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
        IRCode *lastIR = block->partitionedIR[block->partitionedIR.size()-1];
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

void IROptimizer::commonSubexpssionEliminate() {
    for (auto basicBlock : basicBlockList) {
        basicBlock->commonSubexpssionEliminate();
    }
}

void IROptimizer::calLiveInfo() {
    for (auto basicBlock : basicBlockList) {
        basicBlock->calLiveInfo();
    }
}

void IROptimizer::irRebuild() {
    for (auto basicBlock : basicBlockList) {
        for (auto rebuidIR : basicBlock->rebuildIR) {
            optIrCodeList.push_back(rebuidIR);
        }
    }
}

void BasicBlock::commonSubexpssionEliminate() {
    for (auto irCode : partitionedIR) {
        irCode->generateDag(this);
    }
    for (auto dagNode : dagNodeList) {
        dagNode->initRepresentElem();
    }

    for (int i = 0; i < dagNodeList.size(); i++) {
        IRCode *irCode = dagNodeList[i]->irRebuild(rebuildIR);
        if (irCode != nullptr)
            rebuildIR.push_back(irCode);
    }

}

void BasicBlock::calLiveInfo() {
    for (int i = rebuildIR.size()-1; i >= 0; i--) {
        rebuildIR[i]->calLiveInfo(this);
    }
}

DagNode *BasicBlock::searchOperand2DagNode(IROperand *src) {
    auto it = this->operand2DagNode.find(src);
    if (it == this->operand2DagNode.end()) {
        DagNode *newDagNode = new DagTerminalNode(reinterpret_cast<IRVar*>(src)->dataType);
        newDagNode->basicBlock = this;
        operand2DagNode[src] = newDagNode;
        reinterpret_cast<DagTerminalNode*>(newDagNode)->notTemp = src;
        newDagNode->relatedSet.insert(src);
        return newDagNode;
    }
    else {
        return it->second;
    }
}

LiveInfo *BasicBlock::searchLivenessMap(IROperand* operand) {
    LiveInfo *newLiveInfo;
    auto it = livenessMap.find(operand);
    if (it == livenessMap.end()) {
        if (dynamic_cast<IRTemp*>(operand) != nullptr) {
            newLiveInfo = new LiveInfo(false, nullptr);
            livenessMap[operand] = newLiveInfo;
        }
        else {
            newLiveInfo = new LiveInfo(true, nullptr);
            livenessMap[operand] = newLiveInfo;
        }
        return newLiveInfo;
    }
    else {
        return it->second;
    }
}

IROperand *DagTerminalNode::getIROperand() {
    if (dynamic_cast<IRArrayElem*>(notTemp) != nullptr) {
        DagNode *dagNode = basicBlock->searchOperand2DagNode(reinterpret_cast<IRArrayElem*>(notTemp)->tempPtr);
        return new IRArrayElem(reinterpret_cast<IRArrayElem*>(notTemp)->arrayPtr, dagNode->getIROperand());
    }
    else if (dynamic_cast<IRArrayAddr*>(notTemp) != nullptr) {
        DagNode *dagNode = basicBlock->searchOperand2DagNode(reinterpret_cast<IRArrayAddr*>(notTemp)->tempPtr);
        return new IRArrayAddr(reinterpret_cast<IRArrayAddr*>(notTemp)->arrayPtr, dagNode->getIROperand());
    }
    else {
        return notTemp;
    }
}

IROperand *DagInnerNode::getIROperand() {
    if (isArray) {
        auto it = relatedSet.begin();
        DagNode *dagNode = basicBlock->searchOperand2DagNode(reinterpret_cast<IRArrayElem*>(*it)->tempPtr);
        return new IRArrayElem(reinterpret_cast<IRArrayElem*>(*it)->arrayPtr, dagNode->getIROperand());
    }
    else {
        return representElem;
    }
}

void DagInnerNode::initRepresentElem() {
    if (!isArray) {
        if (label != nullptr) {
            representElem = label;
            return ;
        }
        representElem = new IRTemp(dataType);
    }
}

IRCode *DagInnerNode::irRebuild(std::vector<IRCode*>& rebuildIR) {
    IROperand *src1 = lchild->getIROperand();
    IROperand *src2 = nullptr;
    if (rchild != nullptr) {
        src2 = rchild->getIROperand();
    }

    rebuildIR.push_back(new IRCode(dataType, opCode, getIROperand(), src1, src2));

    if (!reinterpret_cast<DagInnerNode*>(this)->isArray) {
        auto it = this->relatedSet.begin();
        if (dynamic_cast<IRTemp*>(*it) == nullptr) {
            for (auto related : this->relatedSet) {
                rebuildIR.push_back(new IRCode(this->dataType, IR_ASSIGN, related, this->getIROperand(), nullptr));
            }
        }
    }

    return nullptr;
}

IRCode *DagOtherNode::irRebuild(std::vector<IRCode*>& rebuildIR) {
    if (opCode != IR_PARAM && opCode != IR_RETURN) {
        return irCode;
    }
    else {
        if (irCode->dst != nullptr) {
            DagNode *dagNode = basicBlock->searchOperand2DagNode(irCode->dst);
            //rebuildIR.push_back(new IRCode(irCode->dataType, irCode->opCode, dagNode->getIROperand(), nullptr, nullptr));
            return new IRCode(irCode->dataType, irCode->opCode, dagNode->getIROperand(), nullptr, nullptr);
        }
        else {
            //rebuildIR.push_back(new IRCode(irCode->dataType, irCode->opCode, nullptr, nullptr, nullptr));
            return new IRCode(irCode->dataType, irCode->opCode, nullptr, nullptr, nullptr);
        }
    }
}

void IROptimizer::printOptIRCode(std::ofstream &irCodeFile) {
    for (auto const & irCode : optIrCodeList) {
        irCode->print(irCodeFile);
    }
}

void IROptimizer::printBasicBlock() {
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

void addReachOut(std::set<IRCode*> &in, std::set<IRCode*> &predOut) {
    for (auto irCode : predOut)
        in.insert(irCode);
}

bool killAndGen(std::set<IRCode*> &in, std::set<IRCode*> &out, std::set<IRCode*> &kill, IRCode *self) {
    std::set<IRCode*> tmp;
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

void IROptimizer::constPass(IRGenerator *irGenerator) {
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
                        if (killAndGen(basicBlockList[j]->partitionedIR[k]->reachIn, basicBlockList[j]->partitionedIR[k]->reachOut, basicBlockList[j]->partitionedIR[k]->dst->def, basicBlockList[j]->partitionedIR[k]))
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
                    if (basicBlockList[j]->partitionedIR[k]->opCode == IR_ASSIGN && dynamic_cast<IRImmediate*>(basicBlockList[j]->partitionedIR[k]->src1) != nullptr && dynamic_cast<IRLocalScalar*>(basicBlockList[j]->partitionedIR[k]->dst) != nullptr || basicBlockList[j]->partitionedIR[k]->opCode == IR_L_ALLOC) {
                        for (auto irCode : basicBlockList[j]->partitionedIR[k]->def1) {
                            if (irCode->src1Use.size() == 1) {
                                if (basicBlockList[j]->partitionedIR[k]->opCode == IR_ASSIGN)
                                    irCode->src1 = basicBlockList[j]->partitionedIR[k]->src1;
                                else
                                    irCode->src1 = reinterpret_cast<IRLocalVar*>(basicBlockList[j]->partitionedIR[k]->dst)->initVal[0];
                                basicBlockList[j]->partitionedIR[k]->def1.erase(irCode);
                                flag1 = true;
                                if (dynamic_cast<IRImmediate*>(irCode->src1) != nullptr && dynamic_cast<IRImmediate*>(irCode->src2) != nullptr) {
                                    if (irCode->opCode == IR_ADD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1+op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_SUB) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1-op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_DIV) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1/op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_MOD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1%op2)); 
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
                                if (dynamic_cast<IRImmediate*>(irCode->src1) != nullptr && dynamic_cast<IRImmediate*>(irCode->src2) != nullptr) {
                                    if (irCode->opCode == IR_ADD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1+op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_SUB) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1-op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_DIV) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1/op2)); 
                                                irCode->src2 = nullptr;
                                                break;
                                        }
                                    }
                                    else if (irCode->opCode == IR_MOD) {
                                        switch(irCode->dataType) {
                                            case INT:
                                                int op1 = stoi(reinterpret_cast<IRImmediate*>(irCode->src1)->val);
                                                int op2 = stoi(reinterpret_cast<IRImmediate*>(irCode->src2)->val);
                                                irCode->opCode = IR_ASSIGN;
                                                irCode->src1 = irGenerator->addIRImmediate(INT, std::to_string(op1%op2)); 
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

void IROptimizer::jumpPass(std::vector<IRCode*> &irCodeList) {
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