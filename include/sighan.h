/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** header dedicated to signal and comm handling
*/

#ifndef SIGHAN_H
#define SIGHAN_H

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <signal.h>

// sighan_g declared as non-constant global variable used in signal handling
#define SIG_G sighan_g

// Struct used to receive and store signal information
// bin_pos contain non-converted binary position send by enemy
// index is used to navigate in bin_pos without having to re-initialize and
// re-count where in bin_pos you have stoped at last signal
// enemy_pid is the enemy pid used to send signal and error handling
// my_pid is the current process/player pid
// error is used for error handling in fuction that cannot return value
struct sighan_t {
    int *bin_pos;
    size_t index;
    pid_t enemy_pid;
    pid_t my_pid;
    bool error;
} sighan_g;

#endif /* !SIGHAN_H */
