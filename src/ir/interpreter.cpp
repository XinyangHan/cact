#include "include/ir/Interpret.h"
#include <iostream>

std::any InterpretBool::getValue(int offset, int base) {
    if (value[offset + base])
        return true;
    else
        return false;
}

void InterpretBool::setValue(std::any newVal, int offset, int base) {
    value[offset + base] = std::any_cast<bool>(newVal);
}

std::any InterpretInt::getValue(int offset, int base) {
    return value[(offset + base) >> 2];
}

void InterpretInt::setValue(std::any newVal, int offset, int base) {
    value[(offset + base) >> 2] = std::any_cast<int>(newVal);
}

std::any InterpretFloat::getValue(int offset, int base) {
    return value[(offset + base) >> 2];
}

void InterpretFloat::setValue(std::any newVal, int offset, int base) {
    value[(offset + base) >> 2] = std::any_cast<float>(newVal);
}

std::any InterpretDouble::getValue(int offset, int base) {
    return value[(offset + base) >> 3];
}

void InterpretDouble::setValue(std::any newVal, int offset, int base) {
    value[(offset + base) >> 3] = std::any_cast<double>(newVal);
}

std::any InterpretTemp::getValue(int offset, int base) {
    return value;
}

void IntermediateInterpreter::interpretIntermediateCode(std::ofstream &interpretFile, std::vector<IntermediateCode*> &irCodeList, std::map<std::string, IROperand*> &immediatePool) {
    int i;
    IntermediateCode *nextIR;
    for (i = 0; i < irCodeList.size()-1; i++) {
        irCodeList[i]->nextIR = irCodeList[i+1];
        irCodeList[i]->locateMainFunction(this, &nextIR);
    }
    irCodeList[i]->locateMainFunction(this, &nextIR);
    
    for (auto it = immediatePool.begin(); it != immediatePool.end(); it++) {
        std::any value = fetchImmediateValue(reinterpret_cast<IRImmediateValue*>(it->second));
        immMap[it->second] = new InterpretImm(value);
    }
    
    currStack = new IntermediateStack(currStack);  //fake stack, who invokes main? 
    currStack->calleeReturnVal = new InterpretTemp(0);
    
    while (nextIR != nullptr) {
        nextIR = nextIR->interpretIntermediateCode(interpretFile, this);
    }
    int mainReturnVal = std::any_cast<int>(reinterpret_cast<InterpretTemp*>(currStack->calleeReturnVal)->value);
    std::cout << "程序返回值: " << mainReturnVal << std::endl;
}

std::any IntermediateInterpreter::fetchImmediateValue(IRImmediateValue* immediate) {
    switch (immediate->dataType) {
        case INT:    {
            int val;
            if((immediate->val[0] == '0' && (immediate->val[1] == 'x' || immediate->val[1] == 'X')) || (immediate->val[0] == '-' && immediate->val[1] == '0' && (immediate->val[2] == 'x' || immediate->val[2] == 'X'))) {
                val = stoi(immediate->val, nullptr, 16);
            }else if(immediate->val[0] == '0' || (immediate->val[0] == '-' && immediate->val[1] == '0')){
                val = stoi(immediate->val, nullptr, 8);
            }else{
                val = stoi(immediate->val);
            }
            return val;          
        }
        case FLOAT:  { 
            float val = stof(immediate->val);
            return val;  
        }
        case DOUBLE: {
            double val = stod(immediate->val);
            return val;
        }
        default:
            bool val = (immediate->val == "true");
            return val;
    }
}