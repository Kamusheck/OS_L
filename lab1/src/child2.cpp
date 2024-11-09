#include "commonchild.hpp"
#include <cstring> // strlen
#include <iostream>
#include <unistd.h> // read, write

int main(int argc, char *argv[]) {
    DataTreatment(argc, argv, DeleteProbels);
    return 0;
}