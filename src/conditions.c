/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** conditions
*/
#include "../include/navy.h"

void count_cross (char cp, char ce, int *p_hit, int *e_hit)
{
    if (cp == 'x')
        *p_hit = *p_hit + 1;
    if (ce == 'x')
        *e_hit = *e_hit + 1;
}

int victory (game_t *game)
{
    int p_hit = 0;
    int e_hit = 0;
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int j = 0; game->map[i][j] != '\0'; j++)
            count_cross (game->map[i][j], game->map_enemy[i][j],
                        &p_hit, &e_hit);
    }
    if (p_hit == 14) {
        game->winner = 1;
        return 1;
    }
    if (e_hit == 14) {
        game->winner = 0;
        return 0;
    }
    return -1;
}

int is_winner (game_t *game)
{
    my_printf("\nmy_positions:");
    display_map (game->map);
    my_printf("\nenemy's positions:");
    display_map (game->map_enemy);
    if (game->winner == 0) {
        my_printf ("\nI won\n");
        return 0;
    } else {
        my_printf ("\nEnemy won\n");
        return 1;
    }
}
