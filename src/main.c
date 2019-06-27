/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** main.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     game_loop(char **map, t_game *game)
{
    while (1) {
        game->win = player(map,game->match,game->len);
        if (game->win == 0) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        if (game->win == 84) {
            my_putchar('\n');
            return (0);
        }
        game->win = ia_turn(map,game->match,game->len);
        if (game->win == 0) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}

int     main(int ac, char **av)
{
    char **map;
    t_game *game;

    if (error_management(ac,av) == 84)
        return (84);
    game->len = my_getnbr(av[1]);
    game->match = my_getnbr(av[2]);
    game->win = 100;
    map = prepare_map(my_getnbr(av[1]));
    display(map);
    return (game_loop(map,game));
}