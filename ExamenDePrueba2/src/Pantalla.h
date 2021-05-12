/*
 * Razas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_
#define TAM_DESCRIPCION 4096
#define TAM_PAIS_ORIGEN 100
#define TAM_TIPO 20

typedef struct
{
	int idPantalla;
	char nombre[TAM_DESCRIPCION];
	char tipo[TAM_TIPO];
	char direccion[TAM_PAIS_ORIGEN];
	float precioPorDia;
	int isEmpty;
}Pantalla;

int pantalla_inicializar(Pantalla* pPantalla, int limite);
int pantalla_alta(Pantalla* pPantalla, int indice);
int pantalla_modificar(Pantalla* pPantalla, int limite);
int pantalla_mostrar(Pantalla* pPantalla, int limite);
int pantalla_mostrarConId(Pantalla* pPantalla, int limite);

int pantalla_buscarIndiceVacio(Pantalla* pPantalla, int limite);
int pantalla_buscarId(Pantalla* pPantalla, int limite, int id);
int pantalla_buscar(Pantalla* pPantalla, int limite);

#endif /* PANTALLA_H_ */
