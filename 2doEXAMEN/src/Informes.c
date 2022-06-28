#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Games.h"
#include "Rooms.h"
#include "Arcades.h"
#include "parser.h"
#include "Informes.h"

/*
int controller_ListRoomsWithFourArcOrMore(LinkedList* pArrayListRoom,LinkedList* pArrayListArcade)
{
	int retorno = 0;
	Room* r;
	int idCount = 0;
	int cantidad;
	cantidad = ll_len(pArrayListRoom); // 3;//

	if(pArrayListRoom != NULL){
		printf("\n|-------------------------------------------------------------------------------------------------------|\n");
		  printf("|    ID    |                 NOMBRE                 |           DIRECCION          |        TIPO        |\n");
		  printf("|-------------------------------------------------------------------------------------------------------|\n");

		for(int i=0;i<ll_len(pArrayListRoom);i++){
			r = ll_get(pArrayListRoom, i);
			idCount = r->id;
		  }

		for(int i=0; i<cantidad;i++){
			r = ll_get(pArrayListRoom, i);
			if(r!=NULL){
				Room_printOne(r);
			}
		}
	}else{
		retorno = -1;
	}
	return retorno;
}
*/
