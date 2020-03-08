/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** test_pos_verif_line.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_memory.h"

#include "tests/test_positions.h"

#include "positions.h"


Test(verif_line, regular_usage)
{
    __close int fd;
    posbuff_t buff = {0};

    cr_assert_not(pos_open((*POS_VALID)[0], &fd));
    cr_assert_not(pos_read(fd, buff));
    cr_expect_not(pos_verif_line((str_t) buff[1]));
}

Test(verif_line, inval_sz1){
    __close int fd;
    posbuff_t buff = {0};

    cr_assert_not(pos_open((*POS_INVAL)[PIX_INVALSZ1][0], &fd));
    cr_assert_not(pos_read(fd, buff));
    cr_expect(pos_verif_line(buff[0]));
}

Test(verif_line, inval_sz2)
{
    __close int fd;
    posbuff_t buff = {0};

    cr_assert_not(pos_open((*POS_INVAL)[PIX_INVALSZ2][0], &fd));
    cr_assert_not(pos_read(fd, buff));
    cr_expect(pos_verif_line(buff[3]));
}

Test(verif_line, oob)
{
    __close int fd;
    posbuff_t buff = {0};

    cr_assert_not(pos_open((*POS_INVAL)[PIX_OUTOFBOUNDS][0], &fd));
    cr_assert_not(pos_read(fd, buff));
    cr_expect(pos_verif_line(buff[3]));
}
