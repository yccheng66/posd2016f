#ifndef SHAPEMEDIA_H_INCLUDED
#define SHAPEMEDIA_H_INCLUDED

#include "Shapes.h"
#include <vector>

class Media {
public :
    virtual double area() const = 0 ;
};

class ShapeMedia :public Media {
private:
    Shape* shape ;
public :
    ShapeMedia( Shape* s ): shape(s) {}
    double area() const { return shape->area() ; }
};

class ComboMedia : public Media {
private:
    std::vector<Media*> media;
public:
    ComboMedia( std::vector<Media*> m ) : media(m) {}
    double area( ) const {
        double total =0;
            for (Media *m: media)
                total += m->area();
        return total;
    }
};





#endif // SHAPEMEDIA_H_INCLUDED
