#include <iostream>

#include "include/matrixhelper.h"
#include "include/mymath.h"

int main() {
    std::cout << "Я умею считать! 1+2=" << mymath::sum(1, 2) << std::endl;
    std::cout << "И выводить матрицы!" << std::endl;
    double** matrix = matrixhelper::CreateMatrix(3, 3);
    matrixhelper::PrintMatrix(matrix, 3, 3);
    matrixhelper::DeleteMatrix(matrix, 3);
    return 0;
}
