/*
 * Estructura.h
 *
 *  Created on: 27 abr. 2021
 *      Author: mateo
 */

#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_
#define TAM_X 100

typedef struct
{
	char string[TAM_X];
	char cadena[TAM_X];
	int numero;
	int id;
	int isEmpty;
}Estructura;

int estructura_inicializar(Estructura* pEstructuras, int limite);
int estructura_buscarIndiceVacio(Estructura* pAEstructuras, int limite);
int estructura_buscar(Estructura* pEstructuras, int limite);

#endif /* ESTRUCTURA_H_ */
