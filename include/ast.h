#ifndef AST_H
#define AST_H
#include <iostream>
#include <vector>
#include <deque>
#include <token.h>
#include "node.h"
using namespace std;
// 抽象语法树类
class Ast {
    public:
        int line;
        int start;
        int end;
        string type;
        Ast () = default;
        // Ast的初始化构造
        Ast (string type) {
            this -> type = type;
        };

        ~Ast () = default;

        // virtual void add_node (Ast * ast_node) {
        //    ast_nodes.push_back(ast_node);
        //    string lexem = "anaysis";
        //    Token * analysis_token = new Token(0, lexem, ANALYSIS);
        //    token_nodes.push_back(analysis_token); 
        // };

        void add_node (Ast * ast_node) {
            this -> body.push_back(ast_node);
        }

        virtual void add_node (Token * token_node) {
            token_nodes.push_back(token_node);
        };

        virtual void print () {
            // filter();
            cout << endl;
            cout << "[" << this -> type << "]" << endl;
            cout << endl;
            for (auto i:token_nodes) {
                if (i -> get_tag() == ANALYSIS) {
                    Ast * top = ast_nodes.front();
                    ast_nodes.pop_front();
                    top -> print();
                    continue;
                }
                cout << i -> get_lexem() << " ";
            }
            cout << endl;
        };

        // 过滤方法，过滤掉语法树中无用的节点（做剪枝）
        void filter () {
            vector <Token *> temp_token_nodes;
            for (auto i:token_nodes) {
                if (i -> get_tag() != DOTSYM&&
                    i -> get_tag() != SEMSYM) {
                        temp_token_nodes.push_back(i);
                    }
            }
            token_nodes = temp_token_nodes;
        };

        // 执行方法，此时将pl0作为脚本执行
        void exec();

    private:
        deque <Ast *> ast_nodes;
        vector <Token *> token_nodes;
        deque <Ast *> body;
};
#endif