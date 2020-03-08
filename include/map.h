/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** map.h -- No description
*/

#ifndef MAP_H
#define MAP_H

#include "fox_define.h"

#include "positions.h"

#define YMAX (8)
#define XMAX (8)

typedef char map_t[YMAX][XMAX];

enum {
    TILE_EMPTY = '.',
    TILE_HIT = 'x',
    TILE_MISS = 'o',
    TILE_BOAT2 = '2',
    TILE_BOAT3 = '3',
    TILE_BOAT4 = '4',
    TILE_BOAT5 = '5',
};

// Init a map with TILE_EMPTY everywhere
void map_init_empty(map_t map) __Anonnull;

// Init a map with data from posbuff
bool map_create_from_posbuff(map_t map, posbuff_t buff) __Anonnull;

// Init a map with data from a pos info file
bool map_create_from_file(map_t map, str2c_t path) __Anonnull;

#endif /* !MAP_H */
