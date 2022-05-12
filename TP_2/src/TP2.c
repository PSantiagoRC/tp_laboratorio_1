#define CANT_PASSENGERS 2000
#define CANT_FLIGHTS 2000
#define TAM_NOMBRES 51
#define TAM_FLYCODE 6

#define ACTIVO 0
#define DEMORADO 1
#define CANCELADO 2

#define LIBRE 0
#define OCUPADO 2
#define BAJA 1

#define CHILD 0
#define ADULT 1

#include "UTN4.h"
#include "Passenger_Flight.h"

int main(void) {
	setbuf(stdout, NULL);

	int retorno = 0;
	ePassenger arrayPassengers[CANT_PASSENGERS];
	eFlight arrayFlights[CANT_FLIGHTS];
	ePassenger_init(arrayPassengers, CANT_PASSENGERS);
	eFlight_init(arrayFlights, CANT_FLIGHTS);

	int flag = 0;
	int opcionMenu1;
	int opcionMenu2;

	do {
		opcionMenu1 = printMenuGetOption(
				"************************\n\n"
				"**** MENU PRINCIPAL ****\n\n"
				"************************\n\n",
				"1) ALTA DE PASAJERO\n"
				"\n"
				"2) MODIFICACION DE PASAJERO\n"
				"\n"
				"3) BAJA DE PASAJERO\n"
				"\n"
				"4) INFORMES\n"
				"\n"
				"5) SALIR\n\n", "Error. Seleccione opción de 1 a 5.\n", 3, 5);

		switch (opcionMenu1) {
		case 1:
		    if(rel_Pass_Flight_alta(arrayPassengers, arrayFlights, CANT_PASSENGERS, CANT_FLIGHTS)>=0)
		    	{
		    		flag = 1;
		    		break;
		    	}else{
		    		puts("Error.\n");
					break;
		    	}
		case 2:
			if (flag == 1) {
				puts("MODIFICACION DE PASAJERO\n");
				puts("INGRESE ID A MODIFICAR\n");
				rel_Pass_Flight_edit(arrayPassengers, CANT_PASSENGERS, arrayFlights, CANT_FLIGHTS);
				break;
			} else {
				puts("NO HAY PASAJEROS DADOS DE ALTA\n");
				break;
			}
		case 3:
			if (flag == 1) {
				puts("BAJA DE PASAJERO\n\n");
				if(ePassenger_baja(arrayPassengers, CANT_PASSENGERS, -1)>=0)
					{
						break;
					}else{
						puts("Error.\n");
						break;
					}
				break;
			} else {
				puts("NO HAY PASAJEROS DADOS DE ALTA\n");
				break;
			}
		case 4:
			if (flag == 1) {
				opcionMenu2 =
						printMenuGetOption("**** INFORMES ****\n",
								"1) Listado de pasajeros (ordenados A-Z)\n" //ordenados alfabéticamente por Apellido y Tipo
										"2) Total y promedio de precios de pasajes. Cantidad de pasajeros sobre el precio promedio.\n"
										"3) Listado de pasajeros por código de vuelo, vuelos activos.\n\n",
								"Error. Reingrese.\n", 3, 4);
				switch (opcionMenu2) {
				case 1:
					puts("\nLISTADO DE PASAJEROS\n");
					ePassenger_SortByPassengerType(arrayPassengers,
					CANT_PASSENGERS, 1); //1 descendente, inicialmente lo teniamos ascendente en carga forzada
					ePassenger_SortByLastName(arrayPassengers,
					CANT_PASSENGERS, 1); //A-Z, falla si pusieron apellido con minuscula
					ePassenger_printMult(arrayPassengers, CANT_PASSENGERS,
					OCUPADO);
					break;
				case 2:
					ePassenger_aboveMeanPrice(arrayPassengers, CANT_PASSENGERS, OCUPADO);
					break;
				case 3:
					//reta = eFlight_charIdExists(arrayFlights, CANT_FLIGHTS, "abc1");
					//printf("El retorno es %d", reta);
					//eFlight_printMult(arrayFlights, CANT_FLIGHTS, OCUPADO);
					rel_Pass_Flight_ListaPassengersPorFlycode(arrayPassengers, CANT_PASSENGERS, arrayFlights, CANT_FLIGHTS, 1);
					break;
				default:
					break;
				}
				break;
			} else {
				puts("NO HAY PASAJEROS DADOS DE ALTA.\n");
				break;
			}
		case 5:
			puts("SALIENDO DEL APLICATIVO...\n");
			retorno = -1;
			break;
		default:
			break;
		}
	} while (retorno != -1);
}
