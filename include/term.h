#pragma once
#include <ostream>


namespace mathterm {
    class Term {
    public:
        double coefficient = 0;
        double exponent = 0;

        Term();
        Term(double coefficient);
        Term(double coefficient, double exponent);
        Term(const Term& other);

        friend std::ostream& operator<<(std::ostream& out, const Term& a);
        friend void operator>>(char* input_line, Term& term);
        friend Term operator+(const Term& a, const Term& b);
    };
}
