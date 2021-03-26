/*
 ============================================================================
 Name        : For2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer el programa que imprima los números del 100 al 0 en
 	 	 	   orden decreciente
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for(int i = 100; i >= 0; i--)
	{
		printf("%d\n", i);
	}

	return EXIT_SUCCESS;
}
