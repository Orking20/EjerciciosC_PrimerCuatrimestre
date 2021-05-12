#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cliente.h"
#include "Compra.h"
#include "Relacion.h"

/**
 * brief Pide al usuario que cargue los datos de una compra y se asignen a un cliente
 * \param Compra* pCompra: Cadena donde se guardarán los datos
 * \param Cliente* pCliente: Cadena para que se relacionen los datos de una estructura con otra
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) si se guardaron los datos o -1 (ERROR) si no*/
int compra_alta(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente, int indice)
{
	int retorno = -1;
	Compra bufferCompra;
	int idCliente;

	if(pCompra != NULL && pCliente != NULL && limiteCompra > 0 && limiteCliente > 0 && indice >= 0)
	{
		if(cliente_buscar(pCliente, limiteCliente) == 1)
		{
			cliente_mostrar(pCliente, limiteCliente);
			if(!utn_getNumero(&idCliente, "\nIngrese el ID del cliente: ", "\nError. Ese ID es inválido", 1, limiteCliente, 3))
			{
				if(!utn_getDireccion(bufferCompra.direccion, "\nIngrese la dirección (sin la altura): ", "Ingrese la altura: ", "\nError. Esa dirección no es válida", "\nError. Esa altura no es válida") &&
				   !utn_getTexto(bufferCompra.color, TAM_COLOR, "Ingrese un color: ", "\nError. Ese color no es válido") &&
				   !utn_getNumero(&bufferCompra.cantBarbijos, "Ingrese la cantidad de barbijos: ", "\nError. La cantidad de barbijos no es válida", 1, 10000, 3))
				{
					for(int i = 0; i < limiteCompra; i++)
					{
						if(idCliente == pCliente[i].idCliente)
						{
							bufferCompra.idCliente = idCliente;
							bufferCompra.idCompra = indice + 1;
							bufferCompra.estado = PENDIENTE_COBRAR;
							pCompra[indice] = bufferCompra;
							compra_mostrarId(pCompra, indice);
							retorno = 0;
							break;
						}
					}
					if(retorno == -1)
					{
						printf("\nNo existe ningun cliente con ese ID");
					}
				}
			}
			else
			{
				printf("\nIngresaste un dato inválido.");
			}
		}
		else
		{
			printf("\nError. Todavía no se ingresó ningun cliente. Primero tiene que dar de alta un cliente para añadir una compra.");
		}
	}

	return retorno;
}

