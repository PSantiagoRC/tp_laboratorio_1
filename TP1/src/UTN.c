/*
 * UTN.c
 *
 *  Created on: 8 abr. 2022
 *      Author: rodri
 */

#include "UTN.h"

/*////////////OPERACIONES BASICAS////////////////////*/




int dividir(float * pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado !=NULL && operador2 != 0)
	{
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}





int sumar(float * pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado !=NULL)
	{
		resultado = (float) operador1 + (float) operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}





int restar(float * pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado !=NULL)
	{
		resultado = (float) operador1 - (float) operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}





int multiplicar(float * pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado !=NULL)
	{
		resultado = (float) operador1 * (float) operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}






/*//////////// GETS ////////////////////*/

int getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado)
{
	int retorno = -1;
	int bufferInt;
	int retornoScanf;
	//Revisar que todos los datos esten bien
	if(mensaje != NULL && mensajeError != NULL && pNumeroIngresado != NULL && reintentos >= 0 && minimo < maximo )
	{
		printf("%s",mensaje);
		retornoScanf = scanf("%d",&bufferInt); //hasta aca no se si los datos son VALIDOS, entonces guardo mi dato por esta variable auxiliar
		do{
			if(retornoScanf != 1 || bufferInt > maximo || bufferInt < minimo)
			{
				printf("%s",mensajeError);
				fflush(stdin); //Porque si ingresan una letra nunca más entro en el do while.
				retornoScanf = scanf("%d",&bufferInt);
				reintentos--;
				printf("Intentos remanentes es: %d", reintentos);
			}
			else{
				reintentos = 0;
				*pNumeroIngresado = bufferInt;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}





int getFloat(char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado)
{
	int retorno = -1;
	float bufferFloat;
	int retornoScanf;
	//Revisar que todos los datos esten bien
	if(mensaje != NULL && mensajeError != NULL && pNumeroIngresado != NULL && reintentos >= 0 && minimo < maximo)
	{
		printf("%s",mensaje);
		retornoScanf = scanf("%f",&bufferFloat); //hasta aca no se si los datos son VALIDOS, entonces guardo mi dato por esta variable auxiliar
		do
		{
			if(retornoScanf != 1 || bufferFloat > maximo || bufferFloat < minimo)
			{
				printf("%s",mensajeError);
				fflush(stdin);
				retornoScanf = scanf("%f",&bufferFloat);
				reintentos--;
				printf("Intentos remanentes es: %d", reintentos);
			}
			else{
				reintentos = 0;
				*pNumeroIngresado = bufferFloat;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}





int getChar(char mensaje[], int reintentos, char minimo, char maximo, char mensajeError[], char *pCharIngresado)
{
	int retorno = -1;
	char bufferChar;
	int retornoScanf;
	//Revisar que todos los datos esten bien
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pCharIngresado != NULL && reintentos > 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		retornoScanf = scanf("%c",&bufferChar); //hasta aca no se si los datos son VALIDOS, entonces guardo mi dato por esta variable auxiliar
		do{
			if(retornoScanf != 1 || bufferChar > maximo || bufferChar < minimo)
			{
				printf("%s",mensajeError);
				fflush(stdin);
				retornoScanf = scanf("%c",&bufferChar);
				reintentos--;
				printf("Intentos remanentes es: %d", reintentos);
			}
			else{
				reintentos = 0;
				*pCharIngresado = bufferChar;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}


