/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** main
*/
#include "../include/navy.h"

void print_h(void)
{
    my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player.");
    my_printf(" pid of the first player.\n\tnavy_positions: ");
    my_printf("file representing the positions of the ships.\n");
}

int error (int ac, char **av, int *h)
{
    if (ac != 2 && ac != 3) {
        write (1, "Bad number of arguments !\n", 26);
        return -1;
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_h();
        *h = 1;
        return 0;
    }
    return 0;
}

int main(int ac, char **av)
{
    int h = 0;
    int win = 0;
    if (error (ac, av, &h) == -1)
        return 84;
    init_signal ();
    char **map;
    if (ac == 2 && h == 0) {
        map = create_map (av[1]);
        if (map == NULL || verif_map (map) == -1)
            return (84);
        win = my_navy1 (map);
    }
    if (ac == 3) {
        map = create_map (av[2]);
        if (map == NULL || verif_map (map) == -1)
            return (84);
        win = my_navy2 (map, my_getnbr(av[1]));
    }
    return win;
}
