#include <iostream>
#include "ModulesNaumenko.h"

int main() {
    try {
        // ��������� ������ 10.1
        solveTask10_1("input.txt", "output.txt");

        // ��������� ������ 10.2
        solveTask10_2("input.txt");

        // ��������� ������ 10.3
        solveTask10_3(5, 2, 3, 42, "output.txt");

        std::cout << "������� ��������� ������!\n";
    } catch (const std::exception& e) {
        std::cerr << "�������: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
