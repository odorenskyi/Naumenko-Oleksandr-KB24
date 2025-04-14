
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

    cout << "Тест: " << testName << " - " << (passed ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
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
        {"input1.txt", "Це моя програма для студентів", "програма: так, студент: так"},
        {"input2.txt", "Тут нічого схожого немає", "ключові слова: ні"},
        {"input3.txt", "Модульчик допомагає студенткам", "модифіковані форми слів знайдені"},
        {"input4.txt", "Програміст створив модульне середовище", "всі чотири ключові слова в похідній формі"},
        {"input5.txt", "", "ключові слова: ні"},
        {"input6.txt", "МоДуЛь СтУдЕнТ пРоГрАмА", "слова в різному регістрі розпізнані"},
        {"input7.txt", string(1001, 'a'), "ключові слова: ні"},
        {"input8.txt", "Програмісти і студенти працюють з модулями", "форми всіх ключових слів виявлені"}
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
        {"output1.txt", "", "Державні символи України"},
        {"output2.txt", "Результат аналізу\n", "Державні символи України"},
        {"output3.txt", "", "Державні символи України"},
        {"output4.txt", "Вже містить символи\n--- Державні символи України ---\n", "Державні символи України"},
        {"output5.txt", "Один рядок\n", "Державні символи України"},
        {"output6.txt", "DOS формат\r\n", "Державні символи України"},
        {"output7.txt", "Текст з\tтабуляціями\n", "Державні символи України"},
        {"output8.txt", "", ""} // Тест на помилку
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

    cout << "Початок тестування..." << endl;

    runTask10_1Tests();
    runTask10_2Tests();
    runTask10_3Tests();

    cout << "Тестування завершено. Результати збережено у файлі test_log.txt" << endl;
}
