#include "lab8_tasks.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>


void print_states_map(const std::map<std::string, int>& states_map) {
    std::cout << "Содержимое отображения штатов:\n";
    std::cout << "====================================\n";
    
    for (const auto& pair : states_map) {
        std::cout << "Штат: " << std::left << std::setw(20) << pair.first 
                  << " | Население: " << std::right << std::setw(6) << pair.second << " тыс. чел.\n";
    }
    
    std::cout << "====================================\n\n";
}

void task9_states_map() {
    std::cout << "\n=== ЗАДАНИЕ 9: Работа с отображением штатов США ===\n";
    
    std::string states[] = {"Wyoming", "Colorado", "Nevada", "Montana", "Arizona", "Idaho"};
    int pops[] = {470, 2890, 800, 787, 2718, 944};
    
    std::map<std::string, int> states_map;
    
    int array_size = sizeof(states) / sizeof(states[0]);
    
    std::cout << "Создаем отображение из массивов данных:\n";
    for (int i = 0; i < array_size; i++) {
        states_map[states[i]] = pops[i];
        std::cout << "Добавляем: " << states[i] << " -> " << pops[i] << " тыс. чел.\n";
    }
    std::cout << "\n";
    
    print_states_map(states_map);
    
    std::cout << "Поиск штата по названию\n";
    std::cout << "Введите название штата:";
    
    
    std::string search_state;
    getline(std::cin, search_state);
    std::cout << "Поиск штата '" << search_state << "':\n";
    
    auto it = states_map.find(search_state);
    
    if (it != states_map.end()) {
        std::cout << "Штат " << search_state << " найден!\n";
        std::cout << "Население: " << it->second << " тысяч человек\n\n";
    } else {
        std::cout << "Штат " << search_state << " не найден в базе данных.\n";
        std::cout << "Доступные штаты: ";
        bool first = true;
        for (const auto& pair : states_map) {
            if (!first) std::cout << ", ";
            std::cout << pair.first;
            first = false;
        }
        std::cout << "\n\n";
    }
}

