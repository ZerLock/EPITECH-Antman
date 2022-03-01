/*
** EPITECH PROJECT, 2022
** get_key.c
** File description:
** get the key
*/

#include "../include/header.h"

char *get_key(char *file, int key_size)
{
    char *key = malloc(sizeof(char) * key_size + 1);
    int i = 0;

    while (i < key_size) {
        key[i] = file[i + file[0] + 1];
        i += 1;
    }
    key[i] = 0;
    return (key);
}

int get_size_of_the_key(char *file)
{
    char *key_size = malloc(sizeof(char) * file[0] + 1);
    int result;

    for (int i = 0 ; i < file[0] ; i++)
        key_size[i] = file[i + 1];
    key_size[file[0]] = 0;
    result = my_getnbr(key_size);
    free(key_size);
    return (result);
}

int get_size_of_key_size(int key_size)
{
    int count = 0;

    while (key_size > 0) {
        count++;
        key_size /= 10;
    }
    return (count);
}
