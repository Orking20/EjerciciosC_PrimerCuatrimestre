/*
 * Empleado.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"

//----------------Memoria dinámica----------------

/*
 * brief Asigna espacio en la memoria heap para un Empleado
 * \return Retora el espacio de memoria obtenido o si no lo pudo conseguir NULL*/
Empleado* empleado_new(void)
{
	return (Empleado*)malloc(sizeof(Empleado));
}

/*
 * brief Asigna espacio en la memoria para un nuevo Empleado y asigna valores a sus campos
 * \param int idEmpleado Asigna un valor a idEmpleado
 * \param char* nombre Asigna un valor a nombre
 * \param char apellido Asigna un valor a apellido
 * \param int dni Asigna un valor a dni
 * \param float precioPorUnidad Asigna un valor a precioPorUnidad
 * \return Retora el espacio de memoria con valores cargados o NULL*/
Empleado* empleado_newParametro(int idEmpleado, char* nombre, char* apellido, char* dni)
{
	Empleado* auxEmpleado = empleado_new();

	if(auxEmpleado != NULL)
	{
		if(empleado_setIdEmpleado(auxEmpleado, idEmpleado) < 0 ||
		   empleado_setNombre(auxEmpleado, nombre) < 0 ||
		   empleado_setApellido(auxEmpleado, apellido) < 0 ||
		   empleado_setDni(auxEmpleado, dni) < 0)
		{
			empleado_delete(auxEmpleado);
			auxEmpleado = NULL;
		}
	}

	return auxEmpleado;
}

/*
 * brief Libera el espacio de memoria entregado por parametro
 * \param Empleado* this Puntero que va a ser liberado
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int empleado_delete(Empleado* this)
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
 * \param Empleado** pEmpleado Cadena que contiene todas las posiciones y va a ser objetivo de la función
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora 0 (EXITO) si pudo iniciar los valores a NULL o -1 (ERROR) si no*/
int empleado_inicializar(Empleado** pEmpleado, int limite)
{
	int retorno = -1;

	if(pEmpleado != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pEmpleado[i] = NULL;
		}

		retorno = 0;
	}

	return retorno;
}

