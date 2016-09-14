#include "..\cppunitlite\TestHarness.h"

using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}

int one () {return 1;}

int two() {return 2;}

// added this line
TEST (first, first) {
    LONGS_EQUAL(1, one());
}

TEST (second, first) {
    CHECK(true);
}

TEST (thrid, first) {
    LONGS_EQUAL(2,two());
}
//added this later
