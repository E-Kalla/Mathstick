/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** modif
*/

#include "../my.h"

int     ispossible(char **map, int lines, int match)
{
    int nb = 0;
    int j = 1;

    while (map[lines][j+1] != '\0') {
        if (map[lines][j] == '|')
            nb += 1;
        j += 1;
    }
    if (nb < match) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int     ispossibleia(char **map, int lines, int match)
{
    int nb = 0;
    int j = 1;

    while (map[lines][j+1] != '\0') {
        if (map[lines][j] == '|')
            nb += 1;
        j += 1;
    }
    if (nb < match) {
        return (1);
    }
    return (0);
}

int     modifia(char **map, int lines, int match)
{
    int nb = 0;
    int j = my_strlen(map[lines]);

    if (ispossibleia(map,lines,match) != 0)
        return (10);
    while (nb < match) {
        if (map[lines][j] == '|') {
            map[lines][j] = ' ';
            nb += 1;
        }
        j -= 1;
    }
    return (0);
}

int     modifplayer(char **map, int lines, int match, int loop)
{
    int nb = 0;
    int j = my_strlen(map[lines]);

    if (loop == 5)
        return (1);
    if (ispossible(map,lines,match) != 0)
        return (1);
    while (nb < match) {
        if (map[lines][j] == '|') {
            map[lines][j] = ' ';
            nb += 1;
        }
        j -= 1;
    }
    display_playermove(lines,match);
    display(map);
    return (0);
}