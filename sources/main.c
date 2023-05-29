/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *str = malloc(sizeof("Hello world!"));
    str = argv[1];
    printf("%s\n", str);
    free(str);
    return 0;
}
