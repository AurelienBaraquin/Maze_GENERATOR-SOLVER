/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** char_array_to_int_array
*/

#include "my.h"

int get_nb_from_char(char c)
{
    if (c == 'X')
        return -1;
    else
        return 0;
}

int** char_array_to_int_array(char** charArray, int weight, int width)
{
    int** intArray = (int**)malloc(sizeof(int*) * weight);
    for (int i = 0; i < weight; i++) {
        intArray[i] = (int*)malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            intArray[i][j] = get_nb_from_char(charArray[i][j]);
        }
    }
    return intArray;
}
