/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse a string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    int mid = len / 2;
    char buffer;
    int i = 0;

    while (i <= mid) {
        buffer = str[i];
        str[i] = str[len - i];
        str[len - i] = buffer;
        i += 1;
    }
    return (str);
}
