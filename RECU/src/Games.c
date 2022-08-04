#include "Games.h"

Game* Game_new(){
	Game* g;
	g = (Game*) malloc(sizeof(Game)*1);
	if(g!=NULL){
		g->id = 0;
		g->nombre[0]='\0'; //es el final de un string (en este caso vacío)
		g->empresa[0]='\0';
		g->genero = 0;
		//p->precio=0;
	}
	return g;
}

int Game_conversorGeneroGame(char* generoGameStr,int *generoGame){
	int retorno = 0;
	if(strcmp(generoGameStr,"Aventura")==0){
		*generoGame = AVENTURA;
	}else{
		if(strcmp(generoGameStr,"Laberinto")==0){
			*generoGame = LABERINTO;
		}else{
			if(strcmp(generoGameStr,"Plataforma")==0){
				*generoGame = PLATAFORMA;
			}else{
				if(strcmp(generoGameStr,"Otro")==0){
					*generoGame = OTRO;
				}else{
					*generoGame = ERROR_TYPE;
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}

int Game_conversorGeneroGameReverse(char* generoGameStr,int *generoGameInt){
	int retorno = 0;
	if(*generoGameInt == AVENTURA){
		strncpy(generoGameStr,"Aventura",50);
	}else{
		if(*generoGameInt == LABERINTO){
			strncpy(generoGameStr,"Laberinto",50);
		}else{
			if(*generoGameInt == PLATAFORMA){
				strncpy(generoGameStr,"Plataforma",50);
			}else{
				if(*generoGameInt == OTRO){
					strncpy(generoGameStr,"Otro",50);
				}else{
					strncpy(generoGameStr,"Error",50);
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}

Game* Game_newParametros(char* idStr,char* nombreStr, char* empresaStr, char* generoStr){

	Game* retorno = NULL;
	Game* g = Game_new();
	int generoGame;

	if(g!=NULL && idStr!=NULL && nombreStr!=NULL && generoStr!=NULL && empresaStr!=NULL){

		Game_conversorGeneroGame(generoStr,&generoGame);

		Game_setIdStr(g, idStr);
		Game_setNombre(g, nombreStr);
		Game_setEmpresa(g, empresaStr);
		Game_setGenero(g, generoGame);

		retorno = g;
	}else{
		puts("Algún campo resultó NULL.");
		retorno = NULL;
		if(g==NULL){
			puts("g es NULL");
		}else{
			if(idStr==NULL){
			puts("idStr es NULL");
			}
		}
	}
	return retorno;
}

int Game_buscarIndexPorIdArray(LinkedList* arrayPunterosGames, int id){
	int retorno = -1;
	Game* g = NULL;
	int limite = ll_len(arrayPunterosGames);
	if(arrayPunterosGames != NULL && limite >0 && id >= 0)
	{
		retorno =-2;
		for(int i=0;i<limite;i++){
			g = ll_get(arrayPunterosGames,i);
			if(g!=NULL && g->id == id){
				retorno = ll_indexOf(arrayPunterosGames, g);
				break;
			}
		}
	}
	return retorno;
}

int Game_getId(Game* this,int* id){
	int retorno =-1;
	if(this !=NULL && id!=NULL)
	{
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}

void Game_printOne(Game* p){

	int id;
	char nombre[NOMBRE_GAME_LEN];
	char empresa[EMPRESA_LEN];
	int generoGameInt;
	char generoGameStr[GENERO_LEN];

	Game_getId(p, &id);
	Game_getNombre(p, nombre);
	Game_getEmpresa(p, empresa);
	Game_getGenero(p, &generoGameInt);

	Game_conversorGeneroGameReverse(generoGameStr, &generoGameInt);

	printf("|%10d|%40s|%30s|%20s|\n",
								   id,
								   nombre,
								   empresa,
								   generoGameStr);
}

int Game_setId(Game* this,int id){ //ACÁ NO VAN FLECHITAS! ESTO SE HACE PARA ATOMIZAR MÁS EL CÓDIGO, ENCAPSULAR LO QUE HACEMOS
	int retorno = -1;

	if(this!=NULL && id>0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Game_setIdStr(Game* this,char * idStr){ //ACÁ NO VAN FLECHITAS! ESTO SE HACE PARA ATOMIZAR MÁS EL CÓDIGO, ENCAPSULAR LO QUE HACEMOS
	int retorno = -1;
	int idAux;

	if(this!=NULL && idStr!=NULL){
		if(!isInt(idStr)){
			idAux = atoi(idStr);
		}
		if(idAux>0 && idAux<=SIZE_GAMES){
			this->id = idAux;
			retorno = 0;
		}
	}
	return retorno;
}

int Game_setNombre(Game* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,NOMBRE_GAME_LEN);
		retorno = 0;
	}
	return retorno;
}

int Game_setEmpresa(Game* this,char* empresa){
	int retorno = -1;

	if(this != NULL && empresa != NULL)
	{
		//myGetsLocal(empresaAux, EMPRESA_LEN, empresa);
		strncpy(this->empresa,empresa,EMPRESA_LEN);
		retorno = 0;
	}
	return retorno;
}

int Game_setGenero(Game* this,int genero){
	int retorno = -1;
	if(this != NULL && genero >=0)
	{
		if(genero>=0 && genero<=3){ //4? O incluir el \0?
			retorno = 0;
		}else{
			genero = 9;
			retorno = 0;
		}
		this->genero = genero;
	}
	return retorno;
}

int Game_getNombre(Game* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_GAME_LEN);
	}
	return retorno;
}

int Game_getEmpresa(Game* this,char* empresa){
	int retorno = -1;
	if(this != NULL && empresa != NULL)
	{
		retorno = 0;
		strncpy(empresa,this->empresa,EMPRESA_LEN);
	}
	return retorno;
}

int Game_getGenero(Game* this,int* generoGame){
	int retorno = -1;
	if(this != NULL && generoGame != NULL)
	{
		retorno = 0;
		*generoGame = this->genero;
	}
	return retorno;
}

/*
int Game_getGeneroStr(Game* this,char* generoGame){
	int retorno = -1;
	if(this != NULL && generoGame != NULL)
	{
		retorno = 0;
		strncpy(generoGame,this->genero,GENERO_LEN);
	}
	return retorno;
}
*/



int Game_SortEmpresa(void* item1,void* item2){
	int retorno = 0;

	char empresa1[EMPRESA_LEN];
	char empresa2[EMPRESA_LEN];

	Game* p1;
	Game* p2;

	p1 = (Game*) item1;
	p2 = (Game*) item2;

	if(!Game_getEmpresa(p1, empresa1) && !Game_getEmpresa(p2, empresa2)){
		retorno = strcmp(p1->empresa,p2->empresa);
	}
	return retorno;
}



/*
int Game_SortCodigoVuelo(void* item1,void* item2){
	int retorno = 0;

	char codigo1[CODIGO_LEN];
	char codigo2[CODIGO_LEN];

	Game* p1;
	Game* p2;

	p1 = (Game*) item1;
	p2 = (Game*) item2;

	if(!Game_getCodigoVuelo(p1, codigo1) && !Game_getCodigoVuelo(p2, codigo2)){
		retorno = strcmp(p1->codigoVuelo,p2->codigoVuelo);
	}
	return retorno;
}
*/

int Game_SortId(void* item1,void* item2){
	int retorno = 0;

	int id1;
	int id2;

	Game* p1;
	Game* p2;

	p1 = (Game*) item1;
	p2 = (Game*) item2;

	if(!Game_getId(p1, &id1) && !Game_getId(p2, &id2)){
		if(p1->id > p2->id){
			retorno =1;
		}else{
			retorno =-1;
		}
	}
	return retorno;
}

int Game_SortName(void* item1,void* item2){
	int retorno = 0;

	char name1[NOMBRE_GAME_LEN];
	char name2[NOMBRE_GAME_LEN];

	Game* g1;
	Game* g2;

	g1 = (Game*) item1;
	g2 = (Game*) item2;

	if(!Game_getNombre(g1, name1) && !Game_getNombre(g2, name2)){
		retorno = strcmp(g1->nombre,g2->nombre);
	}
	return retorno;
}
