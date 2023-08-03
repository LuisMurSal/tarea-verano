/*Name: Luis Angel Murillo Salinas
*explicacion: Buscar la suma de 2 componentes que den como resultado el numero N
//Condiciones:
--No aceptar numeros con punto decimal
--No aceptar numeros negativos
*/
#include <stdio.h>
#include <stdlib.h>

void SumaFinder(int vector[], int n, int target_sum) {
    // Calcular el tamaño necesario para el diccionario
    int dict_size = 0;
    for (int i = 0; i < n; i++) {
        if (vector[i] > 0 && vector[i] <= target_sum) {
            dict_size = (vector[i] > dict_size) ? vector[i] : dict_size;
        }
    }

    // Diccionario para almacenar los índices de los valores
    int *index_dict = (int *)malloc(dict_size * sizeof(int));

    if (index_dict == NULL) {
        printf("Error de asignacion de memoria.\n");
        return;
    }

    for (int i = 0; i < dict_size; i++) {
        index_dict[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        // Verificación para que no sea negativo
        if (vector[i] < 0) {
            continue;
        }

        int complement = target_sum - vector[i];

        // Si está en el diccionario y no es el mismo elemento, hay combinación
        if (complement > 0 && complement <= dict_size && index_dict[complement] && index_dict[complement] - 1 != i) {
            printf("Suma deseada: %d, pareja encontrada: [%d] y [%d] (Valores: %d + %d)\n",
                target_sum, index_dict[complement] - 1, i, complement, vector[i]);
        }

        index_dict[vector[i]] = i + 1;
    }

    free(index_dict);
}

int main() {
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(vector) / sizeof(vector[0]);
    int target_sum = 5;

    // Mostrar el contenido del vector y la suma deseada
    printf("Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    printf("Suma deseada: %d\n", target_sum);

    SumaFinder(vector, n, target_sum);

    return 0;
}
