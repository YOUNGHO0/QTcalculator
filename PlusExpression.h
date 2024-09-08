//
// Created by lee on 2024. 8. 8..
//

#ifndef PLUSEXPRESSION_H
#define PLUSEXPRESSION_H
#include "PostFixExpression.h"


class PlusExpression:public PostFixExpression {
public:
    PlusExpression(){};
    PlusExpression(PostFixExpression* left, PostFixExpression* right);
    PostFixExpression* left;
    PostFixExpression* right;
    int process() override;


};



#endif //PLUSEXPRESSION_H
