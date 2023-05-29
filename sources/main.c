/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include "malloc.h"
#include <string.h>

typedef struct Block {
    void* data;               
    size_t size;
    int freed;
    struct Block* next;      
} Block;

Block* firstBlock = NULL;

void* my_malloc(size_t size) {
    void* data = sbrk(0);
    data = sbrk(size);

    Block* block = (Block*)malloc(sizeof(Block));
    block->data = data;
    block->size = size;
    block->freed = 0;
    block->next = NULL;

    if (firstBlock == NULL) {
        firstBlock = block;
    } else {
        Block* currentBlock = firstBlock;
        while (currentBlock->next != NULL) {
            currentBlock = currentBlock->next;
        }
        currentBlock->next = block;
    }

    return data;
}

void my_free(void* data) {
    Block* currentBlock = firstBlock;
    while (currentBlock != NULL) {
        if (currentBlock->data == data) {
            currentBlock->freed = 1;
            break;
        }
        currentBlock = currentBlock->next;
    }
}

void printAllocatedBlocks() {
    Block* currentBlock = firstBlock;
    printf("Allocated Blocks:\n");
    while (currentBlock != NULL) {
        printf("Pointer: %p, Size: %lu, Freed: %s\n", currentBlock->data, currentBlock->size,
               currentBlock->freed ? "Yes" : "No");
        currentBlock = currentBlock->next;
    }
}

int main() {
    int* data1 = (int*)my_malloc(sizeof(int));
    *data1 = 10;

    char* data2 = (char*)my_malloc(sizeof(char) * 5);
    strcpy(data2, "Hello");

    float* data3 = (float*)my_malloc(sizeof(float));
    *data3 = 3.14;

    printAllocatedBlocks();

    my_free(data1);
    my_free(data2);
    my_free(data3);

    printAllocatedBlocks();

    return 0;
}
