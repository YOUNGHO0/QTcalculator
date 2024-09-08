//
// Created by lee on 2024. 8. 6..
//

#include "Widget.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <set>
#include <stack>
#include <queue>

#include "DivideExpression.h"
#include "MinusExpression.h"
#include "MultiPlyExpression.h"
#include "NumberExpression.h"
#include "PlusExpression.h"
#include "PostFixExpression.h"

Widget::Widget(QWidget *parent):QWidget(parent) {

    resize(300,700);
    label = new QLabel(this);
    label->setText("0");
    label->setStyleSheet("border: 2px solid black;"
                         "margin:20px;"
                         "font-size: 30px"
                         );
    label->resize(300, 100);
    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QString keyboardLayout [5][4] ={
            "7","8","9","+",
            "4","5","6", "-",
            "1","2","3", "*",
            "0","C","=", "/",
             "()","","","",

    };

    QGridLayout * layout = new QGridLayout(this);




    std::set<QString>extra = {"C","=","()"};
    for(int i =0; i<5; i++) {
        for(int j=0; j<4; j++) {
            if(extra.find(keyboardLayout[i][j]) != extra.end()) {

                QPushButton *p = new QPushButton(keyboardLayout[i][j]);
                layout->addWidget(p,i,j);
                if(keyboardLayout[i][j]== "=")
                    connect(p,&QPushButton::clicked,this,&Widget::equal);
                if(keyboardLayout[i][j]=="()"){
                    connect(p,&QPushButton::clicked,this,&Widget::brace);
                }
                if(keyboardLayout[i][j]== "C")
                    connect(p,&QPushButton::clicked,this,&Widget::clear);
                continue;
            }

            QPushButton *p = new QPushButton(keyboardLayout[i][j]);
            layout->addWidget(p,i,j);
            connect(p,&QPushButton::clicked,this,&Widget::character);
        }
    }




}

void Widget::brace() {

    if(braceOpen) {
        QString labelText = this->label->text();
        label->setText(labelText.append(")"));
        braceOpen = false;
    }
    else {
        QString labelText = this->label->text();
        label->setText(labelText.append("("));
        braceOpen = true;
    }
}

void Widget::clear() {
    label->setText("0");
}

bool isOperator(QChar oper) {
    if(oper == '+' || oper== '-' || oper == '*' || oper == '/') {
            return true;
    }
    return false;
}


void Widget::pushNumbertoResult(std::queue<QString>& result, int &number, bool &beforeWasNumber) {
    result.push(QString::number(number));
    number = 0;
    beforeWasNumber = false;
}

void Widget::equal() {
    QString string = label->text();
    std::queue<QString> result;
    std::map<QChar,int> prioritesMap{{'+',0},{'-',0},{'*',1},{'/',1},{'(',-1},{')',-1}};
    int number = 0;
    std::stack<QChar> opStack;
    bool beforeWasNumber = false;
    for(int i =0; i<string.size();i++) {

        if(isOperator(string[i])) {
            if(beforeWasNumber) {
                pushNumbertoResult(result, number, beforeWasNumber);
            }
            while(!opStack.empty() && prioritesMap.at(opStack.top()) >= prioritesMap.at(string[i])) {
                result.push(opStack.top());
                opStack.pop();
            }
            opStack.push(string[i]);
        }
        else if(string[i] == ')') {
            if(beforeWasNumber) {
                pushNumbertoResult(result, number, beforeWasNumber);
            }
            qDebug() << "°ýÈ£ ¸¸³²";
            while(!opStack.empty() && opStack.top() != '(') {
                result.push(opStack.top());
                opStack.pop();
            }
            opStack.pop();
        }
        else if(string[i]== '(') {
            if(beforeWasNumber) {
                pushNumbertoResult(result, number, beforeWasNumber);
            }
            opStack.push(string[i]);
        }
        else {
            number *= 10;
            number += string[i].digitValue();
            beforeWasNumber = true;
        }
    }

    if(number !=0) result.push(QString::number(number));
    while(!opStack.empty()) {
        result.push(opStack.top());
        opStack.pop();
    }


    std::stack<PostFixExpression *> expressionStack;
    std::stack<int> numberStack;
    while(!result.empty()) {
        QString string = result.front();
        result.pop();
        int numberCount = 0;
        int left = 0;
        int right = 0;
        PostFixExpression * leftNumber;
        PostFixExpression * rightNumber;
        PostFixExpression * op;
        if(string.size() ==1) {
            QChar mChar = string[0];
            if(mChar == '+' || mChar == '-' || mChar == '*' || mChar=='/') {
                switch (mChar.toLatin1()) {
                    case '+':
                        leftNumber = expressionStack.top();
                        expressionStack.pop();
                        rightNumber = expressionStack.top();
                        expressionStack.pop();
                        op = new  PlusExpression(leftNumber,rightNumber);
                        expressionStack.push(op);
                        break;
                    case '-':
                        leftNumber = expressionStack.top();
                        expressionStack.pop();
                        rightNumber = expressionStack.top();
                        expressionStack.pop();
                        op = new MinusExpression(leftNumber,rightNumber);
                        expressionStack.push(op);
                        break;
                    case '*':
                        leftNumber = expressionStack.top(); expressionStack.pop();
                        rightNumber =expressionStack.top(); expressionStack.pop();
                        op = new  MultiPlyExpression(leftNumber,rightNumber);
                        expressionStack.push(op);
                        break;
                    case '/':
                        leftNumber = expressionStack.top(); expressionStack.top();
                        rightNumber =expressionStack.top(); expressionStack.top();
                        op = new DivideExpression(leftNumber,rightNumber);
                        expressionStack.push(op);
                        break;
                }
            }
            else {
                expressionStack.push(new NumberExpression(string.toInt()));
            }
        }
        else {
            expressionStack.push(new NumberExpression(string.toInt()));
        }
    }
    label->setText(QString::number(expressionStack.top()->process()));
}

void Widget::character() {

    QPushButton * p = qobject_cast<QPushButton*>(sender());

    if(label->text() == "0") {
        label->setText("");
    }
    QString labelText = this->label->text();
    label->setText(labelText.append(p->text()));

}
