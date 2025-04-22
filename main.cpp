#include <iostream>

#include "set.h"

int main() {
    set::Set<int> integer_set;
    integer_set.add_element(1);
    integer_set.add_element(2);
    integer_set.add_element(3);

    set::Set<int> integer_set_2;
    integer_set_2.add_element(3);
    integer_set_2.add_element(4);
    integer_set_2.add_element(5);
    integer_set -= integer_set_2;

    std::cout << integer_set << std::endl;
    return 0;
}
