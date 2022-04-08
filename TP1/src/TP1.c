/*
 ============================================================================
 Name        : TP1.c
 Author      : Pablo Santiago Rodriguez Castro
 Version     :
 Copyright   :
 Description : Trabajo Practico Nro. 1, Programaci�n, Cuatrimestre 1
 ============================================================================
 */

#include "UTN.h"
#include "auxiliar.h"

//constantes para carga forzada
#define KM 1000
#define PL 10000
#define PA 8000

int main(void) {

	setbuf(stdout, NULL);

	float kmIngresados;
	float precioIngresadoAerolineas;
	float precioIngresadoLatam;

	int respuestaFloat1;
	int respuestaFloat2;
	int respuestaFloat3;
	int respuestaInt1;

	float costoDebitoLatam;
	float costoDebitoAerolineas;
	float costoCreditoLatam;
	float costoCreditoAerolineas;
	float costoBTCLatam;
	float costoBTCAerolineas;
	float precioPorKmLatam;
	float precioPorKmAerolineas;
	float diferenciaEmpresas;

	int seleccion;
	int cargaInicial1 = -1;
	int cargaInicial2 = -1;
	int cargaInicial3 = -1;
	int cargaInicial4 = -1;

	int retorno = -1;

	int salida = -1;

	do
	{
		imprimeMenu();

		//Ingreso de opci�n de men�
		respuestaInt1 = getInt("\nSeleccione una opci�n del men� (opciones 1 a 6)",3,1,6,"\nError, ingrese n�mero entre 1 y 6\n",&seleccion);
		if(respuestaInt1 == 0)
		{
			printf("\n\nUd. ingres� la opci�n %d\n",seleccion);
			retorno = 0;
		}
		else
		{
			printf("\nERROR\n");
			retorno = -1;
		}

		//Switch entre las 6 opciones
		switch(seleccion)
		{
			case 1:
				respuestaFloat1 = getFloat("\nIngrese kil�metros de distancia de su viaje:\n",3,1,999999,"\nError, ingrese n�mero entre 1 y 999999\n",&kmIngresados);
				if(respuestaFloat1 == 0)
				{
					printf("\nUd. ingres� %.2f kil�metros.\n",kmIngresados);
					retorno = 0;
					cargaInicial1 = 0;
				}
				else
				{
					printf("\nERROR\n");
					retorno = -1;
					return retorno;
					salida = 0;
				}
				break;
			case 2:
				respuestaFloat2 = getFloat("\nIngrese precio del vuelo por Aerolineas:\n",3,1,999999,"\nError, ingrese n�mero entre 1 y 999999\n",&precioIngresadoAerolineas);
				if(respuestaFloat2 == 0)
				{
					printf("\nUd. ingres� un precio de %.2f por Aerolineas.\n",precioIngresadoAerolineas);
					cargaInicial2 = 0;
				}
				else
				{
					printf("\nERROR\n");
				}

				respuestaFloat3 = getFloat("\nIngrese precio del vuelo por Latam:\n",3,1,999999,"\nError, ingrese n�mero entre 1 y 999999\n",&precioIngresadoLatam);
				if(respuestaFloat3 == 0)
				{
					printf("\nUd. ingres� un precio de %.2f por Latam.\n",precioIngresadoLatam);
					cargaInicial3 = 0;
				}
				else
				{
					printf("\nERROR\n");
				}
				break;
			case 3:
				if(cargaInicial1 == 0 && cargaInicial2 == 0 && cargaInicial3 == 0)
				{
					calculaCostos(kmIngresados, precioIngresadoLatam, precioIngresadoAerolineas, &costoDebitoLatam, &costoCreditoLatam, &costoDebitoAerolineas, &costoCreditoAerolineas, &costoBTCLatam, &costoBTCAerolineas, &precioPorKmLatam, &precioPorKmAerolineas, &diferenciaEmpresas);
					printf("\nLos costos fueron calculados, ingrese opci�n 4 para visualizarlos.");
					cargaInicial4 = 0;
				}
				else
				{
					printf("\n\nError: debe cargar la distancia en kil�metros (opci�n 1) y ambos precios (opci�n2) para calcular costos.\n");
					printf("\n\t Aguarde para regresar al men� principal.");
					Sleep(3000);
					printf("\n\t3...");
					Sleep(2000);
					printf("\n\t2...");
					Sleep(2000);
					printf("\n\t1...");
					Sleep(2000);
				}
				break;
			case 4:
				if(cargaInicial1 == 0 && cargaInicial2 == 0 && cargaInicial3 == 0 && cargaInicial4 == 0)
				{
					imprimeCostos(costoDebitoLatam, costoDebitoAerolineas, costoCreditoLatam, costoCreditoAerolineas, costoBTCLatam, costoBTCAerolineas, precioPorKmLatam, precioPorKmAerolineas, diferenciaEmpresas);
				}
				else
				{
					printf("\n\nDebe cargar la distancia en kil�metros (opcion 1), ambos precios (opcion 2) y calcular costos (opcion 3) para seleccionar esta opci�n.\n");
					printf("\n\t Aguarde para regresar al men� principal.");
					Sleep(3000);
					printf("\n\t3...");
					Sleep(2000);
					printf("\n\t2...");
					Sleep(2000);
					printf("\n\t1...");
					Sleep(2000);
				}
				break;
			case 5:
				kmIngresados = KM;
				precioIngresadoLatam = PL;
				precioIngresadoAerolineas = PA;
				calculaCostos(kmIngresados, precioIngresadoLatam, precioIngresadoAerolineas, &costoDebitoLatam, &costoCreditoLatam, &costoDebitoAerolineas, &costoCreditoAerolineas, &costoBTCLatam, &costoBTCAerolineas, &precioPorKmLatam, &precioPorKmAerolineas, &diferenciaEmpresas);
				imprimeCostos(costoDebitoLatam, costoDebitoAerolineas, costoCreditoLatam, costoCreditoAerolineas, costoBTCLatam, costoBTCAerolineas, precioPorKmLatam, precioPorKmAerolineas, diferenciaEmpresas);
				break;
			default:
				printf("\nUsted ha salido del aplicativo.");
				salida = 0;
				break;
		}
	}
	while(salida == -1);
}
