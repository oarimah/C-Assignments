#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void) {
    /* Iniialize variables for main.c*/
    char line[100];/* character arrays for line inputOne and inputTwo*/
    char inputOne[50];
    char inputTwo[50];
    

 /*Create a new matrix*/
    Matrix m = matrix_construction();

   /* Ask the user for the input*/
    puts("Enter in the following format: STRING[SPACE]STRING. Seperate by a space. Exit by entering new line");
    while (fgets(line, 100, stdin) != NULL) {
        if (line[0] == '\n') {/*If the first character of a line is null; break the new line*/
            break;
        } else if (sscanf(line, " %s %s", inputOne, inputTwo) != 2)/* striing scan the two user inputs*/ {
            puts("Incorrect Entry, Please Try Again :)");
        } else {
            int returnValue = matrix_isin(m, inputOne, inputTwo);
            printf("%d\n", returnValue);
            
            if (returnValue == 0) {
                 Value value = 1;
                matrix_set(m, inputOne, inputTwo, value);
            } else {
                /*Increment the value by 1,because of the occurences*/
                Value value = 1;
                matrix_inc(m, inputOne, inputTwo, value);
            }
        }
    }
    /* Print the titles for the output, formatted*/
    printf("%-25s %-25s %-25s \n", "String 1",   "String 2",   "Occurence");
    /* list contents of matrix*/
    matrix_list(m);
    /* Destroy the matrix*/
    matrix_destruction(m);
    return 0;
}

