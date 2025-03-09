#include <iostream>

#include "set.h"

int main() {
    set::Set<int> integer_set;
    integer_set.add_element(1);
    integer_set.add_element(2);
    integer_set.add_element(3);
    integer_set.add_element(-5);
    integer_set.add_element(2);
    integer_set.add_element(0);
    integer_set.delete_at_pos(3);
    integer_set.print();
    return 0;
}
