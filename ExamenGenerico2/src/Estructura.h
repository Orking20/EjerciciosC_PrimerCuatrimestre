/*
 * Estructura.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_
#define TAM_CADENA 100

typedef struct
{
	char cadena[TAM_CADENA];
	int numero;
	int id;
	int isEmpty;
}Estructura;

int estructura_inicializar(Estructura* pEstructura, int limite);

void estructura_harcodeo(Estructura* pEstructura, int limite);

int estructura_mostrarId(Estructura* pEstructura, int limite);
int estructura_buscarIndiceVacio(Estructura* pEstructura, int limite);
int estructura_buscarPorId(Estructura* pEstructura, int limite, int id);
int estructura_buscar(Estructura* pEstructura, int limite);
int ordenarPorNumero(Estructura* pEstructura, int limite);

#endif /* ESTRUCTURA_H_ */
