#include "D:\Lab10\prj\TestDriverModules\TestDriver.h"
#include <locale>  // ������ ��� ������ � �����������

int main() {
    // ������������ ��������� �����
    setlocale(LC_ALL, "Ukrainian");
    std::locale::global(std::locale(""));  // ������ std::

    TestDriver testDriver;
    testDriver.runAllTests();

    return 0;
}
