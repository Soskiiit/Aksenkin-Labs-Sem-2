#include "apartments.h"

#include <algorithm>
#include <iostream>
#include <cstring>

namespace apartments {
    char* readUnlimitedWord(std::istream& input) {
        while (input.good() && std::isspace(input.peek())) {
            input.get();
        }

        if (!input.good()) return nullptr;

        size_t bufferSize = 128;
        char* buffer = new char[bufferSize];
        size_t index = 0;

        while (input.good() && !std::isspace(input.peek())) {
            if (index >= bufferSize - 1) {
                size_t newSize = bufferSize * 2;
                char* newBuffer = new char[newSize];
                std::copy(buffer, buffer + bufferSize, newBuffer);
                delete[] buffer;
                buffer = newBuffer;
                bufferSize = newSize;
            }
            buffer[index++] = input.get();
        }

        buffer[index] = '\0';
        char* trimmedBuffer = new char[index + 1];
        std::strcpy(trimmedBuffer, buffer);
        delete[] buffer;

        return trimmedBuffer;
    }

    Apartment::Apartment(char* name, unsigned int radius, bool life, unsigned int number_of_satellites) {
        this->name = new char[std::strlen(name) + 1];
        std::strcpy(this->name, name);
        this->area = radius;
        this->reserved = life;
        this->price = number_of_satellites;
    }

    Apartment::Apartment() {
        const char* defaultName = "default";
        name = new char[std::strlen(defaultName) + 1];
        std::strcpy(name, defaultName);
        area = 0;
        reserved = false;
        price = 0;
    }

    Apartment::Apartment(const Apartment &planet) {
        name = new char[std::strlen(planet.name) + 1];
        std::strcpy(name, planet.name);
        area = planet.area;
        reserved = planet.reserved;
        price = planet.price;
    }

    Apartment::~Apartment() {
        delete[] name;
    }

    Apartment& Apartment::operator=(const Apartment& other) {
        if (this != &other) {
            delete[] name;
            name = new char[std::strlen(other.name) + 1];
            std::strcpy(name, other.name);
            area = other.area;
            reserved = other.reserved;
            price = other.price;
        }
        return *this;
    }

    bool Apartment::operator==(const Apartment &other) {
        return std::strcmp(name, other.name) == 0 &&
               area == other.area &&
               reserved == other.reserved &&
               price == other.price;
    }

    std::strong_ordering Apartment::operator<=>(const Apartment &other) const {
        if (area < other.area) return std::strong_ordering::less;
        if (area > other.area) return std::strong_ordering::greater;
        return std::strong_ordering::equivalent;
    }

    std::ostream& operator<<(std::ostream& out, const Apartment& planet) {
        out << "Квартира: " << planet.name
            << "\tПлощадь: " << planet.area
            << "\tЦена: " << planet.price;
        if (planet.reserved)
            out << "\tЗарезервирована";
        else
            out << "\tДоступна";
        return out;
    }

    std::istream& operator>>(std::istream& input_stream, Apartment& apartment) {
        if (!input_stream.good()) return input_stream;

        char* name = readUnlimitedWord(input_stream);
        unsigned int area = static_cast<unsigned int>(std::stoul(readUnlimitedWord(input_stream)));
        int price = static_cast<unsigned int>(std::stoul(readUnlimitedWord(input_stream)));
        int reserved_value = std::stoi(readUnlimitedWord(input_stream));
        if (reserved_value != 0 && reserved_value != 1)
            throw std::invalid_argument("Бронь определяется 0 или 1");

        apartment.name = name;
        apartment.area = area;
        apartment.price = price;
        apartment.reserved = static_cast<bool>(reserved_value);

        return input_stream;
    }

    std::ofstream& operator<<(std::ofstream &out, Apartment &apartment) {
        out << apartment.name << ' ' << apartment.area << ' '
            << apartment.price << ' ' << apartment.reserved << '\n';
        return out;
    }

    ApartmentsDB::ApartmentsDB() : size(0), capacity(8), apartments(new Apartment[8]) {}

    ApartmentsDB::~ApartmentsDB() {
        delete[] apartments;
    }

    size_t ApartmentsDB::getSize() {
        return size;
    }

    void ApartmentsDB::printApartments() {
        for (size_t i = 0; i < size; ++i) {
            std::cout << i + 1 << ". " << apartments[i] << std::endl;
        }
    }

    void ApartmentsDB::addApartment(Apartment apartment) {
        if (size == capacity) {
            capacity *= 2;
            Apartment* new_planets = new Apartment[capacity];
            std::copy(apartments, apartments + size, new_planets);
            delete[] apartments;
            apartments = new_planets;
        }
        apartments[size++] = apartment;
    }

    void ApartmentsDB::deleteApartment(size_t id) {
        if (id > size || id < 1) throw std::out_of_range("Неверный индекс");
        for (size_t i = id - 1; i < size - 1; ++i) {
            apartments[i] = apartments[i + 1];
        }
        --size;
    }

    void ApartmentsDB::editApartment(size_t id, Apartment apartment) {
        if (id > size || id < 1) throw std::out_of_range("Неверный индекс");
        apartments[id - 1] = apartment;
    }

    void ApartmentsDB::sortApartments() {
        if (size == 0)
            std::cout << "База пуста, сортировка невозможна" << std::endl;
        else
            std::sort(apartments, apartments + size);
    }

    void ApartmentsDB::writeApartments(char* filename) {
        std::ofstream out(filename);
        for (size_t i = 0; i < size; ++i) {
            out << apartments[i];
        }
        out.close();
    }

    void ApartmentsDB::readApartments(char* filename) {
        std::ifstream in(filename);
        while (in.good()) {
            Apartment apartment;
            try {
                in >> apartment;
                addApartment(apartment);
            } catch (const std::logic_error&) {
                break;
            }
        }
    }
}
