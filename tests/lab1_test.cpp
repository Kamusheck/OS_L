#include "parent.hpp"
#include "commonchild.hpp"
#include <fcntl.h>
#include <gtest/gtest.h>
#include <unistd.h>

const char *PATH_TO_CHILD1 = getenv("PATH_TO_CHILD1");
const char *PATH_TO_CHILD2 = getenv("PATH_TO_CHILD2");

// Test ToLowerCase function
TEST(CommonTests,TolowerCase) {
    char str[] = "HeLLo WoRLd!";
    child1_process_func(str);
    EXPECT_STREQ(str, "hello world!");
}

// Test ReplaceSpacesWithUnderscore function
TEST(CommonTests, DeleteProbels) {
    char str[] = "Hello  World!";
    child2_process_func(str);
    EXPECT_STREQ(str, "Hello World!");
}

void SimulateInputOutputForParent(const std::string &testInput,
                                  std::string &output) {
    // Redirect input
    std::istringstream inputStream(testInput);
    std::streambuf *originalCinBuffer = std::cin.rdbuf(inputStream.rdbuf());
    // Redirect output
    std::ostringstream outputStream;
    std::streambuf *originalCoutBuffer = std::cout.rdbuf(outputStream.rdbuf());

    Parent(PATH_TO_CHILD1, PATH_TO_CHILD2);

    // Restore input
    std::cin.rdbuf(originalCinBuffer);
    // Restore output
    std::cout.rdbuf(originalCoutBuffer);
    output = outputStream.str();
    // Remove hints from output
    size_t pos = output.find("Enter your text: ");
    if (pos != std::string::npos) {
        output.erase(pos, strlen("Enter your text: "));
    }
}

void RunParentChildIntegrationTest(const std::string &input,
                                   const std::string &expectedOutput) {
    std::string output;
    SimulateInputOutputForParent(input, output);
    EXPECT_EQ(output, expectedOutput);
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test1) {
    RunParentChildIntegrationTest("New  phrAse", "new phrase\n");
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test2) {
    RunParentChildIntegrationTest("normal format", "normal format\n");
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test3) {
    RunParentChildIntegrationTest("A A aaabb  bb cd ", "a a aaa bb cd\n");
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test4) {
    RunParentChildIntegrationTest(" ", "\n");
}

TEST(ParentChildIntegrationTests, ParentChild1Child2Test5) {
    RunParentChildIntegrationTest("", "\n");
}
// Main entry point for tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}