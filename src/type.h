#pragma once

enum Type {
    VOID,
    BOOL,
    INT,
    FLOAT,
    DOUBLE,
    INT_PTR,
    FLOAT_PTR,
    DOUBLE_PTR
};

enum IROpCode {
    IR_G_ALLOC,
    IR_L_ALLOC,
    IR_LABEL,
    IR_FUNC_START,
    IR_FUNC_END,
    IR_PARAM,
    IR_CALL,
    IR_RETURN,
    IR_ASSIGN,
    IR_ADD,
    IR_SUB,
    IR_MUL,
    IR_DIV,
    IR_MOD,
    IR_AND,
    IR_OR,
    IR_NOT,
    IR_NEG,
    IR_SLT,
    IR_SLTE,
    IR_BLT,
    IR_BLE,
    IR_BGT,
    IR_BGE,
    IR_BEQ,
    IR_BNE,
    IR_GOTO,
    IR_UNKNOWN
};
