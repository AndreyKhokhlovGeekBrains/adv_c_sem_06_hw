// Напишите программу, которая находит разницу между максимальным и минимальным элементом в дереве.
/*        
         10
/       /  \
/      5    15
/     / \   / \
     3   7 13  18
/   /   /
/  1   6
*/
// Данные на выходе: 17

#include <stdio.h>
#include <stdlib.h>

#define datatype int

typedef struct tree {
    datatype key;
    struct tree *left, *right, *parent;
} tree;

void addNode(tree **node, int value) {
    tree *newNode = (tree*)malloc(sizeof(tree));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    if (*node == NULL) {
        *node = newNode;
        return;
    }

    tree *current = *node;
    tree *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (value < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void findMinMax(tree *root, int *my_min, int *my_max) {
    if (root == NULL) return;

    if (*my_min > root->key) {
        *my_min = root->key;
    }

    if (*my_max < root->key) {
        *my_max = root->key;
    }

    findMinMax(root->left, my_min, my_max);
    findMinMax(root->right, my_min, my_max);
}

int findMinMaxDiff(tree *root) {
    if (root == NULL) return 0;

    int my_min = INT_MAX;
    int my_max = INT_MIN;

    findMinMax(root, &my_min, &my_max);

    return my_max - my_min;
}

void free_tree(tree *root) {
    if(root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}

int main (void) {
    tree *root = NULL;
    addNode(&root, 10);
    addNode(&root, 5);
    addNode(&root, 3);
    addNode(&root, 1);
    addNode(&root, 7);
    addNode(&root, 6);
    addNode(&root, 15);
    addNode(&root, 13);
    addNode(&root, 18);

    int diff = 0;
    diff = findMinMaxDiff(root);
    printf("%d", diff);
    free_tree(root);

    return 0;
}