#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

#define LEN_PATH 100
#define SIZE_PASSENGERS 5000

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

	LinkedList* punterosPasajeros = ll_newLinkedList();
	int option = 0;
	//char path[LEN_PATH] = "data.csv";
	char pathSaveTxt[LEN_PATH] = "dataWrittenTxt.csv";
	char pathSaveBin[LEN_PATH] = "dataWrittenBin.bin";
	int retSaveText;
	int flagSave = 0;

    do{
    	utn_getInt("\n1)Cargar datos de pasajeros desde archivo data.csv en modo texto."
    			   "\n2)Cargar datos de pasajeros desde archivo data.csv en modo binario."
    			   "\n3)Alta de pasajero."
    			   "\n4)Modificar pasajero."
    			   "\n5)Baja de pasajero."
    			   "\n6)Listar pasajeros."
    			   "\n7)Ordenar pasajeros."
    			   "\n8)Guardar datos de los pasajeros en el archivo data.csv (modo texto)."
    			   "\n9)Guardar datos de los pasajeros en el archivo data.csv (modo binario)."
    			   "\n10)Salir."
    			   "\n",
				   "\nError. Reingrese.", 1, 10, 3, &option);

        switch(option)
        {
            case 1: //CARGA TEXTO
                if(!controller_loadFromText(pathSaveTxt, punterosPasajeros)){
                	puts("\nCarga de texto OK");
                }
                break;

            case 2: //CARGA BINARIO
                if(!controller_loadFromBinary(pathSaveBin, punterosPasajeros)){
                	puts("\nCarga de texto OK");

                }
                break;

            case 3: //ALTA
            	if(!controller_addPassenger(punterosPasajeros)){
            			puts("\nAlta OK.");
            	}else{
            		puts("\nProblema con alta.");
            	}
            	break;

            case 4: //MODIFICACION
            	if(!controller_ListPassenger(punterosPasajeros) && !controller_editPassenger(punterosPasajeros)){
            		if(!controller_ListPassenger(punterosPasajeros)){
            			puts("\nModificacion OK.");
            		}
            	}else{
            		puts("\nProblema con modificacion.");
            	}

              	break;

            case 5: //BAJA
            	if(!controller_removePassenger(punterosPasajeros)){
            		puts("\nBaja OK.");
            	}else{
            		puts("\nProblema con baja.");
            	}
				break;

            case 6: //LISTAR PASAJEROS
            	if(punterosPasajeros!=NULL && ll_len(punterosPasajeros)>0){
            		if(!controller_ListPassenger(punterosPasajeros)){
            			puts("Listado OK.");
            		}
            	}
				break;

            case 7: //ORDENAR PASAJEROS
            	if(punterosPasajeros!=NULL && ll_len(punterosPasajeros)>0){
            		if(!controller_sortPassenger(punterosPasajeros) && !controller_ListPassenger(punterosPasajeros)){
            			puts("Ordenamiento OK.");
            		}
            	}

				break;

            case 8: //GUARDAR MODO TEXTO
				if(!(retSaveText = controller_saveAsText(pathSaveTxt , punterosPasajeros))){
					puts("Guardado a texto OK.");
					flagSave = 1;
				}else{
					printf("Error con saveAsText, retorno: %d",retSaveText);
				}
				break;

            case 9: // GUARDAR MODO BINARIO
				if(!(retSaveText = controller_saveAsBinary(pathSaveBin , punterosPasajeros))){
					puts("Guardado a binario OK.");
					flagSave = 1;
				}else{
					printf("Error con saveAsBinary, retorno: %d",retSaveText);
				}
				break;

            case 10: // SALIR
            	if(flagSave == 1 && ll_len(punterosPasajeros)>0){
            		option = 11;
            	}else{
            		puts("Seleccione una opción de guardado antes de salir.");
            	}
				break;
            default:
            	break;

        }
    }while(option != 11);

    return 0;
}

