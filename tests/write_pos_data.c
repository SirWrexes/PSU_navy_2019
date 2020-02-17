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

__Aconstructor static void write_pos_data(void)
{
    for (index_t i = 0; POS_INVAL[i] != NULL; i += 1)
        if (write_file((*POS_INVAL[i])[0], (*POS_INVAL[i])[1]))
            abort();
}

int main(void)
{
    return 0;
}
