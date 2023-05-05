/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** event
*/

#include "my.h"

void event(global_t *gl, int key)
{
    //up = 259, down = 258, left = 260, right = 261
    if (key == 259 && gl->pos->y > 0 && gl->maze[gl->pos->y - 1][gl->pos->x] != 'X')
        gl->pos->y--;
    if (key == 258 && gl->pos->y < gl->border->y - 1 && gl->maze[gl->pos->y + 1][gl->pos->x] != 'X')
        gl->pos->y++;
    if (key == 260 && gl->pos->x > 0 && gl->maze[gl->pos->y][gl->pos->x - 1] != 'X')
        gl->pos->x--;
    if (key == 261 && gl->pos->x < gl->border->x - 1 && gl->maze[gl->pos->y][gl->pos->x + 1] != 'X')
        gl->pos->x++;
    if (key == 27)
        gl->stop = TRUE;
    if (key == 's')
        gl->stop = 2;
}