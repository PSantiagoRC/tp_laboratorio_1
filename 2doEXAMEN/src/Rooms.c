#include "Rooms.h"
#include <ctype.h>
#include <stdio.h>
#include "UTN4.h"

Room* Room_new(){
	Room* r;
	r = (Room*) malloc(sizeof(Room)*1);
	if(r!=NULL){
		r->id = 0;
		r->nombre[0]='\0'; //es el final de un string (en este caso vacío)
		r->direccion[0]='\0';
		r->tipo= 0;
	}
	return r;
}

int Room_conversorTipoRoom(char* tipoRoomStr,int *tipoRoom){
	int retorno = 0;
	if(strcmp(tipoRoomStr,"Local")==0){
		*tipoRoom = LOCAL;
	}else{
		if(strcmp(tipoRoomStr,"Shopping")==0){
			*tipoRoom = SHOPPING;
		}else{
			*tipoRoom = ERROR_TYPE_ROOM;
			retorno = -1;
		}
	}
	return retorno;
}

int Room_conversorTipoRoomReverse(char* tipoRoomStr,int *tipoRoomInt){
	int retorno = 0;
	if(*tipoRoomInt == LOCAL){
		strncpy(tipoRoomStr,"Local",50);
	}else{
		if(*tipoRoomInt == SHOPPING){
			strncpy(tipoRoomStr,"Shopping",50);
		}else{
			strncpy(tipoRoomStr,"Error",50);
			retorno = -1;
		}
	}
	return retorno;
}

int Room_buscarIndexPorIdArray(LinkedList* arrayPunterosRooms, int id){
	int retorno = -1;
	Room* r = NULL;
	int limite = ll_len(arrayPunterosRooms);
	if(arrayPunterosRooms != NULL && limite >0 && id >= 0)
	{
		retorno =-2;
		for(int i=0;i<limite;i++){
			r = ll_get(arrayPunterosRooms,i);
			if(r!=NULL && r->id == id){
				retorno = ll_indexOf(arrayPunterosRooms, r);
				break;
			}
		}
	}
	return retorno;
}

Room* Room_newParametros(char* idStr,char* nombreStr, char* direccionStr, int tipoInt){

	Room* retorno = NULL;
	Room* r = Room_new();
	//int tipoRoomInt;

	if(r!=NULL){
		if(idStr!=NULL && nombreStr!=NULL && tipoInt>-1 && direccionStr!=NULL){
			//Room_conversorTipoRoom(tipoStr,&tipoRoomInt);

			if(!Room_setIdStr(r, idStr)){
			}else{
				puts("\nsetId falló");
			}
			if(!Room_setNombre(r, nombreStr)){
			}else{
				puts("\nsetNombre falló");
			}
			if(!Room_setDireccion(r, direccionStr)){
			}else{
				puts("\nsetDireccion falló");
			}
			if(!Room_setTipo(r, tipoInt)){
			}else{
				puts("\nsetTipo falló");
			}
			retorno = r;
		}else{
			puts("\nAlgún campo es NULL");
		}
	}else{
		puts("\nEl espacio encontrado para la entidad Room es NULL.");
		retorno = NULL;
		if(r==NULL){
			puts("r es NULL");
		}else{
			if(idStr==NULL){
			puts("idStr es NULL");
			}
		}
	}
	return retorno;
}

