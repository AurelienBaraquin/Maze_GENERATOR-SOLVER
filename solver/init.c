/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** init
*/

#include "my.h"

char **get_maze(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat a;
    stat(filepath, &a);
    int size = a.st_size;
    char *buffer = malloc((size + 1) * sizeof(char));
    read(fd, buffer, size);
    buffer[size] = '\0';
    char **maze = my_strtok_array(buffer, "\n");
    return maze;
}

global_t *init_global(char *filepath)
{
    global_t *global = malloc(sizeof(global_t));
    global->maze = get_maze(filepath);
    global->height = my_arraylen(global->maze);
    global->width = strlen(global->maze[0]);
    global->maze_int = char_array_to_int_array
    (global->maze, global->height, global->width);
    global->nb = 1;
    return global;
}
