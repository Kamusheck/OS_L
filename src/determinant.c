#include "determinant.h"
#include <stdlib.h>

// Рекурсивная функция для вычисления определителя
int determinant(int **mat, int size) {
    if (size == 1) {
        return mat[0][0];
    }
    int det = 0;
    int sign = 1;

    // Выделяем память для минора
    int **minor = (int **)malloc((size - 1) * sizeof(int *));
    for (int i = 0; i < size - 1; i++) {
        minor[i] = (int *)malloc((size - 1) * sizeof(int));
    }

    // Вычисляем определитель по первой строке
    for (int col = 0; col < size; col++) {
        // Заполняем минор
        for (int i = 1; i < size; i++) {
            int minorCol = 0;
            for (int j = 0; j < size; j++) {
                if (j == col) continue;
                minor[i - 1][minorCol] = mat[i][j];
                minorCol++;
            }
        }

        // Рекурсивно вычисляем определитель минора
        det += sign * mat[0][col] * determinant(minor, size - 1);
        sign = -sign;
    }

    // Освобождаем память
    for (int i = 0; i < size - 1; i++) {
        free(minor[i]);
    }
    free(minor);

    return det;
}