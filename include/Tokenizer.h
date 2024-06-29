#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "Num.h"
#include "Bracket.h"
#include "Operator.h"


using namespace std;

class Tokenizer {
    static inline std::vector<char> operators = {'+', '-', '*', '/'};
    string src;

public:
    Tokenizer(string s) {
        src = s + " ";
    }

    vector<Token *> *tokenize() {
        vector<Token *> *tokens = new std::vector<Token *>();

        for (int j = 0; j < this->src.length(); ++j) {
            char currentChar = src[j];
            int numStartIndex = j;
            bool isNum = false;
            if (currentChar == '(' || currentChar == ')') {
                tokens->push_back(new Bracket(currentChar));
            }
            while (currentChar >= '0' && currentChar <= '9') {
                isNum = true;
                currentChar = src[j++];
            }
            if (isNum) {
                j--;
                std::string numAsStr = this->src.substr(numStartIndex, j-- - numStartIndex);
                Num* num = new Num(std::stoi(numAsStr));
                tokens->push_back(num);
            } else if (std::any_of(operators.begin(), operators.end(),
                                   [currentChar](char c) { return currentChar == c; })) {
                tokens->push_back(new Operator(currentChar));
            }
        }
//        cout << "Die Methode Tokenizer.tokenize ist noch nicht implementiert!" << endl; // remove this line

        return tokens;
    }

};