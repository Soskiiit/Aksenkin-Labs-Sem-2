#include "planets.h"

#include <algorithm>
#include <cstring>
#include <iostream>

namespace planets {
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

    Planet::Planet(char* name, unsigned int radius, bool life, unsigned int number_of_satellites) {
        this->name = new char[std::strlen(name) + 1];
        std::strcpy(this->name, name);
        this->radius = radius;
        this->life = life;
        this->number_of_satellites = number_of_satellites;
        // id = ++total;
        // std::cout << "Планета " << id << " создана" << std::endl;
    }

    Planet::Planet() {
        const char* defaultName = "default";
        name = new char[std::strlen(defaultName) + 1];
        std::strcpy(name, defaultName);
        radius = 0;
        life = false;
        number_of_satellites = 0;
        // id = ++total;
        // std::cout << "Планета " << id << " создана" << std::endl;
    }

    Planet::Planet(const Planet &planet) {
        name = new char[std::strlen(planet.name) + 1];
        std::strcpy(name, planet.name);
        radius = planet.radius;
        life = planet.life;
        number_of_satellites = planet.number_of_satellites;
        // id = ++total;
        // std::cout << "Планета " << id << " создана" << std::endl;
    }

    Planet::~Planet() {
        delete[] name;
        // std::cout << "Планета " << id << " удалена" << std::endl;
    }

    Planet& Planet::operator=(const Planet& other) {
        if (this != &other) {
            delete[] name;
            name = new char[std::strlen(other.name) + 1];
            std::strcpy(name, other.name);
            radius = other.radius;
            life = other.life;
            number_of_satellites = other.number_of_satellites;
            // id = ++total;
            // std::cout << "Планета " << id << "создана" << std::endl;
        }
        return *this;
    }

    bool Planet::operator==(const Planet &other) {
        return std::strcmp(name, other.name) == 0 &&
               radius == other.radius &&
               life == other.life &&
               number_of_satellites == other.number_of_satellites;
    }

    std::strong_ordering Planet::operator<=>(const Planet &other) const {
        if (radius < other.radius) return std::strong_ordering::less;
        if (radius > other.radius) return std::strong_ordering::greater;
        return std::strong_ordering::equivalent;
    }

    std::ostream& operator<<(std::ostream& out, const Planet& planet) {
        out << "Планета: " << planet.name
            << "\tРадиус: " << planet.radius
            << "\tСпутников: " << planet.number_of_satellites;
        if (planet.life)
            out << "\tЖизнь есть";
        else
            out << "\tЖизни нет";
        return out;
    }

    std::istream& operator>>(std::istream& input_stream, Planet& planet) {
        if (!input_stream.good()) return input_stream;

        char* name = readUnlimitedWord(input_stream);
        int radius = static_cast<unsigned int>(std::stoul(readUnlimitedWord(input_stream)));
        int number_of_satellites = static_cast<unsigned int>(std::stoul(readUnlimitedWord(input_stream)));
        int life_value = std::stoi(readUnlimitedWord(input_stream));
        if (life_value != 0 && life_value != 1) {
            std::cout << "Жизнь определяется 0 или 1" << std::endl;
        } else {
            planet.name = name;
            planet.radius = radius;
            planet.life = static_cast<bool>(life_value);
            planet.number_of_satellites = number_of_satellites;
        }

        return input_stream;
    }

    std::ofstream& operator<<(std::ofstream& out, Planet& planet) {
        out << planet.name << ' ' << planet.radius << ' '
            << planet.number_of_satellites << ' ' << planet.life << '\n';
        return out;
    }

    PlanetsDB::PlanetsDB() : size(0), capacity(8), planets(new Planet[8]) {}

    PlanetsDB::~PlanetsDB() {
        delete[] planets;
    }

    size_t PlanetsDB::getSize() {
        return size;
    }

    void PlanetsDB::printPlanets() {
        if (size == 0) {
            std::cout << "База пуста\n";
        }
        for (size_t i = 0; i < size; ++i) {
            std::cout << i + 1 << ". " << planets[i] << std::endl;
        }
        std::cout << std::endl;
    }

    void PlanetsDB::addPlanet(Planet planet) {
        if (size == capacity) {
            capacity *= 2;
            Planet* new_planets = new Planet[capacity];
            std::copy(planets, planets + size, new_planets);
            delete[] planets;
            planets = new_planets;
        }
        planets[size++] = planet;
    }

    void PlanetsDB::deletePlanet(size_t id) {
        if (id >= size || id < 1) throw std::out_of_range("Неверный индекс");
        for (size_t i = id - 1; i < size - 1; ++i) {
            planets[i] = planets[i + 1];
        }
        --size;
    }

    void PlanetsDB::editPlanet(size_t id, Planet planet) {
        if (id > size || id < 1) throw std::out_of_range("Неверный индекс");
        planets[id - 1] = planet;
    }

    void PlanetsDB::sortPlanets() {
        if (size == 0)
            std::cout << "База пуста, сортировка невозможна" << std::endl;
        else
            std::sort(planets, planets + size);
    }

    void PlanetsDB::writePlanets(char* filename) {
        std::ofstream out(filename);
        for (size_t i = 0; i < size; ++i) {
            out << planets[i];
        }
        out.close();
    }

    void PlanetsDB::readPlanets(char* filename) {
        std::ifstream in(filename);
        while (in.good()) {
            Planet planet;
            try {
                in >> planet;
                addPlanet(planet);
            } catch (const std::logic_error&) {
                break;
            }
        }
        in.close();
    }
}
