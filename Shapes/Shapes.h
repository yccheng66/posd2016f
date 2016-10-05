#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <vector>



class Shape
{
public:
    virtual double area() const = 0;
};

double sumOfArea(const std::vector<Shape *> & shapes);

class Rectangle : public Shape
{
public:
    Rectangle(double ulcx, double ulcy, double length, double width):
        x(ulcx),y(ulcy),l(length),w(width) {}
    double area() const
    {
        return l*w;
    }
private:
    double x,y,l,w;
};

class Circle : public Shape
{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius) {}
    double area()const
    {
        return 3*r*r;
    }
private:
    double cx,cy,r;
};

class ComboShape : public Shape
{
public:
    ComboShape(const std::vector<Shape*>& shapes):shapes(shapes) {}

    double area() const
    {
        return sumOfArea(shapes);
    }

    void add(Shape* shape){
    shapes.push_back(shape);
    }

private:
    std::vector<Shape*> shapes;
};

double sumOfArea(const std::vector<Shape *> & shapes)
{
    double total =0;
    for (Shape *s: shapes)
        total += s->area();
    return total;
}

#endif // SHAPES_H_INCLUDED
