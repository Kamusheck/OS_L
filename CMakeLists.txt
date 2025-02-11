cmake_minimum_required(VERSION 3.10)
project(DeterminantCalculator)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

# Добавляем pthread
find_package(Threads REQUIRED)

# Включаем директорию с заголовочными файлами
include_directories(include)

# Основная программа
add_executable(DeterminantCalculator main.c src/determinant.c)
target_link_libraries(DeterminantCalculator ${CMAKE_THREAD_LIBS_INIT})

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Тесты
add_executable(DeterminantTest test.cpp src/determinant.c)
target_link_libraries(DeterminantTest ${GTEST_LIBRARIES} pthread)

# Добавляем тест в CTest
add_test(NAME DeterminantTest COMMAND DeterminantTest)