#include "Passenger.h"
#include <ctype.h>
#include <stdio.h>

/*
static int idAutoPassenger = get_MaxId(Passenger* array);
static int Passenger_getAutoId(void);
static int Passenger_getAutoId() {
	return idAutoPassenger++;
}
*/

int Passenger_inicializarArrayPunteros(Passenger* array[],int limite){
//Inicializa un array lleno de punteros a entidades Passenger, con punteros a NULL, la "posicion 0".

	int retorno = -1;
	int i;
	if(array!=NULL && limite >0){
		retorno = 0;
		for(i=0;i<limite;i++){
			array[i]=NULL; //C automaticamente lo castea como (void * ), NULL es un puntero a posicion 0.
		}
	}
	return retorno;
}

int Passenger_getEmptyIndexArrayPunteros(Passenger* array[],int limite){
	int retorno = -1;
	int i;
	if(array!=NULL && limite>0)
	{
		for(i=0;i<limite;i++){
			if(array[i] == NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int Passenger_deleteIndexInArray(Passenger* arrayPunteros[],int indice)
{
	int retorno=-1;
	if(arrayPunteros != NULL && indice>=0 && arrayPunteros[indice] != NULL){ //Clave indice pueda ser 0! Si no no puedo dar de baja el primer pasajero!
		retorno = 0;
		free(arrayPunteros[indice]); // Libero el espacio de memoria
		arrayPunteros[indice] = NULL; //Si no apunto ese puntero del array a NULL,
										//sigue apuntando ahí, puedo volver a asignarlo eventualmente, PERO
										//lo voy a seguir mostrando en mis prints con basura! (es como volver a inicializarlo)
	}
	return retorno;
}

int Passenger_buscarPorIdArray(Passenger* arrayPunteros[],int limite, int id){
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && limite >0 && id >= 0)
	{
		retorno =-2;
		for(i=0;i<limite;i++){
			if(arrayPunteros[i] != NULL && arrayPunteros[i]->id == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int Passenger_borrarPorIdArray(Passenger* arrayPunteros[],int limite, int id){
	int retorno = -1;
	int indiceBorrar;
	if(arrayPunteros != NULL && limite >0 && id >= 0)
	{
		indiceBorrar = Passenger_buscarPorIdArray(arrayPunteros, limite, id);
		if(!Passenger_deleteIndexInArray(arrayPunteros, indiceBorrar)){
			retorno = 0;
		}
	}
	return retorno;
}

Passenger* Passenger_new(){
	Passenger* p;
	p = (Passenger*) malloc(sizeof(Passenger)*1);
	if(p!=NULL){
		p->id = 0;
		p->nombre[0]='\0'; //es el final de un string (en este caso vacío)
		p->apellido[0]='\0';
		p->codigoVuelo[0]='\0';
		p->estadoVuelo[0]='\0';
		p->precio=0;
		p->tipoPasajero=0;

	}
	return p; //Obtenemos una dirección de memoria a una entidad de pasajero
}

int Passenger_conversorTipoPasajero(char* tipoPasajeroStr,int *tipoPasajero){
	int retorno = 0;
	if(strcmp(tipoPasajeroStr,"EconomyClass")==0){
		*tipoPasajero = ECONOMY_CLASS;
	}else{
		if(strcmp(tipoPasajeroStr,"ExecutiveClass")==0){
			*tipoPasajero = EXECUTIVE_CLASS;
		}else{
			if(strcmp(tipoPasajeroStr,"FirstClass")==0){
						*tipoPasajero = FIRST_CLASS;
			}else{
				*tipoPasajero = ERROR_CLASS;
				retorno = -1;
			}
		}
	}
	return retorno;
}

int Passenger_conversorTipoPasajeroReverse(char* tipoPasajeroStr,int *tipoPasajeroInt){
	int retorno = 0;
	if(*tipoPasajeroInt == ECONOMY_CLASS){
		strncpy(tipoPasajeroStr,"EconomyClass",50);
	}else{
		if(*tipoPasajeroInt == EXECUTIVE_CLASS){
			strncpy(tipoPasajeroStr,"ExecutiveClass",50);
		}else{
			if(*tipoPasajeroInt == FIRST_CLASS){
				strncpy(tipoPasajeroStr,"FirstClass",50);
			}else{
				strncpy(tipoPasajeroStr,"Error",50);
				retorno = -1;
			}
		}
	}
	return retorno;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* tipoPasajeroStr, char* codigoVueloStr, char* precioStr, char* estadoVueloStr){

	Passenger* retorno = NULL;
	Passenger* p = Passenger_new();
	int tipoPasajero = -1;

	if(p!=NULL && idStr!=NULL && nombreStr!=NULL && tipoPasajeroStr!=NULL && apellidoStr!=NULL && codigoVueloStr!=NULL && precioStr!=NULL && estadoVueloStr!=NULL){

		Passenger_conversorTipoPasajero(tipoPasajeroStr,&tipoPasajero);

		//ACA USAR LOS SETTERS (Y GETTERS?)
		//id = Passenger_getId(this, id)

		p->id = atoi(idStr);
		strcpy(p->nombre, nombreStr);
		strcpy(p->apellido, apellidoStr);
		p->tipoPasajero = tipoPasajero;
		strcpy(p->codigoVuelo, codigoVueloStr);
		p->precio = atof(precioStr);
		strcpy(p->estadoVuelo, estadoVueloStr);
		retorno = p;
	}else{
		puts("Algún campo resultó NULL.");
		retorno = NULL;
		if(p==NULL){
			puts("p es NULL");
		}else{
			if(idStr==NULL){
			puts("idStr es NULL");
			}
		}
	}
	return retorno;
}



void Passenger_delete(Passenger* this){ //DESTRUCTOR
	if(this != NULL){
		free(this);
	}
}

int Passenger_getId(Passenger* this,int* id){
	int retorno =-1;
	if(this !=NULL && id!=NULL)
	{
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}

void Passenger_printOne(Passenger* p){

	int id;
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	float precio;
	char estadoVuelo[ESTADO_LEN];
	int tipoPasajero;
	//char tipoPasajeroChar[TIPO_LEN];
	char codigoVuelo[CODIGO_LEN];

	Passenger_getId(p, &id);
	Passenger_getNombre(p, nombre);
	Passenger_getApellido(p, apellido);
	Passenger_getPrecio(p, &precio);
	Passenger_getEstadoVuelo(p, estadoVuelo);
	Passenger_getTipoPasajero(p, &tipoPasajero);
	Passenger_getCodigoVuelo(p, codigoVuelo);

	//Passenger_conversorTipoPasajeroReverse(tipoPasajeroChar, &tipoPasajero);

	printf("|%10d|%15s|%15s|%10.2f|%20s|%20d|%20s|\n",
											   id,
											   nombre,
											   apellido,
											   precio,
											   estadoVuelo,
											   tipoPasajero,
											   codigoVuelo);
}

int Passenger_printArray(Passenger* arrayPunteros[],int limite){
	int retorno = 0;
	int i;
	if(arrayPunteros != NULL && limite >0)
	{
		for(i=0;i<limite;i++){
			Passenger_printOne(arrayPunteros[i]);
		}
	}else{
		retorno = -1;
	}
	return retorno;
}

int Passenger_setId(Passenger* this,int id){ //ACÁ NO VAN FLECHITAS! ESTO SE HACE PARA ATOMIZAR MÁS EL CÓDIGO, ENCAPSULAR LO QUE HACEMOS
	int retorno = -1;

	if(this!=NULL && id>0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(allChars(nombre, NOMBRE_LEN)){
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

/*
int Passenger_setId(Passenger* this,char* id){
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(!isInt(id)){
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}
*/

int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		if(allChars(apellido, APELLIDO_LEN)){
			retorno = 0;
			strncpy(this->apellido,apellido,APELLIDO_LEN);
		}
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno = -1;

	if(this!=NULL && precio>0){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		if(strlen(codigoVuelo)<=CODIGO_LEN){
			retorno = 0;
			strncpy(this->codigoVuelo,codigoVuelo,CODIGO_LEN);
		}
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno = -1;
	if(this != NULL && tipoPasajero >=0)
	{
		if(tipoPasajero>=0 && tipoPasajero<=2){ //4? O incluir el \0?
			retorno = 0;
			this->tipoPasajero = tipoPasajero;
		}
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo){
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		if(allChars(estadoVuelo, 5)){ //4? O incluir el \0?
			retorno = 0;
			strncpy(this->estadoVuelo,estadoVuelo,ESTADO_LEN);
		}
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){ //La idea es que podemos armar campos calculados
													//Ej, getEdad que resta fecha nacimiento a current
													//DEBERÍA USAR ASTERISCO EN STRNCPY(NOMBRE?
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strncpy(apellido,this->apellido,APELLIDO_LEN);
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strncpy(codigoVuelo,this->codigoVuelo,CODIGO_LEN);
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo){
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		retorno = 0;
		strncpy(estadoVuelo,this->estadoVuelo,ESTADO_LEN);
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

int Passenger_SortApellido(void* item1,void* item2){
	int retorno = 0;

	char apellido1[APELLIDO_LEN];
	char apellido2[APELLIDO_LEN];

	Passenger* p1;
	Passenger* p2;

	p1 = (Passenger*) item1;
	p2 = (Passenger*) item2;

	if(!Passenger_getApellido(p1, apellido1) && !Passenger_getApellido(p2, apellido2)){
		retorno = strcmp(p1->apellido,p2->apellido);
	}
	return retorno;
}

int Passenger_SortCodigoVuelo(void* item1,void* item2){
	int retorno = 0;

	char codigo1[CODIGO_LEN];
	char codigo2[CODIGO_LEN];

	Passenger* p1;
	Passenger* p2;

	p1 = (Passenger*) item1;
	p2 = (Passenger*) item2;

	if(!Passenger_getCodigoVuelo(p1, codigo1) && !Passenger_getCodigoVuelo(p2, codigo2)){
		retorno = strcmp(p1->codigoVuelo,p2->codigoVuelo);
	}
	return retorno;
}

int Passenger_SortId(void* item1,void* item2){
	int retorno = 0;

	int id1;
	int id2;

	Passenger* p1;
	Passenger* p2;

	p1 = (Passenger*) item1;
	p2 = (Passenger*) item2;

	if(!Passenger_getId(p1, &id1) && !Passenger_getId(p2, &id2)){
		if(p1->id > p2->id){
			retorno =1;
		}else{
			retorno =-1;
		}
	}
	return retorno;
}
