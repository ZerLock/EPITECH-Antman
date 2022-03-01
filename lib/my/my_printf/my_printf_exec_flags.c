/*
** EPITECH PROJECT, 2021
** my_printf_exec_flags.c
** File description:
** executes flags
*/

#include "../../../include/my.h"

void hashtag_f(char fid)
{
    if (fid == 'o')
        my_putchar('0');
    if (fid == 'x')
        my_putstr("0x", 1);
    if (fid == 'X')
        my_putstr("0X", 1);
}

void plus_f(int nbr)
{
    if (nbr >= 0)
        my_putchar('+');
}

void int_exec_flags(int nbr, char *opt, char fid)
{
    struct flags opt_flag = {0, 0, 0, 0};

    for (int i = 0 ; opt[i] != 0 ; i++) {
        if (opt[i] == '#' && opt_flag.hashtag_flag == 0) {
            opt_flag.hashtag_flag = 1;
            hashtag_f(fid);
        }
        if (opt[i] == '+' && opt_flag.plus_flag == 0) {
            opt_flag.plus_flag = 1;
            plus_f(nbr);
        }
    }
}
