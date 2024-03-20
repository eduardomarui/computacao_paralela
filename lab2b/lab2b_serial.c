#include <stdio.h>
#include <time.h>       // Inclusão da biblioteca para funções de tempo.

int m = 4, n = 4; // Dimensões da matriz e do vetor.

double A[4][4] = { // Inicialização da matriz A 4x4.
    {1.0, 2.0, 3.0, 4.0},
    {5.0, 6.0, 7.0, 8.0},
    {9.0, 10.0, 11.0, 12.0},
    {13.0, 14.0, 15.0, 16.0}
};

double x[4] = {1.0, 2.0, 3.0, 4.0}; // Inicialização do vetor x.
double y[4]; // Vetor resultado.

void mat_vect_mult_serial(double A[][n], double x[], double y[], int m, int n) {
    for (int i = 0; i < m; i++) {
        y[i] = 0.0;
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    clock_t start, end; // Variáveis para armazenar os momentos de início e fim da execução.
    double cpu_time_used; // Variável para armazenar o tempo de CPU utilizado.

    start = clock(); // Marca o momento de início.
    mat_vect_mult_serial(A, x, y, m, n); // Executa a multiplicação matriz-vetor de forma serial.
    end = clock(); // Marca o momento de fim.

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calcula o tempo de CPU utilizado.

    for (int i = 0; i < m; i++) { // Imprime os resultados da multiplicação.
        printf("y[%d] = %f\n", i, y[i]);
    }

    printf("Tempo de execução: %f segundos\n", cpu_time_used); // Imprime o tempo de execução.

    return 0;
}
