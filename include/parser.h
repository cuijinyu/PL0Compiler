#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <set>
#include <map>
// #include <pair>
#include <vector>
#include <stack>
#include <token.h>
using namespace std;


// 这是一个特殊的语法分析器，其中的block部分采用LL1语法分析，其他部分使用递归下降

/**
 * Production
 * 用于表示产生式的数据结构
 **/
typedef struct Production {
        string production_string;
        Tag start_tag;
        vector <Tag> aim_tags;
}Production;

// LL(1) 语法分析器
class Parser {
    public:
        Parser (vector <Token *> tokens) {
            this -> tokens = tokens;
            this -> init_first();
            this -> init_follow();
        };

        ~ Parser () = default;

        void show_tokens () {
            for (auto i:tokens) {
                cout << i -> get_lexem() << endl;
            }
        }

        // 根据Tag判断是否在其的First集合中
        bool in_first (Tag t, string pro);

        // 根据Tag判断是否在其的Follow集合中
        bool in_follow (Tag t, string pro);

        // 根据预测分析表，将非终结符推导   
        void generate ();

        // 判断是否为非终结符
        bool is_vn (Tag t);

        // 判断是否为终结符 
        bool is_vt (Tag t);

        // 开始语法分析
        void parse ();

        // 向前看的两个方法
        Tag get_next_token ();

        Token * look_next_token();

        void put_back_token ();

        // 生成预测分析表
        void generate_table ();

        // 初始化first集合
        void init_first ();

        // 初始化follow集合
        void init_follow ();

        // 判断token是否匹配
        bool match (Tag aim_token,Token * temp_token);

        //
        // 以下是递归下降实现
        //

        void program ();

        void block ();

        void statement ();

        void condition ();

        void expression ();

        void term ();

        void factor ();

        void const_declare ();

        void var_declare ();

        void procedure_declare ();

        void assign_statement ();

        void condition_statement ();

        void while_statement ();

        void call_statement ();

        void read_statement ();

        void complex_statement ();

        void write_statement ();

        // 错误汇报函数
        void error(Tag code, string type,int line);

        // 以下是LL(1)实现的block部分
        void block_ll1();

        // 判断元素是否在set中
        bool is_in (Tag t, set <Tag> s);
    private:
        // 向前看Tag
        Token* lookahead;

        // 预测分析表
        vector <vector <Tag>> table;
        
        // 各个产生式的Ftsirst集合
        map <string, set<Tag> > firsts;

        // 各个产生式的Follow集合
        map <string, set<Tag> > follows;

        // 分析栈
        stack <Tag> analysis;

        // 剩余字符栈
        stack <Tag> lost;

        // token列表
        vector <Token *> tokens;

        // 产生式列表
        static vector <Production> productions;

        // 定义各个非终结符的First与Follow集合
        static set <Tag> program_first;
        static set <Tag> program_follow;
        static set <Tag> sentence_first;
        static set <Tag> sentence_follow;
        static set <Tag> expression_first;
        static set <Tag> expression_follow;
        static set <Tag> condition_first;
        static set <Tag> condition_follow;
        static set <Tag> item_first;
        static set <Tag> item_follow;
        static set <Tag> factor_first;
        static set <Tag> factor_follow;

        // 终结符集合
        static vector <Tag> Vt;

        // 非终结符集合
        static vector <Tag> Vn;

        static set <Tag> block_start;
};

vector <Production> Parser::productions = {

};

