/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "../../include/my.h"

int get_size(char const *pathname)
{
    struct stat s;

    if (stat(pathname, &s) == -1)
        return (-1);
    return (s.st_size + 1);
}

char *read_file(int fd, char const *pathname)
{
    int size = get_size(pathname);
    char *str;
    int len;

    if (size <= 0)
        return (NULL);
    str = malloc(sizeof(char) * size);
    if (!str)
        return (NULL);
    if ((len = read(fd, str, size)) == -1)
        return (NULL);
    str[len] = '\0';
    return (str);
}
