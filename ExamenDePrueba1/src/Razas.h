/*
 * Razas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#ifndef RAZAS_H_
#define RAZAS_H_
#define TAM_DESCRIPCION 4096
#define TAM_PAIS_ORIGEN 100
#define CHICO 1
#define MEDIANO 2
#define GRANDE 3

typedef struct
{
	int idRaza;
	char descripcion[TAM_DESCRIPCION];
	int tamanio;
	char paisOrigen[TAM_PAIS_ORIGEN];
	int isEmpty;
}Raza;

int inicializarRazas(Raza* pRazas, int limite);
int altaRaza(Raza* pRazas, int indice);
int mostrarRazas(Raza* pRazas, int limite);

//int getPeso(Raza* pRazas, int limite, int id, int* tamanio);
int buscarIndiceVacioRaza(Raza* pRazas, int limite);
int buscarIdRazas(Raza* pRazas, int limite, int id);

#endif /* RAZAS_H_ */
