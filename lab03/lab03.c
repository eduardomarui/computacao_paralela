#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return sin(x);
}

void Integrate(double a, double b, int n, int thread_count, double* total_area) {
    double h = (b - a) / n;
    double local_area = 0.0;

    #pragma omp parallel num_threads(thread_count) private(local_area)
    {
        int thread_num = omp_get_thread_num();
        int local_n = n / thread_count;
        double local_a = a + thread_num * local_n * h;
        double local_b = local_a + local_n * h;

        for (int i = 0; i < local_n; i++) {
            double x1 = local_a + i * h;
            double x2 = local_a + (i + 1) * h;
            local_area += (f(x1) + f(x2)) * h / 2.0;
        }
        
        #pragma omp atomic
        *total_area += local_area;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int thread_count = strtol(argv[1], NULL, 10);
    if (thread_count <= 0) {
        fprintf(stderr, "Number of threads must be a positive integer\n");
        return 1;
    }

    double a = 0.0, b = M_PI;
    int n = 1000000; // número de trapézios
    double total_area = 0.0;

    Integrate(a, b, n, thread_count, &total_area);
    printf("Threads: %d, Total area: %f\n", thread_count, total_area);

    return 0;
}

