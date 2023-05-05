/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** create_empty_maze
*/

#include "my.h"

void fill_map(global_t *global, int i, int j)
{
    if (i % 2 == 1 || j % 2 == 1)
        global->maze[i][j] = 'X';
    else
        global->path++;
}

void create_empty_maze(global_t *global)
{
    for (int i = 0; i < global->height; i++) {
        for (int j = 0; j < global->width; j++) {
            fill_map(global, i, j);
        }
    }
}

int verif_map_full_two(char **maze, int i)
{
    for (unsigned int j = 0; maze[i][j] != '\0'; ++j) {
        if (maze[i][j] == '0')
            return 0;
    }
    return 1;
}

int choose_directions(global_t *global, int direction, int x, int y)
{
    if (direction == 1) {
        global->maze[y][x + 1] = '*';
        create_elem_at_end(x + 2, y, global->pile);
    }
    if (direction == 2) {
        global->maze[y - 1][x] = '*';
        create_elem_at_end(x, y - 2, global->pile);
    }
    if (direction == 3) {
        global->maze[y][x - 1] = '*';
        create_elem_at_end(x - 2, y, global->pile);
    }
}
