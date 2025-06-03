#include "lab8_tasks.h"

#include <iostream>
#include <string>

std::string filter_punctuation(const std::string& input) {
    std::string result = "";
    
    for (char c : input) {
        if (c != ' ' && c != '.' && c != ',') {
            result += c;
        }
    }
    
    return result;
}

void task2_filter_characters() {
    std::cout << "\n=== ЗАДАНИЕ 2: Фильтрация символов ===\n";
    
    std::string input;
    
    std::cout << "Введите последовательность символов: ";
    std::getline(std::cin, input);
    
    std::string filtered = filter_punctuation(input);
    
    std::cout << "\nРезультаты:\n";
    std::cout << "Исходная последовательность: \"" << input << "\"\n";
    std::cout << "Отфильтрованная последовательность: \"" << filtered << "\"\n";
    
    std::cout << "\nИсходная длина: " << input.length() << " символов\n";
    std::cout << "Длина после фильтрации: " << filtered.length() << " символов\n";
    std::cout << "Удалено символов: " << (input.length() - filtered.length()) << "\n";
    std::cout << "\n";
}
