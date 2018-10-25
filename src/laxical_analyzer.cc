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
    int max_size = this -> program_string.size();
    if (this -> char_pos >= max_size - 1) {
        return '#';
    }
    this -> char_pos =  this -> char_pos + 1;
    return this -> program_string[this -> char_pos];
}

void Laxer::un_get_char () {
    if (this -> char_pos == 1) {
        return;
    } else {
        this -> char_pos = this -> char_pos - 1;
    }
}

bool is_num ( char test ) {
    if ( test >= '0' && test <= '9' ) {
        return true;
    } else 
        return false;
};

void Laxer::increase_line () {
    this -> line_number = this -> line_number + 1;
}


void Laxer::tokenizer () {

    // 在开始时，置state为START
    state = START;
    string lexem = "";
    while (true) {
        char ch = get_next_char();

        if (ch == '#') {
            break;
        }

        switch (state) {
            case START:
                switch ( ch ) {
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case ';':
                    case ',':
                    case '=':
                    case '(':
                    case ')':
                        state = PLOPERATOR;
                        lexem = lexem + ch;
                        break;
                    case ':':
                        state = ASSIGN;
                        lexem = lexem + ch;
                        break;
                    case '>':
                        state = GEQ;
                        lexem = lexem + ch;
                        break;
                    case '<':
                        state = LEQ;
                        lexem = lexem + ch;
                        break;
                    default:
                        if ( is_num( ch ) ) {
                            state = PLNUM;
                            lexem = lexem + ch;
                        } else if ( isalpha( ch ) ) {
                            state = PLIDEN;
                            lexem = lexem + ch;
                        } else if ( ch == '\n' ) {
                            increase_line();
                        } else if ( isspace( ch ) ) {
                            state = DONE;
                        } else if ( ch == '.' ) {
                            lexem = lexem + ch;
                            state = DOT;
                            state = DONE;
                            cout << lexem << " ------>DOT" << " ---->Line" << line_number << endl;
                        } else {
                            state = ERROR;
                        }
                }
                break;
            case PLNUM:
                switch ( ch ) {
                    default:
                        if ( is_num( ch ) ) {
                            state = PLNUM;
                            lexem = lexem + ch;
                        } else {
                            cout << lexem << " ------>PLNUM" << " ---->Line" << line_number << endl;
                            un_get_char();
                            state = DONE;
                        }
                }
                break;
            case PLIDEN:
                switch ( ch ) {
                    default:
                        if ( isalnum( ch ) ) {
                            state = PLIDEN;
                            lexem = lexem + ch;
                        } else {
                            cout << lexem << " ------>PLIDEN" << " ---->Line" << line_number  << endl;
                            un_get_char();
                            state = DONE;
                        }
                }
                break;
            case PLOPERATOR:
                cout << lexem << " ------>PLOPERATOR" << " ---->Line" << line_number  << endl;
                state = DONE;
                break;
            case ASSIGN:
                switch ( ch ) {
                    case '=':
                        lexem = lexem + ch;
                        cout << lexem << " ------>ASSIGN" << " ---->Line" << line_number << endl;
                        state = DONE;
                        break;
                    default:
                        state = ERROR;
                }
                break;
            case LEQ:
                switch ( ch ) {
                    case '=':
                        lexem = lexem + ch;
                        cout << lexem << " ------>LEQ" << " ---->Line" << line_number << endl;
                        state = DONE;
                        break;
                    case '>':
                        lexem = lexem + ch;
                        cout << lexem << " ------>NEQ" << " ---->Line" << line_number << endl;
                        state = DONE;
                        break;
                    default:
                        cout << lexem << " ------>L" << " ---->Line" << line_number << endl;
                        un_get_char();
                        state = DONE;
                }
                break;
            case GEQ:
                switch ( ch ) {
                    case '=':
                        lexem = lexem + ch;
                        cout << lexem <<" ------>GEQ" << " ---->Line" << line_number << endl;
                        state = DONE;
                        break;
                    default:
                        cout << lexem << " ------>G" << " ---->Line" << line_number << endl;
                        un_get_char();
                        state = DONE;
                }
        }

        // 每次分析结束后判断是否为DONE，此时应该置为新的START
        if (state == DONE) {
            state = START;
            lexem = "";
        } else if (state == ERROR) {
            cout << "ERROR AT LINE" << " ---->Line" << line_number << endl;
            exit(0);
        }
    }

    // 一次扫描完成，开始做详细的分类
}