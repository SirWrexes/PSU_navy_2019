/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** File used for first connection btw process
*/

#include <stdbool.h>
#include <stdlib.h>
#include "sighan.h"

static bool send_sig(void)
{
    if (kill(SIG_G.enemy_pid, SIGUSR1))
        return (true);
    return (false);
}

static void sig_catch(int sig, siginfo_t *siginfo, void *context)
{
    (void) context;
    if (SIG_G.enemy_pid == 0)
        SIG_G.enemy_pid = siginfo->si_pid;
    else if (SIG_G.enemy_pid != siginfo->si_pid)
        SIG_G.error = true;
    if (sig == SIGUSR1)
        write(1, "sig receive\n", 12);
    else if (sig == SIGUSR2)
        write(1, "sig receive\n", 12);
}

static bool receive_sig(void)
{
    struct sigaction siga_s;

    siga_s.sa_flags = SA_SIGINFO;
    siga_s.sa_sigaction = &sig_catch;
    if (sigaction(SIGUSR1, &siga_s, NULL))
        return (true);
    if (sigaction(SIGUSR2, &siga_s, NULL))
        return (true);
    pause();
    return (false);
}

bool create_connection(void)
{
    if (SIG_G.enemy_pid) {
        if (send_sig())
            return (true);
        else if (receive_sig())
            return (true);
    } else {
        if (receive_sig())
            return (true);
        else if (send_sig())
            return (true);
    }
    return (SIG_G.error);
}
