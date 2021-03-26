/*
 ============================================================================
 Name        : Pares.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer el programa que imprima los números pares entre el 1 y el 100
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for(int i = 0; i <= 100; i++)
	{
		if(i % 2 == 0)
		{
			printf("%d\n", i);
		}
	}

	return EXIT_SUCCESS;
}
