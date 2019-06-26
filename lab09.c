/******************************************************************************
 * Assignment:  Lab 8
 * Lab Section: 11453
 * Description: This program takes in a number, converts it from base 10 to base 5 and counts the 4s in the number in each iteration
 * Programmers: Dante Sanaei dsanaei@purdue.edu
 *              Marcus Miller mill1867@purdue.edu
 *              Dylan Kerr kerr32@purdue.edu
 ******************************************************************************/

#include <stdio.h>
#include <math.h>
void inputs(int *number, int *base);
int count4(int number , int base);
int convertFromTen(int number, int base, int count, int base4);
int convertToTen(int number,int base);
void outputs(int number, int base, int fours);
int main()
{
  //Initializations
  int number;							// The number that is inputted
  int base;								// The base that is inputted
  int fours;							// How many fours there are

  //Inputs
  inputs(&number, &base);

  //Outputs
  fours = count4(number, base);
  outputs(convertToTen(number, base), base, fours);

  return 0;

}

/******************************************************************************
 * Function:    inputs()
 * Description: prompts user for inputs and stores them
 * Parameters:  number, int, and the number that is inputted
 *              base, int, and what base the number is
 *              
 * Return:      nothing
 ******************************************************************************/

void inputs(int *number, int *base)
{
  do
  {
    printf("Enter a number -> ");
    scanf("%d", number);
    if(*number < 0)				//if the number is negative
      printf("\nError: Non-negative values only!!\n\n");
  }while(*number < 0);

  do
  {
    printf("Enter the base of the number -> ");
    scanf("%d", base);
    if(*base < 5 || *base > 10)			//if the base is out of range
      printf("\nError: Please enter a base in the range [5, 10]\n\n");
  }while(*base < 5 || *base > 10);

  return;

}

/******************************************************************************
 * Function:    count4()
 * Description: counts how many fours are in a supplied number
 * Parameters:  number, int, and the number that is inputted
 *              base, int, and what base the number is
 *              
 * Return:      how many fours are in a number
 ******************************************************************************/

int count4(int number, int base)
{
  int fours;				//how many fours are in the number
  int lastdig;			//last digit of the number
  int testNumber;		//test number is used to test how many fours there are
  fours = 0;
  testNumber = number;
  while (testNumber)
  {
    lastdig = testNumber % 10;
    testNumber /= 10;
    if (lastdig == 4)
    {
      fours++;
    }
  }
  printf("\nNumber of four digits in %d (Base-%d): %d\n", number, base, fours);
  return fours;

}

/******************************************************************************
 * Function:    convertFromTen()
 * Description: converts a number from base ten to another base
 * Parameters:  number, int, and the number that is inputted
 *              base, int, and what base the number is
 *						   count, int, how many times something has been printed
 *							 base4, int, base4 is the amount of fours the number has at its original base
 *              
 * Return:      retursn 1 if something is printed
 ******************************************************************************/

int convertFromTen(int number, int base, int count, int base4)
{
  int i;			//looping variable to find how many fours there are
  int j;			//looping variable to print the digits
  int values;		//how many values there should be
  int exponent;	//the exponential value that is updated
  int fours;			//how many fours there are
  int first;			//if it is first this will be 1
  int digit;			//the value of each digit
  int number1;		//number that is used for the next loop
  int print;			//if it will be printed this will be 1
  print = 0;
  number1 = number;
  first = 1;
  fours = 0;
  values = 0;
  exponent = pow(base, values);
  while (exponent < number)
  {
    values++;
    exponent = pow(base, values);
  }
  values -= 1;
  for (i = values; i >= 0; i--)
  {
    exponent = pow(base, i);
    digit = number / exponent;
    number %= exponent;
    if (digit == 4)
    {
      fours++;
    }
  }
  if (fours > base4)
  {
    if (count == 1)
    {
      printf("\nConversions with more fours:\n");
      printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
      printf("##      Number      Base     Fours\n");
    }
    print = 1;
    printf("%d:", count);
    for (j = values; j >= 0; j--)
    {
      exponent = pow(base, j);
      digit = number1 / exponent;
      number1 %= exponent;
      if (first)
      {
        printf("%*d", (13-values), digit);
        first = 0;
      }
      else
      {
        printf("%d", digit);
      }
    }
    printf("%7d%10d\n", base, fours);
  }
  return print;
}

/******************************************************************************
 * Function:    convertToTen()
 * Description: converts a non-base 10 number to base 10
 * Parameters:  number, int, and the number that is inputted
 *              base, int, and what base the number is
 *              
 * Return:      the new base ten number
 ******************************************************************************/

int convertToTen(int number,int base)
{
  int total;				//this is the total value of the new digit
  int lastDig;			//this is the last digit of the original number
  int expValue;			//this is the exponential value
  expValue = 0;
  total = 0;
  while (number)
  {
    lastDig = number % 10;
    total += lastDig * pow(base, expValue);
    expValue++;
    number /= 10;
  }
  return total;

}

/******************************************************************************
 * Function:    outputs()
 * Description: converts a non-base 10 number to base 10
 * Parameters:  number, int, and the number that is inputted
 *              base, int, and what base the number is
 *              fours, int, and the number of 4s in the number
 *
 * Return:      Nothing
 ******************************************************************************/

void outputs(int number, int base, int fours)
{
  int i;			// looping variable for the loop 
  int count;	//counts how many have been printed
  count = 1;
  for(i = 10; i > 4; i--)
  {
    count += convertFromTen(number, i, count, fours);
  }
  if (count == 1)
  {
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("No conversions have more 4 digits.\n");
  }
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return;

}