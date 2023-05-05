/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** replace_zero
*/
#include "my.h"

void place_zeros(global_t *glo, int i, int j)
{
    if (glo->maze_int[i][j] == 0)
        glo->maze_int[i][j] = -1;
}
