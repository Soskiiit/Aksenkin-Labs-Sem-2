#pragma once

#include "teacher.h"

namespace lab7 {
    class HeadOfDepartment : public Teacher {
    protected:
        int numberOfSubordinates;
        std::string managementExperience;
        double administrativeSalary;
        
        void validateNumberOfSubordinates(int number) const {
            if (number < 0) {
                throw std::invalid_argument("Количество подчиненных не может быть отрицательным");
            }
            if (number > 1000) {
                throw std::invalid_argument("Количество подчиненных не может превышать 1000");
            }
        }
        
        void validateAdministrativeSalary(double salary) const {
            if (salary < 0.0) {
                throw std::invalid_argument("Административная зарплата не может быть отрицательной");
            }
        }

    public:
        HeadOfDepartment();
        HeadOfDepartment(const std::string& name, int age, const std::string& address,
                        const std::string& department, const std::string& academicTitle, int yearsOfExperience,
                        int numberOfSubordinates, const std::string& managementExperience, double administrativeSalary);
        virtual ~HeadOfDepartment();
        
        HeadOfDepartment(const HeadOfDepartment& other);
        HeadOfDepartment& operator=(const HeadOfDepartment& other);

        void show() const override;
        
        int getNumberOfSubordinates() const { return numberOfSubordinates; }
        const std::string& getManagementExperience() const { return managementExperience; }
        double getAdministrativeSalary() const { return administrativeSalary; }
        
        void setNumberOfSubordinates(int numberOfSubordinates) { 
            validateNumberOfSubordinates(numberOfSubordinates);
            this->numberOfSubordinates = numberOfSubordinates; 
        }
        void setManagementExperience(const std::string& managementExperience) { this->managementExperience = managementExperience; }
        void setAdministrativeSalary(double administrativeSalary) { 
            validateAdministrativeSalary(administrativeSalary);
            this->administrativeSalary = administrativeSalary; 
        }
    };
}
