#ifndef TESTDRIVER_H
#define TESTDRIVER_H

#include <string>
#include <vector>
#include "D:\Lab10\prj\ModulesNaumenko.h"

struct TestCase10_1 {
    std::string inputFile;
    std::string inputContent;
    std::string expectedOutput;
};

struct TestCase10_2 {
    std::string outputFile;
    std::string initialContent;
    std::string expectedContent;
};

struct TestCase10_3 {
    std::string outputFile;
    int x, y, z, b;
    std::string expectedOutput;
};

class TestDriver {
public:
    void runAllTests();
    void logTestResult(const std::string& testName, bool passed, const std::string& details = "");

private:
    void runTask10_1Tests();
    void runTask10_2Tests();
    void runTask10_3Tests();

    bool compareFiles(const std::string& file1, const std::string& file2);
    std::string readFileContent(const std::string& filename);
};

#endif // TESTDRIVER_H
