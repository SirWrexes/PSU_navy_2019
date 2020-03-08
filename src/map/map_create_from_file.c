/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** map_create_from_file.c -- No description
*/

#include "fox_define.h"
#include "fox_memory.h"
#include "fox_io.h"

#include "positions.h"
#include "map.h"

__Anonnull bool map_create_from_file(map_t map, str2c_t path)
{
    int fd;
    posbuff_t buff = {0};

    if (pos_open(path, &fd))
        return !!fox_eprintf("Error openning %s.\n", path);
    if (pos_read(fd, buff))
        return !!fox_eprintf("Error reading %s.\n", path);
    if (pos_verif(buff))
        return !!fox_eprintf("%s contains invalid position data.\n", path);
    fox_memset(map, '.', sizeof(map_t));

}
