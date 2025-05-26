#include "head_of_department.h"

#include <iostream>

namespace lab7 {
    HeadOfDepartment::HeadOfDepartment() : Teacher(), numberOfSubordinates(0), managementExperience(""), administrativeSalary(0.0) {
        std::cout << "HeadOfDepartment()" << std::endl;
    }

    HeadOfDepartment::HeadOfDepartment(const std::string& name, int age, const std::string& address,
                                       const std::string& department, const std::string& academicTitle, int yearsOfExperience,
                                       int numberOfSubordinates, const std::string& managementExperience, double administrativeSalary)
        : Teacher(name, age, address, department, academicTitle, yearsOfExperience), 
          numberOfSubordinates(numberOfSubordinates), managementExperience(managementExperience), administrativeSalary(administrativeSalary) {
        std::cout << "HeadOfDepartment()" << std::endl;
    }

    HeadOfDepartment::~HeadOfDepartment() {
        std::cout << "~HeadOfDepartment()" << std::endl;
    }

    HeadOfDepartment::HeadOfDepartment(const HeadOfDepartment& other) 
        : Teacher(other), numberOfSubordinates(other.numberOfSubordinates), 
          managementExperience(other.managementExperience), administrativeSalary(other.administrativeSalary) {
        std::cout << "HeadOfDepartment(const HeadOfDepartment&)" << std::endl;
    }

    HeadOfDepartment& HeadOfDepartment::operator=(const HeadOfDepartment& other) {
        if (this != &other) {
            Teacher::operator=(other);
            numberOfSubordinates = other.numberOfSubordinates;
            managementExperience = other.managementExperience;
            administrativeSalary = other.administrativeSalary;
        }
        std::cout << "HeadOfDepartment::operator=(const HeadOfDepartment&)" << std::endl;
        return *this;
    }

    void HeadOfDepartment::show() const {
        std::cout << "Заведующий кафедрой: " << name << ", Возраст: " << age 
                  << ", Адрес: " << address << ", Кафедра: " << department 
                  << ", Звание: " << academicTitle << ", Стаж: " << yearsOfExperience << " лет"
                  << ", Подчиненных: " << numberOfSubordinates 
                  << ", Управленческий опыт: " << managementExperience
                  << ", Административная зарплата: " << administrativeSalary << " руб." << std::endl;
    }
}
