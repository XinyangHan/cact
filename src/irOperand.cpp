#include <string.h>
#include "irOperand.h"
#include "symbolTable.h"
#include "irOptimizer.h"

//----------------- IRGloblVar ------------------------------------------------------------------
void IRGloblVar::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "@" << name;
    if (alloc) {
        for (auto imm : initVal) {
            irCodeFile << ", ";
            reinterpret_cast<IRImmediate*>(imm)->printIR(irCodeFile);
        }
        alloc = false;
    }
}

std::string IRGloblScalar::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    switch(dataType) {
        case Type::INT:
            return toRegI(asmGenerator, liveInfo);
        case Type::FLOAT:
            return toRegF(asmGenerator, liveInfo);
        case Type::DOUBLE:
            return toRegD(asmGenerator, liveInfo);
    }
}

std::string IRGloblScalar::toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory)) {
            asmGenerator->regDescriptorMap[reg]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    asmGenerator->asmCodeList.push_back("lw " + addrReg + ", 0(" + addrReg + ")");
    
    //add map GScalar-->addrReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(addrReg);
        asmGenerator->regDescriptorMap[addrReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return addrReg;
}

std::string IRGloblScalar::toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory)) {
            asmGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = asmGenerator->getReg(false);
    std::string srcReg = asmGenerator->getReg(true);
    asmGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    asmGenerator->asmCodeList.push_back("flw " + srcReg + ", 0(" + addrReg + ")");
    
    //add map GScalar-->addrReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        asmGenerator->regDescriptorMap[srcReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return srcReg;
}

std::string IRGloblScalar::toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory)) {
            asmGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = asmGenerator->getReg(false);
    std::string srcReg = asmGenerator->getReg(true);
    asmGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    asmGenerator->asmCodeList.push_back("fld " + srcReg + ", 0(" + addrReg + ")");
    
    //add map GScalar-->srcReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        asmGenerator->regDescriptorMap[srcReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return srcReg;
}

void IRGloblScalar::toMem(AsmGenerator *asmGenerator, LiveInfo *liveInfo, std::string srcReg) {
    std::string asmOpcode;
    switch(dataType) {
        case INT:
            asmOpcode = "sw ";
            break;
        case FLOAT:
            asmOpcode = "fsw ";
            break;
        case DOUBLE:
            asmOpcode = "fsd ";
            break; 
    }
    std::string addrReg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back(std::string("la ") + addrReg + std::string(", GVar") + std::to_string(name));
    asmGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", 0(") + addrReg + std::string(")"));
}

std::string IRGloblArray::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory)) {
            asmGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    
    //add map GArray-->addrReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(addrReg);
        asmGenerator->regDescriptorMap[addrReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
        
    return addrReg;
}

//----------------- IRLocalVar ------------------------------------------------------------------
void IRLocalVar::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "^" << name;
    if (alloc) {
        for (auto imm : initVal) {
            irCodeFile << ", ";
            reinterpret_cast<IRImmediate*>(imm)->printIR(irCodeFile);
        }
        alloc = false;
    }
}

void IRLocalScalar::toAssignReg(AsmGenerator *asmGenerator, int num) {
    std::string asmOpcode;
    std::string assignReg;
    switch(dataType) {
        case INT:
            asmOpcode = "lw ";
            assignReg = "a" + std::to_string(num);
            break;
        case FLOAT:
            asmOpcode = "flw ";
            assignReg = "fa" + std::to_string(num);
            break;
        case DOUBLE:
            asmOpcode = "fld ";
            assignReg = "fa" + std::to_string(num);
            break;
        case INT_PTR: case FLOAT_PTR:
        case DOUBLE_PTR:
            asmOpcode = "ld ";
            assignReg = "a" + std::to_string(num);
            break;
    }
    
    asmGenerator->asmCodeList.push_back(asmOpcode + assignReg + std::string(", ") + std::to_string(-displacement) + std::string("(s0)"));
}

std::string IRLocalScalar::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    switch(dataType) {
        case Type::INT: case Type::INT_PTR:
        case Type::FLOAT_PTR: case Type::DOUBLE_PTR:
            return toRegI(asmGenerator, liveInfo);
        case Type::FLOAT:
            return toRegF(asmGenerator, liveInfo);
        case Type::DOUBLE:
            return toRegD(asmGenerator, liveInfo);
    }
}

