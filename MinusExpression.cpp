//
// Created by lee on 2024. 8. 8..
//

#include "MinusExpression.h"


MinusExpression::MinusExpression(PostFixExpression *left, PostFixExpression *right):left(left),right(right) {
}

int MinusExpression::process() {
    return left->process() - right->process();
}
