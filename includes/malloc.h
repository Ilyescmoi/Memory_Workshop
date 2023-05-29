/*
** EPITECH PROJECT, 2023
** Memory_Workshop
** File description:
** malloc
*/

#ifndef MALLOC_H_
    #define MALLOC_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct malloc_t {
    size_t size;
    int is_free;
    malloc_t *next;
} malloc_s;
#endif /* !MALLOC_H_ */
