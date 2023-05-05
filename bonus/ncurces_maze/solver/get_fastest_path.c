/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** get_fastest_path
*/

#include "my.h"

int* get_directions_reverse(global_t *global, int x, int y)
{
    int *direction = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        direction[i] = -1;
    int index = 0;
    if (y < global->height - 1 && global->maze_int[y + 1][x] != -1)
        direction[index++] = 0;
    if (x < global->width - 1 && global->maze_int[y][x + 1] != -1)
        direction[index++] = 1;
    if (y > 0 && global->maze_int[y - 1][x] != -1)
        direction[index++] = 2;
    if (x > 0 && global->maze_int[y][x - 1] != -1)
        direction[index++] = 3;
    return direction;
}

int get_lowest_dir(global_t *global, int* all_dir, int x, int y)
{
    int nb = global->maze_int[y][x], lowest_dir = 0;
    for (int i = 0; all_dir[i] != -1; i++) {
        if (all_dir[i] == 0 && global->maze_int[y + 1][x] < nb) {
            nb = global->maze_int[y + 1][x];
            lowest_dir = 0;
        }
        if (all_dir[i] == 1 && global->maze_int[y][x + 1] < nb) {
            nb = global->maze_int[y][x + 1];
            lowest_dir = 1;
        }
        if (all_dir[i] == 2 && global->maze_int[y - 1][x] < nb) {
            nb = global->maze_int[y - 1][x];
            lowest_dir = 2;
        }
        if (all_dir[i] == 3 && global->maze_int[y][x - 1] < nb) {
            nb = global->maze_int[y][x - 1];
            lowest_dir = 3;
        }
    }
    return lowest_dir;
}

void apply_direction_reverse(global_t *global, int dir, index_t *p)
{
    if (dir == 0) {
        p->y += 1;
    }
    if (dir == 1) {
        p->x += 1;
    }
    if (dir == 2) {
        p->y -= 1;
    }
    if (dir == 3) {
        p->x -= 1;
    }
}

void get_fastest_path(global_t *global)
{
    index_t *p = malloc(sizeof(index_t));
    p->x = global->width - 1;
    p->y = global->height - 1;
    int* all_dir;
    int dir;
    while (p->x != 0 || p->y != 0) {
        global->maze[p->y][p->x] = 'o';
        all_dir = get_directions_reverse(global, p->x, p->y);
        dir = get_lowest_dir(global, all_dir, p->x, p->y);
        apply_direction_reverse(global, dir, p);
    }
    global->maze[0][0] = 'o';
}
