#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

void free_tree(node *root);
void print_tree(node *root);

int main(void) {


}


void print_tree(node *root) {
    if (root == NULL) 
        return;

    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

void free_tree(node *root) {
    if (root == NULL)
        return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
