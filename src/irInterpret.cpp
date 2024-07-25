#include "irInterpret.h"
#include <iostream>

std::any InterpretBool::getValue(int displacement, int base) {
    if (value[displacement + base])
        return true;
    else
        return false;
}

void InterpretBool::setValue(std::any newVal, int displacement, int base) {
    value[displacement + base] = std::any_cast<bool>(newVal);
}

std::any InterpretInt::getValue(int displacement, int base) {
    return value[(displacement + base) >> 2];
}

void InterpretInt::setValue(std::any newVal, int displacement, int base) {
    value[(displacement + base) >> 2] = std::any_cast<int>(newVal);
}

std::any InterpretFloat::getValue(int displacement, int base) {
    return value[(displacement + base) >> 2];
}

void InterpretFloat::setValue(std::any newVal, int displacement, int base) {
    value[(displacement + base) >> 2] = std::any_cast<float>(newVal);
}

std::any InterpretDouble::getValue(int displacement, int base) {
    return value[(displacement + base) >> 3];
}

void InterpretDouble::setValue(std::any newVal, int displacement, int base) {
    value[(displacement + base) >> 3] = std::any_cast<double>(newVal);
}

std::any InterpretTemp::getValue(int displacement, int base) {
    return value;
}

void IRInterpretor::interpretIRCode(std::ofstream &interpretFile, std::vector<IRCode*> &irCodeList, std::map<std::string, IROperand*> &immediatePool) {
    int i;
    IRCode *nextIR;
    for (i = 0; i < irCodeList.size()-1; i++) {
        irCodeList[i]->nextIR = irCodeList[i+1];
        irCodeList[i]->findMain(this, &nextIR);
    }
    irCodeList[i]->findMain(this, &nextIR);
    
    for (auto it = immediatePool.begin(); it != immediatePool.end(); it++) {
        std::any value = getImmediateVal(reinterpret_cast<IRImmediate*>(it->second));
        immMap[it->second] = new InterpretImm(value);
    }
    
    currStack = new IRStack(currStack);  //fake stack, who invokes main? 
    currStack->calleeReturnVal = new InterpretTemp(0);
    
    while (nextIR != nullptr) {
        nextIR = nextIR->interpretIRCode(interpretFile, this);
    }
    int mainReturnVal = std::any_cast<int>(reinterpret_cast<InterpretTemp*>(currStack->calleeReturnVal)->value);
    std::cout << "cact main return value: " << mainReturnVal << std::endl;
}

std::any IRInterpretor::getImmediateVal(IRImmediate* immediate) {
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