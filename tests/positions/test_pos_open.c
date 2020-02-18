/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** test_pos_open.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_memory.h"

#include "tests/test_positions.h"
#include "tests/wrappers/wrap_open.h"

Test(pos_open, regular_usage, .init = fix_open)
{
    __close int fd = 0;

    cr_expect_not(pos_open("./POS_OK.tmp", &fd));
    cr_expect_neq(fd, 0);
}
