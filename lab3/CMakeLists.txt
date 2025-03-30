add_library(lab3_lib
    src/parent.cpp
    src/commonchild.cpp
    src/child1.cpp
    src/child2.cpp
)

target_include_directories(lab3_lib PUBLIC include)

add_executable(child1 src/child1.cpp)
target_link_libraries(child1 lab3_lib)

add_executable(child2 src/child2.cpp)
target_link_libraries(child2 lab3_lib)

add_executable(main main.cpp)
target_link_libraries(main lab3_lib)