/*
** EPITECH PROJECT, 2017
** sources/isometryx.c
** File description:
** Main entry-point for the isometryx lib.
*/

#include "isometryx.h"
#include "utils.h"

zone_t *parse_zone(uint_t x, uint_t y, uint_t z, tile_t *tiles)
{
	zone_t *new_zone = my_calloc(sizeof(zone_t));

	new_zone->tiles = tiles;
	new_zone->nb_tiles = x * y * z;
	return (new_zone);
}