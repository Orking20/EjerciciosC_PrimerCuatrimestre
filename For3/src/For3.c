/*
 ============================================================================
 Name        : For3.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Diseñar un programa que imprima y sume la serie de
 	 	 	   números 3,6,9,12,...,99.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for(int i = 3; i < 100; i += 3)
	{
		printf("%d\n", i);
	}

	return EXIT_SUCCESS;
}
