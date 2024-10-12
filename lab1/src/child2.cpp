#include "child2.hpp"
#include "commonchild.hpp"

void Child2(int read_fd, int write_fd) {
    data_treatment(read_fd, write_fd, child2_process_func);
}
