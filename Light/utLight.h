#ifndef UTLIGHT_H_INCLUDED
#define UTLIGHT_H_INCLUDED
#include <string>
#include "Light.h"
TEST(LIGHT,LIGHT)
{
    Light light;
    CHECK(std::string("off")==light.getState());
}
TEST(flip,Light)
{
    Light light;
    light.flip();
    CHECK(std::string("med")==light.getState());
}
/*
TEST(medToHigh,Light)
{
    Light light("med");
    light.flip();
    CHECK(std::string("high")==light.getState());
}
TEST(hightoOff,Light)
{
    Light light("high");
    light.flip();
    CHECK(std::string("off")==light.getState());
}*/

#endif // UTLIGHT_H_INCLUDED
