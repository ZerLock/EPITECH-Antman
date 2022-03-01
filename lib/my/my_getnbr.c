/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** transform a string into a number
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    long int res = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == 43 || str[i] == 45) {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        res = res * 10 + (str[i] - 48);
        i++;
        if (res > 2147483648 || (res == 2147483648 && sign == 1))
            return (0);
    }
    return (res * sign);
}
