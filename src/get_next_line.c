/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i += 1;
    }
    return (i);
}

char *myrealloc(char *str, int more)
{
    char *newline;
    int i = 0;
    int lenght = my_strlen(str);

    if ((newline = malloc(sizeof(char) * lenght + more)) == NULL)
        return (NULL);
    while (i < more) {
        newline[i] = str[i];
        i += 1;
    }
    newline[i] = '\0';
    free(str);
    return (newline);
}

char *get_next_line(int fd)
{
    char buff[READ_SIZE + 1];
    int ret;
    int j = READ_SIZE;
    char *line;
    int i = 0;

    if (j != 1)
        j = 1;
    if ((line = malloc(sizeof(char) * j + 1 )) == NULL)
        return (NULL);
    while ((ret = read(fd, buff, j)) != 0 && ret != -1) {
        if (buff[0] != '\n') {
            line[i] = buff[0];
            i += 1;
            line = myrealloc(line,i);
        }
        if (buff[0] == '\n' || buff[0] == '\0')
            return (line);
    }
    return (NULL);
}