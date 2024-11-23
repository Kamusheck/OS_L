#include "commonchild.hpp"
#include <cstring> 
#include <iostream>
#include <unistd.h> 

int main(int argc, char *argv[]) {
    DataTreatment(argc, argv, DeleteProbels);
    return 0;
}