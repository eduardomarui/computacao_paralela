#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mpfr.h>

// Função para calcular uma porção do fatorial em paralelo
void calcular_fatorial_parcial(int inicio, int fim, mpfr_t resultado_parcial, int nBits) {
    mpfr_set_ui(resultado_parcial, 1, MPFR_RNDU);  // Inicializa com 1

    for (int i = inicio; i <= fim; ++i) {
        mpfr_mul_ui(resultado_parcial, resultado_parcial, i, MPFR_RNDU);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Uso: %s <número de threads> <número de termos> <número de bits>\n", argv[0]);
        return 1;
    }

    int nThreads = strtol(argv[1], NULL, 10);
    int n = strtol(argv[2], NULL, 10);
    int nBits = strtol(argv[3], NULL, 10);

    // Aloca memória para armazenar os resultados parciais
    mpfr_t* resultados_parciais = malloc(nThreads * sizeof(mpfr_t));
    for (int i = 0; i < nThreads; ++i) {
        mpfr_init2(resultados_parciais[i], nBits);
        mpfr_set_ui(resultados_parciais[i], 1, MPFR_RNDU);  // Inicializa com 1
    }

    int parcela = n / nThreads;

    #pragma omp parallel num_threads(nThreads)
    {
        int id = omp_get_thread_num();
        int inicio = id * parcela + 1;
        int fim = (id == nThreads - 1) ? n : (id + 1) * parcela;
        calcular_fatorial_parcial(inicio, fim, resultados_parciais[id], nBits);
    }

    // Combina os resultados parciais
    mpfr_t resultado_final;
    mpfr_init2(resultado_final, nBits);
    mpfr_set_ui(resultado_final, 1, MPFR_RNDU);  // Inicializa com 1

    for (int i = 0; i < nThreads; ++i) {
        mpfr_mul(resultado_final, resultado_final, resultados_parciais[i], MPFR_RNDU);
        mpfr_clear(resultados_parciais[i]);
    }
    free(resultados_parciais);

    // Imprime o resultado final
    mpfr_printf("Fatorial de %d com %d bits de precisão: %.Rf\n", n, nBits, resultado_final);

    mpfr_clear(resultado_final);
    return 0;
}
