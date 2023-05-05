/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include "my.h"

void print_maze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        write(1, maze[i], strlen(maze[i]));
        if (maze[i + 1] != NULL)
            write(1, "\n", 1);
    }
}

int gestion_error(int ac, char **av)
{
    if (ac != 3 && ac != 4)
        exit(84);
    if (atoi(av[1]) == 0 || atoi(av[2]) == 0)
        exit(84);
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        return 'p';
}

global_t *init_struct(unsigned int height, unsigned int width, int is_perfect)
{
    global_t *global = malloc(sizeof(global_t));
    global->height = width;
    global->width = height;
    if (is_perfect == 'p') {
        global->is_perfect = 1;
        global->maze = create_twod_array(global->height, global->width, '0');
    } else {
        global->is_perfect = 0;
        global->maze = create_twod_array(global->height, global->width, 'X');
    }
    global->pile = malloc(sizeof(pile_t));
    global->pile->first = NULL;
    global->pile->last = NULL;
    return global;
}

int main(int ac, char **av)
{
    int er = gestion_error(ac, av);
    global_t *global = init_struct(atoi(av[1]), atoi(av[2]), er);
    if (specific_maze(global) == 1) {
        print_maze(global->maze);
        return 0;
    }
    if (global->is_perfect == 0)
        return to_imperfect(global);
    create_empty_maze(global);
    create_paths(global);
    if (global->height % 2 == 0)
        extra_height(global);
    if (global->width % 2 == 0)
        extra_width(global);
    print_maze(global->maze);
}
