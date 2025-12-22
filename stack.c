#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *value;
    int highest_used;
} stack;
