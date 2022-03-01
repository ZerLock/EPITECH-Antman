/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include "header.h"

char *transform_to_bin(node_t *tree, char *src, int *len)
{
    char *str;
    char *tmp;
    int i;
    int j = 0;

    str = malloc(sizeof(char) * my_strlen(src) * 8);
    if (!str)
        return (NULL);
    *str = '\0';
    for (i = 0; src[i]; i++) {
        tmp = my_find_node(tree, src[i]);
        j = add_to_buffer(str, tmp, j, my_strlen(tmp));
    }
    str[j] = '\0';
    *len = j;
    free(src);
    return (str);
}

int get_zero_end_str(char *str, int len, int pars)
{
    int c;
    int i;

    c = 0;
    i = len - pars;
    for (; i < len && str[i] == '0'; i++)
        c += 1;
    return (c);
}

int antman(int ac, char **av)
{
    char *str_binary;
    int key_size;
    int len = 0;
    node_t *node;
    char *str_uncompressed;
    int fd;

    if ((fd = check_error(ac, av)) == EXIT_ERROR ||
    !(str_uncompressed = read_file(fd, av[1])) ||
    !(node = get_freq_in_str(str_uncompressed, get_size(av[1]))))
        return (EXIT_ERROR);
    create_binary_tree(&node, get_nb_node_in_list(node));
    create_all_binary_code(node, "");
    str_binary = transform_to_bin(node, str_uncompressed, &len);
    key_size = get_key_size(node);
    my_printf("%c%d", get_size_of_key_size(key_size), key_size);
    compress_key(node);
    binary_to_ascii(str_binary, len);
    return (EXIT_SUCCESS);
}
