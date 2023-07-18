/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** signal_mess
*/
#include "../include/navy.h"

char *message;

void signal_handler (int sig)
{
    int i = 0;
    for (; message[i] != '2' && message[i] != '\0'; i++);
    if (sig == 10) {
        message[i] = '1';
    }
    if (sig == 12) {
        message[i] = '0';
    }
}

int end_pid (void)
{
    int res;
    for (int i = 0; message[i] != '\0'; i++) {
        res = 0;
        for (;message[i] == '0'; i++)
            res = res + 1;
        if (res >= 10)
            return 0;
    }
    return -1;
}

int recup_pid (void)
{
    message = malloc (sizeof(char) * 50);
    for (int i = 0; i < 50 - 1; i++)
        message[i] = '2';
    message[50 - 1] = '\0';
    while (end_pid () != 0)
        pause ();
    int nb = 0;
    for (int i = 0; message[i] != '2' && message[i] != '\0'; i++) {
        if (message[i] == '1')
            nb = nb + my_compute_power_rec (2, i);
    }
    free (message);
    return nb;
}

int recup_mess (void)
{
    message = malloc (sizeof(char) * 5);
    for (int i = 0; i < 4; i++)
        message[i] = '2';
    message[4] = '\0';
    for (int j = 0; j < 4; j++)
        pause ();
    int nb = 0;
    for (int k = 0; k < 4; k++) {
        if (message[k] == '1')
            nb = nb + my_compute_power_rec (2, k);
    }
    free (message);
    return nb;
}

void recup_shoot (game_t *game, int *coo)
{
    message = malloc (sizeof(char) * 2);
    message[0] = '2';
    message[1] = '\0';
    pause ();
    if (message[0] == '1') {
        game->map_enemy[coo[1]][coo[0]] = 'x';
        my_printf ("%c%c: hit\n", coo[0] + 65, coo[1] + 49);
    } else {
        if (game->map_enemy[coo[1]][coo[0]] == '.')
            game->map_enemy[coo[1]][coo[0]] = 'o';
        my_printf ("%c%c: missed\n", coo[0] + 65, coo[1] + 49);
    }
    free (coo);
    free (message);
}
