#pragma once

typedef struct TreeSetNode {
    int value;

    struct TreeSetNode* left;
    struct TreeSetNode* right;
} TreeSetNode;

typedef struct {
    TreeSetNode* root;
} TreeSet;


/*
 * create a new treeset
 */
TreeSet TREESET_new();

/* 
 * add an element to the treeset
 */
void TREESET_add(TreeSet* treeset, int new_value);
