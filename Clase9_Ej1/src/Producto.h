/*
 * Producto.h
 *
 *  Created on: 15 abr. 2021
 *      Author: mateo
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	int id;
	char nombre[50];
	char descripcion[200];
	float precio;
	int isEmpty;
}Producto;

int inicializarProductos(Producto* pArray, int limite);
int cargarProductos(Producto* pProducto, int indice);
int mostrarProductos(Producto* pProducto, int limite);
int buscarIndiceVacio(Producto* pProducto, int limite);

#endif /* PRODUCTO_H_ */
