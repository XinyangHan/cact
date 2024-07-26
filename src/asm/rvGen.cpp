#include "include/asm/rvGen.h"
#include "include/ir/code.h"
#include <algorithm>

// 生成汇编代码并输出到文件
void AssemblyCodeGenerator::executeAssemblyGene(std::ofstream &asmFile, std::vector<BasicBlock*> &basicBlockList) {
    // 计算栈偏移量
    for (auto basicBlock : basicBlockList) {
        for (auto irCode : basicBlock->rebuildIR) {
            irCode->calculateStackOffset(this);
        }   
    }

    initRegDescriptor();

    // 生成汇编代码
    for (auto basicBlock : basicBlockList) {
        for (auto irCode : basicBlock->rebuildIR) {
            irCode->generateAssembly(this);
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
                regDescriptorMap[reg]->ops.insert(irCode->src1);
                if (paramCount != 0)
                    paramList[0]->assignReg(this, 0);
            }
        }
        // 清除未使用的地址描述符
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
    }

    printAssemblycode(asmFile);
}

// 初始化寄存器描述符
void AssemblyCodeGenerator::initRegDescriptor() {
    for (auto regName : generalRegList) {
        regDescriptorMap[regName] = new RegDescriptor(regName);
    }
    for (auto regName : fpRegs) {
        regDescriptorMap[regName] = new RegDescriptor(regName);
    }
}

// 获取可用寄存器
std::string AssemblyCodeGenerator::getReg(bool fp) {
    if (!fp) {
        for (auto reg : generalRegList) {
            auto it = regDescriptorMap.find(reg);
            if (it->second->ops.size() == 0) {
                if (regConfig && it->second->regName == configReg)
                    continue;
                else
                    return it->second->regName;
            }
        }
    }
    else {
        for (auto reg : fpRegs) {
            auto it = regDescriptorMap.find(reg);
            if (it->second->ops.size() == 0) {
                if (regConfig && it->second->regName == configReg)
                    continue;
                else
                    return it->second->regName;
            }
        }
    }
    throw std::runtime_error("run out of regs.");
}

// 查找地址描述符
AddrDescriptor* AssemblyCodeGenerator::searchAddrDescriptorMap(IROperand *operand) {
    auto it = addrDescriptorMap.find(operand);
    if (it == addrDescriptorMap.end()) {
        AddrDescriptor *newAddrDes = new AddrDescriptor(dynamic_cast<TemporaryValue*>(operand) == nullptr);
        addrDescriptorMap[operand] = newAddrDes;
        return newAddrDes;
    }
    return it->second;
}

// 计算栈帧大小的对齐值
int AssemblyCodeGenerator::roundUp(int stackFrame, int alignSize) {
    return (stackFrame + alignSize - 1) & ~(alignSize - 1);
}

// 输出汇编代码到文件
void AssemblyCodeGenerator::printAssemblycode(std::ofstream &codeFile) {
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
