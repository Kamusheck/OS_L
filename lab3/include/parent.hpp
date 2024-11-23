#ifndef PARENT_HPP
#define PARENT_HPP

#include <iostream>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/mman.h>
#include <fcntl.h>
#include <cstring>
#include <cstdlib>
#include <sys/wait.h>

void Create(const char *pathToChild, int readFd[2], int writeFd[2]);
void Parent(const char *pathToChild1, const char *pathToChild2);

#endif // PARENT_HPP