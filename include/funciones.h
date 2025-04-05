#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

// 
char mapear(char c, const char *clave1, const char *clave2, int len);

// Función para codificar el mensaje
void codificar(FILE *entrada, FILE *salida, const char *clave1, const char *clave2, int len);

// Función para decodificar el mensaje
void decodificar(FILE *entrada, FILE *salida, const char *clave1, const char *clave2, int len);

// Funcion para determinar caracteres repetidos entre 2 strings
int comparacion_strings(const char *str1, const char *str2);
#endif