int Room_getId(Room* this,int* id){
	int retorno =-1;
	if(this !=NULL && id!=NULL)
	{
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}

void Room_printOne(Room* r){

	int id;
	char nombre[NOMBRE_ROOM_LEN];
	char direccion[DIRECCION_LEN];
	int tipoRoomInt;
	char tipoRoomChar[TIPO_ROOM_LEN];

	Room_getId(r, &id);
	Room_getNombre(r, nombre);
	Room_getDireccion(r, direccion);
	Room_getTipo(r, &tipoRoomInt);

	Room_conversorTipoRoomReverse(tipoRoomChar, &tipoRoomInt);

	printf("|%10d|%40s|%30s|%20s|\n",
								   id,
								   nombre,
								   direccion,
								   tipoRoomChar);
}

int Room_setId(Room* this,int id){ //ACÁ NO VAN FLECHITAS! ESTO SE HACE PARA ATOMIZAR MÁS EL CÓDIGO, ENCAPSULAR LO QUE HACEMOS
	int retorno = -1;

	if(this!=NULL && id>0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Room_setIdStr(Room* this,char * idStr){ //ACÁ NO VAN FLECHITAS! ESTO SE HACE PARA ATOMIZAR MÁS EL CÓDIGO, ENCAPSULAR LO QUE HACEMOS
	int retorno = -1;
	int idAux;

	if(this!=NULL && idStr!=NULL){
		if(!isInt(idStr)){
			idAux = atoi(idStr);
		}
		if(idAux>0 && idAux<=SIZE_ROOMS){
			this->id = idAux;
			retorno = 0;
		}
	}
	return retorno;
}

int Room_setNombre(Room* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,NOMBRE_ROOM_LEN);
		retorno = 0;
	}
	return retorno;
}

int Room_setDireccion(Room* this,char* direccion){
	int retorno = -1;

	if(this != NULL && direccion != NULL)
	{
		//myGetsLocal(direccionAux, DIRECCION_LEN, direccion);
		strncpy(this->direccion,direccion,DIRECCION_LEN);
		retorno = 0;
	}
	return retorno;
}

int Room_setTipo(Room* this,int tipo){
	int retorno = -1;
	if(this != NULL && tipo >=0)
	{
		if(tipo>=0 && tipo<=1){ //4? O incluir el \0?
			retorno = 0;
		}else{
			tipo = 9;
			retorno = 0;
		}
		this->tipo = tipo;
	}
	return retorno;
}

int Room_getNombre(Room* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_ROOM_LEN);
	}
	return retorno;
}

int Room_getDireccion(Room* this,char* direccion){
	int retorno = -1;
	if(this != NULL && direccion != NULL)
	{
		retorno = 0;
		strncpy(direccion,this->direccion,DIRECCION_LEN);
	}
	return retorno;
}

int Room_getTipo(Room* this,int* tipoRoom){
	int retorno = -1;
	if(this != NULL && tipoRoom != NULL)
	{
		retorno = 0;
		*tipoRoom = this->tipo;
	}
	return retorno;
}

int Room_SortDireccion(void* item1,void* item2){
	int retorno = 0;

	char direccion1[DIRECCION_LEN];
	char direccion2[DIRECCION_LEN];

	Room* p1;
	Room* p2;

	p1 = (Room*) item1;
	p2 = (Room*) item2;

	if(!Room_getDireccion(p1, direccion1) && !Room_getDireccion(p2, direccion2)){
		retorno = strcmp(p1->direccion,p2->direccion);
	}
	return retorno;
}

/*
int Room_SortCodigoVuelo(void* item1,void* item2){
	int retorno = 0;

	char codigo1[CODIGO_LEN];
	char codigo2[CODIGO_LEN];

	Room* p1;
	Room* p2;

	p1 = (Room*) item1;
	p2 = (Room*) item2;

	if(!Room_getCodigoVuelo(p1, codigo1) && !Room_getCodigoVuelo(p2, codigo2)){
		retorno = strcmp(p1->codigoVuelo,p2->codigoVuelo);
	}
	return retorno;
}


int Room_SortId(void* item1,void* item2){
	int retorno = 0;

	int id1;
	int id2;

	Room* p1;
	Room* p2;

	p1 = (Room*) item1;
	p2 = (Room*) item2;

	if(!Room_getId(p1, &id1) && !Room_getId(p2, &id2)){
		if(p1->id > p2->id){
			retorno =1;
		}else{
			retorno =-1;
		}
	}
	return retorno;
}
*/
