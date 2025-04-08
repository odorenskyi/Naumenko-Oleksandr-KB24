#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "D:\Lab09\prj/ModulesNaumenko.h"

using namespace std;

// Допоміжна функція для перевірки double з похибкою
bool approxEqual(double a, double b, double epsilon = 1e-2) {
    return fabs(a - b) < epsilon;
}

void test_calculateBill() {
    cout << "[Тестування задачі 9.1]" << endl;
    struct TestCase {
        int kWh;
        double expected;
    } tests[] = {
        {120, 36.9984},
        {500, 226.29},
        {1000, 496.37}
    };

    for (const auto& t : tests) {
        double result = calculateBill(t.kWh);
        cout << "  Вхід: " << t.kWh << " → Очікується: " << t.expected << ", Отримано: " << result;
        if (approxEqual(result, t.expected)) cout << " +" << endl;
        else cout << " -" << endl;
    }
}

void test_minBeaufortScale() {
    cout << "\n[Тестування задачі 9.2]" << endl;

    struct TestCase {
        vector<double> speeds;
        int expected;
    };

    vector<TestCase> tests = {
        {{0.0, 0.1, 0.2, 0.25, 0.28, 0.29}, 0},
        {{3.0, 1.2, 0.5, 6.0, 10.0, 2.5}, 1},
        {{28.0, 12.0, 8.0, 20.0, 17.5, 3.2}, 2}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        int result = minBeaufortScale(tests[i].speeds);
        cout << "  Приклад " << i + 1 << " → Очікується: " << tests[i].expected << ", Отримано: " << result;
        if (result == tests[i].expected) cout << " ✔" << endl;
        else cout << " ✘" << endl;
    }
}

void test_countBits() {
    cout << "\n[Тестування задачі 9.3]" << endl;
    struct TestCase {
        unsigned int N;
        int expected;
    } tests[] = {
        {512, 9},
        {256, 2},
        {1023, 0}
    };

    for (const auto& t : tests) {
        int result = countBits(t.N);
        cout << "  Вхід: " << t.N << " → Очікується: " << t.expected << ", Отримано: " << result;
        if (result == t.expected) cout << " ✔" << endl;
        else cout << " ✘" << endl;
    }
}

int main() {
    test_calculateBill();
    test_minBeaufortScale();
    test_countBits();
    return 0;
}
