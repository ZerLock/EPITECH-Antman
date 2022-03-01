/*
** EPITECH PROJECT, 2022
** find_nodes.c
** File description:
** find a node and return it
*/

#include "../include/header.h"

char *my_find_node(node_t *tree, char key)
{
    char *temp;

    if (tree->c == key && !tree->right && !tree->left)
        return (tree->binary);
    if (tree->left) {
        if ((temp = my_find_node(tree->left, key)) != NULL)
            return (temp);
    }
    if (tree->right) {
        if ((temp = my_find_node(tree->right, key)) != NULL)
            return (temp);
    }
    return (NULL);
}
