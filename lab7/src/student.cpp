#include "student.h"

#include <iostream>

namespace lab7 {
    Student::Student() : Person(), studentId(""), group(""), averageGrade(0.0) {
        std::cout << "Student()" << std::endl;
    }

    Student::Student(const std::string& name, int age, const std::string& address,
                     const std::string& studentId, const std::string& group, double averageGrade)
        : Person(name, age, address), studentId(studentId), group(group) {
        validateAverageGrade(averageGrade);
        this->averageGrade = averageGrade;
        std::cout << "Student()" << std::endl;
    }

    Student::~Student() {
        std::cout << "~Student()" << std::endl;
    }

    Student::Student(const Student& other) 
        : Person(other), studentId(other.studentId), group(other.group), averageGrade(other.averageGrade) {
        std::cout << "Student(const Student&)" << std::endl;
    }

    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            Person::operator=(other);
            studentId = other.studentId;
            group = other.group;
            validateAverageGrade(other.averageGrade);
            averageGrade = other.averageGrade;
        }
        std::cout << "Student::operator=(const Student&)" << std::endl;
        return *this;
    }

    void Student::show() const {
        std::cout << "Студент: " << name << ", Возраст: " << age 
                  << ", Адрес: " << address << ", ID: " << studentId 
                  << ", Группа: " << group << ", Средний балл: " << averageGrade << std::endl;
    }
}
