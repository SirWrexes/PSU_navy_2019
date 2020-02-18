/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** positions.h -- No description
*/

#ifndef TEST_POSITIONS_H
#define TEST_POSITIONS_H

#include "fox_define.h"

#include "positions.h"

// posref_t[0] = Ref path
// posref_t[1] = Ref contents
typedef str2c_t posref_t[2];

// Array containing every invalid position data for tests
extern const posref_t *POS_INVAL[];

// Pointer to the reference of a valid pos data file
extern const posref_t *POS_VALID;

#endif /* !TEST_POSITIONS_H */
