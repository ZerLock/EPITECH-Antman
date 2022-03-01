/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** decompress data
*/

#include "header.h"

char *decrypt_bitshift(char c, int nb_zero)
{
    char *str;

    str = int_to_base(c > 0 ? c : c + 256, 2);
    my_putstr(str, 1);
    return (str);
}
