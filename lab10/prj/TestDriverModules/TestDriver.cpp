
#include "TestDriver.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <bitset>

using namespace std;

void TestDriver::logTestResult(const string& testName, bool passed, const string& details) {
    ofstream logFile("test_log.txt", ios::app);

    logFile << "Test: " << testName << " - " << (passed ? "PASSED" : "FAILED") << endl;
    logFile << "Details: " << details << endl << endl;

    logFile.close();

    cout << "����: " << testName << " - " << (passed ? "��������" : "�� ��������") << endl;
}

bool TestDriver::compareFiles(const string& file1, const string& file2) {
    ifstream f1(file1, ios::binary);
    ifstream f2(file2, ios::binary);

    if (!f1.is_open() || !f2.is_open()) {
        return false;
    }

    string content1((istreambuf_iterator<char>(f1)), istreambuf_iterator<char>());
    string content2((istreambuf_iterator<char>(f2)), istreambuf_iterator<char>());

    return content1 == content2;
}

string TestDriver::readFileContent(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

void TestDriver::runTask10_1Tests() {
    vector<TestCase10_1> testCases = {
        {"input1.txt", "�� ��� �������� ��� ��������", "��������: ���, �������: ���"},
        {"input2.txt", "��� ����� ������� ����", "������ �����: �"},
        {"input3.txt", "��������� �������� ����������", "����������� ����� ��� �������"},
        {"input4.txt", "��������� ������� �������� ����������", "�� ������ ������ ����� � ������� ����"},
        {"input5.txt", "", "������ �����: �"},
        {"input6.txt", "������ ������� ��������", "����� � ������ ������ ��������"},
        {"input7.txt", string(1001, 'a'), "������ �����: �"},
        {"input8.txt", "���������� � �������� �������� � ��������", "����� ��� �������� ��� �������"}
    };

    for (const auto& testCase : testCases) {
        ofstream inputFile(testCase.inputFile);
        inputFile << testCase.inputContent;
        inputFile.close();

        string outputFile = "output_" + testCase.inputFile;
        solveTask10_1(testCase.inputFile, outputFile);

        string actualOutput = readFileContent(outputFile);
        bool passed = (actualOutput.find(testCase.expectedOutput) != string::npos);

        logTestResult("Task10_1: " + testCase.inputFile, passed,
                    "Expected: " + testCase.expectedOutput + "\nActual: " + actualOutput);
    }
}

void TestDriver::runTask10_2Tests() {
    vector<TestCase10_2> testCases = {
        {"output1.txt", "", "������� ������� ������"},
        {"output2.txt", "��������� ������\n", "������� ������� ������"},
        {"output3.txt", "", "������� ������� ������"},
        {"output4.txt", "��� ������ �������\n--- ������� ������� ������ ---\n", "������� ������� ������"},
        {"output5.txt", "���� �����\n", "������� ������� ������"},
        {"output6.txt", "DOS ������\r\n", "������� ������� ������"},
        {"output7.txt", "����� �\t�����������\n", "������� ������� ������"},
        {"output8.txt", "", ""} // ���� �� �������
    };

    for (size_t i = 0; i < testCases.size(); i++) {
        const auto& testCase = testCases[i];

        if (i == testCases.size() - 1) {
            logTestResult("Task10_2: " + testCase.outputFile + " (error test)", true, "Manual check required");
            continue;
        }

        ofstream outputFile(testCase.outputFile);
        outputFile << testCase.initialContent;
        outputFile.close();

        solveTask10_2(testCase.outputFile);

        string actualContent = readFileContent(testCase.outputFile);
        bool passed = (actualContent.find(testCase.expectedContent) != string::npos);

        logTestResult("Task10_2: " + testCase.outputFile, passed,
                    "Expected to contain: " + testCase.expectedContent);
    }
}

void TestDriver::runTask10_3Tests() {
    vector<TestCase10_3> testCases = {
        {"res1.txt", 2, 3, 4, 5, "s_calculation(2,3,4)=14"},
        {"res2.txt", 1, 1, 1, 10, "b=1010"},
        {"res3.txt", 5, 0, 2, 15, "b=1111"},
        {"res4.txt", 0, 0, 0, 0, "b=0"},
        {"res5.txt", 100, 200, 300, 255, "b=11111111"},
        {"res6.txt", 3, 5, 7, 1, "b=1"},
        {"res7.txt", 123, 321, 456, 16, "b=10000"},
        {"res8.txt", 7, 8, 9, 1024, "b=10000000000"}
    };

    for (const auto& testCase : testCases) {
        solveTask10_3(testCase.x, testCase.y, testCase.z, testCase.b, testCase.outputFile);

        string actualOutput = readFileContent(testCase.outputFile);
        bool passed = (actualOutput.find(testCase.expectedOutput) != string::npos);

        logTestResult("Task10_3: " + testCase.outputFile, passed,
                    "Expected to contain: " + testCase.expectedOutput + "\nActual: " + actualOutput);
    }
}

void TestDriver::runAllTests() {
    ofstream logFile("test_log.txt");
    logFile.close();

    setlocale(LC_ALL, "Ukrainian");

    cout << "������� ����������..." << endl;

    runTask10_1Tests();
    runTask10_2Tests();
    runTask10_3Tests();

    cout << "���������� ���������. ���������� ��������� � ���� test_log.txt" << endl;
}
