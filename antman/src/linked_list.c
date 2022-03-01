/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "../include/header.h"

int get_nb_node_in_list(node_t *list)
{
    node_t *tmp;
    int i;

    tmp = list;
    for (i = 0; tmp; tmp = tmp->next, i++);
    return (i);
}

int my_put_in_list(node_t **list, char c)
{
    node_t *node;

    node = malloc(sizeof(node_t));
    if (!node)
        return (EXIT_ERROR);
    node->c = c;
    node->next = *list;
    node->left = NULL;
    node->right = NULL;
    node->freq = 1;
    node->is_alive = 1;
    *list = node;
    return (EXIT_SUCCESS);
}

void my_print_list(node_t *list)
{
    node_t *tmp;

    tmp = list;
    while (tmp) {
        my_printf("Letter: %c - Freq: %d", tmp->c, tmp->freq);
        my_printf(" - Is_alive: %d\n", tmp->is_alive);
        tmp = tmp->next;
    }
}

node_t *get_min_node(node_t **list)
{
    node_t *min;
    node_t *tmp;

    min = *list;
    while (!min->is_alive && min)
        min = min->next;
    tmp = min->next;
    while (tmp) {
        if (tmp->freq < min->freq && tmp->is_alive)
            min = tmp;
        tmp = tmp->next;
    }
    min->is_alive = 0;
    return (min);
}
