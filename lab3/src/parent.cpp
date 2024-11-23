#include "parent.hpp"

void Create(const char *pathChild, const char *shm_name) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Ошибка на уровне fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) { 
        char *args[] = {const_cast<char *>(pathChild), const_cast<char *>(shm_name), nullptr};
        if (execvp(args[0], args) == -1) {
            perror("Ошибка на уровне экзека");
            exit(EXIT_FAILURE);
        }
    }
}

void Parent(const char *pathChild1, const char *pathChild2) {
    const char *shm_name = "/shared_memory";
    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Ошибка создания отображаемого файла");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, 256) == -1) {
        perror("Ошибка установки размера отображаемого файла");
        exit(EXIT_FAILURE);
    }

    void *shared_mem = mmap(nullptr, 256, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_mem == MAP_FAILED) {
        perror("Ошибка отображения файла в память");
        exit(EXIT_FAILURE);
    }


    char *shared_buffer = static_cast<char *>(shared_mem);
    std::cin.getline(shared_buffer, 256); 

    Create(pathChild1, shm_name);
    Create(pathChild2, shm_name);

    std::cout << shared_buffer << std::endl; 
    munmap(shared_mem, 256);
    shm_unlink(shm_name);
}

