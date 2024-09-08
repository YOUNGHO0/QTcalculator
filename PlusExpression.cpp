//
// Created by lee on 2024. 8. 8..
//

#include "PlusExpression.h"



PlusExpression::PlusExpression(PostFixExpression *left, PostFixExpression *right):left(left),right(right) {
}

int PlusExpression::process() {
    return left->process() + right->process();
}
