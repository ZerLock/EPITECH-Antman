/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** display a number
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    unsigned int nbr = nb;

    if (nb < 0) {
        nbr *= -1;
        my_putchar('-');
    }
    if (nbr > 9) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    } else
        my_putchar(nbr + 48);
    return (0);
}
