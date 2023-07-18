/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-pierre.giordano
** File description:
** map
*/
#include "../include/navy.h"

void verif_char (int *count, char c)
{
    if (c == '2')
        count[0] = count[0] + 1;
    if (c == '3')
        count[1] = count[1] + 1;
    if (c == '4')
        count[2] = count[2] + 1;
    if (c == '5')
        count[3] = count[3] + 1;
}

int verif_map (char **map)
{
    int count[4] = {0, 0, 0, 0};
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            verif_char (count, map[i][j]);
    }
    if (count[0] != 2 || count[1] != 3 || count[2] != 4 || count[3] != 5) {
        free_map (map);
        write (2, "Bad number of boat !\n", 21);
        return -1;
    }
    return 0;
}

char **empty_map (int size)
{
    char **map = malloc (sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++) {
        map[i] = malloc (sizeof(char) * (size + 1));
        for (int j = 0; j < size; j++)
            map[i][j] = '.';
        map[i][size] = '\0';
    }
    map[size] = NULL;
    return map;
}

char **create_map2 (FILE *fp)
{
    int size = 50;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **map = empty_map (8);
    while ((read = getline (&line, &len, fp)) != -1) {
        if (add_boat (line, map) != 0 || line[0] != size) {
            free (line);
            free_map (map);
            return (map = NULL);
        }
        size++;
    }
    free (line);
    return map;
}

char **create_map (char *filepath)
{
    FILE *fp;
    if ((fp = fopen (filepath, "r")) == NULL) {
        write (2, "No such file !\n", 15);
        return (NULL);
    }
    char **map = create_map2 (fp);
    fclose (fp);
    return map;
}
