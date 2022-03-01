/*
** EPITECH PROJECT, 2021
** my_printf_handle_flags.c
** File description:
** handle flags
*/

#include "../../../include/my.h"

void analyse_opt(va_list list, char *opt)
{
    char fid = opt[my_strlen(opt) - 1];

    if (fid == '%')
        my_putchar('%');
    if (fid == 'c')
        my_putchar(va_arg(list, int));
    if (fid == 's' || fid == 'S')
        str_fid(va_arg(list, char *), opt, fid);
    if (fid == 'd' || fid == 'i')
        int_fid(va_arg(list, int), opt, fid);
    if (fid == 'o' || fid == 'x' || fid == 'X')
        int_fid(va_arg(list, int), opt, fid);
    if (fid == 'u' || fid == 'b')
        uint_fid(va_arg(list, unsigned int), opt, fid);
    if (fid == 'p')
        ulong_fid(va_arg(list, unsigned long), opt, fid);
}

int handle_flags(va_list list, char *str, int i)
{
    int opt_size = get_opt_size(str, i + 1);
    char *opt;

    if (opt_size == 0) {
        my_putchar('%');
        return (0);
    }
    opt = get_opt(str, i + 1, opt_size);
    analyse_opt(list, opt);
    free(opt);
    return (opt_size);
}
