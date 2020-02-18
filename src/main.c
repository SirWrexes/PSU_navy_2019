/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Main source | algo root
*/

#include <stdlib.h>

#include "fox_memory.h"

#include "positions.h"

int main(int __Aunused ac, str_t *av)
{
    __close int fd;
    posbuff_t buff = {0};

    pos_open(av[1], &fd);
    pos_read(fd, buff);
    return EXIT_SUCCESS;
}
