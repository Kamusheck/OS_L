#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>

// Путь к программе (задается через переменную окружения)
const std::string PROGRAM_PATH = std::string(getenv("LAB2_PATH_TO_PROGRAMM"));

// Функция для запуска программы и получения её вывода
std::string ExecuteProgram(const std::string &command) {
    std::array<char, 128> buffer;
    std::string result;
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe) {
        throw std::runtime_error("Failed to open pipe!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

// Функция для создания временного файла с входными данными
void CreateTempFile(const std::string &filePath, const std::string &data) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to create temp file!");
    }
    file << data;
    file.close();
}

// Тест для однопоточного режима
TEST(ProgramTest, SingleThread) {
    // Входные данные
    std::string inputData = "3\n1 2 3\n4 5 6\n7 8 9";
    std::string expectedOutput = "Determinant: 0\n";

    // Создаем временный файл с входными данными
    char tempFilePath[] = "/tmp/temp_input_XXXXXX";
    int fd = mkstemp(tempFilePath);
    if (fd == -1) {
        throw std::runtime_error("Failed to create temp file!");
    }
    close(fd);

    CreateTempFile(tempFilePath, inputData);

    // Запускаем программу в однопоточном режиме
    std::string command = PROGRAM_PATH + " " + tempFilePath + " 1";
    std::string output = ExecuteProgram(command);

    // Проверяем вывод программы
    EXPECT_EQ(output, expectedOutput);

    // Удаляем временный файл
    std::remove(tempFilePath);
}

// Тест для многопоточного режима
TEST(ProgramTest, MultiThread) {
    // Входные данные
    std::string inputData = "3\n1 2 3\n4 5 6\n7 8 9";
    std::string expectedOutput = "Determinant: 0\n";

    // Создаем временный файл с входными данными
    char tempFilePath[] = "/tmp/temp_input_XXXXXX";
    int fd = mkstemp(tempFilePath);
    if (fd == -1) {
        throw std::runtime_error("Failed to create temp file!");
    }
    close(fd);

    CreateTempFile(tempFilePath, inputData);

    // Запускаем программу в многопоточном режиме
    std::string command = PROGRAM_PATH + " " + tempFilePath + " 2";
    std::string output = ExecuteProgram(command);

    // Проверяем вывод программы
    EXPECT_EQ(output, expectedOutput);

    // Удаляем временный файл
    std::remove(tempFilePath);
}

// Тест для сравнения однопоточного и многопоточного режимов
TEST(ProgramTest, SingleVsMultiThread) {
    // Входные данные
    std::string inputData = "3\n1 2 3\n4 5 6\n7 8 9";

    // Создаем временный файл с входными данными
    char tempFilePath[] = "/tmp/temp_input_XXXXXX";
    int fd = mkstemp(tempFilePath);
    if (fd == -1) {
        throw std::runtime_error("Failed to create temp file!");
    }
    close(fd);

    CreateTempFile(tempFilePath, inputData);

    // Запускаем программу в однопоточном режиме
    std::string commandSingle = PROGRAM_PATH + " " + tempFilePath + " 1";
    std::string outputSingle = ExecuteProgram(commandSingle);

    // Запускаем программу в многопоточном режиме
    std::string commandMulti = PROGRAM_PATH + " " + tempFilePath + " 2";
    std::string outputMulti = ExecuteProgram(commandMulti);

    // Проверяем, что результаты совпадают
    EXPECT_EQ(outputSingle, outputMulti);

    // Удаляем временный файл
    std::remove(tempFilePath);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}