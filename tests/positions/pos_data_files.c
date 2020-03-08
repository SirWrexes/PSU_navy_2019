/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** write_pos_data.c -- No description
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fox_define.h"

#include "tests/test_positions.h"

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
    "5:D9:H9\n",
};

const posref_t *POS_VALID = &POS_OK;

const posref_t *POS_INVAL[] = {
    &POS_NOTENOUGH,
    &POS_TOOMANY,
    &POS_INVALSZ1,
    &POS_INVALSZ2,
    &POS_OUTOFBOUNDS,
    NULL,
};;

static void cleanup_filep(FILE **fp)
{
    if (*fp != NULL) {
        fclose(*fp);
        *fp = NULL;
    }
}

static bool write_file(str2c_t path, str2c_t contents)
{
    __Acleanup(cleanup_filep) FILE *file = fopen(path, "w+");

    if (file == NULL)
        return true;
    fwrite(contents, sizeof(*contents), strlen(contents), file);
    return false;
}

__Aconstructor static void create_pos_data(void)
{
    if (__unlikely(write_file((*POS_VALID)[0], (*POS_VALID)[1])))
        abort();
    for (index_t i = 0; POS_INVAL[i] != NULL; i += 1)
        if (__unlikely(write_file((*POS_INVAL[i])[0], (*POS_INVAL[i])[1])))
            abort();
}
