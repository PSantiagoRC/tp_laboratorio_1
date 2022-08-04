#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListGame LinkedList*
 * \return int
 *
 */


int controller_loadGamesFromText(char* path , LinkedList* pArrayListGame)
{
	int retorno = 0;
	int retParser;
	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && ll_len(pArrayListGame)==0){
		if(!(retParser = parser_GameFromText(pFile,pArrayListGame))){
			//ParserOK
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

int controller_loadRoomsFromText(char* path , LinkedList* pArrayListRoom)
{
	int retorno = 0;
	int retParser;
	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && ll_len(pArrayListRoom)==0){
		if(!(retParser = parser_RoomFromText(pFile,pArrayListRoom))){
			//ParserOK
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

int controller_loadArcadesFromText(char* path , LinkedList* pArrayListArcade)
{
	int retorno = 0;
	int retParser;
	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && ll_len(pArrayListArcade)==0){
		if(!(retParser = parser_ArcadeFromText(pFile,pArrayListArcade))){
			//ParserOK
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

int controller_buscaMaxIdGame(LinkedList* pArrayListGame){
	int retorno = -1;
	int flagMaxId = 1;
	int maxId;
	int id;
	Game* g;
	if(pArrayListGame!=NULL && ll_len(pArrayListGame)>0){
		for(int i = 0;i<ll_len((pArrayListGame));i++){
			if((g = ll_get(pArrayListGame, i))!= NULL){
				if(!Game_getId(g, &id)){
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

int controller_buscaMaxIdRoom(LinkedList* pArrayListRoom){
	int retorno = -1;
	int flagMaxId = 1;
	int maxId;
	int id;
	Room* g;
	if(pArrayListRoom!=NULL && ll_len(pArrayListRoom)>0){
		for(int i = 0;i<ll_len((pArrayListRoom));i++){
			if((g = ll_get(pArrayListRoom, i))!= NULL){
				if(!Room_getId(g, &id)){
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

int controller_buscaMaxIdArcade(LinkedList* pArrayListArcade){
	int retorno = -1;
	int flagMaxId = 1;
	int maxId;
	int id;
	Arcade* g;
	if(pArrayListArcade!=NULL && ll_len(pArrayListArcade)>0){
		for(int i = 0;i<ll_len((pArrayListArcade));i++){
			if((g = ll_get(pArrayListArcade, i))!= NULL){
				if(!Arcade_getId(g, &id)){
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

int controller_addGame(LinkedList* pArrayListGame)
{
	int retorno = 0;

	int id;
	char nombre[100];
	char empresa[100];
	int genero;

	if(pArrayListGame!=NULL){
		Game* pG = Game_new();


		if( !utn_getStringWNum("\nIngrese nombre del juego (inicie Mayusc)", "\nError. Reingrese.", 3, NOMBRE_GAME_LEN, nombre) &&
			!utn_getStringWNum("\nIngrese empresa (inicie Mayusc)", "\nError. Reingrese.", 3, EMPRESA_LEN, empresa) &&
			!utn_getInt("\nIngrese genero: Aventura(0), Laberinto(1), Plataforma(2), Otro(3)", "\nError. Ingrese el número de la opción correspondiente.", 0, 3, 3, &genero)){

			if(ll_len(pArrayListGame)==0){
				id = 1; //o sea 1
			}else{
				if(controller_buscaMaxIdGame(pArrayListGame)>0){
					id = controller_buscaMaxIdGame(pArrayListGame)+1;//función que recorre la linkedList y busca el mayor indice
				}
			}

			if(	!Game_setId(pG, id) &&
				!Game_setNombre(pG, nombre)&&
				!Game_setEmpresa(pG, empresa)&&
				!Game_setGenero(pG, genero)&&
				pG!=NULL){

				ll_add(pArrayListGame, pG);
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

int controller_addRoom(LinkedList* pArrayListRoom)
{
	int retorno = 0;

	int id;
	char nombre[100];
	char direccion[100];
	int tipo;

	if(pArrayListRoom!=NULL){
		Room* pR = Room_new();


		if( !utn_getStringWNum("\nIngrese nombre de la sala(inicie Mayusc)", "\nError. Reingrese.", 3, NOMBRE_ROOM_LEN, nombre) &&
			!utn_getStringWNum("\nIngrese direccion de la sala (inicie Mayusc)", "\nError. Reingrese.", 3, DIRECCION_LEN, direccion) &&
			!utn_getInt("\nIngrese tipo de sala: Local(0), Shopping(1)", "\nError. Ingrese el número de la opción correspondiente.", 0, 1, 3, &tipo)){

			if(ll_len(pArrayListRoom)==0){
				id = 1; //o sea 1
			}else{
				if(controller_buscaMaxIdRoom(pArrayListRoom)>0){
					id = controller_buscaMaxIdRoom(pArrayListRoom)+1;//función que recorre la linkedList y busca el mayor indice
				}
			}

			if(	!Room_setId(pR, id) &&
				!Room_setNombre(pR, nombre)&&
				!Room_setDireccion(pR, direccion)&&
				!Room_setTipo(pR, tipo)&&
				pR!=NULL){

				ll_add(pArrayListRoom, pR);
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

int controller_addArcade(LinkedList* pArrayListArcade,LinkedList* pArrayListSalas,LinkedList* pArrayListJuegos)
{
	int retorno = 0;

	int id_arcade;
	int rel_sala;
	int rel_juego;
	int tipoSonidoInt;
	int cap_fichas;
	int num_jugadores;
	char pais[PAIS_LEN];

	if(pArrayListArcade!=NULL && pArrayListJuegos!=NULL && pArrayListSalas!=NULL){
		Arcade* pA = Arcade_new();

		if( !utn_getStringWONumFirstUpper("Ingrese pais (inicial Mayusc)", "Error. Reingrese", 3, PAIS_LEN, pais) &&
			!utn_getInt("\nIngrese tipo de sonido: Mono(0), Stereo(1)", "\nError. Ingrese el número de la opción correspondiente.", 0, 1, 3, &tipoSonidoInt) &&
			!utn_getInt("\nIngrese capacidad de fichas", "\nError. Reingrese.", 0, 9999, 3, &cap_fichas) &&
			!utn_getInt("\nIngrese numero de jugadores", "\nError. Reingrese.", 0, 4, 3, &num_jugadores) &&
			!controller_ListRoom(pArrayListSalas) &&
			!utn_getInt("\nIngrese id de sala", "\nError. Reingrese.", 0, SIZE_ROOMS, 3, &rel_sala) &&
			!controller_ListGame(pArrayListJuegos) &&
			!utn_getInt("\nIngrese id de juego", "\nError. Reingrese.", 0, SIZE_GAMES, 3, &rel_juego)){

			if(ll_len(pArrayListArcade)==0){
				id_arcade = 1; //o sea 1
			}else{
				if(controller_buscaMaxIdArcade(pArrayListArcade)>0){
					id_arcade = controller_buscaMaxIdArcade(pArrayListArcade)+1;//función que recorre la linkedList y busca el mayor indice
				}
			}

			//LISTAR JUEGOS para obtener rel_juego
			//LISTAR SALAS para obtener rel_sala

			if(	!Arcade_setIdInt(pA, id_arcade) &&
				!Arcade_setRelSalaInt(pA, rel_sala)&&
				!Arcade_setRelJuegoInt(pA, rel_juego)&&
				!Arcade_setTipoSonido(pA, tipoSonidoInt)&&
				!Arcade_setPais(pA, pais)&&
				!Arcade_setCapFichasInt(pA, cap_fichas)&&
				!Arcade_setNumJugadoresInt(pA, num_jugadores)&&
				pA!=NULL){

				ll_add(pArrayListArcade, pA);
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

int controller_buscarPorIdLinkedListRooms(LinkedList* pArrayListRoom, int id){
	int retorno = -1;
	int i;
	int index;
	Room* r;

	if(pArrayListRoom != NULL && id >= 0)
	{
		for(i=0;i<ll_len(pArrayListRoom);i++){
			r = ll_get(pArrayListRoom, i);
			if(r!=NULL && r->id == id){
				index = ll_indexOf(pArrayListRoom, r);
				retorno = index;
				break;
			}
		}
	}
	return retorno;
}

int controller_buscarPorIdLinkedListGames(LinkedList* pArrayListGame, int id){
	int retorno = -1;
	int i;
	int index;
	Game* g;

	if(pArrayListGame != NULL && id >= 0)
	{
		for(i=0;i<ll_len(pArrayListGame);i++){
			g = ll_get(pArrayListGame, i);
			if(g!=NULL && g->id == id){
				index = ll_indexOf(pArrayListGame, g);
				retorno = index;
				break;
			}
		}
	}
	return retorno;
}

int controller_buscarPorIdLinkedListArcades(LinkedList* pArrayListArcade, int id){
	int retorno = -1;
	int i;
	int index;
	Arcade* a;

	if(pArrayListArcade != NULL && id >= 0)
	{
		for(i=0;i<ll_len(pArrayListArcade);i++){
			a = ll_get(pArrayListArcade, i);
			if(a!=NULL && a->id_arcade == id){
				index = ll_indexOf(pArrayListArcade, a);
				retorno = index;
				break;
			}
		}
	}
	return retorno;
}

int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListGame, LinkedList* pArrayListRooms){
	int retorno = -1;

	int id;
	int opcion;
	int newNumPlayers;
	int newRelJuego;
	int indexModif;
	Arcade* a;

	controller_ListArcade(pArrayListArcade, pArrayListGame, pArrayListRooms);
	if(!utn_getInt("Ingrese id a modificar", "Error. Reingrese.", 1, SIZE_ARCADES, 3, &id)){
		if(pArrayListArcade != NULL && id >= 0)
		{
			indexModif = controller_buscarPorIdLinkedListArcades(pArrayListArcade, id);
			a = ll_get(pArrayListArcade, indexModif);
		}
		if(a!=NULL){
			utn_getInt("Ingrese 0 para modificar cantidad de jugadores, ingrese 1 para modificar el juego.", "Error. Reingrese.", 0, 1, 3, &opcion);
			if(opcion == 0){
				utn_getInt("Ingrese nueva cantidad de jugadores.", "Error. Reingrese.", 0, 9999, 3, &newNumPlayers);
				if(!Arcade_setNumJugadoresInt(a, newNumPlayers)){
					retorno = 0;
				}
			}else{
				if(opcion == 1){
					controller_ListGame(pArrayListGame);
					utn_getInt("Ingrese nuevo juego.", "Error. Reingrese.", 0, 9999, 3, &newRelJuego);
					if(!Arcade_setRelJuegoInt(a, newRelJuego)){
						retorno = 0;
					}
				}
			}
		}else{
			puts("No se pudo modificar.");
		}
	}else{
		puts("Error id a modificar.");
	}
	return retorno;
}

int controller_buscarPorRelSalaLinkedListArcades(LinkedList* pArrayListArcade, int relSala){
	int retorno = -1;
	int i;
	int index;
	Arcade* a;

	if(pArrayListArcade != NULL && relSala >= 0)
	{
		for(i=0;i<ll_len(pArrayListArcade);i++){
			a = ll_get(pArrayListArcade, i);
			if(a!=NULL && a->rel_sala == relSala){
				index = ll_indexOf(pArrayListArcade, a);
				retorno = index;
				break;
			}
		}
	}
	return retorno;
}



int controller_ListGame(LinkedList* pArrayListGame)
{
	int retorno = 0;
	Game* g;
	int cantidad;
	cantidad = ll_len(pArrayListGame); // 3;//

	if(pArrayListGame != NULL){
		printf("\n|-------------------------------------------------------------------------------------------------------|\n");
		  printf("|    ID    |                 NOMBRE                 |            EMPRESA           |      GENERO        |\n");
		  printf("|-------------------------------------------------------------------------------------------------------|\n");

		for(int i=0; i<cantidad;i++){
			g = ll_get(pArrayListGame, i);
			if(g!=NULL){
				Game_printOne(g);
			}
		}
	}else{
		retorno = -1;
	}
	return retorno;
}

int controller_ListRoom(LinkedList* pArrayListRoom)
{
	int retorno = 0;
	Room* r;
	int cantidad;
	cantidad = ll_len(pArrayListRoom); // 3;//

	if(pArrayListRoom != NULL){
		printf("\n|-------------------------------------------------------------------------------------------------------|\n");
		  printf("|    ID    |                 NOMBRE                 |           DIRECCION          |        TIPO        |\n");
		  printf("|-------------------------------------------------------------------------------------------------------|\n");

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

int controller_ListArcade(LinkedList* pArrayListArcade,LinkedList* pArrayListGames,LinkedList* pArrayListRooms)
{
	int retorno = 0;
	Arcade* a;
	int cantidad;
	cantidad = ll_len(pArrayListArcade); // 3;//

	if(pArrayListArcade != NULL && pArrayListGames != NULL && pArrayListRooms != NULL){
		printf("\n|----------------------------------------------------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|------------------------------|\n");
		  printf("|   ID   | R_SALA | R_JUEGO| FICHAS | PLAYERS|        PAIS        |  SONIDO  |        NOMBRE JUEGO          |        EMPRESA JUEGO         |         GENERO JUEGO         |          NOMBRE SALA         |         DIRECCION SALA       |\n");
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

int controller_removeGame(LinkedList* pArrayListGame, int idBaja)
{
	int retorno = -1;
	int indexBaja;

	if(pArrayListGame!=NULL){
		controller_ListGame(pArrayListGame);
		if(idBaja==0){
			if(!utn_getInt("\nIngrese ID a dar de baja\n", "\nError.Reingrese.", 1, ll_len(pArrayListGame), 3, &idBaja)){
			printf("\nID a dar de baja: %d\n",idBaja);
			}
		}
		indexBaja = controller_buscarPorIdLinkedListGames(pArrayListGame, idBaja);
		if(indexBaja>0){
			printf("Index a dar de baja: %d\n",indexBaja);
			if(!ll_remove(pArrayListGame,indexBaja)){
				retorno = 0;
			}
		}else{
			puts("No se encontró el ID.");
		}
	}
    return retorno;
}

int controller_removeRoom(LinkedList* pArrayListRoom,int idBaja,LinkedList* pArrayListArcade,LinkedList* pArrayListGame)
{
	int retorno = -1;
	int indexBaja;
	int indexArcadeBaja;

	if(pArrayListRoom!=NULL){
		controller_ListRoom(pArrayListRoom);
		if(idBaja==0){
			if(!utn_getInt("\nIngrese ID a dar de baja\n", "\nError.Reingrese.", 1, ll_len(pArrayListRoom), 3, &idBaja)){
				printf("\nID a dar de baja: %d\n",idBaja);
			}
		}
		indexBaja = controller_buscarPorIdLinkedListRooms(pArrayListRoom, idBaja);
		if(indexBaja>0){
			printf("Index de room a dar de baja: %d\n",indexBaja);
			//r = ll_get(pArrayListRooms, indexBaja);
			for(int i=0;i<ll_len(pArrayListArcade);i++){
				if((indexArcadeBaja = controller_buscarPorRelSalaLinkedListArcades(pArrayListArcade, idBaja))>=0){
					//a = ll_get(pArrayListArcade,indexArcadeBaja);
					ll_remove(pArrayListArcade,indexArcadeBaja);
				}
			}
			if(!ll_remove(pArrayListRoom,indexBaja)){
				retorno = 0;
			}
		}else{
			puts("No se encontró el ID.");
		}
	}
    return retorno;
}

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

/*
int controller_sortGame(LinkedList* pArrayListGame)
{
	int retorno = 0;
	int opcion;

	if(pArrayListGame!=NULL){

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
			ll_sort(pArrayListGame, Game_SortId, 1);
			break;
		case 2:
			ll_sort(pArrayListGame, Game_SortApellido, 1);
			break;
		case 3:
			ll_sort(pArrayListGame, Game_SortCodigoVuelo, 1);
			break;
		default:
			break;
	}
    return retorno;
}
*/
int controller_removeArcade(LinkedList* pArrayListArcade, int idBaja,LinkedList* pArrayListGames,LinkedList* pArrayListRooms)
{
	int retorno = -1;
	int indexBaja;
	int intSeguro;

	if(pArrayListArcade!=NULL){
		controller_ListArcade(pArrayListArcade, pArrayListGames, pArrayListRooms);
		if(idBaja==0){
			if(!utn_getInt("\nIngrese ID a dar de baja\n", "\nError.Reingrese.", 1, ll_len(pArrayListArcade), 3, &idBaja)){
				printf("\nID a dar de baja en Arcades: %d\n",idBaja);
			}
		}
		indexBaja = controller_buscarPorIdLinkedListArcades(pArrayListArcade, idBaja);
		if(indexBaja>0){
			printf("Index a dar de baja en Arcades: %d\n",indexBaja);
			utn_getInt("Está seguro? S(1) N(2)", "Error. Indique 1 o 0.", 0, 1, 3, &intSeguro);
			if(intSeguro==1){
				if(!ll_remove(pArrayListArcade,indexBaja)){
					retorno = 0;
				}
			}
		}else{
			puts("No se encontró el ID.");
		}
	}
    return retorno;
}

int controller_saveGamesAsText(char* path , LinkedList* pArrayListGame)
{
	int retorno = 0;
	int id;
	char nombre[100];
	char empresa[100];
	int generoInt;
	char generoChar[100];

	FILE* fp = fopen(path,"w");
	Game* g;
	int tam = ll_len(pArrayListGame);

	if(fp!=NULL){
		fprintf(fp,"id,nombre,empresa,genero\n");
		for(int i = 0;i<tam;i++){
			g = ll_get(pArrayListGame, i);
			if(g!=NULL){
				if(!Game_getId(g, &id) &&
						!Game_getNombre(g, nombre) &&
						!Game_getEmpresa(g, empresa) &&
						!Game_getGenero(g, &generoInt)){
					Game_conversorGeneroGameReverse(generoChar,&generoInt);
					fprintf(fp,"%d,%s,%s,%s\n",id,nombre,empresa,generoChar);
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

int controller_saveRoomsAsText(char* path , LinkedList* pArrayListRoom)
{
	int retorno = 0;
	int id;
	char nombre[100];
	char direccion[100];
	int tipoInt;
	char tipoChar[100];

	FILE* fp = fopen(path,"w");
	Room* r;
	int tam = ll_len(pArrayListRoom);

	if(fp!=NULL){
		fprintf(fp,"id,nombre,tipo,direccion\n");
		for(int i = 0;i<tam;i++){
			r = ll_get(pArrayListRoom, i);
			if(r!=NULL){
				if(!Room_getId(r, &id) &&
						!Room_getNombre(r, nombre) &&
						!Room_getDireccion(r, direccion) &&
						!Room_getTipo(r, &tipoInt)){
					Room_conversorTipoRoomReverse(tipoChar,&tipoInt);
					fprintf(fp,"%d,%s,%s,%s\n",id,nombre,tipoChar,direccion);
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

int controller_saveArcadesAsText(char* path , LinkedList* pArrayListArcade)
{
	int retorno = 0;
	int id_arcade;
	int rel_sala;
	int rel_juego;
	int tipoSonidoInt;
	char tipoSonidoStr[TIPO_SONIDO_LEN];
	int cap_fichas;
	int num_jugadores;
	char pais[PAIS_LEN];

	FILE* fp = fopen(path,"w");
	Arcade* a;
	int tam = ll_len(pArrayListArcade);

	if(fp!=NULL){
		fprintf(fp,"id_arcade,rel_sala,rel_juego,sound_type,token_capacity,num_players,country\n");
		for(int i = 0;i<tam;i++){
			a = ll_get(pArrayListArcade, i);
			if(a!=NULL){
				if(!Arcade_getId(a, &id_arcade)){
					if(!Arcade_getTipoSonido(a, &tipoSonidoInt)&&
					   !Arcade_getRelSala(a, &rel_sala)&&
					   !Arcade_getPais(a, pais)){
							if(!Arcade_getRelJuego(a, &rel_juego)&&
							   !Arcade_getCapFichas(a, &cap_fichas)&&
							   !Arcade_getNumJugadores(a, &num_jugadores)){
									Arcade_conversorTipoSonidoReverse(tipoSonidoStr,&tipoSonidoInt);
									fprintf(fp,"%d,%d,%d,%s,%d,%d,%s\n",id_arcade,rel_sala,rel_juego,tipoSonidoStr,cap_fichas,num_jugadores,pais);
							}else{
								puts("Fallaron reljuego, capfichas o numjug");
								retorno = -7;
							}
					}else{
						puts("Fallaron tiposonido o relsala");
						retorno = -6;
					}
				}else{
					puts("Fallaron getId o getPais");
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

int controller_sortArcade(LinkedList* pArrayListArcade)
{
	int retorno = -1;
	if(pArrayListArcade != NULL)
	{
		ll_sort(pArrayListArcade, Arcade_SortId, 0);
		retorno = 0;
	}
    return retorno;
}

int controller_sortGame(LinkedList* pArrayListGames)
{
	int retorno = -1;
	if(pArrayListGames != NULL)
	{
		ll_sort(pArrayListGames, Games_SortName, 0);
		retorno = 0;
	}
    return retorno;
}
