#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int m = 4, n = 4; // Dimensões da matriz e do vetor.
int thread_count; // Número de threads a serem criadas.

double A[4][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {5.0, 6.0, 7.0, 8.0},
    {9.0, 10.0, 11.0, 12.0},
    {13.0, 14.0, 15.0, 16.0}
};
double x[4] = {1.0, 2.0, 3.0, 4.0};
double y[4];

void *Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int total_elements = m * n;
    int local_elements = total_elements / thread_count;
    int extra = total_elements % thread_count;
    int start = my_rank * local_elements + (my_rank < extra ? my_rank : extra);
    int end = start + local_elements + (my_rank < extra) - 1;

    for (int element = start; element <= end; element++) {
        int i = element / n; // Calcula a linha atual
        int j = element % n; // Calcula a coluna atual
        y[i] += A[i][j] * x[j];
    }

    return NULL;
}

int main() {
    pthread_t* thread_handles;
    clock_t start, end;
    double cpu_time_used;

    int threads[] = {1, 2, 4, 6, 8}; // Configurações de número de threads.

    for (int k = 0; k < 5; k++) {
        thread_count = threads[k];
        thread_handles = malloc(thread_count * sizeof(pthread_t));
        
        start = clock();
        for (long thread = 0; thread < thread_count; thread++) {
            pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
        }
        for (long thread = 0; thread < thread_count; thread++) {
            pthread_join(thread_handles[thread], NULL);
        }
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Threads: %d, Tempo de execução: %f segundos\n", thread_count, cpu_time_used);

        free(thread_handles);
    }

    return 0;
}

