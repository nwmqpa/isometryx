/*
** EPITECH PROJECT, 2017
** sources/utils/my_calloc.c
** File description:
** Allocate and clean memory.
*/

#include <stdlib.h>

void *my_calloc(int size)
{
	void *data;

	if (size < 0)
		return (0x0);
	data = malloc(size);
	if (!data)
		return (0x0);
	for (void *temp = data; size; size--, temp++)
		*((char *) temp) = 0;
	return (data);
}