#include "parent.hpp"

void Create(const char *pathChild, int read_fd[2], int write_fd[2]){
    pid_t pid = fork();
    if(pid == -1){
        perror("Проблемка где то н ауровне форка");
        exit(EXIT_FAILURE);
    }
    if(pid == 0 ){
        close(read_fd[1]);
        close(write_fd[0]);
        std::string read_s = std::to_string(read_fd[0]);
        std::string write_s = std::to_string(write_fd[1]);
        char *args[] = {const_cast<char *>(pathChild),read_s.data(), write_s.data(), nullptr};//const char-т.к. execv только в таком формате принимает, data - метод из вектора возвращает укащатель на массив
        if(execvp(args[0], args)== -1){// отличие это execv то что он приниает путь или имя программы и сам массив
            perror("Проболемка уже на уроыне экзека");
            exit(EXIT_FAILURE);
        }
    }
}

void Parent(const char *pathChild1, const char *pathChild2){
    int pipe_ch1[2], pipe_ch2[2],pipe_ch[2];
    if (pipe(pipe_ch1)== -1 || pipe(pipe_ch2)== -1 || pipe(pipe_ch) == -1){
        std::cerr << "Упс, канальчики не хотятя работать и создаваться" << std::endl; // cerr - стандартный поток вывода ошибок, не зранится временно в буфере, выводится немедленно
        exit(EXIT_FAILURE);
    }
    char input[256];
    std::cin.getline(input, sizeof(input));
    if (write(pipe_ch1[1], input, sizeof(input))== -1){
        perror("Проблемка, ваша инфа не хочет идти в канал");
        exit(EXIT_FAILURE);
    };
    close(pipe_ch1[1]);
    Create(pathChild1, pipe_ch1, pipe_ch);
    close(pipe_ch1[0]);
    close(pipe_ch[1]);
    Create(pathChild2, pipe_ch, pipe_ch2);
    close(pipe_ch[0]);
    close(pipe_ch2[1]);

    if (read(pipe_ch2[0], input, sizeof(input)) == -1){
        perror("Проблемка, я не хочк делиться своей инфой");
        exit(EXIT_FAILURE);
    };
    close(pipe_ch2[0]);
    std::cout << input << std::endl;
}