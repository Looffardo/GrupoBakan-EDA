#ifndef TXT_READER_H
#define TXT_READER_H
#include <stdio.h>

// Abre un archivo en modo lectura y retorna el puntero (o NULL si falla)
FILE* abrir_entrada(const char *nombre_archivo);

// Abre un archivo en modo escritura y retorna el puntero (o NULL si falla)
FILE* abrir_salida(const char *nombre_archivo);

#endif