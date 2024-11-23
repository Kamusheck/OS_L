#include "parent.hpp"
#include "commonchild.hpp"
#include <fcntl.h>
#include <gtest/gtest.h>
#include <unistd.h>

const char *pathChild1 = getenv("pathChild1");
const char *pathChild2 = getenv("pathChild2");

TEST(FuncTests, ToLowTest) {
    char str[] = "HeLLo WoRLd!";
    ToLow(str);
    EXPECT_STREQ(str, "hello world!");
}

TEST(FuncTests, DeleteProbelsTest) {
    char str[] = "Hello  World!";
    DeleteProbels(str);
    EXPECT_STREQ(str, "Hello World!");
}

void SimulateInputOutputForParent(const std::string &testInput,
                                  std::string &output) {
    std::istringstream inputStream(testInput);
    std::streambuf *originalCinBuffer = std::cin.rdbuf(inputStream.rdbuf());
    std::ostringstream outputStream;
    std::streambuf *originalCoutBuffer = std::cout.rdbuf(outputStream.rdbuf());

    Parent(pathChild1, pathChild2);

    std::cin.rdbuf(originalCinBuffer);
    std::cout.rdbuf(originalCoutBuffer);
    output = outputStream.str();
    size_t pos = output.find("Введите инфу: ");
    if (pos != std::string::npos) {
        output.erase(pos, strlen("Введите инфу: "));
    }
}

void RunParentChildIntegrationTest(const std::string &input,
                                   const std::string &expectedOutput) {
    std::string output;
    SimulateInputOutputForParent(input, output);
    EXPECT_EQ(output, expectedOutput);
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test1) {
    RunParentChildIntegrationTest("Hello  World", "hello world\n");
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test2) {
    RunParentChildIntegrationTest("1  2  3  4  5  6", "1 2 3 4 5 6\n");
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test3) {
    RunParentChildIntegrationTest("A  A aaa  bb cd", "a a aaa bb cd\n");
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test4) {
    RunParentChildIntegrationTest("", "\n");
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}