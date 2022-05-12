#include "Passenger_Flight.h"

static int idAuto = 10000;
static int rel_Passenger_getId(void);
static int rel_Passenger_getId() {
	return idAuto++;
}

int rel_Pass_Flight_alta(ePassenger arrayPassengers[], eFlight arrayFlights[],
		int tamPassengers, int tamFlights) {
	int retorno = 0;
	int emptyIndexPassengers;
	int emptyIndexFlights;
	int retLoad;
	ePassenger passengerBuffer;
	eFlight flightBuffer;

	emptyIndexPassengers = ePassenger_findEmptyIndex(arrayPassengers,
			tamPassengers); //Ret index libre o -1 si no hay
	emptyIndexFlights = eFlight_findEmptyIndex(arrayFlights, tamFlights); //Ret index libre o -1 si no hay

	if (arrayPassengers != NULL && arrayFlights != NULL) {
		if (tamPassengers > 0 && tamFlights > 0) {
			if (emptyIndexPassengers >= 0 && emptyIndexFlights >= 0) {
				retLoad = ePassenger_loadPassenger(&passengerBuffer); //Carga nom, ap, price,fk_flycode, type
				if(retLoad == -2){
					utn_getInt(
							"Ingrese estado del vuelo: (0)ACTIVO, (1)DEMORADO, (2) CANCELADO\n",
							"Error. Reingrese.\n", 0, 2, 3,
							&flightBuffer.statusFlight);

					passengerBuffer.PK_id = rel_Passenger_getId();

					passengerBuffer.isEmpty = OCUPADO; //Switch state a ocupado.
					flightBuffer.isEmpty = OCUPADO; //Switch state a ocupado.

					if (valid_siNo(
							"ESTÁ SEGURO DE QUE DESEA REALIZAR EL ALTA? S/N\n",
							"Error. Ingrese S o N.\n", 3)) {

						if (addPassenger(&arrayPassengers[emptyIndexPassengers],
								tamPassengers, passengerBuffer.PK_id,
								passengerBuffer.name, passengerBuffer.lastName,
								passengerBuffer.price,
								passengerBuffer.typePassenger,
								passengerBuffer.FK_flycode) == 0) {

							puts("Carga de pasajero exitosa!");
							printf("Prueba, nombre cargado: %s",arrayPassengers[emptyIndexPassengers].name);
						}
						//arrayPassengers[emptyIndexPassengers] = passengerBuffer;
						if (eFlight_charIdExists(arrayFlights, tamFlights,
								flightBuffer.flycode) != 0) //Ya existe el vuelo en array
								{
							arrayFlights[emptyIndexFlights] = flightBuffer;
							puts("Carga de vuelo exitosa!");
						}else{
							arrayFlights[emptyIndexFlights] = flightBuffer;
							puts("Carga de vuelo exitosa!");
							strcpy(flightBuffer.flycode, passengerBuffer.FK_flycode);
					}
				} else {
					puts("Se decidió no dar el alta");
					retorno = -5; //No quiso dar el alta
				}
			} else {
				puts("Falla en la carga");
				retorno = -4; //Falla en loadPassenger
			}
		} else {
			puts("Base completa");
			retorno = -3; //Array lleno
			}
		} else {
			puts("Tamaño de base insuficiente.");
			retorno = -2; // Len mal definido
		}
	} else {
		puts("Error en base provista.");
		retorno = -1; // Array Null
	}
	return retorno;
}

