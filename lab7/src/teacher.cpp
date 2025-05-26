#include "teacher.h"

#include <iostream>

namespace lab7 {
    Teacher::Teacher() : Person(), department(""), academicTitle(""), yearsOfExperience(0) {
        std::cout << "Teacher()" << std::endl;
    }

    Teacher::Teacher(const std::string& name, int age, const std::string& address,
                     const std::string& department, const std::string& academicTitle, int yearsOfExperience)
        : Person(name, age, address), department(department), academicTitle(academicTitle) {
        validateYearsOfExperience(yearsOfExperience);
        this->yearsOfExperience = yearsOfExperience;
        std::cout << "Teacher()" << std::endl;
    }

    Teacher::~Teacher() {
        std::cout << "~Teacher()" << std::endl;
    }

    Teacher::Teacher(const Teacher& other) 
        : Person(other), department(other.department), academicTitle(other.academicTitle), yearsOfExperience(other.yearsOfExperience) {
        std::cout << "Teacher(const Teacher&)" << std::endl;
    }

    Teacher& Teacher::operator=(const Teacher& other) {
        if (this != &other) {
            Person::operator=(other);
            department = other.department;
            academicTitle = other.academicTitle;
            validateYearsOfExperience(other.yearsOfExperience);
            yearsOfExperience = other.yearsOfExperience;
        }
        std::cout << "Teacher::operator=(const Teacher&)" << std::endl;
        return *this;
    }

    void Teacher::show() const {
        std::cout << "Преподаватель: " << name << ", Возраст: " << age 
                  << ", Адрес: " << address << ", Кафедра: " << department 
                  << ", Звание: " << academicTitle << ", Стаж: " << yearsOfExperience << " лет" << std::endl;
    }
}
