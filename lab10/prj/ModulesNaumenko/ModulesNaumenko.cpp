#include "ModulesNaumenko.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <bitset>
#include <cmath>
#include <locale>

using namespace std;

void solveTask10_1(const string& inputFile, const string& outputFile) {
    setlocale(LC_ALL, "Ukrainian");
    locale::global(locale(""));

    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        throw runtime_error("������� �������� �����!");
    }

    // ����� ��������� ����������
    outFile << "�����: ��������\n";
    outFile << "��������: ����\n";
    outFile << "̳���: �������������\n";
    outFile << "�����: ������\n";
    outFile << "г� ��������: 2025\n\n";

    // ϳ�������� �������
    inFile.seekg(0, ios::end);
    size_t charCount = inFile.tellg();
    inFile.seekg(0, ios::beg);
    outFile << "� ���� " << inputFile << " �������� " << charCount << " �������.\n\n";

    // ������ ���� ���� �����
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    // ������������ �� ����� ������ ��� ���������
    string lowerContent = content;
    transform(lowerContent.begin(), lowerContent.end(), lowerContent.begin(), ::tolower);

    vector<string> baseWords = {"�������", "�����", "�������", "���������"};
    vector<string> keywords = {"��������", "������", "�������", "���������"};
    vector<bool> found(keywords.size(), false);

    for (size_t i = 0; i < baseWords.size(); ++i) {
        // ������ ������ ����� (��� ����������� ����� ����)
        if (lowerContent.find(baseWords[i]) != string::npos) {
            found[i] = true;
        }
    }

    outFile << "���������� ������ �������� ���:\n";
    for (size_t i = 0; i < keywords.size(); ++i) {
        outFile << "- ����� \"" << keywords[i] << "\" "
                << (found[i] ? "��������" : "�� ��������") << " � ����.\n";
    }

    outFile.close();
}

void solveTask10_2(const string& inputFile) {
    // ������������ ��������� �����
    setlocale(LC_ALL, "Ukrainian");
    locale::global(locale(""));

    ofstream outFile(inputFile, ios::app);

    if (!outFile.is_open()) {
        throw runtime_error("������� �������� �����!");
    }

    // ������ ������� ������� ������
    outFile << "\n\n--- ������� ������� ������ (��. 20 ����������� ������) ---\n";
    outFile << "1. ��������� ������ ������\n";
    outFile << "2. ��������� ���� ������\n";
    outFile << "3. ��������� ó�� ������\n";

    // ������ ������� ����
    time_t now = time(nullptr);
    char* dt = ctime(&now);
    outFile << "\n���� ������������� ����������: " << dt;

    outFile.close();
}

int s_calculation(int x, int y, int z) {
    if (x - y + z == 0) {
        throw runtime_error("ĳ����� �� ���� � ������� s_calculation");
    }
    return (sqrt(x) + pow(y, 2)) / (x - y + z);
}

void solveTask10_3(int x, int y, int z, int b, const string& outputFile) {
    setlocale(LC_ALL, "Ukrainian");
    locale::global(locale(""));

    ofstream outFile(outputFile, ios::app);

    if (!outFile.is_open()) {
        throw runtime_error("������� �������� �����!");
    }

    outFile << "\n\n--- ���������� ��������� ---\n";

    try {
        int result = s_calculation(x, y, z);
        outFile << "��������� ������� s_calculation(" << x << ", " << y << ", " << z << "): " << result << "\n";
    } catch (const exception& e) {
        outFile << "������� ����������: " << e.what() << "\n";
    }

    bitset<32> binary(b);
    outFile << "����� " << b << " � ��������� ���: " << binary << "\n";

    outFile.close();
}
