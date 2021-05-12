/*
 * Nacionalidad.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef Nacionalidad_H_
#define Nacionalidad_H_
#define TAM_CADENA 100

typedef struct
{
	int idNacionalidad;
	char descripcion[TAM_CADENA];
	int isEmpty;
}Nacionalidad;

int Nacionalidad_inicializar(Nacionalidad* pNacionalidad, int limite);
int Nacionalidad_alta(Nacionalidad* pNacionalidad, int indice);
int Nacionalidad_modificar(Nacionalidad* pNacionalidad, int limite);

int Nacionalidad_mostrar(Nacionalidad* pNacionalidad, int limite);
int Nacionalidad_mostrarConId(Nacionalidad* pNacionalidad, int limite);
int Nacionalidad_buscarIndiceVacio(Nacionalidad* pNacionalidad, int limite);
int Nacionalidad_buscarPorId(Nacionalidad* pNacionalidad, int limite, int id);
int Nacionalidad_buscar(Nacionalidad* pNacionalidad, int limite);

#endif /* Nacionalidad_H_ */
