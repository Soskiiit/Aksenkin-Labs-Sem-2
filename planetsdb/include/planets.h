#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <compare>
#include <stdexcept>

namespace planets {
    char* readUnlimitedWord(std::istream& input);

    class Planet {
    public:
        char* name;
        unsigned int radius;
        bool life;
        unsigned int number_of_satellites;

        Planet(char* name, unsigned int radius, bool life, unsigned int number_of_satellites);
        Planet();
        Planet(const Planet &planet);
        ~Planet();

        Planet& operator=(const Planet& other);
        bool operator==(const Planet &other);
        std::strong_ordering operator<=>(const Planet &other) const;
    };

    std::ostream& operator<<(std::ostream& out, const Planet& planet);
    std::istream& operator>>(std::istream& input_stream, Planet& planet);
    std::ofstream& operator<<(std::ofstream &out, Planet &planet);

    class PlanetsDB {
    private:
        size_t size;
        size_t capacity;
        Planet* planets;

    public:
        PlanetsDB();
        ~PlanetsDB();

        size_t getSize();
        void printPlanets();
        void addPlanet(Planet planet);
        void deletePlanet(size_t id);
        void editPlanet(size_t id, Planet planet);
        void sortPlanets();
        void writePlanets(char* filename = "planets.txt");
        void readPlanets(char* filename = "planets.txt");
    };
}
