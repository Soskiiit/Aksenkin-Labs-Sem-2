#include "lab8_tasks.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

double Point::distance_from_origin() const {
    return std::sqrt(x * x + y * y);
}

void Point::shift_left(double offset) {
    x -= offset;
}

bool Point::operator<(const Point& other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
}

bool Point::operator==(const Point& other) const {
    return (std::abs(x - other.x) < 1e-9) && (std::abs(y - other.y) < 1e-9);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << std::fixed << std::setprecision(1) << p.x << ", " << p.y << ")";
    return os;
}

void print_point_vector(const std::vector<Point>& points, const std::string& title = "") {
    if (!title.empty()) {
        std::cout << title << ":\n";
    }
    
    std::cout << "Размер вектора: " << points.size() << "\n";
    
    for (size_t i = 0; i < points.size(); i++) {
        std::cout << "Точка " << (i + 1) << ": " << points[i] 
                  << " (расстояние от центра: " 
                  << std::fixed << std::setprecision(2) 
                  << points[i].distance_from_origin() << ")\n";
    }
    std::cout << "\n";
}

void task5_point_vector() {
    std::cout << "\n=== ЗАДАНИЕ 5: Класс Point с контейнером vector ===\n";
    
    std::vector<Point> points = {
        Point(1.2, 6.3),
        Point(4.0, 0.7),
        Point(7.2, 0.8),
        Point(5.3, 3.0),
        Point(4.9, 6.6),
        Point(9.3, 0.2)
    };
    
    print_point_vector(points, "Исходный массив точек");
    
    auto max_distance_it = std::max_element(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return a.distance_from_origin() < b.distance_from_origin();
        });
    
    std::cout << "Точка, наиболее удаленная от центра координат:\n";
    std::cout << *max_distance_it << " (расстояние: " 
              << std::fixed << std::setprecision(2) 
              << max_distance_it->distance_from_origin() << ")\n\n";
    
    double shift_distance;
    std::cout << "Введите расстояние для сдвига всех точек влево по оси X: ";
    std::cin >> shift_distance;
    
    for (Point& point : points) {
        point.shift_left(shift_distance);
    }
    
    print_point_vector(points, "Массив точек после сдвига влево на " + 
                               std::to_string(shift_distance) + " единиц");
}
