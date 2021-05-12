/*
 * Mascotas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_
#define TAM_NOMBRE_ARCHIVO 100
#define TAM_CUIT 12

typedef struct
{
	int idContratacion;
	int idPantalla;
	int cantDias;
	char cuitCliente[TAM_CUIT];
	char nombreArchivo[TAM_NOMBRE_ARCHIVO];
	int isEmpty;
}Contratacion;

int contratacion_inicializar(Contratacion* pContratacion, int limite);
int contratacion_buscarIndiceVacio(Contratacion* pContratacion, int limite);
int contratacion_buscar(Contratacion* pContratacion, int limite);

int getCantDias(Contratacion* pContrataciones, int indice, int* pCantDiasEncontrados);
int setCantDias(Contratacion* pContrataciones, int indice, int* pCantDiasAGuardar);
int getCuit(Contratacion* pContrataciones, int indice, char* pCuitEncontrado);
int setCuit(Contratacion* pContrataciones, int indice, char* pCuitAGuardar);
int getNombreArchivo(Contratacion* pContrataciones, int indice, char* pNombreArchivoEncontrado);
int setNombreArchivo(Contratacion* pContrataciones, int indice, char* pNombreArchivoAGuardar);

#endif /* CONTRATACION_H_ */
