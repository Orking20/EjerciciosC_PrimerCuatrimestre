/*
 * Producto.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define TAM_DESCRIPCION 4096
#define TAM_NACIONALIDAD 64

typedef struct
{
	int idProducto;
	char descripcion[TAM_DESCRIPCION];
	char nacionalidad[TAM_NACIONALIDAD];
	int idTipo;
	float precioPorUnidad;
}Producto;


//Memoria dinámica
Producto* producto_new(void);
Producto* producto_newParametro(int idProducto, char* descripcion, char* nacionalidad, int idTipo, float precioPorUnidad);
int producto_delete(Producto* this);

//ABM
int producto_inicializar(Producto** pProducto, int limite);
int producto_alta(Producto** pProducto, int limite);
int producto_baja(Producto** pProducto, int limite);
int producto_modificar(Producto** pProducto, int limite);
int producto_listado(Producto** pProducto, int limite);
int producto_ordenarPorId(Producto** pProducto, int limite);
int producto_ordenarPorPrecio(Producto** pProducto, int limite);
int producto_ordenarPorDescripcion(Producto** pProducto, int limite);
int producto_buscarIndiceVacio(Producto** pProducto, int limite);
int producto_buscarProducto(Producto** pProducto, int limite);
int producto_generarId(void);
int producto_buscarPorId(Producto** pProducto, int limite, int id);

//Setters
int producto_setIdProducto(Producto* this, int idProducto);
int producto_setDescripcion(Producto* this, char* descripcion);
int producto_setPrecioPorUnidad(Producto* this, float precioPorUnidad);
int producto_setNacionalidad(Producto* this, char* nacionalidad);
int producto_setIdTipo(Producto* this, int idTipo);

//Getters
int producto_getIdProducto(Producto* this, int* flagError);
char* producto_getDescripcion(Producto* this, int* flagError);
float producto_getPrecioPorUnidad(Producto* this, int* flagError);
char* producto_getNacionalidad(Producto* this, int *flagError);
int producto_getIdTipo(Producto* this, int* flagError);

//Validaciones
int isValidId(int id);
int isValidDescripcion(char* descripcion);
int isValidNacionalidad(char* nacionalidad);
int isValidPrecioPorUnidad(float precioPorUnidad);

#endif /* PRODUCTO_H_ */
