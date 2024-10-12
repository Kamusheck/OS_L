#include "child1.hpp"
#include "commonchild.hpp"

void Child1(int read_fd, int write_fd) {
    data_treatment(read_fd, write_fd, child1_process_func);
}