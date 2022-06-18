#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "UTN4.h"

#define NOMBRE_LEN 50
#define APELLIDO_LEN 50
#define CODIGO_LEN 8
#define ESTADO_LEN 20
#define TIPO_LEN 20

#define ECONOMY_CLASS 0
#define EXECUTIVE_CLASS 1
#define FIRST_CLASS 2
#define ERROR_CLASS 9

#define MAX_PRECIO 999999

typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	float precio;
	int tipoPasajero; //Puede ser un int, con defines para cada tipo y usar conversores
	char codigoVuelo[CODIGO_LEN];
	char estadoVuelo[ESTADO_LEN];
}Passenger;

int Passenger_inicializarArrayPunteros(Passenger* arrayPunteros[],int limite);//, int indice, int* idPasajero);
int Passenger_conversorTipoPasajero(char* tipoPasajeroStr,int* tipoPasajero);
int Passenger_getEmptyIndexArrayPunteros(Passenger* array[],int limite);
int Passenger_altaConPunteros(Passenger* arrayPunteros[], int limite, int indice, int* idPasajero);
int Passenger_buscarPorIdArray(Passenger* arrayPunteros[],int limite, int id);
int Passenger_deleteIndexInArray(Passenger* arrayPunteros[],int indice);
int Passenger_borrarPorIdArray(Passenger* arrayPunteros[],int limite, int id);



// DADAS

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* codigoStr,char* precio,char* estado);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

void Passenger_printOne(Passenger* unPasajero);

int Passenger_SortApellido(void* item1,void* item2);
int Passenger_SortId(void* item1,void* item2);
int Passenger_SortCodigoVuelo(void* item1,void* item2);

//int Passenger_printArray(Passenger* arrayPunteros[],int limite);
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_conversorTipoPasajeroReverse(char* tipoPasajeroStr,int *tipoPasajeroInt);

#endif /* PASSENGER_H_ */
