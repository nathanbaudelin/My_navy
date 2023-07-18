/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** fonctions_utiles
*/
#include "../include/navy.h"

int	my_getnbr(char const *str)
{
    int	nb = 0;
    int	isneg = 1;
    int	i = 0;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') isneg = isneg * - 1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        } else
        return (nb * isneg);
    }
    return (nb * isneg);
}

void free_game (game_t *game)
{
    free_map (game->map);
    free_map (game->map_enemy);
    free (game);
}

void free_map (char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free (map[i]);
    free (map);
}

void spaces (int *space)
{
    if (*space != 0) {
        my_printf (" ");
    }
    *space = 1;
}
