#include <gtest/gtest.h>
#include "fn2.hpp" 

TEST(PrimeCountTest, NaivePrimeCount) {
    EXPECT_EQ(PrimeCount(1, 10), 4);
    EXPECT_EQ(PrimeCount(10, 20), 4);
    EXPECT_EQ(PrimeCount(1, 1), 0);  
}

TEST(SinIntegralTest, RectangleMethod) {
    EXPECT_NEAR(SinIntegral(0, 3.14159, 0.01), 2.0, 0.1); 
}