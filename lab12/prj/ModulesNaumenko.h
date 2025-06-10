#ifndef MODULESNAUMENKO_H
#define MODULESNAUMENKO_H

#include <iostream>
#include <cmath>

/**
 * Клас ClassLab12_Naumenko - абстракція сутності "Коло"
 * Реалізує операції над геометричною фігурою "коло"
 */
class ClassLab12_Naumenko {
private:
    double radius;  // Радіус кола (приватний атрибут для інкапсуляції)
    
public:
    // Конструктор за замовчуванням
    ClassLab12_Naumenko(double r = 1.0);
    
    // Конструктор копіювання
    ClassLab12_Naumenko (const ClassLab12_Naumenko& other);
    
    // Деструктор
    ~ClassLab12_Naumenko ();
    
    // Геттер для радіуса
    double getRadius() const;
    
    // Геттер для діаметра
    double getDiameter() const;
    
    // Сеттер для радіуса (з параметром за замовчуванням)
    void setRadius(double r = 1.0);
    
    // Сеттер для діаметра
    void setDiameter(double d);
    
    // Обчислення площі кола (S = π * r²)
    double calculateArea() const;
    
    // Обчислення довжини кола (C = 2 * π * r)
    double calculateCircumference() const;
    
    // Перевірка валідності радіуса
    bool isValid() const;
    
    // Виведення інформації про коло
    void displayInfo() const;
    
    // Оператор присвоєння
    ClassLab12_Naumenko & operator=(const ClassLab12_Naumenko& other);
    
    // Оператор порівняння
    bool operator==(const ClassLab12_Naumenko& other) const;
};

// Реалізація конструктора
ClassLab12_Naumenko::ClassLab12_Naumenko (double r) {
    if (r > 0) {
        radius = r;
    } else {
        radius = 1.0; // Значення за замовчуванням для некоректного радіуса
    }
}

// Реалізація конструктора копіювання
ClassLab12_Naumenko::ClassLab12_Naumenko (const ClassLab12_Naumenko& other) {
    radius = other.radius;
}

// Реалізація деструктора
ClassLab12_Naumenko::~ClassLab12_ Naumenko () {
    // Оскільки використовуються лише прості типи даних, 
    // спеціальне звільнення пам'яті не потрібне
}

// Реалізація геттера для радіуса
double ClassLab12_Naumenko::getRadius() const {
    return radius;
}

// Реалізація геттера для діаметра
double ClassLab12_Naumenko::getDiameter() const {
    return 2.0 * radius;
}

// Реалізація сеттера для радіуса з параметром за замовчуванням
void ClassLab12_Naumenko::setRadius(double r) {
    if (r > 0) {
        radius = r;
    }
}

// Реалізація сеттера для діаметра
void ClassLab12_Naumenko::setDiameter(double d) {
    if (d > 0) {
        radius = d / 2.0;
    }
}

// Реалізація обчислення площі кола
double ClassLab12_Naumenko::calculateArea() const {
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

// Реалізація обчислення довжини кола
double ClassLab12_Naumenko::calculateCircumference() const {
    const double PI = 3.14159265359;
    return 2.0 * PI * radius;
}

// Реалізація перевірки валідності
bool ClassLab12_Naumenko::isValid() const {
    return radius > 0;
}

// Реалізація виведення інформації
void ClassLab12_Naumenko::displayInfo() const {
    std::cout << "Коло з радіусом: " << radius << std::endl;
    std::cout << "Діаметр: " << getDiameter() << std::endl;
    std::cout << "Площа: " << calculateArea() << std::endl;
    std::cout << "Довжина кола: " << calculateCircumference() << std::endl;
}

// Реалізація оператора присвоєння
ClassLab12_Naumenko& ClassLab12_Naumenko::operator=(const ClassLab12_Naumenko& other) {
    if (this != &other) {
        radius = other.radius;
    }
    return *this;
}

// Реалізація оператора порівняння
bool ClassLab12_Naumenko::operator==(const ClassLab12_Naumenko& other) const {
    const double EPSILON = 1e-9;
    return std::abs(radius - other.radius) < EPSILON;
}

#endif // MODULESNAUMENKO_H
