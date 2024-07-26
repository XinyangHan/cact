#include "include/ir/Interpret.h"
#include "include/analysis/map.h"
#include "include/analysis/symTable.h"
#include <algorithm>
#include <iostream>

std::string printAny(std::any result) {
    std::string res;
    if (result.type() == typeid(int)) {
        res = std::to_string(std::any_cast<int>(result));
    }
    else if (result.type() == typeid(float)) {
        res = std::to_string(std::any_cast<float>(result));
    }
    else if (result.type() == typeid(double)) {
        res = std::to_string(std::any_cast<double>(result));
    }
    else {
        res = std::to_string(std::any_cast<bool>(result));
    }
    return res;
}

std::any operator+(const std::any& src1, const std::any& src2) {
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        int result = std::any_cast<int>(src1) + std::any_cast<int>(src2);
        return result;
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        float result = std::any_cast<float>(src1) + std::any_cast<float>(src2);
        return result;
    }
    else {
        double result = std::any_cast<double>(src1) + std::any_cast<double>(src2);
        return result;
    }
}

std::any operator-(const std::any& src1, const std::any& src2) {
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        int result = std::any_cast<int>(src1) - std::any_cast<int>(src2);
        return result;
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        float result = std::any_cast<float>(src1) - std::any_cast<float>(src2);
        return result;
    }
    else {
        double result = std::any_cast<double>(src1) - std::any_cast<double>(src2);
        return result;
    }
}

std::any operator*(const std::any& src1, const std::any& src2) {
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        int result = std::any_cast<int>(src1) * std::any_cast<int>(src2);
        return result;
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        float result = std::any_cast<float>(src1) * std::any_cast<float>(src2);
        return result;
    }
    else {
        double result = std::any_cast<double>(src1) * std::any_cast<double>(src2);
        return result;
    }
}

std::any operator/(const std::any& src1, const std::any& src2) {
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        int result = std::any_cast<int>(src1) / std::any_cast<int>(src2);
        return result;
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        float result = std::any_cast<float>(src1) / std::any_cast<float>(src2);
        return result;
    }
    else {
        double result = std::any_cast<double>(src1) / std::any_cast<double>(src2);
        return result;
    }
}

std::any operator!(const std::any& src1) {
    if (src1.type() == typeid(int)) {
        int result = -std::any_cast<int>(src1);
        return result;
    }
    else if (src1.type() == typeid(float)) {
        float result = -std::any_cast<float>(src1);
        return result;
    }
    else if (src1.type() == typeid(double)) {
        double result = -std::any_cast<double>(src1);
        return result;
    }
    else {
        bool result = (std::any_cast<bool>(src1) == false);
        return result;
    }
}

bool operator<(const std::any& src1, const std::any& src2) {
    bool result;
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        result = std::any_cast<int>(src1) < std::any_cast<int>(src2);
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        result = std::any_cast<float>(src1) < std::any_cast<float>(src2);
    }
    else {
        result = std::any_cast<double>(src1) < std::any_cast<double>(src2);
    }
    return result;
}

bool operator<=(const std::any& src1, const std::any& src2) {
    bool result;
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        result = std::any_cast<int>(src1) <= std::any_cast<int>(src2);
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        result = std::any_cast<float>(src1) <= std::any_cast<float>(src2);
    }
    else {
        result = std::any_cast<double>(src1) <= std::any_cast<double>(src2);
    }
    return result;
}

bool operator>(const std::any& src1, const std::any& src2) {
    bool result;
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        result = std::any_cast<int>(src1) > std::any_cast<int>(src2);
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        result = std::any_cast<float>(src1) > std::any_cast<float>(src2);
    }
    else {
        result = std::any_cast<double>(src1) > std::any_cast<double>(src2);
    }
    return result;
}

bool operator>=(const std::any& src1, const std::any& src2) {
    bool result;
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        result = std::any_cast<int>(src1) >= std::any_cast<int>(src2);
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        result = std::any_cast<float>(src1) >= std::any_cast<float>(src2);
    }
    else {
        result = std::any_cast<double>(src1) >= std::any_cast<double>(src2);
    }
    return result;
}

bool operator==(const std::any& src1, const std::any& src2) {
    bool result;
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        result = std::any_cast<int>(src1) == std::any_cast<int>(src2);
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        result = std::any_cast<float>(src1) == std::any_cast<float>(src2);
    }
    else {
        result = std::any_cast<double>(src1) == std::any_cast<double>(src2);
    }
    return result;
}

bool operator!=(const std::any& src1, const std::any& src2) {
    bool result;
    if (src1.type() == typeid(int) && src2.type() == typeid(int)) {
        result = std::any_cast<int>(src1) != std::any_cast<int>(src2);
    }
    else if (src1.type() == typeid(float) && src2.type() == typeid(float)) {
        result = std::any_cast<float>(src1) != std::any_cast<float>(src2);
    }
    else {
        result = std::any_cast<double>(src1) != std::any_cast<double>(src2);
    }
    return result;
}

void IntermediateCode::print(std::ofstream &irCodeFile) {
    switch(opCode) {
        case IR_G_ALLOC:
            irCodeFile << "IR_G_ALLOC ";
            irCodeFile << type2String[dataType] << ", ";
            reinterpret_cast<IrGlobalVariable*>(dst)->alloc = true;
            dst->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_L_ALLOC:
            irCodeFile << "IR_L_ALLOC ";
            irCodeFile << type2String[dataType] << ", ";
            reinterpret_cast<IRLocalVar*>(dst)->alloc = true;
            dst->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_LABEL:
            irCodeFile << "IR_LABEL ";
            dst->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_FUNC_START:
            irCodeFile << "IR_FUNC_START ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_FUNC_END:
            irCodeFile << "IR_FUNC_END ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << std::endl << std::endl;
            break;
        case IR_PARAM:
            irCodeFile << "IR_PARAM ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_CALL:
            irCodeFile << "IR_CALL ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            if (src1 != nullptr) {
                irCodeFile << ", ";
                src1->printIR(irCodeFile);
            }
            irCodeFile << std::endl;
            break;
        case IR_RETURN:
            irCodeFile << "IR_RETURN ";
            irCodeFile << type2String[dataType];
            if (dst != nullptr) {
                irCodeFile << ", ";
                dst->printIR(irCodeFile);
            }
            irCodeFile << std::endl;
            break;
        case IR_ASSIGN:
            irCodeFile << "IR_ASSIGN ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_ADD:
            irCodeFile << "IR_ADD ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_SUB:
            irCodeFile << "IR_SUB ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_MUL:
            irCodeFile << "IR_MUL ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_DIV:
            irCodeFile << "IR_DIV ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_MOD:
            irCodeFile << "IR_MOD ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_AND:
            irCodeFile << "IR_AND ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_OR:
            irCodeFile << "IR_OR ";
            irCodeFile << type2String[dataType] << " ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_NOT:
            irCodeFile << "IR_NOT ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_NEG:
            irCodeFile << "IR_NEG ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_SLT:
            irCodeFile << "IR_SLT ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_SLTE:
            irCodeFile << "IR_SLTE ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_BLT:
            irCodeFile << "IR_BLT ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_BLE:
            irCodeFile << "IR_BLE ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_BGT:
            irCodeFile << "IR_BGT ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_BGE:
            irCodeFile << "IR_BGE ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_BEQ:
            irCodeFile << "IR_BEQ ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_BNE:
            irCodeFile << "IR_BNE ";
            irCodeFile << type2String[dataType] << ", ";
            dst->printIR(irCodeFile);
            irCodeFile << ", ";
            src1->printIR(irCodeFile);
            irCodeFile << ", ";
            src2->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        case IR_GOTO:
            irCodeFile << "IR_GOTO ";
            dst->printIR(irCodeFile);
            irCodeFile << std::endl;
            break;
        default:
            break;
    }
}

