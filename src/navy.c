/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** navy
*/
#include "../include/navy.h"

int my_game1 (game_t *game)
{
    while (victory (game) == -1) {
        my_printf("\nmy_positions:");
        display_map (game->map);
        my_printf("\nenemy's positions:");
        display_map (game->map_enemy);
        int *coo = recup_input ();
        send_mess (game->pid, coo[0]);
        send_mess (game->pid, coo[1]);
        recup_shoot (game, coo);
        if (victory (game) != -1)
            break;
        my_printf ("\nwaiting for enemy's attack...\n");
        int coo2[2] = {recup_mess(), recup_mess()};
        send_shoot (game, coo2);
    }
    return 0;
}

int my_game2 (game_t *game)
{
    while (victory (game) == -1) {
        my_printf("\nmy_positions:");
        display_map (game->map);
        my_printf("\nenemy's positions:");
        display_map (game->map_enemy);
        my_printf ("\nwaiting for enemy's attack...\n");
        int coo2[2] = {recup_mess(), recup_mess()};
        send_shoot (game, coo2);
        if (victory (game) != -1)
            break;
        int *coo = recup_input ();
        send_mess (game->pid, coo[0]);
        send_mess (game->pid, coo[1]);
        recup_shoot (game, coo);
    }
    return 0;
}

int my_navy1(char **map)
{
    my_printf("my_pid:\t%d\nwaiting for enemy connection...\n", getpid());
    int pid = recup_pid ();
    my_printf ("\nenemy connected\n");
    char **map_enemy = empty_map (8);
    game_t *game = malloc (sizeof (game_t));
    game->map = map;
    game->map_enemy = map_enemy;
    game->pid = pid;
    game->winner = -1;
    my_game1 (game);
    int win = is_winner (game);
    free_game (game);
    return win;
}

int my_navy2(char **map, int pid)
{
    int my_pid = getpid();
    my_printf("my_pid:\t%d\n", my_pid);
    send_pid (pid, my_pid);
    my_printf ("successfully connected\n");
    char **map_enemy = empty_map (8);
    game_t *game = malloc (sizeof (game_t));
    game->map = map;
    game->map_enemy = map_enemy;
    game->pid = pid;
    game->winner = -1;
    my_game2 (game);
    int win = is_winner (game);
    free_game (game);
    return win;
}
