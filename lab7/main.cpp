#include "include/container_functions.h"
#include <iostream>

int main() {
    std::cout << "=== ЛАБОРАТОРНАЯ РАБОТА №7 ===" << std::endl;
    std::cout << "Виртуальные функции и классы" << std::endl;
    std::cout << "Вариант 1: Персона, Студент, Преподаватель, Заведующий кафедрой" << std::endl;
    
    int mode;
    std::cout << "\nВыберите режим работы:" << std::endl;
    std::cout << "1. Демонстрационный режим" << std::endl;
    std::cout << "2. Интерактивный режим" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> mode;
    
    switch (mode) {
        case 1:
            lab7::demonstrationMode();
            break;
        case 2:
            lab7::interactiveMode();
            break;
        default:
            std::cout << "Неверный выбор! Запускаем демонстрационный режим по умолчанию." << std::endl;
            lab7::demonstrationMode();
            break;
    }
    
    std::cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}