void IntermediateCode::locateMainFunction(IntermediateInterpreter *irInterpretor, IntermediateCode **entryPoint) {
    switch(opCode) {
        case IR_G_ALLOC:
        {
            InterpretOperand *newIP;
            int len = reinterpret_cast<IrGlobalVariable*>(dst)->initVal.size();
            switch (dataType) {
                case INT:
                    newIP = new InterpretInt(len);
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        if(castImm->val[0] == '0' && (castImm->val[1] == 'x' || castImm->val[1] == 'X') || (castImm->val[0] == '-' && castImm->val[1] == '0' && (castImm->val[2] == 'x' || castImm->val[2] == 'X'))) {
                            reinterpret_cast<InterpretInt*>(newIP)->value.push_back(std::stoi(castImm->val, 0, 16));
                        }
                        else if(castImm->val[0] == '0' || (castImm->val[0] == '-' && castImm->val[1] == '0')){
                            reinterpret_cast<InterpretInt*>(newIP)->value.push_back(std::stoi(castImm->val, 0, 8));
                        }
                        else {
                            reinterpret_cast<InterpretInt*>(newIP)->value.push_back(std::stoi(castImm->val));
                        }
                    }
                    break;
                case FLOAT: 
                    newIP = new InterpretFloat(len);
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        reinterpret_cast<InterpretFloat*>(newIP)->value.push_back(std::stof(castImm->val));
                    }
                    break;
                case DOUBLE:
                    newIP = new InterpretDouble(len);
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        reinterpret_cast<InterpretDouble*>(newIP)->value.push_back(std::stod(castImm->val));
                    }
                    break;
                default:
                    newIP = new InterpretBool(len);
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        reinterpret_cast<InterpretBool*>(newIP)->value.push_back(castImm->val == "true");
                    }
                    break;
            }
            irInterpretor->globlMap[dst] = newIP;
            break;
        }
        case IR_FUNC_START:
        {
            if (reinterpret_cast<IRFunc*>(dst)->funcSymbol->getSymbolName() == "main") {
                *entryPoint = this;
                irInterpretor->funcMap[reinterpret_cast<IRFunc*>(dst)->funcSymbol] = this;
            }
            else {
                irInterpretor->funcMap[reinterpret_cast<IRFunc*>(dst)->funcSymbol] = this;
            }
            break;
        }
        case IR_LABEL:
        {
            irInterpretor->labelMap[dst] = this;
            break;
        }
        default:
        {
            break;
        }
    }
}

