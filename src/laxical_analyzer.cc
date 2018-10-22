// The PL0 laxical analyzer program
// Author Cui Jinyu
// Github https://github.com/cuijinyu
#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
#include "./laxical_analyzer.h"
using namespace std;
void Laxer::tokenizer () {
    for (char_pos = 0; char_pos < program_string.size(); char_pos++) {
        cout << program_string[char_pos] << endl;
    }
}