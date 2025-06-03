#include "lab8_tasks.h"

#include <iostream>
#include <string>

void show_menu() {
    std::cout << "\n========================================\n";
    std::cout << "  ЛАБОРАТОРНАЯ РАБОТА №8 - ВАРИАНТ 1\n";
    std::cout << "     Стандартная библиотека шаблонов\n";
    std::cout << "========================================\n";
    std::cout << "1. Задание 1 - Подсчет предложений в текстах (string)\n";
    std::cout << "2. Задание 2 - Фильтрация символов (string)\n";
    std::cout << "3. Задание 3 - Обработка файлов (string)\n";
    std::cout << "4. Задание 4 - Операции с вектором (vector)\n";
    std::cout << "5. Задание 5 - Класс Point с вектором (vector)\n";
    std::cout << "6. Задание 6 - Операции со списком (list)\n";
    std::cout << "7. Задание 7 - Класс Planet со списком (list)\n";
    std::cout << "8. Задание 8 - Отображение символов (map)\n";
    std::cout << "9. Задание 9 - Отображение штатов США (map)\n";
    std::cout << "0. Выход\n";
    std::cout << "========================================\n";
    std::cout << "Выберите пункт меню: ";
}

int main() {
    int choice;
    bool continue_program = true;
    
    while (continue_program) {
        show_menu();
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1:
                task1_count_sentences();
                break;
                
            case 2:
                task2_filter_characters();
                break;
                
            case 3:
                task3_file_processing();
                break;
                
            case 4:
                task4_vector_operations();
                break;
                
            case 5:
                task5_point_vector();
                break;
                
            case 6:
                task6_list_operations();
                break;
                
            case 7:
                task7_planet_list();
                break;
                
            case 8:
                task8_char_int_map();
                break;
                
            case 9:
                task9_states_map();
                break;
                    
            case 0:
                std::cout << "Завершение программы\n";
                continue_program = false;
                break;
                
            default:
                std::cout << "Неверный выбор! Попробуйте снова.\n";
                break;
        }
        
        if (continue_program && choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.get();
        }
    }
    
    return 0;
}
