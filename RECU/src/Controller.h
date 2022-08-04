#include "LinkedList.h"
#include "Games.h"
#include "Rooms.h"
#include "Arcades.h"
#include "parser.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadGamesFromText(char* path , LinkedList* pArrayListGame);
int controller_addGame(LinkedList* pArrayListGame);
int controller_ListGame(LinkedList* pArrayListGame);
int controller_saveGamesAsText(char* path , LinkedList* pArrayListGame);
int controller_removeGame(LinkedList* pArrayListGame, int idBaja);

int controller_buscaMaxIdGame(LinkedList* pArrayListGames);
int controller_buscarPorIdLinkedListGames(LinkedList* arrayPunterosGames, int id);

//int controller_loadFromBinary(char* path , LinkedList* pArrayListGame);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListGame);
//int controller_editGame(LinkedList* pArrayListGame);
//int controller_removeGame(LinkedList* pArrayListGame);
//int controller_sortGame(LinkedList* pArrayListGame);

int controller_loadRoomsFromText(char* path , LinkedList* pArrayListRoom);
int controller_addRoom(LinkedList* pArrayListRoom);
int controller_ListRoom(LinkedList* pArrayListRoom);
int controller_saveRoomsAsText(char* path , LinkedList* pArrayListRoom);
int controller_buscarPorIdLinkedListRooms(LinkedList* pArrayListRoom, int id);
int controller_removeRoom(LinkedList* pArrayListRoom,int idBaja,LinkedList* pArrayListArcade,LinkedList* pArrayListGame);
int controller_buscaMaxIdRoom(LinkedList* pArrayListRoom);

int controller_loadArcadesFromText(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayListArcade,LinkedList* pArrayListSalas,LinkedList* pArrayListJuegos);
int controller_buscaMaxIdArcade(LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms);
int controller_saveArcadesAsText(char* path , LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade, int idBaja,LinkedList* pArrayListGames,LinkedList* pArrayListRooms);
int controller_buscarPorIdLinkedListArcades(LinkedList* pArrayListArcades, int id);
int controller_buscarPorRelSalaLinkedListArcades(LinkedList* pArrayListArcade, int relSala);
int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListGame, LinkedList* pArrayListRooms);

int controller_sortArcade(LinkedList* pArrayListArcade);
int controller_sortGame(LinkedList* pArrayListGames);

#endif /* CONTROLLER_H_ */
