#include <txt_reader.h>
#include <stdio.h>


FILE* abrir_entrada(const char *nombre_archivo) {
    return fopen(nombre_archivo, "r");
}

FILE* abrir_salida(const char *nombre_archivo) {
    return fopen(nombre_archivo, "w");
}