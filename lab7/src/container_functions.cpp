#include "container_functions.h"
#include <iostream>
#include <limits>

namespace lab7 {
    void print(const PersonContainer& container) {
        std::cout << "\n=== Содержимое контейнера ===" << std::endl;
        for (size_t i = 0; i < container.getSize(); ++i) {
            std::cout << "Индекс " << i << ": ";
            if (container[i] != nullptr) {
                container[i]->show();
            } else {
                std::cout << "nullptr" << std::endl;
            }
        }
        std::cout << "Всего элементов: " << container.getSize() << std::endl;
        std::cout << "=========================" << std::endl;
    }

    void remove(PersonContainer& container, size_t index) {
        if (index >= container.getSize()) {
            std::cout << "Ошибка: индекс " << index << " выходит за границы контейнера (размер: " << container.getSize() << ")" << std::endl;
            return;
        }
        
        if (container[index] != nullptr) {
            delete container[index];
            std::cout << "Объект по индексу " << index << " удален из памяти" << std::endl;
        }
        
        container.delete_element(index);
        std::cout << "Элемент по индексу " << index << " удален из контейнера" << std::endl;
    }

    void clear(PersonContainer& container) {
        std::cout << "\n=== Очистка контейнера ===" << std::endl;
        for (size_t i = 0; i < container.getSize(); ++i) {
            if (container[i] != nullptr) {
                delete container[i];
            }
        }
        while (container.getSize() > 0) {
            container.delete_element(0);
        }
        std::cout << "Контейнер очищен" << std::endl;
    }

    void demonstrationMode() {
        std::cout << "\n=== ДЕМОНСТРАЦИОННЫЙ РЕЖИМ ===" << std::endl;
        
        PersonContainer container;
        
        std::cout << "\n--- Создание объектов ---" << std::endl;
        
        Person* student1 = new Student("Иванов Иван Иванович", 20, "ул. Студенческая, 1", 
                                      "STU001", "ИУ5-61Б", 4.5);
        container.push_back(student1);
        
        Person* student2 = new Student("Петрова Анна Сергеевна", 19, "ул. Молодежная, 15", 
                                      "STU002", "ИУ5-62Б", 4.8);
        container.push_back(student2);
        
        Person* teacher1 = new Teacher("Сидоров Петр Алексеевич", 45, "ул. Преподавательская, 10",
                                      "ИУ5", "Доцент", 15);
        container.push_back(teacher1);
        
        Person* head1 = new HeadOfDepartment("Козлов Александр Михайлович", 55, "ул. Административная, 5",
                                            "ИУ5", "Профессор", 25, 12, "20 лет", 150000.0);
        container.push_back(head1);
        
        std::cout << "\n--- Демонстрация функции print ---" << std::endl;
        print(container);
        
        std::cout << "\n--- Демонстрация функции remove ---" << std::endl;
        std::cout << "Удаляем элемент с индексом 1:" << std::endl;
        remove(container, 1);
        print(container);
        
        std::cout << "\n--- Демонстрация функции clear ---" << std::endl;
        clear(container);
        print(container);
        
        std::cout << "\n=== КОНЕЦ ДЕМОНСТРАЦИОННОГО РЕЖИМА ===" << std::endl;
    }

    void showMenu() {
        std::cout << "\n=== МЕНЮ ===" << std::endl;
        std::cout << "1. Добавить персону" << std::endl;
        std::cout << "2. Показать содержимое контейнера" << std::endl;
        std::cout << "3. Удалить элемент по индексу" << std::endl;
        std::cout << "4. Очистить контейнер" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите пункт меню: ";
    }

    Person* createPersonFromInput() {
        int type;
        std::cout << "\nВыберите тип персоны:" << std::endl;
        std::cout << "1. Студент" << std::endl;
        std::cout << "2. Преподаватель" << std::endl;
        std::cout << "3. Заведующий кафедрой" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> type;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::string name, address;
        int age;
        
        std::cout << "Введите имя: ";
        std::getline(std::cin, name);
        std::cout << "Введите возраст: ";
        std::cin >> age;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите адрес: ";
        std::getline(std::cin, address);
        
        switch (type) {
            case 1: {
                std::string studentId, group;
                double averageGrade;
                
                std::cout << "Введите ID студента: ";
                std::getline(std::cin, studentId);
                std::cout << "Введите группу: ";
                std::getline(std::cin, group);
                std::cout << "Введите средний балл: ";
                std::cin >> averageGrade;
                
                return new Student(name, age, address, studentId, group, averageGrade);
            }
            case 2: {
                std::string department, academicTitle;
                int yearsOfExperience;
                
                std::cout << "Введите кафедру: ";
                std::getline(std::cin, department);
                std::cout << "Введите ученое звание: ";
                std::getline(std::cin, academicTitle);
                std::cout << "Введите стаж (лет): ";
                std::cin >> yearsOfExperience;
                
                return new Teacher(name, age, address, department, academicTitle, yearsOfExperience);
            }
            case 3: {
                std::string department, academicTitle, managementExperience;
                int yearsOfExperience, numberOfSubordinates;
                double administrativeSalary;
                
                std::cout << "Введите кафедру: ";
                std::getline(std::cin, department);
                std::cout << "Введите ученое звание: ";
                std::getline(std::cin, academicTitle);
                std::cout << "Введите стаж (лет): ";
                std::cin >> yearsOfExperience;
                std::cout << "Введите количество подчиненных: ";
                std::cin >> numberOfSubordinates;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введите управленческий опыт: ";
                std::getline(std::cin, managementExperience);
                std::cout << "Введите административную зарплату: ";
                std::cin >> administrativeSalary;
                
                return new HeadOfDepartment(name, age, address, department, academicTitle, 
                                          yearsOfExperience, numberOfSubordinates, 
                                          managementExperience, administrativeSalary);
            }
            default:
                std::cout << "Неверный выбор!" << std::endl;
                return nullptr;
        }
    }

    void interactiveMode() {
        std::cout << "\n=== ИНТЕРАКТИВНЫЙ РЕЖИМ ===" << std::endl;
        
        PersonContainer container;
        int choice;
        
        do {
            showMenu();
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            switch (choice) {
                case 1: {
                    Person* person = createPersonFromInput();
                    if (person != nullptr) {
                        container.push_back(person);
                        std::cout << "Персона добавлена в контейнер!" << std::endl;
                    }
                    break;
                }
                case 2:
                    print(container);
                    break;
                case 3: {
                    if (container.getSize() == 0) {
                        std::cout << "Контейнер пуст!" << std::endl;
                        break;
                    }
                    size_t index;
                    std::cout << "Введите индекс для удаления (0-" << (container.getSize() - 1) << "): ";
                    std::cin >> index;
                    remove(container, index);
                    break;
                }
                case 4:
                    clear(container);
                    break;
                case 0:
                    std::cout << "Очищаем контейнер перед выходом..." << std::endl;
                    clear(container);
                    std::cout << "Выход из программы." << std::endl;
                    break;
                default:
                    std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            }
        } while (choice != 0);
        
        std::cout << "\n=== КОНЕЦ ИНТЕРАКТИВНОГО РЕЖИМА ===" << std::endl;
    }
}
