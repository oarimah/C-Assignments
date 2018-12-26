#include <stdio.h>
#include <string.h>

int
main ()
{

  int number[10];		//intialize an integer array
  char storeArr[10];		//initalize a charcter array used for storing
  char choice;			//initalize choice for the Y or N section
  const char segments[10][3][3] =
    { {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
  {{' ', ' ', ' '}, {' ', '|', ' '}, {' ', '|', ' '}}, {{' ', '_', ' '},
							{' ', '_', '|'}, {'|',
									  '_',
									  ' '}},
  {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}}, {{' ', ' ', ' '},
							{'|', '_', '|'}, {' ',
									  ' ',
									  '|'}},
  {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}}, {{' ', '|', ' '},
							{'|', '_', ' '}, {'|',
									  '_',
									  '|'}},
  {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, {{' ', '_', ' '},
							{'|', '_', '|'}, {'|',
									  '_',
									  '|'}},
  {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}
  };				// intialize the array used to store each number

  do
    {
      printf ("Enter an integer: ");
      scanf ("%s", &storeArr);	// ask for and scan the integer 

      for (int i = 0; i < strlen (storeArr); i++)	// for loop which increments i everytime it is less than the length of array
	number[i] = storeArr[i] - '0';

      for (int j = 0; j < strlen (storeArr); j++)
	{			// second for loop which loops and increments everytime it is less than the length of array

	  for (int x = 0; x < 3; x++)
	    {			//for loop for second postion within the number

	      for (int y = 0; y < 3; y++)
		{		// for loop for last postion withtin the numer
		  printf ("%c", segments[number[j]][x][y]);	// print the number entered

		}

	      printf ("\n");	// seperated by a new line

	    }
	}



      printf
	("\n Would you like to continue. Enter Y for yes. Enter N for quit: ");
      scanf (" %c", &choice);	// ask the user for the Input and scan that Input

      while (choice != 'N' && choice != 'Y')
	{
	  printf ("Invalid Input, please try again. Enter Y or N:  ");	// if the choice is neither N or Y then print the following
	  scanf (" %c", &choice);
	}
    }
  while (choice == 'Y');

}
