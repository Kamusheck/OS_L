cmake_minimum_required(VERSION 3.10)

project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
set(BUILD_DIR ${CMAKE_BINARY_DIR})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(fn1 SHARED ${SRC_DIR}/fn1.cpp)
add_library(fn2 SHARED ${SRC_DIR}/fn2.cpp)

add_executable(main_compile ${SRC_DIR}/main_compile.cpp)
target_link_libraries(main_compile PRIVATE fn1)

add_executable(main_runtime ${SRC_DIR}/main_runtime.cpp)
target_link_libraries(main_runtime PRIVATE dl)

enable_testing()

find_package(GTest REQUIRED)

add_executable(test_fn1 ${TEST_DIR}/test_fn1.cpp)
target_link_libraries(test_fn1 PRIVATE fn1 GTest::GTest GTest::Main)

add_executable(test_fn2 ${TEST_DIR}/test_fn2.cpp)
target_link_libraries(test_fn2 PRIVATE fn2 GTest::GTest GTest::Main)

add_test(NAME TestFn1 COMMAND test_fn1)
add_test(NAME TestFn2 COMMAND test_fn2)

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}
    COMMENT "Cleaning up build directory"
)
