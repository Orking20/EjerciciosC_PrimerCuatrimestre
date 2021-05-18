/*
 * Producto.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"

//----------------Memoria dinámica----------------

/*
 * brief Asigna espacio en la memoria heap para un producto
 * \return Retora el espacio de memoria obtenido o si no lo pudo conseguir NULL*/
Producto* producto_new(void)
{
	return (Producto*)malloc(sizeof(Producto));
}

/*
 * brief Asigna espacio en la memoria para un nuevo producto y asigna valores a sus campos
 * \param int idProducto Asigna un valor a idProducto
 * \param char* descripcion Asigna un valor a descripcion
 * \param char nacionalidad Asigna un valor a nacionalidad
 * \param int idTipo Asigna un valor a idTipo
 * \param float precioPorUnidad Asigna un valor a precioPorUnidad
 * \return Retora el espacio de memoria con valores cargados o NULL*/
Producto* producto_newParametro(int idProducto, char* descripcion, char* nacionalidad, int idTipo, float precioPorUnidad)
{
	Producto* auxProducto = producto_new();

	if(auxProducto != NULL)
	{
		if(producto_setIdProducto(auxProducto, idProducto) < 0 ||
		   producto_setDescripcion(auxProducto, descripcion) < 0 ||
		   producto_setNacionalidad(auxProducto, nacionalidad) < 0 ||
		   producto_setIdTipo(auxProducto, idTipo) < 0 ||
		   producto_setPrecioPorUnidad(auxProducto, precioPorUnidad) < 0)
		{
			producto_delete(auxProducto);
			auxProducto = NULL;
		}
	}

	return auxProducto;
}

/*
 * brief Libera el espacio de memoria entregado por parametro
 * \param Producto* this Puntero que va a ser liberado
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int producto_delete(Producto* this)
{
	int retorno = -1;

	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}

	return retorno;
}

//----------------ABM----------------

/*
 * brief Inicia los valores de todas las posiciones a NULL
 * \param Producto** pProducto Cadena que contiene todas las posiciones y va a ser objetivo de la función
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si pudo iniciar los valores a NULL o -1 (ERROR) si no*/
int producto_inicializar(Producto** pProducto, int limite)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pProducto[i] = NULL;
		}

		retorno = 0;
	}

	return retorno;
}

