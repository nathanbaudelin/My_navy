/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** boat
*/
#include "../include/navy.h"

int *verif_info (int *info)
{
    int size = 0;
    if (info[1] == info[3] && info[1] >= 'A' && info[1] <= 'H') {
        if (info[2] >= '1' && info[2] <= '8' &&
            info[4] >= '1' && info[4] <= '8')
            size = info[4] - info[2];
        info[5] = 1;
    }
    if (info[2] == info[4] && info[2] >= '1' && info[2] <= '8') {
        if (info[1] >= 'A' && info[1] <= 'H' &&
            info[3] >= 'A' && info[3] <= 'H')
            size = info[3] - info[1];
        info[5] = 2;
    }
    if ((size + 1) != info[0]) {
        write (2, "Bad coordinates !\n", 18);
        free (info);
        return (info = NULL);
    }
    return info;
}

int *verif_line (char *line)
{
    int *info = malloc (sizeof (int) * 6);
    int ind = 1;
    info[0] = my_getnbr (line);
    for (int i = 1; line[i] != '\0' && line[i] != '\n'; i++) {
        if (ind >= 5) {
            write (2, "Bad file !\n", 11);
            free (info);
            return (info = NULL);
        }
        if (line[i] != ':') {
            info[ind] = line[i];
            ind++;
        }
    }
    info[5] = 0;
    info = verif_info (info);
    return info;
}

int place_boat_d (int *info, char **map)
{
    int i = info[2] - 49;
    int j = info[1] - 65;
    for (; j <= (info[3] - 65); j++) {
        if (map[i][j] != '.') {
            write (2, "Boats superposed !\n", 19);
            free (info);
            return -1;
        }
        map[i][j] = info[0] + 48;
    }
    return 0;
}

int place_boat_b (int *info, char **map)
{
    int i = info[2] - 49;
    int j = info[1] - 65;
    for (; i <= (info[4] - 49); i++) {
        if (map[i][j] != '.') {
            write (2, "Boats superposed !\n", 19);
            free (info);
            return -1;
        }
        map[i][j] = info[0] + 48;
    }
    return 0;
}

int add_boat (char *line, char **map)
{
    int *info = verif_line (line);
    if (info == NULL)
        return -1;
    if (info[5] == 1)
        if (place_boat_b (info, map) != 0)
            return -1;
    if (info[5] == 2)
        if (place_boat_d (info, map) != 0)
            return -1;
    free (info);
    return 0;
}
