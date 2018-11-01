#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <set>
#include <stack>
#include <token>
using namespace std;

// LL(1) 语法分析器
class Parser {
    public:
        Parser (vector <Token *> tokens) {
            this -> tokens = tokens;
        };
        ~ Parser () = default;
    private:
        // LL(1) 语法分析器的 first 集
        set <char> first [100];

        // LL(1) 语法分析器的 follow 集
        set <char> follow [100];

        // 分析栈
        stack <char> analysis;

        // 剩余字符栈
        stack <char> lost;

        // token列表
        vector <Token *> tokens;

        // 获取 first 集
        void get_first ();

        // 获取 follow 集
        void get_follow ();

        // 生成预测分析表
        void create_table ();
};
#endif