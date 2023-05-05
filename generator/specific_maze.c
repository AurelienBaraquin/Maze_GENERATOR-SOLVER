/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** specific_maze
*/

#include "my.h"

int specific_maze_3(global_t *global)
{
    if (global->height == 2) {
        for (int i = 0; i < global->width; i++)
            global->maze[0][i] = '*';
        for (int i = 0; i < global->width - 1; i++)
            global->maze[1][i] = 'X';
        global->maze[1][global->width - 1] = '*';
        return 1;
    }
    return 0;
}

int specific_maze_2(global_t *global)
{
    if (global->width == 2 && global->height == 2) {
        global->maze[0][0] = '*';
        global->maze[0][1] = 'X';
        global->maze[1][0] = '*';
        global->maze[1][1] = '*';
        return 1;
    }
    if (global->width == 2) {
        for (int i = 0; i < global->height; i++)
            global->maze[i][0] = '*';
        for (int i = 0; i < global->height - 1; i++)
            global->maze[i][1] = 'X';
        global->maze[global->height - 1][1] = '*';
        return 1;
    }
    return specific_maze_3(global);
}

int specific_maze(global_t *global)
{
    if (global->width == 1 && global->height == 1) {
        global->maze[0][0] = '*';
        return 1;
    }
    if (global->width == 1) {
        for (int i = 0; i < global->height; i++)
            global->maze[i][0] = '*';
        return 1;
    }
    if (global->height == 1) {
        for (int i = 0; i < global->width; i++)
            global->maze[0][i] = '*';
        return 1;
    }
    return specific_maze_2(global);
}
