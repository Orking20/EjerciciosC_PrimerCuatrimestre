/*
 * Nacionalidad.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_
#define TAM_CADENA 100

typedef struct
{
	int idNacionalidad;
	char descripcion[TAM_CADENA];
}Nacionalidad;

//Memoria dinámica
Nacionalidad* nacionalidad_new(void);
Nacionalidad* nacionalidad_newParam(int idNacionalidad, char* descripcion);
int nacionalidad_delete(Nacionalidad* this);

//Setters
int nacionalidad_setId(Nacionalidad* this, int idNacionalidad);
int nacionalidad_setDescripcion(Nacionalidad* this, char* descripcion);

//Getters
int nacionalidad_getId(Nacionalidad* this, int* flagError);
char* nacionalidad_getDescripcion(Nacionalidad* this, int* flagError);

#endif /* NACIONALIDAD_H_ */
