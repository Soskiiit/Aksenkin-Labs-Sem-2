#include "lab8_tasks.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

void print_vector(const std::vector<float>& vec, const std::string& title) {
    if (!title.empty()) {
        std::cout << title << ":\n";
    }
    
    std::cout << "Размер вектора: " << vec.size() << "\n";
    std::cout << "Содержимое вектора: [";
    
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << std::fixed << std::setprecision(2) << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    
    std::cout << "]\n\n";
}

void task4_vector_operations() {
    std::cout << "\n=== ЗАДАНИЕ 4: Операции с вектором ===\n";
    
    std::vector<float> vec;
    
    std::cout << "Заполняем вектор 25 вещественными числами:\n";
    for (int i = 0; i < 25; i++) {
        float value = (i + 1) * 1.5f + (i % 3) * 0.7f;
        vec.push_back(value);
    }
    
    print_vector(vec, "Исходный вектор");
    
    if (vec.size() > 1) {
        std::cout << "Удаляем элемент с индексом 1 (значение: " 
                  << std::fixed << std::setprecision(2) << vec[1] << ")\n";
        vec.erase(vec.begin() + 1);
    }
    
    print_vector(vec, "Вектор после удаления элемента с индексом 1");
}
