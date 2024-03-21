#include <stdio.h>
#include <stdlib.h>
#include "treeset.h"

// API just return a null root at this point
TreeSet TREESET_new() {
    return (TreeSet) { .root = NULL };
}


// helper recursive
// TODO maybe use pointer to pointer for shorter code
void inner_add(TreeSetNode* root, TreeSetNode* new_node) {

    int new_value = new_node->value;

    // set is a unique value container, do nothing if it presents.
    if (new_value == root->value) {
        printf("oops, same value\n");

        free(new_node); // nothing will be added, the new node wont be used
    }

    // if bigger than root then go left
    else if (new_value > root->value) {
        if (root->left == NULL) {
            printf("adding new node on the left\n");
            root->left = new_node;

        } else {

            // go recursively
            printf("going left\n");
            inner_add(root->left, new_node);
        }
    }

    // if smaller than root then go right
    else if (new_value < root->value) {
        if (root->right == NULL) {
            printf("adding new node on the right\n");
            root->right = new_node;

        } else {

            // go recursively
            printf("going right\n");
            inner_add(root->right, new_node);
        }
    }
}

// API, uses inner recursive method
void TREESET_add(TreeSet *treeset, int new_value) {

    // initialize new node
    TreeSetNode* nd = malloc(sizeof(TreeSetNode));
    nd->value = new_value;
    nd->right = NULL;
    nd->left = NULL;

    // if empty insert manually
    if (treeset->root == NULL) {
        printf("empty set, add root\n");
        treeset->root = nd;

    } else {
        inner_add(treeset->root, nd);
    }
}

// helper recursive
bool inner_contains(TreeSetNode* root, int value) {
    if (root == NULL) {
        printf("null node\n");
        return false;
    }

    else if (value > root->value) {
        printf("going left\n");
        return inner_contains(root->left, value);
    }
    else if (value < root->value) {
        printf("going right\n");
        return inner_contains(root->right, value);
    }

    // must equal
    printf("equals\n");
    return true;
}

// API
bool TREESET_contains(TreeSet* treeset, int value) {
    return inner_contains(treeset->root, value);
}