vector <Tag> Parser::Vt = {
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

vector <Tag> Parser::Vn  = {
            PROGRAM,    
            SENTENCE,   
            EXPRESSION, 
            CONDITION,  
            ITEM,       
            FACTOR      
        };

set <Tag> Parser::program_first = {
        CONSTSYM,
        VARSYM,
        PROCSYM,
        IDESYM,
        CALLSYM,
        IFSYM,
        BEGINSYM,
        WHILESYM
};

set <Tag> Parser::program_follow = {
        DOTSYM,
        SEMSYM
};

set <Tag> Parser::sentence_first = {
        IDESYM,
        CALLSYM,
        BEGINSYM,
        IFSYM,
        WHILESYM
};

set <Tag> Parser::sentence_follow = {
        DOTSYM,
        SEMSYM,
        ENDSYM
};

set <Tag> Parser::expression_first = {
        PLUSSYM,
        SUBSYM,
        LEFTBRACKET,
        IDESYM,
        NUMSYM
};

set <Tag> Parser::expression_follow = {
        DOTSYM,
        SEMSYM,
        RIGHTBRACKET,
        // R
        EQSYM,
        LSYM,
        GSYM,
        LEQSYM,
        GEQSYM,
        NEQSYM,

        ENDSYM,
        THENSYM,
        DOSYM
};

set <Tag> Parser::condition_first = {
        ODDSYM,
        PLUSSYM,
        SUBSYM,
        IDESYM,
        NUMSYM
};

set <Tag> Parser::condition_follow = {
        THENSYM,
        DOSYM
};

set <Tag> Parser::item_first = {
        IDESYM,
        NUMSYM,
        LEFTBRACKET
};

set <Tag> Parser::item_follow = {
        DOTSYM,
        SEMSYM,
        RIGHTBRACKET,
        // R
        EQSYM,
        LSYM,
        GSYM,
        LEQSYM,
        GEQSYM,
        NEQSYM,

        PLUSSYM,
        SUBSYM,
        ENDSYM,
        THENSYM,
        DOSYM
};

set <Tag> Parser::factor_first = {
        IDESYM,
        NUMSYM,
        LEFTBRACKET
};

set <Tag> Parser::factor_follow = {
        DOTSYM,
        SEMSYM,
        RIGHTBRACKET,
        // R
        EQSYM,
        LSYM,
        GSYM,
        LEQSYM,
        GEQSYM,
        NEQSYM,

        PLUSSYM,
        SUBSYM,
        MULTSYM,
        DIVSYM,
        ENDSYM,
        THENSYM,
        DOSYM
};

set <Tag> Parser::block_start = {
        CONSTSYM,
        VARSYM,
        PROCSYM
};

void Parser::error (Tag code, string type, int line ) {
    cout << "Syntax Error: type ->" << type <<" [Code]:"<< code << " at line " << line << endl;
}

void Parser::init_first () {
    // program
    string program = "program";
    auto pair_pro = make_pair(program, program_first);
    firsts.insert(pair_pro);

    // sentence
    string sentence = "sentence";
    auto pair_sen = make_pair(sentence, sentence_first);
    firsts.insert(pair_sen);

    // expression
    string expression = "expression";
    auto pair_exp = make_pair(expression, expression_first);
    firsts.insert(pair_exp);

    // condition
    string condition = "condition";
    auto pair_con = make_pair(condition, condition_first);
    firsts.insert(pair_con);

    // item
    string item = "item";
    auto pair_item = make_pair(item, item_first);
    firsts.insert(pair_item);

    // factor
    string factor = "factor";
    auto pair_factor = make_pair(factor, factor_first);
    firsts.insert(pair_factor);
}

void Parser::init_follow () {
    // program
    string program = "program";
    auto pair_pro = make_pair(program, program_follow);
    follows.insert(pair_pro);

    // sentence
    string sentence = "sentence";
    auto pair_sen = make_pair(sentence, sentence_follow);
    follows.insert(pair_sen);

    // expression
    string expression = "expression";
    auto pair_exp = make_pair(expression, expression_follow);
    follows.insert(pair_exp);

    // condition
    string condition = "condition";
    auto pair_con = make_pair(condition, condition_follow);
    follows.insert(pair_con);

    // item
    string item = "item";
    auto pair_item = make_pair(item, item_follow);
    follows.insert(pair_item);

    // factor
    string factor = "factor";
    auto pair_factor = make_pair(factor, factor_follow);
    follows.insert(pair_factor);
}


void Parser::parse() {
    // analysis.push(PSTART);

    // 当token没有被消费完的时候，调用program
    while (look_next_token() -> get_tag() != PROEND) {
        program();
    }
    
}

// 获取token列表中下一个token，当程序结束时，返回PROEND这个Tag
Tag Parser::get_next_token () {
    if (!tokens.empty()) {
        Token * temp_token = tokens[0];
        tokens.erase(tokens.begin());
        lookahead = temp_token;
        return temp_token -> get_tag();
    }
    else return PROEND;
}

Token * Parser::look_next_token () {
    if (!tokens.empty()) {
        return tokens[0];
    }
}

// void Parser::put_back_token () {
//     tokens.insert(0, lookahead);
// }

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
}

