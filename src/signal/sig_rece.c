/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** File for signal reception handling
*/

#include <signal.h>
#include <unistd.h>
#include "sighan.h"

static int bin_to_dec(int *bin)
{
    int ret = 0;

    for (int i = 0 ; bin[i] != -1 ; i++) {
        if (i < 4 && bin[i] == 1)
            ret += 10;
        else if (i > 3 && bin[i] == 1)
            ret += 1;
    }
    return (*bin);
}

static void sig_catch(int sig, siginfo_t *siginfo, void *context)
{
    (void) context;
    if (SIG_G.enemy_pid != siginfo->si_pid)
        SIG_G.error = true;
    if (sig == SIGUSR1)
        SIG_G.bin_pos[SIG_G.index] = 1;
    else if (sig == SIGUSR2)
        SIG_G.bin_pos[SIG_G.index] = 0;
    SIG_G.index += 1;
}

int signal_reception(void)
{
    struct sigaction siga_s;
    int ret = 0;

    siga_s.sa_flags = SA_SIGINFO;
    siga_s.sa_sigaction = &sig_catch;
    if (sigaction(SIGUSR1, &siga_s, NULL))
        return (-1);
    if (sigaction(SIGUSR2, &siga_s, NULL))
        return (-1);
    for (int i = 0 ; i < 8 ; i++)
        pause();
    ret = bin_to_dec(SIG_G.bin_pos);
    if (SIG_G.error == true)
        return (-1);
    return (ret);
}
