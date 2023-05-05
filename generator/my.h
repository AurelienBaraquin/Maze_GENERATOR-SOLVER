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

typedef struct elem_s {
    unsigned int x;
    unsigned int y;
    struct elem_s *next;
    struct elem_s *prev;
} elem_t;

typedef struct pile_s {
    elem_t *first;
    elem_t *last;
} pile_t;

typedef struct global_s {
    unsigned int height;
    unsigned int width;
    unsigned int is_perfect;
    char **maze;
    unsigned int path;
    pile_t *pile;
} global_t;

char **create_twod_array(int x, int y, char c);
int mlrand(int min, int max);
void create_paths(global_t *global);
void create_empty_maze(global_t *global);
int to_imperfect(global_t *global);
void print_maze(char **maze);
void extra_height(global_t *global);
void extra_width(global_t *global);
int verif_map_full_two(char **maze, int i);
int choose_directions(global_t *global, int direction, int x, int y);
void create_elem_at_end(int x, int y, pile_t *pile);
int specific_maze(global_t *global);

#endif /* !my_H */
