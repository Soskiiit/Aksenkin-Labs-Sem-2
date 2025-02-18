#include <iostream>

#include "mymath/mymath.h"
#include "matrixhelper/matrixhelper.h"


int main() {
    setlocale(LC_ALL, "Russian");
    double** matrix = new double*[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i * 3 + j + 1;
        }
    }
    std::cout << "Я умею суммировать! Зацени 10+32=";
    std::cout << mymath::sum(10, 32) << std::endl;
    matrixhelper::PrintMatrix(matrix, 3, 3);
    return 0;
}
