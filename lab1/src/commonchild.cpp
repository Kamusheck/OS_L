#include <unistd.h>
#include <cstring>
#include <string>
#include <iostream>
#include <functional>
#include <sstream>

void data_treatment(int read_fd, int write_fd, std::function<std::string(const std::string&)> process_func) {
    close(write_fd); 
    char buffer[256];
    
    while (true) {
        ssize_t bytesRead = read(read_fd, buffer, sizeof(buffer) - 1); 
        if (bytesRead <= 0) {
            break; 
        }
        
        buffer[bytesRead] = '0'; 
        std::string input(buffer); 
        std::string result = process_func(input); 
        

        write(write_fd, result.c_str(), result.size() + 1); 
    }
    
    close(read_fd); 
}

std::string child1_process_func(const std::string& input) {
    std::string work_phrase = input;
    for (char& i : work_phrase) {
        i = tolower(i);
    }
    return work_phrase;
}

std::string child2_process_func(const std::string& input) {
    std::istringstream work_phrase(input);
    std::string word;
    std::string result;
    
    while (work_phrase >> word) {
        if (!result.empty()) {
            result += ' ';
        }
        result += word;
    }
    
    return result;
}
