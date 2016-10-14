#ifndef SHAPEMEDIA_H_INCLUDED
#define SHAPEMEDIA_H_INCLUDED

#include "Shapes.h"
#include <vector>
#include <string>

class ShapeMedia;
class ComboMedia;
class DescriptionVisitor {
public:
    DescriptionVisitor (): desc(std::string("")) {}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm);
    std::string getDescription() const {return desc;}
private:
    std::string desc;
};

class Media {
public :
    virtual double area() const = 0 ;
    virtual void accept(DescriptionVisitor * dv) = 0;
    virtual void add(Media * m) {
        throw std::string("Illegal: add on media");
    }
};

class ShapeMedia :public Media {
private:
    Shape* shape ;
public :
    ShapeMedia( Shape* s ): shape(s) {}
    virtual void accept(DescriptionVisitor * dv) {
        dv->visitShapeMedia(this);
    }
    double area() const { return shape->area() ; }
    Shape * getShape()const {return shape;}
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
    void accept(DescriptionVisitor * dv) {
        for (Media *m: media)
            m->accept(dv);
        dv->visitComboMedia(this);
    }
    void add (Media *m) {
        media.push_back(m);
    }
};

void DescriptionVisitor::visitShapeMedia(ShapeMedia *sm) {
    desc += sm->getShape()->description();
}

void DescriptionVisitor::visitComboMedia(ComboMedia *cm) {
    desc = std::string("combo(")+desc+std::string(")");
}
#endif // SHAPEMEDIA_H_INCLUDED
