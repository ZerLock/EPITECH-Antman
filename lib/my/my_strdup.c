/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** allocates memory and copies the string given as argument in it
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int src_len = my_strlen(src);
    char *to_return;
    int i = 0;

    to_return = malloc(sizeof(char) * (src_len + 1));
    if (!to_return)
        return (NULL);
    while (i < src_len) {
        to_return[i] = src[i];
        i += 1;
    }
    to_return[i] = '\0';
    return (to_return);
}
