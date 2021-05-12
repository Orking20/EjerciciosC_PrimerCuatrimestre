/*
 * Producto.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef Producto_H_
#define Producto_H_
#define TAM_DESCRIPCION 100

typedef struct
{
	int idProducto;
	char descripcion[TAM_DESCRIPCION];
	int idNacionalidad;
	int idTipo;
	float precioPorUnidad;
	int isEmpty;
}Producto;

int Producto_inicializar(Producto* pProducto, int limite);

void Producto_harcodeo(Producto* pProducto, int limite);

int Producto_mostrarId(Producto* pProducto, int limite);
int Producto_mostrarConId(Producto* pProducto, int limite);
int Producto_buscarIndiceVacio(Producto* pProducto, int limite);
int Producto_buscarPorId(Producto* pProducto, int limite, int id);
int Producto_buscar(Producto* pProducto, int limite);
int ordenarPorNumero(Producto* pProducto, int limite);

//Setters
int producto_setIdProducto(Producto* this, int idProducto);
int producto_setDescripcion(Producto* this, char* descripcion);
int producto_setPrecioPorUnidad(Producto* this, float precioPorUnidad);
int producto_setIdNacionalidad(Producto* this, int idNacionalidad);
int producto_setIdTipo(Producto* this, int idTipo);

//Getters
int producto_getIdProducto(Producto* this, int* flagError);
char* producto_getDescripcion(Producto* this, int* flagError);
float producto_getPrecioPorUnidad(Producto* this, int* flagError);
int producto_getIdNacionalidad(Producto* this, int* flagError);
int producto_getIdTipo(Producto* this, int* flagError);

#endif /* Producto_H_ */
