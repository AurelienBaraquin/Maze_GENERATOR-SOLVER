/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** get_file
*/

#include "my.h"

char *get_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 10000000);
    int size = read(fd, buffer, 10000000);
    buffer[size] = '\0';
    return buffer;
}
