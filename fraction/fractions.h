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
            void ReduceAFraction() {
                int divider = gcd(std::abs(this->numerator), std::abs(this->denominator));
                this->numerator /= divider;
                this->denominator /= divider;
                if (this->denominator < 0) {
                    this->numerator = -this->numerator;
                    this->denominator = -this->denominator;
                }
            }

            Fraction() {
                this->numerator = 0;
                this->denominator = 1;
            }

            Fraction(long numerator, long denominator) {
                this->numerator = numerator;
                this->denominator = denominator;
                if (denominator == 0) {
                    throw std::invalid_argument("denominator cannot be zero");
                }
                ReduceAFraction();
            }

            Fraction(long numerator) {
                this->numerator = numerator;
                this->denominator = 1;
            }

            Fraction(int numerator) {
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

                this->numerator = numerator;
                this->denominator = denominator;
                ReduceAFraction();
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

                value *= 1'024 * 1'024;
                numerator = value;
                denominator = 1'024 * 1'024;

                ReduceAFraction();
            }

            ;

            friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
                os << fraction.numerator << "/" << fraction.denominator;
                return os;
            }

            friend std::istream &operator>>(std::istream &input, Fraction &fraction) {
                input >> fraction.numerator >> fraction.denominator;
                return input;
            }

            Fraction operator+(const Fraction &other) const {
                long new_numerator = numerator * other.denominator + other.numerator * denominator;
                long new_denominator = this->denominator * other.denominator;
                Fraction result(new_numerator, new_denominator);
                return result;
            }

            friend Fraction operator+(double lhs, const Fraction &rhs) {
                return Fraction(lhs) + rhs;
            }

            friend Fraction operator+(int lhs, const Fraction &rhs) {
                return Fraction(lhs) + rhs;
            }

            Fraction operator-(const Fraction &other) {
                long new_numerator = numerator * other.denominator - other.numerator * denominator;
                long new_denominator = this->denominator * other.denominator;
                Fraction result(new_numerator, new_denominator);
                return result;
            }

            Fraction operator*(const Fraction &other) {
                long new_numerator = numerator * other.denominator;
                long new_denominator = this->denominator * other.numerator;
                Fraction result(new_numerator, new_denominator);
                return result;
            }

            Fraction operator/(const Fraction &other) {
                long new_numerator = numerator * other.denominator;
                long new_denominator = this->denominator * other.numerator;
                Fraction result(new_numerator, new_denominator);
                return result;
            }

            Fraction operator+=(const Fraction &other) {
                numerator = numerator * other.denominator + other.numerator * denominator;
                denominator = denominator * other.denominator;
                ReduceAFraction();
                return *this;
            }

            Fraction operator+=(const long rhs) {
                return operator+=(Fraction(rhs));
            }

            Fraction operator-=(const Fraction &other) {
                numerator = numerator * other.denominator + other.numerator * denominator;
                denominator = denominator * other.denominator;
                ReduceAFraction();
                return *this;
            }

            Fraction operator*=(const Fraction &other) {
                numerator = numerator * other.numerator;
                denominator = denominator * other.denominator;
                ReduceAFraction();
                return *this;
            }

            Fraction operator/=(const Fraction &other) {
                numerator = numerator * other.denominator;
                denominator = denominator * other.numerator;
                ReduceAFraction();
                return *this;
            }
    };
}
