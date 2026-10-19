#include <stdlib.h>
#include <stdio.h>
#define SIZE 255


typedef struct node {
    int candy;
    struct node *left, *right;
} node;


typedef struct stack {
    node *values[SIZE];
    int highest_used;
} stack;


node *new_house(int candy) {
    node *house = malloc(sizeof(node));
    if (house == NULL) {
    fprintf(stderr, "malloc error\n");
    exit(1);
    }
    house->candy = candy;
    house->left = NULL;
    house->right = NULL;
    return house;
}

node *new_nonhouse(node *left, node *right) {
    node *nonhouse = malloc(sizeof(node));
    if (nonhouse == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    nonhouse->left = left;
    nonhouse->right = right;
    return nonhouse;
}

stack *new_stack(void) {
    stack *s = malloc(sizeof(stack));
    if (s == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    s->highest_used = -1;
    return s;
}


void push_stack(stack *s, node *value) {
    s->highest_used++;
    s->values[s->highest_used] = value;
}

node *pop_stack(stack *s) {
    node *ret = s->values[s->highest_used];
    s->highest_used--;
    return ret;
}

int is_empty_stack(stack *s) {
    return s->highest_used == -1;
}

int tree_candy(node *tree) {
    int total = 0;
    stack *s = new_stack();
    while (tree != NULL) {
        if (tree->left && tree->right) {
            push_stack(s, tree->left);
            tree = tree->right;
        } else {
            total = total + tree->candy;
            if (is_empty_stack(s))
                tree = NULL;
            else
                tree = pop_stack(s);
        }
    }
    return total;
}

int re_tree_candy(node *tree) {
    if (!tree->left && !tree->right)
        return tree->candy;
    return re_tree_candy(tree->left) + re_tree_candy(tree->right);
}

int tree_nodes(node *tree) {
    if (!tree->left && !tree->right)
        return 1;

    return 1 + tree_nodes(tree->left) + tree_nodes(tree->right);
}


int tree_leaves(node *tree) {
    if (!tree->left && !tree->right)
        return 1;

    return tree_leaves(tree->left) + tree_leaves(tree->right);
}


int tree_streets(node *tree) {
    if (!tree->left && !tree->right)
        return 0;
    return tree_streets(tree->left) + tree_streets(tree->right) + 4;
}

int max(int v1, int v2) {
    if (v1 > v2)
        return v1;
    else
        return v2;
}

int tree_height(node *tree) {
    if (!tree->left && !tree->right)
        return 0;
    return 1 + max(tree_height(tree->right), tree_height(tree->right));
}

void tree_solve(node *tree) {
    int candy = tree_candy(tree);
    int height = tree_height(tree);
    int num_streets = tree_streets(tree) - height;
    printf("%d %d\n", num_streets, candy);
}

int main(void) {
    stack *s;
    s = new_stack();
    node *n, *n1, *n2, *n3, *na, *nb;
    n1 = new_house(20);
    n2 = new_house(30);
    n3 = new_house(10);
    push_stack(s, n1);
    push_stack(s, n2);
    push_stack(s, n3);
    while (!is_empty_stack(s)) {
        n = pop_stack(s);
        printf("%d\n", n->candy);
    }
    nb = new_nonhouse(n1, n2);
    na = new_nonhouse(n3, nb);
    tree_solve(na);
    return 0;
}
