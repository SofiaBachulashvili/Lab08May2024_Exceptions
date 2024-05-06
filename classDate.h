#pragma once

#include <iostream>
#include <string>

//#include <stdexcept> // ���� ����������� ���������� std::out_of_range

// ����� Wrong_Date ����������� �� out_of_range ��� ��������� ������ � �����
class Wrong_Date : public std::out_of_range {
private:
    int day;
    int month;
    int year;

public:
    // ����������� ������ Wrong_Date
    Wrong_Date(int d, int m, int y) : std::out_of_range("!!!Incorrect date!!!"), day(d), month(m), year(y) {}

    // ����� ��� ������ ���������� � ������������ ����
    void printIncorrectDate();
};

// ����������� ������ printIncorrectDate �� ������ Wrong_Date
void Wrong_Date::printIncorrectDate() {
    std::cout << "Incorrect Date: " << day << "." << month << "." << year << std::endl;
}

// ����� ��� ������������� ����
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y); // ���������� ������������

    bool isCorrectDate(); //���������� ������ �������� ������������ ����

    void printDate(); //���������� ������ ������ ����
};

// ����������� ������������ Date
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (!Date::isCorrectDate()) {
        throw Wrong_Date(d, m, y); // ��������� ����������: �������� ���������� - ����� Wrong_Date, ����������� �� out_of_range
    }
}

// ����������� ������ ��� ������ ����
void Date::printDate() {
    std::cout << day << "." << month << "." << year << std::endl;
}

// ����������� ������ �������� ������������ ����
bool Date::isCorrectDate() {

    // ����� ������� : ���-�� ���� � ������ 1 <= n <= 31
    if (day < 1 || day > 31) return false;

    //�������: 29 ��� 28 ���� 
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // ���������� ��� (| 4 � | 100) ���(| 400)
            if (day > 29) return false;
        }
        else { // ������������ ���
            if (day > 28) return false;
        }
    }

    // 30 ����: ������, ����, ��������, ������
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    //����� ������� : 1 <= ����� <= 12
    if (month < 1 || month > 12) return false;

    // ����� ������� : ��� > 0
    if (year < 0) return false;

    // ���� ��� ������
    return true;
}
  