#include "Passenger.h"

int ePassenger_init(ePassenger arrayPassengers[], int tam) {

	int retorno = 0;
	int i;

	if (arrayPassengers != NULL) {
		if (tam > 0) {
			for (i = 0; i < tam; i++) {
				arrayPassengers[i].isEmpty = LIBRE;
			}
		} else {
			retorno = -2;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

void ePassenger_printOne(ePassenger p) {
	printf("|%6d|%-18s|%-18s|%-8.2f|%-10s|", p.PK_id, p.name, p.lastName, p.price, p.FK_flycode);
			if(p.typePassenger == 0){
				printf("%-10s|\n","CHILD");
			}else{
				printf("%-10s|\n","ADULT");
			}
}

int ePassenger_printMult(ePassenger arrayPassengers[], int tam, int estado) {
	int retorno = 1;
	int i;

	if (arrayPassengers != NULL) {
		if (tam > 0) { //OK
			puts("|------+------------------+------------------+--------+----------+----------|");
			puts("|  ID  |       NAME       |    LAST NAME     |  PRICE | FLY CODE |    TYPE  |");
			puts("|------+------------------+------------------+--------+----------+----------|");
			puts("|------+------------------+------------------+--------+----------+----------|");
			for(i = 0; i < tam; i++) {
				if (arrayPassengers[i].isEmpty == estado) {
					ePassenger_printOne(arrayPassengers[i]);
					puts("|------|------------------|------------------|--------|----------|----------|");
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

int ePassenger_findEmptyIndex(ePassenger arrayPassengers[], int tam) {
	int retorno = 0;
	int flag = 0;
	int i;

	if (arrayPassengers != NULL) {
		if (tam > 0) {
			for (i = 0; i < tam; i++) {
				if (arrayPassengers[i].isEmpty == LIBRE) {
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

int ePassenger_loadPassenger(ePassenger *p) {
	int ret = 1;
	do{
			if(utn_getStringWONum("Ingrese nombre del pasajero.\n", "Error. Reingrese caracteres válidos.\n", 3, TAM_NOMBRES, p->name)==0)
			{
				ret = 0;
			}else{
				ret = -1;
				break;
			}
			if(utn_getStringWONumFirstUpper("Ingrese apellido del pasajero (inicial en mayúscula)\n", "Error. Reingrese caracteres válidos (inicial en mayúscula).\n", 3, TAM_NOMBRES, p->lastName)==0){
				ret = 0;
			}else{
				ret = -1;
				break;
			}
			if(utn_getFloat(&p->price, "Ingrese precio abonado.\n", "Error. Reingrese precio inferior a 999999. \n",	0, 999999, 3)==0){
				ret = 0;
			}else{
				ret = -1;
				break;
			}
			if(utn_getStringWNum("Ingrese código de vuelo (5 dígitos).\n", "Error. Reingrese un código válido (5 dígitos).\n", 3, TAM_FLYCODE, p->FK_flycode)==0){
				ret = 0;
			}else{
				ret = -1;
				break;
			}
			if(utn_getInt("Ingrese tipo de pasajero: (0)INFANTE, (1)ADULTO.\n", "Error. Reingrese.\n", 0, 1, 3,
					&p->typePassenger)==0){
				ret=-2;
			}else{
				ret = -1;
				break;
			}
		}while(ret >= 0);
		return ret;
}



int ePassenger_baja(ePassenger arrayPassengers[], int tam, int optId) {
	int retorno = 0;
	int indexBaja = optId;

	if (arrayPassengers != NULL) {
		if (tam > 0) {
			if(optId<=0)
			{
				indexBaja = ePassenger_findIndexById(arrayPassengers, tam, optId); //-1 si no encuentra index a dar de baja, caso contrario index buscado.
			}
			if (indexBaja < 0) {
				retorno = -1;
			} else {
				printf("Index seleccionado: %d\n", indexBaja);
				if (valid_siNo(
						"ESTÁ SEGURO DE QUE DESEA DAR DE BAJA AL PASAJERO? S/N\n",
						"Error. Ingrese S o N\n", 3)) {

					arrayPassengers[indexBaja].isEmpty = BAJA;

					puts("\n\nSE DIO DE BAJA EL PASAJERO.\n\n");
				} else {
					retorno = -2; // USUARIO NO ESTÁ SEGURO
				}
			}
		} else {
			retorno = -3; // LEN MAL DEFINIDO
		}
	} else {
		retorno = -4; // ARRAY NULO
	}
	return retorno;
}

int ePassenger_findIndexById(ePassenger arrayPassengers[], int tam, int optId) {
	int retorno = 0;
	int flag = 0;
	int i;
	int IDtoFind = optId;

	if (arrayPassengers != NULL) {
		if (tam > 0) {
			ePassenger_printMult(arrayPassengers, tam, OCUPADO); //Lista de usuarios posibles para baja

			if(optId <=0)
			{
				utn_getInt("Ingrese ID seleccionado\n0 para cancelar.",
									"Error. Reingrese.\n", 0, 99999, 3, &IDtoFind);
			}

			if (IDtoFind == 0) {
				puts("Cancelado.");
				retorno = -5;
			} else {
				if (IDtoFind == -1) {
					puts("EL INDICE NO EXISTE.\n");
				} else {
					for (i = 0; i < tam; i++) {
						if (arrayPassengers[i].isEmpty == OCUPADO) {
							if (arrayPassengers[i].PK_id == IDtoFind) {
								flag = 1;
								return i; //retorno index correspondiente al ID ingresado
								break;
							}
						}
					}
				}
			}
			if (flag == 0) {
				retorno = -1; //No se encontró
			}
		} else {
			retorno = -2; //Tamaño array <=0
		}
	} else {
		retorno = -3; //Array es NULL
	}

	return retorno;
}

ePassenger ePassenger_editOnePassenger(ePassenger p, int* flagChangeFlyCode) {
	*flagChangeFlyCode=0;
	int opcion = printMenuGetOption("\n\n**** DATO A MODIFICAR ***\n\n",
			"1) NOMBRE\n"
					"2) APELLIDO\n"
					"3) PRECIO\n"
					"4) TIPO DE PASAJERO\n"
					"5) CÓDIGO DE VUELO\n\n", "Error. Ingrese opción de 1 a 5.",
			3, 5);

	switch (opcion) {
	case 1:
		utn_getStringWONum("Ingrese nombre del pasajero\n",
				"Error. Reingrese caracteres válidos.\n", 3,
				TAM_NOMBRES, p.name);
		break;
	case 2:
		utn_getStringWONumFirstUpper("Ingrese apellido del pasajero (inicial en mayúscula)\n",
					"Error. Reingrese caracteres válidos (inicial en mayúscula).\n", 3,
					TAM_NOMBRES, p.lastName);
		break;
	case 3:
		utn_getFloat(&p.price, "Ingrese precio del vuelo.\n",
				"Error. Reingrese un precio inferior a 9999999.\n", 0.0, 9999999.0, 3);
		break;
	case 4:
		utn_getInt("Ingrese tipo de pasajero (0 para niño, 1 para adulto).\n", "Error. Reingrese.\n", 0, 5,
				3, &p.typePassenger);
		break;
	case 5:
		*flagChangeFlyCode = 1;
		utn_getStringWNum("Ingrese código de vuelo (5 digitos).\n", "Error. Reingrese un código válido (5 dígitos).\n",
				2,
				TAM_FLYCODE, p.FK_flycode);
	default:
		break;
	}
	return p;
}

int ePassenger_SortByPassengerType(ePassenger array[], int TAM, int criterio) {
	int retorno = 0;
	int i;
	int j;
	ePassenger aux;

	if (array != NULL && TAM > 0) { //Si existe array y límite es válido
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					if (array[i].isEmpty == OCUPADO //Verifico que ambos tengan estado "ocupado"
					&& array[j].isEmpty == OCUPADO) {
						if (array[i].typePassenger > array[j].typePassenger) { //Criterio de ordenamiento ASCENDENTE
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
						if (array[i].typePassenger < array[j].typePassenger) { //Criterio de ordenamiento DESCENDENTE
							aux = array[i]; //Intercambio posiciones
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

int ePassenger_SortByLastName(ePassenger array[], int TAM, int criterio) {
	int retorno = 0;
	int i;
	int j;
	ePassenger aux;

	//USAR 1 y -1 PARA ORDEN

	if (array != NULL && TAM > 0) { //Si existe array y límite es válido
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					if (array[i].isEmpty == OCUPADO //Verifico que ambos tengan estado "ocupado"
					&& array[j].isEmpty == OCUPADO) {
						if (strcmp(array[i].lastName, array[j].lastName) > 0) { //Criterio de ordenamiento ASCENDENTE
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
						if (strcmp(array[i].lastName, array[j].lastName) > 0) { //Criterio de ordenamiento DESCENDENTE
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

int ePassenger_meanPrice(ePassenger arrayPassengers[], int tam, int estado, float* total, float* promedio, int* clientes) {
	int retorno = -1;
	int i;
	int contador = 0;
	float acumulador = 0;

	if (arrayPassengers != NULL) {
		if (tam > 0) { //OK
			for(i = 0; i < tam; i++) {
				if (arrayPassengers[i].isEmpty == estado) {
					contador ++;
					acumulador += arrayPassengers[i].price;
				}
			}
			if(contador==0){
				retorno = -3;
				puts("ERROR, NO HAY CLIENTES PARA CALCULAR");
			}else{
				retorno = 0;
				*total = acumulador;
				*clientes = contador;
				*promedio = acumulador/contador;
			}
		} else {
			retorno = -2;
		}
	} else {
		retorno = -1;
	}
	return retorno;
}

int ePassenger_aboveMeanPrice(ePassenger arrayPassengers[], int tam, int estado) {
	int retorno = -1;
	int i;
	int contador = 0;
	float total;
	float promedio;
	int clientes;

	int meanPrice = ePassenger_meanPrice(arrayPassengers, tam, estado, &total, &promedio, &clientes);

	if (arrayPassengers != NULL) {
		if (tam > 0) {
			for(i = 0; i < tam; i++) {
				if (arrayPassengers[i].isEmpty == estado && meanPrice == 0 && arrayPassengers[i].price > promedio) {
					contador ++;
					retorno = 0;
				}
			}
			if(contador>-1){
				printf("\n***LA CANTIDAD DE CLIENTES DADOS DE ALTA ES: %d\n",clientes);
				printf("***PAGARON UN PRECIO PROMEDIO DE: %.2f\n",promedio);
				printf("***PARA UNA FACTURACIÓN TOTAL DE: %.2f\n",total);
				printf("***CANTIDAD DE PASAJEROS QUE PAGARON MÁS QUE EL PROMEDIO: %d\n\n",contador);
			}else{
				retorno = -3; //Error con el contador
			}
		} else {
			retorno = -2; //tamaño array nulo o neg
		}
	} else {
		retorno = -1; // array NULL
	}
	return retorno;
}

int addPassenger(ePassenger* arrayPassengersItem, int tamPassengers, int id, char name[], char lastName[],float price, int typePassenger, char flycode[])
{
	int rtn = -1;
	if(arrayPassengersItem->isEmpty == OCUPADO || tamPassengers <= 0)
	{
		puts("No hay espacio en array.");
	}else{
		arrayPassengersItem->PK_id = id;
		strncpy(arrayPassengersItem->name,name,strlen(name));
		strncpy(arrayPassengersItem->lastName,lastName,strlen(lastName));
		arrayPassengersItem->price = price;
		arrayPassengersItem->typePassenger = typePassenger;
		strncpy(arrayPassengersItem->FK_flycode,flycode,strlen(flycode));
		arrayPassengersItem->isEmpty = OCUPADO;
		rtn = 0;
	}
	return rtn;

}

/*
 * NO UTILIZADAS
 *
 int ePassenger_SortByStatusFlight(ePassenger array[], int TAM, int criterio) {
 int retorno = 0;
 int i;
 int j;
 ePassenger aux;

 //EJEMPLO DE SORT CON ID DE Passenger
 //MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
 //CASE -1 -> MENOR A MAYOR (ASCENDENTE)
 //CASE  1 -> MAYOR A MENOR (DESCENDENTE)
 //UTILIZAR strcmp(...) PARA COMPARAR CADENAS


 if (array != NULL && TAM > 0) { //Si existe array y límite es válido
 switch (criterio) {
 case -1:
 for (i = 0; i < TAM - 1; i++) {
 for (j = i + 1; j < TAM; j++) {
 if (array[i].isEmpty == OCUPADO //Verifico que ambos tengan estado "ocupado"
 && array[j].isEmpty == OCUPADO) {
 if (array[i].statusFlight > array[j].statusFlight) { //Criterio de ordenamiento ASCENDENTE
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
 if (array[i].statusFlight < array[j].statusFlight) { //Criterio de ordenamiento DESCENDENTE
 aux = array[i]; //Intercambio posiciones
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
 */
