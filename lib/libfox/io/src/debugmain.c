/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Main source
*/

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tests/printers.h"
#include "fox_define.h"
#include "fox_math.h"
#include "fox_io.h"

#include "printf/fstruct.h"
#include "printf/printers.h"

int main()
{
    fox_printf("%%s%%d%s%d%%\n", "Astek", 42);
    return EXIT_SUCCESS;
}
