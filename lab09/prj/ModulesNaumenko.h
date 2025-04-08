#ifndef MODULESNAUMENKO_H_INCLUDED
#define MODULESNAUMENKO_H_INCLUDED

#include <cmath>
#include <vector>

// Існуюча функція (за лабораторною №8)
double s_calculation(double x, double y, double z);

// Задача 9.1: розрахунок суми за спожиту електроенергію
double calculateBill(int kWh);

// Задача 9.2: визначення мінімального бала Бофорта
int getBeaufortScale(double speed);
int minBeaufortScale(const std::vector<double>& speeds);

// Задача 9.3: аналіз бітів числа
int countBits(unsigned int N);

#endif // MODULESNAUMENKO_H_INCLUDED
