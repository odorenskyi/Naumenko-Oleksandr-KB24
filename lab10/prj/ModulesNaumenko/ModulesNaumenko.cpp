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
        throw runtime_error("Помилка відкриття файлів!");
    }

    // Запис авторської інформації
    outFile << "Автор: Науменко\n";
    outFile << "Установа: ЦНТУ\n";
    outFile << "Місто: Кропивницький\n";
    outFile << "Країна: Україна\n";
    outFile << "Рік розробки: 2025\n\n";

    // Підрахунок символів
    inFile.seekg(0, ios::end);
    size_t charCount = inFile.tellg();
    inFile.seekg(0, ios::beg);
    outFile << "У файлі " << inputFile << " міститься " << charCount << " символів.\n\n";

    // Читаємо весь вміст файлу
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    // Перетворюємо на нижній регістр для порівняння
    string lowerContent = content;
    transform(lowerContent.begin(), lowerContent.end(), lowerContent.begin(), ::tolower);

    vector<string> baseWords = {"програм", "модул", "студент", "програміст"};
    vector<string> keywords = {"програма", "модуль", "студент", "програміст"};
    vector<bool> found(keywords.size(), false);

    for (size_t i = 0; i < baseWords.size(); ++i) {
        // Шукаємо основу слова (для знаходження різних форм)
        if (lowerContent.find(baseWords[i]) != string::npos) {
            found[i] = true;
        }
    }

    outFile << "Результати пошуку ключових слів:\n";
    for (size_t i = 0; i < keywords.size(); ++i) {
        outFile << "- Слово \"" << keywords[i] << "\" "
                << (found[i] ? "знайдено" : "не знайдено") << " у файлі.\n";
    }

    outFile.close();
}

void solveTask10_2(const string& inputFile) {
    // Встановлення української локалі
    setlocale(LC_ALL, "Ukrainian");
    locale::global(locale(""));

    ofstream outFile(inputFile, ios::app);

    if (!outFile.is_open()) {
        throw runtime_error("Помилка відкриття файлу!");
    }

    // Додаємо державні символи України
    outFile << "\n\n--- Державні символи України (ст. 20 Конституції України) ---\n";
    outFile << "1. Державний Прапор України\n";
    outFile << "2. Державний Герб України\n";
    outFile << "3. Державний Гімн України\n";

    // Додаємо поточну дату
    time_t now = time(nullptr);
    char* dt = ctime(&now);
    outFile << "\nДата дозаписування інформації: " << dt;

    outFile.close();
}

int s_calculation(int x, int y, int z) {
    if (x - y + z == 0) {
        throw runtime_error("Ділення на нуль у функції s_calculation");
    }
    return (sqrt(x) + pow(y, 2)) / (x - y + z);
}

void solveTask10_3(int x, int y, int z, int b, const string& outputFile) {
    setlocale(LC_ALL, "Ukrainian");
    locale::global(locale(""));

    ofstream outFile(outputFile, ios::app);

    if (!outFile.is_open()) {
        throw runtime_error("Помилка відкриття файлу!");
    }

    outFile << "\n\n--- Результати обчислень ---\n";

    try {
        int result = s_calculation(x, y, z);
        outFile << "Результат функції s_calculation(" << x << ", " << y << ", " << z << "): " << result << "\n";
    } catch (const exception& e) {
        outFile << "Помилка обчислення: " << e.what() << "\n";
    }

    bitset<32> binary(b);
    outFile << "Число " << b << " у двійковому коді: " << binary << "\n";

    outFile.close();
}
