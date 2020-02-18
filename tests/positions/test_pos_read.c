/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** UT: Reading a positions file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_memory.h"

#include "io.h"
#include "positions.h"

#include "tests/test_positions.h"

Test(pos_read, regular_usage)
{
    __close int fd;
    posbuff_t buff = {0};

    cr_assert_not(pos_open((*POS_VALID)[0], &fd));
    cr_expect_not(pos_read(fd, buff));
    cr_expect_arr_eq((str_t) buff, (*POS_VALID)[1], ARRAY_SIZE(buff));
}

Test(pos_red, not_enough_chars, .init = cr_redirect_stderr)
{
    __close int fd;
    posbuff_t buff = {0};
    str2c_t e = NAVY_ERR[E_POS_NECHARS];
    char emsg[strlen(e)];

    strcpy(emsg, e);
    strcat(emsg, "\n");
    cr_assert_not(pos_open((*POS_INVAL)[PIX_NOTENOUGH][0], &fd));
    cr_expect(pos_read(fd, buff));
    cr_expect_stderr_eq_str(emsg);
}

Test(pos_red, too_many_chars, .init = cr_redirect_stderr)
{
    __close int fd;
    posbuff_t buff = {0};
    str2c_t e = NAVY_ERR[E_POS_TMCHARS];
    char emsg[strlen(e)];

    strcpy(emsg, e);
    strcat(emsg, "\n");
    cr_assert_not(pos_open((*POS_INVAL)[PIX_TOOMANY][0], &fd));
    cr_expect(pos_read(fd, buff));
    cr_expect_stderr_eq_str(emsg);
}
