/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** print
*/

#include "my.h"

int resize(global_t *global)
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);
    if (x < global->border->x + 2 || y < global->border->y + 2)
        return 1;
    return 0;
}

void print_in_border(global_t *gl)
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);
    mvprintw(y - 1, x - 1, " ");

}

void print_resize(global_t *global)
{
    clear();
    attr_on(COLOR_PAIR(2), NULL);
    mvprintw(0, 0, "Please resize your terminal");
    mvprintw(1, 0, "Minimum Width: %d", global->border->x + 2);
    mvprintw(2, 0, "Minimum Height: %d", global->border->y + 2);
    attr_off(COLOR_PAIR(2), NULL);
    refresh();
}

void print_all(global_t *global)
{
    if (resize(global) == 1) {
        print_resize(global);
        return;
    }
    clear();
    attr_on(COLOR_PAIR(1), NULL);
    for (int x = 0; x != global->border->x + 2; x++)
        mvprintw(0, x, "#");
    for (int y = 0; y != global->border->y; y++) {
        mvprintw(y + 1, 0, "#");
        for (int x = 0; x != global->border->x; x++) {
            if (global->maze[y][x] == 'X')
                mvprintw(y + 1, x + 1, "X");
            else
                mvprintw(y + 1, x + 1, " ");
        }
        mvprintw(y + 1, global->border->x + 1, "#");
    }
    for (int x = 0; x != global->border->x + 2; x++)
        mvprintw(global->border->y + 1, x, "#");
    attr_off(COLOR_PAIR(1), NULL);
    attr_on(COLOR_PAIR(8), NULL);
    mvprintw(global->pos->y + 1, global->pos->x + 1, " ");
    attr_off(COLOR_PAIR(8), NULL);
    refresh();
}
