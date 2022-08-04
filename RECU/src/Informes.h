#include "UTN4.h"
#include "Games.h"
#include "Rooms.h"
#include "Arcades.h"
#include "LinkedList.h"
#include "controller.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int informes_AListRoomsMoreThanFourArcades(LinkedList* pArrayArcadeList, LinkedList* pArrayListRoom, LinkedList* pArrayListGame);
void informes_printOneRoomMoreThanFourArcades(Arcade* a, LinkedList* pArrayListGames,LinkedList* pArrayListRooms);
int informes_countArcadeByRoom(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms, int roomId);

int informes_BArcadesForTwoOrMore(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms);
void informes_BArcade_printOne(Arcade* a, LinkedList* pArrayListGames,LinkedList* pArrayListRooms);

int informes_CPrintUserRooms(LinkedList* pArrayListRoom);

int informes_DcountArcadeByGenre(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms, int roomId, int genre);
int informes_DListCompleteRooms(LinkedList* pArrayArcadeList, LinkedList* pArrayListRoom, LinkedList* pArrayListGame);

void informes_ERoom_ListArcadesByRoomId(LinkedList* pArrayListGames,LinkedList* pArrayListRooms, LinkedList* pArrayListArcades);

#endif /* INFORMES_H_ */
