#pragma once

#include <iostream>
#include <string>

//#include <stdexcept> // есть стандартные исключени€ std::out_of_range

//  ласс Wrong_Date производный от out_of_range дл€ обработки ошибок с датой
class Wrong_Date : public std::out_of_range {
private:
    int day;
    int month;
    int year;

public:
    //  онструктор класса Wrong_Date
    Wrong_Date(int d, int m, int y) : std::out_of_range("!!!Incorrect date!!!"), day(d), month(m), year(y) {}

    // ћетод дл€ вывода информации о некорректной дате
    void printIncorrectDate();
};

// ќпределение метода printIncorrectDate из класса Wrong_Date
void Wrong_Date::printIncorrectDate() {
    std::cout << "Incorrect Date: " << day << "." << month << "." << year << std::endl;
}

//  ласс дл€ представлени€ даты
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y); // ќбъ€вление конструктора

    bool isCorrectDate(); //ќбъ€вление метода проверки корректности даты

    void printDate(); //ќбъ€вление метода вывода даты
};

// ќпределение конструктора Date
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (!Date::isCorrectDate()) {
        throw Wrong_Date(d, m, y); // √енераци€ исключени€: значание исключени€ - класс Wrong_Date, производный от out_of_range
    }
}

// ќпределение метода дл€ вывода даты
void Date::printDate() {
    std::cout << day << "." << month << "." << year << std::endl;
}

// ќпределение метода проверки корректности даты
bool Date::isCorrectDate() {

    // ќбщее условие : кол-во дней в мес€це 1 <= n <= 31
    if (day < 1 || day > 31) return false;

    //‘евраль: 29 или 28 дней 
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // високосный год (| 4 и | 100) или(| 400)
            if (day > 29) return false;
        }
        else { // невисокосный год
            if (day > 28) return false;
        }
    }

    // 30 дней: апрель, июнь, сент€брь, но€брь
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    //ќбщее условие : 1 <= мес€ц <= 12
    if (month < 1 || month > 12) return false;

    // ќбщее условие : год > 0
    if (year < 0) return false;

    // если все хорошо
    return true;
}
  