IntermediateCode *IntermediateCode::interpretIntermediateCode(std::ofstream &interpretFile, IntermediateInterpreter *irInterpretor) {
    IROperand *operand1, *operand2;
    IROperand *displace1, *displace2;
    int displaceNum1 = 0, displaceNum2 = 0;
    InterpretOperand *newIP;
    std::any r1, r2, result;
    
    switch(opCode) {
        case IR_L_ALLOC:
        {
            InterpretOperand *newIP;
            int len = reinterpret_cast<IRLocalVar*>(dst)->initVal.size();
            switch(dataType) {
                case INT:
                    newIP = new InterpretInt(len);
                    for(int i = 0; i < len; i++) {
                        IRLocalVar  *castDst = reinterpret_cast<IRLocalVar*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        if(castImm->val[0] == '0' && (castImm->val[1] == 'x' || castImm->val[1] == 'X') || (castImm->val[0] == '-' && castImm->val[1] == '0' && (castImm->val[2] == 'x' || castImm->val[2] == 'X'))) {
                            reinterpret_cast<InterpretInt*>(newIP)->value.push_back(std::stoi(castImm->val, 0, 16));
                        }
                        else if(castImm->val[0] == '0' || (castImm->val[0] == '-' && castImm->val[1] == '0')){
                            reinterpret_cast<InterpretInt*>(newIP)->value.push_back(std::stoi(castImm->val, 0, 8));
                        }
                        else {
                            reinterpret_cast<InterpretInt*>(newIP)->value.push_back(std::stoi(castImm->val));
                        }
                    }
                    break;
                case FLOAT:
                    newIP = new InterpretFloat(len);
                    for(int i = 0; i < len; i++) {
                        IRLocalVar  *castDst = reinterpret_cast<IRLocalVar*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        reinterpret_cast<InterpretFloat*>(newIP)->value.push_back(std::stof(castImm->val));
                    }
                    break;
                case DOUBLE: 
                    newIP = new InterpretDouble(len);
                    for(int i = 0; i < len; i++) {
                        IRLocalVar  *castDst = reinterpret_cast<IRLocalVar*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        reinterpret_cast<InterpretDouble*>(newIP)->value.push_back(std::stod(castImm->val));
                    }
                    break;
                default:
                    newIP = new InterpretBool(len);
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        reinterpret_cast<InterpretBool*>(newIP)->value.push_back(castImm->val == "true");
                    }
                    break;
            }
            irInterpretor->currStack->interpretMap[dst] = newIP;
            irInterpretor->currStack->baseMap[dst] = 0;
            return nextIR;
        }
        case IR_ADD:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            std::any result = r1 + r2;
            newIP = new InterpretTemp(result);
            irInterpretor->currStack->interpretMap[dst] = newIP;
            irInterpretor->currStack->baseMap[dst] = 0;
            
            //for debug
            dst->printIR(interpretFile);
            interpretFile << " = " << printAny(result) << std::endl;
            return nextIR;
        }
        case IR_SUB:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            std::any result = r1 - r2;
            newIP = new InterpretTemp(result);
            irInterpretor->currStack->interpretMap[dst] = newIP;
            irInterpretor->currStack->baseMap[dst] = 0;
            
            //for debug
            dst->printIR(interpretFile);
            interpretFile << " = " << printAny(result) << std::endl;
            return nextIR;
        }
        case IR_MUL:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            std::any result = r1 * r2;
            newIP = new InterpretTemp(result);
            irInterpretor->currStack->interpretMap[dst] = newIP;
            irInterpretor->currStack->baseMap[dst] = 0;
            
            //for debug
            dst->printIR(interpretFile);
            interpretFile << " = " << printAny(result) << std::endl;
            return nextIR;
        }
        case IR_DIV:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            std::any result = r1 / r2;
            newIP = new InterpretTemp(result);
            irInterpretor->currStack->interpretMap[dst] = newIP;
            irInterpretor->currStack->baseMap[dst] = 0;
            
            //for debug
            dst->printIR(interpretFile);
            interpretFile << " = " << printAny(result) << std::endl;
            return nextIR;
        }
        case IR_NEG: case IR_NOT:
        {
            operand1  = src1->getSrc();
            displace1 = src1->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            std::any result = !r1;
            newIP = new InterpretTemp(result);
            irInterpretor->currStack->interpretMap[dst] = newIP;
            irInterpretor->currStack->baseMap[dst] = 0;
            
            //for debug
            dst->printIR(interpretFile);
            interpretFile << " = " << printAny(result) << std::endl;
            return nextIR;
        }
        case IR_BLT:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            bool cond   = r1 < r2;
            if (!cond) {
                return nextIR;
            }
            else {
                //for debug
                interpretFile << "goto "; 
                dst->printIR(interpretFile); 
                interpretFile << std::endl;
                return irInterpretor->labelMap[dst];
            }
        }
        case IR_BLE:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            bool cond   = r1 <= r2;
            if (!cond) {
                return nextIR;
            }
            else {
                //for debug
                interpretFile << "goto "; 
                dst->printIR(interpretFile); 
                interpretFile << std::endl;
                return irInterpretor->labelMap[dst];
            }
        }
        case IR_BGT:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            bool cond   = r1 > r2;
            if (!cond) {
                return nextIR;
            }
            else {
                //for debug
                interpretFile << "goto "; 
                dst->printIR(interpretFile); 
                interpretFile << std::endl;
                return irInterpretor->labelMap[dst];
            }
        }
        case IR_BGE:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            bool cond   = r1 >= r2;
            if (!cond) {
                return nextIR;
            }
            else {
                //for debug
                interpretFile << "goto "; 
                dst->printIR(interpretFile); 
                interpretFile << std::endl;
                return irInterpretor->labelMap[dst];
            }
        }
        case IR_BEQ:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            bool cond   = r1 == r2;
            if (!cond) {
                return nextIR;
            }
            else {
                //for debug
                interpretFile << "goto "; 
                dst->printIR(interpretFile); 
                interpretFile << std::endl;
                return irInterpretor->labelMap[dst];
            }
        }
        case IR_BNE:
        {
            operand1  = src1->getSrc();
            operand2  = src2->getSrc();   
            displace1 = src1->getDisplace();
            displace2 = src2->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                r1 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                r1 = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                r2 = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                r2 = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            bool cond   = r1 != r2;
            if (!cond) {
                return nextIR;
            }
            else {
                //for debug
                interpretFile << "goto "; 
                dst->printIR(interpretFile); 
                interpretFile << std::endl;
                return irInterpretor->labelMap[dst];
            }
        }
        case IR_GOTO:
        {
            //for debug
            interpretFile << "goto "; 
            dst->printIR(interpretFile); 
            interpretFile << std::endl;
            return irInterpretor->labelMap[dst];
        }
        case IR_ASSIGN:
        {
            operand1  = dst->getSrc();
            operand2  = src1->getSrc();
            displace1 = dst->getDisplace();
            displace2 = src1->getDisplace();
            if (displace1 != nullptr) {
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (displace2 != nullptr) {
                displaceNum2 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace2]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand2) != nullptr) {
                result = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand2])->getValue();
            }
            else {
                result = irInterpretor->currStack->interpretMap[operand2]->getValue(displaceNum2, irInterpretor->currStack->baseMap[operand2]);
            }
            irInterpretor->currStack->interpretMap[operand1]->setValue(result, displaceNum1, irInterpretor->currStack->baseMap[operand1]);
            
            //for debug
            dst->printIR(interpretFile);
            interpretFile << " = " << printAny(result) << std::endl;
            return nextIR;
        }
        case IR_PARAM:
        {
            operand1  = dst->getSrc();
            displace1 = dst->getDisplace();
            if (displace1 != nullptr) {
                if (dynamic_cast<IRArrayAddr*>(dst) != nullptr) {
                    irInterpretor->currStack->realParamList.push_back(dst);
                    return nextIR;
                }
                displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
            }
            if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                result = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
            }
            else {
                auto tmp = irInterpretor->currStack->interpretMap[operand1];
                auto base = irInterpretor->currStack->baseMap[operand1];
                result = tmp->getValue(displaceNum1, base);
            }
            irInterpretor->currStack->realParamList.push_back(result);
            return nextIR;
        }
        case IR_CALL:
        {
            InterpretOperand *newInterpretTemp = nullptr;
            //libfunc
            std::string funcName = reinterpret_cast<IRFunc*>(dst)->funcSymbol->getSymbolName();
            
            if (funcName == "get_int") {
                int input;
                std::cin >> input;
                newInterpretTemp = new InterpretTemp(input);
                irInterpretor->currStack->interpretMap[src1] = newInterpretTemp;
                return nextIR;
            }
            else if (funcName == "get_float") {
                float input;
                std::cin >> input;
                newInterpretTemp = new InterpretTemp(input);
                irInterpretor->currStack->interpretMap[src1] = newInterpretTemp;
                return nextIR;
            }
            else if (funcName == "get_double") {
                double input;
                std::cin >> input;
                newInterpretTemp = new InterpretTemp(input);
                irInterpretor->currStack->interpretMap[src1] = newInterpretTemp;
                return nextIR;
            }
            else if (funcName == "print_bool") {
                bool output = std::any_cast<bool>(irInterpretor->currStack->realParamList[0]);
                std::cout << output << std::endl;
                irInterpretor->currStack->realParamList.clear();
                return nextIR;
            }
            else if (funcName == "print_int") {
                int output = std::any_cast<int>(irInterpretor->currStack->realParamList[0]);
                std::cout << output << std::endl;
                irInterpretor->currStack->realParamList.clear();
                return nextIR;
            }
            else if (funcName == "print_float") {
                float output = std::any_cast<float>(irInterpretor->currStack->realParamList[0]);
                std::cout << output << std::endl;
                irInterpretor->currStack->realParamList.clear();
                return nextIR;
            }
            else if (funcName == "print_double") {
                double output = std::any_cast<double>(irInterpretor->currStack->realParamList[0]);
                std::cout << output << std::endl;
                irInterpretor->currStack->realParamList.clear();
                return nextIR;    
            }
            
            if (src1 != nullptr) {
                newInterpretTemp = new InterpretTemp(0);
                irInterpretor->currStack->interpretMap[src1] = newInterpretTemp;
            }
            irInterpretor->currStack->calleeReturnVal  = newInterpretTemp;
            irInterpretor->currStack->calleeReturnAddr = nextIR; 
            return irInterpretor->funcMap[reinterpret_cast<IRFunc*>(dst)->funcSymbol];
        }
        case IR_FUNC_START:
        {
            //for debug
            interpretFile << "invoke " << reinterpret_cast<IRFunc*>(dst)->funcSymbol->getSymbolName() << std::endl;
            
            irInterpretor->currStack = new IntermediateStack(irInterpretor->currStack);
            for (auto it = irInterpretor->globlMap.begin(); it != irInterpretor->globlMap.end(); it++) {
                irInterpretor->currStack->interpretMap[it->first] = it->second;
                irInterpretor->currStack->baseMap[it->first] = 0;
            }
            std::vector<ValSymbol*> fParamList = reinterpret_cast<IRFunc*>(dst)->funcSymbol->getParams();
            for (int i = 0; i < fParamList.size(); i++) {
                IROperand *operand = fParamList[i]->getIROperand();
                IROperand *param;
                switch(operand->opDataType) {
                    case BOOL:
                        irInterpretor->currStack->interpretMap[operand] = new InterpretBool(1, irInterpretor->currStack->preStack->realParamList[i]);
                        irInterpretor->currStack->baseMap[operand] = 0;
                        break;
                    case INT:
                        irInterpretor->currStack->interpretMap[operand] = new InterpretInt(1, irInterpretor->currStack->preStack->realParamList[i]);
                        irInterpretor->currStack->baseMap[operand] = 0;
                        break;
                    case FLOAT:
                        irInterpretor->currStack->interpretMap[operand] = new InterpretFloat(1, irInterpretor->currStack->preStack->realParamList[i]);
                        irInterpretor->currStack->baseMap[operand] = 0;
                        break;
                    case DOUBLE:
                        irInterpretor->currStack->interpretMap[operand] = new InterpretDouble(1, irInterpretor->currStack->preStack->realParamList[i]);
                        irInterpretor->currStack->baseMap[operand] = 0;
                    case INT_PTR: case FLOAT_PTR: case DOUBLE_PTR:
                    {
                        param = std::any_cast<IROperand*>(irInterpretor->currStack->preStack->realParamList[i]);
                        irInterpretor->currStack->interpretMap[operand] = irInterpretor->currStack->preStack->interpretMap[reinterpret_cast<IRArrayAddr*>(param)->arrayPtr];
                        int base = std::any_cast<int>(irInterpretor->currStack->preStack->interpretMap[reinterpret_cast<IRArrayAddr*>(param)->tempPtr]->getValue(0, 0));
                        irInterpretor->currStack->baseMap[operand] = irInterpretor->currStack->preStack->baseMap[reinterpret_cast<IRArrayAddr*>(param)->arrayPtr] + base;
                        break;
                    }
                    default:
                        break;
                }
            }
            irInterpretor->currStack->preStack->realParamList.clear();
            return nextIR;
        }
        case IR_RETURN: case IR_FUNC_END:
        {
            //for debug
            interpretFile << "return ";
            
            if (opCode != IR_FUNC_END && dst != nullptr) {
                operand1  = dst->getSrc();
                displace1 = dst->getDisplace();
                if (displace1 != nullptr) {
                    displaceNum1 = std::any_cast<int>(irInterpretor->currStack->interpretMap[displace1]->getValue(0, 0));
                }
                if (dynamic_cast<IRImmediateValue*>(operand1) != nullptr) {
                    result = reinterpret_cast<InterpretImm*>(irInterpretor->immMap[operand1])->getValue();
                }
                else {
                    result = irInterpretor->currStack->interpretMap[operand1]->getValue(displaceNum1, irInterpretor->currStack->baseMap[operand1]);
                }
                reinterpret_cast<InterpretTemp*>(irInterpretor->currStack->preStack->calleeReturnVal)->value = result;
                interpretFile << printAny(result);
            }
            interpretFile << std::endl;
            irInterpretor->currStack = irInterpretor->currStack->preStack;
            return irInterpretor->currStack->calleeReturnAddr;
        }
        default:
            return nextIR;
    }
}

