#include <iostream>

#include "stk.h"


int main() {
    stk::Stack<int> stack;
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    std::cout << stack.Pop() << std::endl << stack.Pop() << std::endl << stack.Pop() << std::endl;
    return 0;
}
