/*
** EPITECH PROJECT, 2022
** antman
** File description:
** data comrpess
*/

#include "header.h"

int research_node(node_t *tmp, char *str, int i, int is_new)
{
    while (tmp) {
        if (str[i] == tmp->c) {
            is_new += 1;
            tmp->freq += 1;
            break;
        }
        tmp = tmp->next;
    }
    return (is_new);
}

node_t *get_freq_in_str(char *str, int size)
{
    node_t *node = NULL;
    node_t *tmp = NULL;
    int i;
    int is_new;

    my_put_in_list(&node, str[0]);
    for (i = 1; i < size - 1; i++) {
        is_new = 0;
        tmp = node;
        is_new = research_node(tmp, str, i, is_new);
        if (is_new <= 0)
            my_put_in_list(&node, str[i]);
    }
    return (node);
}
