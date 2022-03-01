/*
** EPITECH PROJECT, 2021
** my_putnbr_base.c
** File description:
** print a decimal number in a different base
*/

#include "../../include/my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = my_strlen(base);
    unsigned int nb = nbr;

    if (nbr < 0) {
        nb *= - 1;
        my_putchar('-');
    }
    if (nbr != 0) {
        my_putnbr_base(nb / base_len, base);
        my_putchar(base[nb % base_len]);
    }
    return (0);
}
