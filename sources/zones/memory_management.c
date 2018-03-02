/*
** EPITECH PROJECT, 2017
** sources/isometryx.c
** File description:
** Memory management for zone structutre.
*/

#include <stdlib.h>
#include "isometryx.h"
#include "utils.h"

zone_t *create_zone(void)
{	
	zone_t *new = my_calloc(sizeof(zone_t));

	new->nb_tiles = 0;
	new->size = (vector3_t) {0, 0, 0};
	new->view = sfView_create();
	new->tiles = my_calloc(0);
	new->te_list = 0x0;
	return (new);
}

zone_t *create_tiled_zone(uint_t x, uint_t y, uint_t z, tile_t const *tiles)
{
	zone_t *new_zone = create_zone();

	free(new_zone->tiles);
	new_zone->nb_tiles = x * y * z;
	new_zone->tiles = my_calloc(sizeof(short int) * new_zone->nb_tiles);
	my_memcpy((char *) new_zone->tiles, (char *) tiles, 2 * x * y * z);
	return (new_zone);
}

zone_t *copy_zone(zone_t const *ol)
{
	zone_t *new = my_calloc(sizeof(zone_t));

	new->nb_tiles = ol->nb_tiles;
	new->size = ol->size;
	new->view = sfView_copy(ol->view);
	new->tiles = my_calloc(sizeof(short int) * ol->nb_tiles);
	new->te_list = tile_entities_copy(ol->te_list);
	my_memcpy((char *) new->tiles, (char *) ol->tiles, 2 * ol->nb_tiles);
	return (new);
}

void destroy_zone(zone_t *zone)
{
	free(zone->tiles);
	free_tile_entities(zone->te_list);
	free(zone);
}
