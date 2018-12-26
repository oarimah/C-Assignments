/*Computer Science 2211A
   Assignment 5
   Ositadinma Arimah
   250 981 235
   matrix.h
*/

#ifndef matrix_H
#define matrix_H
#include "bstree.h"
typedef BStree Matrix;
typedef char* Index;
typedef int Value;

/*Matrix construction using bs tree ini();*/
Matrix matrix_construction(void);

/*If at location (index1, index2) in Matrix m, the value is defined, then return a pointer to the associated data. Otherwise, return NULL.*/
Value *matrix_get(Matrix m, Index index1, Index index2);
 
 /*Assign data to Matrix m at location (index1, index2). If that location already has data, then overwrite.*/
void matrix_set(Matrix m, Index index1, Index index2, Value value);

/*Print values in the Matrix m (with bs tree traversal()).*/
void matrix_list(Matrix m);

/*Free allocated space (with bs tree free()).*/
void matrix_destruction(Matrix m);

/*If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0*/
unsigned char matrix_isin(Matrix m, Index index1, Index index2);

/*If location (index1, index2) is defined in Matrix m, then increase the associated value by value. Otherwise, report error*/
void matrix_inc(Matrix m, Index index1, Index index2, Value value);

/*If location (index1, index2) is defined in Matrix m, then increase the associated value by
 * value.Otherwise, report error.*/
void matrix_inc(Matrix m, Index index1, Index index2, Value value);

#endif
