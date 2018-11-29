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
    if (this -> char_pos == 0) {
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

vector <Token *> Laxer::get_tokens () {
    return tokens;
}

void Laxer::tokenizer () {

    // 在开始时，置state为START
    char_pos = -1;
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
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, PLUSSYM));
                        state = PLOPERATOR;
                        break;
                    case '-':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, SUBSYM));
                        state = PLOPERATOR;
                        break;
                    case '*':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, MULTSYM));
                        state = PLOPERATOR;
                        break;
                    case '/':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, DIVSYM));
                        state = PLOPERATOR;
                        break;
                    case ';':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, SEMSYM));
                        state = PLOPERATOR;
                        break;
                    case ',':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, COMMASYM));
                        state = PLOPERATOR;
                        break;
                    case '=':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, EQSYM));
                        state = PLOPERATOR;
                        break;
                    case '(':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, LEFTBRACKET));
                        state = PLOPERATOR;
                        break;
                    case ')':
                        if (ch == ')') {
                            lexem = lexem + ch; 
                            tokens.push_back(new Token(line_number, lexem, RIGHTBRACKET));
                        }
                        state = PLOPERATOR;
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
                            tokens.push_back(new Token(line_number, lexem, DOTSYM));
                            // cout << lexem << " ------>DOT" << " ---->Line" << line_number << endl;
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
                            tokens.push_back(new Token(line_number, lexem, NUMSYM));
                            // cout << lexem << " ------>PLNUM" << " ---->Line" << line_number << endl;
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
                            tokens.push_back(new Token(line_number, lexem, IDESYM));
                            // cout << lexem << " ------>PLIDEN" << " ---->Line" << line_number  << endl;
                            un_get_char();
                            state = DONE;
                        }
                }
                break;
            case PLOPERATOR:
                // cout << lexem << " ------>PLOPERATOR" << " ---->Line" << line_number  << endl;
                state = DONE;
                break;
            case ASSIGN:
                switch ( ch ) {
                    case '=':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, ASSIGNSYM));
                        // cout << lexem << " ------>ASSIGN" << " ---->Line" << line_number << endl;
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
                        tokens.push_back(new Token(line_number, lexem, LEQSYM));
                        // cout << lexem << " ------>LEQ" << " ---->Line" << line_number << endl;
                        state = DONE;
                        break;
                    case '>':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, NEQSYM));
                        // cout << lexem << " ------>NEQ" << " ---->Line" << line_number << endl;
                        state = DONE;
                        break;
                    default:
                        tokens.push_back(new Token(line_number, lexem, LSYM));    
                        // cout << lexem << " ------>L" << " ---->Line" << line_number << endl;
                        un_get_char();
                        state = DONE;
                }
                break;
            case GEQ:
                switch ( ch ) {
                    case '=':
                        lexem = lexem + ch;
                        tokens.push_back(new Token(line_number, lexem, GEQSYM));
                        // cout << lexem <<" ------>GEQ" << " ---->Line" << line_number << endl;
                        state = DONE;
                        break;
                    default:
                        tokens.push_back(new Token(line_number, lexem, GSYM));
                        // cout << lexem << " ------>G" << " ---->Line" << line_number << endl;
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

    cout << endl;
    cout << "一次扫描完成，开始做详细的分类" << endl;
    cout << endl;

    // 一次扫描完成，开始做详细的分类
    for (auto i:tokens) {
        if (i -> get_tag() == IDESYM) {
            for (int j = 0; j < 12; j++) {
                if (reserved_word_list[j].lexem.compare(i -> get_lexem()) == 0) {
                    i -> set_tag(reserved_word_list[j].t);
                }
            }
        }
        cout << i -> get_lexem() << "  "<<i -> get_tag() << endl;
    }
}