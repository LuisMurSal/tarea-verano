#include <stdio.h>

// Pasar de numero a vector
int pasar_a_vector(int num, int vector[]) {
    int longitud = 0;
    while (num > 0) {
        vector[longitud] = num % 10;
        num /= 10;
        longitud++;
    }

    // Invertir el vector para reflejar el orden original
    for (int i = 0; i < longitud / 2; i++) {
        int temp = vector[i];
        vector[i] = vector[longitud - 1 - i];
        vector[longitud - 1 - i] = temp;
    }

    return longitud;
}

// Sumar a la posicion deseada
void sumale(int posicion, int valor, int vector[], int longitud) {
    int suma = vector[posicion] + valor;
    int acarreo = suma / 10;
    vector[posicion] = suma % 10;

    for (int i = posicion + 1; i < longitud; i++) {
        suma = vector[i] + acarreo;
        acarreo = suma / 10;
        vector[i] = suma % 10;
    }

    while (acarreo > 0) {
        if (longitud == 20) {
            printf("Error: Desbordamiento del vector.\n");
            return;
        }
        vector[longitud] = acarreo % 10;
        acarreo /= 10;
        longitud++;
    }
}

int main() {
    int num;
    printf("Ingrese el numero original: ");
    scanf("%d", &num);

    // Tamano del vector
    int vector[20]; 
    int longitud = pasar_a_vector(num, vector);

    printf("Numero original: %d => [", num);
    for (int i = 0; i < longitud; i++) {
        printf("%d", vector[i]);
        if (i != longitud - 1) {
            printf(",");
        }
    }
    printf("]\n");

    int posicion, valor;
    printf("Ingrese la posicion donde desea aplicar sumale (comenzando desde 0): ");
    scanf("%d", &posicion);
    printf("Ingrese el valor de suma: ");
    scanf("%d", &valor);

    sumale(posicion, valor, vector, longitud);

    printf("Resultado: [");
    for (int i = 0; i < longitud; i++) {
        printf("%d", vector[i]);
        if (i != longitud - 1) {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
}
