#include "commonchild.h"

void data_treatment(int read_fd, int write_fd, std::function<std::string(const std::string&)> procedd_func){
    close(write_fd);
    char massive[256];
    while (true){
        ssize_t bytesRead = read(read_fd, massive, sizeof(massive));
        if (bytesRead <=0){
            break;
        }
        std:: string input(massive, bytesRead);
        std:: string result = procedd_func(input);
        write(write_fd, result.c_str(), result.size()+1);
    }
    close(read_fd);
}

std::string child1_process_func(const std::string& input){
    std::string work_phrase = input;
    for(char& i :work_phrase){
        i = tolower(i);
    } 
    return work_phrase;
}

std::string child2_process_func(const std::string& input){
    std::istringstream work_phrase(input);
    std::string word;
    std:: string result;
    while(work_phrase >> word){
        if(!result.empty()){
            result += ' ';
        }
        result += word;
    }
    return result;
}