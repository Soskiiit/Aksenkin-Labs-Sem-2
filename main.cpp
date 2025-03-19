#include <cstring>
#include <iostream>
#include <iomanip>

#include "fractions.h"


void interactive() {
    setlocale(LC_ALL, "Russian");

    // ввод дроби с клавиатуры
    std::cout << "Введите дробь: \n";
    frac::Fraction z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    frac::Fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    frac::Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    frac::Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    frac::Fraction f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
}

void demo() {

    setlocale(LC_ALL, "Russian");

    // ввод дроби с клавиатуры
    frac::Fraction z(1, 1);
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    frac::Fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    frac::Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    frac::Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    frac::Fraction f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
}

    int main(int argc, char *argv[]) {
    bool isInteractive = false;    // по умолчанию демо-режим.

    // Если i передается в качестве аргумента, то программу
    // необходимо запустить в интерактивном режиме
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        interactive();

    } else {
        demo();
    }
    return 0;
}