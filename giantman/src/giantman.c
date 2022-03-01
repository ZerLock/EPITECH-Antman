/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** decompress data
*/

#include "../include/header.h"

char *add_zeros(char *tmp, int len)
{
    for (int i = 0; i < 8 - len; i++)
        tmp = my_strcat(tmp, "0");
    return (tmp);
}

char *decompress_all_data(char *str, int i, int size)
{
    char *data = malloc(sizeof(char) * (8 * size - 1));
    char *tmp;
    int pos = 0;
    int tmp_char;

    for (; i < size - 3; i++) {
        tmp_char = (unsigned char) str[i];
        tmp = int_to_base(tmp_char, 2);
        tmp = add_zeros(tmp, my_strlen(tmp));
        pos = add_to_buffer(data, my_revstr(tmp), pos, 8);
    }
    tmp_char = (unsigned char) str[size - 3];
    tmp = int_to_base(tmp_char, 2);
    for (int j = 0; j < str[size - 2] - '0'; j++)
        tmp = my_strcat(tmp, "0");
    pos = add_to_buffer(data, my_revstr(tmp), pos, my_strlen(tmp));
    data[pos] = '\0';
    return (data);
}

char *create_void_str(void)
{
    char *str = malloc(sizeof(char) * 7);
    if (!str)
        return (NULL);
    str[0] = 1;
    str[1] = '3';
    str[2] = 0;
    str[3] = 0;
    str[4] = '0';
    str[5] = '0';
    str[6] = '\0';
    return (str);
}

int giantman(int ac, char **av)
{
    int fd = check_error(ac, av);
    char *str_compressed;
    char *str_unpacked;
    int len;
    int len_decompressed;
    int i = 0;
    list_t *list = NULL;
    int len_binary;
    if (fd == EXIT_ERROR || !(str_compressed = read_file(fd, av[1])))
        return (EXIT_ERROR);
    if (my_strcmp(str_compressed, create_void_str()) == 0)
        return (EXIT_SUCCESS);
    len = get_size_of_the_key(str_compressed);
    list = create_linked_list(get_key(str_compressed, len), len);
    len = 1 + get_size_of_the_key(str_compressed) + str_compressed[0];
    str_unpacked = decompress_all_data(str_compressed, len, get_size(av[1]));
    print_decompress_file(str_unpacked, list);
    free_list(list);
    free(str_compressed);
    return (EXIT_SUCCESS);
}