/**
 * brief Permite borrar un cliente y, si las tiene, todas sus compras
 * \param Cliente* pCliente: Cadena donde se borrarán los datos de un cliente
 * \param Compra* pCompra: Cadena donde se borrarán las compras relacionadas con el cliente escogida
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) si se pudieron borrar los datos o -1 (ERROR) si no*/
int cliente_baja(Cliente* pCliente, Compra* pCompra, int limiteCliente, int limiteCompra)
{
	int retorno = -1;
	int idCliente;
	int indiceCompra;
	char respuesta[3];
	int flagValidarId = 0;

	if(pCliente != NULL && pCompra != NULL && limiteCliente > 0 && limiteCompra > 0)
	{
		if(cliente_buscar(pCliente, limiteCliente) == 1)
		{
			cliente_mostrar(pCliente, limiteCliente);
			if(!utn_getNumero(&idCliente, "\nIngrese el ID del cliente a eliminar: ", "\nError. Ese ID no es válido", 1, limiteCliente, 3))
			{
				for(int i = 0; i < limiteCliente; i++)
				{
					if(pCliente[i].idCliente == idCliente)
					{
						flagValidarId = 1;
						break;
					}
				}
				if(!flagValidarId)
				{
					printf("\nEse ID no existe");
				}
				else
				{
					cliente_mostrarComprasPorId(pCompra, limiteCompra, &idCliente);
					if(!utn_getRespuestaSiNo(respuesta, "\nAl borrar el cliente también se borrarán todas las compras relacionadas con él\n¿Estás seguro que quieres borrar este cliente? (si/no): ", "\nError. Solo puedes ingresar si o no") &&
					   strncmp(respuesta, "si", sizeof(respuesta)) == 0)
					{
						for(int j = 0; j < limiteCompra; j++)
						{
							indiceCompra = compra_buscarPorId(pCompra, limiteCompra, idCliente);
							if(idCliente == pCompra[j].idCliente)
							{
								pCompra[indiceCompra].idCliente = 0;
								pCompra[indiceCompra].idCompra = 0;
								strncpy(pCompra[indiceCompra].direccion, "", sizeof(pCompra[indiceCompra].direccion));
								strncpy(pCompra[indiceCompra].color, "", sizeof(pCompra[indiceCompra].color));
								pCompra[indiceCompra].cantBarbijos = 0;
								pCompra[indiceCompra].estado = VACIO;
							}
						}
						for(int i = 0; i < limiteCliente; i++)
						{
							if(idCliente == pCliente[i].idCliente)
							{
								pCliente[i].idCliente = 0;
								strncpy(pCliente[i].nombre, "", sizeof(pCliente[i].nombre));
								strncpy(pCliente[i].apellido, "", sizeof(pCliente[i].apellido));
								strncpy(pCliente[i].cuit, "", sizeof(pCliente[i].cuit));
								pCliente[i].isEmpty = 1;
								retorno = 0;
								printf("\nBorrado exitosamente!");
								break;
							}
						}
					}
				}
			}
		}
		else
		{
			printf("\nTodavía no ingresaste ningun cliente");
		}
	}

	return retorno;
}

/**
 * brief Se ingresa un importe a una compra y pasa a estado "cobrada"
 * \param Compra* pCompra: Cadena donde se guardará el importe y quedará en estado "cobrada"
 * \param Cliente* pCliente: Cadena que se usa para llamar a otra función
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \return Retora 0 (EXITO) si cargó el importe o -1 (ERROR) si no*/
int compra_pagarImporte(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente)
{
	int retorno = -1;
	float importe;
	char respuesta[3];
	int indice;
	int flagValidarId = 0;

	if(pCompra != NULL && pCliente != NULL && limiteCompra > 0 && limiteCliente > 0)
	{
		compra_mostrarClientesRelacionados(pCompra, pCliente, limiteCompra, limiteCliente, &indice, &flagValidarId);

		if(flagValidarId)
		{
			if(!utn_getPrecio(&importe, "\n\nIngrese el importe pagado por el cliente: ", "\nError. Ese precio es inválido") &&
			   !utn_getRespuestaSiNo(respuesta, "\nEl estado cambiará de pendiente a cobrado\n¿Desea confirmar esta acción? (si/no): ", "\nError. Solo puede ingresar si o no") &&
			   strncmp(respuesta, "si", sizeof(respuesta)) == 0)
			{
				pCompra[indice].importe = importe;
				pCompra[indice].estado = COBRADO;
				retorno = 0;
			}
		}
	}

	return retorno;
}

