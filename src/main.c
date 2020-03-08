/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Main source | algo root
*/

#include <stdlib.h>
#include <unistd.h>

#include "fox_io.h"
#include "fox_std.h"

#include "game.h"
#include "io.h"
#include "map.h"
#include "positions.h"
#include "sighan.h"

__Anonnull static int navy_run(player_t *me, player_t *them)
{
    status_t s = NAVY_RUNNING;

    while (s == NAVY_RUNNING) {
        display_current_boards(me, them);
        PLAYER_TURN[SIG_G.whoami](me, them);
        PLAYER_TURN[!SIG_G.whoami](me, them);
        s = 0;
    }
    fox_printf("%s won\n", (s == NAVY_WON) ? "I" : "Enemy");
    return s;
}

int main(int ac, str_t *av)
{
    player_t me = {.pieces = PLAYER_PCS_BASE};
    player_t them = {.pieces = PLAYER_PCS_BASE};

    SIG_G.my_pid = getpid();
    if (ac == 2) {
        SIG_G.enemy_pid = 0;
        SIG_G.whoami = HOST;
    } else if (ac == 3) {
        if (fox_strtol(av[1], NULL) <= 0)
            return EPITECH_ERROR | !fox_eprintf("Invalid pid: %s\n", av[1]);
        SIG_G.whoami = CLIENT;
        SIG_G.enemy_pid = fox_strtol(av[1], NULL);
    } else
        return EPITECH_ERROR | !fox_eprintf("Invalid argument count\n");
    if (map_create_from_file(me.board, av[ac - 1]))
        return EPITECH_ERROR;
    map_init_empty(them.board);
    if (create_connection())
        return EPITECH_ERROR | !fox_eprintf("Error during connection.\n");
    return navy_run(&me, &them);
}
