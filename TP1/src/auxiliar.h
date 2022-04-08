/*
 * auxiliar.h
 *
 *  Created on: 8 abr. 2022
 *      Author: rodri
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void imprimeMenu(void);
void calculaCostos(float kmIngresados,float precioIngresadoLatam,float precioIngresadoAerolineas, float* costoDebitoLatam, float* costoCreditoLatam, float* costoDebitoAerolineas, float* costoCreditoAerolineas, float* costoBTCLatam, float*costoBTCAerolineas, float* precioPorKmLatam, float* precioPorKmAerolineas, float* diferenciaEmpresas);
void imprimeCostos(float costoDebitoLatam, float costoDebitoAerolineas, float costoCreditoLatam, float costoCreditoAerolineas, float costoBTCLatam, float costoBTCAerolineas, float precioPorKmLatam, float precioPorKmAerolineas, float diferenciaEmpresas);


#endif /* AUXILIAR_H_ */
