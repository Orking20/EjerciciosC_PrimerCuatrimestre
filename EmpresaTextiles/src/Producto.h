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

#endif /* Producto_H_ */
