/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include "my.h"

void print_maze_int(int **maze, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf(" | %d", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_maze(char **maze, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void fill_with_zero(global_t *glo, int i)
{
    for (int j = 0; j < glo->width; j++) {
        if (glo->maze_int[i][j] == 0)
            glo->maze_int[i][j] = -1;
    }
}

void replace_zero_by_x(global_t *glo)
{
    for (int i = 0; i < glo->height; i++) {
        fill_with_zero(glo, i);
    }
}

char ** solver_function(char **av)
{
    global_t *glo = init_global(av);
    fill_maze_int(glo, 0, 0);
    replace_zero_by_x(glo);
    get_fastest_path(glo);
    return glo->maze;
}
