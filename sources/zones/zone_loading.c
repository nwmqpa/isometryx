/*
** EPITECH PROJECT, 2017
** sources/zones/loading.c
** File description:
** Loads data into zones
*/

#include <stdlib.h>
#include "isometryx.h"
#include "utils.h"

void load_tiles_in(zone_t *zone, tile_t *tiles, vector3_t size)
{
	free(zone->tiles);
	zone->size = size;
	zone->nb_tiles = size.x * size.y * size.z;
	zone->tiles = my_calloc(sizeof(short int) * zone->nb_tiles);
	my_memcpy((char *) zone->tiles, (char *) tiles, 2 * zone->nb_tiles);
}

void add_layer(zone_t *zone)
{
	vector3_t size = zone->size;
	int old_size = zone->nb_tiles;
	int new_size = size.x * size.y * (size.z + 1);
	int offset = sizeof(short int) * old_size;
	tile_t *tiles = my_calloc(sizeof(short int) * new_size);

	my_memcpy((char *) tiles, (char *) zone->tiles, offset);
	for (int i = old_size; i < new_size; i++) {
		tiles[i] = 0;
	}
	zone->tiles = tiles;
	zone->size = (vector3_t) {size.x, size.y, size.z + 1};
	zone->nb_tiles = new_size;
}

void add_column(zone_t *zone)
{
	vector3_t size = zone->size;
	int old_size = zone->nb_tiles;
	int new_size = size.x * (size.y + 1) * size.z;
	int offset = sizeof(short int) * size.x;
	tile_t *tiles = my_calloc(sizeof(short int) * new_size);

	for (int i = 0; i < new_size; i += (offset / sizeof(short int))) {
		my_memcpy((char *) tiles + i, (char *) zone->tiles, offset);
		tiles[i + (offset / sizeof(short int))] = 0;
		i++;
	}
	zone->tiles = tiles;
	zone->size = (vector3_t) {size.x, size.y + 1, size.z};
	zone->nb_tiles = new_size;	
}

void add_row(zone_t *zone)
{
	vector3_t size = zone->size;
	int old_size = zone->nb_tiles;
	int new_size = size.x * (size.y + 1) * size.z;
	int offset = sizeof(short int) * size.y * size.x;
	tile_t *tiles = my_calloc(sizeof(short int) * new_size);

	for (int i = 0; i < new_size; i += (offset / sizeof(short int))) {
		my_memcpy((char *) tiles + i, (char *) zone->tiles, offset);
		for (int j = 0; j < size.x; j++, i++)
			tiles[i] = 0;
	}
	zone->tiles = tiles;
	zone->size = (vector3_t) {size.x, size.y + 1, size.z};
	zone->nb_tiles = new_size;	
}

tile_t *copy_tiles(zone_t *zone)
{
	int len = sizeof(short int) * zone->nb_tiles;
	tile_t *tiles = my_calloc(len);

	my_memcpy((char *) tiles, (char *) zone->tiles, len);
	return (tiles);
}