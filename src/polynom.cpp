#include "polynom.h"

#include <algorithm>
#include <cstring>
#include <functional>

#include "term.h"


namespace polynom {
    Polynom::Polynom() {
        this->size = 0;
        this->capacity = 8;
        this->sort_order = SortOrder::descending;
        this->terms = new mathterm::Term[this->capacity];
    }

    Polynom::Polynom(const Polynom &polynom) {
        this->size = polynom.size;
        this->capacity = polynom.capacity;
        this->sort_order = polynom.sort_order;
        this->terms = new mathterm::Term[this->capacity];
        std::copy_n(polynom.terms, this->capacity, this->terms);
    }

    Polynom::~Polynom() {
        delete[] this->terms;
    }

    void Polynom::AddTerm(mathterm::Term term) {
        if (this->size == this->capacity) {
            this->capacity *= 2;
            mathterm::Term* new_terms = new mathterm::Term[this->capacity];
            std::copy_n(this->terms, this->capacity, new_terms);
            delete[] this->terms;
            this->terms = new_terms;
        }
        this->terms[this->size++] = term;
    }

    void Polynom::DeleteTerm(size_t index) {
        if (index >= this->size) {
            throw std::out_of_range("Index is out of range");
        }
        size--;
        for (size_t i = index; i < this->size; i++) {
            this->terms[i] = this->terms[i + 1];
        }
    }

    void Polynom::OptimizePolynom() {

        switch (this->sort_order) {
            case SortOrder::ascending:
                std::sort(
                    this->terms,
                    this->terms + this->size,
                    [](const mathterm::Term &a, const mathterm::Term &b) {
                        return a.exponent < b.exponent;
                    }
                );
                break;
            case SortOrder::descending:
                std::sort(
                    this->terms,
                    this->terms + this->size,
                    [](const mathterm::Term &a, const mathterm::Term &b) {
                        return a.exponent > b.exponent;
                    }
                );
                break;
        }
        
        for (int i = this->size - 2; i >= 0; i--) {
            if (this->terms[i].exponent == this->terms[i + 1].exponent) {
                this->terms[i] = this->terms[i + 1] + this->terms[i];
                DeleteTerm(i + 1);
            }
        }
    }

    Polynom Polynom::operator=(const Polynom &polynom) {
        delete[] this->terms;
        this->size = polynom.size;
        this->capacity = polynom.capacity;
        this->sort_order = polynom.sort_order;
        this->terms = new mathterm::Term[this->capacity];
        std::copy_n(polynom.terms, this->size, this->terms);
        return *this;
    }

    Polynom& Polynom::operator+=(const mathterm::Term &term) {
        AddTerm(term);
        OptimizePolynom();
        return *this;
    }

    Polynom& Polynom::operator+=(const Polynom &polynom) {
        for (size_t i = 0; i < polynom.size; i++) {
            this->AddTerm(polynom.terms[i]);
        }
        OptimizePolynom();
        return *this;
    }

    Polynom & Polynom::operator+=(double num) {
        this->AddTerm(mathterm::Term(num));
        OptimizePolynom();
        return *this;
    }

    Polynom Polynom::operator+(double num) {
        Polynom result(*this);
        result += num;
        return result;
    }

    Polynom Polynom::operator+(const mathterm::Term &term) {
        Polynom result(*this);
        result += term;
        return result;

    }

    Polynom Polynom::operator+(const Polynom &polynom) {
        Polynom result(*this);
        result += polynom;
        return result;
    }

    std::ostream& operator<<(std::ostream &out, const Polynom &polynom) {
        bool is_first = true;
        if (polynom.size == 0) {
            std::cout << 0;
            return out;
        }
        if (polynom.size == 1) {
            out << polynom.terms[0];
            return out;
        }

        for (int i = 0; i < polynom.size; i++) {
            if (!is_first) {
                if (polynom.terms[i].coefficient < 0)
                    out << " - ";
                else
                    out << " + ";
            } else {
                is_first = false;
            }
            mathterm::Term abs_copy = polynom.terms[i];
            abs_copy.coefficient = std::abs(abs_copy.coefficient);
            out << abs_copy;
        }
        return out;
    }

    char* ReadLineIgnoreSpaces(std::istream& input) {
        while (input.good() && std::isspace(input.peek())) {
            input.get();
        }

        if (!input.good()) return nullptr;

        size_t bufferSize = 128;
        char* buffer = new char[bufferSize];
        size_t index = 0;

        while (input.good()) {
            if (index >= bufferSize - 1) {
                size_t newSize = bufferSize * 2;
                char* newBuffer = new char[newSize];
                std::copy(buffer, buffer + bufferSize, newBuffer);
                delete[] buffer;
                buffer = newBuffer;
                bufferSize = newSize;
            }
            if (input.peek() == '\n') break;
            while (std::isspace(input.peek())) input.get();
            buffer[index++] = input.get();
        }

        buffer[index] = '\0';
        char* trimmedBuffer = new char[index + 1];
        std::strcpy(trimmedBuffer, buffer);
        delete[] buffer;

        return trimmedBuffer;
    }

    std::istream & operator>>(std::istream &in, Polynom &polynom) {
        char* raw_line = ReadLineIgnoreSpaces(in);

        size_t edited_line_size = 0;
        char* edited_line = new char[strlen(raw_line) * 2 + 2];
        edited_line[edited_line_size++] = '+';
        for (int i = 0; raw_line[i] != '\0'; i++) {
            if (raw_line[i] == '-') {
                edited_line[edited_line_size++] = '+';
            }
            edited_line[edited_line_size++] = raw_line[i];
        }
        edited_line[edited_line_size] = '\0';

        delete[] raw_line;
        raw_line = nullptr;

        char* buffer = new char[edited_line_size + 1];
        size_t buffer_size = 0;

        for (size_t i = 0; i < edited_line_size; i++) {
            if (edited_line[i] == '+') {
                buffer[buffer_size] = '\0';

                if (buffer_size != 0) {
                    mathterm::Term term;
                    buffer >> term;
                    polynom += term;
                }

                buffer_size = 0;
            } else {
                buffer[buffer_size++] = edited_line[i];
            }
        }
        if (buffer_size != 0) {
            mathterm::Term term;
            buffer[buffer_size] = '\0';
            buffer >> term;
            polynom += term;
        }

        delete[] buffer;
        delete[] edited_line;
        return in;
    }
}
