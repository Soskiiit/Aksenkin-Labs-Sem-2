#include <iostream>

#include "stk.h"

namespace {
    std::pair<int*, int> Factorize(int n) {
        int *dividers = new int[30];
        int dividers_count = 0;
        int divider = 2;
        while (n > 1) {
            if (n % divider == 0) {
                dividers[dividers_count++] = divider;
                n = n / divider;
            } else {
                divider++;
            }
        }
        int *ans = new int[dividers_count];
        for (int i = 0; i < dividers_count; i++) {
            ans[i] = dividers[i];
        }
        delete[] dividers;

        return {ans, dividers_count};
    }

    std::pair<stk::Stack<int>, stk::Stack<int>> Multipliers(int n) {
        stk::Stack<int> multipliers_ascending, multipliers_descending;
        auto [dividers, dividers_count] = Factorize(n);
        for (int i = 0; i < dividers_count; i++) multipliers_descending.Push(dividers[i]);
        for (int i = dividers_count - 1; i >= 0; i--) multipliers_ascending.Push(dividers[i]);
        return {multipliers_ascending, multipliers_descending};
    }
}



int main() {
    int n = 3960;
    bool first_multiplier_printed = false;
    auto [multipliers_ascending, multipliers_descending] = Multipliers(n);

    // Ascending
    std::cout << n << " = ";
    while (!multipliers_ascending.IsEmpty()) {
        if (first_multiplier_printed) {
            std::cout << " * ";
        } else {
            first_multiplier_printed = true;
        }
        std::cout << multipliers_ascending.Pop();
    }
    std::cout << std::endl;

    // Descending
    std::cout << n << " = ";
    first_multiplier_printed = false;
    while (!multipliers_descending.IsEmpty()) {
        if (first_multiplier_printed) {
            std::cout << " * ";
        } else {
            first_multiplier_printed = true;
        }
        std::cout << multipliers_descending.Pop();
    }
    std::cout << std::endl;

    return 0;
}
