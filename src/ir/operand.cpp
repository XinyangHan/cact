#include <string.h>
#include "include/ir/operand.h"
#include "include/analysis/symTable.h"
#include "include/ir/optimizer.h"

//----------------- IrGlobalVariable ------------------------------------------------------------------
void IrGlobalVariable::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "@" << name;
    if (alloc) {
        for (auto imm : initVal) {
            irCodeFile << ", ";
            reinterpret_cast<IRImmediateValue*>(imm)->printIR(irCodeFile);
        }
        alloc = false;
    }
}

std::string IRGloblScalar::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    switch(dataType) {
        case Type::INT:
            return toRegisterInt(AssemblyGenerator, liveInfo);
        case Type::FLOAT:
            return toRegisterFloat(AssemblyGenerator, liveInfo);
        case Type::DOUBLE:
            return toRegisterDouble(AssemblyGenerator, liveInfo);
    }
}

std::string IRGloblScalar::toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem)) {
            AssemblyGenerator->regDescriptorMap[reg]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    AssemblyGenerator->asmCodeList.push_back("lw " + addrReg + ", 0(" + addrReg + ")");
    
    //add map GScalar-->addrReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(addrReg);
        AssemblyGenerator->regDescriptorMap[addrReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return addrReg;
}

std::string IRGloblScalar::toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem)) {
            AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = AssemblyGenerator->getReg(false);
    std::string srcReg = AssemblyGenerator->getReg(true);
    AssemblyGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    AssemblyGenerator->asmCodeList.push_back("flw " + srcReg + ", 0(" + addrReg + ")");
    
    //add map GScalar-->addrReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        AssemblyGenerator->regDescriptorMap[srcReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return srcReg;
}

std::string IRGloblScalar::toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem)) {
            AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = AssemblyGenerator->getReg(false);
    std::string srcReg = AssemblyGenerator->getReg(true);
    AssemblyGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    AssemblyGenerator->asmCodeList.push_back("fld " + srcReg + ", 0(" + addrReg + ")");
    
    //add map GScalar-->srcReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        AssemblyGenerator->regDescriptorMap[srcReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return srcReg;
}

void IRGloblScalar::toMem(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo, std::string srcReg) {
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
    std::string addrReg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back(std::string("la ") + addrReg + std::string(", GVar") + std::to_string(name));
    AssemblyGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", 0(") + addrReg + std::string(")"));
}

std::string IRGloblArray::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem)) {
            AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string addrReg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back("la " + addrReg + ", GVar" + std::to_string(name));
    
    //add map GArray-->addrReg, if it will be used later
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(addrReg);
        AssemblyGenerator->regDescriptorMap[addrReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
        
    return addrReg;
}

//----------------- IRLocalVar ------------------------------------------------------------------
void IRLocalVar::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "^" << name;
    if (alloc) {
        for (auto imm : initVal) {
            irCodeFile << ", ";
            reinterpret_cast<IRImmediateValue*>(imm)->printIR(irCodeFile);
        }
        alloc = false;
    }
}

void IRLocalScalar::assignReg(AssemblyCodeGenerator *AssemblyGenerator, int num) {
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
    
    AssemblyGenerator->asmCodeList.push_back(asmOpcode + assignReg + std::string(", ") + std::to_string(-offset) + std::string("(s0)"));
}

std::string IRLocalScalar::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    switch(dataType) {
        case Type::INT: case Type::INT_PTR:
        case Type::FLOAT_PTR: case Type::DOUBLE_PTR:
            return toRegisterInt(AssemblyGenerator, liveInfo);
        case Type::FLOAT:
            return toRegisterFloat(AssemblyGenerator, liveInfo);
        case Type::DOUBLE:
            return toRegisterDouble(AssemblyGenerator, liveInfo);
    }
}

