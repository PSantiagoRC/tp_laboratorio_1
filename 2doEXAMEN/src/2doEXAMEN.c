#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "UTN4.h"
#include "Controller.h"
//#include "Games.h"

#define LEN_PATH 100

//PUNTO EXTRA: OBTENER UNA NUEVA LISTA FILTRADA (BASARLO EN SORT)

int main()
{
	setbuf(stdout,NULL);

	LinkedList* punterosGames = ll_newLinkedList();
	LinkedList* punterosRooms = ll_newLinkedList();
	LinkedList* punterosArcades = ll_newLinkedList();

	int option = 0;
	char pathGames[LEN_PATH] = "JUEGOS.csv";
	char pathRooms[LEN_PATH] = "SALAS.csv";
	char pathArcades[LEN_PATH] = "ARCADES.csv";

	int flagSave = 0;

    do{
    	utn_getInt("\n********* MENU **********"
    			   "\n1)Alta de salón"
    			   "\n2)Baja salón (y sus arcades)"
    			   "\n3)Listar salones"
    			   "\n4)Alta de arcade"
    			   "\n5)Modificar arcade (cantidad jugadores, juego instalado)"
    			   "\n6)Baja de arcade"
    			   "\n7)Listar arcades"
    			   "\n8)Alta Juego"
    			   "\n9)Listar Juegos"
    			   "\n"
    			   "\nINFORMES"
    			   "\n10)Listar salones con mas de 4 arcades (id del salon, nombre direccion, tipo de salon)"
    			   "\n11)Listar  los  arcade  para  más  de  2  jugadores,  indicando  ID  de  arcade,  cantidad  de  jugadores, nombre  del juego,  su género y nombre del salón al que pertenece."
    			   "\n12)Listar toda la información de un salón en específico ingresado por el usuario. Imprimir ID de salón, nombre, tipo y dirección."
    			   "\n13)Un salón se encuentra completo si posee al menos 4 juegos del género plataforma, 3 del género laberinto y 5 del género Aventura. Listar los salones que cumplan con este mínimo de requisito."
    			   "\n14)Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos los arcade con sus datos junto con el nombre del juego que lo compone."
    			   "\n15)Imprimir el salón con más cantidad de arcade, indicando todos los datos del salón y la cantidad de arcade que posee. Ordenado de manera ascendente."
    			   "\n16)Listar los arcades que cumplan con sonido MONO y el género de su juego sea PLATAFORMA, informando nombre de juego, género y cantidad de jugadores que soporta el arcade. El listado deberá estar ordenado por nombre de juego."
    			   "\n"
    			   "\nCARGA Y GUARDADO"
    			   "\n30)Cargar datos de Juegos, Salas y Arcades desde archivo csv en modo texto"
    			   "\n40)Guardar datos de Juegos, Salas y Arcades en modo texto"
    			   "\n50)SALIR"
    			   "\n",
				   "\nError. Reingrese.", 0, 40 , 3, &option);

        switch(option)
        {
			case 1: //ALTA SALA
				if(!controller_addRoom(punterosRooms)){
						puts("\nAlta OK.");
				}else{
					puts("\nProblema con alta.");
				}
				break;

            case 2: //BAJA SALA
            	if(!controller_removeRoom(punterosRooms, 0, punterosArcades,punterosGames)){
            		puts("\nBaja OK. FALTA QUE BORRE SUS ARCADES.");
            	}else{
            		puts("\nProblema con baja.");
            	}
				break;

            case 3: //LISTAR SALONES
            	if(punterosRooms!=NULL && ll_len(punterosRooms)>0){
            		if(!controller_ListRoom(punterosRooms)){
            			puts("Listado OK.");
            		}
            	}
				break;

            case 4: //ALTA ARCADE
				if(!controller_addArcade(punterosArcades, punterosRooms, punterosGames)){
						puts("\nAlta OK.");
				}else{
					puts("\nProblema con alta.");
				}
				break;

            case 5: //MODIFICACION
            	if(!controller_editArcade(punterosArcades, punterosGames,punterosRooms)){
            		if(!controller_ListArcade(punterosArcades, punterosGames, punterosRooms)){
            			puts("\nModificacion OK.");
            		}
            	}else{
            		puts("\nProblema con modificacion.");
            	}

              	break;

            case 6: //BAJA
            	if(!controller_removeArcade(punterosArcades, 0, punterosGames, punterosRooms)){
            		puts("\nBaja OK.");
            	}else{
            		puts("\nProblema con baja.");
            	}
				break;

            case 7: //LISTAR ARCADES
            	if(punterosArcades!=NULL && ll_len(punterosArcades)>0){
            		if(!controller_ListArcade(punterosArcades,punterosGames,punterosRooms)){
            			puts("Listado OK.");
            		}
            	}
				break;

        	case 8: //ALTA
				if(!controller_addGame(punterosGames)){
						puts("\nAlta OK.");
				}else{
					puts("\nProblema con alta.");
				}
				break;

            case 9: //LISTAR JUEGOS
            	if(punterosGames!=NULL && ll_len(punterosGames)>0){
            		if(!controller_ListGame(punterosGames)){
            			puts("Listado OK.");
            		}
            	}
				break;

            case 30: //CARGA CSVs
            	puts("Opcion 30, CARGA");
                if(!controller_loadGamesFromText(pathGames, punterosGames)){
                	puts("\nCarga de texto Juegos OK");
                }else{
                	puts("\nError en carga de texto Juegos.");
                }
                if(!controller_loadRoomsFromText(pathRooms, punterosRooms)){
                	puts("\nCarga de texto Salas OK");
                }else{
                	puts("\nError en carga de texto Salas.");
                }
                if(!controller_loadArcadesFromText(pathArcades, punterosArcades)){
                	puts("\nCarga de texto Arcades OK");
                }else{
                	puts("\nError en carga de texto Arcades.");
                }
                break;

            /*
            case 11: //ORDENAR PASAJEROS
            	if(punterosPasajeros!=NULL && ll_len(punterosPasajeros)>0){
            		if(!controller_sortPassenger(punterosPasajeros) && !controller_ListPassenger(punterosPasajeros)){
            			puts("Ordenamiento OK.");
            		}
            	}

				break;
			*/

            case 40: //GUARDAR TODO MODO TEXTO
				if(ll_len(punterosGames)>0&&ll_len(punterosRooms)>0&&ll_len(punterosArcades)>0){
	            	if(!controller_saveGamesAsText(pathGames , punterosGames)){
						puts("Guardado de Juegos a texto OK.");
						flagSave++;
					}else{
						puts("Error con saveGamesAsText.");
					}
					if(!controller_saveRoomsAsText(pathRooms , punterosRooms)){
						puts("Guardado de Salas a texto OK.");
						flagSave++;
					}else{
						puts("Error con saveRoomsAsText.");
					}
					if(!controller_saveArcadesAsText(pathArcades, punterosArcades)){
						puts("Guardado de Arcades a texto OK.");
						flagSave++;
					}else{
						puts("Error con saveArcadesAsText.");
					}
				}else{
					puts("NO ES POSIBLE GUARDAR LISTAS VACIAS.");
				}

				break;

            case 50: // SALIR
            	if(flagSave>2){
            		option = 51;
            	}else{
            		puts("Seleccione una opción de guardado antes de salir.");
            	}
				break;
            default:
            	break;

        }
    }while(option != 51);

    return 0;
}

