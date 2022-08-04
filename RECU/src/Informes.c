#include "Informes.h"

/*
int informes_ListRoomsWithFourArcOrMore(LinkedList* pArrayListRoom,LinkedList* pArrayListArcade)
{
	int retorno = 0;
	Room* r;
	Arcade* a;
	int relSalaAnt =0;
	int relCount = 0;
	int idRoom;

	if(pArrayListRoom != NULL){
		printf("\n|-------------------------------------------------------------------------------------------------------|\n");
		  printf("|    ID    |                 NOMBRE                 |           DIRECCION          |        TIPO        |\n");
		  printf("|-------------------------------------------------------------------------------------------------------|\n");

		for(int i=0;i<ll_len(pArrayListArcade);i++){
			a = ll_get(pArrayListArcade, i);
			if(relSalaAnt == a->rel_sala || relSalaAnt == 0 ){
				relCount++;
				relSalaAnt = a->rel_sala;}
			if(relCount>=3){//&& a->rel_sala != relSalaAnt){
				relCount=0;
				relSalaAnt = 0;
				idRoom = controller_buscarPorIdLinkedListRooms(pArrayListRoom, a->rel_sala);
				r = ll_get(pArrayListRoom, idRoom);
				if(r!=NULL){
					Room_printOne(r);
				}
			}
		 }
	}else{
		retorno = -1;
	}
	return retorno;
}
*/

/*
int Game_SortBySalon(void* item1,void* item2){
	int retorno = 0;

	int IdSala1;
	int IdSala2;

	Game* p1;
	Game* p2;

	p1 = (Game*) item1;
	p2 = (Game*) item2;

	if(!Game_getEmpresa(p1, empresa1) && !Game_getEmpresa(p2, empresa2)){
		retorno = strcmp(p1->empresa,p2->empresa);
	}
	return retorno;
}
*/

void informes_printOneRoomMoreThanFourArcades(Arcade* a, LinkedList* pArrayListGames,LinkedList* pArrayListRooms){

	int id_arcade;
	int rel_sala;
	int rel_juego;
	int tipoSonidoInt;
	char tipoSonidoStr[TIPO_SONIDO_LEN];
	int cap_fichas;
	int num_jugadores;
	char pais[PAIS_LEN];

	char nomJuego[NOMBRE_GAME_LEN];
	char empJuego[EMPRESA_LEN];
	int genJuegoInt;
	char genJuegoStr[GENERO_LEN];

	char direcSala[DIRECCION_LEN];
	char nomSala[NOMBRE_ROOM_LEN];

	int indexJuego;
	Game* juegoAux;

	int indexSala;
	Room* salaAux;

	Arcade_getId(a, &id_arcade);
	Arcade_getPais(a, pais);
	Arcade_getTipoSonido(a, &tipoSonidoInt);
	Arcade_getRelSala(a, &rel_sala);
	Arcade_getRelJuego(a, &rel_juego);
	Arcade_getCapFichas(a, &cap_fichas);
	Arcade_getNumJugadores(a, &num_jugadores);

	indexJuego = Game_buscarIndexPorIdArray(pArrayListGames, rel_juego);
	juegoAux = ll_get(pArrayListGames, indexJuego);
	if(!Game_getNombre(juegoAux, nomJuego)){
	}else{
		puts("\nError getNombreJuego");
	}
	if(!Game_getEmpresa(juegoAux, empJuego)){
	}else{
		puts("\nError getNombreJuego");
	}
	if(!Game_getGenero(juegoAux, &genJuegoInt)){
	}else{
		puts("\nError getNombreJuego");
	}

	indexSala = Room_buscarIndexPorIdArray(pArrayListRooms, rel_sala);
	salaAux = ll_get(pArrayListRooms, indexSala);
	if(salaAux!=NULL){
		if(!Room_getNombre(salaAux, nomSala)){
			//OK
		}else{
			puts("\nError getNombreSala");
		}
		if(!Room_getDireccion(salaAux, direcSala)){
			//OK
		}else{
			puts("\nError getDireccionSala");
		}
	}else{
		puts("SalaAux es NULL");
	}

	Game_conversorGeneroGameReverse(genJuegoStr, &genJuegoInt);
	Arcade_conversorTipoSonidoReverse(tipoSonidoStr, &tipoSonidoInt);

	printf("|%8d|%8d|%8d|%8d|%8d|%20s|%10s|%30s|%30s|%30s|%30s|%30s|\n",
								   id_arcade,
								   rel_sala,
								   rel_juego,
								   cap_fichas,
								   num_jugadores,
								   pais,
								   tipoSonidoStr,
								   nomJuego,
								   empJuego,
								   genJuegoStr,
								   nomSala,
								   direcSala);
}


