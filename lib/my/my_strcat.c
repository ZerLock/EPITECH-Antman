/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concatenate 2 strings into a new
*/

#include "../../include/lib.h"
#include <stdlib.h>

char *my_strcat(char *s1, char *s2)
{
    int len = my_strlen(s1) + my_strlen(s2);
    char *dest = malloc(sizeof(char) * (len + 1));
    int i;
    int j;

    if (!dest)
        return (NULL);
    for (i = 0; s1[i]; i++)
        dest[i] = s1[i];
    for (j = 0; s2[j]; j++, i++)
        dest[i] = s2[j];
    dest[len] = '\0';
    return (dest);
}
