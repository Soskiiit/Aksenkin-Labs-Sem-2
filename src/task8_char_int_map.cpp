#include "../include/lab8_tasks.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>

void print_char_int_map(const std::map<char, int>& char_map) {
    std::cout << "\n====================================\n";
    std::cout << " Символ  | Значение\n";
    std::cout << "====================================\n";
    
    for (const auto& pair : char_map) {
        std::cout << "    " << pair.first << "    |    " << pair.second << "\n";
    }
    std::cout << "====================================\n";
}

void task8_char_int_map() {
    std::cout << "\n=== ЗАДАНИЕ 8: Отображение символов на числа (map) ===\n";
    
    std::map<char, int> char_to_int_map;
    
    std::cout << "Создаем отображение символов на числа:\n";
    char_to_int_map['A'] = 1;
    char_to_int_map['B'] = 2;
    char_to_int_map['C'] = 3;
    char_to_int_map['D'] = 4;
    char_to_int_map['E'] = 5;
    
    std::cout << "Добавлены пары: A->1, B->2, C->3, D->4, E->5\n";
    print_char_int_map(char_to_int_map);
    
    std::cout << "\nДемонстрация поиска по символам:\n";
    
    char test_chars[] = {'A', 'C', 'E', 'X'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
    
    for (int i = 0; i < num_tests; i++) {
        char search_char = test_chars[i];
        std::cout << "\nПоиск символа '" << search_char << "':\n";
        
        auto it = char_to_int_map.find(search_char);
        if (it != char_to_int_map.end()) {
            std::cout << "✓ Символ '" << search_char << "' найден!\n";
            std::cout << "  Соответствующее число: " << it->second << "\n";
        } else {
            std::cout << "✗ Символ '" << search_char << "' не найден в отображении.\n";
            std::cout << "  Доступные символы: A, B, C, D, E\n";
        }
    }
    
    std::cout << "\nДополнительная статистика:\n";
    std::cout << "- Количество элементов в отображении: " << char_to_int_map.size() << "\n";
    
    auto min_element = std::min_element(char_to_int_map.begin(), char_to_int_map.end(),
        [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second < b.second;
        });
    
    auto max_element = std::max_element(char_to_int_map.begin(), char_to_int_map.end(),
        [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second < b.second;
        });
    
    std::cout << "- Минимальное значение: " << min_element->first 
              << " -> " << min_element->second << "\n";
    std::cout << "- Максимальное значение: " << max_element->first 
              << " -> " << max_element->second << "\n";
    
    
    int sum = 0;
    for (const auto& pair : char_to_int_map) {
        sum += pair.second;
    }
    std::cout << "- Сумма всех значений: " << sum << "\n";
    std::cout << "- Среднее значение: " << std::fixed << std::setprecision(1) 
              << static_cast<double>(sum) / char_to_int_map.size() << "\n";
}

