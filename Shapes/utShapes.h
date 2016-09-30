#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include <vector>

const double epsilon = 0.000001;
// added this line
TEST (first, Rectangle) {
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(8,rect.area(),epsilon);
}

TEST(sencond,Circle)
{
    Circle circ(0,0,10);
    DOUBLES_EQUAL(300,circ.area(),epsilon);
}

TEST (fifth, sumOfArea) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    std::vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    DOUBLES_EQUAL(308,sumOfArea(ss),epsilon);
}
#endif // UTSHAPES_H_INCLUDED
