/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "../../include/my.h"

int check_error(int ac, char **av)
{
    int fd;

    if (ac != 3)
        return (-1);
    if (my_strcmp(av[2], "1") != 0 && my_strcmp(av[2], "2") != 0 &&
    my_strcmp(av[2], "3") != 0)
        return (-1);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    return (fd);
}
