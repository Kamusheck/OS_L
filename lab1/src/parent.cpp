#include "parent.hpp"
#include "commonchild.hpp"
#include "child1.hpp"
#include "child2.hpp"

void Parent() {
    int pipe1[2]; 
    int pipe2[2]; 

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("error with creating pipe");
        return;
    }

    pid_t child1 = fork();
    if (child1 == -1) {
        perror("error with creating child1 process");
        return;
    }
    if (child1 == 0) {
        close(pipe1[1]);
        close(pipe2[0]);
        Child1(pipe1[0], pipe2[1]);
        close(pipe2[1]);
        return;
    }

    pid_t child2 = fork();
    if (child2 == -1) {
        perror("error with creating child2 process");
        return;
    }
    if (child2 == 0) {
        close(pipe1[0]); 
        close(pipe2[1]);
        Child2(pipe2[0], STDOUT_FILENO); 
        close(pipe2[0]);
        return;
    }

    close(pipe1[0]); 
    close(pipe2[0]);

    std::string phrase;
    while (true) {
        std::cout << "enter phrase or exit to finish: ";
        std::getline(std::cin, phrase);
        if (phrase == "exit") {
            break;
        }
        write(pipe1[1], phrase.c_str(), phrase.size() + 1);
    }

    close(pipe1[1]); 


    char buffer[256];
    while (read(pipe2[0], buffer, sizeof(buffer)) > 0) {
        std::cout << "Result from Child2: " << buffer << std::endl;
    }

    close(pipe2[0]);
}

