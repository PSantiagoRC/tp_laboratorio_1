#include "parser.h"


int parser_GameFromText(FILE* pFile , LinkedList* pArrayListGame)
{
	int retorno = 0;
	char idAux[100];
	char nombreAux[100];
	char empresaAux[100];
	char nombreAuxCut[100];
	char empresaAuxCut[100];
	char generoAux[100];
	//int generoIntAux;
    char falsa[100];
    Game* gAux;

	if(pFile != NULL && pArrayListGame !=NULL){

		fscanf(pFile,"%[^\n]\n",falsa); //Headers

    	while(!feof(pFile))// for(int i=0;i<3;i++)//
    	{
    		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\r\n]\n",idAux,nombreAux,empresaAux,generoAux);

    		if(strlen(nombreAux)==30){
        		strncpy(nombreAuxCut,nombreAux,29);
    		}else{
        		strncpy(nombreAuxCut,nombreAux,30);
    		}

    		if(strlen(empresaAux)==25){
    			strncpy(empresaAuxCut,empresaAux,24);
    		}else{
    			strncpy(empresaAuxCut,empresaAux,25);
    		}


			if((gAux = Game_newParametros(idAux,nombreAuxCut,empresaAuxCut,generoAux))!=NULL){
				ll_add(pArrayListGame, gAux);
			}else{
				retorno = -2;//FUNCION newParametros devuelve puntero a NULL
			}
    	}
	}else{
	retorno = -1; //Archivo cerrado o array NULL
	}
	return retorno;
}

int parser_RoomFromText(FILE* pFile , LinkedList* pArrayListRoom)
{
	int retorno = 0;
	char idAux[100];
	char nombreAux[100];
	char direccionAux[100];
	char nombreAuxCut[100];
	char direccionAuxCut[100];
	char tipoAuxStr[100];
	int tipoIntAux;
    char falsa[100];
    Room* rAux;

	if(pFile != NULL && pArrayListRoom !=NULL){

		fscanf(pFile,"%[^\n]\n",falsa); //Headers

    	while(!feof(pFile))// for(int i=0;i<3;i++)//
    	{
    		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\r\n]\n",idAux,nombreAux,tipoAuxStr,direccionAux);

    		strncpy(nombreAuxCut,nombreAux,30);
    		strncpy(direccionAuxCut,direccionAux,30);

    		Room_conversorTipoRoom(tipoAuxStr, &tipoIntAux);

			if((rAux = Room_newParametros(idAux,nombreAuxCut,direccionAuxCut,tipoIntAux))!=NULL){
				ll_add(pArrayListRoom, rAux);
			}else{
				puts("Falla en newParametros de Room");
				retorno = -2;//FUNCION newParametros devuelve puntero a NULL
			}
    	}
	}else{
	retorno = -1; //Archivo cerrado o array NULL
	}
	return retorno;
}

int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	int retorno = 0;
	char idArcadeAux[100];
	char relSalaAux[100];
	char relJuegoAux[100];
	char paisAux[100];
	char capacidadFichasAux[100];
	char numJugadoresAux[100];

	int tipoSonidoIntAux;
	char tipoSonidoStrAux[100];

    char falsa[100];
    Arcade* aAux;

	if(pFile != NULL && pArrayListArcade !=NULL){

		fscanf(pFile,"%[^\n]\n",falsa); //Headers

    	while(!feof(pFile))//
    	{
    		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r\n]\n",idArcadeAux,relSalaAux,relJuegoAux,tipoSonidoStrAux,capacidadFichasAux,numJugadoresAux,paisAux);

    		Arcade_conversorTipoSonido(tipoSonidoStrAux, &tipoSonidoIntAux);

			if((aAux = Arcade_newParametros(idArcadeAux,relSalaAux,relJuegoAux,tipoSonidoIntAux, capacidadFichasAux, numJugadoresAux, paisAux))!=NULL){
				ll_add(pArrayListArcade, aAux);
			}else{
				puts("Falla en newParametros de Arcade");
				retorno = -2;//FUNCION newParametros devuelve puntero a NULL
			}
    	}
	}else{
	retorno = -1; //Archivo cerrado o array NULL
	}
	return retorno;
}
