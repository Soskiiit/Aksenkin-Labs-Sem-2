#include "lab8_tasks.h"

#include <fstream>
#include <iostream>
#include <string>

std::string to_uppercase_latin(const std::string& line) {
    std::string result = line;
    
    for (char& c : result) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        } else if (c >= 'а' && c <= 'я') {
            c = c - 'а' + 'А';
        }
    }
    
    return result;
}

void task3_file_processing() {
    std::cout << "\n=== ЗАДАНИЕ 3: Работа с файлами ===\n";
    
    const std::string input_filename = "input.txt";
    const std::string output_filename = "output.txt";
    
    std::cout << "Создаем тестовый файл '" << input_filename << "'...\n";
    std::ofstream input_file(input_filename);
    if (!input_file.is_open()) {
        std::cout << "Ошибка: не удалось создать файл " << input_filename << "\n";
        return;
    }
    
    input_file << "Hello World! This is a Test File.\n";
    input_file << "It contains MIXED case letters: abc XYZ 123.\n";
    input_file << "Some russian text: Привет мир!\n";
    input_file << "Special characters: @#$%^&*()_+-=[]{}|;':\",./<>?\n";
    input_file << "lowercase: abcdefghijklmnopqrstuvwxyz\n";
    input_file << "UPPERCASE: ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    input_file.close();
    
    std::ifstream infile(input_filename);
    std::ofstream outfile(output_filename);
    
    if (!infile.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл " << input_filename << "\n";
        return;
    }
    
    if (!outfile.is_open()) {
        std::cout << "Ошибка: не удалось создать файл " << output_filename << "\n";
        infile.close();
        return;
    }
    
    std::string line;
    int line_number = 1;
    
    std::cout << "\nОбрабатываем файл построчно:\n";
    std::cout << "==================================\n";
    
    while (std::getline(infile, line)) {
        std::cout << "Строка " << line_number << " (исходная): " << line << "\n";
        
        std::string processed_line = to_uppercase_latin(line);
        
        std::cout << "Строка " << line_number << " (обработанная): " << processed_line << "\n";
        std::cout << "---\n";
        
        outfile << processed_line << "\n";
        
        line_number++;
    }
    
    infile.close();
    outfile.close();
    
    std::cout << "\nОбработка завершена!\n";
    std::cout << "Исходный файл: " << input_filename << "\n";
    std::cout << "Результат сохранен в: " << output_filename << "\n";
    
    std::cout << "\nСодержимое выходного файла:\n";
    std::cout << "==========================\n";
    std::ifstream result_file(output_filename);
    if (result_file.is_open()) {
        std::string result_line;
        while (std::getline(result_file, result_line)) {
            std::cout << result_line << "\n";
        }
        result_file.close();
    }
    
    std::cout << "\nСтатистика обработки:\n";
    std::cout << "Обработано строк: " << (line_number - 1) << "\n";
    std::cout << "Функция преобразования: to_uppercase_latin()\n";
    std::cout << "Преобразованы все маленькие латинские буквы (a-z) в большие (A-Z)\n";
}
