/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** error_handling
*/

#include "my.h"

int error_handling(int ac, char **av)
{
    if (ac != 2) {
        printf("Error: invalid number of arguments -> do -h for help\n");
        return 84;
    }
    if (strcmp(av[1], "-h") == 0) {
        printf("\nUSAGE\n\t./ncurses_maze maze.txt\n\nDESCRIPTION\n\tmaze.txt\t-> File representing the maze to be solved.\n");
        printf("\t\t\tThe file must contain a rectangle maze, made of ‘X’ for walls and ‘*’ for paths.\n\t\t\tYou can move using directional arrows and quit with [ESCAPE].\n");
        printf("\t\t\tPress [S] to auto-solve the maze.\n\n\n");
        return 84;
    }
    if (open(av[1], O_RDONLY) == -1) {
        printf("Error: invalid file\n");
        return 84;
    }
    return 0;
}
