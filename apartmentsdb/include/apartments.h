#pragma once

#include <fstream>
#include <compare>

namespace apartments {
    char* readUnlimitedWord(std::istream& input);

    class Apartment {
    public:
        char* name;
        unsigned int area;
        bool reserved;
        unsigned int price;

        Apartment(char* name, unsigned int area, bool reserved, unsigned int price);
        Apartment();
        Apartment(const Apartment &planet);
        ~Apartment();

        Apartment& operator=(const Apartment& other);
        bool operator==(const Apartment &other);
        std::strong_ordering operator<=>(const Apartment &other) const;
    };

    std::ostream& operator<<(std::ostream& out, const Apartment& planet);
    std::istream& operator>>(std::istream& input_stream, Apartment& apartment);
    std::ofstream& operator<<(std::ofstream &out, Apartment &apartment);

    class ApartmentsDB {
    private:
        size_t size;
        size_t capacity;
        Apartment* apartments;

    public:
        ApartmentsDB();
        ~ApartmentsDB();

        size_t getSize();
        void printApartments();
        void addApartment(Apartment apartment);
        void deleteApartment(size_t id);
        void editApartment(size_t id, Apartment apartment);
        void sortApartments();
        void writeApartments(char* filename = "apartments.txt");
        void readApartments(char* filename = "apartments.txt");
    };
}
