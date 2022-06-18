#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int retParser;
	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && ll_len(pArrayListPassenger)==0){
		if(!(retParser = parser_PassengerFromText(pFile,pArrayListPassenger))){
			//OK!
		}else{
			if(retParser == -2){
				puts("Puntero devuelto por newParametros es NULL.");
				retorno = -2;
			}else{
				if(retParser == -1){
					puts("Archivo cerrado o array NULL");
					retorno = -1;
				}
			}
		}
	}else{
		puts("No se pudo abrir el archivo o ya existen datos en Array");
		retorno = -3;
	}
	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int retParser;
	FILE* pFile = fopen(path, "rb");

	if(pFile != NULL && ll_len(pArrayListPassenger)==0){
		if(!(retParser = parser_PassengerFromText(pFile,pArrayListPassenger))){
			//OK!
		}else{
			if(retParser == -2){
				puts("Puntero devuelto por newParametros es NULL.");
				retorno = -2;
			}else{
				if(retParser == -1){
					puts("Archivo cerrado o array NULL");
					retorno = -1;
				}
			}
		}
	}else{
		puts("No se pudo abrir el archivo o ya existen datos en Array");
		retorno = -3;
	}
	fclose(pFile);
	return retorno;
}

int controller_buscaMaxId(LinkedList* pArrayListPassenger){
	int retorno = -1;
	int flagMaxId = 1;
	int maxId;
	int id;
	Passenger* p;
	if(pArrayListPassenger!=NULL && ll_len(pArrayListPassenger)>0){
		for(int i = 0;i<ll_len((pArrayListPassenger));i++){
			if((p = ll_get(pArrayListPassenger, i))!= NULL){
				if(!Passenger_getId(p, &id)){
					if(flagMaxId || id>maxId){
						flagMaxId = 0;
						maxId = id;
						retorno = maxId;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	int id;
	char nombre[100];
	char apellido[100];
	char estadoVuelo[100];
	int tipoPasajero;
	float precio;
	char codigo[100];

	if(pArrayListPassenger!=NULL){
		Passenger* pP = Passenger_new();


		if( !utn_getStringWONumFirstUpper("\nIngrese nombre (inicie Mayusc)", "\nError. Reingrese.", 3, NOMBRE_LEN, nombre) &&
			!utn_getStringWONumFirstUpper("\nIngrese apellido (inicie Mayusc)", "\nError. Reingrese.", 3, APELLIDO_LEN, apellido) &&
			!utn_getFloat(&precio, "\nIngrese precio", "\nError. Reingrese.", 0, MAX_PRECIO, 3) &&
			!utn_getInt("\nIngrese tipo pasajero: Economy(0), Executive(1), First(2)", "\nError. Ingrese el número de la opción correspondiente.", 0, 2, 3, &tipoPasajero) &&
			!utn_getStringWNum("\nIngrese codigo de vuelo", "\nError. Reingrese.", 3, CODIGO_LEN, codigo) &&
			!utn_getStringWONum("\nIngrese estado de vuelo: Demorado/En Vuelo/Aterrizado", "\nError. Reingrese.", 3, ESTADO_LEN, estadoVuelo)){

			if(ll_len(pArrayListPassenger)==0){
				id = 1; //o sea 1
			}else{
				if(controller_buscaMaxId(pArrayListPassenger)>0){
					id = controller_buscaMaxId(pArrayListPassenger)+1;//función que recorre la linkedList y busca el mayor indice
				}
			}

			if(	!Passenger_setId(pP, id) &&
				!Passenger_setNombre(pP, nombre)&&
				!Passenger_setApellido(pP, apellido)&&
				!Passenger_setEstadoVuelo(pP, estadoVuelo)&&
				!Passenger_setTipoPasajero(pP, tipoPasajero)&&
				!Passenger_setPrecio(pP, precio)&&
				!Passenger_setCodigoVuelo(pP, codigo)&&
				pP!=NULL){

				ll_add(pArrayListPassenger, pP);
				retorno = 0;
			}
		}else{
			retorno = -1;
		}
	}else{
		retorno = -2;
	}
	return retorno;
}

int controller_buscarPorIdLinkedList(LinkedList* arrayPunteros, int id){
	int retorno = -1;
	int i;
	int index;
	Passenger* p;

	if(arrayPunteros != NULL && id >= 0)
	{
		for(i=0;i<ll_len(arrayPunteros);i++){
			p = ll_get(arrayPunteros, i);
			if(p!=NULL && p->id == id){
				index = ll_indexOf(arrayPunteros, p);
				retorno = index;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
	int retorno = 1;

	int Id;
	int indexModif;
	int opc;
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	float precio;
	char codigoVuelo[CODIGO_LEN];
	int tipoPasajero;
	char estadoVuelo[ESTADO_LEN];

	Passenger* p = NULL;

	if (pArrayListPassenger != NULL)
	{

		if(!utn_getInt("\nIngrese ID a modificar.\n", "\nError.Reingrese.\n", 1, 5000, 3, &Id))
		{
			indexModif = controller_buscarPorIdLinkedList(pArrayListPassenger, Id);
			p = (Passenger*) ll_get(pArrayListPassenger, indexModif);
			if(!utn_getInt("\nSeleccione campo a modificar:\n"
							"1)Nombre\n"
							"2)Apellido\n"
							"3)Precio\n"
							"4)Codigo de vuelo\n"
							"5)Tipo de pasajero\n"
							"6)Estado de vuelo\n", "\nError.Reingrese.\n", 1, 6, 3, &opc)){
				switch(opc){
					case 1:
						if(!utn_getStringWONumFirstUpper("\nIngrese nombre (inicie Mayusc)", "\nError. Reingrese.", 3, NOMBRE_LEN, nombre))
						{
							if(!Passenger_setNombre(p, nombre))
							{
								retorno = 0;
							}
						}
						break;
					case 2:
						if(!utn_getStringWONumFirstUpper("\nIngrese apellido (inicie Mayusc)", "\nError. Reingrese.", 3, APELLIDO_LEN, apellido))
						{
							if(!Passenger_setApellido(p, apellido))
							{
								retorno = 0;
							}
						}
						break;
					case 3:
						if(!utn_getFloat(&precio, "\nIngrese precio", "\nError. Reingrese.", 0, MAX_PRECIO, 3))
						{
							if(!Passenger_setPrecio(p, precio))
							{
								retorno = 0;
							}
						}
						break;
					case 4:
						if(!utn_getStringWNum("\nIngrese codigo de vuelo", "\nError. Reingrese.", 3, CODIGO_LEN, codigoVuelo))
						{
							if(!Passenger_setCodigoVuelo(p, codigoVuelo))
							{
								retorno = 0;
							}
						}
						break;
					case 5:
						if(!utn_getInt("\nIngrese tipo pasajero: Economy(0), Executive(1), First(2)", "\nError. Ingrese el número de la opción correspondiente.", 0, 2, 3, &tipoPasajero))
						{
							if(!Passenger_setTipoPasajero(p, tipoPasajero))
							{
								retorno = 0;
							}
						}
						break;
					case 6:
						if(!utn_getStringWONum("\nIngrese estado de vuelo: Demorado/En Vuelo/Aterrizado", "\nError. Reingrese.", 3, ESTADO_LEN, estadoVuelo))
						{
							if(!Passenger_setEstadoVuelo(p, estadoVuelo))
							{
								retorno = 0;
							}
						}
						break;
					default:
						break;
				}
			}else{
				retorno = -1;
			}
		}else{
			retorno = -2;
		}
	}else{
		retorno = -3;
	}
	return retorno;
}



/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger* p;
	int cantidad;
	cantidad = ll_len(pArrayListPassenger); // 3;//

	if(pArrayListPassenger != NULL){
		printf("\n|--------------------------------------------------------------------------------------------------------------------|\n");
		printf("|    ID    |     NOMBRE    |    APELLIDO   |  PRECIO  |       ESTADO       |        TIPO        |       CODIGO       |\n");
		printf("|--------------------------------------------------------------------------------------------------------------------|\n");

		for(int i=0; i<cantidad;i++){
			p = ll_get(pArrayListPassenger, i);
			if(p!=NULL){
				Passenger_printOne(p);
			}
		}
	}else{
		retorno = -1;
	}
	return retorno;
}



/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int idBaja;
	int indexBaja;

	if(pArrayListPassenger!=NULL){
		controller_ListPassenger(pArrayListPassenger);
		if(!utn_getInt("\nIngrese ID a dar de baja\n", "\nError.Reingrese.", 1, ll_len(pArrayListPassenger), 3, &idBaja)){
			printf("\nID a dar de baja: %d\n",idBaja);
			indexBaja = controller_buscarPorIdLinkedList(pArrayListPassenger, idBaja);
			if(indexBaja>0){
				printf("Index a dar de baja: %d\n",indexBaja);
				printf("Length de la list antes de remove: %d\n",ll_len(pArrayListPassenger));
				if(!ll_remove(pArrayListPassenger,indexBaja)){
					printf("Length de la list luego de remove: %d",ll_len(pArrayListPassenger));
					retorno = 0;
				}
			}else{
				puts("No se encontró el ID.");
			}
		}
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int opcion;

	if(pArrayListPassenger!=NULL){

		if(!utn_getInt("\nDe acuerdo a qué campo desea ordenar a los pasajeros?\n"
				"\n1)ID"
				"\n2)Apellido"
				"\n3)Codigo de vuelo\n", "\nError. Reingrese.\n", 1, 3, 3, &opcion)){

			printf("Opción %d",opcion);
		}
	}else{
		retorno = -1;
	}
	switch(opcion){
		case 1:
			ll_sort(pArrayListPassenger, Passenger_SortId, 1);
			break;
		case 2:
			ll_sort(pArrayListPassenger, Passenger_SortApellido, 1);
			break;
		case 3:
			ll_sort(pArrayListPassenger, Passenger_SortCodigoVuelo, 1);
			break;
		default:
			break;
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[100];
	char apellido[100];
	char estado[100];
	int tipoInt;
	char tipoChar[50];
	float precio;
	char codigo[100];
	FILE* fp = fopen(path,"w");
	Passenger* p;
	int tam = ll_len(pArrayListPassenger);

	if(fp!=NULL){
		fprintf(fp,"id,name,lastname,price,flycode,typePassenger,statusFlight");
		for(int i = 0;i<tam;i++){
			p = ll_get(pArrayListPassenger, i);
			if(p!=NULL){
				if(!Passenger_getId(p, &id) && !Passenger_getNombre(p, nombre) && !Passenger_getApellido(p, apellido) &&
						!Passenger_getPrecio(p, &precio) && !Passenger_getCodigoVuelo(p, codigo) && !Passenger_getEstadoVuelo(p, estado) &&
							!Passenger_getTipoPasajero(p, &tipoInt)){
					Passenger_conversorTipoPasajeroReverse(tipoChar,&tipoInt);
					fprintf(fp,"%d,%s,%s,%.2f,%s,%s,%s\n",id,nombre,apellido,precio,codigo,tipoChar,estado);
				}else{
					retorno = -5;
				}
			}else{
				retorno = -4;
			}
		}
		fclose(fp);
	}else{
		retorno = -1;
	}
    return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[100];
	char apellido[100];
	char estado[100];
	int tipoInt;
	char tipoChar[50];
	float precio;
	char codigo[100];
	FILE* fp = fopen(path,"w");
	Passenger* p;
	int tam = ll_len(pArrayListPassenger);

	if(fp!=NULL){
		fprintf(fp,"id,name,lastname,price,flycode,typePassenger,statusFlight");
		for(int i = 0;i<tam;i++){
			p = ll_get(pArrayListPassenger, i);
			if(p!=NULL){
				if(!Passenger_getId(p, &id) && !Passenger_getNombre(p, nombre) && !Passenger_getApellido(p, apellido) &&
						!Passenger_getPrecio(p, &precio) && !Passenger_getCodigoVuelo(p, codigo) && !Passenger_getEstadoVuelo(p, estado) &&
							!Passenger_getTipoPasajero(p, &tipoInt)){
					Passenger_conversorTipoPasajeroReverse(tipoChar,&tipoInt);
					fprintf(fp,"%d,%s,%s,%.2f,%s,%s,%s\n",id,nombre,apellido,precio,codigo,tipoChar,estado);
				}else{
					retorno = -3;
				}
			}else{
				retorno = -2;
			}
		}
		fclose(fp);
	}else{
		retorno = -1;
	}
    return retorno;
}