std::string IRLocalScalar::toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem) && !addrDescriptor->isArg) {
            AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string srcReg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back(std::string("lw ") + srcReg + std::string(", ") + std::to_string(-offset) + std::string("(s0)"));
    
    //add map LScalar-->srcReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        AssemblyGenerator->regDescriptorMap[srcReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    return srcReg;
}

std::string IRLocalScalar::toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem) && !addrDescriptor->isArg) {
            AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string srcReg = AssemblyGenerator->getReg(true);
    AssemblyGenerator->asmCodeList.push_back("flw " + srcReg + ", " + std::to_string(-offset) + std::string("(s0)"));
    
    //add map LScalar-->srcReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        AssemblyGenerator->regDescriptorMap[srcReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    return srcReg;
}

std::string IRLocalScalar::toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem) && !addrDescriptor->isArg) {
            AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string srcReg = AssemblyGenerator->getReg(true);
    AssemblyGenerator->asmCodeList.push_back("fld " + srcReg + ", " + std::to_string(-offset) + std::string("(s0)"));
    
    //add map LScalar-->srcReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(srcReg);
        AssemblyGenerator->regDescriptorMap[srcReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    return srcReg;
}

void IRLocalScalar::toMem(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo, std::string srcReg) {
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
    AssemblyGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", ") + std::to_string(-offset) + std::string("(s0)"));
}

std::string IRLocalArray::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search Reg descriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem)) {
            AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    std::string baseReg;
    baseReg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back(std::string("addi ") + baseReg + std::string(", s0, ") + std::to_string(-offset));
    
    //add map LArray-->baseReg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(baseReg);
        AssemblyGenerator->regDescriptorMap[baseReg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return baseReg;
}

//----------------- IRImmediateValue ------------------------------------------------------------------
std::string IRImmediateValue::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    switch(dataType) {
        case Type::INT:
            return toRegisterInt(AssemblyGenerator, liveInfo);
        case Type::FLOAT: 
            return toRegisterFloat(AssemblyGenerator, liveInfo);
        case Type::DOUBLE: 
            return toRegisterDouble(AssemblyGenerator, liveInfo);
    }
}

std::string IRImmediateValue::toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    std::string reg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back("li " + reg + ", " + reinterpret_cast<IRImmediateValue*>(this)->val);
    return reg;
}

std::string IRImmediateValue::toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    float fval = std::stof(reinterpret_cast<IRImmediateValue*>(this)->val);
    int dval = *(int*)&fval;
    std::string reg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back("li " + reg + ", " + std::to_string(dval));
    std::string fReg = AssemblyGenerator->getReg(true);
    AssemblyGenerator->asmCodeList.push_back("fmv.w.x " + fReg + ", " + reg);
    return fReg;
}

std::string IRImmediateValue::toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    AssemblyGenerator->asmDataList.push_back(".data");
    AssemblyGenerator->asmDataList.push_back(".align 3");
    AssemblyGenerator->asmDataList.push_back(std::string(".type IMM") + std::to_string(name) + std::string(", @object"));
    AssemblyGenerator->asmDataList.push_back(std::string(".size IMM") + std::to_string(name) + std::string(", 8"));
    AssemblyGenerator->asmDataList.push_back(std::string("IMM") + std::to_string(name) + std::string(":"));

    double fval = std::stod(val);
    long long dval = *(long long *)&fval;
    AssemblyGenerator->asmDataList.push_back(std::string(".dword ") + std::to_string(dval));

    std::string addrReg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back(std::string("la ") + addrReg + std::string(", IMM") + std::to_string(name));
    std::string fReg = AssemblyGenerator->getReg(true);
    AssemblyGenerator->asmCodeList.push_back(std::string("fld ") + fReg + std::string(", ") + std::string("0(") + addrReg + std::string(")"));
    return fReg;
}

void IRImmediateValue::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "$" << val;
}

