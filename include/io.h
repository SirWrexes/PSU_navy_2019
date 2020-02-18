/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** io.h -- No description
*/

#ifndef IO_H
#define IO_H

#include "fox_define.h"

// Error messages index
enum navy_error {
    /* Print those on STDERR */
    E_POS_TMCHARS,
    E_POS_NECHARS,

    /* Print those on STDOUT */

    /* KEEP LAST */
    E_CNT
};

extern const str2c_t NAVY_ERR[E_CNT];

#endif /* !IO_H */
