#ifndef ARCADES_H_
#define ARCADES_H_
#include "UTN4.h"
#include "LinkedList.h"

#define PAIS_LEN 60
#define TIPO_SONIDO_LEN 60

#define SIZE_ARCADES 9999

#define MONO 0
#define STEREO 1
#define ERROR_TYPE_SOUND 9

#define SIZE_FICHAS 1000


typedef struct
{
	int id_arcade;
	int rel_sala;
	int rel_juego;
	int tipoSonido;
	int cap_fichas;
	int num_jugadores;
	char pais[PAIS_LEN];
}Arcade;

int Arcade_conversorTipoSonido(char* tipoSonidoStr,int* tipoSonidoInt);

Arcade* Arcade_new();
Arcade* Arcade_newParametros(char* idArcadeStr,char* relSalaStr,char* relJuegoStr,int soundTypeInt, char* capacidadFichasStr, char* numPlayersStr, char* paisStr);
void Arcade_delete();
int Arcade_buscarIndexPorIdArray(LinkedList* arrayPunterosArcades, int id);

//int Arcade_setId(Arcade* this,int id);
int Arcade_setIdInt(Arcade* this,int idArcadeInt);
int Arcade_getId(Arcade* this,int* idArcade);
int Arcade_setIdStr(Arcade* this,char* idStr);

int Arcade_setRelJuegoStr(Arcade* this,char * relJuegoStr);
int Arcade_getRelJuego(Arcade* this,int* relJuego);
int Arcade_setRelJuegoInt(Arcade* this,int relJuegoInt);

int Arcade_setRelSalaStr(Arcade* this,char * relSalaStr);
int Arcade_getRelSala(Arcade* this,int* relSala);
int Arcade_setRelSalaInt(Arcade* this,int relSalaInt);

int Arcade_setCapFichas(Arcade* this,char* capFichasStr);
int Arcade_getCapFichas(Arcade* this,int* capFichas);
int Arcade_setCapFichasInt(Arcade* this,int capFichasInt);

int Arcade_setNumJugadores(Arcade* this,char* numJugadoresStr);
int Arcade_getNumJugadores(Arcade* this,int* numJugadores);
int Arcade_setNumJugadoresInt(Arcade* this,int numJugadoresInt);

int Arcade_setTipoSonido(Arcade* this,int tipoSonido);
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);
int Arcade_setTipoStr(Arcade* this,char* tipoStr);

int Arcade_setPais(Arcade* this,char* pais);
int Arcade_getPais(Arcade* this,char* pais);

void Arcade_printOne(Arcade* a, LinkedList* pArrayListGames,LinkedList* pArrayListRooms);

int Arcade_SortApellido(void* item1,void* item2);
int Arcade_SortId(void* item1,void* item2);
int Arcade_SortCodigoVuelo(void* item1,void* item2);

int Arcade_conversorTipoSonidoReverse(char* tipoArcadeStr,int *tipoArcadeInt);

#endif /* PASSENGER_H_ */
