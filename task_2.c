// Напишите программу, которая возвращает сумму всех элементов в дереве.
/*        
         10
/       /  \
/      5    15
/     / \   / \
     3   7 13  18
/   /   /
/  1   6
*/
// Данные на выходе: 78


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

int findTreeSum(tree *root) {
    if(root == NULL) return 0;

    int left_sum = findTreeSum(root->left);
    int right_sum = findTreeSum(root->right);

    return root->key + left_sum + right_sum;
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

    int my_sum = 0;
    my_sum = findTreeSum(root);
    printf("%d", my_sum);
    free_tree(root);

    return 0;
}