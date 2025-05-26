#pragma once

#include "person.h"

namespace lab7 {
    class Teacher : public Person {
    protected:
        std::string department;
        std::string academicTitle;
        int yearsOfExperience;
        
        void validateYearsOfExperience(int years) const {
            if (years < 0) {
                throw std::invalid_argument("Стаж работы не может быть отрицательным");
            }
            if (years > 70) {
                throw std::invalid_argument("Стаж работы не может превышать 70 лет");
            }
        }

    public:
        Teacher();
        Teacher(const std::string& name, int age, const std::string& address,
                const std::string& department, const std::string& academicTitle, int yearsOfExperience);
        virtual ~Teacher();
        
        Teacher(const Teacher& other);
        Teacher& operator=(const Teacher& other);

        void show() const override;
        
        const std::string& getDepartment() const { return department; }
        const std::string& getAcademicTitle() const { return academicTitle; }
        int getYearsOfExperience() const { return yearsOfExperience; }
        
        void setDepartment(const std::string& department) { this->department = department; }
        void setAcademicTitle(const std::string& academicTitle) { this->academicTitle = academicTitle; }
        void setYearsOfExperience(int yearsOfExperience) { 
            validateYearsOfExperience(yearsOfExperience);
            this->yearsOfExperience = yearsOfExperience; 
        }
    };
}
