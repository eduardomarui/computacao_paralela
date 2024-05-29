#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Versão paralela da função compute_e com cálculo incremental do fatorial
double compute_e_parallel(int terms, int num_threads) {
    double e = 1.0;  // Inicializa e com o primeiro termo da série de Taylor
    double* factorials = (double*)malloc(terms * sizeof(double));
    factorials[0] = 1.0;  // 0! = 1

    // Calcula os fatoriais de forma incremental
    for (int i = 1; i < terms; i++) {
        factorials[i] = factorials[i - 1] * i;
    }

    #pragma omp parallel for num_threads(num_threads) reduction(+:e) schedule(static)
    for (int i = 1; i < terms; i++) {
        e += 1.0 / factorials[i]; // Adiciona o termo diretamente, sem seção crítica
    }

    free(factorials);
    return e;
}

int main(int argc, char *argv[]) {
    int terms = 100000;  // Aumenta o número de termos na série de Taylor para calcular 'e'

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <número de threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);  // Converte o argumento de linha de comando para inteiro
    omp_set_num_threads(num_threads);  // Define o número de threads para o OpenMP

    double result = compute_e_parallel(terms, num_threads);  // Calcula 'e' paralelamente
    printf("O valor de e calculado com %d thread(s) e %d termos é: %.15f\n", num_threads, terms, result);

    return 0;
}