void Parser::block () {
    do {
        Token * temp_token = look_next_token();
        if (match(CONSTSYM, temp_token)) {
            get_next_token();
            const_declare();
            while(match(COMMASYM, look_next_token())) {
                get_next_token();
                const_declare();
            }
            if (!match(SEMSYM, look_next_token())) {
                error(SEMSYM, "const ", look_next_token() -> get_line());
            }

            get_next_token();
        } else if (match(VARSYM, temp_token)) {
            get_next_token();
            var_declare();
            if (!match(SEMSYM, look_next_token())) {
                error(SEMSYM, "var ", look_next_token() -> get_line());
            }
            get_next_token();
        } else if (match(PROCSYM, temp_token)) {
            procedure_declare();
        }
    } while (is_in(look_next_token() -> get_tag(), block_start));
        statement();
}

void Parser::statement () {
    switch (look_next_token() -> get_tag()) {
        case BEGINSYM:
            complex_statement();
            break;
        case IDESYM:
            assign_statement();
            break;
        case IFSYM:
            condition_statement();
            break;
        case WHILESYM:
            while_statement();
            break;
        case CALLSYM:
            call_statement();
            break;
        case READSYM:
            read_statement();
            break;
        case WRITESYM:
            write_statement();
            break;
        default:
            return;
    }
}

void Parser::condition () {
    if (match(ODDSYM, look_next_token())) {
        get_next_token();
        expression();
    }
    expression();
    if (!(match(EQSYM, look_next_token())||
        match(NEQSYM, look_next_token())||
        match(LEQSYM, look_next_token())||
        match(LSYM, look_next_token())||
        match(GSYM, look_next_token())||
        match(GEQSYM, look_next_token()))) {
            error(EQSYM, "conditioin", look_next_token() -> get_line());
    }
    get_next_token();
    expression();
}

void Parser::expression () {
    if (match(PLUSSYM, look_next_token())||
        match(SUBSYM, look_next_token())) {
            get_next_token();
    }
    term();
    get_next_token();
    if (match(PLUSSYM, look_next_token())||
        match(SUBSYM, look_next_token())
        // match(MULTSYM, look_next_token())||
        // match(DIVSYM, look_next_token())
        ) {
            get_next_token();
            term();
            get_next_token();
    }
}

void Parser::term () {
    factor();
    if (match(MULTSYM, tokens[1])||
        match(DIVSYM, tokens[1])) {
            get_next_token();
            get_next_token();
            factor();
    }
} 

void Parser::factor () {
    switch (look_next_token() -> get_tag()) {
        case IDESYM:
            break;
        case NUMSYM:
            break;
        case LEFTBRACKET:
            expression();
            if (!match(RIGHTBRACKET, look_next_token())) {
                error(RIGHTBRACKET, "factor", look_next_token() -> get_line());
            }
            break;
    }
}

void Parser::const_declare () {
    if (!match(IDESYM, look_next_token())) {
        error(IDESYM, "const declare", look_next_token() -> get_line());
    }
    get_next_token();
    if (!match(EQSYM, look_next_token())) {

    }
    get_next_token();
    if (!match(NUMSYM, look_next_token())) {
        error(NUMSYM, "const declare", look_next_token() -> get_line());
    }
    get_next_token();
}

