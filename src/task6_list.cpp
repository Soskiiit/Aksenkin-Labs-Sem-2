#include "lab8_tasks.h"

#include <algorithm>
#include <iostream>

void print_list(const std::list<int>& lst, const std::string& title) {
    if (!title.empty()) {
        std::cout << title << ":\n";
    }
    
    std::cout << "Размер списка: " << lst.size() << "\n";
    std::cout << "Содержимое списка: [";
    
    bool first = true;
    for (const int& value : lst) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << value;
        first = false;
    }
    
    std::cout << "]\n\n";
}

void process_list(std::list<int>& lst) {
    auto it = lst.begin();
    while (it != lst.end()) {
        int value = *it;
        ++it;
        lst.insert(it, -value);
    }
    
    lst.remove_if([](int x) { return x < 0; });
}

void task6_list_operations() {
    std::cout << "\n=== ЗАДАНИЕ 6: Операции со списком ===\n";
    
    std::list<int> numbers = {5, -3, 8, 12, -7, 4, -1, 9};
    
    print_list(numbers, "Исходный список");
    
    std::list<int> temp_list = numbers;
    
    std::cout << "Добавляем после каждого элемента элемент с обратным знаком...\n";
    
    auto it = temp_list.begin();
    while (it != temp_list.end()) {
        int value = *it;
        ++it;
        temp_list.insert(it, -value);
    }
    
    print_list(temp_list, "Список после добавления элементов с обратным знаком");
    
    std::cout << "Удаляем все отрицательные элементы...\n";
    temp_list.remove_if([](int x) { return x < 0; });
    
    print_list(temp_list, "Список после удаления отрицательных элементов");
    
    std::cout << "Демонстрация функции process_list() на исходном списке:\n";
    process_list(numbers);
    print_list(numbers, "Результат применения process_list()");
    
    std::cout << "Дополнительная статистика:\n";
    
    if (!numbers.empty()) {
        int sum = 0;
        for (int value : numbers) {
            sum += value;
        }
        
        std::cout << "Количество элементов в итоговом списке: " << numbers.size() << "\n";
        std::cout << "Сумма всех элементов: " << sum << "\n";
        std::cout << "Среднее значение: " << static_cast<double>(sum) / numbers.size() << "\n";
        
        auto min_it = std::min_element(numbers.begin(), numbers.end());
        auto max_it = std::max_element(numbers.begin(), numbers.end());
        
        std::cout << "Минимальный элемент: " << *min_it << "\n";
        std::cout << "Максимальный элемент: " << *max_it << "\n";
    } else {
        std::cout << "Итоговый список пуст!\n";
    }
    
    std::cout << "\nДополнительный пример с новыми данными:\n";
    std::list<int> example2 = {10, 20, -5, 15, -8, 25};
    print_list(example2, "Новый исходный список");
    
    process_list(example2);
    print_list(example2, "Результат обработки нового списка");
}
