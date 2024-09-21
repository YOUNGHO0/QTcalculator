cmake_minimum_required(VERSION 3.28)
project(calculatorPractice2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(calculatorPractice2 main.cpp
        Widget.h
        Widget.cpp
        PostFixExpression.h
        NumberExpression.h
        NumberExpression.cpp
        PostFixExpression.cpp
        PlusExpression.h
        PlusExpression.cpp
        MinusExpression.h
        MinusExpression.cpp
        MultiPlyExpression.h
        MultiPlyExpression.cpp
        DivideExpression.h
        DivideExpression.cpp)
target_link_libraries(calculatorPractice2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

