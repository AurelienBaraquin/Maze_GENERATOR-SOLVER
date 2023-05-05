/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int main(int ac, char **av)
{
    for (int i = 0; i < 1000; i++)
        printf("%d\n", mlrand(0, 100));
    return 0;
}
