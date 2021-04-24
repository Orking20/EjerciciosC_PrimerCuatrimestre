/*
 * Producto.h
 *
 *  Created on: 19 abr. 2021
 *      Author: mateo
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define TAM_DESCRIPCION 400

typedef struct
{
	int idProducto;
	char descripcion[TAM_DESCRIPCION];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
}Producto;

#endif /* PRODUCTO_H_ */

int inicializarProductos(Producto* pArray, int limite);
int cargarProductos(Producto* pArray, int indice);
int eliminarProducto(Producto* pArray, int limite);
int modificarProducto(Producto* pArray, int limite);
int ordenadoId(Producto* pArray, int limite);
int ordenadoPrecio(Producto* pArray, int limite);
int ordenadoDescripcion(Producto* pArray, int limite);
int buscarIndiceVacio(Producto* pArray, int limite);

/*
 * 1. idProducto (numerico)
   2. descripcion (alfanumérico)
   3. nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
   4. tipo (numérico, por el momento utilizaremos un define: IPHONE - MAC - IPAD - ACCESORIOS)
   5. precio (numérico decimal)*/
