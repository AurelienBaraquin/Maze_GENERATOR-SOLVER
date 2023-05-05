/*
** EPITECH PROJECT, 2023
** dante
** File description:
** my
*/

#ifndef my_H
    #define my_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <curses.h>

typedef struct xy_s {
    int x;
    int y;
} xy_t;

typedef struct global_s {
    xy_t *border;
    xy_t *pos;
    char **maze;
    char **solved_maze;
    int stop;
} global_t;

char **my_strtok_array(char *str, char *delim);
int error_handling(int ac, char **av);
int my_arraylen(char **array);
int my_strlen(char *str);
global_t* init_ncurses(char *str);
char *get_file(char *filepath);
void event(global_t *gl, int key);
void print_all(global_t *global);
void print_in_border(global_t *gl);
int win(global_t *gl);
int mlrand(int min, int max);
char ** solver_function(char **av);
void solve_curse(global_t *global);
void print_resize(global_t *global);
int resize(global_t *global);

#endif /* !my_H */
