/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** to_imperfect
*/

#include "my.h"

int get_directions_imperfect(global_t *global, int y, int x)
{
    int direction[4] = {0, 0, 0, 0};
    int index = 0;
    if (y < global->height - 1)
        direction[index++] = 0;
    if (x < global->width - 1)
        direction[index++] = 1;
    if (index == 0)
        return -1;
    return direction[mlrand(0, index - 1)];
}

void create_path_maze(global_t *global)
{
    int x = 0;
    int y = 0;
    while (x != global->width - 1 || y != global->height - 1) {
        global->maze[y][x] = '*';
        int direction = get_directions_imperfect(global, y, x);
        if (direction == 0) {
            global->maze[y + 1][x] = '*';
            y += 1;
        }
        if (direction == 1) {
            global->maze[y][x + 1] = '*';
            x += 1;
        }
        global->maze[y][x] = '*';
    }
}

int to_imperfect(global_t *global)
{
    create_path_maze(global);
    int to_destroy = (global->height * global->width) / 2;
    int x = 0;
    int y = 0;
    while (to_destroy > 0) {
        x = mlrand(0, global->width - 1);
        y = mlrand(0, global->height - 1);
        if (global->maze[y][x] == 'X') {
            global->maze[y][x] = '*';
            to_destroy--;
        }
    }
    print_maze(global->maze);
    return 0;
}
