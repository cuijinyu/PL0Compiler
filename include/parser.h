#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <token.h>
using namespace std;

// LL(1) 语法分析器
class Parser {
    public:
        Parser (vector <Token *> tokens) {
            this -> tokens = tokens;
        };

        ~ Parser () = default;

        void show_tokens () {
            for (auto i:tokens) {
                cout << i -> get_lexem() << endl;
            }
        }

        // 开始语法分析
        void parse();
    private:
        // 分析栈
        stack <char> analysis;

        // 剩余字符栈
        stack <char> lost;

        // token列表
        vector <Token *> tokens;

        // 定义各个非终结符的First与Follow集合
        static vector <Tag> program_first;
        static vector <Tag> program_follow;
        static vector <Tag> sentence_first;
        static vector <Tag> sentence_follow;
        static vector <Tag> expression_first;
        static vector <Tag> expression_follow;
        static vector <Tag> condition_first;
        static vector <Tag> condition_follow;
        static vector <Tag> item_first;
        static vector <Tag> item_follow;
        static vector <Tag> factor_first;
        static vector <Tag> factor_follow;
        // 终结符集合
        static vector<Tag> Vt;

        // 非终结符集合
        static vector<Tag> Vn;
};
#endif