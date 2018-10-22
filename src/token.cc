#include "token.h"
#include <iostream>
using namespace std;

int Token::getLine () {
    return line;
};

Tag Token::getTag () {
    return tag;
};