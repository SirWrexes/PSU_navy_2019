/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** pos_open.c -- No description
*/

#include <fcntl.h>
#include <stdbool.h>

#include "fox_define.h"

__Anonnull bool pos_open(str2c_t path, int *fdp)
{
    *fdp = open(path, O_RDONLY);
    return __unlikely(*fdp == -1);
}
