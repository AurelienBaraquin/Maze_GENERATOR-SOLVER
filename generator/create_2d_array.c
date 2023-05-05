/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** create_twod_array
*/

#include <stdlib.h>

char **create_twod_array(int y, int x, char c)
{
    if (x <= 0 || y <= 0)
        return NULL;
    char **arr = malloc((y + 1) * sizeof(char *));
    for (int i = 0; i < y; i++) {
        arr[i] = malloc((x + 1) * sizeof(char));
        for (int j = 0; j < x; j++) {
            arr[i][j] = c;
        }
        arr[i][x] = '\0';
    }
    arr[y] = NULL;
    return arr;
}
