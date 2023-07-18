/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** recup_input
*/
#include "../include/navy.h"

int check_input (char *input, int ind)
{
    if (input[0] >= 'A' && input[0] <= 'H' &&
        input[1] >= '1' && input[1] <= '8' && ind == 3)
        return 0;
    my_printf ("wrong position");
    return -1;
}

char *my_read (int *ind)
{
    char *input = malloc (sizeof(char) * 3);
    input[0] = '0';
    input[1] = '0';
    input[2] = '\0';
    char buffer[2] = "0";
    my_printf ("\nattack: ");
    while (buffer[0] != '\n') {
        read (0, buffer, 1);
        if (*ind < 2)
            input[*ind] = buffer[0];
        *ind = *ind + 1;
    }
    return input;
}

int *recup_input (void)
{
    int *res = malloc (sizeof(int) * 2);
    int ind = 0;
    char *input;
    int error = -1;
    while (error != 0) {
        input = my_read (&ind);
        error = check_input (input, ind);
        ind = 0;
    }
    res[0] = input[0] - 65;
    res[1] = input[1] - 49;
    free (input);
    return (res);
}
