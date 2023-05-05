/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** strtok_array
*/

#include "my.h"

char **my_strtok_array(char *str, char *delim)
{
    char **array = malloc(sizeof(char *) * 100000);
    int i = 0;
    char *token = strtok(str, delim);
    while (token != NULL) {
        array[i++] = token;
        token = strtok(NULL, delim);
    }
    array[i] = NULL;
    return array;
}
