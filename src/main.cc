#include <iostream>
#include "laxical_analyzer.h"
using namespace std;
int main () {
    Laxer laxer("./test.pl0");
    laxer.tokenizer();
}