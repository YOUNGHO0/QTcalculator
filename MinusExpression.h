//
// Created by lee on 2024. 8. 8..
//

#ifndef MINUSEXPRESSION_H
#define MINUSEXPRESSION_H
#include "PostFixExpression.h"


class MinusExpression: public PostFixExpression {
public:
    MinusExpression(){};
    MinusExpression(PostFixExpression* left, PostFixExpression* right);

    PostFixExpression* left;
    PostFixExpression* right;

    int process() override;

};



#endif //MINUSEXPRESSION_H
