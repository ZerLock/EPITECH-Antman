/*
** EPITECH PROJECT, 2022
** llist.c
** File description:
** create linked_list
*/

#include "../include/header.h"

int free_list(list_t *list)
{
    list_t *tmp;

    while (list) {
        tmp = list;
        list = list->next;
        free(tmp->binary);
        free(tmp);
    }
    return (EXIT_SUCCESS);
}

list_t *put_element_in_list(char *key, int pos)
{
    list_t *node = malloc(sizeof(struct llist_l));
    int len = key[pos + 1] > 0 ? key[pos + 1] : key[pos + 1] + 256;

    len = (len % 8 == 0 ? len / 8 + 2 : len / 8 + 3);
    node->letter = key[pos];
    node->binary = decompress_char(key, pos);
    node->next = NULL;
    return (node);
}

list_t *create_linked_list(char *key, int len)
{
    list_t *begin = put_element_in_list(key, 0);
    list_t *node = begin;
    int i = 0;
    int char_len = key[i + 1];

    char_len = (char_len % 8 == 0 ? char_len / 8 + 3 : char_len / 8 + 4);
    i += char_len;
    while (i < len) {
        node->next = put_element_in_list(key, i);
        node = node->next;
        char_len = key[i + 1];
        char_len = (char_len % 8 == 0 ? char_len / 8 + 3 : char_len / 8 + 4);
        i += char_len;
    }
    return (begin);
}
