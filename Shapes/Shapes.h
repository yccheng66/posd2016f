#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

class Rectangle {
public:
    Rectangle(double ulcx, double ulcy, double length, double width):
        x(ulcx),y(ulcy),l(length),w(width){}
    double area() const {return l*w;}
private:
    double x,y,l,w;
};

#endif // SHAPES_H_INCLUDED
