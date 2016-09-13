#ifndef UT_H_INCLUDED
#define UT_H_INCLUDED
#include "cppunitlite\Test.h"
#include "Rational.h"

/*
TEST (Rational, constructor) {
    Rational p(2,3);
    LONGS_EQUAL(2,p.numerator());
    LONGS_EQUAL(3,p.denominator());
}

TEST (Rational, deafult_constructor) {
    Rational p;
    LONGS_EQUAL(0,p.numerator());
    LONGS_EQUAL(1,p.denominator());
}

TEST (Rational, constructorAcceptingInteger) {
    Rational p(3);
    LONGS_EQUAL(3,p.numerator());
    LONGS_EQUAL(1,p.denominator());
}

TEST (Rational, reduce) {
    Rational p(8,6);
    p.reduce();
    LONGS_EQUAL(4,p.numerator());
    LONGS_EQUAL(3,p.denominator());
}

TEST (gcd, allcases) {
    LONGS_EQUAL(2, gcd(8,6));
    LONGS_EQUAL(2, gcd(-8,6));
    LONGS_EQUAL(2, gcd(-8,-6));
    LONGS_EQUAL(2, gcd(8,-6));
    LONGS_EQUAL(1, gcd(4,7));
}

TEST (Rational, gcdpp) {
    LONGS_EQUAL(2, gcd(8,6));
}

TEST (Rational, gcdnp) {
    LONGS_EQUAL(2, gcd(-8,6));
}

TEST (Rational, gcdnn) {
    LONGS_EQUAL(2, gcd(-8,-6));
}

TEST (Rational, gcdpn) {
    LONGS_EQUAL(2, gcd(8,-6));
}

TEST (Rational, gcd_1) {
    LONGS_EQUAL(1, gcd(4,7));
}

TEST (Rational, gcd_undefined) {
    try {
        gcd(0,7);
        FAIL("exception not thrown");
    } catch (std::string s) {
        CHECK(std::string("gcd undefined") == s);
    }
}

TEST (Rational, add) {
    Rational p(1,2);
    Rational q(2,3);
    Rational r(p+q);
    LONGS_EQUAL(7, r.numerator());
    LONGS_EQUAL(6,r.denominator());
}

TEST (Rational, add_reduce) {
    Rational p(1,2);
    Rational q(4,8);
    Rational r=p+q;
    r.reduce();
    LONGS_EQUAL(1,r.numerator());
    LONGS_EQUAL(1,r.denominator());
}
*/

TEST (Rational, destructor) {
    Rational p(1,2);
    Rational q(4,8);
    std::cout <<"*** foo" << std::endl;
    p.foo(q);
    std::cout <<"***" << std::endl;
    std::cout <<"*** bar" << std::endl;
    p.bar(q);
    std::cout <<"***" << std::endl;
}
#endif // UT_H_INCLUDED
