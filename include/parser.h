#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <set>
#include <map>
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

        // 根据Tag判断是否在其的First集合中
        bool in_first (Tag t, string pro);

        // 根据Tag判断是否在其的Follow集合中
        bool in_follow (Tag t, string pro);

        // 根据预测分析表，将非终结符推导   
        void generate ();

        // 判断是否为非终结符
        bool is_vn (Tag t);

        // 判断是否为终结符 
        bool is_vt (Tag t);

        // 开始语法分析
        void parse ();

        Tag get_next_token ();

        // 生成预测分析表
        void generate_table ();

    private:
        // 产生式列表，用于生成First集合与Follow集合
        vector <string> productions;

        // 预测分析表
        vector <vector <Tag>> table;
        
        // 各个产生式的First集合
        map <string, set<Tag> > firsts;

        // 各个产生式的Follow集合
        map <string, set<Tag> > follows;

        // 分析栈
        stack <Tag> analysis;

        // 剩余字符栈
        stack <Tag> lost;

        // token列表
        vector <Token *> tokens;

        // 定义各个非终结符的First与Follow集合
        // static vector <Tag> program_first;
        // static vector <Tag> program_follow;
        // static vector <Tag> sentence_first;
        // static vector <Tag> sentence_follow;
        // static vector <Tag> expression_first;
        // static vector <Tag> expression_follow;
        // static vector <Tag> condition_first;
        // static vector <Tag> condition_follow;
        // static vector <Tag> item_first;
        // static vector <Tag> item_follow;
        // static vector <Tag> factor_first;
        // static vector <Tag> factor_follow;

        // 终结符集合
        static vector <Tag> Vt;

        // 非终结符集合
        static vector <Tag> Vn;
};
#endif