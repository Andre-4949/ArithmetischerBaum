//
// Created by andre on 27.06.2024.
//

#ifndef LABORRECHENBAUM_UTIL_H
#define LABORRECHENBAUM_UTIL_H


#include <vector>
#include <deque>
#include "../include/Token.h"

class Util {
public:
    static std::deque<std::vector<Token *>> splitVectorAtOperator(std::vector<Token *> tokens) {
        int openBrackets = 0;
        int index = -1;
        bool splitAtAdditionSubtraction = false;
        for (int i = 0; i < tokens.size() - 1; i++) {
            Token *item = tokens[i];
            if (item->type == 'b') {
                if (item->value == '(')openBrackets++;
                if (item->value == ')')openBrackets--;
                continue;
            }
            if (openBrackets >= 1)continue;
            if (item->type == 'o') {
                if ((item->value == '+' || item->value == '-')) {
                    index = i;
                    splitAtAdditionSubtraction = true;
                }
                if ((item->value == '*' || item->value == '/') && !splitAtAdditionSubtraction) {
                    index = i;

                }
            }
        }
        if (index == -1) {
            auto first = ++tokens.begin();
            auto last = --tokens.end();
            vector<Token *> newVec(first, last);
            return splitVectorAtOperator(newVec);
        }
        auto first = tokens.begin();
        auto mid = tokens.begin() + index;
        auto last = tokens.end();
        vector<Token *> firstHalf(first, mid);
        vector<Token *> secondHalf(mid + 1, last);
        vector<Token *> middle = {tokens[index]};
        deque <vector<Token *>> result = {middle, firstHalf, secondHalf};
        result.shrink_to_fit();
        return result;

    }

};


#endif //LABORRECHENBAUM_UTIL_H
