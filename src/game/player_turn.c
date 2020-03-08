/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** player_turn.c -- No description
*/

#include <malloc.h>
#include <stdio.h>

#include "fox_io.h"
#include "fox_memory.h"

#include "game.h"
#include "map.h"

static bool x_is_valid(char x)
{
    return (x >= 'A' && x <= 'H');
}

static bool y_is_valid(char y)
{
    return (y >= '1' && y <= '8');
}

static void turn_offense(player_t __Aunused *me, player_t __Aunused *them)
{
    size_t len = 0;
    __smart str_t line = NULL;

    while (true) {
        if (getline(&line, &len, stdin) == -1)
            break;
        if (line[2] != '\n' || !x_is_valid(line[0] || !y_is_valid(line[1]))) {
            fox_printf("wrong position\n");
            continue;
        }
    }
}

static void turn_defense(player_t __Aunused *me, player_t __Aunused *them)
{
    fox_printf("waiting for enemy’s attack...\n");
}

const turn_t PLAYER_TURN[2] = {
    &turn_offense,
    &turn_defense,
};
