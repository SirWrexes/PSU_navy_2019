/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** pos_read.c -- No description
*/

#include <stdbool.h>
#include <unistd.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_memory.h"
#include "fox_string.h"

#include "io.h"
#include "positions.h"

static const size_t SZ_MAX = sizeof(posbuff_t) / sizeof(char);
static const size_t SZ_TMP = 2 * SZ_MAX;

__Anonnull bool pos_read(int fd, posbuff_t buff)
{
    char tmp[SZ_TMP];

    fox_memset(tmp, '\0', sizeof(tmp));
    if (__unlikely(read(fd, tmp, SZ_TMP) == -1))
        return !!fox_perror(__func__);
    if (tmp[SZ_MAX - 2] == '\0')
        return !!fox_eprintf("%s\n", NAVY_ERR[E_POS_NECHARS]);
    if (tmp[SZ_MAX - 1] != '\0' && ((tmp[SZ_MAX - 1] | tmp[SZ_MAX]) != '\n'))
        return !!fox_eprintf("%s\n", NAVY_ERR[E_POS_TMCHARS]);
    fox_memcpy(buff, tmp, sizeof(posbuff_t));
    for (hindex_t i = 0; i < 4; i += 1)
        buff[i][7] = '\0';
    return false;
}
