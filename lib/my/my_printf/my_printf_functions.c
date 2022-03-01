/*
** EPITECH PROJECT, 2021
** my_printf_functions.c
** File description:
** print new needed functions
*/

#include "../../../include/my.h"

int my_put_unbr(unsigned int nbr)
{
    if (nbr > 9) {
        my_put_unbr(nbr / 10);
        my_put_unbr(nbr % 10);
    } else
        my_putchar(nbr + 48);
    return (0);
}

int my_put_longnbr_base(unsigned long nbr, char const *base)
{
    int base_len = my_strlen(base);

    if (nbr != 0) {
        my_put_longnbr_base(nbr / base_len, base);
        my_putchar(base[nbr % base_len]);
    }
    return (0);
}

int my_putunbr_base(unsigned int nbr, char const *base)
{
    int base_len = my_strlen(base);

    if (nbr != 0) {
        my_putnbr_base(nbr / base_len, base);
        my_putchar(base[nbr % base_len]);
    }
    return (0);
}

void upper_s_fid_print_octal_nb(char c)
{
    if (c < 8)
        my_putstr("\\00", 1);
    if (c > 8 && c < 32)
        my_putstr("\\0", 1);
    if (c > 126)
        my_putchar('\\');
    my_putnbr_base(c, "01234567");
}

int upper_s_fid(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] < 32 || str[i] >= 127) {
            upper_s_fid_print_octal_nb(str[i]);
        } else
            my_putchar(str[i]);
        i += 1;
    }
    return (0);
}
