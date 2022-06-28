#ifndef GAMES_H_
#define GAMES_H_

#include "LinkedList.h"

#define NOMBRE_GAME_LEN 60
#define EMPRESA_LEN 60
#define GENERO_LEN 60

#define SIZE_GAMES 9999

#define AVENTURA 0
#define LABERINTO 1
#define PLATAFORMA 2
#define OTRO 3
#define ERROR_TYPE 9


typedef struct
{
	int id;
	char nombre[NOMBRE_GAME_LEN];
	char empresa[EMPRESA_LEN];
	int genero;
}Game;


int Game_conversorGeneroGame(char* generoGameStr,int* generoGame);

Game* Game_new();
Game* Game_newParametros(char* idStr,char* nombreStr,char* generoGameStr,char* empresaStr);
void Game_delete();
int Game_buscarIndexPorIdArray(LinkedList* arrayPunterosGames, int id);

int Game_setId(Game* this,int id);
int Game_getId(Game* this,int* id);
int Game_setIdStr(Game* this,char* idStr);

int Game_setNombre(Game* this,char* nombre);
int Game_getNombre(Game* this,char* nombre);

int Game_setEmpresa(Game* this,char* empresa);
int Game_getEmpresa(Game* this,char* empresa);

int Game_setGenero(Game* this,int generoGame);
int Game_getGenero(Game* this,int* generoGame);
int Game_setGeneroStr(Game* this,char* generoStr);

void Game_printOne(Game* unGame);

int Game_SortApellido(void* item1,void* item2);
int Game_SortId(void* item1,void* item2);
int Game_SortCodigoVuelo(void* item1,void* item2);

int Game_conversorGeneroGameReverse(char* generoGameStr,int *generoGameInt);

#endif /* PASSENGER_H_ */
