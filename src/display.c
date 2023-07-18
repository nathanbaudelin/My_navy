/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** display
*/
#include "../include/navy.h"

void display_map2 (char **map)
{
    int space;
    for (int i = 0; map[i] != NULL; i++) {
        my_printf("%d|", i + 1);
        space = 0;
        for (int j = 0; map[i][j] != '\0'; j++) {
            spaces (&space);
            my_printf("%c", map[i][j]);
        }
        my_printf("\n");
    }
}

void display_map (char **map)
{
    int space = 0;
    my_printf("\n |");
    for (int i = 0; map[i] != NULL; i++) {
        spaces (&space);
        my_printf("%c", i + 65);
    }
    my_printf("\n-+");
    for (int i = 0; map[i] != NULL; i++)
        my_printf("-");
    for (int i = 0; map[i + 1] != NULL; i++)
        my_printf("-");
    my_printf("\n");
    display_map2 (map);
}