//----------------- TemporaryValue ------------------------------------------------------------------
std::string TemporaryValue::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    switch(dataType) {
        case Type::INT:
            return toRegisterInt(AssemblyGenerator, liveInfo);
        case Type::FLOAT: case Type::DOUBLE: 
            return toRegisterFloat(AssemblyGenerator, liveInfo);
    }
}

std::string TemporaryValue::toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem)) {
            AssemblyGenerator->regDescriptorMap[reg]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string reg = AssemblyGenerator->getReg(false);
    //add map TempReg-->reg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(reg);
        AssemblyGenerator->regDescriptorMap[reg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return reg;
}

std::string TemporaryValue::toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    //search addrDescriptor
    AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(reinterpret_cast<IROperand*>(this));
    if (addrDescriptor->atReg.size() != 0) {
        std::string reg = addrDescriptor->atReg[0];
        if (liveInfo->usedInfo == nullptr && (!liveInfo->liveness || liveInfo->liveness && addrDescriptor->inMem)) {
            AssemblyGenerator->regDescriptorMap[reg]->ops.erase(reinterpret_cast<IROperand*>(this));
            addrDescriptor->atReg.clear();
        }
        return reg;
    }
    
    //not found
    std::string reg = AssemblyGenerator->getReg(true);
    //add map TempReg-->reg
    if (liveInfo->usedInfo != nullptr) {
        addrDescriptor->atReg.push_back(reg);
        AssemblyGenerator->regDescriptorMap[reg]->ops.insert(reinterpret_cast<IROperand*>(this));
    }
    
    return reg;
}

void TemporaryValue::printIR(std::ofstream &irCodeFile) {
    irCodeFile << "%" << name;
}

//----------------- IRArrayElem ------------------------------------------------------------------
std::string IRArrayElem::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    Type dataType;
    if (dynamic_cast<IrGlobalVariable*>(arrayPtr) != nullptr) 
        dataType = reinterpret_cast<IrGlobalVariable*>(arrayPtr)->dataType;
    else 
        dataType = reinterpret_cast<IRLocalVar*>(arrayPtr)->dataType;
    switch(dataType) {
        case Type::INT: case Type::INT_PTR: case Type::BOOL:
            return toRegisterInt(AssemblyGenerator, liveInfo);
        case Type::FLOAT: case Type::FLOAT_PTR:
            return toRegisterFloat(AssemblyGenerator, liveInfo);
        case Type::DOUBLE: case Type::DOUBLE_PTR:
            return toRegisterDouble(AssemblyGenerator, liveInfo);
    }
}

std::string IRArrayElem::toRegisterInt(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    if (dynamic_cast<IRLocalArray*>(arrayPtr) != nullptr) {
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string baseReg = AssemblyGenerator->getReg(false);
        AssemblyGenerator->asmCodeList.push_back(std::string("add ") + baseReg + std::string(", s0, ") + displaceReg);
        AssemblyGenerator->asmCodeList.push_back(std::string("lw ") + baseReg + std::string(", -") + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->offset) + std::string("(") + baseReg + std::string(")"));
        return baseReg;
    }
    else {
        std::string baseReg = arrayPtr->toRegister(AssemblyGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string addrReg = AssemblyGenerator->getReg(false);
        AssemblyGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseReg + ", " + displaceReg);
        AssemblyGenerator->asmCodeList.push_back("lw " + addrReg + ", " + "0(" + addrReg + ")");
        return addrReg;
    }
}

std::string IRArrayElem::toRegisterFloat(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    std::string valReg;
    if (dynamic_cast<IRLocalArray*>(arrayPtr) != nullptr) {
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string baseReg = AssemblyGenerator->getReg(false);
        valReg  = AssemblyGenerator->getReg(true);
        AssemblyGenerator->asmCodeList.push_back("add " + baseReg + "s0, " + displaceReg);
        AssemblyGenerator->asmCodeList.push_back("flw " + valReg + ", -" + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->offset) + "(" + baseReg + ")");
    }
    else {
        std::string baseReg = arrayPtr->toRegister(AssemblyGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string addrReg = AssemblyGenerator->getReg(false);
        valReg  = AssemblyGenerator->getReg(true);
        AssemblyGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseReg + ", " + displaceReg);
        AssemblyGenerator->asmCodeList.push_back("flw " + valReg + ", " + "0(" + addrReg + ")");
    }
    return valReg;
}

