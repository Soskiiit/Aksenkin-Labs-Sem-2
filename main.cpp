#include <iostream>

#include "polynom.h"
#include "term.h"


int main() {
    polynom::Polynom main_polynom;
    main_polynom += mathterm::Term(1, 2);
    main_polynom += mathterm::Term(3, 1);
    main_polynom += mathterm::Term(5, 0);
    main_polynom += mathterm::Term(-7, 1);
    std::cout << main_polynom << std::endl << std::endl;

    // 3x^2 - x^2 -    3x^2 + x ^2 + 5x^5   - 4x^3 +x^2 - 7
    polynom::Polynom test_input_polynom;
    std::cin >> test_input_polynom;
    std::cout << test_input_polynom << std::endl;

    return 0;
}
