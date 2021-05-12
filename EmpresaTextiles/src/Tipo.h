/*
 * Tipo.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef TIPO_H_
#define TIPO_H_
#define TAM_CADENA 100

typedef struct
{
	int idTipo;
	char Marca[TAM_CADENA];
	char Fabrica[TAM_CADENA];
	char TipoDeTela[TAM_CADENA];
	int isEmpty;
}Tipo;

int Tipo_inicializar(Tipo* pTipo, int limite);

void Tipo_harcodeo(Tipo* pTipo, int limite);

int Tipo_mostrarId(Tipo* pTipo, int limite);
int Tipo_buscarIndiceVacio(Tipo* pTipo, int limite);
int Tipo_buscarPorId(Tipo* pTipo, int limite, int id);
int Tipo_buscar(Tipo* pTipo, int limite);
int ordenarPorNumero(Tipo* pTipo, int limite);

#endif /* TIPO_H_ */
