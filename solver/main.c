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
        if (i != height - 1)
            printf("\n");
    }
}

void replace_zero_by_x(global_t *glo)
{
    for (int i = 0; i < glo->height; i++) {
        for (int j = 0; j < glo->width; j++) {
            place_zeros(glo, i, j);
        }
    }
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return 84;
    global_t *glo = init_global(av[1]);
    if (error_handling_maze(glo->maze) == 84)
        return 84;
    fill_maze_int(glo, 0, 0);
    replace_zero_by_x(glo);
    get_fastest_path(glo);
    print_maze(glo->maze, glo->height, glo->width);
    return 0;
}
