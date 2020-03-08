/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** map_create_extra.h -- No description
*/

#ifndef MAP_CREATE_EXTRA_H
#define MAP_CREATE_EXTRA_H

#include "fox_define.h"

#include "map.h"

__Aconst static inline bool *ship_is_set(char len)
{
    static bool state[4];

    return &(state[len - '0' - 2]);
}

__Aconst static inline char *tile(map_t map, hindex_t step, posline_t ln)
{
    enum { V = true, H = false } direction = (ln[2] == ln[5]);
    hindex_t x = ln[2] - 'A' + (step * (direction == H));
    hindex_t y = ln[3] - '1' + (step * (direction == V));

    return &(map[y][x]);
}

#endif /* !MAP_CREATE_EXTRA_H */
