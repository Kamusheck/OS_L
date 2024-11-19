#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstring> 
#include <iostream>
#include <string>
#include <unistd.h>

void ToLow(char *str);
void DeleteProbels(char *str);
void DataTreatment(int argc, char *argv[], void (*StringOperation)(char *));

#endif 