#include "Arcades.h"
#include <ctype.h>
#include <stdio.h>
#include "UTN4.h"
#include "Games.h"
#include "Rooms.h"


Arcade* Arcade_new(){
	Arcade* a;
	a = (Arcade*) malloc(sizeof(Arcade)*1);
	if(a!=NULL){
		a->id_arcade = 0;
		a->rel_juego = 0;
		a->rel_sala = 0;
		a->pais[0]='\0'; //es el final de un string (en este caso vacío)
		a->cap_fichas = 0;
		a->num_jugadores = 0;
		a->tipoSonido = 0;
	}
	return a;
}

int Arcade_conversorTipoSonido(char* tipoSonidoStr,int *tipoSonido){
	int retorno = 0;
	if(strcmp(tipoSonidoStr,"mono")==0){
		*tipoSonido = MONO;
	}else{
		if(strcmp(tipoSonidoStr,"stereo")==0){
			*tipoSonido = STEREO;
		}else{
			*tipoSonido = ERROR_TYPE_SOUND;
			retorno = -1;
		}
	}
	return retorno;
}

int Arcade_conversorTipoSonidoReverse(char* tipoSonidoStr,int *tipoSonidoInt){
	int retorno = 0;
	if(*tipoSonidoInt == MONO){
		strncpy(tipoSonidoStr,"mono",50);
	}else{
		if(*tipoSonidoInt == STEREO){
			strncpy(tipoSonidoStr,"stereo",50);
		}else{
			strncpy(tipoSonidoStr,"Error",50);
			retorno = -1;
		}
	}
	return retorno;
}