void IntermediateCode::createDAG(BasicBlock *basicBlock) {
    switch(opCode) {
        DagNode *node1;
        DagNode *node2;
        
        case IR_G_ALLOC: case IR_L_ALLOC: case IR_LABEL:
        case IR_FUNC_START: case IR_FUNC_END: case IR_PARAM:
        case IR_CALL: case IR_GOTO: case IR_RETURN:
            basicBlock->dagNodeList.push_back(new DagOtherNode(this, opCode, basicBlock));
            break;
        case IR_ASSIGN:
        {
            auto it = basicBlock->operand2DagNode.find(dst);
            if (it != basicBlock->operand2DagNode.end()) {
                it->second->relatedSet.erase(dst);
            }
            node1 = basicBlock->findDagNode(src1);
            if (dynamic_cast<IRArrayElem*>(dst) != nullptr) {
                auto newDagNode = new DagInnerNode(dataType, opCode, node1, nullptr);
                newDagNode->basicBlock = basicBlock;
                basicBlock->operand2DagNode.insert({dst, newDagNode});
                newDagNode->relatedSet.insert(dst);
                basicBlock->dagNodeList.push_back(newDagNode);
                newDagNode->isArray = true;
                return ;
            }
            for (auto dagNode : basicBlock->dagNodeList) {
                if (dagNode->opCode == opCode && node1 == dagNode->lchild && !reinterpret_cast<DagInnerNode*>(dagNode)->isArray) {
                    basicBlock->operand2DagNode.erase(dst);
                    basicBlock->operand2DagNode.insert({dst, dagNode});
                    dagNode->relatedSet.insert(dst);
                    return ;
                }
            }
            auto newDagNode = new DagInnerNode(dataType, opCode, node1, nullptr);
            newDagNode->basicBlock = basicBlock;
            basicBlock->operand2DagNode[dst] = newDagNode;
            newDagNode->relatedSet.insert(dst);
            basicBlock->dagNodeList.push_back(newDagNode);
            break;
        }
        case IR_ADD: case IR_SUB: case IR_MUL:
        case IR_DIV: case IR_MOD: case IR_AND:
        case IR_OR:  case IR_SLT: case IR_SLTE:
        {
            node1 = basicBlock->findDagNode(src1);
            node2 = basicBlock->findDagNode(src2);
            for (auto dagNode : basicBlock->dagNodeList) {
                if (dagNode->opCode == opCode && node1 == dagNode->lchild && node2 == dagNode->rchild) {
                    basicBlock->operand2DagNode.insert({dst, dagNode});
                    dagNode->relatedSet.insert(dst);
                    return ;
                }
            }
            auto newDagNode = new DagInnerNode(dataType, opCode, node1, node2);
            newDagNode->basicBlock = basicBlock;
            basicBlock->operand2DagNode.insert({dst, newDagNode});
            newDagNode->relatedSet.insert(dst);
            basicBlock->dagNodeList.push_back(newDagNode);
            break;
        }
        case IR_NOT: case IR_NEG:
        {
            node1 = basicBlock->findDagNode(src1);
            for (auto dagNode : basicBlock->dagNodeList) {
                if (dagNode->opCode == opCode && node1 == dagNode->lchild) {
                    basicBlock->operand2DagNode.insert({dst, dagNode});
                    dagNode->relatedSet.insert(dst);
                    return ;
                }
            }
            auto newDagNode = new DagInnerNode(dataType, opCode, node1, nullptr);
            newDagNode->basicBlock = basicBlock;
            basicBlock->operand2DagNode.insert({dst, newDagNode});
            newDagNode->relatedSet.insert(dst);
            basicBlock->dagNodeList.push_back(newDagNode);
            break;
        }
        case IR_BLT: case IR_BLE: case IR_BGT:
        case IR_BGE: case IR_BEQ: case IR_BNE:
        {
            node1 = basicBlock->findDagNode(src1);
            node2 = basicBlock->findDagNode(src2);
            auto newDagNode = new DagInnerNode(dataType, opCode, node1, node2);
            newDagNode->basicBlock = basicBlock;
            newDagNode->label = dst;
            basicBlock->dagNodeList.push_back(newDagNode);
            break;
        }
    }
}

