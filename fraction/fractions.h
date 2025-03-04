#pragma once

#include <climits>
#include <cmath>
#include <cstring>


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

            Fraction(const char* input_line) {
                char* line_copy = new char[strlen(input_line) + 1];
                strcpy(line_copy, input_line);
                char* part1 = line_copy;
                char* part2;
                char* pos = strchr(line_copy, ' ');

                if (pos != nullptr) {
                    *pos = '\0';
                    part2 = pos + 1;
                } else {
                    part2 = nullptr;
                }

                if (part2 == nullptr) {
                    char* pos = strchr(part1, '/');
                    if (pos == nullptr) {
                        numerator = atoi(part1);
                        denominator = 1;
                    } else {
                        *pos = '\0';
                        numerator = atoi(part1);
                        denominator = atoi(pos + 1);
                    }
                } else {
                    char* pos = strchr(part2, '/');
                    if (pos == nullptr) {
                        numerator = atoi(part2);
                        denominator = 1;
                    } else {
                        *pos = '\0';
                        numerator = atoi(part2) + atoi(part1);
                        denominator = atoi(pos + 1);
                    }
                }
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
            };

            friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
                int integer_part = std::abs(fraction.numerator) / std::abs(fraction.denominator);
                int fractional_part = std::abs(fraction.numerator) % std::abs(fraction.denominator);
                if (fraction.numerator < 0) os << '-';
                if (integer_part > 0) {
                    os << integer_part;
                }
                if (fractional_part > 0) {
                    if (integer_part > 0) {
                        os << ' ';
                    }
                     os << fractional_part << '/' << fraction.denominator;
                }
                if (fraction.numerator == 0)
                    os << 0;
                return os;
            }

            friend std::istream &operator>>(std::istream &input, Fraction &fraction) {
                char* line = new char[99];
                input.getline(line, 99);
                Fraction fraction_temp(line);
                fraction = fraction_temp;
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
