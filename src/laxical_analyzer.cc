// The PL0 laxical analyzer program
// Author Cui Jinyu
// Github https://github.com/cuijinyu

#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
#include "laxical_analyzer.h"
using namespace std;

char Laxer::get_next_char () {
    int temp_pos = char_pos;
    temp_pos ++;
    return program_string[temp_pos];
}

void Laxer::tokenizer () {
    for (char_pos = 0; char_pos < program_string.size(); char_pos++) {
        state = START;
        char current_char = program_string[char_pos];
        char temp_char;
        string token_lexm;
        cout << program_string[char_pos] << endl;

        // 当状态为DONE时，满足当前状态机
        while (state != DONE) {
            cout << "----->" << current_char << endl;
            if (state == ERROR) {
                cout << "程序出错 ---> Line:" <<line_number<< endl;
                // 程序出错并且提示出错信息退出
                exit(0);
            }

            switch (current_char){
             case '+':
                token_lexm = '+';
                cout << "PLUS" << endl;
                state = DONE;
                break;
             case '-':
                token_lexm = '-';
                cout << "SUB"<< endl;
                state = DONE;
                break;
             case '*':
                token_lexm = '*';
                cout << "MUL" << endl;
                state = DONE;
                break;
             case '/':
                token_lexm = '/';
                cout << "DIV" << endl;
                state = DONE;
                break;
             case '=':
                if (state == LEQ) {
                    state = DONE;
                } else if (state == GEQ) {
                    state = DONE;
                } else if (state == ASSIGN) {
                    token_lexm = ":=";
                } else if (state == START) {
                    token_lexm = '=';
                    state = DONE;
                }
                break;
             case ':':
                if (state != START) {
                    state = ERROR;
                }
                state = ASSIGN;
                char_pos++;
                break;
             case '>':
                state = GEQ;
                char_pos++;
                break;
             case '<':
                state = LEQ;
                char_pos++;
                break;
             default:
                if (current_char == '\n') {
                    line_number ++;
                    state = START;
                }
                if (state == LEQ || state == GEQ) {
                    state = DONE;
                }
                if (isalpha(current_char)) {
                    if (state == PLIDEN || state == START) {
                        state = PLIDEN;
                        char_pos++;
                    }
                } else if (isalnum(current_char)) {
                    if (state == PLNUM || state == START) {
                        state = PLNUM;
                        char_pos++;
                    } else if (state == PLIDEN) {
                        state = PLIDEN;
                        char_pos++;
                    }
                } else if (isspace(current_char)) {
                    state = DONE;
                }
            }
        }

        // 每次自动机完成，字符位置后移1
        if (char_pos < program_string.size())
            char_pos ++;
    }
}