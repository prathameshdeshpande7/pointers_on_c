/*
 * Write a program to check for memory allocated
 * using malloc to be auto-checked for NULL
 */

#include<stdio.h>
#include "alloc.h"

int main()
{
	int *new_memory;

	new_memory = MALLOC(25, int);
	printf("Allocated memory\n");
}
