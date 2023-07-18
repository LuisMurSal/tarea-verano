/*Name: Luis Angel Murillo Salinas
*explicacion: Trabajar en un codigo C que pueda leer una IP, validarla y sacar el broadcast de esta.
//Condiciones:
--Encabezado con tus datos y una explicacion del codigo
--Filtro del rango de numeros permitidos
--No aceptar numeros negativos
Biblioteca*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Función para validar una dirección IP
bool validarIP(const char *ip) {
    //array de 4 octetos (filtro)
    int octeto[4];
    int n = sscanf(ip, "%d.%d.%d.%d", &octeto[0], &octeto[1], &octeto[2], &octeto[3]);

    if (n != 4) {
        return false;
    }
    //cada octeto no debe superar 255
    for (int i = 0; i < 4; i++) {
        if (octeto[i] < 0 || octeto[i] > 255) {
            return false;
        }
    }

    return true;
}

// Convertir decimal a binario
void DecimalBinario(int octeto) {
    for (int i = 7; i >= 0; i--) {
        int bit = (octeto >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    // Espacio para la dirección IP
    char direccionIP[16];

    printf("\n|===============================================================|");
    printf("\n|                  Calcular Broadcast en Clang                  |");
    printf("\n|===============================================================|");

    printf("\nIngrese una direccion IP: ");
    // Se lee la dirección IP ingresada por el usuario
    scanf("%15s", direccionIP);

    if (validarIP(direccionIP)) {
        printf("La direccion IP %s es valida.\n", direccionIP);

        // Convertir a binario
        int octeto[4];
        sscanf(direccionIP, "%d.%d.%d.%d", &octeto[0], &octeto[1], &octeto[2], &octeto[3]);
        printf("Direccion IP en binario: ");
        for (int i = 0; i < 4; i++) {
            DecimalBinario(octeto[i]);
            if (i < 3) {
                printf(".");
            }
        }
        printf("\n");
    } else {
        printf("La direccion IP %s no es valida.\n", direccionIP);
    }

    return 0;
}

