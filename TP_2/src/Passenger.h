/*
 * BIBLIOTECA "ARRAY PASSENGER"
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include "UTN4.h"

#define LIBRE 0
#define OCUPADO 2
#define BAJA 1

#define CHILD 0
#define ADULT 1

#define TAM_NOMBRES 51
#define TAM_FLYCODE 6
#define CANT_PASSENGERS 2000

struct {
	int PK_id;
	char name[TAM_NOMBRES];
	char lastName[TAM_NOMBRES];
	float price;
	char FK_flycode[TAM_FLYCODE];
	int typePassenger;
	int isEmpty;
}typedef ePassenger;


// EL PUNTO 2.7, SORT PASSENGERS BY CODE, SE ENCUENTRA EN LA BIBLIOTECA CORRESPONDIENTE A LA RELACION PASSENGER_FLIGHT


int ePassenger_init(ePassenger arrayPassengers[], int tam);
/// 2.1 INIT PASSENGER
///
///  @fn int ePassenger_init(ePassenger[], int)
/// @param arrayPassengers
/// @param tam
/// @return

void ePassenger_printOne(ePassenger p);
/// @fn void ePassenger_printOne(ePassenger)
/// @param p

int ePassenger_printMult(ePassenger arrayPassengers[], int tam, int estado);
///	2.6 PRINT PASSENGERS
///
/// @fn int ePassenger_printMult(ePassenger[], int, int)
/// @param arrayPassengers
/// @param tam
/// @param estado
/// @return

int ePassenger_findEmptyIndex(ePassenger arrayPassengers[], int tam);
/// Busca próxima posición disponible en el array.
///
/// @fn int ePassenger_findEmptyIndex(ePassenger[], int)
/// @param arrayPassengers
/// @param tam
/// @return

int ePassenger_alta(ePassenger arrayPassengers[], int tam); //SE UTILIZA LA FUNCIÓN ALTA CONTENIDA EN LA BIBLIOTECA DE LA RELACION "PASSENGER_FLIGHT"
/// Da de alta un pasajero en el array.
///
/// @fn int ePassenger_alta(ePassenger[], int)
/// @param arrayPassengers
/// @param tam
/// @return

int ePassenger_loadPassenger();
/// Carga los datos de un pasajero previo a su alta
///
/// @fn ePassenger ePassenger_loadPassenger()
/// @return

int ePassenger_baja(ePassenger arrayPassengers[], int tam, int optId);
/// 2.4 REMOVE PASSENGER
///
///  @fn int ePassenger_baja(ePassenger[], int)
/// @param arrayPassengers
/// @param tam
/// @return

int ePassenger_findIndexById(ePassenger arrayPassengers[], int tam, int optId);
/// 2.3 FIND PASSENGER BY ID
///
///  @fn int ePassenger_findIndexById(ePassenger[], int)
/// @param arrayPassengers
/// @param tam
/// @return

ePassenger ePassenger_editOnePassenger(ePassenger p,int* flagChangeFlyCode);
/// @fn ePassenger ePassenger_editOnePassenger(ePassenger, int*)
/// @param p
/// @param flagChangeFlyCode
/// @return

int ePassenger_SortByPassengerType(ePassenger array[], int TAM, int criterio);
/// Ordena el array de pasajeros según su tipo (adulto o niño) criterio ascendente o descendente.
///
/// @fn int ePassenger_SortByPassengerType(ePassenger[], int, int)
/// @param array
/// @param TAM
/// @param criterio
/// @return

int ePassenger_SortByLastName(ePassenger array[], int TAM, int criterio);
/// Ordena el array de pasajeros por su apellido, criterio ascendente o descendente.
///
/// @fn int ePassenger_SortByLastName(ePassenger[], int, int)
/// @param array
/// @param TAM
/// @param criterio
/// @return

int ePassenger_meanPrice(ePassenger arrayPassengers[], int tam, int estado, float* total, float* promedio, int* clientes);
/// Calcula el precio promedio y lo muestra, junto con total y cantidad por encima del promedio.
///
/// @fn int ePassenger_meanPrice(ePassenger[], int, int, float*, float*, int*)
/// @param arrayPassengers
/// @param tam
/// @param estado
/// @param total
/// @param promedio
/// @param clientes
/// @return

int ePassenger_aboveMeanPrice(ePassenger arrayPassengers[], int tam, int estado);
/// Calcula cantidad de pasajeros que pagaron más que el promedio
///
/// @fn int ePassenger_aboveMeanPrice(ePassenger[], int, int)
/// @param arrayPassengers
/// @param tam
/// @param estado
/// @return

int addPassenger(ePassenger* arrayPassengersItem,int tamPassengers, int id, char name[], char lastName[],float price, int typePassenger, char flycode[]);
///	Agrega un pasajero de manera manual, sin pedir datos por consola.
///
/// @fn int addPassenger(ePassenger, int, int, char[], char[], float, int, char[])
/// @param arrayPassengersItem
/// @param tamPassengers
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @return


/*
NO UTILIZADAS
int ePassenger_SortByStatusFlight(ePassenger array[], int TAM, int criterio);
int ePassenger_printMultFiltStatusFlight(ePassenger arrayPassengers[], int tam,
		int filter);
*/

#endif /* ARRAYPASSENGER_H_ */