int Arcade_buscarIndexPorIdArray(LinkedList* arrayPunterosArcades, int id){
	int retorno = -1;
	Arcade* a = NULL;
	int limite = ll_len(arrayPunterosArcades);
	if(arrayPunterosArcades != NULL && limite >0 && id >= 0)
	{
		retorno =-2;
		for(int i=0;i<limite;i++){
			a = ll_get(arrayPunterosArcades,i);
			if(a!=NULL && a->id_arcade == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

Arcade* Arcade_newParametros(char* idArcadeStr,char* relSalaStr,char* relJuegoStr,int soundTypeInt, char* capacidadFichasStr, char* numPlayersStr, char* paisStr){

	Arcade* retorno = NULL;
	Arcade* a = Arcade_new();
	//int tipoSonidoInt;

	if(a!=NULL){
		if(idArcadeStr!=NULL && relSalaStr!=NULL && relJuegoStr!=NULL && soundTypeInt>-1 && capacidadFichasStr!=NULL && numPlayersStr!=NULL && paisStr!=NULL){
			//Arcade_conversorTipoSonido(tipoStr,&tipoSonidoInt);

			if(!Arcade_setIdStr(a, idArcadeStr)){
			}else{
				puts("\nsetId falló");
			}
			if(!Arcade_setRelJuegoStr(a, relJuegoStr)){
			}else{
				puts("\nsetRelJuego falló");
			}
			if(!Arcade_setRelSalaStr(a, relSalaStr)){
			}else{
				puts("\nsetRelSala falló");
			}
			if(!Arcade_setNumJugadores(a, numPlayersStr)){
			}else{
				puts("\nsetNumJugadores falló");
			}
			if(!Arcade_setCapFichas(a, capacidadFichasStr)){
			}else{
				puts("\nsetCapFichas falló");
			}
			if(!Arcade_setTipoSonido(a, soundTypeInt)){
			}else{
				puts("\nsetRelSala falló");
			}
			if(!Arcade_setPais(a, paisStr)){
			}else{
				puts("\nsetPais falló");
			}
			retorno = a;
		}else{
			puts("\nAlgún campo es NULL");
		}
	}else{
		puts("\nEl espacio encontrado para la entidad Arcade es NULL.");
		retorno = NULL;
		if(a==NULL){
			puts("a es NULL");
		}else{
			if(idArcadeStr==NULL){
			puts("idStr es NULL");
			}
		}
	}
	return retorno;
}

void Arcade_printOne(Arcade* a, LinkedList* pArrayListGames,LinkedList* pArrayListRooms){

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

int Arcade_setIdInt(Arcade* this,int idArcadeInt){
	int retorno = -1;

	if(this!=NULL && idArcadeInt>=0 && idArcadeInt<SIZE_ARCADES){
			this->id_arcade = idArcadeInt;
			retorno = 0;
		}
	return retorno;
}

int Arcade_setIdStr(Arcade* this,char * idStr){ //ACÁ NO VAN FLECHITAS! ESTO SE HACE PARA ATOMIZAR MÁS EL CÓDIGO, ENCAPSULAR LO QUE HACEMOS
	int retorno = -1;
	int idAux;

	if(this!=NULL && idStr!=NULL){
		if(!isInt(idStr)){
			idAux = atoi(idStr);
		}
		if(idAux>0 && idAux<=SIZE_ARCADES){
			this->id_arcade = idAux;
			retorno = 0;
		}
	}
	return retorno;
}

int Arcade_setRelSalaStr(Arcade* this,char * relSalaStr){
	int retorno = -1;
	int relSalaAux;

	if(this!=NULL && relSalaStr!=NULL){
		if(!isInt(relSalaStr)){
			relSalaAux = atoi(relSalaStr);
		}
		if(relSalaAux>0 && relSalaAux<=SIZE_ARCADES){
			this->rel_sala = relSalaAux;
			retorno = 0;
		}
	}
	return retorno;
}

int Arcade_setRelJuegoStr(Arcade* this,char * relJuegoStr){
	int retorno = -1;
	int relJuegoAux;

	if(this!=NULL && relJuegoStr!=NULL){
		if(!isInt(relJuegoStr)){
			relJuegoAux = atoi(relJuegoStr);
		}
		if(relJuegoAux>0 && relJuegoAux<=SIZE_GAMES){
			this->rel_juego = relJuegoAux;
			retorno = 0;
		}
	}
	return retorno;
}

int Arcade_setRelJuegoInt(Arcade* this,int relJuegoInt){
	int retorno = -1;

	if(this!=NULL && relJuegoInt>=0 && relJuegoInt<SIZE_GAMES){
			this->rel_juego = relJuegoInt;
			retorno = 0;
		}
	return retorno;
}

int Arcade_setRelSalaInt(Arcade* this,int relSalaInt){
	int retorno = -1;

	if(this!=NULL && relSalaInt>=0 && relSalaInt<SIZE_GAMES){
			this->rel_sala = relSalaInt;
			retorno = 0;
		}
	return retorno;
}

int Arcade_setNumJugadoresInt(Arcade* this,int numJugadoresInt){
	int retorno = -1;

	if(this!=NULL && numJugadoresInt>=0 && numJugadoresInt<SIZE_GAMES){
			this->num_jugadores = numJugadoresInt;
			retorno = 0;
		}
	return retorno;
}

int Arcade_setCapFichasInt(Arcade* this,int capFichasInt){
	int retorno = -1;

	if(this!=NULL && capFichasInt>=0 && capFichasInt<SIZE_FICHAS){
			this->cap_fichas = capFichasInt;
			retorno = 0;
		}
	return retorno;
}

int Arcade_setPais(Arcade* this,char* pais){
	int retorno = -1;
	if(this != NULL && pais != NULL)
	{
		strncpy(this->pais,pais,PAIS_LEN);
		retorno = 0;
	}
	return retorno;
}

int Arcade_setTipoSonido(Arcade* this,int tipoSonido){
	int retorno = -1;
	if(this != NULL && tipoSonido >=0)
	{
		if(tipoSonido>=0 && tipoSonido<=1){
			retorno = 0;
		}else{
			tipoSonido = 9;
			retorno = 0;
		}
		this->tipoSonido = tipoSonido;
	}
	return retorno;
}

int Arcade_setCapFichas(Arcade* this,char* capFichasStr){
	int retorno = -1;
	if(this != NULL && capFichasStr != NULL)
	{
		if(!isInt(capFichasStr)){
			retorno = 0;
			this->cap_fichas = atoi(capFichasStr);
		}
	}
	return retorno;
}

int Arcade_setNumJugadores(Arcade* this,char* numJugadoresStr){
	int retorno = -1;
	if(this != NULL && numJugadoresStr != NULL)
	{
		if(!isInt(numJugadoresStr)){
			retorno = 0;
			this->num_jugadores = atoi(numJugadoresStr);
		}
	}
	return retorno;
}

int Arcade_getPais(Arcade* this,char* pais){
	int retorno = -1;
	if(this != NULL && pais != NULL)
	{
		retorno = 0;
		strncpy(pais,this->pais,PAIS_LEN);
	}
	return retorno;
}

int Arcade_getId(Arcade* this,int* idArcade){
	int retorno = -1;
	if(this != NULL && idArcade != NULL)
	{
		retorno = 0;
		*idArcade = this->id_arcade;
	}else{
		puts("Error Arcade_getId");
		printf("idArcade es %d",this->id_arcade);
	}
	return retorno;
}

int Arcade_getRelSala(Arcade* this,int* relSala){
	int retorno = -1;
	if(this != NULL && relSala != NULL)
	{
		retorno = 0;
		*relSala = this->rel_sala;
	}
	return retorno;
}

int Arcade_getRelJuego(Arcade* this,int* relJuego){
	int retorno = -1;
	if(this != NULL && relJuego != NULL)
	{
		retorno = 0;
		*relJuego = this->rel_juego;
	}
	return retorno;
}

int Arcade_getCapFichas(Arcade* this,int* capFichas){
	int retorno = -1;
	if(this != NULL && capFichas != NULL)
	{
		retorno = 0;
		*capFichas = this->cap_fichas;
	}
	return retorno;
}

int Arcade_getNumJugadores(Arcade* this,int* numJugadores){
	int retorno = -1;
	if(this != NULL && numJugadores != NULL)
	{
		retorno = 0;
		*numJugadores = this->num_jugadores;
	}
	return retorno;
}

int Arcade_getTipoSonido(Arcade* this,int* tipoSonido){
	int retorno = -1;
	if(this != NULL && tipoSonido != NULL)
	{
		retorno = 0;
		*tipoSonido = this->tipoSonido;
	}
	return retorno;
}

/*
int Arcade_SortDireccion(void* item1,void* item2){
	int retorno = 0;

	char direccion1[DIRECCION_LEN];
	char direccion2[DIRECCION_LEN];

	Arcade* p1;
	Arcade* p2;

	p1 = (Arcade*) item1;
	p2 = (Arcade*) item2;

	if(!Arcade_getDireccion(p1, direccion1) && !Arcade_getDireccion(p2, direccion2)){
		retorno = strcmp(p1->direccion,p2->direccion);
	}
	return retorno;
}


int Arcade_SortCodigoVuelo(void* item1,void* item2){
	int retorno = 0;

	char codigo1[CODIGO_LEN];
	char codigo2[CODIGO_LEN];

	Arcade* p1;
	Arcade* p2;

	p1 = (Arcade*) item1;
	p2 = (Arcade*) item2;

	if(!Arcade_getCodigoVuelo(p1, codigo1) && !Arcade_getCodigoVuelo(p2, codigo2)){
		retorno = strcmp(p1->codigoVuelo,p2->codigoVuelo);
	}
	return retorno;
}


int Arcade_SortId(void* item1,void* item2){
	int retorno = 0;

	int id1;
	int id2;

	Arcade* p1;
	Arcade* p2;

	p1 = (Arcade*) item1;
	p2 = (Arcade*) item2;

	if(!Arcade_getId(p1, &id1) && !Arcade_getId(p2, &id2)){
		if(p1->id > p2->id){
			retorno =1;
		}else{
			retorno =-1;
		}
	}
	return retorno;
}
*/

