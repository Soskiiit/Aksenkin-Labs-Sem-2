#pragma once

#include <iostream>

#include "term.h"


namespace polynom {
    enum class SortOrder {
        ascending,
        descending
    };

    class Polynom {
    private:
        mathterm::Term* terms = nullptr;
        size_t size = 0;
        size_t capacity = 0;
        SortOrder sort_order = SortOrder::ascending;
    public:
        Polynom();
        ~Polynom();
        Polynom(const Polynom& polynom);
        Polynom operator=(const Polynom& polynom);

        Polynom& operator+=(double num);
        Polynom &operator+=(const mathterm::Term &term);
        Polynom& operator+=(const Polynom &polynom);

        Polynom operator+(const Polynom& polynom);
        Polynom operator+(const mathterm::Term &term);
        Polynom operator+(double num);

        void OptimizePolynom();
        void AddTerm(mathterm::Term term);
        void DeleteTerm(size_t index);

        friend std::ostream& operator<<(std::ostream& out, const Polynom& polynom);
        friend std::istream& operator>>(std::istream& in, Polynom& polynom);
    };
}
