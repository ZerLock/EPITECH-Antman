/*
** EPITECH PROJECT, 2022
** int to binary
** File description:
** int_to_base
*/

#include "../../include/my.h"

char *int_to_base(unsigned int nb, int base)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * 9);
    if (!str)
        return (NULL);
    for (i = 0; nb > 0; i++) {
        str[i] = nb % base + '0';
        nb /= base;
    }
    str[i] = '\0';
    return (str);
}
