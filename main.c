#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "include/determinant.h"

#define MAX_THREADS 8  // Максимальное количество потоков

int **matrix;
int n;
int det = 0;
pthread_mutex_t mutex;

typedef struct {
    int start_col;
    int end_col;
} ThreadData;

void* calculateTerm(void* arg);

// Функция для ввода матрицы вручную
void inputMatrix() {
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Matrix size must be a positive integer.\n");
        exit(1);
    }

    // Выделение памяти для матрицы
    matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Ввод значений матрицы
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main(int argc, char *argv[]) {
    int num_threads;

    if (argc == 3) {
        // Режим с аргументами командной строки
        const char *input_file = argv[1];
        num_threads = atoi(argv[2]);

        if (num_threads <= 0 || num_threads > MAX_THREADS) {
            printf("Number of threads must be between 1 and %d.\n", MAX_THREADS);
            return 1;
        }

        // Чтение матрицы из файла
        FILE *file = fopen(input_file, "r");
        if (!file) {
            printf("Error opening file: %s\n", input_file);
            return 1;
        }

        fscanf(file, "%d", &n);
        matrix = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                fscanf(file, "%d", &matrix[i][j]);
            }
        }
        fclose(file);
    } else if (argc == 1) {
        // Ручной режим
        inputMatrix();

        printf("Enter the number of threads (1-%d): ", MAX_THREADS);
        scanf("%d", &num_threads);

        if (num_threads <= 0 || num_threads > MAX_THREADS) {
            printf("Number of threads must be between 1 and %d.\n", MAX_THREADS);
            return 1;
        }
    } else {
        printf("Usage:\n");
        printf("  Automatic mode: %s <input_file> <num_threads>\n", argv[0]);
        printf("  Manual mode:    %s\n", argv[0]);
        return 1;
    }

    // Создание потоков
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    pthread_mutex_init(&mutex, NULL);

    int cols_per_thread = n / num_threads;
    int remaining_cols = n % num_threads;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start_col = i * cols_per_thread;
        thread_data[i].end_col = (i + 1) * cols_per_thread;

        if (i == num_threads - 1) {
            thread_data[i].end_col += remaining_cols;  // Последний поток берет оставшиеся столбцы
        }

        pthread_create(&threads[i], NULL, calculateTerm, (void *)&thread_data[i]);
    }

    // Ожидание завершения потоков
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    // Вывод результата
    printf("Determinant: %d\n", det);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Функция для вычисления слагаемого в формуле определителя
void* calculateTerm(void* arg) {
    ThreadData *data = (ThreadData *)arg;
    int start_col = data->start_col;
    int end_col = data->end_col;

    for (int col = start_col; col < end_col; col++) {
        int sign = (col % 2 == 0) ? 1 : -1;

        // Выделяем память для минора
        int **minor = (int **)malloc((n - 1) * sizeof(int *));
        for (int i = 0; i < n - 1; i++) {
            minor[i] = (int *)malloc((n - 1) * sizeof(int));
        }

        // Заполняем минор
        for (int i = 1; i < n; i++) {
            int minor_col = 0;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                minor[i - 1][minor_col] = matrix[i][j];
                minor_col++;
            }
        }

        // Вычисляем определитель минора
        int minor_det = determinant(minor, n - 1);

        // Обновляем общий определитель
        pthread_mutex_lock(&mutex);
        det += sign * matrix[0][col] * minor_det;
        pthread_mutex_unlock(&mutex);

        // Освобождаем память
        for (int i = 0; i < n - 1; i++) {
            free(minor[i]);
        }
        free(minor);
    }

    pthread_exit(NULL);
}