/*
int informes_ListRoomsMoreThanFourArcades(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms)
{
	int retorno = 0;
	Arcade* a;
	int cantidad;
	cantidad = ll_len(pArrayListArcade); // 3;//

	if(pArrayListArcade != NULL && pArrayListGames != NULL && pArrayListRooms != NULL){
		printf("\n|----------------------------------------------------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|\n");
		  printf("| ID ARC | R_SALA | R_JUEGO| FICHAS | PLAYERS|        PAIS        |  SONIDO  |        NOMBRE JUEGO          |        EMPRESA JUEGO         |         GENERO JUEGO         |          NOMBRE SALA         |         DIRECCION SALA       |\n");
		  printf("|----------------------------------------------------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|\n");

		for(int i=0; i<cantidad;i++){
			a = ll_get(pArrayListArcade, i);
			if(a!=NULL){
				Arcade_printOne(a,pArrayListGames,pArrayListRooms);
			}
		}
	}else{
		retorno = -1;
	}
	return retorno;
}
*/

int informes_countArcadeByRoom(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms, int roomId)
{
	int retorno = -1;
	int i;
	int size;
	int arcadeCount=0;
	Arcade* a;
	int roomIdBuffer;
	if(pArrayListArcade != NULL && pArrayListRooms != NULL && pArrayListGames != NULL)
	{
		size = ll_len(pArrayListArcade);
		if(size != -1)
		{
			for (i = 0; i < size; i++) //Recorre la LL de Arcades y compara el campo salonId de cada Arcade con el dado, caso favorable cuenta.
			{
				a = ll_get(pArrayListArcade, i);
				Arcade_getRelSala(a,&roomIdBuffer);
				if(a != NULL && roomIdBuffer == roomId)
				{
					arcadeCount++;
					retorno = arcadeCount;

				}
			}
		}
	}
	return retorno;
}

