#include "Flight.h"

int eFlight_init(eFlight arrayFlights[], int tam) {
	int retorno = 0;
	int i;

	if (arrayFlights != NULL) {
		if (tam > 0) {
			for (i = 0; i < tam; i++) {
				arrayFlights[i].isEmpty = LIBRE;
			}
		} else {
			retorno = -2;
		}
	} else {
		retorno = -1;
	}
	return retorno;
}

int eFlight_findEmptyIndex(eFlight arrayFlights[], int tam) {
	int retorno = 0;
	int flag = 0;
	int i;

	if (arrayFlights != NULL) {
		if (tam > 0) {
			for (i = 0; i < tam; i++) {
				if (arrayFlights[i].isEmpty == LIBRE) {
					flag = 1;
					retorno = i;
					break;
				}
			}

			if (flag == 0) {
				retorno = -1; //Array lleno
			}
		} else {
			retorno = -2; //tamaño array 0 o negativo
		}
	} else {
		retorno = -3; //array NULL
	}
	return retorno;
}

int eFlight_charIdExists(eFlight arrayFlights[], int tamFlights, char charId[])
{
	int rtn = -1;
	if(arrayFlights != NULL && tamFlights >= 0)
	{
		for(int i = 0; i < tamFlights; i++)
		{
			if(arrayFlights[i].isEmpty==OCUPADO)
			{
				if(strcmp(arrayFlights[i].flycode,charId)==0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}else{
		rtn = -2;
	}
	return rtn;
}

void eFlight_printOne(eFlight f) {
	printf("FLY CODE: %s \n"
		"FLIGHT STATUS: %d \n"
		"\n", f.flycode, f.statusFlight);
}

int eFlight_printMult(eFlight arrayFlights[], int tam, int estado) {
	int retorno = 1;
	int i;

	if (arrayFlights != NULL) {
		if (tam > 0) { //OK
			for (i = 0; i < tam; i++) {
				if (arrayFlights[i].isEmpty == estado) {
					eFlight_printOne(arrayFlights[i]);
				}
			}
		} else {
			retorno = -2;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int eFlight_printMultFiltStatus(eFlight arrayFlights[], int tam, int estado, int filtro) {
	int retorno = 1;
	int i;

	if (arrayFlights != NULL) {
		if (tam > 0) { //OK
			for (i = 0; i < tam; i++) {
				if (arrayFlights[i].isEmpty == estado && arrayFlights[i].statusFlight == filtro) {
					eFlight_printOne(arrayFlights[i]);
				}
			}
		} else {
			retorno = -2;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int eFlight_checkFlightStatus(eFlight arrayFlights[], int tam, char codeToCheck[]) {
	int retorno = -1;
	int i;

	if (arrayFlights != NULL) {
		if (tam > 0) {
			for (i = 0; i < tam; i++) {
				if (arrayFlights[i].isEmpty == OCUPADO && strncmp(arrayFlights[i].flycode, codeToCheck, TAM_FLYCODE)==0) {
					retorno = arrayFlights[i].statusFlight;
				} else {
					retorno = -3; //
					puts("No se pudo verificar");
				}
			}
		} else {
			retorno = -2;
		}
	} else {
		retorno = -1;
	}
	return retorno;
}

int eFlight_SortByFlyCode(eFlight array[], int TAM, int criterio) {
	int retorno = 0;
	int i;
	int j;
	eFlight aux;

	//USAR 1 y -1 PARA ORDEN

	if (array != NULL && TAM > 0) { //Si existe array y límite es válido
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					if (array[i].isEmpty == OCUPADO //Verifico que ambos tengan estado "ocupado"
					&& array[j].isEmpty == OCUPADO) {
						if (strcmp(array[i].flycode, array[j].flycode) > 0) { //Criterio de ordenamiento ASCENDENTE
							aux = array[i]; //Intercambio posiciones
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					if (array[i].isEmpty == OCUPADO //Verifico que ambos tengan estado "ocupado"
					&& array[j].isEmpty == OCUPADO) {
						if (strcmp(array[i].flycode, array[j].flycode) > 0) { //Criterio de ordenamiento DESCENDENTE
							//Intercambio posiciones
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		default:
			retorno = 0; //Error en criterio de ordenamiento
			break;
		}
	}
	return retorno;
}

/*
 * NO UTILIZADAS
 *
int retUniqueFlightCodes(eFlight arrayFlights[], int tamFlights, char* arrayNuevo){
	int rtn = -1;
	char arrayUnicos[tamFlights][TAM_FLYCODE];
	int contador = 0;

	if(arrayFlights != NULL){
		if(tamFlights >0){
			rtn = 0;
			eFlight_SortByFlyCode(arrayFlights, tamFlights, -1);
			for(int i = 0; i < tamFlights ; i++)
			{
				if(strcmp(arrayFlights[i].flycode,arrayFlights[i-1].flycode)!=0)
				{
					strcpy(arrayUnicos[i],arrayFlights[i].flycode);
					contador++;
				}
			}
		}
	}
	rtn = 0;
	return rtn;
}
*/
