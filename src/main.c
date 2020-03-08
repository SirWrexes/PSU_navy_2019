/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Main source | algo root
*/

#include <stdlib.h>
#include <unistd.h>

#include "fox_io.h"

#include "io.h"
#include "map.h"
#include "positions.h"
#include "player_info.h"

int main(int __Aunused ac, str_t *av)
{
    player_t me = {.pid = getpid(), .pieces = PLAYER_PCS_BASE};
    player_t them = {.pieces = PLAYER_PCS_BASE};

    if (map_create_from_file(me.board, av[ac - 1]))
        return EPITECH_ERROR;
    map_init_empty(them.board);
    if (ac == 2)
        them.pid = wait_for_client();
    else if (ac == 3)
        them.pid = connect_to_host();
    else
        return EPITECH_ERROR | !fox_eprintf("Invalid argument count\n");
    return EXIT_SUCCESS;
}
