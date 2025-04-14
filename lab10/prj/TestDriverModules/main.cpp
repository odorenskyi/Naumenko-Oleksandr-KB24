#include "D:\Lab10\prj\TestDriverModules\TestDriver.h"
#include <locale>  // Додано для роботи з локалізацією

int main() {
    // Встановлення української локалі
    setlocale(LC_ALL, "Ukrainian");
    std::locale::global(std::locale(""));  // Додано std::

    TestDriver testDriver;
    testDriver.runAllTests();

    return 0;
}
