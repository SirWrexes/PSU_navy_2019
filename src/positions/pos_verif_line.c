/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** pos_veif_line.c -- No description
*/

#include <stdbool.h>

#include "fox_define.h"
#include "fox_io.h"
#include "fox_string.h"

#include "positions.h"

#include "./pos_verif_line_size.h"

__Anonnull static bool check_index(str_t *ln)
{
    static enum { CHECKX = 0, CHECKY = 1 } which = 0;

    switch (*(*ln)++) {
        case ':': return false;
        case 'A' ... 'H':
            if (which == CHECKX)
                break;
            return !!fox_eprintf("Invalid X index: %c\n", (*ln)[-1]);
        case '1' ... '8':
            if (which == CHECKY)
                break;
            return !!fox_eprintf("Ivalid Y index: %c\n", (*ln)[-1]);
        default: return !!fox_eprintf("Invalid index: %c\n", (*ln)[-1]);
    }
    which = !which;
    return false;
}

__Anonnull bool pos_verif_line(posline_t ln)
{
    char len;
    enum { HORIZONTAL = 0, VERTICAL = 1 } direction;

    if (!size_is_valid(*ln))
        return !!fox_eprintf("[%s] Invalid length: '%c'\n", ln, *ln);
    len = CHAR_TO_N(*ln);
    ln += 2;
    direction = (ln[0] == ln[3]) ? VERTICAL : HORIZONTAL;
    if (!CHECK_XY_SIZE[direction](ln, len))
        return !!fox_eprintf(
            "[%s] Invalid actual length (not %c)\n", ln, ln[-2]);
    while (*ln != '\0')
        if (check_index(&ln))
            return true;
    return false;
}
