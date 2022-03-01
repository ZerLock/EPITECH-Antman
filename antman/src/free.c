/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "header.h"

void free_all(char *str, node_t *node)
{
    free(str);
    free_list(node);
}

int delete_first_node(node_t **list)
{
    node_t *tmp;

    if (!(*list))
        return (EXIT_ERROR);
    tmp = *list;
    *list = (*list)->next;
    return (EXIT_SUCCESS);
}

int delete_node(node_t **list, char key)
{
    node_t *tmp;
    node_t *prev;

    prev = *list;
    if (prev->c == key) {
        delete_first_node(list);
        return (EXIT_SUCCESS);
    }
    if (!prev || !prev->next)
        return (EXIT_ERROR);
    tmp = prev->next;
    while (tmp && tmp->c != key) {
        prev = prev->next;
        tmp = tmp->next;
    }
    if (tmp)
        prev->next = tmp->next;
    return (EXIT_SUCCESS);
}

int free_list(node_t *list)
{
    node_t *tmp;

    while (list->next) {
        tmp = list;
        list = list->next;
        if (!tmp->right && !tmp->left)
            free(tmp->binary);
        free(tmp);
    }
    free(list);
}

void free_binary_tree(node_t *tree)
{
    if (!tree)
        return;
    free_binary_tree(tree->left);
    free_binary_tree(tree->right);
    free(tree);
}
