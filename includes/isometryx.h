/*
** EPITECH PROJECT, 2017
** includes/isometryx.h
** File description:
** Header file for exported functions and structures
*/

#ifndef ISOMETRYX_H_
#define ISOMETRYX_H_

typedef unsigned int uint_t;
typedef short int tile_t;

struct zone {
	tile_t *tiles;
	uint_t nb_tiles;
};

typedef struct zone zone_t;

#endif /* ISOMETRYX_H_*/