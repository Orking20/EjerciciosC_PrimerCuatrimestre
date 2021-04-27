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

int inicializarPantalla(Pantalla* pPantalla, int limite);
int altaPantalla(Pantalla* pPantalla, int indice);
int modificarPantalla(Pantalla* pPantalla, int limite);
int mostrarPantalla(Pantalla* pPantalla, int limite);
int mostrarPantallaId(Pantalla* pPantalla, int limite);

//int getPeso(Raza* pRazas, int limite, int id, int* tamanio);
int buscarIndiceVacioPantalla(Pantalla* pPantalla, int limite);
int buscarIdPantalla(Pantalla* pPantalla, int limite, int id);
int buscarPantalla(Pantalla* pPantalla, int limite);

#endif /* PANTALLA_H_ */
