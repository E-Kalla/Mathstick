/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** error_management
*/

#include "../my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int     error_management(int ac, char **av)
{
    if (ac != 3) {
        write(2,"argument invalid\n",18);
        return (84);
    }
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100) {
        write(2,"invalid numbers of sticks\n",26);
        return (84);
    }
    if (my_getnbr(av[2]) <= 0)
        return (84);
    return (0);
}