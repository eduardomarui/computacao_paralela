#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Função para calcular o fatorial de um número n
double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Versão paralela da função compute_e
double compute_e_parallel(int terms, int num_threads) {
    double e = 1.0;  // Inicializa e com o primeiro termo da série de Taylor
    #pragma omp parallel for num_threads(num_threads) reduction(+:e)
    for (int i = 1; i < terms; i++) {
        e += 1.0 / factorial(i); // Adiciona o termo diretamente, sem seção crítica
    }
    return e;
}

int main(int argc, char *argv[]) {
    int terms = 20;  // Número de termos na série de Taylor para calcular 'e'

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <número de threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);  // Converte o argumento de linha de comando para inteiro
    omp_set_num_threads(num_threads);  // Define o número de threads para o OpenMP

    double result = compute_e_parallel(terms, num_threads);  // Calcula 'e' paralelamente
    printf("O valor de e calculado com %d thread(s) é: %.15f\n", num_threads, result);

    return 0;
}
