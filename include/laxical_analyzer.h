#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "token.h"
#ifndef LAXICAL_ANALYZER_H
#define LAXICAL_ANALYZER_H
#define MAX_TOKENSIZE 40;
using namespace std;

struct reserved_word {
    string lexem;
    Tag t;
};

// DFA中的各种状态
enum STATE {
    START,
    DONE,
    ERROR,
    PLNUM,
    PLIDEN,
    PLOPERATOR,
    EQ,
    LEQ,
    GEQ,
    NEQ,
    ASSIGN,
    DOT
};

class Laxer
{
    public:
        Laxer () {};

        Laxer (string file_path) {
          this -> file_path = file_path;
          line_number = 1;
          char_pos = -1;
          open_source_file();
        };

        ~Laxer () {
          infile.close();
        };

        void show_program_string () {
            cout << this -> program_string << endl;
        };

        void show_line_number () {
            cout << this -> line_number << endl;
        };

        // 获得 tokens
        vector <Token *> get_tokens ();

        // 词法分析器主程序
        void tokenizer ();

    private:
        // 用来获取下一个字符
        char get_next_char ();

        // 放回一个字符
        void un_get_char ();

        // 增加行数
        void increase_line();

        //  progran_string 用来存储程序源代码
        string program_string;

        // line_number 用来token所在的行数
        int line_number;

        // char_pos 用来记录当前字符所在的位置
        int char_pos;

        // file_path 用来存储打开的程序文件的地址
        string file_path;

        // infile 用来打开文件的输入流
        ifstream infile;

        // state 用来保存DFA目前的状态
        STATE state;

        vector <Token *> tokens;

        void increase_line_number () {
            this -> line_number ++;
        };

        void open_source_file () {
            infile.open(file_path);
            ostringstream buf;
            buf << infile.rdbuf();
            program_string = buf.str();
            if (infile) {
                cout << "文件" << file_path << "打开成功" << endl;
            } else {
                cout << "文件" << file_path << "打开失败" << "，请检查文件是否存在" << endl;
            }
        };

        reserved_word  reserved_word_list [14]= {
            "const", CONSTSYM,
            "if", IFSYM,
            "else", ELSESYM,
            "then", THENSYM,
            "while", WHILESYM,
            "begin", BEGINSYM,
            "end", ENDSYM,
            "read", READSYM,
            "write", WRITESYM,
            "call", CALLSYM,
            "var", VARSYM,
            "procedure", PROCSYM,
            "do", DOSYM,
            "odd", ODDSYM
        };

};
#endif