/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** display_current_boards.c -- No description
*/

#include "fox_define.h"
#include "fox_io.h"

#include "io.h"
#include "game.h"

__Anonnull void display_current_boards(player_t *me, player_t *them)
{
    fox_printf("\nmy positions:\n");
    display_board(me->board);
    fox_printf("\nenemy's positions:\n");
    display_board(them->board);
}
