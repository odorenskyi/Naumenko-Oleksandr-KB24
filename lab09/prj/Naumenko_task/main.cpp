#include <iostream>
#include <cctype>
#include <limits>
#include <clocale>
#include ""D:\Lab09\prj\ModulesNaumenko.h""

using namespace std;

void run_program() {
    char command;
    while (true) {
        cout << "\n������ ������� ('z', 'r', 's', 't') ��� 'q' ��� ������: ";
        cin >> command;

        switch (tolower(command)) {
            case 'z': {
                double x, y, z;
                cout << "������ x, y, z ��� ���������� S: ";
                cin >> x >> y >> z;
                double result = s_calculation(x, y, z);
                cout << "��������� ���������� s_calculation: " << result << endl;
                break;
            }
            case 'r': {
                int kWh;
                cout << "������ ���������� �����������㳿 (������): ";
                cin >> kWh;
                double result = calculateBill(kWh);
                cout << "���� �� ������: " << result << " ���\n";
                break;
            }
            case 's': {
                double temps[6];
                cout << "������ ����������� (6 ������� ����� �����): ";
                for (int i = 0; i < 6; ++i) {
                    cin >> temps[i];
                }
                double avg;
                temperatureAnalysis(temps, 6, avg);
                cout << "������� �����������: " << avg << " �C\n";
                break;
            }
            case 't': {
                unsigned int N;
                cout << "������ ���������� ����� N: ";
                cin >> N;
                int count = countBits(N);
                cout << "ʳ������ ������������ ���: " << count << endl;
                break;
            }
            case 'q':
                cout << "���������� ��������.\n";
                return;
            default:
                cout << "\a������ �������! �������� ��������.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    run_program();
    return 0;
}
