/* Ositadinma Arimah
 *  * 250 981 235
 *   * CS2211a Assignment 5
 *    * The purpose of bstree.c is to hold the functions which can create, edit, insert, and
 *     * delete the various nodes of a binary tree.
 *      */

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"


/* The purpose of bstree_ini is to allocate memory for a new binary seach tree*/
BStree bstree_ini(void){

    /* Allocate the memory for a new BStree and set the value to null*/
    BStree bst = (BStree)malloc( sizeof( BStree_node* ) );
    *bst = NULL;

    /* Return a pointer to the newly created tree*/
    return bst;

}

/* The purpose of bstree_insert is to insert a Key and Data into an available node in the binary search tree given*/
void bstree_insert(BStree bst, Key key, Data data){

    /* Create a new node with the given Key and Data, store a pointer to the node in the variable target */
    BStree_node* node = new_node( key, data);

    /* If the inputted BStree is empty, make the bst point to the newly created node*/
    if (*bst == NULL){
        *bst = node;
        return;
    }

    /* The currnode variable holds the position of the current node*/
    BStree_node currNode = **bst;

    /* Compare the key of the root node to the inputted key*/
    int compare = key_comp( currNode.key, key);

    /* If the root.key is less than the inputted key check the left node*/
    if (compare > 0 ){

        /* If the left node of the parent is empty add the new node to that location*/
        if ( currNode.left == NULL){
            (**bst).left = node;
        } else {

            /* If the left node is not empty, run through bstree_insert again using the node to the left of the root*/
            bstree_insert( &currNode.left, key, data);
        }

        /* If the root.key is greater than the inputted key*/
    } else if(compare < 0){

        /* If the position to the right of the current position is empty add the inputted data to that position*/
        if ( currNode.right == NULL){
            (**bst).right = node;

        } else {

            /* If the position to the right is filled, run through bstree_insert again using the position to the right of the current position*/
            bstree_insert( &currNode.right, key, data);
        }

        /* If the key inputted is equal to the key at the current position do nothing*/
    } else if(compare == 0){
        return;
    }


}

/* Helper function for bstree_insert, it allocates memory for a node which holds a Key, Data, and a pointer to the left and right node*/
BStree_node *new_node(Key key, Data data){

    /* Allocate the memory to hold a new node then store a pointer to it in the variable newNode*/
    BStree_node* node=(BStree_node*)malloc( sizeof( BStree_node ) );

    /* Add the inputted Key and Data into the node, and set the location of the children nodes to NULL*/
    (*node).key = key;
    (*node).data = data;
    (*node).left = NULL;
    (*node).right = NULL;
    return node;
}

/* The function bstree_search looks through an inputted BStree and will return the data of an inputted Key (If the Key exists)*/
Data bstree_search(BStree bst, Key key){

    BStree_node* node = bstree_nodeSearch(*bst, key);
    if (node == NULL){
        return NULL;
    } else{
        Data findData = node->data;
        return findData;
    }
}

BStree_node *bstree_nodeSearch(BStree_node *node, Key key){
    if (node != NULL){
        int compare = key_comp(node->key, key);

        if (compare > 0){
            return bstree_nodeSearch(node->left, key);
        }

        if (compare < 0){
            return bstree_nodeSearch(node->right, key);
        }

        if (compare ==0){
            return node;
        }
    } 
    return NULL;
    
}


/* The function bstree_traversal runs through an inputted BStree and prints the Key and Data of each node*/
void bstree_traversal(BStree bst){

    /* If the tree is not NULL*/
    if (*bst != NULL){

        /* Set the position of the root node in the inputted tree to currNode*/
        BStree_node currNode = **bst;

        /* If the node to the left is not NULL*/
        if (currNode.left != NULL){

            /* Run through bstree_traversal going down the left node until there are not more left nodes*/
            bstree_traversal(&currNode.left);
        }

        /* Print the Key and the Data in the currNode*/
        key_print(currNode.key);
        data_print(currNode.data);

        /* If the node to the right is not NULL*/
        if (currNode.right != NULL){

            /* Run through bstree_traversal going down the right node until there are no more right nodes*/
            bstree_traversal(&currNode.right);
        }
    }
}

/* The function bstree_free is designed to free all the memory alloted to BStree*/
void bstree_free(BStree bst){

    /* While the tree is not NULL*/
    if (*bst != NULL){

        /* Run through and free node to the left and right of the current node then free the tree itself*/
        bstree_free(&(**bst).right);
        bstree_free(&(**bst).left);
        free(*bst);

        /* When the tree is NULL do nothing*/
    } else{
        return;
    }
}

