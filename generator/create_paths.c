/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-dante-aurelien.baraquin
** File description:
** create_paths
*/

#include "my.h"

int verif_is_map_full(char **maze)
{
    for (unsigned int i = 0; maze[i] != NULL; ++i) {
        if (verif_map_full_two(maze, i) == 0)
            return 0;
    }
    return 1;
}

void create_elem_at_end(int x, int y, pile_t *pile)
{
    elem_t *elem = malloc(sizeof(elem_t));
    elem_t *tmp = pile->first;
    elem->x = x;
    elem->y = y;
    elem->next = NULL;
    if (pile->first == NULL) {
        pile->first = elem;
        pile->last = elem;
        elem->prev = NULL;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
    pile->last = elem;
    elem->prev = tmp;
}

int get_directions(global_t *global)
{
    unsigned int direction[5] = {0, 0, 0, 0, 0};
    unsigned int index = 0;
    if (global->pile->last->y < global->height - 2 &&
    global->maze[global->pile->last->y + 2][global->pile->last->x] == '0')
        direction[index++] = 0;
    if (global->pile->last->x < global->width - 2 &&
    global->maze[global->pile->last->y][global->pile->last->x + 2] == '0')
        direction[index++] = 1;
    if (global->pile->last->y > 1 &&
    global->maze[global->pile->last->y - 2][global->pile->last->x] == '0')
        direction[index++] = 2;
    if (global->pile->last->x > 1 &&
    global->maze[global->pile->last->y][global->pile->last->x - 2] == '0')
        direction[index++] = 3;
    if (index == 0)
        return -1;
    return direction[mlrand(0, index - 1)];
}

int apply_direction(global_t *global, int direction)
{
    if (direction == -1) {
        global->pile->last = global->pile->last->prev;
        return 0;
    }
    if (direction == 0) {
        global->maze[global->pile->last->y + 1][global->pile->last->x] = '*';
        create_elem_at_end(global->pile->last->x,
        global->pile->last->y + 2, global->pile);
    }
    if (direction == 1 || direction == 2 || direction == 3)
        choose_directions(global, direction,
        global->pile->last->x, global->pile->last->y);
    return 1;
}

void create_paths(global_t *global)
{
    int direction = 0;
    create_elem_at_end(0, 0, global->pile);
    global->maze[global->pile->last->y][global->pile->last->x] = '*';
    while (global->path > 1) {
        if (apply_direction(global, get_directions(global)) == 1) {
            global->maze[global->pile->last->y][global->pile->last->x] = '*';
            global->path--;
        }
    }
}
