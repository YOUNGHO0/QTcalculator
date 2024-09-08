//
// Created by lee on 2024. 8. 8..
//

#ifndef DIVIDEEXPRESSION_H
#define DIVIDEEXPRESSION_H
#include "PostFixExpression.h"


class DivideExpression :public PostFixExpression {
public:
    DivideExpression(){};
    DivideExpression(PostFixExpression* left, PostFixExpression * right);
    PostFixExpression* left;
    PostFixExpression* right;

    int process() override;
};



#endif //DIVIDEEXPRESSION_H
