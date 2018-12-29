#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <stack>
#include <ast.h>
using namespace std;
class Identifier_node:public Ast {
    public:
        Identifier_node (string type) {
            this -> type = type;
        };
        void set_identifier (Token * identifier) {
            identifier_token = identifier;
            this -> identifier = identifier_token -> get_lexem();
            line = identifier_token -> get_line();
        };
    private:
        string identifier;
        Token * identifier_token;
};

class Num_node:public Ast {
    public:
        Num_node (string type) {
            this -> type = type;
        };
        void set_number (Token * num_token) {
            this -> num_token = num_token;
            num = stoi(num_token -> get_lexem());
            line = num_token -> get_line();
        }
    private:
        string type;
        Token * num_token;
        int num;
};

class Term_node:public Ast {
    public:
        Term_node (string type) {
            this -> type = type;
        }
    private:
        Ast * term;
};

class Factor_node:public Ast {
    public:
        Factor_node (string type) {
            this -> type = type;
        }
    private:
};

class Read_statement_node:public Ast {
    public:
        Read_statement_node (string type) {
            this -> type = type;
        };

        void set_read_identifier (Token * read_identifier) {
            this -> read_identifier = read_identifier;
        };
    private:
        Token * read_identifier;
};

class Write_statement_node:public Ast {
    public:
        Write_statement_node (string type) {
            this -> type = type;
        }
    private:
        Token * write_identifier;
};

class Complex_statement_node:public Ast {
    public:
        Complex_statement_node (string type) {
            this -> type = type;
        }
    private:
};

class Call_statement_node:public Ast {
    public:
        Call_statement_node (string type) {
            this -> type = type;
        }
    private:
};

class While_statement_node:public Ast {
    public:
        While_statement_node (string type) {
            this -> type = type;
        }
    private:
};

class Condition_statement_node:public Ast {
    public:
        Condition_statement_node (string type) {
            this -> type = type;
        }
    private:
};

class Assign_statement_node:public Ast {
    public:
        Assign_statement_node (string type) {
            this -> type = type;
        }
    private:
};

class Statement_node:public Ast {
    public:
        Statement_node (string type) {
            this -> type = type;
        }
    private:
};

class Const_node:public Ast {
    public:
        Const_node (string type) {
            this -> type = type;
        }
    private:
};

class Const_declare_node:public Ast {
    public:
        Const_declare_node (string type) {
            this -> type = type;
        }
    private:
};

class Var_declare_node:public Ast {
    public:
        Var_declare_node (string type) {
            this -> type = type;
        }
    private:
};

class Expression_node:public Ast {
    public:
        Expression_node (string type) {
            this -> type = type;
        }
    private:
};
#endif