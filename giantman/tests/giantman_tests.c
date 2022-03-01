/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (giantman, giantman, .init = redirect_all_std)
{
    char *av[] = {"./giantman", "tests/ph_compressed", "3", NULL};
    giantman(3, av);
}
