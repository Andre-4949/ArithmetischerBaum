#include <iostream>
#include <queue>
#include "../include/Tokenizer.h"
#include "Util.h"
#include "../include/Evaluator.h"

int main() {
    Tokenizer tokenizer = Tokenizer("((2+3)*(5+(4*4)))");
    auto vec = *tokenizer.tokenize();
    Evaluator evaluator = Evaluator();
    //((2+3)*(5+(4*4)))+(7*8-(9/3)+(10/10))
    evaluator.evaluate("2 3 +5 4 4 *+*7 8 *9 3 /-10 10 /++", '>');
    cout << endl;

//    std::queue<Token *> preOrder;
//    deque<vector<Token *>> tokensToInsert = Util::splitVectorAtOperator(vec);
//    Token *start = tokensToInsert[0][0];
//    tokensToInsert.erase(tokensToInsert.begin());
//    while (!tokensToInsert.empty()) {
//        if (tokensToInsert[0].size() > 1) {
//            deque<vector<Token *>> newTokensToInsert = Util::splitVectorAtOperator(tokensToInsert[0]);
//            tokensToInsert.erase(tokensToInsert.begin());
//            std::reverse(newTokensToInsert.begin(), newTokensToInsert.end());
//
//            for (const auto &item: newTokensToInsert) {
//                tokensToInsert.insert(tokensToInsert.begin(), item);
//            }
//        } else {
//            start->insertPrefix(tokensToInsert[0][0]);
//            preOrder.push(tokensToInsert[0][0]);
////                std::cout << tokensToInsert[0][0]->value << std::endl;
//            tokensToInsert.erase(tokensToInsert.begin());
//        }
//    }
//    while (!preOrder.empty()) {
//        if(preOrder.front()->type=='n')
//            std::cout << ((Num*)preOrder.front())->number;
//        else
//            std::cout << (char)preOrder.front()->value;
//        preOrder.pop();
//    }



    return 0;
}
