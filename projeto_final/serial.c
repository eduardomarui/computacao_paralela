#include <stdio.h>

double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double compute_e(int terms) {
    double e = 1.0; // Primeiro termo da série é 1
    for (int i = 1; i < terms; i++) {
        e += 1.0 / factorial(i);
    }
    return e;
}

int main() {
    int terms = 20;
    double result = compute_e(terms);
    printf("O valor de e calculado é: %.15f\n", result);
    return 0;
}
