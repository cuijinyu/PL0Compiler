#ifndef AST_H
#define AST_H
#include <iostream>
#include <vector>
#include "node.h"
using namespace std;
// 抽象语法树类
class Ast {
    public:
        // Ast的初始化构造
        Ast () {
            root_node = new Node();
        };

        ~Ast () {

        };
    private:
        Node * root_node;
};
#endif