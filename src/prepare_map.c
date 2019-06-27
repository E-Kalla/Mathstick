/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** preparemap
*/

#include "../my.h"
#include <stdlib.h>
#include <stdio.h>

char **stickplace(char **map, int maxline)
{
    int i = maxline;
    int stick = maxline*2 -1;
    int space = 0;
    int j = 1;

    while (i >= 1) {
        while (j + space <= stick) {
            map[i][j] = '|';
            j += 1;
        }
        i -= 1;
        space += 1;
        j = 1 + space;    
    }    
    return (map);
}

char **square(char **map, int maxline)
{
    int i = 0;
    int j = 0;

    while (i < maxline + 2) {
        while (j < maxline*2 + 1) {
            if (j == 0 || j == maxline*2)
                map[i][j] = '*';
            else if (i == 0 || i == maxline + 1)
                map[i][j] = '*';
            else
                map[i][j] = ' ';
            j += 1;
        }
        map[i][j] = '\0';
        j = 0;
        i += 1;
    }
    return (map);
}

char **prepare_map(int maxline)
{
    int i = 0;
    char **stick;

    stick = malloc(sizeof(char *) * 100 + 2);
    while (i < maxline + 2) {
        stick[i] = malloc(sizeof(char) * 321);
        i += 1;
    }
    stick = square(stick,maxline);
    stick = stickplace(stick,maxline);
    return (stick);
}