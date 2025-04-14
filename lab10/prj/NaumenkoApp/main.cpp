#include <iostream>
#include "ModulesNaumenko.h"

int main() {
    try {
        // Виконання задачі 10.1
        solveTask10_1("input.txt", "output.txt");

        // Виконання задачі 10.2
        solveTask10_2("input.txt");

        // Виконання задачі 10.3
        solveTask10_3(5, 2, 3, 42, "output.txt");

        std::cout << "Обробка завершена успішно!\n";
    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
