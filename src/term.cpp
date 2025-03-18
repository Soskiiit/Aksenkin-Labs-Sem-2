#include "term.h"

#include <cstring>
#include <iostream>


namespace mathterm {
    Term::Term() {
        this->coefficient = 0;
        this->exponent = 0;
    }

    Term::Term(double coefficient) {
        this->coefficient = coefficient;
        this->exponent = 0;
    }

    Term::Term(double coefficient, double exponent) {
        this->coefficient = coefficient;
        this->exponent = exponent;
    }

    Term::Term(const Term &other) {
        this->coefficient = other.coefficient;
        this->exponent = other.exponent;
    }

    std::ostream& operator<<(std::ostream &out, const Term &term) {
        if (term.exponent == 0) {
            out << term.coefficient;
        } else if (term.exponent == 1) {
            if (term.coefficient == 1) out << "x";
            else out << term.coefficient << "x";
        } else {
            if (term.coefficient == 1) out << "x^" << term.exponent;
            else out << term.coefficient << "x^" << term.exponent;
        }
        return out;
    }

    void operator>>(char* input_line, Term& term) {
        char* buffer = new char[strlen(input_line)];
        size_t buffer_size = 0;
        size_t index = 0;
        while (input_line[index] != 'x' && input_line[index] != '\0') {
            buffer[buffer_size++] = input_line[index++];
        }
        buffer[buffer_size] = '\0';

        if (input_line[index] == '\0') {
            term.coefficient = atof(buffer);
            term.exponent = 0;
            return;
        }

        if (input_line[index + 1] != '^') {
            term.coefficient = atof(buffer);
            term.exponent = 1;
            return;
        }

        index += 2;

        if (buffer_size == 0)
            term.coefficient = 1;
        else if (buffer_size == 1 && buffer[0] == '-')
            term.coefficient = -1;
        else
            term.coefficient = atof(buffer);


        buffer_size = 0;
        while (input_line[index] != '\0') {
            buffer[buffer_size++] = input_line[index++];
        }
        buffer[buffer_size] = '\0';
        term.exponent = atof(buffer);

        delete[] buffer;
    }

    Term operator+(const Term& a, const Term& b) {
        if (a.exponent != b.exponent) {
            throw std::invalid_argument("Term does not have the same exponent");
        }
        return Term(a.coefficient + b.coefficient, a.exponent);
    }
}
