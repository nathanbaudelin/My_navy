/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** navy
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "my_printf.h"

#ifndef NAVY_H_
    #define NAVY_H_

    typedef struct init_game {
        char **map;
        char **map_enemy;
        int pid;
        int winner;
    } game_t;

    int my_navy1(char **map);
    int my_navy2(char **map, int pid);
    int my_game1 (game_t *game);
    int my_game2 (game_t *game);

    int *verif_info (int *info);
    int *verif_line (char *line);
    int add_boat (char *line, char **map);
    int place_boat_d (int *info, char **map);
    int place_boat_b (int *info, char **map);

    char **create_map (char *filepath);
    char **create_map2 (FILE *fp);
    char **empty_map (int size);
    int verif_map (char **map);
    void verif_char (int *count, char c);

    void display_map (char **map);
    void display_map2 (char **map);

    int init_signal (void);
    void send_pid (pid_t pid, int mess);
    void send_mess (pid_t pid, int mess);
    void send_shoot (game_t *game, int *coo);

    int recup_pid (void);
    int end_pid (void);
    void signal_handler (int sig);
    int recup_mess (void);
    void recup_shoot (game_t *game, int *coo);

    int *recup_input (void);
    char *my_read (int *ind);
    int check_input (char *input, int ind);

    int victory (game_t *game);
    void count_cross (char cp, char ce, int *p_hit, int *e_hit);
    int is_winner (game_t *game);

    int	my_getnbr(char const *str);
    void free_game (game_t *game);
    void free_map (char **map);
    void spaces (int *space);

#endif /* !NAVY_H_ */