void Parser::var_declare () {
    if (!match(IDESYM, look_next_token())) {
        error(IDESYM, "var declare", look_next_token() -> get_line());
    }
    get_next_token();
    while (match(COMMASYM, look_next_token())) {
        get_next_token();
        if (!match(IDESYM, look_next_token())) {
            error(IDESYM, "var declare", look_next_token() -> get_line());
        }
        get_next_token();
    }
}

void Parser::procedure_declare () {
    get_next_token();
    if (!match(IDESYM, look_next_token())) {
        error(IDESYM, "procedure header", look_next_token() -> get_line());
    }

    get_next_token();
    if (!match(SEMSYM, look_next_token())) {
        error(SEMSYM, "procedure declare", look_next_token() -> get_line());
    }

    get_next_token();
    block();
    if (!match(SEMSYM, look_next_token())) {
        error(SEMSYM, "procedure declare", look_next_token() -> get_line());
    }

    get_next_token();
    if (match(PROCSYM, look_next_token())) {
        procedure_declare();
    }
}

void Parser::assign_statement () {
    get_next_token();
    if (!match(ASSIGNSYM, look_next_token())) {
        error(ASSIGNSYM, "assign", look_next_token() -> get_line());
    }
    get_next_token();
    expression();
}

void Parser::condition_statement () {
    get_next_token();
    condition();
    if (!match(THENSYM, look_next_token())) {
        error(THENSYM, "condition statement", look_next_token() -> get_line());
    }
    get_next_token();
    statement();
    if (match(ELSESYM, look_next_token())) {
        get_next_token();
        statement();
    }
}

void Parser::while_statement () {
    if (!match(WHILESYM, look_next_token())) {
        error(WHILESYM, "while", look_next_token() -> get_line());
    }
    get_next_token();
    condition();
    // get_next_token();
    if (!match(DOSYM, look_next_token())) {
        error(DOSYM, "while", look_next_token() -> get_line());
    }
    get_next_token();
    statement();
}

void Parser::call_statement () {
    get_next_token();
    if (!match(IDESYM, look_next_token())) {
        error(IDESYM, "call", look_next_token() -> get_line());
    }
    get_next_token();
}

void Parser::read_statement () {
    if (!match(READSYM, look_next_token())) {
        error(READSYM, "read statement", look_next_token() -> get_tag());
    }
    get_next_token();
}

void Parser::write_statement () {
    if (!match(WRITESYM, look_next_token())) {
        error(WRITESYM, "write statement", look_next_token() -> get_tag());
    }
    get_next_token();
    if (!match(LEFTBRACKET, look_next_token())) {
        error(LEFTBRACKET, "write statement", look_next_token() -> get_line());
    }
    get_next_token();
    if (!match(IDESYM, look_next_token())) {
        error(IDESYM, "write statement", look_next_token() -> get_line());
    }
    get_next_token();
    while (match(COMMASYM, look_next_token())) {
        get_next_token();
        if (!match(IDESYM, look_next_token())) {
            error(IDESYM, "write statement", look_next_token() -> get_line());
        }
        get_next_token();
    }
    if (!match(RIGHTBRACKET, look_next_token())) {
        error(RIGHTBRACKET, "right statement", look_next_token() -> get_line());
    }
    get_next_token();
}

void Parser::complex_statement () {
    get_next_token();
    statement();
    while(match(SEMSYM, look_next_token())) {
        get_next_token();
        if (match(ENDSYM, look_next_token())) {
            get_next_token();
            // error(ENDSYM, "complex statement", look_next_token() -> get_line());
            return;
        }
        statement();
    }
}

bool Parser::match (Tag aim_token, Token * temp_token) {
    if (aim_token == temp_token -> get_tag()) {
        return true;
    } else {
        return false;
    }
}

bool Parser::is_in (Tag t, set <Tag> s) {
    return s.find(t) != s.end();
}
#endif