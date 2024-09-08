//
// Created by lee on 2024. 8. 8..
//

#include "MultiPlyExpression.h"

MultiPlyExpression::MultiPlyExpression(PostFixExpression *left, PostFixExpression *right):left(left),right(right) {
}

int MultiPlyExpression::process() {
    return left->process() * right->process();
}
