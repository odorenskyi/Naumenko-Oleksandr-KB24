#include <iostream>
#include <clocale>
#include "../ModulesNaumenko.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    cout << "=========================================" << endl;
    cout << " Naumenko Oleksandr, ddima1812000000@gmail.com  " << endl;
    cout << " �������� ���������, ddima1812000000@gmail.com  " << endl;
    cout << "==========(c)All Rights Reserved=========" << endl;

    double x, y, z;
    cout << "������ �������� x, y, z: " << endl;
    cin >> x >> y >> z;

    double S = s_calculation(x, y, z);

    cout << "�������� S = " << S << endl;

    return 0;
}
