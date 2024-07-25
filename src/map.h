#pragma once
#include <type.h>
#include <map>

std::map <Type, std::string> type2String{
        {Type::VOID,    "VOID"},
        {Type::BOOL,    "BOOL"},
        {Type::INT,     "INT"},
        {Type::FLOAT,   "FLOAT"},
        {Type::DOUBLE,  "DOUBLE"}
};