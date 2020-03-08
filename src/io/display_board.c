/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** display_board.c -- No description
*/

#include "fox_io.h"

#include "map.h"

__Anonnull void display_board(map_t map)
{
    fox_printf(" |");
    for (typeof(XMAX) x = 0; x < XMAX; x += 1)
        fox_printf((x == 0) ? "%c" : " %c", 'A' + x);
    fox_printf("\n-+");
    for (typeof(XMAX) x = 0; x < XMAX; x += 1)
        fox_printf((x == 0) ? "-" : "--");
    for (typeof(YMAX) y = 0; y < YMAX; y += 1) {
        fox_printf("\n%i|", y + 1);
        for (typeof(XMAX) x = 0; x < XMAX; x += 1)
            fox_printf((x == 0) ? "%c" : " %c", map[y][x]);
    }
    fox_printf("\n");
}
