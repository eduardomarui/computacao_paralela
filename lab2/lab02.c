#include <stdio.h>      // Inclui a biblioteca padrão
#include <stdlib.h>     // Inclui a biblioteca padrão
#include <pthread.h>    // Inclui a biblioteca de threads

// Define o número de threads a serem criadas.
int thread_count = 4;
//define dimensão da matriz e do vetor
int m = 4, n = 4;
// Inicializaa a  matriz A 4x4 
double A[4][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {5.0, 6.0, 7.0, 8.0},
    {9.0, 10.0, 11.0, 12.0},
    {13.0, 14.0, 15.0, 16.0}
};
// Inicializa um vetor x com 4 elementos
double x[4] = {1.0, 2.0, 3.0, 4.0};
// Declara um vetor y para armazenar o resultado da multiplicação da matriz pelo vetor.
double y[4];

// Função executada pelas threads para multiplicar a matriz pelo vetor.
void *Pth_mat_vect(void* rank) {
    // Converte o argumento rank de volta para um tipo long, que identifica a thread.
    long my_rank = (long) rank;
    // Calcula quantas linhas da matriz cada thread deve processar.
    int local_m = m/thread_count;
    // Determina a primeira linha da matriz que a thread irá processar.
    int my_first_row = my_rank*local_m;
    // Define a última linha da matriz que esta thread irá processar.
    int my_last_row = (my_rank+1)*local_m - 1;

    // Loop nas linhas da thread.
    for (int i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0; // Inicializa a entrada do vetor de resultado com zero.
        // Loop por cada coluna da matriz.
        for (int j = 0; j < n; j++) {
            // Multiplica o elemento da matriz pelo elemento correspondente do vetor e acumula o resultado.
            y[i] += A[i][j]*x[j];
        }
    }

    return NULL; // Retorna NULL uma vez concluiu sua tarefa.
}

// Função principal do programa.
int main() {
    // Declara um ponteiro para armazenar os identificadoress das threads.
    pthread_t* thread_handles;

    // Aloca memória para eles threads.
    thread_handles = malloc (thread_count*sizeof(pthread_t));

    // Cria as threads usando create; cada uma executará a função Pth_mat_vect.
    for (long thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);

    // Aguarda todas as threads terminarem usando join.
    for (long thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    // Imprime os resultados da multiplicação.
    for (int i = 0; i < m; i++) {
        printf("y[%d] = %f\n", i, y[i]);
    }

    // Libera a memória alocada para os identificadores das threads.
    free(thread_handles);
    return 0; // Termina a execução do programa.
}
