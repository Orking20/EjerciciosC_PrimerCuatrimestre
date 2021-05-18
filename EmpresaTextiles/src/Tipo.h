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
}Tipo;

//Memoria dinámica
Tipo* tipo_new(void);
Tipo* tipo_newParam(int idTipo, char* marca, char* fabrica, char* tipoDeTela);
int tipo_delete(Tipo* this);

//Setters
int tipo_setIdTipo(Tipo* this, int idTipo);
int tipo_setIdMarca(Tipo* this, int idTipo);
int tipo_setFabrica(Tipo* this, char* descripcion);
int tipo_setTipoDeTela(Tipo* this, float precioPorUnidad);

//Getters
int tipo_getIdTipo(Tipo* this, int* flagError);
char* tipo_getIdMarca(Tipo* this, int* flagError);
char* tipo_getFabrica(Tipo* this, int* flagError);
char* tipo_getTipoDeTela(Tipo* this, int* flagError);

#endif /* TIPO_H_ */
