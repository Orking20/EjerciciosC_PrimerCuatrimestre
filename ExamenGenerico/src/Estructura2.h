/*
 * Estructura2.h
 *
 *  Created on: 27 abr. 2021
 *      Author: mateo
 */

#ifndef ESTRUCTURA2_H_
#define ESTRUCTURA2_H_
#define TAM_Y 100

typedef struct
{
	char string[TAM_Y];
	char cadena[TAM_Y];
	int numero;
	int id;
	int isEmpty;
}Estructura2;

int inicializarEstructura2(Estructura2* pEstructura2, int limite);
int altaEstructura2(Estructura2* pEstructura2, int indice);
int modificarEstructura2(Estructura2* pEstructura2, int limite);
int mostrarEstructura2(Estructura2* pEstructura2, int limite);
int mostrarEstructura2Id(Estructura2* pEstructura2, int limite);

int buscarIndiceVacioEstructura2(Estructura2* pEstructura2, int limite);
int buscarIdEstructura2(Estructura2* pEstructura2, int limite, int id);
int buscarEstructura2(Estructura2* pEstructura2, int limite);

#endif /* ESTRUCTURA2_H_ */
