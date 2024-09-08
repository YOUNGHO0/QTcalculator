//
// Created by lee on 2024. 8. 8..
//

#ifndef MULTIPLYEXPRESSION_H
#define MULTIPLYEXPRESSION_H
#include "PostFixExpression.h"


class MultiPlyExpression: public PostFixExpression {
public:
    MultiPlyExpression(){};
    MultiPlyExpression(PostFixExpression* left, PostFixExpression* right);
    PostFixExpression* left;
    PostFixExpression* right;
    int process() override;

};



#endif //MULTIPLYEXPRESSION_H
