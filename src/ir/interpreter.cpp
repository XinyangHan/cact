#include "include/ir/Interpret.h" // 包含解释器头文件
#include <iostream> // 引入输入输出流库

// 获取布尔值
std::any InterpretBool::getValue(int offset, int base) {
    return value[offset + base] ? true : false;
}

// 设置布尔值
void InterpretBool::setValue(std::any newVal, int offset, int base) {
    value[offset + base] = std::any_cast<bool>(newVal);
}

// 获取整数值
std::any InterpretInt::getValue(int offset, int base) {
    return value[(offset + base) >> 2];
}

// 设置整数值
void InterpretInt::setValue(std::any newVal, int offset, int base) {
    value[(offset + base) >> 2] = std::any_cast<int>(newVal);
}

// 获取浮点数值
std::any InterpretFloat::getValue(int offset, int base) {
    return value[(offset + base) >> 2];
}

// 设置浮点数值
void InterpretFloat::setValue(std::any newVal, int offset, int base) {
    value[(offset + base) >> 2] = std::any_cast<float>(newVal);
}

// 获取双精度浮点数值
std::any InterpretDouble::getValue(int offset, int base) {
    return value[(offset + base) >> 3];
}

// 设置双精度浮点数值
void InterpretDouble::setValue(std::any newVal, int offset, int base) {
    value[(offset + base) >> 3] = std::any_cast<double>(newVal);
}

// 获取临时值
std::any InterpretTemp::getValue(int offset, int base) {
    return value;
}

// 解释执行中间代码
void IntermediateInterpreter::interpretIntermediateCode(std::ofstream &interpretFile, std::vector<IntermediateCode*> &irCodeList, std::map<std::string, IROperand*> &immediatePool) {
    int i;
    IntermediateCode *nextIR;

    // 设定中间代码的下一个指令和定位主函数
    for (i = 0; i < irCodeList.size() - 1; i++) {
        irCodeList[i]->nextIR = irCodeList[i + 1];
        irCodeList[i]->locateMainFunction(this, &nextIR);
    }
    irCodeList[i]->locateMainFunction(this, &nextIR);

    // 处理立即数池中的值
    for (auto it = immediatePool.begin(); it != immediatePool.end(); it++) {
        std::any value = fetchImmediateValue(reinterpret_cast<IRImmediateValue*>(it->second));
        immMap[it->second] = new InterpretImm(value);
    }

    currStack = new IntermediateStack(currStack);  // 创建虚拟栈帧，谁调用了main？
    currStack->calleeReturnVal = new InterpretTemp(0);

    // 执行中间代码
    while (nextIR != nullptr) {
        nextIR = nextIR->interpretIntermediateCode(interpretFile, this);
    }

    int mainReturnVal = std::any_cast<int>(reinterpret_cast<InterpretTemp*>(currStack->calleeReturnVal)->value);
    std::cout << "程序返回值: " << mainReturnVal << std::endl;
}

// 获取立即数值
std::any IntermediateInterpreter::fetchImmediateValue(IRImmediateValue* immediate) {
    switch (immediate->dataType) {
        case INT: {
            int val;
            if ((immediate->val[0] == '0' && (immediate->val[1] == 'x' || immediate->val[1] == 'X')) || 
                (immediate->val[0] == '-' && immediate->val[1] == '0' && (immediate->val[2] == 'x' || immediate->val[2] == 'X'))) {
                val = stoi(immediate->val, nullptr, 16);
            } else if (immediate->val[0] == '0' || (immediate->val[0] == '-' && immediate->val[1] == '0')) {
                val = stoi(immediate->val, nullptr, 8);
            } else {
                val = stoi(immediate->val);
            }
            return val;          
        }
        case FLOAT: {
            float val = stof(immediate->val);
            return val;  
        }
        case DOUBLE: {
            double val = stod(immediate->val);
            return val;
        }
        default: {
            bool val = (immediate->val == "true");
            return val;
        }
    }
}