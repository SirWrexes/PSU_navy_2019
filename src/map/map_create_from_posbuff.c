/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** map_create_from_posbuf.c -- No description
*/

#include <stdbool.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_memory.h"

#include "map.h"
#include "positions.h"

#include "./map_create_extra.h"

__Anonnull static bool set_line(map_t map, posline_t line)
{
    char *tilep;

    for (hindex_t i = 0; i < CHAR_TO_N(line[0]); i += 1) {
        tilep = tile(map, i, line);
        if (*tilep != TILE_EMPTY)
            return !!fox_eprintf(
                "Ships %c and %c overlap.\n", line[0], *tilep);
        *tilep = line[0];
    }
    return false;
}

__Anonnull bool map_create_from_posbuff(map_t map, posbuff_t buff)
{
    map_init_empty(map);
    for (hindex_t i = 0; i < 4; i += 1) {
        if (*ship_is_set(*buff[i]))
            return !!fox_eprintf("Ship of size %c is set twice.\n", *buff[i]);
        *ship_is_set(*buff[i]) = true;
        if (set_line(map, buff[i]))
            return !!fox_eprintf("Error during map init.\n");
    }
    return false;
}
