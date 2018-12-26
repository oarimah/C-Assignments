#ifndef ASSIGNMENT4_BST_H
#define ASSIGNMENT4_BST_H


#include "data.h"
typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void traversal_recursion(BStree bst, int index);
int leftNode(int index);
int rightNode(int index);
void bstree_insert_helper (BStree bst, Key *key, int data, int index);
#endif //ASSIGNMENT4_BST_H
