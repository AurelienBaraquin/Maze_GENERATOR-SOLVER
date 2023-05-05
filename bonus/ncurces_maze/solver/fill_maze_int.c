/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** fill_maze_int
*/

#include "my.h"

int* get_directions(global_t *global, int x, int y, int nb)
{
    int *direction = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        direction[i] = -1;
    int index = 0;
    if (y < global->height - 1 && global->maze_int[y + 1][x] == 0)
        direction[index++] = 0;
    if (x < global->width - 1 && global->maze_int[y][x + 1] == 0)
        direction[index++] = 1;
    if (y > 0 && global->maze_int[y - 1][x] == 0)
        direction[index++] = 2;
    if (x > 0 && global->maze_int[y][x - 1] == 0)
        direction[index++] = 3;
    return direction;
}

void apply_direction(global_t *global, int dir, int x, int y, int nb)
{
    if (dir == 0) {
        global->maze_int[y + 1][x] = nb;
    }
    if (dir == 1) {
        global->maze_int[y][x + 1] = nb;
    }
    if (dir == 2) {
        global->maze_int[y - 1][x] = nb;
    }
    if (dir == 3) {
        global->maze_int[y][x - 1] = nb;
    }
}

void finished_continue(global_t *global, int *dir, int x, int y)
{
    for (int i = 0; i < 5; i++) {
        apply_direction(global, dir[i], x, y, global->nb + 1);
    }
}

void continue_maze_int(global_t *global, int tmpx, int tmpy, int y)
{
    for (int x = 0; x < global->width - tmpx; x++) {
        if (global->maze_int[y][x] == global->nb) {
            int *dir = get_directions(global, x, y, global->nb);
            finished_continue(global, dir, x, y);
        }
    }
}

void fill_maze_int(global_t *global, int start_x, int start_y)
{
    int tmpx = global->width - 1;
    int tmpy = global->height - 1;
    global->maze_int[start_y][start_x] = global->nb;
    while (global->maze_int[global->height - 1][global->width - 1] == 0) {
        for (int y = 0; y < global->height - tmpy; y++) {
            continue_maze_int(global, tmpx, tmpy, y);
        }
        tmpx -= tmpx > 0 ? 1 : 0;
        tmpy -= tmpy > 0 ? 1 : 0;
        global->nb++;
    }
}
