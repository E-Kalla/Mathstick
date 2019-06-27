/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** check.c
*/

#include "../my.h"
#include <stdio.h>

int     isnum(char *str)
{
    int i = 0;

    while (i < my_strlen(str) - 1) {
        if (str[i] >= '0' && str[i] <= '9')
            i += 1;
        else
            return (1);
    }
    return (0);
}

int     check_lines(char *lines, int nb)
{
    int a = my_getnbr(lines);

    if (isnum(lines) != 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (a > nb || a == 0) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    if (my_strlen(lines) > 2)
        return (1);
    return (0);
}

int     check_match(char *match, int nb)
{
    int a = my_getnbr(match);

    if (isnum(match) != 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (a > nb) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(nb);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (a == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    return (0);
}