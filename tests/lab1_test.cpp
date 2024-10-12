#include "parent.hpp"
#include "commonchild.hpp"
#include "child1.hpp"
#include "child2.hpp"
#include <fcntl.h>
#include <gtest/gtest.h>
#include <unistd.h>
#include <sstream>


TEST(UtilsTests, ToLowerCaseTest) {
    std::string input = "Phrase Check";
    std::string expected = "phrase check";
    EXPECT_EQ(child1_process_func(input), expected);
}


TEST(UtilsTests, RemoveDoubleSpacesTest) {
    std::string input = "Phrase  Check";
    std::string expected = "Phrase Check";
    EXPECT_EQ(child2_process_func(input), expected);
}


void SimulateInputOutputForParent(const std::string &testInput, std::string &output) {
    std::istringstream inputStream(testInput);
    std::streambuf *originalCinBuffer = std::cin.rdbuf(inputStream.rdbuf());
    std::ostringstream outputStream;
    std::streambuf *originalCoutBuffer = std::cout.rdbuf(outputStream.rdbuf());

 
    Parent();

    std::cin.rdbuf(originalCinBuffer);
    std::cout.rdbuf(originalCoutBuffer);
    

    output = outputStream.str();
    

    size_t pos = output.find("enter phrase or exit to finish: ");
    if (pos != std::string::npos) {
        output.erase(pos, strlen("enter phrase or exit to finish: "));
    }
}

void RunParentChildIntegrationTest(const std::string &input, const std::string &expectedOutput) {
    std::string output;
    SimulateInputOutputForParent(input + "nexit", output); // Добавляем exit для завершения
    EXPECT_EQ(output, expectedOutput);
}


TEST(ParentChildIntegrationTests, SimpleLowerCase) {
    RunParentChildIntegrationTest("Hello World", "hello world\n");
}

TEST(ParentChildIntegrationTests, NumbersWithSpaces) {
    RunParentChildIntegrationTest("1  2  3", "1 2 3\n");
}

TEST(ParentChildIntegrationTests, MixedCaseAndSpaces) {
    RunParentChildIntegrationTest("HeLLo   wORLD", "hello world\n");
}

TEST(ParentChildIntegrationTests, EmptyInput) {
    RunParentChildIntegrationTest("", "\n");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
