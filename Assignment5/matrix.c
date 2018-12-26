/*sitadinma Arimah
 * 250 981 235
 *  * CS2211 Assignment 5
 *   * The purpose of matrix.c is to hold the functions affecting objects of the Matrix type
 *    * The matrix structure will be implemented as a Matrix using BStree
 *     *
 *      */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/* The matrix_construction function is designed to create a new matrix using bstree_ini*/
Matrix matrix_construction(void){
    Matrix m =(Matrix) bstree_ini();
    return m;
}

/* Search through the inputted matrix looking for (index1, index2)*/
unsigned char matrix_isin(Matrix m, Index index1, Index index2){

    /* Create a new Key holding index1 and index2 which can be searched for*/
    Key searchKey = key_gen( index1, index2);

    /* Search through the matrix m looking for the searchKey, store the returned value as a Data type in the variable toFind*/
    Data toFind = (Data)bstree_search( m, searchKey);

    /* If (index1, index2) is in the matrix return 1, if not return 1*/
    if (toFind!= NULL){
        return 1;
    } else{
        return 0;
    }
}

/* matrix_get is a function that looks through a matrix for (index1, index2) and returns a pointer to the location if it exists, if it doesn't it returns null*/
Value *matrix_get(Matrix m, Index index1, Index index2){

    /* Create a new Key to search for using the inputted values*/
    Key searchKey = key_gen(index1, index2);

    /* Search for the new Key and return a pointer if it exists, if it doesn't return NULL*/
    return (Value*)bstree_search(m, searchKey);
}

/* The function matrix_set assigns the given Value to Matrix m at the location of the indexs'*/
void matrix_set(Matrix m, Index index1, Index index2, Value value){

        /* Create a new Key using index1 and index2*/
        Key newKey = key_gen(index1, index2);

        /* If the new Key is not in the matrix m insert the new Key and the value into m*/
        if (bstree_search(m, newKey) == NULL){
            Data toInsert = data_gen(value);
            bstree_insert(m, newKey, toInsert);
        } else{
            /* If the new Key is already in m, overwrite it with the new value */
            data_set((Data)matrix_get(m, index1, index2), value);
            
        }
    }


/* The function matrix_inc looks for the location of (index1, index2) and adds the inputted value to the value already there*/
void matrix_inc(Matrix m, Index index1, Index index2, Value value){

        /* Get the location of (index1, index2) in the matrix and store it in currData*/
        Value currData = *matrix_get(m, index1, index2);

        /* If the location exists add the given value to the current Value*/
        if (&currData != NULL){
            int newData = (int)currData + (int)value;
            
            matrix_set(m, index1, index2, newData);
            /* If the location is not in the matrix m, report an error */
        } else{
            exit(1);
        }
    }

/* The function matrix_list prints the matrix m using bstree_traversal*/
void matrix_list(Matrix m){
    bstree_traversal(m);
}

/* The function matrix_destruction frees the matrix m using bstree_free*/
void matrix_destruction(Matrix m){
    bstree_free(m);
}


