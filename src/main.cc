#include <iostream>
#include "parser.h"
#include "laxical_analyzer.h"
using namespace std;
int main () {
    Laxer laxer("./test.pl0");
    laxer.tokenizer();
    vector <Token *> tokens = laxer.get_tokens();
    Parser parser(tokens);
}