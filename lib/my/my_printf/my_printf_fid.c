/*
** EPITECH PROJECT, 2021
** my_printf_fid.c
** File description:
** printf all format identifiers
*/

#include "../../../include/my.h"

void str_fid(char *str, char *opt, char fid)
{
    if (fid == 's')
        my_putstr(str, 1);
    if (fid == 'S')
        upper_s_fid(str);
}

int int_fid(int nb, char *opt, char fid)
{
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    int_exec_flags(nb, opt, fid);
    if (fid == 'd' || fid == 'i')
        my_put_nbr(nb);
    if (fid == 'o')
        my_putnbr_base(nb, "01234567");
    if (fid == 'x')
        my_putnbr_base(nb, "0123456789abcdef");
    if (fid == 'X')
        my_putnbr_base(nb, "0123456789ABCDEF");
    return (0);
}

void uint_fid(unsigned int nb, char *opt, char fid)
{
    if (fid == 'u')
        my_put_unbr(nb);
    if (fid == 'b')
        my_putunbr_base(nb, "01");
}

void ulong_fid(unsigned long nb, char *opt, char fid)
{
    my_putstr("0x", 1);
    my_put_longnbr_base(nb, "0123456789abcdef");
}
