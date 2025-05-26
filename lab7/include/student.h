#pragma once

#include "person.h"

namespace lab7 {
    class Student : public Person {
    protected:
        std::string studentId;
        std::string group;
        double averageGrade;
        
        void validateAverageGrade(double grade) const {
            if (grade < 0.0) {
                throw std::invalid_argument("Средний балл не может быть отрицательным");
            }
            if (grade > 5.0) {
                throw std::invalid_argument("Средний балл не может быть больше 5.0");
            }
        }

    public:
        Student();
        Student(const std::string& name, int age, const std::string& address,
                const std::string& studentId, const std::string& group, double averageGrade);
        virtual ~Student();
        
        Student(const Student& other);
        Student& operator=(const Student& other);

        void show() const override;
        
        const std::string& getStudentId() const { return studentId; }
        const std::string& getGroup() const { return group; }
        double getAverageGrade() const { return averageGrade; }
        
        void setStudentId(const std::string& studentId) { this->studentId = studentId; }
        void setGroup(const std::string& group) { this->group = group; }
        void setAverageGrade(double averageGrade) { 
            validateAverageGrade(averageGrade);
            this->averageGrade = averageGrade; 
        }
    };
}
