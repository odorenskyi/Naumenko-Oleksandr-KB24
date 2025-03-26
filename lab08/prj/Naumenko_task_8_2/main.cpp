#include <iostream>
#include <iomanip>  // ��� ������������ ������
#include <clocale>
#include "ModulesNaumenko.h"  // ϳ��������� ������������� �����

using namespace std;

// ������� ��� ������ ���������� ��� ����������
void printDeveloperInfo() {
    cout << "=========================================" << endl;
    cout << " ������� ��'�, email@example.com " << endl;
    cout << " (c) All Rights Reserved " << endl;
    cout << "=========================================" << endl;
}

// ������� ��� �������� �������� ������ (a + 1 >= b)
bool checkLogicalExpression(char a, char b) {
    return (a + 1) >= b;
}

// ������� ��� ������ ������� x, y, z � ��������� � �������������� ������
void printValues(double x, double y, double z) {
    cout << "��������� �������: x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << "س������������ �������: "
         << "x = " << hexfloat << x << ", "
         << "y = " << hexfloat << y << ", "
         << "z = " << hexfloat << z << endl;
    cout << defaultfloat; // ��������� ��������� ������
}

// ������� �������
int main() {
    setlocale(LC_ALL, "ukr");

    // ��������� ���������� ��� ����������
    printDeveloperInfo();

    // �������� ������� x, y, z �� ������� a, b
    double x, y, z;
    char a, b;
    cout << "������ �������� x, y, z: ";
    cin >> x >> y >> z;
    cout << "������ ������� a, b: ";
    cin >> a >> b;

    // ��������� �������� ������
    bool result = checkLogicalExpression(a, b);
    cout << "��������� ������ (" << a << " + 1 >= " << b << "): "
         << (result ? "true" : "false") << endl;

    // ��������� ������� � ����� �������� ��������
    printValues(x, y, z);

    // ���������� �������� S
    double S = s_calculation(x, y, z);
    cout << "�������� S = " << S << endl;

    return 0;
}