/*
 * brief Carga los datos de un Empleado
 * \param Empleado** pEmpleado Cadena donde se cargarán los datos
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora 0 (EXITO) si se cargaron todos los datos o -1 (ERROR) si no*/
int empleado_alta(Empleado** pEmpleado, int limite)
{
	int retorno = -1;
	Empleado bufferEmpleado;
	int indice;
	int idEmpleado;
	Empleado* auxEmpleado;

	if(pEmpleado != NULL && limite > 0)
	{
		indice = empleado_buscarIndiceVacio(pEmpleado, limite);
		if(indice >= 0)
		{
			if(!utn_getNombre(bufferEmpleado.nombre, "\nIngrese el nombre: ", "\nError. Esa descripción no es válida") &&
			   !utn_getNombre(bufferEmpleado.apellido, "Ingrese la apellido: ", "\nError. Esa apellido no es válida") &&
			   !utn_getDni(bufferEmpleado.dni, "Ingrese el DNI: ", "\nError. Ese DNI es inválido"))
			{
				idEmpleado = empleado_generarId();

				auxEmpleado = empleado_newParametro(idEmpleado, bufferEmpleado.nombre, bufferEmpleado.apellido, bufferEmpleado.dni);
				if(auxEmpleado != NULL)
				{
					pEmpleado[indice] = auxEmpleado;
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/*
 * brief Pide al usuario el ID y borra el Empleado correspondiente
 * \param Empleado** pEmpleado Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora 0 (EXITO) si se borraron los datos o -1 (ERROR) si no*/
int empleado_baja(Empleado** pEmpleado, int limite)
{
	int retorno = -1;
	int idEmpleado;
	int indice;

	if(pEmpleado != NULL && limite > 0)
	{
		if(empleado_buscarEmpleado(pEmpleado, limite))
		{
			empleado_listado(pEmpleado, limite);
			if(!utn_getNumero(&idEmpleado, "\nIngrese el ID del Empleado que desea eliminar: ", "\nError. Ese ID no es válido", 1, limite, 3))
			{
				indice = empleado_buscarPorId(pEmpleado, limite, idEmpleado);
				if(indice >= 0)
				{
					empleado_delete(pEmpleado[indice]);
					pEmpleado[indice] = NULL;
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
			printf("\nNo hay ningún Empleado cargado");
		}
	}

	return retorno;
}

/*
 * brief Pide al usuario el ID y modifica los campos de ese Empleado
 * \param Empleado** pEmpleado Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora 0 (EXITO) si se modificaron los datos o -1 (ERROR) si no*/
int empleado_modificar(Empleado** pEmpleado, int limite)
{
	int retorno = -1;
	int idEmpleado;
	int indice;
	Empleado bufferEmpleado;
	Empleado* auxEmpleado;

	if(pEmpleado != NULL && limite > 0)
	{
		if(empleado_buscarEmpleado(pEmpleado, limite))
		{
			empleado_listado(pEmpleado, limite);
			if(!utn_getNumero(&idEmpleado, "\nIngrese el ID del Empleado que desea eliminar: ", "\nError. Ese ID no es válido", 1, limite, 3))
			{
				indice = empleado_buscarPorId(pEmpleado, limite, idEmpleado);
				if(indice >= 0)
				{
					if(!utn_getNombre(bufferEmpleado.nombre, "\nIngrese la descripción: ", "\nError. Esa descripción no es válida") &&
					   !utn_getNombre(bufferEmpleado.apellido, "Ingrese la apellido: ", "\nError. Esa apellido no es válida") &&
					   !utn_getDni(bufferEmpleado.dni, "Ingrese el DNI: ", "\nError. Ese DNI no es válido"))
					{
						idEmpleado = empleado_generarId();

						auxEmpleado = empleado_newParametro(idEmpleado, bufferEmpleado.nombre, bufferEmpleado.apellido, bufferEmpleado.dni);
						if(auxEmpleado != NULL)
						{
							pEmpleado[indice] = auxEmpleado;
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
			printf("\nNo hay ningún Empleado cargado");
		}
	}

	return retorno;
}

/*
 * brief Lista todos los campos de la estructura
 * \param Empleado** pEmpleado Cadena donde se buscarán los datos
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora 0 (EXITO) si se mostraron los datos o -1 (ERROR) si no*/
int empleado_listado(Empleado** pEmpleado, int limite)
{
	int retorno = -1;
	int flagError;
	int idEmpleado;
	char* nombre;
	char* apellido;
	char* dni;

	if(pEmpleado != NULL && limite > 0)
	{
		if(empleado_buscarEmpleado(pEmpleado, limite))
		{
			printf("ID\tNombre\t\t\tApellido\t\tDNI\n--------------------------------------------------------------------------------\n");
			for(int i = 0; i < limite; i++)
			{
				if(pEmpleado[i] != NULL)
				{
					idEmpleado = empleado_getIdEmpleado(pEmpleado[i], &flagError);
					nombre = empleado_getNombre(pEmpleado[i], &flagError);
					apellido = empleado_getApellido(pEmpleado[i], &flagError);
					dni = empleado_getDni(pEmpleado[i], &flagError);
					printf("\n%-7d %-23s %-23s %-8s", idEmpleado, nombre, apellido, dni);
				}
			}
			retorno = 0;
		}
		else
		{
			printf("\nNo hay ningún Empleado cargado");
		}
	}

	return retorno;
}

/*
 * brief Ordena todos los Empleados por nombre
 * \param Empleado** pEmpleado Cadena donde se encuentran los datos
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora 0 (EXITO) si se ordenaron los datos o -1 (ERROR) si no*/
int empleado_ordenarPorNombre(Empleado** pEmpleado, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Empleado* auxiliar;
	int flagError;
	char* nombre1;
	char* nombre2;

	if(pEmpleado != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				nombre1 = empleado_getNombre(pEmpleado[i], &flagError);
				nombre2 = empleado_getNombre(pEmpleado[i + 1], &flagError);
				if(strcmp(nombre1, nombre2) < 0)
				{
					auxiliar = pEmpleado[i];
					pEmpleado[i] = pEmpleado[i + 1];
					pEmpleado[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		printf("\n\n\nLISTA ORDENADA POR nombre:\n");
		empleado_listado(pEmpleado, limite);
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Busca la primer posición vacía en pEmpleado
 * \param Empleado** pEmpleado Cadena que contiene todas las posiciones y va a ser objetivo de la función
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora la posición vacía o -1 (ERROR) si no hay ningúna posición vacía*/
int empleado_buscarIndiceVacio(Empleado** pEmpleado, int limite)
{
	int respuesta = -1;

	if(pEmpleado != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEmpleado[i] == NULL)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/*
 * brief Busca si hay Empleados cargados
 * \param Empleado** pEmpleado Cadena que contiene todas las posiciones y va a ser objetivo de la función
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \return Retora 1 si hay por lo menos un Empleado, 0 si no hay ninguno o -1 si hay un error*/
int empleado_buscarEmpleado(Empleado** pEmpleado, int limite)
{
	int retorno = -1;

	if(pEmpleado != NULL && limite > 0)
	{
		retorno = 0;
		for(int i = 0; i < limite; i++)
		{
			if(pEmpleado[i] != NULL)
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
int empleado_generarId(void)
{
	static int contador = 0;

	contador++;

	return contador;
}

/*
 * brief Busca la posición donde los IDs son iguales
 * \param Empleado** pEmpleado Cadena que contiene todos los IDs
 * \param int limite Limite o tamaño de la cadena pEmpleado
 * \param int id ID que se va a comparar con todos los IDs
 * \return Retora la posición donde los IDs son iguales o -1 (ERROR) si no hay IDs iguales*/
int empleado_buscarPorId(Empleado** pEmpleado, int limite, int id)
{
	int respuesta = -1;
	int flagError;

	if(pEmpleado != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEmpleado[i] != NULL && empleado_getIdEmpleado(pEmpleado[i], &flagError) == id && !flagError)
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
 * brief Comprueba que idEmpleado sea válido y lo asigna a la estructura
 * \param Empleado* this Donde se guardará el dato obtenido
 * \param int idEmpleado Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int empleado_setIdEmpleado(Empleado* this, int idEmpleado)
{
	int retorno = -1;

	if(this != NULL && isValidId(idEmpleado))
	{
		this->idEmpleado = idEmpleado;
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que nombre sea válido y lo asigna a la estructura
 * \param Empleado* this Donde se guardará el dato obtenido
 * \param char* nombre Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int empleado_setNombre(Empleado* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && isValidNombre(nombre))
	{
		strncpy(this->nombre, nombre, sizeof(this->nombre));
		retorno = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que apellido sea válido y lo asigna a la estructura
 * \param Empleado* this Donde se guardará el dato obtenido
 * \param char* apellido Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int empleado_setApellido(Empleado* this, char* apellido)
{
	int retorno  = -1;

	if(this != NULL && isValidApellido(apellido))
	{
		strncpy(this->apellido, apellido, sizeof(this->apellido));
		retorno  = 0;
	}

	return retorno;
}

/*
 * brief Comprueba que dni sea válido y lo asigna a la estructura
 * \param Empleado* this Donde se guardará el dato obtenido
 * \param int dni Dato que se evaluará y guardará en la estructura
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int empleado_setDni(Empleado* this, char* dni)
{
	int retorno = -1;

	if(this != NULL && isValidDni(dni))
	{
		strncpy(this->dni, dni, sizeof(this->dni));
		retorno = 0;
	}

	return retorno;
}

//----------------Getters----------------

/*
 * brief Obtiene el valor de idEmpleado
 * \param Empleado* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de idEmpleado o NULL*/
int empleado_getIdEmpleado(Empleado* this, int* flagError)
{
	*flagError = -1;
	int auxId = -1;

	if(this != NULL && flagError != NULL)
	{
		auxId = this->idEmpleado;
		*flagError = 0;
	}

	return auxId;
}

/*
 * brief Obtiene el valor de nombre
 * \param Empleado* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de nombre o NULL*/
char* empleado_getNombre(Empleado* this, int* flagError)
{
	*flagError = -1;
	char* auxnombre = NULL;

	if(this != NULL && flagError != NULL)
	{
		auxnombre = this->nombre;
		*flagError = 0;
	}

	return auxnombre;
}

/*
 * brief Obtiene el valor de apellido
 * \param Empleado* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de apellido o NULL*/
char* empleado_getApellido(Empleado* this, int *flagError)
{
	*flagError = -1;
	char* auxapellido = NULL;

	if(this != NULL && flagError != NULL)
	{
		auxapellido = this->apellido;
		*flagError = 0;
	}

	return auxapellido;
}

/*
 * brief Obtiene el valor de dni
 * \param Empleado* this Dato que queremos obtener
 * \param int* flagError Nos avisa si hay algún error
 * \return Retora el valor dentro de dni o NULL*/
char* empleado_getDni(Empleado* this, int* flagError)
{
	*flagError = -1;
	char* auxdni = NULL;

	if(this != NULL && flagError != NULL)
	{
		auxdni = this->dni;
		*flagError = 0;
	}

	return auxdni;
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
 * brief Comprueba que la nombre sea válida
 * \param char* nombre El dato a comprobar que sea válido
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int isValidNombre(char* nombre)
{
	int retorno = -1;

	retorno = 1;

	return retorno;
}

/*
 * brief Comprueba que la apellido sea válida
 * \param char* apellido El dato a comprobar que sea válido
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int isValidApellido(char* apellido)
{
	int retorno = -1;

	return retorno;
}


int isValidDni(char* dni)
{
	int retorno = -1;

	return retorno;
}

//----------------Archivos----------------

int empleado_establecerDatos(Empleado** pEmpleado, int limite)
{
	int retorno = -1;
	FILE* pFile;
	Empleado* auxiliarEmpleado;
	char bufferNombre[64];
	char bufferApellido[64];
	char bufferDni[30];
	int indice;
	int idEmpleado;
	int rs;

	pFile = fopen("Texto.txt", "r");

	if(pEmpleado != NULL && limite > 0 && pFile != NULL)
	{
		do
		{
			rs = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufferNombre, bufferApellido, bufferDni);
			if(rs == 3)
			{
				idEmpleado = empleado_generarId();
				auxiliarEmpleado = empleado_newParametro(idEmpleado, bufferNombre, bufferApellido, bufferDni);
				indice = empleado_buscarIndiceVacio(pEmpleado, limite);

				if(auxiliarEmpleado != NULL && indice >= 0)
				{
					pEmpleado[indice] = auxiliarEmpleado;
					indice++;
					retorno = 0;
				}
			}
			else
			{
				break;
			}
		}while(1);

		fclose(pFile);
	}

	return retorno;
}

int empleado_guardarCambios(Empleado** pEmpleado, int limite)
{
	int retorno = -1;
	FILE* pFile;
	int flagError;

	pFile = fopen("Texto.txt", "w");

	if(pEmpleado != NULL && limite > 0 && pFile != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEmpleado[i] != NULL)
			{
				fprintf(pFile, "%s,%s,%s\n", empleado_getNombre(pEmpleado[i], &flagError), empleado_getApellido(pEmpleado[i], &flagError), empleado_getDni(pEmpleado[i], &flagError));
			}
		}
		fclose(pFile);
		printf("Guardado exitosamente!");
		retorno = 0;
	}

	return retorno;
}
