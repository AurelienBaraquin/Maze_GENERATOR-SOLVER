/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** error_handling
*/

#include "my.h"

int search_char_in_str(char *str, char* c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != c[0] && str[i] != c[1])
            return 1;
    }
    return 0;
}

int error_handling_maze(char **maze)
{
    int len2 = strlen(maze[0]);
    for (int i = 0; maze[i]; i++) {
        if (strlen(maze[i]) != len2) {
            printf("Error: invalid maze\n");
            return 84;
        }
        if (search_char_in_str(maze[i], "*X") == 1) {
            printf("Error: invalid maze\n");
            return 84;
        }
    }
    return 0;
}

int error_handling_solver(int ac, char **av)
{
    if (ac != 2) {
        printf("Error: invalid number of arguments\n");
        return 84;
    }
    if (open(av[1], O_RDONLY) == -1) {
        printf("Error: file not found\n");
        return 84;
    }
    return 0;
}
