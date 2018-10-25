#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "tag.h"
using namespace std;
class Token {
    public:
        Token (int line, string &lexem);
        Token (int line, string &lexem, Tag t);
        ~ Token () {};
        int get_line ();
        Tag get_tag ();
        void set_tag (Tag t);
        string get_lexem ();
    private:
        int line;
        string lexem;
        Tag tag;
};
#endif