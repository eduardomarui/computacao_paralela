#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return sin(x);
}

double integrate(double a, double b, int n, int num_threads) {
    double h = (b - a) / n;
    double total_area = 0.0;
    
    #pragma omp parallel num_threads(num_threads)
    {
        double thread_area = 0.0;
        #pragma omp for
        for (int i = 0; i < n; i++) {
            double x1 = a + i * h;
            double x2 = a + (i + 1) * h;
            thread_area += (f(x1) + f(x2)) * h / 2.0;
        }
        
        #pragma omp critical
        total_area += thread_area;
    }
    
    return total_area;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    if (num_threads <= 0) {
        fprintf(stderr, "Number of threads must be a positive integer\n");
        return 1;
    }

    double a = 0.0, b = M_PI;
    int n = 1000000; // número de trapézios

    double result = integrate(a, b, n, num_threads);
    printf("Threads: %d, Result: %f\n", num_threads, result);
    return 0;
}

