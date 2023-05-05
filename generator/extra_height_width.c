/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** extra_height_width
*/

#include "my.h"

void extra_height(global_t *global)
{
    int y = global->height - 1;
    int x = 1;
    int random = 0;
    while (x != global->width - 2) {
        random = mlrand(0, 1);
        if (random == 0 && global->maze[y - 1][x] == '*' &&
        global->maze[y][x - 1] != '*') {
            global->maze[y][x] = '*';
        }
        x++;
    }
    if (global->height > 1) {
        global->maze[global->height - 2][global->width - 1] = '*';
        global->maze[global->height - 1][global->width - 1] = '*';
    }
}

void extra_width(global_t *global)
{
    int y = 1;
    int x = global->width - 1;
    int random = 0;
    while (y != global->height - 2) {
        random = mlrand(0, 1);
        if (random == 0 && global->maze[y][x - 1] == '*' &&
        global->maze[y - 1][x] != '*')
            global->maze[y][x] = '*';
        y++;
    }
    if (global->width > 1)
        global->maze[global->height - 1][global->width - 1] = '*';
}
