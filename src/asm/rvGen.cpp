#include "include/asm/RV_Gen.h"
#include "include/ir/code.h"
#include <algorithm>

void AsmGenerator::invokeAsmGene(std::ofstream &asmCodeFile, std::vector<BasicBlock*> &basicBlockList) {
    for (auto basicBlock : basicBlockList) {
        for (auto irCode : basicBlock->rebuildIR) {
            irCode->calStackDisplacement(this);
        }   
    }

    initRegDescriptor();

    for (auto basicBlock : basicBlockList) {
        for (auto irCode : basicBlock->rebuildIR) {
            irCode->genAsmCode(this);
            if (irCode->opCode == IR_CALL && irCode->src1 != nullptr) {
                std::string reg;
                if (irCode->dataType == FLOAT) {
                    reg = getReg(true);
                    asmCodeList.push_back(std::string("fmv.s ") + reg + std::string(", ") + std::string("fa0"));
                }
                else if (irCode->dataType == DOUBLE) {
                    reg = getReg(true);
                    asmCodeList.push_back(std::string("fmv.d ") + reg + std::string(", ") + std::string("fa0"));
                }
                else {
                    reg = getReg(false);
                    asmCodeList.push_back(std::string("mv ") + reg + std::string(", ") + std::string("a0"));
                }
                AddrDescriptor *addrDes = searchAddrDescriptorMap(irCode->src1);
                addrDes->atReg.push_back(reg);
                regDescriptorMap[reg]->operandList.insert(irCode->src1);
                if (paramNum != 0)
                    paramList[0]->toAssignReg(this, 0);
                }
        }
        auto it = addrDescriptorMap.begin();
        while (it != addrDescriptorMap.end()) {
            if (std::count(paramList.begin(), paramList.end(), it->first) == 0) {
                auto dit = it;
                it++;
                addrDescriptorMap.erase(dit->first);
            }
            else {
                it++;
            }
        }
        /*for (auto reg : generalRegList) {
            regDescriptorMap[reg]->operandList.clear();
        }
        for (auto reg : fpRegList) {
            regDescriptorMap[reg]->operandList.clear();
        }
        if (flag) {
            std::string reg;
            if (callType == FLOAT) {
                reg = getReg(true);
                asmCodeList.push_back(std::string("fmv.s ") + reg + std::string(", ") + std::string("fa0"));
            }
            else if (callType == DOUBLE) {
                reg = getReg(true);
                asmCodeList.push_back(std::string("fmv.d ") + reg + std::string(", ") + std::string("fa0"));
            }
            else {
                reg = getReg(false);
                asmCodeList.push_back(std::string("mv ") + reg + std::string(", ") + std::string("a0"));
            }
            AddrDescriptor *addrDes = searchAddrDescriptorMap(src1);
            addrDes->atReg.push_back(reg);
            regDescriptorMap[reg]->operandList.insert(src1);
            if (paramNum != 0)
                paramList[0]->toAssignReg(this, 0);
        }*/
    }

    printAsmcode(asmCodeFile);
}

void AsmGenerator::initRegDescriptor() {
    for (auto regName : generalRegList) {
        regDescriptorMap[regName] = new RegDescriptor(regName);
    }
    for (auto regName : fpRegList) {
        regDescriptorMap[regName] = new RegDescriptor(regName);
    }
}

std::string AsmGenerator::getReg(bool fp) {
    if (!fp) {
        for (auto reg : generalRegList) {
            auto it = regDescriptorMap.find(reg);
            if (it->second->operandList.size() == 0) {
                if (regConfig && it->second->regName == configReg)
                    continue;
                else
                    return it->second->regName;
            }
        }
    }
    else {
        for (auto reg : fpRegList) {
            auto it = regDescriptorMap.find(reg);
            if (it->second->operandList.size() == 0) {
                if (regConfig && it->second->regName == configReg)
                    continue;
                else
                    return it->second->regName;
            }
        }
    }
    throw std::runtime_error("run out of regs.");
}

AddrDescriptor *AsmGenerator::searchAddrDescriptorMap(IROperand *operand) {
    auto it = addrDescriptorMap.find(operand);
    if (it == addrDescriptorMap.end()) {
        if (dynamic_cast<IRTemp*>(operand) == nullptr) {
            AddrDescriptor *newAddrDes = new AddrDescriptor(true);
            addrDescriptorMap[operand] = newAddrDes;
            return newAddrDes;
        }
        else {
            AddrDescriptor *newAddrDes = new AddrDescriptor(false);
            addrDescriptorMap[operand] = newAddrDes;
            return newAddrDes;
        }
    }
    return it->second;
}

int AsmGenerator::roundUp(int stackFrame, int alignSize) {
    return (stackFrame + alignSize - 1) & ~(alignSize - 1);
}

void AsmGenerator::printAsmcode(std::ofstream &codeFile) {
    codeFile << "   .option nopic\n";
    codeFile << "   .attribute arch, \"rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0\"\n";
    codeFile << "   .attribute unaligned_access, 0\n";
    codeFile << "   .attribute stack_align, 16\n";
    for (auto code : asmCodeList) {
        if (code[0] != 'L') {
            codeFile << "   ";
        }
        codeFile << code << "\n";
    }
    codeFile << "\n";
    for (auto data : asmDataList) {
        codeFile << "   " << data << "\n";
    }
}

