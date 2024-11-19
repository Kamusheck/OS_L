#include "commonchild.hpp"

void DataTreatment(int argc, char *argv[], void(*ChildFunc)(char*)) {
    if(argc<3){
        std::cerr <<"Не то количество аргументов" <<std::endl;
        exit(EXIT_FAILURE);
    }
    int read_f = atoi(argv[1]);
    int write_f = atoi(argv[2]);
    char input[256];
    if(read(read_f, input, sizeof(input))== -1){
        perror("Проблема чтение их канальчика, проблема на этапе обработки и передачи в конкреьный ффункционал chil");
        exit(EXIT_FAILURE);
    }
    ChildFunc(input);
    if (write(write_f, input, strlen(input)+ 1) == -1) {
        perror("Проблема записи их канальчика, проблема на этапе обработки и передачи в конкреьный ффункционал chil");
        exit(EXIT_FAILURE);
    }

    close(read_f);
    close(write_f);
}

void ToLow(char * str){
    for (int i =0; str[i] != '\0'; i++){
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
