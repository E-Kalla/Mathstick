/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** play
*/

#include <stdio.h>
#include <stdlib.h>
#include "../my.h"

int     check_stick(char **map)
{
    int nb = 0;
    int i = 0;
    int j = 0;

    while (map[i]) {
        while (map[i][j] != '\0') {
            if (map[i][j] == '|')
                nb += 1;
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return (nb);
}

int     player(char **map, int match, int len)
{
    my_putstr("\nYour turn: \n");
    return (player_turn(map,match,len));
}

int     player_turn(char **map,int match, int len)
{
    char *lines = malloc(sizeof(char) * 100);
    char *matches = malloc(sizeof(char) * 100);
    int loop = 1;
    size_t lenght = 1500;

    while (loop != 0) {
        my_putstr("Line: ");
        if (getline(&lines,&lenght,stdin) == -1)
            return (84);
        loop = check_lines(lines,len);
    }
    my_putstr("Matches: ");
    if (getline(&matches,&lenght,stdin) == -1)
        return (84);
    if (check_match(matches,match) != 0)
        loop = 5;
    if (modifplayer(map,my_getnbr(lines),my_getnbr(matches),loop) == 1 || loop == 5)
        player_turn(map,match,len);
    return (check_stick(map));
}

int     ia_turn(char **map, int match, int len)
{
    int lines;
    int matches;

    lines = (random() % len) + 1;
    matches = (random() % match) + 1;
    if (modifia(map,lines,matches) == 0) {
        display_iamove(lines,matches);
        display(map);
    }
    else 
        ia_turn(map,match,len);
    return (check_stick(map));
}