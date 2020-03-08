/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** player_info.h -- No description
*/

#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H

#include <sys/types.h>

#include "fox_define.h"

#include "map.h"

#define PLAYER_PCS_BASE (2 + 3 + 4 + 5)

typedef struct {
    pid_t pid;
    hcount_t pieces;
    map_t board;
} player_t;

#endif /* !PLAYER_INFO_H */
