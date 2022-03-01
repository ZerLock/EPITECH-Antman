/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "header.h"

char my_strlen_char(char const *src)
{
    char c = 0;

    for (int i = 0, c = 0; src[i]; i++)
        c += 1;
    return (c);
}

void print_key_for_node(node_t *node)
{
    char len;

    write(1, &node->c, 1);
    len = my_strlen(node->binary);
    write(1, &len, 1);
    binary_to_ascii(node->binary, len);
}

void compress_key(node_t *tree)
{
    if (tree->right && tree->left) {
        compress_key(tree->left);
        compress_key(tree->right);
    } else
        print_key_for_node(tree);
}

int get_key_size(node_t *tree)
{
    int count = 0;
    int len = 0;

    if (tree->left && tree->right) {
        count += get_key_size(tree->left);
        count += get_key_size(tree->right);
    } else {
        len = my_strlen(tree->binary);
        return (len / 8 + 1 + 2 + (len % 8 == 0 ? 0 : 1));
    }
    return (count);
}

char get_size_of_key_size(int key_size)
{
    char count = 0;
    while (key_size > 0) {
        count++;
        key_size /= 10;
    }
    return (count);
}
