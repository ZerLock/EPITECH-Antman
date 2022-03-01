/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "header.h"

void print_compressed_data(char *binary, int len)
{
    char c;

    c = 0;
    write(1, binary, len);
}

void binary_to_ascii(char *str, int len)
{
    char *binary = malloc(sizeof(char) * len);
    char c = 0;
    int pars = 0;
    int j = 0;

    for (int i = 0; i < len; i++) {
        c += str[i] - '0';
        pars++;
        if (pars == 8 || i + 1 == len) {
            binary[j++] = c;
            c = 0;
            pars = (i + 1 == len) ? pars : 0 ;
        } else
            c <<= 1;
    }
    print_compressed_data(binary, j);
    j = get_zero_end_str(str, len, pars);
    my_put_nbr(j);
    free(str);
    free(binary);
}
