#ifndef PASSENGER_FLIGHT_H_
#define PASSENGER_FLIGHT_H_

#include "Passenger.h"
#include "Flight.h"


int rel_Pass_Flight_alta(ePassenger arrayPassengers[], eFlight arrayFlights[],
		int tamPassengers, int tamFlights);
///	Da de alta un pasajero en su array, y el vuelo si es que no existe de un alta previa.
///
/// @fn int rel_Pass_Flight_alta(ePassenger[], eFlight[], int, int)
/// @param arrayPassengers
/// @param arrayFlights
/// @param tamPassengers
/// @param tamFlights
/// @return

int rel_Pass_Flight_edit(ePassenger arrayPassengers[], int tamPassengers, eFlight arrayFlights[], int tamFlights);
/// Edita un pasajero individual, solicitando su id al usuario.
///
/// @fn int rel_Pass_Flight_edit(ePassenger[], int, eFlight[], int)
/// @param arrayPassengers
/// @param tamPassengers
/// @param arrayFlights
/// @param tamFlights
/// @return

int rel_Pass_Flight_ListaPassengersPorFlycode(ePassenger arrayPassengers[], int tamPassengers, eFlight arrayFlights[], int tamFlights, int criterio);
/// 2.7 SORT PASSENGERS BY CODE
///
/// @fn int rel_Pass_Flight_ListaPassengersPorFlycode(ePassenger[], int, eFlight[], int)
/// @param arrayPassengers
/// @param tamPassengers
/// @param arrayFlights
/// @param tamFlights
/// @return



/*

NO UTILIZADAS
void rel_hardcode(ePassenger *arrayPassengers, eFlight *arrayFlights);
/// @fn void rel_hardcode(ePassenger*, eFlight*)
/// @param arrayPassengers
/// @param arrayFlights

//ePassenger rel_Pass_Flight_editOne(ePassenger p, eFlight f);
//int ePassenger_printMultFiltStatusFlight(ePassenger arrayPassengers[], eFlight arrayFlights[], int tam, int filter);
//int ePassenger_findFlightIndexById(ePassenger arrayFlights[], int tam)
*/

#endif /* PASSENGER_FLIGHT_H_ */
