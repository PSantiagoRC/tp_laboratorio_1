/*
 * auxiliar.c
 *
 *  Created on: 8 abr. 2022
 *      Author: rodri
 */

#include "auxiliar.h"

void calculaCostos(float kmIngresados,float precioIngresadoLatam,float precioIngresadoAerolineas, float* costoDebitoLatam, float* costoCreditoLatam, float* costoDebitoAerolineas, float* costoCreditoAerolineas, float* costoBTCLatam, float*costoBTCAerolineas, float* precioPorKmLatam, float* precioPorKmAerolineas, float* diferenciaEmpresas)
{
	float tasaCostoDebito = -0.1;
	float tasaCostoCredito = 0.25;
	float cambioBTC = 4606954.55;

	*costoDebitoLatam = precioIngresadoLatam * (1 + tasaCostoDebito);
	*costoDebitoAerolineas = precioIngresadoAerolineas * (1 + tasaCostoDebito);
	*costoCreditoLatam = precioIngresadoLatam * (1 + tasaCostoCredito);
	*costoCreditoAerolineas = precioIngresadoAerolineas * (1 + tasaCostoCredito);
	*costoBTCLatam = precioIngresadoLatam * (1 / cambioBTC);
	*costoBTCAerolineas = (float)precioIngresadoAerolineas * (1 / cambioBTC);

	*precioPorKmLatam = precioIngresadoLatam / kmIngresados;
	*precioPorKmAerolineas = precioIngresadoAerolineas / kmIngresados;

	*diferenciaEmpresas = precioIngresadoLatam - precioIngresadoAerolineas;


}

void imprimeCostos(float costoDebitoLatam, float costoDebitoAerolineas, float costoCreditoLatam, float costoCreditoAerolineas, float costoBTCLatam, float costoBTCAerolineas, float precioPorKmLatam, float precioPorKmAerolineas, float diferenciaEmpresas)
{
	printf("\nResultados:\nLatam:");
	printf("\na)Precio con tarjeta de d�bito: %.2f",costoDebitoLatam);
	printf("\nb)Precio con tarjeta de cr�dito: %.2f",costoCreditoLatam);
	printf("\nc)Precio pagando con bitcoin: %.5f",costoBTCLatam);
	printf("\nd)Precio unitario: %.2f",precioPorKmLatam);
	printf("\nAerol�neas:");
	printf("\na)Precio con tarjeta de d�bito: %.2f",costoDebitoAerolineas);
	printf("\nb)Precio con tarjeta de cr�dito: %.2f",costoCreditoAerolineas);
	printf("\nc)Precio pagando con bitcoin: %.5f",costoBTCAerolineas);
	printf("\nd)Precio unitario: %.2f",precioPorKmAerolineas);
	printf("\nLa diferencia de precio es : %.2f\n",diferenciaEmpresas);
}

void imprimeMenu(void)
{
	printf("\n\n1. Ingresar Kil�metros: ( km=x)");
	printf("\n\n2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)");
	printf("\n\t- Precio vuelo Aerol�neas:");
	printf("\n\t- Precio vuelo Latam:");
	printf("\n\n3. Calcular todos los costos:");
	printf("\na) Tarjeta de d�bito (descuento 10%%)");
	printf("\nb) Tarjeta de cr�dito (inter�s 25%%)");
	printf("\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
	printf("\nd) Mostrar precio por km (precio unitario)");
	printf("\ne) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)");
	printf("\n\n4. Informar Resultados");
	printf("\nLatam:");
	printf("\na) Precio con tarjeta de d�bito: r");
	printf("\nb) Precio con tarjeta de cr�dito: r");
	printf("\nc) Precio pagando con bitcoin : r");
	printf("\nd) Precio unitario: r");
	printf("\nAerol�neas:");
	printf("\na) Precio con tarjeta de d�bito: r");
	printf("\nb) Precio con tarjeta de cr�dito: r");
	printf("\nc) Precio pagando con bitcoin : r");
	printf("\nd) Precio unitario: r ");
	printf("\nLa diferencia de precio es : r");
	printf("\n\n5. Carga forzada de datos ");
	printf("\n\n6. Salir \n");
}
