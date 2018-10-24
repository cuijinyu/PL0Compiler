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
        cout << "长度超标" << endl;
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


void Laxer::tokenizer () {

    // 在开始时，置state为START
    state = START;
    while (true) {
        char ch = get_next_char();

        if (ch == '#') {
            return;
        }

        cout << ch << endl;

        switch ( ch ) {
            case '+':
            case '-':
            case '*':
            case '/':
            case ';':
            case ',':
            case '(':
            case ')':
                state = DONE;
                break;
            case ':':
                state = ASSIGN;
                break;
            case '>':
                state = GEQ;
                break;
            case '<':
                state = LEQ;
                break;
            case '=':
                switch (state) {
                    case ASSIGN:
                        state = DONE;
                        break;
                    case GEQ:
                        state = DONE;
                        break;
                    case LEQ:
                        state = DONE;
                        break;
                }
            default:
                if ( isalnum(ch) ) {
                    switch (state) {
                        case PLNUM:
                        case PLIDEN:
                        case START:
                    }
                } else if ( isalpha(ch) ) {
                    switch (state) {
                        case START:
                        case PLIDEN:
                    }
                }
        }

        // 每次分析结束后判断是否为DONE，此时应该置为新的START
        if (state == DONE) {

        }
    }
}