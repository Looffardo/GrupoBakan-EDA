#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>

// Funcion para cambiar los caracteres en funcion de las claves entregadas
char mapear(char c, const char *clave1, const char *clave2, int len);

// Funcion para determinar caracteres repetidos entre 2 strings
int comparacion_strings(const char *str1, const char *str2);

// Función para codificar el mensaje
void codificar(FILE *entrada, FILE *salida, const char *clave1, const char *clave2, int len);

// Función para decodificar el mensaje
void decodificar(FILE *entrada, FILE *salida, const char *clave1, const char *clave2, int len);

#endif