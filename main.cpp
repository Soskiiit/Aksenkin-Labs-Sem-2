#include <cstring>
#include <iomanip>
#include <iostream>

#include "apartmentsdb/include/apartments.h"
#include "planetsdb/include/planets.h"


namespace {
    int planetsDemo() {
        planets::PlanetsDB db;


        std::cout << "Выводим БД" << std::endl;
        db.printPlanets();

        std::cout << "Добавим пару планет" << std::endl;
        db.addPlanet(planets::Planet(new char[]{"Юпитер"}, 123456, false, 16));
        db.addPlanet(planets::Planet(new char[]{"Меркурий"}, 4878, false, 0));

        std::cout << "Выводим БД" << std::endl;
        db.printPlanets();

        std::cout << "Увеличим Юпитер и отсортируем БД" << std::endl;
        db.editPlanet(1, planets::Planet(new char[]{"Юпитер"}, 150000, false, 16));
        db.sortPlanets();

        std::cout << "Выводим БД" << std::endl;
        db.printPlanets();

        std::cout << "Читаем из файла" << std::endl;
        db.readPlanets("planets.txt");
        db.printPlanets();

        std::cout << "И записываем обратно" << std::endl;
        db.writePlanets("planets.txt");

        return 0;
    }

    void printMenu() {
        std::cout << "1. Добавить элемент          \t5. Запись в файл" << std::endl;
        std::cout << "2. Удалить элемент           \t6. Чтение из файла" << std::endl;
        std::cout << "3. Изменить элемент          \t7. Сортировка списка" << std::endl;
        std::cout << "4. Вывести базу на экран     \t8. Выход" << std::endl;
    }

    int interactiveApartaments() {
        apartments::ApartmentsDB db;
        apartments::Apartment apartment;
        int choice;
        size_t id;
        while (true) {
            printMenu();
            std::cout << "Выберите действие: ";
            std::cin >> choice;
            switch (choice) {
                case 1:
                    std::cout << "Введите название, площадь, цену и доступна/забронирована(0/1)" << std::endl;
                    try {
                        std::cin >> apartment;
                        db.addApartment(apartment);
                    } catch (const std::exception &e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Введите id: ";
                    std::cin >> id;
                    try {
                        db.deleteApartment(id);
                    } catch (const std::out_of_range e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Введите id: ";
                    std::cin >> id;
                    std::cout << "Введите название, площадь, цену и доступна/забронирована(0/1)" << std::endl;
                    std::cin >> apartment;
                    try {
                        db.editApartment(id, apartment);
                    } catch (const std::exception e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                case 4:
                    std::cout << std::endl;
                    db.printApartments();
                    std::cout << std::endl;
                    break;
                case 5:
                    db.writeApartments();
                    std::cout << "База записана в файл apartments.txt" << std::endl;
                    break;
                case 6:
                    db.readApartments();
                    std::cout << "База прочтена из файла apartments.txt" << std::endl;
                    break;
                case 7:
                    db.sortApartments();
                    std::cout << "Значения отсортированы" << std::endl;
                    break;
                case 8:
                    return 0;
                default:
                    std::cin.ignore();
                    std::cout << "Такого действия нет" << std::endl;
                    break;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    bool isInteractive = false;
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive)
        return interactiveApartaments();
    return planetsDemo();
}
