#include "funciones.h"
#include <stdio.h>
#include <ctype.h>



char mapear(char c, const char *clave1, const char *clave2, int len) {
    for (int i = 0; i < len; i++) {
        if (tolower(c) == tolower(clave1[i]))
            return isupper(c) ? toupper(clave2[i]) : tolower(clave2[i]);
        if (tolower(c) == tolower(clave2[i]))
            return isupper(c) ? toupper(clave1[i]) : tolower(clave1[i]);
    }
    return c;
}



int comparacion_strings(const char *str1, const char *str2) {
    
    // arreglo de tamaño 256 para guardar caracteres
    int marcado[256] = {0};

    // Recorremos el primer string
    for (int i = 0; str1[i] != '\0'; i++) {
        // Si el carácter ya está marcado, hay repetición
        if (marcado[(unsigned char)str1[i]]) {
            return 1;  // Retorna 1 si encuentra repetición
        }
        // Marcamos el carácter como encontrado
        marcado[(unsigned char)str1[i]] = 1;
    }

    // Recorremos el segundo string
    for (int i = 0; str2[i] != '\0'; i++) {
        // Si el carácter ya está marcado, hay repetición
        if (marcado[(unsigned char)str2[i]]) {
            return 1;
        }
        // Marcamos el carácter como encontrado
        marcado[(unsigned char)str2[i]] = 1;
    }

    // Si no se encuentra ningún carácter repetido, retornamos 0
    return 0;
}



void codificar(FILE *entrada, FILE *salida, const char *clave1, const char *clave2, int len) {
    int c;
    while ((c = fgetc(entrada)) != EOF) {
        char nuevo = mapear(c, clave1, clave2, len);
        fputc(nuevo, salida);
    }
}



void decodificar(FILE *entrada, FILE *salida, const char *clave1, const char *clave2, int len) {
    // La decodificación es exactamente igual a la codificación con las mismas claves
    codificar(entrada, salida, clave1, clave2, len);
}