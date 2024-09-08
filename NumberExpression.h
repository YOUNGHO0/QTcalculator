//
// Created by lee on 2024. 8. 8..
//

#ifndef NUMBEREXPRESSION_H
#define NUMBEREXPRESSION_H
#include "PostFixExpression.h"


class NumberExpression: public PostFixExpression{

    int number;
public:
    NumberExpression(){};
    NumberExpression(int number);
    int process() override;
};



#endif //NUMBEREXPRESSION_H
