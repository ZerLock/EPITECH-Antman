/*
** EPITECH PROJECT, 2021
** my_printf_main.c
** File description:
** main of the printf function
*/

#include "../../../include/my.h"

void my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0 ; str[i] != 0 ; i++) {
        if (str[i] == '%')
            i += handle_flags(list, str, i);
        else
            my_putchar(str[i]);
    }
    va_end(list);
}
