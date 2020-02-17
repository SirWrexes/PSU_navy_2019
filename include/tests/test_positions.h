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

// Eveything is fine
static const posref_t POS_OK = {
    "./POS_OK.tmp",
    "2:C1:C2\n"
    "3:D4:F4\n"
    "4:B5:B8\n"
    "5:D7:H7\n",
};

// Missing one ship
static const posref_t POS_NOTENOUGH = {
    "./POS_NOTENOUGH.tmp",
    "2:C1:C2\n"
    "3:D4:F4\n"
    "4:B5:B8\n",
};

// There are too many ships
static const posref_t POS_TOOMANY = {
    "./POS_TOOMANY.tmp",
    "2:C1:C2\n"
    "3:D4:F4\n"
    "4:B5:B8\n"
    "5:D7:H7\n"
    "5:B1:F1\n",
};

// A ship's size doesn't correspond to its positions
static const posref_t POS_INVALSZ1 = {
    "./POS_INVALSZ1.tmp",
    "2:C1:C3\n"
    "3:D4:F4\n"
    "4:B5:B8\n"
    "5:D7:H7\n",
};

// A ship has a size diferrent than [2-5]
static const posref_t POS_INVALSZ2 = {
    "./POS_INVALSZ2.tmp",
    "2:C1:C2\n"
    "3:D4:F4\n"
    "4:B5:B8\n"
    "6:D7:H8\n",
};

// A ship is out of bounds
static const posref_t POS_OUTOFBOUNDS = {
    "./POS_OUTOFBOUNDS.tmp",
    "2:C1:C2\n"
    "3:D4:F4\n"
    "4:B5:B8\n"
    "5:D8:H8\n",
};

// Array containing every invalid position data for tests
static const posref_t *POS_INVAL[] = {
    &POS_NOTENOUGH,
    &POS_TOOMANY,
    &POS_INVALSZ1,
    &POS_INVALSZ2,
    &POS_OUTOFBOUNDS,
    NULL,
};

#endif /* !TEST_POSITIONS_H */
