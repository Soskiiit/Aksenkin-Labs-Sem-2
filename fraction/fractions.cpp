#include "fractions.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <numeric>


namespace frac {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

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

    void Fraction::ReduceAFraction() {
        int divider = std::gcd(std::abs(numerator), std::abs(denominator));
        numerator /= divider;
        denominator /= divider;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    Fraction::Fraction() : numerator(0), denominator(1) {}

    Fraction::Fraction(long numerator, long denominator) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) throw std::invalid_argument("denominator cannot be zero");
        ReduceAFraction();
    }

    Fraction::Fraction(long numerator) : numerator(numerator), denominator(1) {}
    Fraction::Fraction(int numerator) : numerator(numerator), denominator(1) {}

    Fraction::Fraction(const char* input_line) {
        char* line_copy = new char[strlen(input_line) + 1];
        strcpy(line_copy, input_line);
        char* part1 = line_copy;
        char* part2 = nullptr;
        char* pos = strchr(line_copy, ' ');

        if (pos) {
            *pos = '\0';
            part2 = pos + 1;
        }

        if (!part2) {
            pos = strchr(part1, '/');
            if (!pos) {
                numerator = atoi(part1);
                denominator = 1;
            } else {
                *pos = '\0';
                numerator = atoi(part1);
                denominator = atoi(pos + 1);
            }
        } else {
            pos = strchr(part2, '/');
            if (!pos) {
                numerator = atoi(part2);
                denominator = 1;
            } else {
                *pos = '\0';
                numerator = atoi(part2) + atoi(part1);
                denominator = atoi(pos + 1);
            }
        }
        delete[] line_copy;
        ReduceAFraction();
    }

    Fraction::Fraction(double value) {
        if (std::isnan(value) || std::isinf(value))
            throw std::invalid_argument("Invalid double value");

        if (value == 0.0) {
            numerator = 0;
            denominator = 1;
            return;
        }

        value *= 1024 * 1024;
        numerator = value;
        denominator = 1024 * 1024;
        ReduceAFraction();
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        int integer_part = std::abs(fraction.numerator) / fraction.denominator;
        int remainder = std::abs(fraction.numerator) % fraction.denominator;

        if (fraction.numerator < 0) os << "-";
        if (integer_part != 0) os << integer_part;
        if (remainder != 0) {
            if (integer_part != 0) os << " ";
            os << remainder << "/" << fraction.denominator;
        }
        if (integer_part == 0 && remainder == 0) os << "0";
        return os;
    }

    std::istream& operator>>(std::istream& input, Fraction& fraction) {
        char line[100];
        input.getline(line, 100);
        Fraction temp(line);
        fraction = temp;
        return input;
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction operator+(double lhs, const Fraction& rhs) { return Fraction(lhs) + rhs; }
    Fraction operator+(int lhs, const Fraction& rhs) { return Fraction(lhs) + rhs; }

    Fraction Fraction::operator-(const Fraction& other) {
        return Fraction(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction Fraction::operator*(const Fraction& other) {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction Fraction::operator/(const Fraction& other) {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction Fraction::operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        ReduceAFraction();
        return *this;
    }

    Fraction Fraction::operator+=(long rhs) { return *this += Fraction(rhs); }

    Fraction Fraction::operator-=(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        ReduceAFraction();
        return *this;
    }

    Fraction Fraction::operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        ReduceAFraction();
        return *this;
    }

    Fraction Fraction::operator/=(const Fraction& other) {
        numerator *= other.denominator;
        denominator *= other.numerator;
        ReduceAFraction();
        return *this;
    }
}
