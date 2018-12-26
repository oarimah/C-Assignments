#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/* Input: ’size’: size of an array
 *  Output: a pointer of type BStree, i.e. a pointer to an allocated memory of BStree_struct type
 *   Effect: dynamically allocate memory of type BStree_struct
 *    allocate memory for a Node array of size+1 for member tree_nodes
 *     allocate memory for an unsigned char array of size+1 for member is_free
 *      set all entries of is_free to 1
 *       set member size to ’size’;*/
BStree bstree_ini(int size)
{
    BStree bst;
    bst = (BStree_struct*)(malloc(sizeof(BStree_struct)));
    if(bst == NULL){
        printf("Error with memory allocation");
        exit(1);
    }
    bst->tree_nodes = (Node*)(malloc((size+1)*sizeof(Node)));
    if(bst->tree_nodes == NULL){
        printf("Error with memory allocation");
        exit(1);
    }
    bst->is_free = (unsigned char*)(malloc((size + 1) * sizeof(unsigned char)));
    if(bst->is_free == NULL){
        printf("Error with memory allocation");
        exit(1);
    }
    int i;
    for (i = 0; i<= size; i++){
        bst->is_free[i] = '1';
    }
    bst->size = size;
    return bst;
}
/* Input: ’bst’: a binary search tree
 *  ’key’: a pointer to Key
 *   ’data’: an integer
 *    Effect: ’data’ with ’key’ is inserted into ’bst’
 *     if ’key’ is already in ’bst’, do nothing*/

void bstree_insert(BStree bst, Key *key, int data) {
    bstree_insert_helper(bst, key, data, 1);
}

/* Input: 'bst', 'key', 'data', 'value': the value from strcmp, determines if , 'index': the current index of is_free & tree_nodes
 *  Effect: recursively search for an array for the first appropriate branch for the given key, using the strcmp value from bstree_insert*/
void bstree_insert_helper (BStree bst, Key *key, int data, int position){
    if (bst->is_free[position] == '1'){
        bst->tree_nodes[position].key = key;
        bst->tree_nodes[position].data = data;
        bst->is_free[position] = '0';
    } else {
        int compare = key_comp(*key, *bst->tree_nodes[position].key);
        if (compare < 0){
            int newPosi = 2*position;
            if (bst->is_free[newPosi] == '1'){
                bst->tree_nodes[newPosi].key = key;
                bst->tree_nodes[newPosi].data = data;
                bst->is_free[newPosi] = '0';
            } else {
                bstree_insert_helper(bst, key, data, newPosi);
            }
        } else if (compare> 0){
            int newPosi = 2*position+1;
            if (bst->is_free[newPosi] == '1'){
                bst->tree_nodes[newPosi].key = key;
                bst->tree_nodes[newPosi].data = data;
                bst->is_free[newPosi] = '0';
            } else {
                bstree_insert_helper(bst, key, data, newPosi);
            }
        } else {
            printf("Key already exists\n");
        }
    }
}


/* Input: ’bst’: a binary search tree
 *  Effect: print all the nodes in bst using in order traversal*/
void bstree_traversal(BStree bst)
{
    int position=1;
    traversal_recursion(bst, position);
}
void traversal_recursion(BStree bst, int position) {
    if (bst->is_free[position] == '0') /*if index is full*/
    {
        traversal_recursion(bst, leftNode(position)); /* traverse the left nodes*/
        print_node(bst->tree_nodes[position]); /* print the node */
        traversal_recursion(bst, rightNode(position)); /* traverse the right nodes */
    }

}
    /* Input: ’bst’: a binary search tree
 *      Effect: all memory used by bst are freed */
    void bstree_free(BStree bst){
        free(bst->tree_nodes);
        free(bst->is_free);
        free(bst);
    }
    /* Input: index of the node
 *      Effect: returns the index of the node left of position */
    int leftNode(int position) {
        return (position * 2);
    }


    /* Input: index of the node
 *     Effect: returns the index of the node right of position */
    int rightNode(int position) {
        return ((position * 2) + 1);
    }