/**
 * brief Permite borrar una compra que este pendiente de cobrar
 * \param Compra* pCompra: Cadena donde se borrará la compra
 * \param Cliente* pCliente: Cadena que se usa para llamar a otra función
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \return Retora 0 (EXITO) si borró la compra o -1 (ERROR) si no*/
int compra_baja(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente)
{
	int retorno = -1;
	char respuesta[3];
	int indice;
	int flagValidarId = 0;

	if(pCompra != NULL && pCliente != NULL && limiteCompra > 0 && limiteCliente > 0)
	{
		compra_mostrarClientesRelacionados(pCompra, pCliente, limiteCompra, limiteCliente, &indice, &flagValidarId);

		if(flagValidarId)
		{
			if(pCompra[indice].estado == PENDIENTE_COBRAR)
			{
				if(!utn_getRespuestaSiNo(respuesta, "\n\nSi confirma, la compra se eliminará\n¿Desea confirmar esta acción? (si/no): ", "\nError. Solo puede ingresar si o no") &&
				   strncmp(respuesta, "si", sizeof(respuesta)) == 0)
				{
					pCompra[indice].idCompra = 0;
					pCompra[indice].idCliente = 0;
					strncpy(pCompra[indice].direccion, "", sizeof(pCompra[indice].direccion));
					strncpy(pCompra[indice].color, "", sizeof(pCompra[indice].color));
					pCompra[indice].cantBarbijos = 0;
					pCompra[indice].importe = 0;
					pCompra[indice].estado = VACIO;
					retorno = 0;
				}
			}
			else
			{
				printf("\nError. Esa compra no se encuentra pendiente de cobrar");
			}
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario un ID de compra y muestra su cliente relacionado
 * \param Compra* pCompra: Cadena que se usa para encontrar el indice del ID de la compra
 * \param Cliente* pCliente: Cadena que se usa para encontrar y mostrar los valores del cliente relacionado con la compra
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \param int limiteCliente: Limite o tamaño de la cadena pCliente
 * \param int* indice: Puntero donde se guardará el indice de la compra
 * \param int* flagValidarId: Puntero que se usa para saber si el ID ingresado existe o no
 * \return Retora 0 (EXITO) si encontró y mostró el cliente relacionado con la compra o -1 (ERROR) si no*/
int compra_mostrarClientesRelacionados(Compra* pCompra, Cliente* pCliente, int limiteCompra, int limiteCliente, int* indice, int* flagValidarId)
{
	int retorno = -1;
	int idVenta;
	int indiceCompra;
	int indiceCliente;
	int auxFlagValidarId = 0;

	if(pCompra != NULL && pCliente != NULL && limiteCompra > 0)
	{
		compra_mostrarConId(pCompra, limiteCompra);
		if(!utn_getNumero(&idVenta, "\nIngrese el ID de la venta: ", "\nError. Ese ID es inválido", 1, limiteCompra, 3))
		{
			for(int i = 0; i < limiteCompra; i++)
			{
				if(pCompra[i].estado != VACIO && pCompra[i].idCompra == idVenta)
				{
					auxFlagValidarId = 1;
					indiceCompra = i;
					break;
				}
			}

			if(!auxFlagValidarId)
			{
				printf("\nEse ID no existe");
			}
			else
			{
				*indice = indiceCompra;
				indiceCliente = cliente_buscarPorId(pCliente, limiteCompra, pCompra[indiceCompra].idCliente);
				printf("\nLa compra pertence al cliente:\nNombre: %-15s Apellido: %-20s CUIT: %-15s", pCliente[indiceCliente].nombre, pCliente[indiceCliente].apellido, pCliente[indiceCliente].cuit);
				retorno = 0;
			}
			*flagValidarId = auxFlagValidarId;
		}
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las compras que tiene un cliente
 * \param Compra* pCompra: Cadena que se usa para mostrar los datos de la compra
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \param int* auxiliarId: Puntero que se usa para evaluar si los IDs son iguales
 * \return Retora 0 (EXITO) si muestra las compras o -1 (ERROR) si no*/
int cliente_mostrarComprasPorId(Compra* pCompra, int limiteCompra, int* auxiliarId)
{
	int retorno = -1;

	if(pCompra != NULL && limiteCompra > 0 && auxiliarId != NULL)
	{
		for(int i = 0; i < limiteCompra; i++)
		{
			if(pCompra[i].idCliente == *auxiliarId)
			{
				printf("\tDirección: %-20s Color: %-15s Cantidad de días: %-15d\n", pCompra[i].direccion, pCompra[i].color, pCompra[i].cantBarbijos);
			}
		}
		retorno = 0;
	}

	return retorno;
}
