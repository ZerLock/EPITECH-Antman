/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include "../../include/my.h"

/* binary tree */
typedef struct node {
    struct node *left;
    struct node *right;
    struct node *next;
    char *binary;
    char c;
    int is_alive;
    int freq;
} node_t;

typedef struct list {
    node_t *node;
} list_t;

/* antman */
int antman(int ac, char **av);
int get_zero_end_str(char *str, int len, int pars);
char *transform_to_bin(node_t *tree, char *src, int *len);

/* transform_to_binary */
void print_compressed_data(char *binary, int len);
void binary_to_ascii(char *str, int len);

/* get_min_node */
int research_node(node_t *tmp, char *str, int i, int is_new);
node_t *get_freq_in_str(char *str, int size);

/* find_node */
char *my_find_node(node_t *tree, char key);

/* key */
void print_key_for_node(node_t *node);
void compress_key(node_t *tree);
int get_key_size(node_t *tree);
char get_size_of_key_size(int key_size);

/* free */
void free_all(char *str, node_t *node);
int free_list(node_t *list);
int delete_first_node(node_t **list);
int delete_node(node_t **list, char key);
void free_binary_tree(node_t *tree);

/* binary_tree */
int create_binary_tree(node_t **list, int len);
void create_all_binary_code(node_t *tree, char *binary);
int my_put_in_binary_tree(node_t **list, node_t *a, node_t *b);

/* linked_list */
int my_put_in_list(node_t **list, char c);
void my_print_list(node_t *list);
int get_nb_node_in_list(node_t *list);
node_t *get_min_node(node_t **list);

/* add_to_buffer */
int add_to_buffer(char *buffer, char const *str, int i,  int size);

#endif /* HEADER_H_ */
