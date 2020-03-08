/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** File used for first connection btw process
*/

#include <stdbool.h>
#include <stdlib.h>

#include "fox_define.h"
#include "fox_io.h"

#include "sighan.h"

static bool send_sig(void)
{
    if (kill(SIG_G.enemy_pid, SIGUSR1))
        return (true);
    return (false);
}

static void sig_catch(
    __Aunused int sig, siginfo_t *siginfo, __Aunused void *context)
{
    (void) context;
    if (SIG_G.enemy_pid == 0)
        SIG_G.enemy_pid = siginfo->si_pid;
    else if (SIG_G.enemy_pid != siginfo->si_pid)
        SIG_G.error = true;
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
    fox_printf("my_pid: %u\n", SIG_G.my_pid);
    if (SIG_G.whoami == CLIENT) {
        if (send_sig())
            return (true);
        else if (receive_sig())
            return (true);
        fox_printf("successfully connected\n");
    } else {
        fox_printf("waiting for enemy connection...\n");
        if (receive_sig())
            return (true);
        else if (send_sig())
            return (true);
        fox_printf("\nenemy connected\n");
    }
    return (SIG_G.error);
}
