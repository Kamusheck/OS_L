#include "commonchild.hpp"

void DataTreatment(int argc, char *argv[], void (*ChildFunc)(char *)) {
    if (argc < 2) {
        std::cerr << "Недостаточно аргументов" << std::endl;
        exit(EXIT_FAILURE);
    }
    const char *shm_name = argv[1];
    int shm_fd = shm_open(shm_name, O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Ошибка открытия отображаемого файла");
        exit(EXIT_FAILURE);
    }

    void *shared_mem = mmap(nullptr, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_mem == MAP_FAILED) {
        perror("Ошибка отображения файла в память");
        exit(EXIT_FAILURE);
    }

    char *shared_buffer = static_cast<char *>(shared_mem);

    std::istringstream input(shared_buffer);
    std::ostringstream output;
    std::string line;
    while (std::getline(input, line)) {
        char lineBuffer[256];
        strncpy(lineBuffer, line.c_str(), 256);
        ChildFunc(lineBuffer);
        output << lineBuffer << '\n';
    }

    strncpy(shared_buffer, output.str().c_str(), 4096);

    munmap(shared_mem, 4096);
    close(shm_fd);
}

void ToLow(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = std::tolower(static_cast<unsigned char>(str[i]));
    }
}

void DeleteProbels(char *str) {
    int i, j = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] == ' ') {
            if (i < len - 1 && str[i + 1] == ' ') {
                continue;
            }
        }
        str[j++] = str[i];
    }
    str[j] = '\0';
}
