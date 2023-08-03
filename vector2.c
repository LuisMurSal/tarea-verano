#include <stdio.h>
#include <stdlib.h>

void SumaFinder(int vector[], int n, int target_sum) {
    // Diccionario para almacenar los indices de los valores
    int *index_dict = (int *)malloc(1000 * sizeof(int));

    if (index_dict == NULL) {
        printf("Error de asignacion de memoria.\n");
        return;
    }

    for (int i = 0; i < 1000; i++) {
        index_dict[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        // Verificacion para que no sea negativo
        if (vector[i] < 0) {
            continue;
        }

        int complement = target_sum - vector[i];

        // Si esta en el diccionario y no es el mismo elemento, hay combinacion
        if (complement > 0 && complement <= 1000 && index_dict[complement] && index_dict[complement] - 1 != i) {
            printf("[%d] y [%d]\n", index_dict[complement] - 1, i);
        }

        index_dict[vector[i]] = i + 1;
    }

    free(index_dict);
}

int main() {
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(vector) / sizeof(vector[0]);
    int target_sum = 5;

    SumaFinder(vector, n, target_sum);

    return 0;
}
