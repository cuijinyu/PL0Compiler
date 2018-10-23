#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "tag.h"

class Token {
    public:
        Token () {};
        Token (int line, Tag tag):line(line),tag(tag){};
        ~ Token () {};
        int getLine ();
        Tag getTag ();
    private:
        int line;
        Tag tag;
};
#endif