/*
** EPITECH PROJECT, 2017
** includes/isometryx.h
** File description:
** Header file for exported functions and structures
*/

#ifndef ISOMETRYX_H_
#define ISOMETRYX_H_

#include <SFML/Graphics.h>

/*
** Library typedef for primary types 
*/

typedef unsigned int uint_t;
typedef unsigned short int tile_t;
typedef char byte_t;

/*
** Library structure
*/


struct vector3 {
	int x;
	int y;
	int z;
} typedef vector3_t;

struct zone {
	tile_t *tiles;
	uint_t nb_tiles;
	vector3_t size;
	struct tile_entity *te_list;
	sfView *view;
} typedef zone_t;

struct tile_entity {
	int index;
	byte_t *data;
	struct tile_entity *next;
} typedef te_t;

struct button {
	int index;
	int state;
	sfTexture *normal_texture;
	sfTexture *activated_texture;
	sfTexture *hover_texture;
	sfSprite *normal_sprite;
	sfSprite *activated_sprite;
	sfSprite *hover_sprite;
	sfFloatRect rect;
	int (*use)(sfSprite ***sprites, zone_t *zone);
} typedef button_t;

struct ui {
	struct button *buttons;
	sfView *view;
} typedef ui_t;

struct game {
	sfTexture **textures;
	struct zone *zone;
	struct ui *ui;
};

/*
** Library functions
*/

zone_t *create_zone(void);
zone_t *create_tiled_zone(uint_t x, uint_t y, uint_t z, tile_t const *tiles);
zone_t *copy_zone(zone_t const *ol);
void destroy_zone(zone_t *zone);

void load_tiles_in(zone_t *zone, tile_t *tiles, vector3_t size);
void add_layer(zone_t *zone);
void add_column(zone_t *zone);
void add_row(zone_t *zone);
tile_t *copy_tiles(zone_t *zone);

/*
** Library Values
*/

#define AIR (0)

#endif /* ISOMETRYX_H_*/