/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** win
*/

#include "my.h"

void print_win(global_t *gl)
{
    clear();
    int color = mlrand(1, 7);
    attr_on(COLOR_PAIR(color), NULL);
    mvprintw(gl->border->y / 2, gl->border->x / 2 - 5, "You win !");
    attr_off(COLOR_PAIR(color), NULL);
    mvprintw(gl->border->y / 2 + 1, gl->border->x / 2 - 5, "Press q to quit");
    mvprintw(gl->border->y / 2 + 2, gl->border->x / 2 - 5, "Press r to restart");
    refresh();
}

void event_win(global_t *gl, int key)
{
    if (key == 'q')
        gl->stop = TRUE;
    if (key == 'r') {
        gl->pos->x = 0;
        gl->pos->y = 0;
    }
}

int win(global_t *gl)
{
    if (gl->pos->x == gl->border->x - 1 && gl->pos->y == gl->border->y - 1) {
        event_win(gl, getch());
        print_win(gl);
        print_in_border(gl);
        return 1;
    }
    return 0;
}