void IntermediateCode::calculateLiveness(BasicBlock *basicBlock) {
    switch(opCode) {
        case IR_ADD: case IR_SUB: case IR_MUL:
        case IR_DIV: case IR_MOD: case IR_AND:
        case IR_OR:  case IR_SLT: case IR_SLTE:
        {
            dstInfo  = dst->setLifetimeInfo(basicBlock);
            src1Info = src1->setLifetimeInfo(basicBlock);
            src2Info = src2->setLifetimeInfo(basicBlock);
            
            dst->calculateLiveness(basicBlock, false, nullptr);
            src1->calculateLiveness(basicBlock, true, this);
            src2->calculateLiveness(basicBlock, true, this);
            break;
        }
        case IR_NOT: case IR_NEG: case IR_ASSIGN:
        {
            dstInfo  = dst->setLifetimeInfo(basicBlock);
            src1Info = src1->setLifetimeInfo(basicBlock);
            
            if (dynamic_cast<IRArrayElem*>(dst) != nullptr) {
                dst->calculateLiveness(basicBlock, false, this);
            }
            else {
                dst->calculateLiveness(basicBlock, false, nullptr);
            }
            src1->calculateLiveness(basicBlock, true, this);
            break;
        }
        case IR_G_ALLOC: case IR_L_ALLOC:
        {
            dstInfo = dst->setLifetimeInfo(basicBlock);
            break;
        }
        case IR_PARAM:
        {
            dstInfo = dst->setLifetimeInfo(basicBlock);
            dst->calculateLiveness(basicBlock, true, this);
            break;
        }
        case IR_CALL:
        {
            if (src1 != nullptr)
                src1->setLifetimeInfo(basicBlock);
            break;
        }
        case IR_BLT: case IR_BLE: case IR_BGT:
        case IR_BGE: case IR_BEQ: case IR_BNE:
        {
            src1Info = src1->setLifetimeInfo(basicBlock);
            src2Info = src2->setLifetimeInfo(basicBlock);
            
            src1->calculateLiveness(basicBlock, true, this);
            src2->calculateLiveness(basicBlock, true, this);
            break;
        }
        case IR_RETURN:
        {
            if (dst != nullptr) {
                dstInfo  = dst->setLifetimeInfo(basicBlock);
                dst->calculateLiveness(basicBlock, true, this);
            }
            break;
        }
        default:
            break;
    }
}

void IntermediateCode::calculateStackOffset(AssemblyCodeGenerator *AssemblyGenerator) {
    int alignSize;
    int byteSize;
    switch(opCode) {
        case IR_FUNC_START:
        {
            if (AssemblyGenerator->opt == 1)
                AssemblyGenerator->stackFrame = 48;
            else
                AssemblyGenerator->stackFrame = 104;
            for (auto param : reinterpret_cast<IRFunc*>(dst)->funcSymbol->getParams()) {
                switch(reinterpret_cast<IRLocalVar*>(param->getIROperand())->dataType) {
                    case BOOL:
                        alignSize = 4;
                        break;
                    case INT: case FLOAT:
                        alignSize = 4;
                        break;
                    case INT_PTR: case FLOAT_PTR:
                    case DOUBLE:  case DOUBLE_PTR:
                        alignSize = 8;
                        break;
                }  
                AssemblyGenerator->stackFrame = AssemblyGenerator->roundUp(AssemblyGenerator->stackFrame, alignSize);  
                AssemblyGenerator->stackFrame += alignSize;  
                reinterpret_cast<IRLocalVar*>(param->getIROperand())->offset = AssemblyGenerator->stackFrame;
            }
            break;
        }
        case IR_L_ALLOC:
        {
            switch(reinterpret_cast<IRLocalVar*>(dst)->dataType) {
                case BOOL:
                    alignSize = 4;
                    byteSize  = 4;
                    break;
                case INT: case FLOAT:
                    alignSize = 4;
                    byteSize  = 4;
                    break;
                case DOUBLE:
                    alignSize = 8;
                    byteSize  = 8;
                    break;
            }      
            if (reinterpret_cast<IRLocalVar*>(dst)->len > 1) {
                alignSize = 8;
            }
            AssemblyGenerator->stackFrame += byteSize * reinterpret_cast<IRLocalVar*>(dst)->len;
            AssemblyGenerator->stackFrame = AssemblyGenerator->roundUp(AssemblyGenerator->stackFrame, alignSize);
            reinterpret_cast<IRLocalVar*>(dst)->offset = AssemblyGenerator->stackFrame;             
            break;
        }
        case IR_FUNC_END:
        {
            AssemblyGenerator->stackFrame = AssemblyGenerator->roundUp(AssemblyGenerator->stackFrame, 16);
            reinterpret_cast<IRFunc*>(dst)->stackSize = AssemblyGenerator->stackFrame;
            break;
        }
        default:
            break;
    }
}

