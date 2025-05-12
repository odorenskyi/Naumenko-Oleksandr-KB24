#ifndef STRUCT_TYPE_PROJECT_5_H_INCLUDED
#define STRUCT_TYPE_PROJECT_5_H_INCLUDED

#include <string>
using namespace std;

// ��������� ��� ��������� ���������� ��� ���� ��������
struct BusSchedule {
    int routeNumber;               // ����� ����� (���������)
    string departureStop;          // ������� �����������
    string arrivalStop;            // ������� ��������
    string frequency;              // ������� ���� (���������, "�����", "���� ��", "������ ��")
    string departureTime;          // ��� ����������� (������ "HH:MM")
    string arrivalTime;            // ��� �������� (������ "HH:MM")

    // ����������� �� �������������
    BusSchedule()
        : routeNumber(0), departureStop(""), arrivalStop(""),
          frequency(""), departureTime(""), arrivalTime("") {}

    // ����������� � �����������
    BusSchedule(int rn, const string &dep, const string &arr, const string &freq,
                const string &depTime, const string &arrTime)
        : routeNumber(rn), departureStop(dep), arrivalStop(arr),
          frequency(freq), departureTime(depTime), arrivalTime(arrTime) {}
};

// ����� ������������ ������, �� ������ ����� ��� ���������� ����
struct Node {
    BusSchedule record; // ����� ��������
    Node* next;         // �������� �� ��������� �����

    // ����������� �����
    Node(const BusSchedule &rec)
        : record(rec), next(nullptr) {}
};

#endif // STRUCT_TYPE_PROJECT_5_H_INCLUDED