int rel_Pass_Flight_edit(ePassenger arrayPassengers[], int tamPassengers,
		eFlight arrayFlights[], int tamFlights) {
	int retorno = 0;
	int passengerIndexToEdit;
	int emptyIndexFlights;
	int flagChangeFlyCode = 0;
	ePassenger passengerBuffer;
	eFlight flightBuffer;

	if (arrayPassengers != NULL && arrayFlights != NULL) {
		if (tamPassengers > 0 && tamFlights > 0) {
			passengerIndexToEdit = ePassenger_findIndexById(arrayPassengers,
					tamPassengers,0); //Busca index por ID - Retorna -1 si el ID no se encuentra en el array
			if (passengerIndexToEdit < 0) { //No se encontró el index
				retorno = -1;
			} else {
				passengerBuffer = arrayPassengers[passengerIndexToEdit];
				passengerBuffer = ePassenger_editOnePassenger(passengerBuffer,
						&flagChangeFlyCode); //Modifica
				if (flagChangeFlyCode != 0) {
					emptyIndexFlights = eFlight_findEmptyIndex(arrayFlights,
							tamFlights); //Ret index libre o -1 si no hay

					if (arrayFlights != NULL) {
						if (tamFlights > 0) {
							if (emptyIndexFlights >= 0) {

								strcpy(flightBuffer.flycode,
										passengerBuffer.FK_flycode);
								utn_getInt(
										"Ingrese estado del vuelo correspondiente al nuevo código:\n"
												"(0)ACTIVO, (1)DEMORADO, (2)CANCELADO\n",
										"Error. Reingrese.\n", 0, 2, 3,
										&flightBuffer.statusFlight);

								flightBuffer.isEmpty = OCUPADO; //Switch state a ocupado.
								if (valid_siNo(
										"ESTÁ SEGURO DE QUE DESEA MODIFICAR? S/N\n",
										"Error. Ingrese S o N.\n", 3)) {
									arrayPassengers[passengerIndexToEdit] =
											passengerBuffer;
									arrayFlights[emptyIndexFlights] =
											flightBuffer;
									puts(
											"Se modificó la información correspondiente al ID ingresado.\n");
								} else {
									retorno = -7; // Decidió no modificar
								}
							} else {
								retorno = -6; //No se encontró indice libre en flights
							}
						} else {
							retorno = -5; 	// tamFlights <= 0
						}
					}

				} else {
					if (valid_siNo("ESTÁ SEGURO DE QUE DESEA MODIFICAR? S/N\n",
							"Error. Ingrese S o N.\n", 3)) {
						arrayPassengers[passengerIndexToEdit] = passengerBuffer;
					}
				}
			}
		} else {
			retorno = -3; // tamPass o tamFlights <=0
		}
	} else {
		retorno = -2; // arrayPassengers NULL
	}
	return retorno;
}

int rel_Pass_Flight_ListaPassengersPorFlycode(ePassenger arrayPassengers[],
		int tamPassengers, eFlight arrayFlights[], int tamFlights, int criterio) {
	int rtn = 0;
	char targetFlycode[TAM_FLYCODE];
	char prevFlycode[TAM_FLYCODE];

	if (arrayPassengers != NULL) {
		if (arrayFlights != NULL) {
			if (tamPassengers >= 0 && tamFlights >= 0) {
				puts(
						"|------+------------------+------------------+--------+----------+----------|");
				puts(
						"|  ID  |       NAME       |    LAST NAME     |  PRICE | FLY CODE |    TYPE  |");
				puts(
						"|------+------------------+------------------+--------+----------+----------|");

				eFlight_SortByFlyCode(arrayFlights, tamFlights, criterio);

				for (int i = 0; i < tamFlights; i++) {
					if (arrayFlights[i].statusFlight == 0
							&& arrayFlights[i].isEmpty == OCUPADO) {
						strncpy(targetFlycode, arrayFlights[i].flycode,
						TAM_FLYCODE);
						strncpy(prevFlycode, arrayFlights[i - 1].flycode,
						TAM_FLYCODE);

						if (strcmp(targetFlycode, prevFlycode) != 0) {
							puts(
									"|------+------------------+------------------+--------+----------+----------|");
							printf(
									"|VUELO: %-10s        +                  +        +          +          |\n",
									targetFlycode);
							puts(
									"|------+------------------+------------------+--------+----------+----------|");
						}
						for (int j = 0; j < tamPassengers; j++) {
							if (strcmp(targetFlycode,
									arrayPassengers[j].FK_flycode) == 0
									&& arrayPassengers[j].isEmpty == OCUPADO) {
								ePassenger_printOne(arrayPassengers[j]);
								puts(
										"|------+------------------+------------------+--------+----------+----------|");
							}
						}
					}
				}
			} else {
				rtn = -3; //Problema en tamaños
			}
		} else {
			rtn = -2; //arrayFlights NULL
		}
	} else {
		rtn = -1; //arrayPassengers NULL
	}
	return rtn;
}

