/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my.h
*/

#ifndef MY_H_
	#define MY_H_

typedef struct game_s {
    int len;
    int match;
    int win;
    } t_game;

int     check_match(char *match, int nb);
int     check_lines(char *lines, int nb);
int     my_getnbr(char  const *str);
int     my_putstr(char const *str);
void    my_putchar(char n);
int     my_strlen(char const *str);
int     error_management(int ac, char **av);
char**  prepare_map(int maxline);
void    display(char **map);
int     my_put_nbr(int nb);
int     my_strlen(char const *str);
void    display_playermove(int lines,int match);
int     modifplayer(char **map,int lines, int match, int loop);
int     modifia(char **map, int lines, int match);
void    display_iamove(int lines, int match);
int     player(char **map, int match, int len);
int     player_turn(char **map, int match, int len);
int     ia_turn(char **map, int match, int len);

#endif
