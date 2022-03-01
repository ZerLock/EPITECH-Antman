/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "header.h"

int create_binary_tree(node_t **list, int len)
{
    node_t *min_one = NULL;
    node_t *min_two = NULL;
    node_t *tmp;

    min_one = *list;
    tmp = (*list)->next;
    for (int i = 0; i < len - 1; i++) {
        min_one = get_min_node(list);
        min_two = get_min_node(list);
        my_put_in_binary_tree(list, min_one, min_two);
    }
    return (EXIT_SUCCESS);
}

void create_all_binary_code(node_t *tree, char *binary)
{
    if (tree->right && tree->left) {
        create_all_binary_code(tree->right, my_strcat(binary, "1"));
        create_all_binary_code(tree->left, my_strcat(binary, "0"));
    } else
        tree->binary = my_strdup(binary);
}

int my_put_in_binary_tree(node_t **list, node_t *a, node_t *b)
{
    node_t *node;

    node = malloc(sizeof(node_t));
    if (!node)
        return (EXIT_ERROR);
    node->freq = a->freq + b->freq;
    node->left = a;
    node->right = b;
    node->c = 42;
    node->is_alive = 1;
    node->next = *list;
    *list = node;
    return (EXIT_SUCCESS);
}
