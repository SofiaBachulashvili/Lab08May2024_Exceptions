// Lab08May2024.cpp
#include "classDate.h"


int main() {

    // НЕКОРРЕКТНЫЕ ДАТЫ

    std::cout << "  # INCORRECT DATES \n\n ";
    try {
        Date dateN(29, 2, 2023);   // Попробуем создать некорректную дату: ошибка - невисокосный год
        dateN.printDate(); // Вывод даты
    }
    catch (Wrong_Date& e) {
        //метод what(), который унаследован от класса std::exception и возвращает строку,
        // описывающую исключение "!!!Incorrect date!!!"
        std::cout << e.what() << std::endl;
        e.printIncorrectDate(); // Вывод информации о некорректной дате
    }

    std::cout << "\n";

    try {
        Date dateN(32, 12, 2004);  // Попробуем создать некорректную дату : ошибка - кол-во дней в месяце 32
        dateN.printDate();
    }
    //Перехват исключения Wrong_Date
    catch (Wrong_Date& e) {
        std::cout << e.what() << std::endl; 
        e.printIncorrectDate();
    }

    std::cout << "\n";

    try {
        Date dateN(31, 6, 2024);  // Попробуем создать некорректную дату : ошибка - кол-во дней в месяце 31
        dateN.printDate();
    }
    catch (Wrong_Date& e) {
        std::cout << e.what() << std::endl;
        e.printIncorrectDate();
    }

    std::cout << "\n";
    
    try{
        Date dateN(4, 8, -3);  // Попробуем создать корректную дату в будущем
        dateN.printDate();
    }
        catch (Wrong_Date& e) {
        std::cout << e.what() << std::endl;
        e.printIncorrectDate();
    }

    std::cout << "\n";




    // КОРРЕКТНЫЕ ДАТЫ
    std::cout << "\n\n  # CORRECT DATES \n\n";

    try {
        Date dateN(27, 5, 1703);  // Создаем корректную дату в прошлом
        dateN.printDate(); // Вывод даты
    }
    catch (Wrong_Date& e) { // Перехват исключения Wrong_Date
        std::cout << e.what() << std::endl; // Вывод сообщения об ошибке
        e.printIncorrectDate(); // Вывод информации о некорректной дате
    }

    std::cout << "\n";

    try {
        Date dateN(22, 2, 14567);  // Попробуем создать корректную дату в будущем
        dateN.printDate();
    }
    catch (Wrong_Date& e) {
        std::cout << e.what() << std::endl;
        e.printIncorrectDate();
    }

    return 0;
}
