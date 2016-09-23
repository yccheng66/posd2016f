#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <vector>

class Shape {
public:
    virtual double area() const = 0;
};
class Rectangle : public Shape {
public:
    Rectangle(double ulcx, double ulcy, double length, double width):
        x(ulcx),y(ulcy),l(length),w(width){}
    double area() const {return l*w;}
private:
    double x,y,l,w;
};

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius){}
    double area()const {return 3*r*r;}
private:
    double cx,cy,r;
};

double sumOfArea(std::vector<Rectangle> rects) {
    double total =0;
    for (Rectangle r: rects)
        total += r.area();
    return total;
}

double sumOfArea(std::vector<Shape *> rects) {
    double total =0;
    for (Shape *r: rects)
        total += r->area();
    return total;
}

#endif // SHAPES_H_INCLUDED
