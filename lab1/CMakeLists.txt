add_library(lab1_lib
    src/parent.cpp
    src/commonchild.cpp
    src/child1.cpp
    src/child2.cpp
    main.cpp
)

target_include_directories(lab1_lib PUBLIC include)

add_executable(Parent src/parent.cpp)
target_link_libraries(Parent lab1_lib)

add_executable(Child1 src/child1.cpp)
target_link_libraries(Child1 lab1_lib)

add_executable(Child2 src/child2.cpp)
target_link_libraries(Child2 lab1_lib)

add_executable(main main.cpp)
target_link_libraries(main lab1_lib)