#ifndef AST_H
#define AST_H
#include <iostream>
#include <vector>
#include <token.h>
#include "node.h"
using namespace std;
// 抽象语法树类
class Ast {
    public:
        // Ast的初始化构造
        Ast (string type) {
            this -> type = type;
        };

        ~Ast () = default;

        void add_node (Ast * ast_node) {
           ast_nodes.push_back(ast_node); 
        };

        void add_node (Token * token_node) {
            token_nodes.push_back(token_node);
        };

        void print () {
            for (auto i:token_nodes) {
                cout << i -> get_lexem() << endl;
            }
            for (auto i:ast_nodes) {
                cout << i -> type << endl << endl;
                i -> print();
            }
        };  
    private:
        string type;
        vector <Ast *> ast_nodes;
        vector <Token *> token_nodes;
};
#endif