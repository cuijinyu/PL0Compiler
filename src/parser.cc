#include "parser.h"
vector<Tag> Parser::Vt = {
            PLUSSYM, 
            SUBSYM, 
            MULTSYM, 
            DIVSYM, 
            EQSYM,
            LSYM,
            GSYM,
            LEQSYM,
            GEQSYM,
            NUMSYM,     
            IDESYM,     
            IFSYM,      
            ELSESYM,    
            THENSYM,  
            WHILESYM,   
            BEGINSYM, 
            ENDSYM,    
            READSYM,   
            WRITESYM,  
            CALLSYM,   
            CONSTSYM,  
            VARSYM,    
            PROCSYM,  
            COMMASYM,  
            DOTSYM,   
            SEMSYM,    
            ASSIGNSYM, 
            NEQSYM,    
            LEFTBRACKET,   
            RIGHTBRACKET   
        };

vector<Tag> Parser::Vn  = {
            PROGRAM,    
            SENTENCE,   
            EXPRESSION, 
            CONDITION,  
            ITEM,       
            FACTOR      
        };

// vector <Tag> Parser::program_first = {
//         CONSTSYM,
//         VARSYM,
//         PROCSYM,
//         IDESYM,
//         CALLSYM,
//         IFSYM,
//         BEGINSYM,
//         WHILESYM
// };

// vector <Tag> Parser::program_follow = {
//         DOTSYM,
//         SEMSYM
// };

// vector <Tag> Parser::sentence_first = {
//         IDESYM,
//         CALLSYM,
//         BEGINSYM,
//         IFSYM,
//         WHILESYM
// };

// vector <Tag> Parser::sentence_follow = {
//         DOTSYM,
//         SEMSYM,
//         ENDSYM
// };

// vector <Tag> Parser::expression_first = {
//         PLUSSYM,
//         SUBSYM,
//         LEFTBRACKET,
//         IDESYM,
//         NUMSYM
// };

// vector <Tag> Parser::expression_follow = {
//         DOTSYM,
//         SEMSYM,
//         RIGHTBRACKET,
//         // R
//         EQSYM,
//         LSYM,
//         GSYM,
//         LEQSYM,
//         GEQSYM,
//         NEQSYM,

//         ENDSYM,
//         THENSYM,
//         DOSYM
// };

// vector <Tag> Parser::condition_first = {
//         ODDSYM,
//         PLUSSYM,
//         SUBSYM,
//         IDESYM,
//         NUMSYM
// };

// vector <Tag> Parser::condition_follow = {
//         THENSYM,
//         DOSYM
// };

// vector <Tag> Parser::item_first = {
//         IDESYM,
//         NUMSYM,
//         LEFTBRACKET
// };

// vector <Tag> Parser::item_follow = {
//         DOTSYM,
//         SEMSYM,
//         RIGHTBRACKET,
//         // R
//         EQSYM,
//         LSYM,
//         GSYM,
//         LEQSYM,
//         GEQSYM,
//         NEQSYM,

//         PLUSSYM,
//         SUBSYM,
//         ENDSYM,
//         THENSYM,
//         DOSYM
// };

// vector <Tag> Parser::factor_first = {
//         IDESYM,
//         NUMSYM,
//         LEFTBRACKET
// };

// vector <Tag> Parser::factor_follow = {
//         DOTSYM,
//         SEMSYM,
//         RIGHTBRACKET,
//         // R
//         EQSYM,
//         LSYM,
//         GSYM,
//         LEQSYM,
//         GEQSYM,
//         NEQSYM,

//         PLUSSYM,
//         SUBSYM,
//         MULTSYM,
//         DIVSYM,
//         ENDSYM,
//         THENSYM,
//         DOSYM
// };


void Parser::parse() {
    analysis.push(PSTART);
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

}

void Parser::generate () {
    
}