std::string IRArrayElem::toRegisterDouble(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    std::string valReg;
    if (dynamic_cast<IRLocalArray*>(arrayPtr) != nullptr) {
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string baseReg = AssemblyGenerator->getReg(false);
        valReg  = AssemblyGenerator->getReg(true);
        AssemblyGenerator->asmCodeList.push_back("add " + baseReg + "s0, " + displaceReg);
        AssemblyGenerator->asmCodeList.push_back("fld " + valReg + ", -" + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->offset) + "(" + baseReg + ")");
    }
    else {
        std::string baseReg = arrayPtr->toRegister(AssemblyGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string addrReg = AssemblyGenerator->getReg(false);
        valReg  = AssemblyGenerator->getReg(true);
        AssemblyGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseReg + ", " + displaceReg);
        AssemblyGenerator->asmCodeList.push_back("fld " + valReg + ", " + "0(" + addrReg + ")");
    }
    return valReg;
}

void IRArrayElem::toMem(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo, std::string srcReg) {
    std::string asmOpcode;
    Type dataType;
    if (dynamic_cast<IrGlobalVariable*>(arrayPtr) != nullptr) 
        dataType = reinterpret_cast<IrGlobalVariable*>(arrayPtr)->dataType;
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
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string baseReg = AssemblyGenerator->getReg(false);
        AssemblyGenerator->asmCodeList.push_back(std::string("add ") + baseReg + std::string(", s0, ") + displaceReg);
        AssemblyGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", -") + std::to_string(reinterpret_cast<IRLocalArray*>(arrayPtr)->offset) + "(" + baseReg + ")");
    }
    else {
        std::string baseReg = arrayPtr->toRegister(AssemblyGenerator, liveInfo->arrayInfo);
        std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
        std::string addrReg = AssemblyGenerator->getReg(false);
        AssemblyGenerator->asmCodeList.push_back(std::string("add ") + addrReg + std::string(", ") + baseReg + std::string(", ") + displaceReg);
        AssemblyGenerator->asmCodeList.push_back(asmOpcode + srcReg + std::string(", ") + std::string("0(") + addrReg + std::string(")"));
    }
}

void IRArrayElem::printIR(std::ofstream &irCodeFile) {
    arrayPtr->printIR(irCodeFile);
    irCodeFile << "<";
    tempPtr->printIR(irCodeFile);
}

LifetimeInfo* IRArrayElem::setLifetimeInfo(BasicBlock *basicBlock) {
    LifetimeInfo *ArrayLifetimeInfo = basicBlock->findLiveInfo(this->arrayPtr);
    LifetimeInfo *TempLifetimeInfo  = basicBlock->findLiveInfo(this->tempPtr);
    return new LifetimeInfo(ArrayLifetimeInfo, TempLifetimeInfo);
}

void IRArrayElem::calculateLiveness(BasicBlock *basicBlock, bool liveness, IntermediateCode *usedInfo) {
    arrayPtr->calculateLiveness(basicBlock, true, usedInfo);
    tempPtr->calculateLiveness(basicBlock, true, usedInfo);
}

IROperand *IRArrayElem::getSrc() {
    return arrayPtr;
}

IROperand *IRArrayElem::getDisplace() {
    return tempPtr;
}