/*
 * NO UTILIZADAS
 *
void rel_hardcode(ePassenger *arrayPassengers, eFlight *arrayFlights) {
	//HARDCODE 1
	arrayPassengers[0].PK_id = 10096;
	strcpy(arrayPassengers[0].name, "Pedro");
	strcpy(arrayPassengers[0].lastName, "Perez");
	arrayPassengers[0].price = 100;
	strcpy(arrayPassengers[0].FK_flycode, "abc25");
	arrayPassengers[0].typePassenger = CHILD;
	arrayPassengers[0].isEmpty = OCUPADO;

	strcpy(arrayFlights[0].flycode, "abc25");
	arrayFlights[0].statusFlight = ACTIVO;
	arrayFlights[0].isEmpty = OCUPADO;

	//HARDCODE 2
	arrayPassengers[1].PK_id = 10097;
	strcpy(arrayPassengers[1].name, "Juan");
	strcpy(arrayPassengers[1].lastName, "Riquelme");
	arrayPassengers[1].price = 200;
	strcpy(arrayPassengers[1].FK_flycode, "def2");
	arrayPassengers[1].typePassenger = ADULT;
	arrayPassengers[1].isEmpty = OCUPADO;

	strcpy(arrayFlights[1].flycode, "def2");
	arrayFlights[1].statusFlight = ACTIVO;
	arrayFlights[1].isEmpty = OCUPADO;

	//HARDCODE 3
	arrayPassengers[2].PK_id = 10098;
	strcpy(arrayPassengers[2].name, "Antonio");
	strcpy(arrayPassengers[2].lastName, "Hopkins");
	arrayPassengers[2].price = 300;
	strcpy(arrayPassengers[2].FK_flycode, "ghi13");
	arrayPassengers[2].typePassenger = ADULT;
	arrayPassengers[2].isEmpty = OCUPADO;

	strcpy(arrayFlights[2].flycode, "ghi13");
	arrayFlights[2].statusFlight = DEMORADO;
	arrayFlights[2].isEmpty = OCUPADO;

	//HARDCODE 4
	arrayPassengers[3].PK_id = 10099;
	strcpy(arrayPassengers[3].name, "Roberto");
	strcpy(arrayPassengers[3].lastName, "Gomez");
	arrayPassengers[3].price = 3000;
	strcpy(arrayPassengers[3].FK_flycode, "abc1");
	arrayPassengers[3].typePassenger = ADULT;
	arrayPassengers[3].isEmpty = OCUPADO;

	strcpy(arrayFlights[3].flycode, "abc1");
	arrayFlights[3].statusFlight = ACTIVO;
	arrayFlights[3].isEmpty = OCUPADO;

	//HARDCODE 5
	arrayPassengers[4].PK_id = 10100;
	strcpy(arrayPassengers[4].name, "Matias");
	strcpy(arrayPassengers[4].lastName, "Martin");
	arrayPassengers[4].price = 600;
	strcpy(arrayPassengers[4].FK_flycode, "jbl89");
	arrayPassengers[4].typePassenger = CHILD;
	arrayPassengers[4].isEmpty = OCUPADO;

	strcpy(arrayFlights[4].flycode, "jbl89");
	arrayFlights[4].statusFlight = ACTIVO;
	arrayFlights[4].isEmpty = OCUPADO;

	//HARDCODE 6 (sin alta flight)
	arrayPassengers[5].PK_id = 10101;
	strcpy(arrayPassengers[5].name, "Pedro");
	strcpy(arrayPassengers[5].lastName, "Martin");
	arrayPassengers[5].price = 900;
	strcpy(arrayPassengers[5].FK_flycode, "jbl89");
	arrayPassengers[5].typePassenger = ADULT;
	arrayPassengers[5].isEmpty = OCUPADO;
}
*/
