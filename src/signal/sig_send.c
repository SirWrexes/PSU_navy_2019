/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** File for signal sending handling
*/

#include <signal.h>
#include <stdbool.h>
#include "sighan.h"

bool sending(void)
{
    for (int i = 0; SIG_G.bin_pos[i] == -1; i++) {
        if (SIG_G.bin_pos[i] == 0 && kill(SIG_G.enemy_pid, SIGUSR2))
            return (true);
        else if (SIG_G.bin_pos[i] == 1 && kill(SIG_G.enemy_pid, SIGUSR1))
            return (true);
    }
    return (false);
}
