#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <tag.h>
#include <string>
#include <code.h>
using namespace std;
/**
 * 将Tag格式化为string
 **/ 
string formatTag (Tag t) {
    string tags[] = {
        "+",
        "-",
        "*",
        "/",
        "=",
        "<",
        ">",
        "<=",
        ">=",
        "number",
        "identifier",
        "if",
        "else",
        "then",
        "while",
        "begin",
        "end",
        "do",
        "read",
        "write",
        "call",
        "const",
        "var",
        "procedure",
        "odd",
        ",",
        ".",
        ";",
        ":=",
        "<>",
        "(",
        ")"
    };
    return tags[static_cast<int>(t)];
};

string formatOperator(Code c) {
    string operators[] = {
        "INT", "CAL", "LIT", "LOD",
        "STO", "JMP", "JPC", "OPR" 
    };
    return operators[static_cast<int>(c)];
};
#endif