#include "matrixhelper.h"

#include <iostream>
#include <iomanip>


namespace matrixhelper {
    double **CreateMatrix(int rows, int cols) {
        auto **matrix = new double *[rows];
        // Iterates over matrix and creates every row
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[cols];
        }
        return matrix;
    }

    void DeleteMatrix(double **matrix, int rows) {
      for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
      }
        delete[] matrix;
    }

    void PrintMatrix(double **matrix, int rows, int cols, OutputMode outputMode, int precision, int maxLineLength) {
        int margin = 4;
        if (outputMode == OutputMode::Scientific) margin += 8;
        int oneElementWidth = precision + margin;
        int elenemtsInOneRow = maxLineLength / oneElementWidth;
        int tableWidth = std::min(oneElementWidth * std::min(elenemtsInOneRow, cols) + margin, maxLineLength + margin);
        int pagesCount = cols / elenemtsInOneRow;
        if (cols % elenemtsInOneRow != 0) pagesCount++;

        // Print "=======..." (start of table) and configures output
        if (outputMode == OutputMode::Fixed) {
            std::cout << std::fixed;
        } else {
            std::cout << std::scientific;
        }
        std::cout << std::setprecision(precision) << std::setfill('=');
        std::cout << std::setw(tableWidth) << "=" << std::endl << std::setfill(' ');

        // Printing table
        for (int i = 0; i < pagesCount; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < elenemtsInOneRow; k++) {
                    if (i * elenemtsInOneRow + k < cols)
                        std::cout << std::setw(oneElementWidth) << matrix[j][i * elenemtsInOneRow + k];
                }
                std::cout << std::endl;
            }
            // If it was last row and wasn't last page separates pages by print "-------..."
            if (i != pagesCount - 1) {
                std::cout << std::setfill('-') << std::setw(tableWidth) << '-' << std::endl;
                std::cout << std::setfill(' ');
            }
        }
        // Prints "=======..." (end of table)
        std::cout << std::setfill('=') << std::setw(tableWidth) << "=" << std::endl << std::setfill(' ');
    }
}
