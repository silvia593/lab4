#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "regression.hpp"
//#include "regression.hpp"

TEST_CASE ("Testing Regression") {
    Regression reg;
    reg.add (0.,1.);
    reg.add (1.,0.);
    auto result = reg.fit();
    CHECK (result.A == doctest::Approx(1.));
    CHECK (result.B == doctest::Approx(-1.));
}
