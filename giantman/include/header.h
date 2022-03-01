/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** decompress data
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include "../../include/my.h"

/* linked list */
typedef struct llist_l {
    char letter;
    char *binary;
    struct llist_l *next;
} list_t;

/* giantman */
int giantman(int ac, char **av);
char *add_zeros(char *tmp, int len);
char *decompress_each_char(char *key, int j, int i);
char *decompress_char(char *key, int i);

/* get_key */
int get_size_of_the_key(char *file);
int get_size_of_key_size(int key_size);
char *get_key(char *file, int key_size);
list_t *create_linked_list(char *key, int len);

/* list */
int free_list(list_t *list_key);

/* decrypt_bitshift */
char *decrypt_bitshift(char c, int nb_zero);

/* decrypt binary */
void print_decompress_file(char *file, list_t *list);

#endif /* HEADER_H_ */
