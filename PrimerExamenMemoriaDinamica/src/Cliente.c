#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "utn.h"

/**
 * brief Inicia los valores de todos los datos de la Cliente a valores vacíos
 * \param Cliente* pCliente: Cadena que contiene todos los campos y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int cliente_inicializar(Cliente** pCliente, int limite)
{
	int retorno = -1;

	if(pCliente != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pCliente[i] = NULL;

			/*strncpy(pCliente[i].nombre, "", sizeof(pCliente[i].nombre));
			strncpy(pCliente[i].apellido, "", sizeof(pCliente[i].apellido));
			strncpy(pCliente[i].cuit, "", sizeof(pCliente[i].cuit));
			pCliente[i].idCliente = 0;
			pCliente[i].isEmpty = 1;*/
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Agrega datos a la cadena pCliente
 * \param Cliente* pCliente: Cadena que va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena*/
void cliente_harcodeo(Cliente* pCliente, int limite)
{
	int idCliente[3] = {1, 2, 3};
	char nombre[3][TAM_NOMBRE] = {"Gabriel", "Lautaro", "Mateo"};
	char apellido[3][TAM_APELLIDO] = {"Martinez", "Canaggia", "Luchetti Capalbo"};
	char cuit[3][TAM_CUIT] = {"34486984123", "68456784535", "20418340143"};
	int isEmpty[3] = {0, 0, 0};

	for(int i = 0; i < limite; i++)
	{
		pCliente[i].idCliente = idCliente[i];
		strncpy(pCliente[i].nombre, nombre[i], sizeof(pCliente[i].nombre));
		strncpy(pCliente[i].apellido, apellido[i], sizeof(pCliente[i].apellido));
		strncpy(pCliente[i].cuit, cuit[i], sizeof(pCliente[i].cuit));
		pCliente[i].isEmpty = isEmpty[i];
	}
}

Cliente* cliente_nuevo(int indice)
{
	Cliente* pCliente;

	pCliente = (Cliente*)malloc(sizeof(Cliente));
	if(pCliente != NULL)
	{
		pCliente->idCliente = 0;
		pCliente->nombre[indice] = '\0';
		pCliente->apellido[indice] = '\0';
		pCliente->cuit[indice] = '\0';

		return pCliente;
	}
	else
	{
		return NULL;
	}
}

/**
 * brief Pide al usuario que cargue los datos de un cliente
 * \param Cliente* pCliente: Cadena donde se guardarán los valores
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) si se dió de alta o -1 (ERROR) si no*/
int cliente_alta(Cliente** pCliente, int limite)
{
	int retorno = -1;
	int indice;
	Cliente* bufferCliente;

	if(pCliente != NULL && limite > 0)
	{
		indice = cliente_buscarIndiceVacio(pCliente, limite);
		bufferCliente = cliente_nuevo(indice);

		if(!utn_getNombre(bufferCliente->nombre, "\nIngrese el nombre: ", "\nError. Ese nombre no es válido.") &&
		   !utn_getNombre(bufferCliente->apellido, "Ingrese el apellido: ", "\nError. Ese apellido no es válido.") &&
		   !utn_getCuit(bufferCliente->cuit, "Ingrese el CUIT: ", "\nError. Ese CUIT no es válido."))
		{
			bufferCliente->idCliente = indice + 1;
			//bufferCliente.isEmpty = 0;


			pCliente[indice] = bufferCliente;
			//cliente_mostrarId(pCliente, indice);
			retorno = 0;
		}
		else
		{
			printf("\nIngresaste un dato inválido.");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que modifique los valores de un cliente ingresando su ID
 * \param Cliente* pCliente: Cadena donde se guardarán los nuevos valores
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo modificar los datos o -1 (ERROR) si no*/
int cliente_modificar(Cliente* pCliente, int limite)
{
	int retorno = -1;
	Cliente bufferCliente;
	int idModificar;

	if(pCliente != NULL && limite > 0)
	{
		cliente_mostrar(pCliente, limite);
		if(!utn_getNumero(&idModificar, "\nIngrese el ID del cliente a modificar\n", "\nError. Ese ID no es válido\n", 1, limite, 3))
		{
			for(int i = 0; i < limite; i++)
			{
				if(idModificar == pCliente[i].idCliente)
				{
					if(!utn_getNombre(bufferCliente.nombre, "\nIngrese el nombre: ", "\nError. El nombre no es válido") &&
					   !utn_getNombre(bufferCliente.apellido, "Ingrese el apellido: ", "\nError. El apellido no es válido") &&
					   !utn_getCuit(bufferCliente.cuit, "Ingrese el CUIT: ", "\nError. El CUIT no es válido"))
					{
						bufferCliente.idCliente = idModificar;
						bufferCliente.isEmpty = 0;
						pCliente[i] = bufferCliente;
						retorno = 0;
						break;
					}
				}
			}
		}
		else
		{
			printf("\nEse ID no existe");
		}
	}

	return retorno;
}

/**
 * brief Muestra el ID de un cliente
 * \param Cliente* pCliente: Cadena que va a ser recorrida
 * \param int indice: La posición donde está el ID a mostrar
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int cliente_mostrarId(Cliente* pCliente, int indice)
{
	int retorno = -1;

	if(pCliente != NULL && indice >= 0)
	{
		printf("\nEl ID del nuevo cliente es %d\n", pCliente[indice].idCliente);
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de los clientes
 * \param Cliente* pCliente: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int cliente_mostrar(Cliente* pCliente, int limite)
{
	int retorno = -1;

	if(pCliente != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pCliente[i].isEmpty)
			{
				printf("ID: %-5d Nombre: %-15s Apellido: %-15s CUIT: %-15s\n", pCliente[i].idCliente, pCliente[i].nombre, pCliente[i].apellido, pCliente[i].cuit);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pCliente una posición vacía
 * \param Cliente* pCliente: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int cliente_buscarIndiceVacio(Cliente** pCliente, int limite)
{
	int respuesta = -1;

	if(pCliente != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pCliente[i] == NULL)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde la estructura Cliente y otra estructura tengan el mismo ID
 * \param Cliente* pCliente: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena pCliente
 * \param int id: ID que va a ser comparado con el ID del cliente
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int cliente_buscarPorId(Cliente* pCliente, int limite, int id)
{
	int retorno = -1;

	if(pCliente != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pCliente[i].isEmpty == 0 && pCliente[i].idCliente == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pCliente si hay por lo menos un dato cargado
 * \param Cliente* pCliente: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea un cliente, 0 si no hay ninguno o -1 en caso de error*/
int cliente_buscar(Cliente* pCliente, int limite)
{
	int respuesta = -1;

	if(pCliente != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pCliente[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
