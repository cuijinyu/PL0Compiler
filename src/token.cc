#include "token.h"
#include <iostream>
using namespace std;

int Token::get_line () {
    return line;
};

Tag Token::get_tag () {
    return tag;
};

Token::Token(int line, string &lexem) {
    this -> line = line;
    this -> lexem = lexem;
};

Token::Token(int line, string &lexem, Tag t) {
    this -> line = line;
    this -> lexem = lexem;
    this -> tag = t;
};

void Token::set_tag(Tag t) {
    this -> tag = t;
};

string Token::get_lexem ()  {
    return lexem;
};