std::string IRLocalScalar::toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory) && !addrDescriptor->isArg) {
            asmGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string srcReg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back(std::string("lw ") + srcReg + std::string(", ") + std::to_string(-displacement) + std::string("(s0)"));
    
    //add map LScalar-->srcReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        asmGenerator->regDescriptorMap[srcReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    return srcReg;
}

std::string IRLocalScalar::toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory) && !addrDescriptor->isArg) {
            asmGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string srcReg = asmGenerator->getReg(true);
    asmGenerator->asmCodeList.push_back("flw " + srcReg + ", " + std::to_string(-displacement) + std::string("(s0)"));
    
    //add map LScalar-->srcReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        asmGenerator->regDescriptorMap[srcReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    return srcReg;
}

std::string IRLocalScalar::toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory) && !addrDescriptor->isArg) {
            asmGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string srcReg = asmGenerator->getReg(true);
    asmGenerator->asmCodeList.push_back("fld " + srcReg + ", " + std::to_string(-displacement) + std::string("(s0)"));
    
    //add map LScalar-->srcReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        asmGenerator->regDescriptorMap[srcReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    return srcReg;
}

void IRLocalScalar::toMem(AsmGenerator *asmGenerator, LiveInfo *liveInfo, std::string srcReg) {
    std::string asmOpcode;
    switch(dataType) {
        case INT:
            asmOpcode = "sw ";
            break;
        case FLOAT: 
            asmOpcode = "fsw ";
            break;
        case DOUBLE:
            asmOpcode = "fsd ";
            break; 
        case INT_PTR: case FLOAT_PTR:
        case DOUBLE_PTR:
            asmOpcode = "sd ";
            break;
    }
    asmGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", ") + std::to_string(-displacement) + std::string("(s0)"));
}

std::string IRLocalArray::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory)) {
            asmGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    std::string baseReg;
    baseReg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back(std::string("addi ") + baseReg + std::string(", s0, ") + std::to_string(-displacement));
    
    //add map LArray-->baseReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(baseReg);
        asmGenerator->regDescriptorMap[baseReg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return baseReg;
}

//----------------- IRImmediate ------------------------------------------------------------------
std::string IRImmediate::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    switch(dataType) {
        case Type::INT:
            return toRegI(asmGenerator, liveInfo);
        case Type::FLOAT: 
            return toRegF(asmGenerator, liveInfo);
        case Type::DOUBLE: 
            return toRegD(asmGenerator, liveInfo);
    }
}

std::string IRImmediate::toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    std::string reg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back("li " + reg + ", " + reinterpret_cast<IRImmediate*>(this)->val);
    return reg;
}

std::string IRImmediate::toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    float fval = std::stof(reinterpret_cast<IRImmediate*>(this)->val);
    int dval = *(int*)&fval;
    std::string reg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back("li " + reg + ", " + std::to_string(dval));
    std::string fReg = asmGenerator->getReg(true);
    asmGenerator->asmCodeList.push_back("fmv.w.x " + fReg + ", " + reg);
    return fReg;
}

std::string IRImmediate::toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    asmGenerator->asmDataList.push_back(".data");
    asmGenerator->asmDataList.push_back(".align 3");
    asmGenerator->asmDataList.push_back(std::string(".type IMM") + std::to_string(name) + std::string(", @object"));
    asmGenerator->asmDataList.push_back(std::string(".size IMM") + std::to_string(name) + std::string(", 8"));
    asmGenerator->asmDataList.push_back(std::string("IMM") + std::to_string(name) + std::string(":"));

    double fval = std::stod(val);
    long long dval = *(long long *)&fval;
    asmGenerator->asmDataList.push_back(std::string(".dword ") + std::to_string(dval));

    std::string addrReg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back(std::string("la ") + addrReg + std::string(", IMM") + std::to_string(name));
    std::string fReg = asmGenerator->getReg(true);
    asmGenerator->asmCodeList.push_back(std::string("fld ") + fReg + std::string(", ") + std::string("0(") + addrReg + std::string(")"));
    return fReg;
}

