/*
** EPITECH PROJECT, 2023
** dante
** File description:
** my
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef my_H
    #define my_H


typedef struct index_s {
    int x;
    int y;
} index_t;

typedef struct global_s {
    int width;
    int height;
    char **maze;
    int **maze_int;
    int nb;
} global_t;

char **my_strtok_array(char *str, char *delim);
int my_arraylen(char **array);
int error_handling_solver(int ac, char **av);
int error_handling_maze(char **maze);
global_t *init_global(char **maze);
int** char_array_to_int_array(char** charArray, int weight, int width);
int mlrand(int min, int max);
void fill_maze_int(global_t *global, int start_x, int start_y);
void get_fastest_path(global_t *global);
char ** solver_function(char **av);

#endif /* !my_H */
