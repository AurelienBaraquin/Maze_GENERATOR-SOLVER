/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** init_ncurses
*/

#include "my.h"

void init_colors(global_t *gl)
{
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_CYAN);
}

global_t* init_ncurses(char *str)
{
    global_t *gl = malloc(sizeof(global_t));
    gl->maze = my_strtok_array(str, "\n");
    gl->solved_maze = NULL;
    gl->border = malloc(sizeof(xy_t));
    gl->border->x = my_strlen(gl->maze[0]);
    gl->border->y = my_arraylen(gl->maze);
    gl->pos = malloc(sizeof(xy_t));
    gl->pos->x = 0;
    gl->pos->y = 0;
    gl->stop = 0;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);
    start_color();
    halfdelay(1);
    init_colors(gl);
    return gl;
}
