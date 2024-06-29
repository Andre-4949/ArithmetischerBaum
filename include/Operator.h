#ifndef OpDef
#define OpDef

#include <iostream>
#include <string>
#include "Token.h"

class Operator : public Token {
private:
    Token *left, *right;

public:
    Operator(char type, char t, Token *l, Token *r) {
        left = l;
        right = r;
    }

    explicit Operator(char value) {
        type = 'o';
        this->value = value;
        left = nullptr;
        right = nullptr;
    }


    Token *getLeft() { return left; }

    Token *getRight() { return right; }

    int eval() {
        int result = this->left->eval();
        switch (this->value) {
            case '*':
                result *= this->right->eval();
                break;
            case '/':
                result /= this->right->eval();
                break;
            case '+':
                result += +this->right->eval();
                break;
            case '-':
                result -= this->right->eval();
                break;
        }
        return result;
    }

    string prefix() {
        return value + this->left->prefix() + this->right->prefix();
    }

    string infix() {
        return "(" + this->left->infix() + value + this->right->infix() + ")";

    }

    string postfix() {
        return this->left->postfix() + this->right->postfix() + value;
    }

    int nodes() {
        int nodesLeft = left->type == 'n' ? 1 : left->nodes();
        int nodesRight = right->type == 'n' ? 1 : right->nodes();
        return nodesLeft + 1 + nodesRight;//+1 fuer Elternknoten
//        return 1;
    }

    int depth() {
        return max(left->depth() + 1, right->depth() + 1);
    }

    void order(Order *o) {
        left->order(o);
        setOrd(++o->counter);
        right->order(o);
    }

    bool insertPrefix(Token *t) {
        bool hasBeenInserted = false;
        if (left == nullptr) {
            left = t;
            return true;
        } else if (left->type == 'o') {
            hasBeenInserted = left->insertPrefix(t);
        }

        if (hasBeenInserted)return true;

        if (right == nullptr) {
            right = t;
            return true;
        } else if (right->type == 'o') {
            return right->insertPrefix(t);
        }
        return hasBeenInserted;
    }

    bool insertPostfix(Token *t) override {
        bool hasBeenInserted = false;
        if (right == nullptr) {
            right = t;
            return true;
        } else if (right->type == 'o') {
            hasBeenInserted = right->insertPostfix(t);
        }

        if (hasBeenInserted)return true;

        if (left == nullptr) {
            left = t;
            return true;
        } else if (left->type == 'o') {
            return left->insertPostfix(t);
        }
        return hasBeenInserted;
    }

    string toString() override {
        return string(1,value);
    }

};

#endif //OpDef