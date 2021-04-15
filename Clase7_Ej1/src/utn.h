/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: mateo
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumber(int* pNumero,
		const char* pTexto,
		const char* mensajeError,
		int reintentos,
		int min,
		int max);

float utn_getFloat (float* pNumero,
		const char* pTexto,
		const char* mensajeError,
		int reintentos,
		float min,
		float max);

char utn_getChar (char* pChar,
		const char* pTexto,
		const char* mensajeError,
		int reintentos,
		char min,
		char max);

int calcularMayor(int* pResultado,
		int num1,
		int num2);

#endif /* UTN_H_ */
