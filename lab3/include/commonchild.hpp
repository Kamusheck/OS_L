#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <string>
#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <sstream>

void ToLow(char *str);
void DeleteProbels(char *str);
void DataTreatment(int argc, char *argv[], void (*StringOperation)(char *));

#endif 