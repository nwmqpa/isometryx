/*
** EPITECH PROJECT, 2017
** sources/utils/my_memcpy.c
** File description:
** Copy len bytes of memory from src to dest
*/

void my_memcpy(char *dest, char *src, int bytes)
{
	for (int i = 0; bytes; bytes--, i++) {
		dest[i] = src[i];
	}
}