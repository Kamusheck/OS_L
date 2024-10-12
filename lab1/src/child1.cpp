#include "child1.h"
#include "commonchild.h"

void Child1(int read_fd, int write_fd) {
    data_treatment(read_fd, write_fd, child1_process_func);
}
