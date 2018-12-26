/*
 *    Computer Science 2211A
 *       Assignment 5
 *          Ositadinma Arimah
 *             250 981 235
 *                datatype.c
 *                */

#include "datatype.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int key_comp(Key k1, Key k2)
{
    int result = strcmp(k1->skey1, k2->skey1);
    if(result > 0) {
        return 1;
    } else if(result < 0) {
        return -1;
    } else {
        int result2 = strcmp(k1->skey2, k2->skey2);
        if(result2 > 0) {
            return 1;
        } else if(result2 < 0) {
            return -1;
        }
        return 0;
    }
}

/*Allocate memory and return the subkey*/
char * string_dup(char *str) {
    char *strp;
    char *p;
    int length = 0;
    /*Continue looping and incrementing legnth counter until end of string is reached*/ 
    while (str[length]) {
        length++;
    }
    strp = malloc(length + 1);
    p = strp;
    /*Copy string over to p*/
    while (*str) {
        *p++ = *str++;
    }
    /*Add terminating key to p*/ 
    *p = '\0';
    return strp;
}

/*Use the two sub keys to build a Key*/
Key key_gen(char *skey1, char* skey2)
{
        Key key;
        key=(Key )malloc(sizeof(Key));
        key->skey1 = strdup(skey1);
        key->skey2 = strdup(skey2);
        return key;
    }


/* Print the two sub keys in the key*/
 void key_print(Key key)
{
    printf("%-25s %-25s", key->skey1, key->skey2);
}

/*Print the data*/
void data_print(Data data)
{
    printf("%-25d\n",*data);
}

/*Assign data with idata.*/
void data_set(Data data, int idata){
    *data = idata;
}
/*Free memory allocated for data.*/
void data_free(Data data){
    free(data);
}

/*Generate a data with dynamic memory allocation.*/
Data data_gen(int idata){
    Data new_data = (int*)malloc(sizeof(int));
    *new_data = idata;
    return new_data;

}
/*Free memory allocated for key*/
void key_free(Key key){
    free(key->skey1);
    free(key->skey2);
    free(key);
}



