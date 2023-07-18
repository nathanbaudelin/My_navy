/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** signal
*/
#include "../include/navy.h"

int init_signal (void)
{
    struct sigaction sa;
    sigemptyset (&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = signal_handler;
    sigaction (10, &sa, NULL);
    sigaction (12, &sa, NULL);
    return 0;
}

void send_pid (pid_t pid, int mess)
{
    while (mess != 0) {
        if ((mess % 2) == 0) {
            kill (pid, 12);
        } else {
            kill (pid, 10);
        }
        mess = mess / 2;
        usleep (300);
    }
    for (int i = 0; i < 10; i++) {
        kill (pid, 12);
        usleep (300);
    }
}

void send_mess (pid_t pid, int mess)
{
    for (int i = 0; i < 4; i++) {
        if ((mess % 2) == 0) {
            kill (pid, 12);
        } else {
            kill (pid, 10);
        }
        if (mess != 0)
            mess = mess / 2;
        usleep (300);
    }
}

void send_shoot (game_t *game, int *coo)
{
    usleep (1000);
    if (game->map[coo[1]][coo[0]] >= '2' && game->map[coo[1]][coo[0]] <= '5') {
        game->map[coo[1]][coo[0]] = 'x';
        my_printf ("%c%c: hit\n", coo[0] + 65, coo[1] + 49);
        kill (game->pid, 10);
        usleep (300);
    } else {
        if (game->map[coo[1]][coo[0]] == '.')
            game->map[coo[1]][coo[0]] = 'o';
        my_printf ("%c%c: missed\n", coo[0] + 65, coo[1] + 49);
        kill (game->pid, 12);
        usleep (300);
    }
}
