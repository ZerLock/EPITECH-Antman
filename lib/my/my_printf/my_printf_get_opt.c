/*
** EPITECH PROJECT, 2021
** my_printf_get_opt.c
** File description:
** get flags and formats identifier
*/

#include "../../../include/my.h"

int is_fid(char c)
{
    char fid[] = "dioxXucspbS%";

    for (int i = 0 ; fid[i] != 0 ; i++)
        if (c == fid[i])
            return (i);
    return (-1);
}

int is_flag(char c)
{
    char flags[] = "-0123456789+#";

    for (int i = 0 ; flags[i] != 0 ; i++)
        if (c == flags[i])
            return (i);
    return (-1);
}

int get_opt_size(char *str, int init_pos)
{
    int len = 0;
    int i = init_pos;

    while (is_flag(str[i]) >= 0) {
        i += 1;
        len += 1;
    }
    if (is_fid(str[i]) < 0)
        return (0);
    return (len + 1);
}

char *get_opt(char *str, int pos, int opt_size)
{
    char *opt = malloc(sizeof(char) * (opt_size + 1));
    int i = 0;

    while (i < opt_size) {
        opt[i] = str[pos];
        i += 1;
        pos += 1;
    }
    opt[opt_size] = 0;
    return (opt);
}
