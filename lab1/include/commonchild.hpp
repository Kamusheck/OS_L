#include <iostream>
#include <cctype>
#include <unistd.h>
#include <functional>
#include <sstream>
#include <string>

#ifndef COMMON_H
#define COMMON_H


std::string child1_process_func(const std::string& input);
std::string child2_process_func(const std::string& input);
void data_treatment(int read_fd, int write_fd, std::function<std::string(const std::string&)> procedd_func);

#endif