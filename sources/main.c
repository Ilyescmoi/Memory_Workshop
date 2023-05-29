/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include "malloc.h"

void *my_malloc(size_t size)
{
    void *check_end_data = sbrk(0);

    if (check_end_data == (void*)-1) {
        return NULL;
    }
    check_end_data = sbrk(size);
    return check_end_data;
}

int main(int argc, char *argv[])
{
    size_t size = 10;
        void *malloc = my_malloc(size);

        if (malloc == NULL) {
            printf("erreur memoire\n");
        } else {
            printf("mémoire alloué %p\n", malloc);
        }


    return 0;
}
