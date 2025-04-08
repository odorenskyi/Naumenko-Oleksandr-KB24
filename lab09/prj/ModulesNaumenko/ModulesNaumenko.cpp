#include "ModulesNaumenko.h"
#include <cmath>

// Реалізація функції з лабораторної №8
double s_calculation(double x, double y, double z) {
    return pow(x, 2) + sqrt(y) + log(z); // Приклад реалізації
}

// Реалізація задачі 9.1
double calculateBill(int kWh) {
    if (kWh <= 100) return kWh * 0.9;
    else if (kWh <= 500) return 100 * 0.9 + (kWh - 100) * 1.5;
    else return 100 * 0.9 + 400 * 1.5 + (kWh - 500) * 2.0;
}

// Реалізація задачі 9.2
int getBeaufortScale(double speed) {
    if (speed < 0.3) return 0;
    else if (speed < 1.6) return 1;
    else if (speed < 3.4) return 2;
    else return 3; // Спрощено для прикладу
}

int minBeaufortScale(const std::vector<double>& speeds) {
    int minScale = 12; // Максимальний бал Бофорта
    for (double speed : speeds) {
        int scale = getBeaufortScale(speed);
        if (scale < minScale) minScale = scale;
    }
    return minScale;
}

// Реалізація задачі 9.3
int countBits(unsigned int N) {
    int count = 0;
    while (N) {
        count += N & 1;
        N >>= 1;
    }
    return count;
}