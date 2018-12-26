/*Computer Science 2211A
   Assignment 5
   Ositadinma Arimah
   250 981 235
   datatype.h
*/

#ifndef keydata_H
#define keydata_H
typedef int* Data;
typedef struct {char *skey1; char *skey2;} Key_struct;
typedef Key_struct* Key;
/* Use strcmp( ) to do comparison. If key1.key1 and key2.key1 are different, then they de- termine the comparison result. If key1.key1 and key2.key1 are the same, then key1.key2 and key2.key2 determine the comparison result.*/
int key_comp(Key k1, Key k2);

/* Allocate memory and return the subkey*/
char * string_dup(char *str);

/* Use the two subkeys to build a Key*/
Key key_gen(char *skey1, char* skey2);

/* Print the two subkeys in the key*/
void key_print(Key key);

/* Print the data*/
void data_print(Data data);

/* Assign data with idata.*/
void data_set(Data data, int idata);

/*Free memory allocated for data.*/
void data_free(Data data);

/*Generate a data with dynamic memory allocation.*/
Data data_gen(int idata);

/*Free memory allocated for key*/
void key_free(Key key);

#endif
