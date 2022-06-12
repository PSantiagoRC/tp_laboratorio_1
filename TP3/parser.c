#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char id[100];
	char nombre[100];
	char apellido[100];
	char estado[100];
	char tipo[100];
	char precio[100];
	char codigo[100];
    char falsa[100];
    Passenger* p;

	if(pFile != NULL && pArrayListPassenger !=NULL){

		fscanf(pFile,"%[^\n]\n",falsa); //Headers

    	while(!feof(pFile))// for(int i=0;i<3;i++)//
    	{
    		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r\n]\n",id,nombre,apellido,precio,codigo,tipo,estado); //Antes usaba %[^\n],\nUlt elemento leido debe ser \n. Y ult \n es para nextline.

    		//CAMBIAR ESTO POR SETTERS/GETTERS???

			if((p = Passenger_newParametros(id,nombre,apellido,tipo,codigo,precio,estado))!=NULL){
				ll_add(pArrayListPassenger, p);
			}else{
				retorno = -2;//FUNCION newParametros devuelve puntero a NULL
			}
    	}
	}else{
	retorno = -1; //Archivo cerrado o array NULL
	}
	return retorno;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char id[100];
	char nombre[100];
	char apellido[100];
	char estado[100];
	char tipo[100];
	char precio[100];
	char codigo[100];
    char falsa[100];
    Passenger* p;

	if(pFile != NULL && pArrayListPassenger !=NULL){

		fscanf(pFile,"%[^\n]\n",falsa); //Headers

    	while(!feof(pFile))// for(int i=0;i<3;i++)//
    	{
    		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r\n]\n",id,nombre,apellido,precio,codigo,tipo,estado); //Ult elemento leido debe ser \n. Y ult \n es para nextline.

			if((p = Passenger_newParametros(id,nombre,apellido,tipo,codigo,precio,estado))!=NULL){
				ll_add(pArrayListPassenger, p);
			}else{
				retorno = -2;//FUNCION newParametros devuelve puntero a NULL
			}
    	}
	}else{
	retorno = -1; //Archivo cerrado o array NULL
	}
	return retorno;
}
