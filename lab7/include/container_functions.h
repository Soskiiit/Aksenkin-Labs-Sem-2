#pragma once

#include "../../mylibs/vector.h"
#include "lab7_classes.h"

namespace lab7 {
    using PersonContainer = vector::Vector<Person*>;

    void print(const PersonContainer& container);
    void remove(PersonContainer& container, size_t index);
    void clear(PersonContainer& container);

    void demonstrationMode();
    void interactiveMode();

    void showMenu();
    Person* createPersonFromInput();
}
