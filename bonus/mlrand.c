/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlrand
*/

#include "my.h"

int mlrand(int min, int max)
{
    if (max - min < 0)
        return -1;
    static unsigned int state = 0;
    if (state == 0) {
        char *c;
        state = &c;
    }
    state = state * 1103515245 + 12345;
    unsigned int r = (state >> 16) & RAND_MAX;
    return min + r % (max - min + 1);
}
