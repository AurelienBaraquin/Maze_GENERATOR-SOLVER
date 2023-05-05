/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return 84;
    global_t *gl = init_ncurses(get_file(av[1]));
    while (gl->stop != 1) {
        if (gl->stop == 2)
            solve_curse(gl);
        if (win(gl) == 1)
            continue;
        event(gl, getch());
        print_all(gl);
        print_in_border(gl);
    }
    endwin();
    return 0;
}
