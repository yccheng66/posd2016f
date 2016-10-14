#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <vector>
#include <string>
#include <sstream>


class Shape
{
public:
    virtual double area() const = 0;
    virtual std::string description() const {return std::string("");}
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
    std::string description() const {
        std::stringstream ss;
        ss << "r(" << x << " " << y << " " << l << " " << w << ") ";
        return ss.str();
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
    std::string description() const {
        std::stringstream ss;
        ss << "c(" << cx << " " << cy << " " << r << ") ";
        return ss.str();
    }
private:
    double cx,cy,r;
};


double sumOfArea(const std::vector<Shape *> & shapes)
{
    double total =0;
    for (Shape *s: shapes)
        total += s->area();
    return total;
}

#endif // SHAPES_H_INCLUDED
