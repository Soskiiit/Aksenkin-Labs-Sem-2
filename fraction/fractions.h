#pragma once

#include <iostream>


namespace frac {
    int gcd(int a, int b);
    char* readUnlimitedWord(std::istream& input);

    class Fraction {
    private:
        long numerator;
        long denominator;

    public:
        void ReduceAFraction();

        Fraction();
        Fraction(long numerator, long denominator);
        Fraction(long numerator);
        Fraction(int numerator);
        Fraction(const char* input_line);
        Fraction(double value);

        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& input, Fraction& fraction);

        Fraction operator+(const Fraction& other) const;
        friend Fraction operator+(double lhs, const Fraction& rhs);
        friend Fraction operator+(int lhs, const Fraction& rhs);
        Fraction operator-(const Fraction& other);
        Fraction operator*(const Fraction& other);
        Fraction operator/(const Fraction& other);

        Fraction operator+=(const Fraction& other);
        Fraction operator+=(long rhs);
        Fraction operator-=(const Fraction& other);
        Fraction operator*=(const Fraction& other);
        Fraction operator/=(const Fraction& other);
    };
}
