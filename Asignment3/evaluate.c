#include <stdio.h>
#include <stdlib.h>



float m_exp (float sub_exp, char op);	//Initiaize all the functions
float get_num ();
char get_op ();
float s_exp (float sub_exp, char op);


float				// get_num is a function that returns a number in the expression
get_num ()
{
  float number;
  scanf ("%f", &number);
  return number;
}

char
get_op ()			// get_op is a function that returns an operator in the expression
{
  char op;
  scanf ("%c", &op);
  while (op == ' ')
    {
      scanf ("%c", &op);
    }
  return op;
}

float
s_exp (float sub_exp, char op)
{
  float sub_exp_two;		//the next number is the expression
  char op_two;			//the next operator is the expression
  if (op == '*' || op == '/' || op == '\n')	//if multiplication or division then call m_exp recursively
    {
      sub_exp_two = m_exp (sub_exp, op);	// set the next number as the result
      op_two = get_op ();	// get the next operator
      if (op_two != '\n')	// if its not is an empty line
	return s_exp (sub_exp_two, op_two);	// return the formula recursively
      else
	return sub_exp_two;	// return the next number

    }
  else
    {
      float sub_exp_one = get_num ();	// get the next number in expression
      char op_one = get_op ();	// set the next operator in expression
      sub_exp_two = m_exp (sub_exp_one, op_one);
      op_two = get_op ();	// get the next operator
      if (op == '+')		// if it is a plus
	return s_exp (sub_exp + sub_exp_two, op_two);	// add the two numbers
      else
	return s_exp (sub_exp - sub_exp_two, op_two);	//else (which is minus) subtract the two numbers
    }
}

float
m_exp (float sub_exp, char op)	// multiplication expression
{
  float sub_exp_two;
  char op_two;
  if (op == '+' || op == '-' || op == '\n')
    {
      ungetc (op, stdin);	//The ungetc() function takes a single character and shoves it back onto an input stream. Do this wih the operator
      return sub_exp;		// return the number is it is plus or minus
    }
  else
    {
      sub_exp_two = get_num ();	// get the next number
      op_two = get_op ();	// get the next operator
      if (op == '*')
	return m_exp (sub_exp * sub_exp_two, op_two);	// if multiplication then multiply the two numbers
      else
	return m_exp (sub_exp / sub_exp_two, op_two);	// else (which is division) divide the two numbers
    }

}

int
main ()
{
  char choice;			// Initiaize choice
  do
    {
      printf
	("Please enter a simple arithmetic expression to be evaluated: ");
      float f = get_num ();	// get the nume from expression
      char op = get_op ();	// get the operator from expression
      float answer = s_exp (f, op);	// calculate result and set it to answer
      printf ("\n Your answer is %f", answer);	// print the answer as a float



      printf
	("\n Enter Y to enter another arithmetic expression. Enter N to exit: ");
      scanf ("%c", &choice);	// ask for and scan the users choice

      while (choice != 'N' && choice != 'Y')
	{
	  printf ("Invalid input. Enter Y to continue. Enter N to quit: ");
	  scanf (" %c", &choice);	// if not N and Y then ask the user again

	}



    }
  while (choice == 'Y');	// restart the program if Y is entered.
}
