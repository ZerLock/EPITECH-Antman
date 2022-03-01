/*
** EPITECH PROJECT, 2022
** Antman
** File description:
** decompress the file
*/

#include "../include/header.h"

int compare_binary(char *file, list_t *node)
{
    for (int i = 0; node->binary[i]; i++) {
        if (file[i] != node->binary[i])
            return (-1);
    }
    return (0);
}

list_t *get_binary_letter(char *file, list_t *list)
{
    list_t *temp = list;

    while (compare_binary(file, temp) != 0)
        temp = temp->next;
    return (temp);
}

void print_decompress_file(char *file, list_t *list)
{
    list_t *node = NULL;
    int i = 0;
    int binary_len = my_strlen(file);

    while (i < binary_len) {
        node = get_binary_letter(&file[i], list);
        my_putchar(node->letter);
        i += my_strlen(node->binary);
    }
}

char *decompress_each_char(char *key, int j, int i)
{
    int c = (unsigned char) key[j + i + 1];
    return (int_to_base(c, 2));
}

char *decompress_char(char *key, int i)
{
    char *bin = "";
    char *tmp;
    int len = key[i + 1];
    int len_c = (len % 8 == 0) ? len / 8 : len / 8 + 1;
    int k;
    int j;
    for (j = 1; j < len_c; j++) {
        tmp = decompress_each_char(key, j, i);
        for (k = my_strlen(tmp); k < 8; k++)
            tmp[k] = '0';
        tmp[k] = '\0';
        bin = my_strcat(bin, my_revstr(tmp));
    }
    tmp = decompress_each_char(key, j, i);
    j = my_strlen(tmp);
    for (k = my_strlen(tmp); k < j + key[len_c + 2 + i] - '0'; k++)
        tmp[k] = '0';
    tmp[k] = '\0';
    bin = my_strcat(bin, my_revstr(tmp));
    return (bin);
}
