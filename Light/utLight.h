#ifndef UTLIGHT_H_INCLUDED
#define UTLIGHT_H_INCLUDED
#include <string>
#include "Light.h"
TEST(Light,Light)
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


TEST(medToHigh,Light)
{
    Light light(MedState::GetInstance());
    light.flip();
    CHECK(std::string("high")==light.getState());
}

TEST(hightoOff,Light)
{
    Light light(HighState::GetInstance());
    light.flip();
    CHECK(std::string("off")==light.getState());
}

#endif // UTLIGHT_H_INCLUDED
