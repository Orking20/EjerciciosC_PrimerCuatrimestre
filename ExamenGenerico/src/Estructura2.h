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

int estructura2_inicializar(Estructura2* pEstructura2, int limite);
int estructura2_alta(Estructura2* pEstructura2, int indice);
int estructura2_modificar(Estructura2* pEstructura2, int limite);
int estructura2_mostrar(Estructura2* pEstructura2, int limite);
int estructura2_mostrarConId(Estructura2* pEstructura2, int limite);

int estructura2_buscarIndiceVacio(Estructura2* pEstructura2, int limite);
int estructura2_buscarPorId(Estructura2* pEstructura2, int limite, int id);
int estructura2_buscar(Estructura2* pEstructura2, int limite);

#endif /* ESTRUCTURA2_H_ */
