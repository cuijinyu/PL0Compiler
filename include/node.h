#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node{
    public:
        Node (string type) {
            this -> type = type;
        };
        ~Node () {

        };
    private:
        string type;
};
#endif