/*
 * brief Carga los datos de un producto
 * \param Producto** pProducto Cadena donde se cargarán los datos
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si se cargaron todos los datos o -1 (ERROR) si no*/
int producto_alta(Producto** pProducto, int limite)
{
	int retorno = -1;
	Producto bufferProducto;
	int indice;
	int idProducto;
	Producto* auxProducto;

	if(pProducto != NULL && limite > 0)
	{
		indice = producto_buscarIndiceVacio(pProducto, limite);
		if(indice >= 0)
		{
			if(!utn_getDescripcion(bufferProducto.descripcion, "\nIngrese la descripción: ", "\nError. Esa descripción no es válida") &&
			   !utn_getTexto(bufferProducto.nacionalidad, TAM_NACIONALIDAD, "Ingrese la nacionalidad: ", "\nError. Esa nacionalidad no es válida") &&
			   !utn_getNumero(&bufferProducto.idTipo, "Ingrese el tipo: ", "\nError. Ese número no es válido", 1, 100, 3) &&
			   !utn_getPrecio(&bufferProducto.precioPorUnidad, "Ingrese el precio por unidad: ", "\nError. Ese precio no es válido"))
			{
				idProducto = producto_generarId();

				auxProducto = producto_newParametro(idProducto, bufferProducto.descripcion, bufferProducto.nacionalidad, bufferProducto.idTipo, bufferProducto.precioPorUnidad);
				if(auxProducto != NULL)
				{
					pProducto[indice] = auxProducto;
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/*
 * brief Pide al usuario el ID y borra el producto correspondiente
 * \param Producto** pProducto Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si se borraron los datos o -1 (ERROR) si no*/
int producto_baja(Producto** pProducto, int limite)
{
	int retorno = -1;
	int idProducto;
	int indice;

	if(pProducto != NULL && limite > 0)
	{
		if(producto_buscarProducto(pProducto, limite))
		{
			producto_listado(pProducto, limite);
			if(!utn_getNumero(&idProducto, "\nIngrese el ID del producto que desea eliminar: ", "\nError. Ese ID no es válido", 1, limite, 3))
			{
				indice = producto_buscarPorId(pProducto, limite, idProducto);
				if(indice >= 0)
				{
					producto_delete(pProducto[indice]);
					pProducto[indice] = NULL;
					retorno = 0;
				}
				else
				{
					printf("\nEse ID no coincide con ningún otro");
				}
			}
		}
		else
		{
			printf("\nNo hay ningún producto cargado");
		}
	}

	return retorno;
}

/*
 * brief Pide al usuario el ID y modifica los campos de ese producto
 * \param Producto** pProducto Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si se modificaron los datos o -1 (ERROR) si no*/
int producto_modificar(Producto** pProducto, int limite)
{
	int retorno = -1;
	int idProducto;
	int indice;
	Producto bufferProducto;
	Producto* auxProducto;

	if(pProducto != NULL && limite > 0)
	{
		if(producto_buscarProducto(pProducto, limite))
		{
			producto_listado(pProducto, limite);
			if(!utn_getNumero(&idProducto, "\nIngrese el ID del producto que desea eliminar: ", "\nError. Ese ID no es válido", 1, limite, 3))
			{
				indice = producto_buscarPorId(pProducto, limite, idProducto);
				if(indice >= 0)
				{
					if(!utn_getDescripcion(bufferProducto.descripcion, "\nIngrese la descripción: ", "\nError. Esa descripción no es válida") &&
					   !utn_getTexto(bufferProducto.nacionalidad, TAM_NACIONALIDAD, "Ingrese la nacionalidad: ", "\nError. Esa nacionalidad no es válida") &&
					   !utn_getNumero(&bufferProducto.idTipo, "Ingrese el tipo: ", "\nError. Ese número no es válido", 1, 100, 3) &&
					   !utn_getPrecio(&bufferProducto.precioPorUnidad, "Ingrese el precio por unidad: ", "\nError. Ese precio no es válido"))
					{
						idProducto = producto_generarId();

						auxProducto = producto_newParametro(idProducto, bufferProducto.descripcion, bufferProducto.nacionalidad, bufferProducto.idTipo, bufferProducto.precioPorUnidad);
						if(auxProducto != NULL)
						{
							pProducto[indice] = auxProducto;
							retorno = 0;
						}
					}
				}
				else
				{
					printf("\nEse ID no coincide con ningún otro");
				}
			}
		}
		else
		{
			printf("\nNo hay ningún producto cargado");
		}
	}

	return retorno;
}

/*
 * brief Lista todos los campos de la estructura
 * \param Producto** pProducto Cadena donde se buscarán los datos
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si se mostraron los datos o -1 (ERROR) si no*/
int producto_listado(Producto** pProducto, int limite)
{
	int retorno = -1;
	int flagError;
	int idProducto;
	char* descripcion;
	char* nacionalidad;
	int idTipo;
	float precio;

	if(pProducto != NULL && limite > 0)
	{
		if(producto_buscarProducto(pProducto, limite))
		{
			printf("ID\tDescripción\t\tNacionalidad\t\tID Tipo\t\tPrecio\n--------------------------------------------------------------------------------\n");
			for(int i = 0; i < limite; i++)
			{
				if(pProducto[i] != NULL)
				{
					idProducto = producto_getIdProducto(pProducto[i], &flagError);
					descripcion = producto_getDescripcion(pProducto[i], &flagError);
					nacionalidad = producto_getNacionalidad(pProducto[i], &flagError);
					idTipo = producto_getIdTipo(pProducto[i], &flagError);
					precio = producto_getPrecioPorUnidad(pProducto[i], &flagError);
					printf("\n%-7d %-23s %-26s %-8d %10.2f", idProducto, descripcion, nacionalidad, idTipo, precio);
				}
			}
			retorno = 0;
		}
		else
		{
			printf("\nNo hay ningún producto cargado");
		}
	}

	return retorno;
}

/*
 * brief Ordena todos los productos por ID
 * \param Producto** pProducto Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si se ordenaron los datos o -1 (ERROR) si no*/
int producto_ordenarPorId(Producto** pProducto, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Producto* auxiliar;
	int flagError;
	int id1;
	int id2;

	if(pProducto != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				id1 = producto_getIdProducto(pProducto[i], &flagError);
				id2 = producto_getIdProducto(pProducto[i + 1], &flagError);
				if(id1 > id2)
				{
					auxiliar = pProducto[i];
					pProducto[i] = pProducto[i + 1];
					pProducto[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Ordena todos los productos por precio
 * \param Producto** pProducto Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si se ordenaron los datos o -1 (ERROR) si no*/
int producto_ordenarPorPrecio(Producto** pProducto, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Producto* auxiliar;
	int flagError;
	float precio1;
	float precio2;

	if(pProducto != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				precio1 = producto_getPrecioPorUnidad(pProducto[i], &flagError);
				precio2 = producto_getPrecioPorUnidad(pProducto[i + 1], &flagError);
				if(precio1 > precio2)
				{
					auxiliar = pProducto[i];
					pProducto[i] = pProducto[i + 1];
					pProducto[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		printf("\n\n\nLISTA ORDENADA POR PRECIO DE MENOR A MAYOR:\n");
		producto_listado(pProducto, limite);
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Ordena todos los productos por descripcion
 * \param Producto** pProducto Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) si se ordenaron los datos o -1 (ERROR) si no*/
int producto_ordenarPorDescripcion(Producto** pProducto, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Producto* auxiliar;
	int flagError;
	char* descripcion1;
	char* descripcion2;

	if(pProducto != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				descripcion1 = producto_getDescripcion(pProducto[i], &flagError);
				descripcion2 = producto_getDescripcion(pProducto[i + 1], &flagError);
				if(strcmp(descripcion1, descripcion2) < 0)
				{
					auxiliar = pProducto[i];
					pProducto[i] = pProducto[i + 1];
					pProducto[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		printf("\n\n\nLISTA ORDENADA POR DESCRIPCION:\n");
		producto_listado(pProducto, limite);
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Busca la primer posición vacía en pProducto
 * \param Producto** pProducto Cadena que contiene todas las posiciones y va a ser objetivo de la función
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora la posición vacía o -1 (ERROR) si no hay ningúna posición vacía*/
int producto_buscarIndiceVacio(Producto** pProducto, int limite)
{
	int respuesta = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pProducto[i] == NULL)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/*
 * brief Busca si hay productos cargados
 * \param Producto** pProducto Cadena que contiene todas las posiciones y va a ser objetivo de la función
 * \param int limite Limite o tamaño de la cadena pProducto
 * \return Retora 1 si hay por lo menos un producto, 0 si no hay ninguno o -1 si hay un error*/
int producto_buscarProducto(Producto** pProducto, int limite)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		retorno = 0;
		for(int i = 0; i < limite; i++)
		{
			if(pProducto[i] != NULL)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

/*
 * brief Genera un ID automáticamente
 * \return Retora el ID generado*/
int producto_generarId(void)
{
	static int contador = 0;

	contador++;

	return contador;
}

/*
 * brief Busca la posición donde los IDs son iguales
 * \param Producto** pProducto Cadena que contiene todos los IDs
 * \param int limite Limite o tamaño de la cadena pProducto
 * \param int id ID que se va a comparar con todos los IDs
 * \return Retora la posición donde los IDs son iguales o -1 (ERROR) si no hay IDs iguales*/
int producto_buscarPorId(Producto** pProducto, int limite, int id)
{
	int respuesta = -1;
	int flagError;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pProducto[i] != NULL && producto_getIdProducto(pProducto[i], &flagError) == id && !flagError)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

//----------------Setters----------------

/*
 * brief Comprueba que idProducto sea válido y lo asigna a la estructura
 * \param Producto* this Donde se guardará el dato obtenido
 * \param int idProducto Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int producto_setIdProducto(Producto* this, int idProducto)
{
	int retorno = -1;

	if(this != NULL && isValidId(idProducto))
	{
		this->idProducto = idProducto;
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que descripcion sea válido y lo asigna a la estructura
 * \param Producto* this Donde se guardará el dato obtenido
 * \param char* descripcion Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int producto_setDescripcion(Producto* this, char* descripcion)
{
	int retorno = -1;

	if(this != NULL && isValidDescripcion(descripcion))
	{
		strncpy(this->descripcion, descripcion, sizeof(this->descripcion));
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que nacionalidad sea válido y lo asigna a la estructura
 * \param Producto* this Donde se guardará el dato obtenido
 * \param char* nacionalidad Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int producto_setNacionalidad(Producto* this, char* nacionalidad)
{
	int retorno  = -1;

	if(this != NULL && isValidNacionalidad(nacionalidad))
	{
		strncpy(this->nacionalidad, nacionalidad, sizeof(this->nacionalidad));
		retorno  = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que idTipo sea válido y lo asigna a la estructura
 * \param Producto* this Donde se guardará el dato obtenido
 * \param int idTipo Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int producto_setIdTipo(Producto* this, int idTipo)
{
	int retorno = -1;

	if(this != NULL && isValidId(idTipo))
	{
		this->idTipo = idTipo;
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que precioPorUnidad sea válido y lo asigna a la estructura
 * \param Producto* this Donde se guardará el dato obtenido
 * \param float precioPorUnidad Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int producto_setPrecioPorUnidad(Producto* this, float precioPorUnidad)
{
	int retorno = -1;

	if(this != NULL && isValidPrecioPorUnidad(precioPorUnidad))
	{
		this->precioPorUnidad = precioPorUnidad;
		retorno = 0;
	}

	return retorno;
}

//----------------Getters----------------

/*
 * brief Obtiene el valor de idProducto
 * \param Producto* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de idProducto o NULL*/
int producto_getIdProducto(Producto* this, int* flagError)
{
	*flagError = -1;
	int auxId = -1;

	if(this != NULL && flagError != NULL)
	{
		auxId = this->idProducto;
		*flagError = 0;
	}

	return auxId;
}

/*
 * brief Obtiene el valor de descripcion
 * \param Producto* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de descripcion o NULL*/
char* producto_getDescripcion(Producto* this, int* flagError)
{
	*flagError = -1;
	char* auxDescripcion = NULL;

	if(this != NULL && flagError != NULL)
	{
		auxDescripcion = this->descripcion;
		*flagError = 0;
	}

	return auxDescripcion;
}

/*
 * brief Obtiene el valor de nacionalidad
 * \param Producto* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de nacionalidad o NULL*/
char* producto_getNacionalidad(Producto* this, int *flagError)
{
	*flagError = -1;
	char* auxNacionalidad = NULL;

	if(this != NULL && flagError != NULL)
	{
		auxNacionalidad = this->nacionalidad;
		*flagError = 0;
	}

	return auxNacionalidad;
}

/*
 * brief Obtiene el valor de idTipo
 * \param Producto* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de idTipo o NULL*/
int producto_getIdTipo(Producto* this, int* flagError)
{
	*flagError = -1;
	int auxIdTipo = -1;

	if(this != NULL && flagError != NULL)
	{
		auxIdTipo = this->idTipo;
		*flagError = 0;
	}

	return auxIdTipo;
}

/*
 * brief Obtiene el valor de precioPorUnidad
 * \param Producto* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de precioPorUnidad o NULL*/
float producto_getPrecioPorUnidad(Producto* this, int* flagError)
{
	*flagError = -1;
	float auxPrecioPorUnidad = -1;

	if(this != NULL && flagError != NULL)
	{
		auxPrecioPorUnidad = this->precioPorUnidad;
		*flagError = 0;
	}

	return auxPrecioPorUnidad;
}

//----------------Validaciones----------------

/*
 * brief Comprueba que el ID sea válido
 * \param int id El dato a comprobar que sea válido
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int isValidId(int id)
{
	int retorno = -1;

	if(id > 0)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que la descripcion sea válida
 * \param char* descripcion El dato a comprobar que sea válido
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int isValidDescripcion(char* descripcion)
{
	int retorno = -1;

	retorno = 1;

	return retorno;
}

/*
 * brief Comprueba que la nacionalidad sea válida
 * \param char* nacionalidad El dato a comprobar que sea válido
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int isValidNacionalidad(char* nacionalidad)
{
	int retorno = -1;

	return retorno;
}

/*
 * brief Comprueba que el precio por unidad sea válido
 * \param float precioPorUnidad El dato a comprobar que sea válido
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int isValidPrecioPorUnidad(float precioPorUnidad)
{
	int retorno = -1;

	return retorno;
}
