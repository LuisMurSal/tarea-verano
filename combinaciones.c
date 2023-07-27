#include <stdio.h>
#include <stdlib.h>

void print_binary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <bits_prestado>\n", argv[0]);
        return 1;
    }

    int bits_prestado = atoi(argv[1]);
    if (bits_prestado <= 0) {
        printf("El numero de bits prestados debe ser un entero positivo.\n");
        return 1;
    }

    int combinaciones = 1 << bits_prestado;
    printf("Combinaciones posibles con %d bits: %d\n", bits_prestado, combinaciones);

    printf("Combinaciones de bits:\n");
    for (int i = 0; i < combinaciones; i++) {
        print_binary(i, bits_prestado);
        printf("\n");
    }

    return 0;
}
