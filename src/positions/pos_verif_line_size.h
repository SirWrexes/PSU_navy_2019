/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** pos_verif_line_extra.h -- No description
*/

#ifndef POS_VERIF_LINE_SIZE_H
#define POS_VERIF_LINE_SIZE_H

#include "fox_define.h"

// Size verification
__Anonnull static inline bool size_is_valid(char sz)
{
    return (sz >= '2' && sz <= '5');
}

// Actual size match verification
__Anonnull static inline bool horizontal_size_is_valid(str2c_t pos, char len)
{
    len -= 1;
    return (pos[3] == pos[0] + len) || (pos[3] == pos[0] - len);
}

__Anonnull static inline bool vertical_size_is_valid(str2c_t pos, char len)
{
    len -= 1;
    return (pos[4] == pos[1] + len) || (pos[4] == pos[1] - len);
}

static bool (*const CHECK_XY_SIZE[2])(str2c_t, char len) = {
    &horizontal_size_is_valid,
    &vertical_size_is_valid,
};

#endif /* !POS_VERIF_LINE_SIZE_H */
