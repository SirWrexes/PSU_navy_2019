/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** player_info.h -- No description
*/

#ifndef GAME_H
#define GAME_H

#include <sys/types.h>

#include "fox_define.h"

#include "map.h"

#define PLAYER_PCS_BASE (2 + 3 + 4 + 5)

typedef struct {
    hcount_t pieces;
    map_t board;
} player_t;

typedef enum {
    NAVY_RUNNING = -1,
    NAVY_WON = 0,
    NAVY_LOST = 1,
} status_t;

typedef void (*turn_t)(player_t *me, player_t *them);

extern const turn_t PLAYER_TURN[2];

#endif /* !GAME_H */