void IntermediateCode::generateAssembly(AssemblyCodeGenerator *AssemblyGenerator) {
    //std::ofstream asmdebug;
    //asmdebug.open("./asmdebug.S");
    //AssemblyGenerator->printAssemblycode(asmdebug);
    //asmdebug.close();
    std::string asmOpCode;
    std::string tmp;
    switch(opCode) {
        case IR_G_ALLOC:
        {
            AssemblyGenerator->asmDataList.push_back(std::string(".globl ") + std::string("GVar") + std::to_string(reinterpret_cast<IrGlobalVariable*>(dst)->name));
            if (dst->zero)
                AssemblyGenerator->asmDataList.push_back(".bss");
            else
                AssemblyGenerator->asmDataList.push_back(".data");
            int len = reinterpret_cast<IrGlobalVariable*>(dst)->len;
            int alignSize;
            int dataLen;
            switch (reinterpret_cast<IrGlobalVariable*>(dst)->dataType) {
                case INT: case FLOAT:
                    alignSize = 2;
                    dataLen = 4;
                    break;
                case DOUBLE:
                    alignSize = 3;
                    dataLen = 8;
                    break;
                case BOOL:
                    alignSize = 1;
                    dataLen = 1;
                    break;
            }
            if (len > 1)
                alignSize = 3;
            AssemblyGenerator->asmDataList.push_back(std::string(".align") + std::string(" ") + std::to_string(alignSize));
            AssemblyGenerator->asmDataList.push_back(std::string(".type GVar") + std::to_string(reinterpret_cast<IrGlobalVariable*>(dst)->name) + std::string(", @object"));
            AssemblyGenerator->asmDataList.push_back(std::string(".size GVar") + std::to_string(reinterpret_cast<IrGlobalVariable*>(dst)->name) + std::string(", ") + std::to_string(len * dataLen));
            AssemblyGenerator->asmDataList.push_back(std::string("GVar") + std::to_string(reinterpret_cast<IrGlobalVariable*>(dst)->name) + std::string(":"));
            if (dst->zero) {
                AssemblyGenerator->asmDataList.push_back(std::string(".zero ") + std::to_string(len * dataLen) + std::string("\n"));
                return;
            }
            
            switch(dataType) {
                case INT:
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        AssemblyGenerator->asmDataList.push_back(std::string(".word ") + std::string(castImm->val));
                    }
                    break;
                case FLOAT:
                {
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        float fval = std::stof(castImm->val);
                        int dval = *(int *)&fval;
                        AssemblyGenerator->asmDataList.push_back(std::string(".word ") + std::to_string(dval));
                    }
                    break;
                }
                case DOUBLE:
                { 
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        double fval = std::stod(castImm->val);
                        long long dval = *(long long *)&fval;
                        AssemblyGenerator->asmDataList.push_back(std::string(".dword ") + std::to_string(dval));
                    }
                    break;
                }
                case BOOL:
                {
                    for(int i = 0; i < len; i++) {
                        IrGlobalVariable  *castDst = reinterpret_cast<IrGlobalVariable*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        if (castImm->val == "true")
                            AssemblyGenerator->asmDataList.push_back(std::string(".word ") + std::string("1"));
                        else
                            AssemblyGenerator->asmDataList.push_back(std::string(".word ") + std::string("0"));
                    }
                    break;
                }
            }
            break;  
        }
        case IR_L_ALLOC:
        {
            int len = reinterpret_cast<IRLocalVar*>(dst)->len;
            int dataLen;
            int alignSize;
            if (dataType == INT) {
                std::string valReg = AssemblyGenerator->getReg(false);
                for(int i = 0; i < len; i++) {
                    IRLocalVar  *castDst = reinterpret_cast<IRLocalVar*>(dst);
                    IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                    AssemblyGenerator->asmCodeList.push_back(std::string("li ") + valReg + std::string(", ") + castImm->val);
                    AssemblyGenerator->asmCodeList.push_back(std::string("sw ") + valReg + std::string(", ") + std::to_string(i*4-reinterpret_cast<IRLocalVar*>(dst)->offset) + std::string("(s0)"));
                }
                return;
            }
            
            AssemblyGenerator->asmDataList.push_back(".data");
            switch (reinterpret_cast<IRLocalVar*>(dst)->dataType) {
                case FLOAT:
                    alignSize = 2;
                    dataLen = 4;
                    break;
                case DOUBLE:
                    alignSize = 3;
                    dataLen = 8;
                    break;
                case BOOL:
                    alignSize = 1;
                    dataLen = 1;
                    break;
            }
            if (len > 1)
                alignSize = 3;
            AssemblyGenerator->asmDataList.push_back(std::string(".align ") + std::to_string(alignSize));
            AssemblyGenerator->asmDataList.push_back(std::string(".type LVar") + std::to_string(reinterpret_cast<IRLocalVar*>(dst)->name) + std::string(", @object"));
            AssemblyGenerator->asmDataList.push_back(std::string(".size LVar") + std::to_string(reinterpret_cast<IRLocalVar*>(dst)->name) + std::string(", ") + std::to_string(len * dataLen));
            AssemblyGenerator->asmDataList.push_back(std::string("LVar") + std::to_string(reinterpret_cast<IRLocalVar*>(dst)->name) + std::string(":"));
            
            switch(dataType) {
                case FLOAT:
                {
                    for(int i = 0; i < len; i++) {
                        IRLocalVar  *castDst = reinterpret_cast<IRLocalVar*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        float fval = std::stof(castImm->val);
                        int dval = *(int *)&fval;
                        AssemblyGenerator->asmDataList.push_back(std::string(".word ") + std::to_string(dval));
                    }
                    break;
                }
                case DOUBLE:
                { 
                    for(int i = 0; i < len; i++) {
                        IRLocalVar  *castDst = reinterpret_cast<IRLocalVar*>(dst);
                        IRImmediateValue *castImm = reinterpret_cast<IRImmediateValue*>(castDst->initVal[i]);
                        double fval = std::stod(castImm->val);
                        long long dval = *(long long *)&fval;
                        AssemblyGenerator->asmDataList.push_back(std::string(".dword ") + std::to_string(dval));
                    }
                    break;
                }
            }
            
            std::string addrReg = AssemblyGenerator->getReg(false);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = addrReg;
            std::string valReg  = AssemblyGenerator->getReg(false);
            AssemblyGenerator->regConfig = false;
            AssemblyGenerator->asmCodeList.push_back(std::string("la ") + addrReg + ", LVar" + std::to_string(reinterpret_cast<IRLocalVar*>(dst)->name)); 
            int totalByte = len * dataLen;
            int doneByte  = 0;
            int leftByte;
            while (doneByte < totalByte) {
                leftByte = totalByte - doneByte;
                if (leftByte >= 8) {
                    AssemblyGenerator->asmCodeList.push_back(std::string("ld ") + valReg + std::string(", ") + std::to_string(doneByte) + std::string("(") + addrReg + std::string(")"));
                    AssemblyGenerator->asmCodeList.push_back(std::string("sd ") + valReg + std::string(", ") + std::to_string(doneByte-reinterpret_cast<IRLocalVar*>(dst)->offset) + std::string("(s0)"));
                    doneByte += 8;
                }
                else if (leftByte == 4) {
                    AssemblyGenerator->asmCodeList.push_back(std::string("lw ") + valReg + std::string(", ") + std::to_string(doneByte) + std::string("(") + addrReg + std::string(")"));
                    AssemblyGenerator->asmCodeList.push_back(std::string("sw ") + valReg + std::string(", ") + std::to_string(doneByte-reinterpret_cast<IRLocalVar*>(dst)->offset) + std::string("(s0)"));
                    doneByte += 4;
                }
            }
            break; 
        }
        case IR_FUNC_START:
        {
            AssemblyGenerator->asmCodeList.push_back(".text");
            AssemblyGenerator->asmCodeList.push_back(".align 2");
            AssemblyGenerator->asmCodeList.push_back(".global " + reinterpret_cast<IRFunc*>(dst)->funcSymbol->getSymbolName());
            AssemblyGenerator->asmCodeList.push_back(".type " + reinterpret_cast<IRFunc*>(dst)->funcSymbol->getSymbolName() + ", @function");
            AssemblyGenerator->asmCodeList.push_back(reinterpret_cast<IRFunc*>(dst)->funcSymbol->getSymbolName() + ":");
            AssemblyGenerator->stackSize = reinterpret_cast<IRFunc*>(dst)->stackSize;
            AssemblyGenerator->asmCodeList.push_back(std::string("addi sp, sp, ") + std::to_string(-AssemblyGenerator->stackSize));
            AssemblyGenerator->asmCodeList.push_back(std::string("sd s0, ") + std::to_string(AssemblyGenerator->stackSize-8) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("sd ra, ") + std::to_string(AssemblyGenerator->stackSize-16) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("sd s1, ") + std::to_string(AssemblyGenerator->stackSize-24) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("sd s2, ") + std::to_string(AssemblyGenerator->stackSize-32) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("sd s3, ") + std::to_string(AssemblyGenerator->stackSize-40) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("sd s4, ") + std::to_string(AssemblyGenerator->stackSize-48) + std::string("(sp)"));
            if (AssemblyGenerator->opt == 0){
                for (int i = 5; i < 12; i++)
                    AssemblyGenerator->asmCodeList.push_back(std::string("sd s") + std::to_string(i) + std::string(", ") + std::to_string(AssemblyGenerator->stackSize-16-8*i) + std::string("(sp)"));
            }
            AssemblyGenerator->asmCodeList.push_back(std::string("addi s0, ") + std::string("sp, ") + std::to_string(AssemblyGenerator->stackSize));
            AssemblyGenerator->paramCount = 0;
            std::string paramReg;
            AssemblyGenerator->addrDescriptorMap.clear();
            for (auto param : reinterpret_cast<IRFunc*>(dst)->funcSymbol->getParams()) {
                AddrDescriptor *newAddrDes = AssemblyGenerator->searchAddrDescriptorMap(param->getIROperand());
                newAddrDes->isArg = true;
                if (reinterpret_cast<IRVar*>(param)->dataType == FLOAT || reinterpret_cast<IRVar*>(param)->dataType == DOUBLE) {
                    paramReg = "fa"+std::to_string(AssemblyGenerator->paramCount);
                }
                else {
                    paramReg = "a"+std::to_string(AssemblyGenerator->paramCount);
                }
                newAddrDes->atReg.push_back(paramReg);
                AssemblyGenerator->paramList.push_back(param->getIROperand());
                AssemblyGenerator->paramCount++;
            }
            break;
        } 
        case IR_FUNC_END:
        {
            AssemblyGenerator->paramList.clear();
            AssemblyGenerator->addrDescriptorMap.clear();
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s0, ") + std::to_string(AssemblyGenerator->stackSize-8) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld ra, ") + std::to_string(AssemblyGenerator->stackSize-16) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s1, ") + std::to_string(AssemblyGenerator->stackSize-24) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s2, ") + std::to_string(AssemblyGenerator->stackSize-32) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s3, ") + std::to_string(AssemblyGenerator->stackSize-40) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s4, ") + std::to_string(AssemblyGenerator->stackSize-48) + std::string("(sp)"));
            if (AssemblyGenerator->opt == 0){
                for (int i = 5; i < 12; i++)
                    AssemblyGenerator->asmCodeList.push_back(std::string("ld s") + std::to_string(i) + std::string(", ") + std::to_string(AssemblyGenerator->stackSize-16-8*i) + std::string("(sp)"));
            }
            AssemblyGenerator->asmCodeList.push_back(std::string("addi sp, sp, ") + std::to_string(AssemblyGenerator->stackSize));
            AssemblyGenerator->asmCodeList.push_back("ret");   
            break;  
        }
        case IR_PARAM:
        {
            if (AssemblyGenerator->calleeParamNum < AssemblyGenerator->paramCount) {
                IROperand *saveOperand = AssemblyGenerator->paramList[AssemblyGenerator->calleeParamNum];
                saveOperand->toMem(AssemblyGenerator, nullptr, AssemblyGenerator->addrDescriptorMap[saveOperand]->atReg[0]);
            }
            std::string srcReg = dst->toRegister(AssemblyGenerator, dstInfo);
            dst->argReg(AssemblyGenerator, AssemblyGenerator->calleeParamNum, srcReg);
            AssemblyGenerator->calleeParamNum++;
            break;
        }
        case IR_CALL:
        {
            std::string newAssembly = "call " + reinterpret_cast<IRFunc*>(dst)->funcSymbol->getSymbolName();
            AssemblyGenerator->asmCodeList.push_back(newAssembly);
            int i = 0;
            if (src1 != nullptr) {
                i = 1;
            }
            int minParamNum = (AssemblyGenerator->calleeParamNum > AssemblyGenerator->paramCount) ? AssemblyGenerator->paramCount : AssemblyGenerator->calleeParamNum;
            for (; i < minParamNum; i++) {
                AssemblyGenerator->paramList[i]->assignReg(AssemblyGenerator, i);
            }
            AssemblyGenerator->calleeParamNum = 0;
            break;
        }
        case IR_ADD:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            std::string dstReg  = dst->toRegister(AssemblyGenerator, dstInfo);
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "add ";
                    break;
                case Type::FLOAT: 
                    asmOpCode = "fadd.s ";
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fadd.d ";
                    break;
                default:
                    break;
            }
            AssemblyGenerator->asmCodeList.push_back(asmOpCode + dstReg + ", " + srcReg1 + ", " + srcReg2);
            break;
        }
        case IR_SUB:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            std::string dstReg  = dst->toRegister(AssemblyGenerator, dstInfo);
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "sub ";
                    break;
                case Type::FLOAT: 
                    asmOpCode = "fsub.s ";
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fsub.d ";
                    break;
                default:
                    break;
            }
            AssemblyGenerator->asmCodeList.push_back(asmOpCode + dstReg + ", " + srcReg1 + ", " + srcReg2);
            break;
        }
        case IR_MUL:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            std::string dstReg  = dst->toRegister(AssemblyGenerator, dstInfo);
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "mul ";
                    break;
                case Type::FLOAT: 
                    asmOpCode = "fmul.s ";
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fmul.d ";
                    break;
                default:
                    break;
            }
            AssemblyGenerator->asmCodeList.push_back(asmOpCode + dstReg + ", " + srcReg1 + ", " + srcReg2);
            break;
        }
        case IR_DIV:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            std::string dstReg  = dst->toRegister(AssemblyGenerator, dstInfo);
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "div ";
                    break;
                case Type::FLOAT: 
                    asmOpCode = "fdiv.s ";
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fdiv.d ";
                    break;
                default:
                    break;
            }
            AssemblyGenerator->asmCodeList.push_back(asmOpCode + dstReg + ", " + srcReg1 + ", " + srcReg2);
            break;
        }
        case IR_MOD:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            std::string dstReg  = dst->toRegister(AssemblyGenerator, dstInfo);
            AssemblyGenerator->asmCodeList.push_back(std::string("rem ") + dstReg + ", " + srcReg1 + ", " + srcReg2);
            break;
        }
        case IR_ASSIGN:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            if (dynamic_cast<IRArrayElem*>(dst) != nullptr) {
                dst->toMem(AssemblyGenerator, dstInfo, srcReg1);       
            }
            else if (std::count(AssemblyGenerator->paramList.begin(), AssemblyGenerator->paramList.end(), dst) != 0) {
                std::string dstReg = AssemblyGenerator->searchAddrDescriptorMap(dst)->atReg[0];
                AssemblyGenerator->asmCodeList.push_back(std::string("mv ") + dstReg + std::string(", ") + srcReg1);
            }
            else if (std::count(AssemblyGenerator->paramList.begin(), AssemblyGenerator->paramList.end(), src1) != 0) {
                std::string reg = AssemblyGenerator->getReg(false);
                AssemblyGenerator->asmCodeList.push_back(std::string("mv ") + reg + std::string(", ") + srcReg1);
                AddrDescriptor *addrDes = AssemblyGenerator->searchAddrDescriptorMap(dst);
                addrDes->atReg.push_back(reg);
                AssemblyGenerator->regDescriptorMap[reg]->ops.insert(dst);
            }
            else if (dstInfo->liveness && dstInfo->usedInfo != nullptr && dynamic_cast<TemporaryValue*>(dst) == nullptr) {
                dst->toMem(AssemblyGenerator, nullptr, srcReg1);
                AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(dst);
                if (addrDescriptor->atReg.size() > 0) {
                    AssemblyGenerator->regDescriptorMap[addrDescriptor->atReg[0]]->ops.erase(dst);
                    addrDescriptor->atReg[0] = srcReg1;
                }
                else
                    addrDescriptor->atReg.push_back(srcReg1);
                AssemblyGenerator->regDescriptorMap[srcReg1]->ops.insert(dst);
                addrDescriptor->inMem = false;
            }
            else if (dstInfo->liveness && dstInfo->usedInfo == nullptr) {
                dst->toMem(AssemblyGenerator, nullptr, srcReg1);
                //AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(dst);
                //addrDescriptor->inMem = true;
            }
            else {
                AddrDescriptor *addrDescriptor = AssemblyGenerator->searchAddrDescriptorMap(dst);
                //addrDescriptor->atReg.push_back(srcReg1);
                if (addrDescriptor->atReg.size() > 0)
                    addrDescriptor->atReg[0] = srcReg1;
                else 
                    addrDescriptor->atReg.push_back(srcReg1);
                AssemblyGenerator->regDescriptorMap[srcReg1]->ops.insert(dst);
                addrDescriptor->inMem = false;
            }
            break;
        }
        case IR_NEG:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string dstReg  = dst->toRegister(AssemblyGenerator, dstInfo);
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "neg ";
                    break;
                case Type::FLOAT: 
                    asmOpCode = "fneg.s ";
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fneg.d ";
                    break;
                default:
                    break;
            }
            AssemblyGenerator->asmCodeList.push_back(asmOpCode + dstReg + ", " + srcReg1);
            break;
        }
        case IR_BLT:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "blt ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + srcReg1 + std::string(", ") + srcReg2 + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::FLOAT: 
                    asmOpCode = "flt.s ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "flt.d ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                default:
                    break;
            }
            break;
        }
        case IR_BLE:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "bge ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + srcReg2 + std::string(", ") + srcReg1 + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::FLOAT: 
                    asmOpCode = "fle.s ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fle.d ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                default:
                    break;
            }
            break;
        }
        case IR_BGT:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "blt ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + srcReg2 + std::string(", ") + srcReg1 + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::FLOAT: 
                    asmOpCode = "flt.s ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg2 + std::string(", ") + srcReg1);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fle.d ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                default:
                    break;
            }
            break;
        }
        case IR_BGE:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "bge ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + srcReg1 + std::string(", ") + srcReg2 + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::FLOAT: 
                    asmOpCode = "fle.s ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg2 + std::string(", ") + srcReg1);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "fle.d ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg2 + std::string(", ") + srcReg1);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                default:
                    break;
            }
            break;
        }
        case IR_BEQ:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            std::string tmp;
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "beq ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + srcReg1 + std::string(", ") + srcReg2 + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::FLOAT: 
                    asmOpCode = "feq.s ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "feq.d ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("bnez ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                default:
                    break;
            }
            break; 
        }
        case IR_BNE:
        {
            std::string srcReg1 = src1->toRegister(AssemblyGenerator, src1Info);
            AssemblyGenerator->regConfig = true;
            AssemblyGenerator->configReg = srcReg1;
            std::string srcReg2 = src2->toRegister(AssemblyGenerator, src2Info);
            AssemblyGenerator->regConfig = false;
            std::string tmp;
            switch(dataType) {
                case Type::INT: 
                    asmOpCode = "bne ";
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + srcReg1 + std::string(", ") + srcReg2 + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::FLOAT: 
                    asmOpCode = "feq.s ";
                    tmp = AssemblyGenerator->getReg(true);
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("beqz ") + tmp + ", L" + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                case Type::DOUBLE: 
                    asmOpCode = "feq.d ";
                    tmp = AssemblyGenerator->getReg(true);
                    AssemblyGenerator->asmCodeList.push_back(asmOpCode + tmp + std::string(", ") + srcReg1 + std::string(", ") + srcReg2);
                    AssemblyGenerator->asmCodeList.push_back(std::string("beqz ") + tmp + std::string(", L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
                    break;
                default:
                    break;
            }
            break;
        }
        case IR_LABEL:
        {
            AssemblyGenerator->asmCodeList.push_back(std::string("L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name) + std::string(":"));   
            break;
        }
        case IR_RETURN:
        {
            if (dst != nullptr) {
                std::string reg = dst->toRegister(AssemblyGenerator, dstInfo);
                std::string asmOpcode;
                std::string returnReg;
                if (dataType == INT) {
                    asmOpcode = "mv ";
                    returnReg = "a0";
                }
                else if (dataType == FLOAT) {
                    asmOpcode = "fmv.s ";
                    returnReg = "fa0";
                }
                else {
                    asmOpcode = "fmv.d ";
                    returnReg = "fa0";
                }
                AssemblyGenerator->asmCodeList.push_back(asmOpcode + returnReg + ", " + reg);
            }
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s0, ") + std::to_string(AssemblyGenerator->stackSize-8) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld ra, ") + std::to_string(AssemblyGenerator->stackSize-16) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s1, ") + std::to_string(AssemblyGenerator->stackSize-24) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s2, ") + std::to_string(AssemblyGenerator->stackSize-32) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s3, ") + std::to_string(AssemblyGenerator->stackSize-40) + std::string("(sp)"));
            AssemblyGenerator->asmCodeList.push_back(std::string("ld s4, ") + std::to_string(AssemblyGenerator->stackSize-48) + std::string("(sp)"));
            if (AssemblyGenerator->opt == 0){
                for (int i = 5; i < 12; i++)
                    AssemblyGenerator->asmCodeList.push_back(std::string("ld s") + std::to_string(i) + std::string(", ") + std::to_string(AssemblyGenerator->stackSize-16-8*i) + std::string("(sp)"));
            }
            AssemblyGenerator->asmCodeList.push_back(std::string("addi sp, sp, ") + std::to_string(AssemblyGenerator->stackSize));
            AssemblyGenerator->asmCodeList.push_back("ret");   
            break;
        }
        case IR_GOTO:
        {
            AssemblyGenerator->asmCodeList.push_back(std::string("j L") + std::to_string(reinterpret_cast<IRLabel*>(dst)->name));
            break;
        }
    }
}
