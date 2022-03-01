/*
** EPITECH PROJECT, 2022
** antman
** File description:
** data compress
*/

#include "../../include/lib.h"

int add_to_buffer(char *buffer, char const *str, int i,  int size)
{
    int k;

    k = 0;
    for (int j = i; j < i + size; j++, k++)
        buffer[j] = str[k];
    return (i + size);
}