//----------------- IRArrayAddr ------------------------------------------------------------------
std::string IRArrayAddr::toRegister(AssemblyCodeGenerator *AssemblyGenerator, LifetimeInfo *liveInfo) {
    std::string baseAddr = arrayPtr->toRegister(AssemblyGenerator, liveInfo->arrayInfo);
    std::string displaceReg = tempPtr->toRegister(AssemblyGenerator, liveInfo->tempInfo);
    std::string addrReg = AssemblyGenerator->getReg(false);
    AssemblyGenerator->asmCodeList.push_back("add " + addrReg + ", " + baseAddr + ", " + displaceReg);
    return addrReg;
}

void IRArrayAddr::printIR(std::ofstream &irCodeFile) {
    arrayPtr->printIR(irCodeFile);
    irCodeFile << ">";
    tempPtr->printIR(irCodeFile);
}

LifetimeInfo* IRArrayAddr::setLifetimeInfo(BasicBlock *basicBlock) {
    LifetimeInfo *ArrayLifetimeInfo = basicBlock->findLiveInfo(this->arrayPtr);
    LifetimeInfo *TempLifetimeInfo  = basicBlock->findLiveInfo(this->tempPtr);
    return new LifetimeInfo(ArrayLifetimeInfo, TempLifetimeInfo);
}

IROperand *IRArrayAddr::getSrc() {
    return arrayPtr;
}

IROperand *IRArrayAddr::getDisplace() {
    return tempPtr;
}

//----------------- IRLabel ------------------------------------------------------------------
void IRArrayAddr::calculateLiveness(BasicBlock *basicBlock, bool liveness, IntermediateCode *usedInfo) {
    arrayPtr->calculateLiveness(basicBlock, true, usedInfo);
    tempPtr->calculateLiveness(basicBlock, true, usedInfo);
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
LifetimeInfo* IROperand::setLifetimeInfo(BasicBlock *basicBlock) {
    return basicBlock->findLiveInfo(this);
}

void IROperand::calculateLiveness(BasicBlock *basicBlock, bool liveness, IntermediateCode *usedInfo) {
    basicBlock->livenessMap[this]  = new LifetimeInfo(liveness, usedInfo);
}

void IROperand::argReg(AssemblyCodeGenerator *AssemblyGenerator, int num, std::string srcReg) {
    std::string reg;
    std::string asmOpcode;
    if (dynamic_cast<IRArrayElem*>(this) != nullptr) {
        if (dynamic_cast<IrGlobalVariable*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr) != nullptr) {
            if (reinterpret_cast<IrGlobalVariable*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr)->dataType == FLOAT) {
                reg = "fa" + std::to_string(num);
                asmOpcode = "fmv.s ";
            }
            else if (reinterpret_cast<IrGlobalVariable*>(reinterpret_cast<IRArrayElem*>(this)->arrayPtr)->dataType == DOUBLE) {
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
    else if (dynamic_cast<IrGlobalVariable*>(this) != nullptr) {
        if (reinterpret_cast<IrGlobalVariable*>(this)->dataType == FLOAT) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.s ";
        }
        else if (reinterpret_cast<IrGlobalVariable*>(this)->dataType == DOUBLE) {
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
    else if (dynamic_cast<TemporaryValue*>(this) != nullptr) {
        if (reinterpret_cast<TemporaryValue*>(this)->dataType == FLOAT) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.s ";
        }
        else if (reinterpret_cast<TemporaryValue*>(this)->dataType == DOUBLE) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.d ";
        }
        else {
            reg = "a" + std::to_string(num);
            asmOpcode = "mv ";
        }
    }
    else if (dynamic_cast<IRImmediateValue*>(this) != nullptr) {
        if (reinterpret_cast<IRImmediateValue*>(this)->dataType == FLOAT) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.s ";
        }
        else if (reinterpret_cast<IRImmediateValue*>(this)->dataType == DOUBLE) {
            reg = "fa" + std::to_string(num);
            asmOpcode = "fmv.d ";
        }
        else {
            reg = "a" + std::to_string(num);
            asmOpcode = "mv ";
        }
    }
    AssemblyGenerator->asmCodeList.push_back(asmOpcode + reg + std::string(", ") + srcReg);
}
