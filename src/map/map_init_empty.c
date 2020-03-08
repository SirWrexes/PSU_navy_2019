/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** map_init_empty.c -- No description
*/

#include "map.h"

__Anonnull __AalwaysILext void map_init_empty(map_t map)
{
    for (typeof(YMAX) y = 0; y < YMAX; y += 1)
        for (typeof(XMAX) x = 0; x < XMAX; x += 1)
            map[y][x] = TILE_EMPTY;
}