void IRImmediate::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "$" << val;
}

//----------------- IRTemp ------------------------------------------------------------------
std::string IRTemp::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    switch(dataType) {
        case Type::INT:
            return toRegI(asmGenerator, liveInfo);
        case Type::FLOAT: case Type::DOUBLE: 
            return toRegF(asmGenerator, liveInfo);
    }
}

std::string IRTemp::toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory)) {
            asmGenerator->regDescriptorMap[reg]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string reg = asmGenerator->getReg(false);
    //add map TempReg-->reg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(reg);
        asmGenerator->regDescriptorMap[reg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return reg;
}

std::string IRTemp::toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = asmGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->atMemory)) {
            asmGenerator->regDescriptorMap[reg]->operandList.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string reg = asmGenerator->getReg(true);
    //add map TempReg-->reg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(reg);
        asmGenerator->regDescriptorMap[reg]->operandList.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return reg;
}

void IRTemp::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "%" << name;
}

//----------------- IRArrayElem ------------------------------------------------------------------
std::string IRArrayElem::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    Type dataType;
    if (dynamic_cast<IRGloblVar*>(arrayPtr) != nullptr) 
        dataType = reinterpret_cast<IRGloblVar*>(arrayPtr)->dataType;
    else 
        dataType = reinterpret_cast<IRLocalVar*>(arrayPtr)->dataType;
    switch(dataType) {
        case Type::INT: case Type::INT_PTR: case Type::BOOL:
            return toRegI(asmGenerator, liveInfo);
        case Type::FLOAT: case Type::FLOAT_PTR:
            return toRegF(asmGenerator, liveInfo);
        case Type::DOUBLE: case Type::DOUBLE_PTR:
            return toRegD(asmGenerator, liveInfo);
    }
}

std::string IRArrayElem::toRegI(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    if (dynamic_cast<IRLocalArray*>(arrayPtr) != nullptr) {
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string baseReg = asmGenerator->getReg(false);
        asmGenerator->asmCodeList.push_back(std::string("add ") + baseReg + std::string(", s0, ") + displaceReg);
        asmGenerator->asmCodeList.push_back(std::string("lw ") + baseReg + std::string(", -") + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->displacement) + std::string("(") + baseReg + std::string(")"));
        return baseReg;
    }
    else {
        std::string baseReg = arrayPtr->toReg(asmGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string addrReg = asmGenerator->getReg(false);
        asmGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseReg + ", " + displaceReg);
        asmGenerator->asmCodeList.push_back("lw " + addrReg + ", " + "0(" + addrReg + ")");
        return addrReg;
    }
}

std::string IRArrayElem::toRegF(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    std::string valReg;
    if (dynamic_cast<IRLocalArray*>(arrayPtr) != nullptr) {
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string baseReg = asmGenerator->getReg(false);
        valReg  = asmGenerator->getReg(true);
        asmGenerator->asmCodeList.push_back("add " + baseReg + "s0, " + displaceReg);
        asmGenerator->asmCodeList.push_back("flw " + valReg + ", -" + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->displacement) + "(" + baseReg + ")");
    }
    else {
        std::string baseReg = arrayPtr->toReg(asmGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string addrReg = asmGenerator->getReg(false);
        valReg  = asmGenerator->getReg(true);
        asmGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseReg + ", " + displaceReg);
        asmGenerator->asmCodeList.push_back("flw " + valReg + ", " + "0(" + addrReg + ")");
    }
    return valReg;
}

std::string IRArrayElem::toRegD(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    std::string valReg;
    if (dynamic_cast<IRLocalArray*>(arrayPtr) != nullptr) {
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string baseReg = asmGenerator->getReg(false);
        valReg  = asmGenerator->getReg(true);
        asmGenerator->asmCodeList.push_back("add " + baseReg + "s0, " + displaceReg);
        asmGenerator->asmCodeList.push_back("fld " + valReg + ", -" + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->displacement) + "(" + baseReg + ")");
    }
    else {
        std::string baseReg = arrayPtr->toReg(asmGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string addrReg = asmGenerator->getReg(false);
        valReg  = asmGenerator->getReg(true);
        asmGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseReg + ", " + displaceReg);
        asmGenerator->asmCodeList.push_back("fld " + valReg + ", " + "0(" + addrReg + ")");
    }
    return valReg;
}

