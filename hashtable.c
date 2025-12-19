#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Hash table node
typedef struct node {
    int key;
    int value;
    struct node* next;
} node;

// Hash table
node* hashTable[TABLE_SIZE];
