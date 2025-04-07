#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "txt_reader.h"
#include "funciones.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 6) { // 5 parámetros + el nombre del ejecutable 
        printf("Error: Debes ingresar 5 parametros.\n");
        return 1;
    }

    char *archivo_entrada = argv[1];
    char *accion = argv[2];
    char *clave1 = argv[3];
    char *clave2 = argv[4];
    char *archivo_salida = argv[5];

    //
    // Verificar que los parametros de entrada son correctos
    //

    if (strcmp(accion, "encode") != 0 && strcmp(accion, "decode") != 0) {
        printf("Error: El segundo parametro debe ser 'encode' o 'decode'.\n");
        return 1;
    }

    if (strlen(clave1) != strlen(clave2)) {
        printf("Error: Las palabras clave deben tener la misma longitud.\n");
        return 1;
    }

    // Verifica que las claves no tengan caracteres repetidos.
    if (comparacion_strings(clave1, clave2) == 1) {
        printf("Error: Las palabras clave no pueden contener caracteres repetidos.\n");
        return 1;
    }

    // Abrir el archivo de entrada para lectura
    FILE *entrada = fopen(archivo_entrada, "r");
    if (!entrada) {
        printf("Error: No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    // Crear o abrir el archivo de salida para escritura
    FILE *salida = fopen(archivo_salida, "w");
    if (!salida) {
        printf("Error: No se pudo crear el archivo de salida.\n");
        fclose(entrada);
        return 1;
    }

    if (strcmp(accion, "encode") == 0) {
        codificar(entrada, salida, clave1, clave2, strlen(clave1));
    } else {
        decodificar(entrada, salida, clave1, clave2, strlen(clave1));
    }    

    // Cerrar los archivos
    fclose(entrada);
    fclose(salida);

    printf("El archivo fue %s con exito.\n", accion);
    return 0;
}