/*
 * Entidad.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_
#define TAM_CADENA 100

typedef struct
{
	char cadena[TAM_CADENA];
	int numero;
	int id;
	int isEmpty;
}Entidad;

int entidad_inicializar(Entidad* pEntidad, int limite);
int entidad_alta(Entidad* pEntidad, int indice);
int entidad_modificar(Entidad* pEntidad, int limite);

int entidad_mostrar(Entidad* pEntidad, int limite);
int entidad_mostrarConId(Entidad* pEntidad, int limite);
int entidad_buscarIndiceVacio(Entidad* pEntidad, int limite);
int entidad_buscarPorId(Entidad* pEntidad, int limite, int id);
int entidad_buscar(Entidad* pEntidad, int limite);

#endif /* ENTIDAD_H_ */
