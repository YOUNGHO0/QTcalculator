//
// Created by lee on 2024. 8. 8..
//

#include "DivideExpression.h"


DivideExpression::DivideExpression(PostFixExpression *left, PostFixExpression *right):left(left),right(right) {
}

int DivideExpression::process() {
    return left->process() / right->process();
}
