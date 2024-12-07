#include <gtest/gtest.h>
#include "fn2.hpp"  // Заменить на актуальный заголовочный файл

// Тестирование подсчета простых чисел (решето Эратосфена)
TEST(PrimeCountTest, SievePrimeCount) {
    EXPECT_EQ(PrimeCount(1, 10), 4); // Простые числа в [1, 10]: 2, 3, 5, 7
    EXPECT_EQ(PrimeCount(10, 20), 4); // Простые числа в [10, 20]: 11, 13, 17, 19
    EXPECT_EQ(PrimeCount(1, 1), 0);  // Нет простых чисел в [1, 1]
}

// Тестирование интеграла методом трапеций
TEST(SinIntegralTest, TrapezoidMethod) {
    EXPECT_NEAR(SinIntegral(0, 3.14159, 0.01), 2.0, 0.1); // интеграл от sin(x) на [0, π]
}
