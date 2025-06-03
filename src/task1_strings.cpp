#include "lab8_tasks.h"

#include <algorithm>
#include <iostream>
#include <string>

int count_sentences_in_text(const std::string& text) {
    int sentence_count = 0;
    
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentence_count++;
        }
    }
    
    return sentence_count;
}

void task1_count_sentences() {
    std::cout << "\n=== ЗАДАНИЕ 1: Подсчет количества предложений в текстах ===\n";
    
    std::string text1, text2;
    
    std::cout << "Введите первый текст: ";
    std::getline(std::cin, text1);
    
    std::cout << "Введите второй текст: ";
    std::getline(std::cin, text2);
    
    int sentences1 = count_sentences_in_text(text1);
    int sentences2 = count_sentences_in_text(text2);
    
    std::cout << "\nРезультаты:\n";
    std::cout << "Первый текст: \"" << text1 << "\"\n";
    std::cout << "Количество предложений в первом тексте: " << sentences1 << "\n\n";
    
    std::cout << "Второй текст: \"" << text2 << "\"\n";
    std::cout << "Количество предложений во втором тексте: " << sentences2 << "\n\n";
    
    if (sentences1 > sentences2) {
        std::cout << "В первом тексте больше предложений на " << (sentences1 - sentences2) << "\n";
    } else if (sentences2 > sentences1) {
        std::cout << "Во втором тексте больше предложений на " << (sentences2 - sentences1) << "\n";
    } else {
        std::cout << "В обоих текстах одинаковое количество предложений\n";
    }
}
