/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** solve_curse
*/

#include "my.h"

void print_solve_maze(global_t *global)
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
            else if (global->maze[y][x] == '*')
                mvprintw(y + 1, x + 1, " ");
            else {
                attr_on(COLOR_PAIR(2), NULL);
                mvprintw(y + 1, x + 1, "o");
                attr_off(COLOR_PAIR(2), NULL);
            }
        }
        mvprintw(y + 1, global->border->x + 1, "#");
    }
    for (int x = 0; x != global->border->x + 2; x++)
        mvprintw(global->border->y + 1, x, "#");
    attr_off(COLOR_PAIR(1), NULL);
    print_in_border(global);
    refresh();
    usleep(10000);
}

char **array_copy(char **array, global_t *global)
{
    char **copy = malloc(sizeof(char *) * (global->border->y + 1));
    for (int i = 0; i < global->border->y; i++) {
        copy[i] = malloc(sizeof(char) * (global->border->x + 1));
        for (int j = 0; j < global->border->x; j++) {
            copy[i][j] = array[i][j];
        }
    }
    return copy;
}

void event_solve(global_t *global, int key)
{
    if (key == 27)
        global->stop = 1;
}

void solve_curse(global_t *global)
{
    global->solved_maze = solver_function(array_copy(global->maze, global));
    xy_t index = (xy_t){0, 0};
    while ((index.x != global->border->x - 1 || index.y != global->border->y - 1) && global->stop == 2) {
        event_solve(global, getch());
        if (resize(global) == 0) {
            global->solved_maze[index.y][index.x] = '*';
            global->maze[index.y][index.x] = 'o';
            if (global->solved_maze[index.y][index.x + 1] == 'o')
                index.x++;
            else if (global->solved_maze[index.y + 1][index.x] == 'o')
                index.y++;
            else if (global->solved_maze[index.y][index.x - 1] == 'o')
                index.x--;
            else if (global->solved_maze[index.y - 1][index.x] == 'o')
                index.y--;
        }
        print_solve_maze(global);
    }
    global->solved_maze[index.y][index.x] = '*';
    global->maze[index.y][index.x] = 'o';
    print_solve_maze(global);
    while (global->stop == 2)
        event_solve(global, getch());
}