void IRArrayElem::toMem(AsmGenerator *asmGenerator, LiveInfo *liveInfo, std::string srcReg) {
    std::string asmOpcode;
    Type dataType;
    if (dynamic_cast<IRGloblVar*>(arrayPtr) != nullptr) 
        dataType = reinterpret_cast<IRGloblVar*>(arrayPtr)->dataType;
    else 
        dataType = reinterpret_cast<IRLocalVar*>(arrayPtr)->dataType;
    switch(dataType) {
        case INT: case INT_PTR:
            asmOpcode = "sw ";
            break;
        case FLOAT: case FLOAT_PTR:
            asmOpcode = "fsw ";
            break;
        case DOUBLE: case DOUBLE_PTR:
            asmOpcode = "fsd ";
            break; 
    }
    if (dynamic_cast<IRLocalArray*>(arrayPtr) != nullptr) {
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string baseReg = asmGenerator->getReg(false);
        asmGenerator->asmCodeList.push_back(std::string("add ") + baseReg + std::string(", s0, ") + displaceReg);
        asmGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", -") + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->displacement) + "(" + baseReg + ")");
    }
    else {
        std::string baseReg = arrayPtr->toReg(asmGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
        std::string addrReg = asmGenerator->getReg(false);
        asmGenerator->asmCodeList.push_back(std::string("add ") + addrReg + std::string(", ") + baseReg + std::string(", ") + displaceReg);
        asmGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", ") + std::string("0(") + addrReg + std::string(")"));
    }
}

void IRArrayElem::printIR(std::ofstream &irCodeFile) {
    arrayPtr->printIR(irCodeFile);
    irCodeFile << "<";
    tempPtr->printIR(irCodeFile);
}

LiveInfo* IRArrayElem::setLiveInfo(BasicBlock *basicBlock) {
    LiveInfo *ArrayLiveInfo = basicBlock->searchLivenessMap(this->arrayPtr);
    LiveInfo *TempLiveInfo  = basicBlock->searchLivenessMap(this->tempPtr);
    return new LiveInfo(ArrayLiveInfo, TempLiveInfo);
}

void IRArrayElem::calLiveInfo(BasicBlock *basicBlock, bool liveness, IRCode *usedInfo) {
    arrayPtr->calLiveInfo(basicBlock, true, usedInfo);
    tempPtr->calLiveInfo(basicBlock, true, usedInfo);
}

IROperand *IRArrayElem::getSrc() {
    return arrayPtr;
}

IROperand *IRArrayElem::getDisplace() {
    return tempPtr;
}

//----------------- IRArrayAddr ------------------------------------------------------------------
std::string IRArrayAddr::toReg(AsmGenerator *asmGenerator, LiveInfo *liveInfo) {
    std::string baseAddr = arrayPtr->toReg(asmGenerator, liveInfo->arrayInfo);
    std::string displaceReg = tempPtr->toReg(asmGenerator, liveInfo->tempInfo);
    std::string addrReg = asmGenerator->getReg(false);
    asmGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseAddr + ", " + displaceReg);
    return addrReg;
}

void IRArrayAddr::printIR(std::ofstream &irCodeFile) {
    arrayPtr->printIR(irCodeFile);
    irCodeFile << ">";
    tempPtr->printIR(irCodeFile);
}

LiveInfo* IRArrayAddr::setLiveInfo(BasicBlock *basicBlock) {
    LiveInfo *ArrayLiveInfo = basicBlock->searchLivenessMap(this->arrayPtr);
    LiveInfo *TempLiveInfo  = basicBlock->searchLivenessMap(this->tempPtr);
    return new LiveInfo(ArrayLiveInfo, TempLiveInfo);
}

IROperand *IRArrayAddr::getSrc() {
    return arrayPtr;
}

IROperand *IRArrayAddr::getDisplace() {
    return tempPtr;
}

