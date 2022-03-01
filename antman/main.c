/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "header.h"

int main(int ac, char **av)
{
    if (antman(ac, av) == EXIT_ERROR)
        return (EXIT_ERROR);
    return (EXIT_SUCCESS);
}
