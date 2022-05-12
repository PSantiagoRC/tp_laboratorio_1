#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <stdio.h>
#include <stdlib.h>
#include "UTN4.h"

#define ACTIVO 0
#define DEMORADO 1
#define CANCELADO 2

#define LIBRE 0
#define OCUPADO 2
#define BAJA 1

#define TAM_FLYCODE 6

struct {
	char flycode[TAM_FLYCODE];
	int statusFlight;
	int isEmpty;
}typedef eFlight;

int eFlight_init(eFlight arrayFlights[], int tam);
/// Inicializa entidad arrayFlights
///
/// @fn int eFlight_init(eFlight[], int)
/// @param arrayFlights
/// @param tam
/// @return

void eFlight_printOne(eFlight p);
/// Imprime un vuelo
///
/// @fn void eFlight_printOne(eFlight)
/// @param p

int eFlight_printMult(eFlight arrayFlights[], int tam, int estado);
/// Imprime múltiples vuelos según estado (isEmpty)
///
/// @fn int eFlight_printMult(eFlight[], int, int)
/// @param arrayFlights
/// @param tam
/// @param estado
/// @return

int eFlight_printMultFiltStatus(eFlight arrayFlights[], int tam, int estado, int filtro);
///  Imprime múltiples vuelos según estado (isEmpty) y según estado del vuelo (activo, demorado, cancelado).
///
/// @fn int eFlight_printMultFiltStatus(eFlight[], int, int, int)
/// @param arrayFlights
/// @param tam
/// @param estado
/// @param filtro
/// @return

int eFlight_findEmptyIndex(eFlight arrayFlights[], int tam);
/// Encuentra la próxima posición vacía en el array
///
/// @fn int eFlight_findEmptyIndex(eFlight[], int)
/// @param arrayFlights
/// @param tam
/// @return

int eFlight_SortByFlyCode(eFlight array[], int TAM, int criterio);
/// Ordena el array de vuelos por orden alfabético de su flycode.
///
/// @fn int eFlight_SortByFlyCode(eFlight[], int, int)
/// @param array
/// @param TAM
/// @param criterio
/// @return

int eFlight_charIdExists(eFlight arrayFlights[], int tamFlights, char charId[]);
/// Verifica que un determinado flycode exista en el array.
///
/// @fn int eFlight_charIdExists(eFlight[], int, char[])
/// @param arrayFlights
/// @param tamFlights
/// @param charId
/// @return

//NO UTILIIZADAS
//int eFlight_alta(eFlight arrayFlights[], int tam);
//eFlight eFlight_loadFlight();
//int eFlight_baja(eFlight arrayFlights[], int tam);
//int eFlight_findIndexById(eFlight arrayFlights[], int tam);

#endif /* FLIGHT_H_ */
