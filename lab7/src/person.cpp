#include "person.h"

#include <iostream>

namespace lab7 {
    Person::Person() : name(""), age(0), address("") {
        std::cout << "Person()" << std::endl;
    }

    Person::Person(const std::string& name, int age, const std::string& address)
        : name(name), address(address) {
        validateAge(age);
        this->age = age;
        std::cout << "Person()" << std::endl;
    }

    Person::~Person() {
        std::cout << "~Person()" << std::endl;
    }

    Person::Person(const Person& other) 
        : name(other.name), age(other.age), address(other.address) {
        std::cout << "Person(const Person&)" << std::endl;
    }

    Person& Person::operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            validateAge(other.age);
            age = other.age;
            address = other.address;
        }
        std::cout << "Person::operator=(const Person&)" << std::endl;
        return *this;
    }
}
