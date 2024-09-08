//
// Created by lee on 2024. 8. 6..
//

#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>
#include <queue>
#include <QtWidgets/qwidget.h>


class Widget: public QWidget{

public:
    bool braceOpen = false;
    QLabel * label;
    Widget(QWidget * parent= 0);

    public slots:
    void brace();
    void clear();

    void pushNumbertoResult(std::queue<QString>& result, int &number, bool &beforeWasNumber);

    void equal();
    void character();
};



#endif //WIDGET_H
