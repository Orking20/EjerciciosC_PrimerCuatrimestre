/*
 * Relacion.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int Producto_alta(Producto* pProducto, Nacionalidad* pNacionalidad, int limiteProducto, int limiteNacionalidad, int indice);
int Producto_modificar(Producto* pProducto, Nacionalidad* pNacionalidad, int limiteProducto, int limiteNacionalidad);
int Nacionalidad_baja(Nacionalidad* pNacionalidad, Producto* pProducto, int limiteNacionalidad, int limiteProducto);
int Producto_baja(Producto* pProducto, Nacionalidad* pNacionalidad, int limiteProducto, int limiteNacionalidad);
int Producto_mostrar(Producto* pProducto, Nacionalidad* pNacionalidad, int limiteProducto, int limiteNacionalidad);

#endif /* RELACION_H_ */
