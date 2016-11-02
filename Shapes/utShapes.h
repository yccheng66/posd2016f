#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include "ShapeMedia.h"
#include <vector>

const double epsilon = 0.000001;
// added this line
TEST (first, Rectangle)
{
    Rectangle rect(0,0,4,2);
    DOUBLES_EQUAL(8,rect.area(),epsilon);
}

TEST(sencond,Circle)
{
    Circle circ(0,0,10);
    DOUBLES_EQUAL(300,circ.area(),epsilon);
}

TEST (fifth, sumOfArea)
{
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    std::vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    DOUBLES_EQUAL(308,sumOfArea(ss),epsilon);
}






TEST ( seven, media ) {
    Rectangle r1(0,0,4,2);
    ShapeMedia sR1( &r1 ) ;
    DOUBLES_EQUAL(8,sR1.area(),epsilon);
}

TEST ( eight, comboMedia ) {
    Rectangle r1(0,0,4,2);
    Rectangle r2(0,0,4,3);
    ShapeMedia sR1( &r1 ) ;
    ShapeMedia sR2( &r2 ) ;
    std::vector<Media *> ss{&sR1,&sR2};
    ComboMedia cm(ss);
    DOUBLES_EQUAL(20,cm.area(),epsilon) ;
}

#include <iostream>

TEST (ComboMedia, DescriptionVisitor) {
    Rectangle r1(0,0,4,2);
    Circle r2(0,0,10);
    ShapeMedia sR1( &r1 ) ;
    ShapeMedia sR2( &r2 ) ;
    std::vector<Media *> ss{&sR1,&sR2};
    ComboMedia cm(ss);
    DescriptionVisitor dv;
    cm.accept(&dv);
    CHECK(std::string("x(r(0 0 4 2) c(0 0 10) )") == dv.getDescription());
}

TEST (ShapeMedia, DescriptionVisitor) {
    Rectangle r1(0,0,4,2);
    ShapeMedia sR1( &r1 ) ;
    DescriptionVisitor dv;
    sR1.accept(&dv);
    CHECK(std::string("r(0 0 4 2) ") == dv.getDescription());
}

TEST (IllegalAdd, ShapeMedia) {
    Rectangle r1(0,0,4,2);
    Circle r2(0,0,10);
    ShapeMedia sR1( &r1 ) ;
    ShapeMedia sR2( &r2 ) ;
    try {
        sR1.add(&sR2);
        FAIL("should not be here");
    } catch(std::string s) {
        CHECK(std::string("Illegal: add on media") == s);
    }
}

TEST (ComboMedia2, MediaBuilder) {
    MediaBuilder mb;

    mb.buildComboMedia();
    Rectangle r(0,0,4,2);
    mb.buildShapeMedia(&r);
    Circle c(0,0,10);
    mb.buildShapeMedia(&c);

    ComboMedia * combo = mb.getComboMedia();
    DescriptionVisitor dv;
    combo->accept(&dv);
    CHECK(std::string("x(r(0 0 4 2) c(0 0 10) )") == dv.getDescription());

}

TEST (ComboMedia3, MediaBuilder) {
    MediaBuilder mb;

    try{
        Rectangle r(0,0,4,2);
        mb.buildShapeMedia(&r);
        FAIL("should not be here");
    }catch(std::string s){
        CHECK(std::string("null point ex")==s);
    }
}

TEST (ComboMedia4, MediaBuilder) {
    MediaBuilder mb;
    mb.buildComboMedia();

    Rectangle r(0,0,4,2);
    mb.buildShapeMedia(&r);
    Circle c(0,0,10);
    mb.buildShapeMedia(&c);

    MediaBuilder mb2;
    mb2.buildComboMedia();

    Rectangle r2(0,0,2,1);
    mb2.buildShapeMedia(&r2);
    Circle c2(0,0,5);
    mb2.buildShapeMedia(&c2);

    ComboMedia *cm = mb2.getComboMedia();
    mb.buildAddComboMedia(cm);

    DescriptionVisitor dv;
    mb.getComboMedia()->accept(&dv);
    // std::cout << dv.getDescription() << std::endl;
    CHECK(std::string("x(r(0 0 4 2) c(0 0 10) x(r(0 0 2 1) c(0 0 5) ))") == dv.getDescription());

}

#include<stack>
TEST (ComboMedia5, MediaBuilder) {
    std::stack<MediaBuilder *> mbs;
    mbs.push(new MediaBuilder());
    mbs.top()->buildComboMedia();

    Rectangle r(0,0,4,2);
    mbs.top()->buildShapeMedia(&r);
    Circle c(0,0,10);
    mbs.top()->buildShapeMedia(&c);

    mbs.push(new MediaBuilder());
    mbs.top()->buildComboMedia();

    Rectangle r2(0,0,2,1);
    mbs.top()->buildShapeMedia(&r2);
    Circle c2(0,0,5);
    mbs.top()->buildShapeMedia(&c2);
    ComboMedia *cm = mbs.top()->getComboMedia();
    mbs.pop();
    mbs.top()->buildAddComboMedia(cm);

    DescriptionVisitor dv;
    mbs.top()->getComboMedia()->accept(&dv);
    // std::cout << dv.getDescription() << std::endl;

    CHECK(std::string("x(r(0 0 4 2) c(0 0 10) x(r(0 0 2 1) c(0 0 5) ))") == dv.getDescription());

}
TEST (MediaDirector,MediaBuilder){
    MediaDirector md(std::string("x(r(0 0 4 2) c(0 0 10) x(r(0 0 2 1) c(0 0 5) ))"));
    md.build();
    Media* m = md.getResult();
    DescriptionVisitor dv;
    m->accept(&dv);
    CHECK(std::string("x(r(0 0 4 2) c(0 0 10) x(r(0 0 2 1) c(0 0 5) ))") == dv.getDescription());
}
#endif // UTSHAPES_H_INCLUDED
