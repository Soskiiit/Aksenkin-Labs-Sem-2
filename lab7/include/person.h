#pragma once

#include <string>
#include <stdexcept>

namespace lab7 {
    class Person {
    protected:
        std::string name;
        int age;
        std::string address;
        
        void validateAge(int age) const {
            if (age < 0) {
                throw std::invalid_argument("Возраст не может быть отрицательным");
            }
            if (age > 150) {
                throw std::invalid_argument("Возраст не может быть больше 150 лет");
            }
        }

    public:
        Person();
        Person(const std::string& name, int age, const std::string& address);
        virtual ~Person();
        
        Person(const Person& other);
        Person& operator=(const Person& other);

        virtual void show() const = 0;
        
        const std::string& getName() const { return name; }
        int getAge() const { return age; }
        const std::string& getAddress() const { return address; }
        
        void setName(const std::string& name) { this->name = name; }
        void setAge(int age) { 
            validateAge(age);
            this->age = age; 
        }
        void setAddress(const std::string& address) { this->address = address; }
    };
}
