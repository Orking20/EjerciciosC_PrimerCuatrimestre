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

//Setters
int producto_setIdTipo(Producto* this, int idTipo);
int producto_setIdMarca(Producto* this, int idProducto);
int producto_setFabrica(Producto* this, char* descripcion);
int producto_setTipoDeTela(Producto* this, float precioPorUnidad);

//Getters
int producto_getIdTipo(Producto* this, int* flagError);
char* producto_getIdMarca(Producto* this, int* flagError);
char* producto_getFabrica(Producto* this, int* flagError);
char* producto_getTipoDeTela(Producto* this, int* flagError);

#endif /* TIPO_H_ */
