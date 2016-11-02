#ifndef SHAPEMEDIA_H_INCLUDED
#define SHAPEMEDIA_H_INCLUDED

#include "Shapes.h"
#include <vector>
#include <string>

class ShapeMedia;
class ComboMedia;
class Visitor {
public:
    virtual void visitShapeMedia(ShapeMedia *sm) = 0;
    virtual void visitComboMediaPre(ComboMedia *cm) = 0;
    virtual void visitComboMediaPost(ComboMedia *cm) = 0;
};
class DescriptionVisitor : public Visitor{
public:
    DescriptionVisitor (): desc(std::string("")) {}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMediaPre(ComboMedia *cm);
    void visitComboMediaPost(ComboMedia *cm);
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
    ComboMedia () {}
    double area( ) const {
        double total =0;
            for (Media *m: media)
                total += m->area();
        return total;
    }
    void accept(DescriptionVisitor * dv) {
        dv->visitComboMediaPre(this);
        for (Media *m: media)
            m->accept(dv);
        dv->visitComboMediaPost(this);
    }
    void add (Media *m) {
        media.push_back(m);
    }
};

void DescriptionVisitor::visitShapeMedia(ShapeMedia *sm) {
    desc += sm->getShape()->description();
}

void DescriptionVisitor::visitComboMediaPre(ComboMedia *cm) {
    desc = desc + std::string("x(");
}

void DescriptionVisitor::visitComboMediaPost(ComboMedia *cm) {
    desc = desc + std::string(")");
}

class MediaBuilder {
public:
    MediaBuilder (): combo(0) {}
    void buildComboMedia() {combo = new ComboMedia;}
    void buildShapeMedia(Shape * s) {
        if(!combo)
            throw std::string("null point ex") ;
        combo->add(new ShapeMedia(s));

    }
    void buildAddComboMedia(ComboMedia * cm){
        combo->add(cm);
    }
    ComboMedia * getComboMedia() const {return combo;}
private:
    ComboMedia * combo;
};
#endif // SHAPEMEDIA_H_INCLUDED
