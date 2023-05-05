/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** len
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int my_arraylen(char **array)
{
    int i = 0;
    while (array[i] != NULL)
        i++;
    return i;
}
