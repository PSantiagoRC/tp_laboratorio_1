#include "Controller.h"
#include "Informes.h"

#define LEN_PATH 100

//PUNTO EXTRA: OBTENER UNA NUEVA LISTA FILTRANDO (BASARLO EN SORT)
//PARA FINAL REDUCE O MAP

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
            		puts("\nListado de Salones");
            		if(!controller_ListRoom(punterosRooms)){
            			puts("\nListado OK.");
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
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms!=NULL && ll_len(punterosArcades)>0){
            		puts("\nListado de Arcades");
            		if(!controller_ListArcade(punterosArcades,punterosGames,punterosRooms)){
            			puts("\nListado OK.");
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
            		puts("Listado de Juegos");
            		if(!controller_ListGame(punterosGames)){
            			puts("Listado OK.");
            		}
            	}
				break;

	/******************** INFORMES ********************/
            case 10: //SALONES CON MAS DE 4 ARCADES
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms!=NULL){
            		puts("\nLista de salones con más de 4 arcades");
            		informes_AListRoomsMoreThanFourArcades(punterosArcades,punterosRooms,punterosGames);
            		puts("\nListado OK");
            	}
            	break;

            case 11: //ARCADES PARA MAS DE 2 JUGADORES
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms!=NULL){
            	    puts("\nLista de salones con más de 4 arcades");
            	    informes_BArcadesForTwoOrMore(punterosArcades,punterosGames,punterosRooms);
            	}
            	break;

            case 12: //ROOM ELEGIDO POR USER
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms != NULL){
               		puts("\nListado de Salones");
                		if(!controller_ListRoom(punterosRooms)){
                			puts("\nListado OK.");
                			if(!informes_CPrintUserRooms(punterosRooms)){
                				puts("Informe C OK");
                			}
                		}
                	}
            	break;

            case 13: //ROOMS COMPLETOS
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms != NULL){
            		puts("Rooms Completos:");
            		if(!informes_DListCompleteRooms(punterosArcades, punterosRooms, punterosGames)){
            			puts("Informe D OK");
            		}
            	}
            	break;

            case 14: //TODOS LOS ARCADES DE UN ROOM ID
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms != NULL){
               		puts("\nListado de Salones");
					if(!controller_ListRoom(punterosRooms)){
						puts("\nListado OK.");
						informes_ERoom_ListArcadesByRoomId(punterosGames,punterosRooms, punterosArcades);
						puts("Informe E OK");
					}
                }

            	break;

            case 15: // SALON CON MAS ARCADES
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms != NULL){
            		puts("Rooms con más arcades:");
            		if(!informes_FSalonConMasArcadesOrdenado(punterosRooms,punterosArcades,punterosGames)){
            			puts("Informe F OK");
            		}
            	}
            	break;

            case 16: // FALTA! ARCADES MONO con juego PLATAFORMA con datos JUEGO, ORDENADO NOMBRE JUEGO
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms != NULL){
            		puts("Rooms Completos:");
            		if(!informes_DListCompleteRooms(punterosArcades, punterosRooms, punterosGames)){
            			puts("Informe D OK");
            		}
            	}
            	break;

            case 17: // PUNTO EXTRA EXAMEN
            	if(punterosArcades!=NULL && punterosGames!=NULL && punterosRooms != NULL){
            		puts("Rooms Completos:");
            		if(!informes_DListCompleteRooms(punterosArcades, punterosRooms, punterosGames)){
            			puts("Informe D OK");
            		}
            	}
            	break;

            case 30: //CARGA CSVs
            	puts("\nOpcion 30, CARGA");
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

            case 40: //GUARDAR ALL MODO TEXTO
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

