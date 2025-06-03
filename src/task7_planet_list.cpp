#include "lab8_tasks.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>

bool Planet::operator<(const Planet& other) const {
    return satellites < other.satellites;
}

bool Planet::operator==(const Planet& other) const {
    return name == other.name && satellites == other.satellites;
}

std::ostream& operator<<(std::ostream& os, const Planet& p) {
    os << p.name << " (" << p.satellites << " спутников)";
    return os;
}


void print_planet_list(const std::list<Planet>& planets, const std::string& title = "") {
    if (!title.empty()) {
        std::cout << title << ":\n";
    }
    
    std::cout << "Количество планет: " << planets.size() << "\n";
    std::cout << "Список планет:\n";
    std::cout << "==============\n";
    
    int counter = 1;
    for (const Planet& planet : planets) {
        std::cout << counter << ". " << planet.name 
                  << " - " << planet.satellites << " спутников\n";
        counter++;
    }
    std::cout << "\n";
}


void task7_planet_list() {
    std::cout << "\n=== ЗАДАНИЕ 7: Класс Planet с контейнером list ===\n";
    

    std::list<Planet> planets = {
        Planet("Меркурий", 0),
        Planet("Венера", 0),
        Planet("Земля", 1),
        Planet("Марс", 2),
        Planet("Юпитер", 69),
        Planet("Сатурн", 62),
        Planet("Уран", 27),
        Planet("Нептун", 14),
        Planet("Плутон", 10)
    };
    

    print_planet_list(planets, "Планеты Солнечной системы");
    

    auto max_satellites_it = std::max_element(planets.begin(), planets.end(),
        [](const Planet& a, const Planet& b) {
            return a.satellites < b.satellites;
        });
    
    std::cout << "Планета с максимальным количеством спутников:\n";
    std::cout << "🪐 " << max_satellites_it->name 
              << " - " << max_satellites_it->satellites << " спутников\n\n";
    

    std::cout << "Статистика по планетам:\n";
    std::cout << "======================\n";
    

    int total_satellites = 0;
    for (const Planet& planet : planets) {
        total_satellites += planet.satellites;
    }
    std::cout << "Общее количество спутников в Солнечной системе: " 
              << total_satellites << "\n";
    

    double average_satellites = static_cast<double>(total_satellites) / planets.size();
    std::cout << "Среднее количество спутников на планету: " 
              << std::fixed << std::setprecision(1) << average_satellites << "\n";
    

    std::cout << "\nПланеты без спутников:\n";
    for (const Planet& planet : planets) {
        if (planet.satellites == 0) {
            std::cout << "- " << planet.name << "\n";
        }
    }
    

    std::cout << "\nПланеты-гиганты (более 50 спутников):\n";
    for (const Planet& planet : planets) {
        if (planet.satellites > 50) {
            std::cout << "- " << planet.name << " (" << planet.satellites << " спутников)\n";
        }
    }
    

    std::cout << "\nПланеты внутренней части Солнечной системы:\n";
    auto it = planets.begin();
    for (int i = 0; i < 4 && it != planets.end(); i++, it++) {
        std::cout << "- " << it->name << " (" << it->satellites << " спутников)\n";
    }
    

    std::cout << "\nПланеты внешней части Солнечной системы:\n";
    it = planets.begin();
    std::advance(it, 4); 
    while (it != planets.end()) {
        std::cout << "- " << it->name << " (" << it->satellites << " спутников)\n";
        it++;
    }
    

    std::cout << "\nИнтересные факты:\n";
    std::cout << "================\n";
    

    auto min_nonzero_it = std::min_element(planets.begin(), planets.end(),
        [](const Planet& a, const Planet& b) {
            if (a.satellites == 0 && b.satellites == 0) return false;
            if (a.satellites == 0) return false;
            if (b.satellites == 0) return true;
            return a.satellites < b.satellites;
        });
    
    if (min_nonzero_it != planets.end() && min_nonzero_it->satellites > 0) {
        std::cout << "- Планета с минимальным ненулевым количеством спутников: " 
                  << min_nonzero_it->name << " (" << min_nonzero_it->satellites << ")\n";
    }
    

    int even_count = 0, odd_count = 0;
    for (const Planet& planet : planets) {
        if (planet.satellites % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    std::cout << "- Планет с четным количеством спутников: " << even_count << "\n";
    std::cout << "- Планет с нечетным количеством спутников: " << odd_count << "\n";
}
