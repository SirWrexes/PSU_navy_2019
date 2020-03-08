/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** map.h -- No description
*/

#ifndef MAP_H
#define MAP_H

#include "fox_define.h"

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

#endif /* !MAP_H */
