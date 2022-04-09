/*
 * UTN.h
 *
 *  Created on: 8 abr. 2022
 *      Author: rodri
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>

int dividir(float * pResultado, int operador1, int operador2);
int sumar(float * pResultado, int operador1, int operador2);
int restar(float * pResultado, int operador1, int operador2);
int multiplicar(float * pResultado, int operador1, int operador2);

int getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);
int getFloat(char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado);
int getChar(char mensaje[], int reintentos, char minimo, char maximo, char mensajeError[], char *pCharIngresado);

#endif /* UTN_H_ */
