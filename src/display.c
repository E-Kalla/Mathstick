/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** display
*/

#include "../my.h"

void    display_playermove(int lines, int match)
{
    my_putstr("Player removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(lines);
    my_putchar('\n');
}

void    display_iamove(int lines, int match)
{
    my_putstr("\nAI's turn...\nAI removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(lines);
    my_putchar('\n');
}

void    display(char **map)
{
    for (int i = 0; map[i] ; i += 1) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}