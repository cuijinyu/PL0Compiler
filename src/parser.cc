#include "parser.h"

void Parser::parse() {
    // analysis.push(PSTART);
}

// 获取token列表中下一个token，当程序结束时，返回PROEND这个Tag
Tag Parser::get_next_token () {
    if (!tokens.empty()) {
        Token * temp_token = tokens[0];
        tokens.pop_back();
        return temp_token -> get_tag();
    }
    else return PROEND;
}

bool Parser::is_vn (Tag t) {
    for (auto a:Vn) {
        if (a == t) {
            return true;
        }
    }
    return false;
} 

bool Parser::is_vt (Tag t) {
    for (auto a:Vt) {
        if (a == t) {
            return true;
        }
    }
    return false;
}

bool Parser::in_first (Tag t, string pro) {
    for (auto i:firsts) {
        if (i.first == pro) {
            return i.second.find(t) != i.second.end();
        }
    }
}

bool Parser::in_follow (Tag t, string pro) {
    for (auto i:follows) {
        if (i.first == pro) {
            return i.second.find(t) != i.second.end();
        }
    }
}

void Parser::generate_table () {
    for (auto first:firsts) {

    }
    

    for (auto follow:follows) {

    }
}

void Parser::generate () {
    
}

void Parser::program () {
    block();
    Tag next_token = get_next_token();
    if (match(DOTSYM, next_token)) {
        return;
    } else {
        cout << "syntax error ,Code:" << DOTSYM;
    }
}

void Parser::block () {
    Tag next_token = get_next_token();
    if (match(CONSTSYM, next_token)) {

    } else if (match(VARSYM, next_token)) {

    } else if (match(PROCSYM, next_token)) {

    } else {
        statement();
    }
}

void Parser::statement () {

}

void Parser::condition () {

}

void Parser::expression () {

}

void Parser::term () {
    factor();
} 

void Parser::factor () {
    Tag next_token = get_next_token();
    switch (next_token) {
        case IDESYM:

    }
}

void Parser::const_declare () {

}

void Parser::var_declare () {

}

void Parser::procedure_declare () {

}

void Parser::assign_statement () {

}

void Parser::condition_statement () {

}

void Parser::while_statement () {

}

void Parser::call_statement () {

}

void Parser::read_statement () {

}

void Parser::write_statement () {

}

void Parser::complex_statement () {
    
}

bool Parser::match (Tag aim_token, Tag temp_token) {
    if (aim_token == temp_token) {
        return true;
    } else {
        return false;
    }
}