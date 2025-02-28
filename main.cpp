#include <iostream>

#include "fractions.h"

int main() {
    frac::Fraction fr1(2, 5);
    frac::Fraction fr2(3, 4);
    std::cout << fr1 + fr2 << " " << std::endl;
    frac::Fraction fr3(2.25f);
    std::cout << fr3 + fr3 << " " << std::endl;
    return 0;
}
