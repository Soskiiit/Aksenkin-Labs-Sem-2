#pragma once
#include <climits>
#include <cmath>
#include <cstring>

namespace frac {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    class Fraction {
        private:
            long numerator;
            long denominator;
        public:
            Fraction(long numerator, long denominator) {
                this->numerator = numerator;
                this->denominator = denominator;
                if (denominator == 0) {
                    throw std::invalid_argument("denominator cannot be zero");
                }
                int divider = gcd(std::abs(numerator), std::abs(denominator));
                this->numerator /= divider;
                this->denominator /= divider;
            }

            Fraction(long numerator) {
                this->numerator = numerator;
                this->denominator = 1;
            }

            Fraction(const char* line) {
                int slash_position = strchr(line, '/') - line;
                if (slash_position < 1) {
                    throw std::invalid_argument("Fraction string contains invalid characters");
                }
                char* numerator_string = new char[slash_position + 1];
                char* denominator_string = new char[slash_position + 1];
                strncpy(numerator_string, line, slash_position);
                numerator_string[slash_position] = '\0';
                strncpy(denominator_string, line + 1 + slash_position, slash_position);
                denominator_string[slash_position] = '\0';
                int numerator = atoi(numerator_string);
                int denominator = atoi(denominator_string);

                if (denominator == 0) {
                    throw std::invalid_argument("denominator cannot be zero");
                }

                int divider = gcd(std::abs(numerator), std::abs(denominator));
                numerator /= divider;
                denominator /= divider;
                this->numerator = numerator;
                this->denominator = denominator;
            }

            Fraction(double value) {
                if (std::isnan(value)) {
                    throw std::invalid_argument("Cannot convert NaN to Fraction");
                }
                if (std::isinf(value)) {
                    throw std::invalid_argument("Cannot convert infinity to Fraction");
                }

                if (value == 0.0f) {
                    numerator = 0;
                    denominator = 1;
                    return;
                }

                value *= 1'000'000;
                numerator = value;
                denominator = 1'000'000;

                int divider = gcd(std::abs(numerator), std::abs(denominator));
                numerator /= divider;
                denominator /= divider;
            }

            Fraction operator+(const Fraction &other) const {
                long new_numerator = numerator * other.denominator + other.numerator * denominator;
                long new_denominator = this->denominator * other.denominator;
                Fraction result(new_numerator, new_denominator);
                return result;
            }

            friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
                os << fraction.numerator << "/" << fraction.denominator;
                return os;
            }
    };
}
