/*
** EPITECH PROJECT, 2021
** lib.h
** File description:
** libmy.a header
*/


#ifndef LIB_H_
    #define LIB_H_
    #include <stdarg.h>
/* Basic lib */
void my_putchar(char c);
int my_put_nbr(int nb);
char *my_strdup(char const *src);
int my_getnbr(char const *str);
int my_putstr(char const *str, int channel);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_putnbr_base(int nbr, char const *base);
char *my_strcat(char *s1, char *s2);
int check_error(int ac, char **av);
int get_size(char const *pathname);
char *read_file(int fd, char const *pathname);
char *int_to_base(unsigned int nb, int base);
int add_to_buffer(char *buffer, char const *str, int i,  int size);
int my_strcmp(char const *s1, char const *s2);
/* my_printf */
void my_printf(char *str, ...);
int handle_flags(va_list list, char *str, int i);
int get_opt_size(char *str, int i);
char *get_opt(char *str, int pos, int opt_size);
void int_exec_flags(int nbr, char *opt, char fid);
void str_fid(char *str, char *opt, char fid);
int int_fid(int nb, char *opt, char fid);
void uint_fid(unsigned int nb, char *opt, char fid);
void ulong_fid(unsigned long nb, char *opt, char fid);
int my_put_unbr(unsigned int nbr);
int my_putunbr_base(unsigned int nbr, char const *base);
int my_put_longnbr_base(unsigned long nbr, char const *base);

int upper_s_fid(char *str);
/* my_printf structure */
struct flags {
    int hashtag_flag;
    int less_flag;
    int zero_flag;
    int plus_flag;
};
#endif /* !LIB_H_ */