//----------------- IRLabel ------------------------------------------------------------------
void IRArrayAddr::calLiveInfo(BasicBlock *basicBlock, bool liveness, IRCode *usedInfo) {
    arrayPtr->calLiveInfo(basicBlock, true, usedInfo);
    tempPtr->calLiveInfo(basicBlock, true, usedInfo);
}

//----------------- IRLabel ------------------------------------------------------------------
void IRLabel::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "L" << name;
}

//----------------- IRFunc ------------------------------------------------------------------
void IRFunc::printIR(std::ofstream &irCodeFile) {
    irCodeFile << funcSymbol->getSymbolName().c_str();
}

//----------------- IROperand ------------------------------------------------------------------
LiveInfo* IROperand::setLiveInfo(BasicBlock *basicBlock) {
    return basicBlock->searchLivenessMap(this);
}

void IROperand::calLiveInfo(BasicBlock *basicBlock, bool liveness, IRCode *usedInfo) {
    basicBlock->livenessMap[this]  = new LiveInfo(liveness, usedInfo);
}

void IROperand::toArgReg(AsmGenerator *asmGenerator, int num, std::string srcReg) {
    std::string reg;
    std::string asmOpcode;
    if (dynamic_cast<IRArrayElem*>(this) != nullptr) {
        if (dynamic_cast<IRGloblVar*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr) != nullptr) {
            if (reinterpret_cast<IRGloblVar*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr)->dataType == FLOAT) {
                reg = "fa" + std::to_string(num);
                asmOpcode = "fmv.s ";
            }
            else if (reinterpret_cast<IRGloblVar*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr)->dataType == DOUBLE) {
                reg = "fa" + std::to_string(num);
                asmOpcode = "fmv.d ";
            }
            else {
                reg = "a" + std::to_string(num);
                asmOpcode = "mv ";
            }
        }
        else {
            if (reinterpret_cast<IRLocalVar*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr)->dataType == FLOAT) {
                reg = "fa" + std::to_string(num);
                asmOpcode = "fmv.s ";
            }
            else if (reinterpret_cast<IRLocalVar*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr)->dataType == DOUBLE) {
                reg = "fa" + std::to_string(num);
                asmOpcode = "fmv.d ";
            }
            else {
                reg = "a" + std::to_string(num);
                asmOpcode = "mv ";
            }
        }    
    }
    else if (dynamic_cast<IRArrayAddr*>(this) != nullptr) {
        reg = "a" + std::to_string(num);
        asmOpcode = "mv ";
    }
    else if (dynamic_cast<IRGloblVar*>(this) != nullptr) {
        if (reinterpret_cast<IRGloblVar*>(this)->dataType == FLOAT) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.s ";
        }
        else if (reinterpret_cast<IRGloblVar*>(this)->dataType == DOUBLE) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.d ";
        }
        else {
            reg = "a" + std::to_string(num);
            asmOpcode = "mv ";
        }
    }
    else if (dynamic_cast<IRLocalVar*>(this) != nullptr) {
        if (reinterpret_cast<IRLocalVar*>(this)->dataType == FLOAT) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.s ";
        }
        else if (reinterpret_cast<IRLocalVar*>(this)->dataType == DOUBLE) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.d ";
        }
        else {
            reg = "a" + std::to_string(num);
            asmOpcode = "mv ";
        }
    }
    else if (dynamic_cast<IRTemp*>(this) != nullptr) {
        if (reinterpret_cast<IRTemp*>(this)->dataType == FLOAT) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.s ";
        }
        else if (reinterpret_cast<IRTemp*>(this)->dataType == DOUBLE) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.d ";
        }
        else {
            reg = "a" + std::to_string(num);
            asmOpcode = "mv ";
        }
    }
    else if (dynamic_cast<IRImmediate*>(this) != nullptr) {
        if (reinterpret_cast<IRImmediate*>(this)->dataType == FLOAT) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.s ";
        }
        else if (reinterpret_cast<IRImmediate*>(this)->dataType == DOUBLE) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.d ";
        }
        else {
            reg = "a" + std::to_string(num);
            asmOpcode = "mv ";
        }
    }
    asmGenerator->asmCodeList.push_back(asmOpcode + reg + std::string(", ") + srcReg);
}