int informes_AListRoomsMoreThanFourArcades(LinkedList* pArrayArcadeList, LinkedList* pArrayListRoom, LinkedList* pArrayListGame)
{
	int retorno = -1;
	int i;
	int size;
	int roomIdBuffer;
	Room* r;
	if(pArrayListRoom != NULL)
	{
		size = ll_len(pArrayListRoom);
		if(size > 0)
		{	printf("\n|------------------------------------ SALONES CON MAS DE CUATRO ARCADES --------------------------------|\n");
			  printf("|-------------------------------------------------------------------------------------------------------|\n");
			  printf("|    ID    |                 NOMBRE                 |           DIRECCION          |        TIPO        |\n");
			  printf("|-------------------------------------------------------------------------------------------------------|\n");

			for (i = 0; i < size; i++)
			{
				r = ll_get(pArrayListRoom, i);
				Room_getId(r, &roomIdBuffer);
				if(r != NULL && (informes_countArcadeByRoom(pArrayArcadeList, pArrayListGame, pArrayListRoom, roomIdBuffer)>4))
				{
					Room_printOne(r);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

void informes_BArcade_printOne(Arcade* a, LinkedList* pArrayListGames,LinkedList* pArrayListRooms){

	int id_arcade;
	int rel_sala;
	int rel_juego;
	int num_jugadores;

	char nomJuego[NOMBRE_GAME_LEN];
	int genJuegoInt;
	char genJuegoStr[GENERO_LEN];

	char nomSala[NOMBRE_ROOM_LEN];

	int indexJuego;
	Game* juegoAux;

	int indexSala;
	Room* salaAux;

	Arcade_getId(a, &id_arcade);
	Arcade_getRelSala(a, &rel_sala);
	Arcade_getRelJuego(a, &rel_juego);
	Arcade_getNumJugadores(a, &num_jugadores);

	indexJuego = Game_buscarIndexPorIdArray(pArrayListGames, rel_juego);
	juegoAux = ll_get(pArrayListGames, indexJuego);
	if(!Game_getNombre(juegoAux, nomJuego)){
	}else{
		puts("\nError getNombreJuego");
	}
	if(!Game_getGenero(juegoAux, &genJuegoInt)){
	}else{
		puts("\nError getGeneroJuego");
	}

	indexSala = Room_buscarIndexPorIdArray(pArrayListRooms, rel_sala);
	salaAux = ll_get(pArrayListRooms, indexSala);
	if(salaAux!=NULL){
		if(!Room_getNombre(salaAux, nomSala)){
			//OK
		}else{
			puts("\nError getNombreSala");
		}
	}else{
		puts("SalaAux es NULL");
	}

	Game_conversorGeneroGameReverse(genJuegoStr, &genJuegoInt);

	printf("|%8d|%8d|%30s|%30s|%30s|\n",
								   id_arcade,
								   num_jugadores,
								   nomJuego,
								   genJuegoStr,
								   nomSala);
}

int informes_BArcadesForTwoOrMore(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms)
{
	int retorno = 0;
	Arcade* a;
	int cantidad;
	cantidad = ll_len(pArrayListArcade); // 3;//

	if(pArrayListArcade != NULL && pArrayListGames != NULL && pArrayListRooms != NULL){
		printf("\n|------------------------------------------------|------------------------------|------------------------------|\n");
		  printf("|   ID   | PLAYERS|        NOMBRE JUEGO          |         GENERO JUEGO         |          NOMBRE SALA         |\n");
		  printf("|------------------------------------------------|------------------------------|------------------------------|\n");

		for(int i=0; i<cantidad;i++){
			a = ll_get(pArrayListArcade, i);
			if(a!=NULL && a->num_jugadores>2){
				informes_BArcade_printOne(a, pArrayListGames,pArrayListRooms);
			}
		}
	}else{
		retorno = -1;
	}
	return retorno;
}

int informes_CPrintUserRooms(LinkedList* pArrayListRoom)
{
	int roomIdInput;
	int retorno = -1;
	int i;
	int size;
	Room* r;
	int roomIdBuffer;

	utn_getInt("Ingrese ID de Sala", "Error. Reingrese.", 1, 999, 3, &roomIdInput);

	if(pArrayListRoom != NULL)
	{
		size = ll_len(pArrayListRoom);
		if(size > 0)
		{	  printf("|-------------------------------------------------------------------------------------------------------|\n");
			  printf("|    ID    |                 NOMBRE                 |           DIRECCION          |        TIPO        |\n");
			  printf("|-------------------------------------------------------------------------------------------------------|\n");

			for (i = 0; i < size; i++)
			{
				r = ll_get(pArrayListRoom, i);
				Room_getId(r, &roomIdBuffer);
				if(r != NULL && roomIdBuffer==roomIdInput)
				{
					Room_printOne(r);
					retorno = 0;
				}
			}
			printf("|-------------------------------------------------------------------------------------------------------|\n");
		}
	}
	return retorno;
}

int informes_DcountArcadeByGenre(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms, int roomId, int genre)
{
	int retorno = -1;
	int i;
	int size;
	int genreCount=0;
	int gameIndex;
	Arcade* a;
	Game * g;
	int roomIdBuffer;
	int gameIdBuffer;
	if(pArrayListArcade != NULL && pArrayListRooms != NULL && pArrayListGames != NULL)
	{
		size = ll_len(pArrayListArcade);
		if(size != -1)
		{
			for (i = 0; i < size; i++) //Recorre la LL de Arcades y compara el campo salonId de cada Arcade con el dado, caso favorable cuenta.
			{
				a = ll_get(pArrayListArcade, i);
				Arcade_getRelSala(a,&roomIdBuffer);
				Arcade_getRelJuego(a, &gameIdBuffer);
				gameIndex = controller_buscarPorIdLinkedListGames(pArrayListGames, gameIdBuffer);
				g = ll_get(pArrayListGames, gameIndex);
				if(a != NULL && g != NULL && roomIdBuffer == roomId && g->genero==genre)
				{
					genreCount++;
					retorno = genreCount;
				}
			}
		}
	}
	return retorno;
}

int informes_DListCompleteRooms(LinkedList* pArrayArcadeList, LinkedList* pArrayListRoom, LinkedList* pArrayListGame)
{
	int retorno = -1;
	int i;
	int size;
	int roomIdBuffer;
	Room* r;
	if(pArrayListRoom != NULL)
	{
		size = ll_len(pArrayListRoom);
		if(size > 0)
		{	printf("\n|------------------------------------ SALONES CON MAS DE CUATRO ARCADES --------------------------------|\n");
			  printf("|-------------------------------------------------------------------------------------------------------|\n");
			  printf("|    ID    |                 NOMBRE                 |           DIRECCION          |        TIPO        |\n");
			  printf("|-------------------------------------------------------------------------------------------------------|\n");

			for (i = 0; i < size; i++)
			{
				r = ll_get(pArrayListRoom, i);
				Room_getId(r, &roomIdBuffer);
				if(r != NULL && (informes_DcountArcadeByGenre(pArrayArcadeList,pArrayListGame,pArrayListRoom, roomIdBuffer, AVENTURA))>4
						&& (informes_DcountArcadeByGenre(pArrayArcadeList,pArrayListGame,pArrayListRoom, roomIdBuffer, LABERINTO))>2
						&& (informes_DcountArcadeByGenre(pArrayArcadeList,pArrayListGame,pArrayListRoom, roomIdBuffer, PLATAFORMA))>3)
				{
					Room_printOne(r);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

void informes_ERoom_ListArcadesByRoomId(LinkedList* pArrayListGames,LinkedList* pArrayListRooms, LinkedList* pArrayListArcades){

	//QUE ESTA FUNCION SEA UN PRINT ONE Y METERLA EN UNA FUNCION LIST, PORQUE SINO NO PARA?

	int idRoom;
	int indexRoom;
	Room* r;
	Arcade* arcadeAux;
	char tipoAux[TIPO_ROOM_LEN];
	int tipoAuxInt;

	utn_getInt("\nIngrese ID de Sala", "\nError. Reingrese.", 1, 999, 3, &idRoom);

	indexRoom = Room_buscarIndexPorIdArray(pArrayListRooms, idRoom);
	r = ll_get(pArrayListRooms,indexRoom);

	tipoAuxInt = r->tipo;

	puts("Se viene el error");
	if(tipoAuxInt==0){
		strcpy(tipoAux,"Local");
	}else{
		if (tipoAuxInt==1){
			strcpy(tipoAux,"Shopping");
		}else{
			strcpy(tipoAux,"Error");
		}
	}

	printf("\n>>> Se eligio el RoomID: %d <<<",idRoom);
	printf("\n>>> Nombre: %s <<<",r->nombre);
	printf("\n>>> Tipo: %s <<<",tipoAux);

	if(r!=NULL){
		printf("\n|------------------------------------------------------------------------------------------------------------ ARCADES DEL SALON --------------------------------------------------------------------------------------------------------|\n");
		  printf("|----------------------------------------------------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|\n");
		  printf("|   ID   | R_SALA | R_JUEGO| FICHAS | PLAYERS|        PAIS        |  SONIDO  |        NOMBRE JUEGO          |        EMPRESA JUEGO         |         GENERO JUEGO         |          NOMBRE SALA         |         DIRECCION SALA       |\n");
		  printf("|----------------------------------------------------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|\n");
		for(int i = 0;i<ll_len(pArrayListArcades);i++){
			arcadeAux = ll_get(pArrayListArcades, i);
			//printf("\nId del arcade: %d \nSala del arcade: %d \nID del room: %d",arcadeAux->id_arcade,arcadeAux->rel_sala, r->id);
			if(arcadeAux!=NULL && arcadeAux->rel_sala == r->id){
				Arcade_printOne(arcadeAux, pArrayListGames,pArrayListRooms);
			}
		}
	}
}

int informes_FSalonConMasArcadesOrdenado(LinkedList* pArrayListRooms, LinkedList* pArrayListArcades, LinkedList* pArrayListGames)
{
	int retorno = -1;
	int contadorArcades=0;
	int maxCant=0;
	int flagFirst = 0;
	int exito = 0;
	Room* r;
	Arcade* a;
	Room* auxMax=NULL;
	int auxRelRoom;
	int auxIdRoom;

	if(pArrayListRooms != NULL && pArrayListArcades != NULL)
	{
		controller_sortArcade(pArrayListArcades);
		for (int i=0; i<ll_len(pArrayListRooms);i++)
		{
			r = ll_get(pArrayListRooms, i);
			for(int j=0;j<ll_len(pArrayListArcades);j++)
			{
				a  = ll_get(pArrayListArcades,j);
				if(a->rel_sala == r->id)
				{
					contadorArcades++;
					if(contadorArcades > maxCant || flagFirst == 0)
					{
						maxCant=contadorArcades;
						flagFirst = 1;
						auxMax = r;
						exito=1;
					}
				}
			}
			if(exito==1)
			{
						printf("\n|------------------------------------------------------------------------------------------------------------ SALON CON MAS ARCADES ----------------------------------------------------------------------------------------------------|\n");
						  printf("|----------------------------------------------------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|\n");
						  printf("|   ID   | R_SALA | R_JUEGO| FICHAS | PLAYERS|        PAIS        |  SONIDO  |        NOMBRE JUEGO          |        EMPRESA JUEGO         |         GENERO JUEGO         |          NOMBRE SALA         |         DIRECCION SALA       |\n");
						  printf("|----------------------------------------------------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|\n");

				for(int j=0;j<ll_len(pArrayListArcades);j++)
				{
					a = ll_get(pArrayListArcades,j);
					Arcade_getRelSala(a, &auxRelRoom);
					Room_getId(auxMax, &auxIdRoom);
					if(auxRelRoom == auxIdRoom)
					{
						Arcade_printOne(a, pArrayListGames,pArrayListRooms);
					}
				}
				printf("Cantidad de Arcades: %d: \n ", maxCant);
			}
			exito = 0;
			contadorArcades=0;
		}
		retorno = 0;
	}
	return retorno;
}


int informes_GArcadesMonoConJuegoPlataforma(LinkedList* pArrayListRooms, LinkedList* pArrayListArcades, LinkedList* pArrayListGames)
{
	int retorno = -1;
	int cantidadRegistros=0;
	char auxGenero[GENERO_LEN];
	Arcade* a;
	Game* g;
	int auxRelJuego;
	int auxGameId;
	int auxTipoSonido;
	int auxGeneroInt;
	if(pArrayListArcades != NULL && pArrayListGames != NULL)
	{
		controller_sortGame(pArrayListGames);

		for (i=0; i<ll_len(pArrayListGames);i++)
		{
			g = ll_get(pArrayListGames, i);
			for(j=0;j<ll_len(pArrayListArcades);j++)
			{
				a  = ll_get(pArrayListArcades,j);
				Arcade_getRelJuego(a, &auxRelJuego);
				Game_getId(g, &auxGameId);
				if(auxRelJuego == auxGameId)
				{
					Arcade_getTipoSonido(a, &auxTipoSonido);
					Game_getGenero(g, &auxGenero);
					if(auxTipoSonido == MONO && auxGenero == PLATAFORMA)
					{
						Arcade_printOne(a, pArrayListGames, pArrayListRooms)
						cantidadRegistros++;
					}
				}
			}
		}
		printf("Cantidad de Arcades: %d: \n ", cantidadRegistros);
		retorno = 0;
	}
	return retorno;

}
