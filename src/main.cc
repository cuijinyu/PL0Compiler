#include <iostream>
#include "parser.h"
#include "laxical_analyzer.h"
using namespace std;
int main () {
    Laxer laxer("/home/cuijinyu/文档/pl0Compiler/test/test.pl0");
    laxer.tokenizer();
    vector <Token *> tokens = laxer.get_tokens();
    Parser parser(tokens);
    parser.parse();
}