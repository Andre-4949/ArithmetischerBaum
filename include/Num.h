#pragma once

#include <iostream>
#include <string>
#include "Token.h"

class Num : public Token {

public:
    int number{};

    Num() = default; // DIESEN LEEREN STANDARDKONSTRUKTOR NICHT LOESCHEN
    explicit Num(int i) {
        this->type = 'n';
        number = i;
        value = i;
    }

    int eval() {
        return number;
    }

    string prefix() {
        return std::to_string(number)+" ";
    }

    string infix() {
        return std::to_string(number);
    }

    string postfix() {
        return std::to_string(number)+" ";
    }

    void order(Order o) {
        setOrd(++o.counter);
    }

    bool insertPrefix(Token *t) override {
        return true;
    }

    string toString() override {
        return std::to_string(number);
    }

};