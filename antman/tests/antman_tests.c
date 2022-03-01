/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress data
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"

void redirect_all_std(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test (antman, antman_global, .init = redirect_all_std)
{
    char *av[] = {"./antman", "Makefile", "3", NULL};
    antman(3, av);
}

Test (my_put_in_list, create_new_node_in_front_of_the_list)
{
    node_t *list = NULL;

    my_put_in_list(&list, 'c');
}

Test (my_print_list, print_the_list, .init = redirect_all_std)
{
    node_t *list = NULL;

    my_put_in_list(&list, 'c');
    my_print_list(list);
    cr_assert_stdout_eq_str("Letter: c - Freq: 1 - Is_alive: 1\n");
}

Test (get_nb_node_in_list, get_number_of_node_in_list)
{
    node_t *list = NULL;
    int nb;

    nb = 0;
    my_put_in_list(&list, 'c');
    my_put_in_list(&list, 'd');
    my_put_in_list(&list, 'e');
    nb = get_nb_node_in_list(list);
    cr_assert_eq(nb, 3);
}

Test (my_put_in_binary_tree, put_new_node_in_binary_tree)
{
    node_t *tree = NULL;
    node_t *list = NULL;

    my_put_in_list(&list, 'c');
    my_put_in_list(&list, 'd');
    my_put_in_binary_tree(&tree, list, list->next);
}

Test (read_file, read_file_with_wrong_pathname)
{
    int fd = -1;
    char *str;

    str = read_file(fd, "tee");
}

Test (delete_node, delete_node_in_list)
{
    node_t *list = NULL;

    my_put_in_list(&list, 'c');
    my_put_in_list(&list, 'd');
    delete_node(&list, list->next->c);
}

Test (delete_node, delete_node_in_list_with_first_node_to_delete)
{
    node_t *list = NULL;

    my_put_in_list(&list, 'c');
    delete_node(&list, list->c);
}

Test (free_list, free_linked_list)
{
    node_t *list = NULL;
    my_put_in_list(&list, 'c');
    my_put_in_list(&list, 'd');
    my_put_in_list(&list, 'e');
    free_list(list);
}

Test (delete_first_node, delete_the_first_node_of_a_list)
{
    node_t *list = NULL;

    my_put_in_list(&list, 'c');
    delete_first_node(&list);
}

Test (delete_first_node, delete_the_first_node_of_a_list_with_node_null)
{
    node_t *list = NULL;

    delete_first_node(&list);
}

Test (free_all, free_all_malloc)
{
    char *str = malloc(sizeof(char) * 8);
    node_t *node = NULL;

    my_put_in_list(&node, 'c');
    my_put_in_list(&node, 'e');
    my_put_in_list(&node, 'd');
    free_all(str, node);
}

Test (find_node, find_node_right_in_binary_tree)
{
    node_t *tree = NULL;
    node_t *list = NULL;
    char *tmp;

    my_put_in_list(&list, 'c');
    my_put_in_list(&list, 'd');
    my_put_in_binary_tree(&tree, list, list->next);
    tmp = my_find_node(tree, 'c');
}

Test (find_node, find_node_left_in_binary_tree)
{
    node_t *tree = NULL;
    node_t *list = NULL;
    char *tmp;

    my_put_in_list(&list, 'c');
    my_put_in_list(&list, 'd');
    my_put_in_binary_tree(&tree, list, list->next);
    tmp = my_find_node(tree, 'd');
}

Test (check_error, error_handling)
{
    char **av;

    av = malloc(sizeof(char *) * 2);
    av[0] = my_strdup("./antman");
    av[1] = my_strdup("tests/test_read_file");

    check_error(2, av);
}

Test (check_error, error_handling_bad_pathname)
{
    char **av;

    av = malloc(sizeof(char *) * 2);
    av[0] = my_strdup("./antman");
    av[1] = my_strdup("test_reile");

    check_error(2, av);
}

Test (check_error, error_handling_bad_ac)
{
    char **av;

    av = malloc(sizeof(char *) * 2);
    av[0] = my_strdup("./antman");
    av[1] = my_strdup("test_read_file");

    check_error(1, av);
}

Test (get_min_node, get_node_with_min_freq)
{
    node_t *list = NULL;
    node_t *tmp;

    my_put_in_list(&list, 'c');
    my_put_in_list(&list, 'd');
    tmp = get_min_node(&list);
    cr_assert_eq(tmp->freq, 1);
}
