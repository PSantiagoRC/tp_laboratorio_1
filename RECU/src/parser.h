#include "LinkedList.h"
#include "UTN4.h"
#include "Games.h"
#include "Rooms.h"
#include "Arcades.h"

#ifndef PARSER_H_
#define PARSER_H_

int parser_GameFromText(FILE* pFile , LinkedList* pArrayListGame);
int parser_RoomFromText(FILE* pFile , LinkedList* pArrayListRoom);
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade);

//int parser_GameFromBinary(FILE* pFile , LinkedList* pArrayListGame);

#endif /* PARSER_H_ */
