#ifndef ROOMS_H_
#define ROOMS_H_
#include "UTN4.h"
#include "LinkedList.h"

#define NOMBRE_ROOM_LEN 60
#define DIRECCION_LEN 60
#define TIPO_ROOM_LEN 60

#define SIZE_ROOMS 9999

#define LOCAL 0
#define SHOPPING 1
#define ERROR_TYPE_ROOM 9


typedef struct
{
	int id;
	char nombre[NOMBRE_ROOM_LEN];
	char direccion[DIRECCION_LEN];
	int tipo;
}Room;

int Room_conversorTipoRoom(char* tipoRoomStr,int* tipoRoom);

Room* Room_new();
Room* Room_newParametros(char* idStr,char* nombreStr,char* direccionStr,int tipoInt);
void Room_delete();
int Room_buscarIndexPorIdArray(LinkedList* arrayPunterosRooms, int id);

int Room_setId(Room* this,int id);
int Room_getId(Room* this,int* id);
int Room_setIdStr(Room* this,char* idStr);

int Room_setNombre(Room* this,char* nombre);
int Room_getNombre(Room* this,char* nombre);

int Room_setDireccion(Room* this,char* empresa);
int Room_getDireccion(Room* this,char* empresa);

int Room_setTipo(Room* this,int tipoRoom);
int Room_getTipo(Room* this,int* tipoRoom);
int Room_setTipoStr(Room* this,char* tipoStr);

void Room_printOne(Room* unRoom);

int Room_SortApellido(void* item1,void* item2);
int Room_SortId(void* item1,void* item2);
int Room_SortCodigoVuelo(void* item1,void* item2);

int Room_conversorTipoRoomReverse(char* tipoRoomStr,int *tipoRoomInt);

#endif /* PASSENGER_H_ */
