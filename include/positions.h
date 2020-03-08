/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** Position fetching and validation
*/

#ifndef POSITIONS_H
#define POSITIONS_H

#include <stdbool.h>

#include "fox_define.h"

#define MAX_SHIPS (4)

// Lines shall be of the format defined by this regex :
//   * [2-5]:[A-H][1-8]:[A-H][1-8] (and a null terminator)
// Representing these values :
//   * LENGTH:START_INDEX:END_INDEX
typedef char posline_t[8];

// A position buffer contains 4 lines
typedef posline_t posbuff_t[MAX_SHIPS];

// Try opening a map file.
//
// Returns true in case of error.
bool pos_open(str2c_t path, int *fdp) __Anonnull;

// Write the contents of a pos file in a char buffer if it's valid, meaning :
//   * File contains just the right amount of characters (MAX_SHIPS * 8 ± 1);
//
// Returns true in case of error.
bool pos_read(int fd, posbuff_t buff) __Anonnull;

// Check if positions are valid, meaning :
//   * Lines are of the format defined by posline_t's regex
//   * Ships are of size 2, 3, 4 and 5
//   * Ship actual size matches given size
//   * Ship positions are in bounds
//
// Returns false and sets file offset to 0 on success
// Returns true in case of error.
bool pos_verif_line(posline_t ln);

#endif /* !POSITIONS_H */
