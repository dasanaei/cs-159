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
#define SIZE 10
void inputs(long long numbers[], int *base);
int convertFromTen(long long number, int base);
int convertToTen(long long numbers[],int base);
void outputs(long long numbers[], int base, int bases[], int Fours[], int numbersOG[]);
int convertFromTenPrint(long long number, int base);
int count4(int number, int base)

int main()
{
  //Initializations
  long long numbers[SIZE];							// The number that is inputed
  int base;								              // The base that is inputed
  int bases[50];                      // array of bases that holds the bases with most 4s
  int Fours[50];                      // array of amount of 4s for each number
  int numbersOG[SIZE];

  //Inputs
  inputs(numbers, &base, numbersOG);
  //Outputs
  convertToTen(numbers, base);
  outputs(numbers, base, bases, Fours, numbersOG);

  return 0;

}

/******************************************************************************
 * Function:    inputs()
 * Description: prompts user for inputs and stores them
 * Parameters:  numbers[], long long, and the number array that is inputted
 *              base, int, and what base the number is
 *              
 * Return:      nothing
 ******************************************************************************/

void inputs(long long numbers[], int *base, int numbersOG[])
{

  int fail;               //if the number fails this is 1
  long long num;        // copy of inputed number
  long long number;         //copy of inputted number
  int i;                    // index variable for for loop
  int t;
  do
  {
    printf("Enter the base of the data set -> ");
    scanf("%d", base);
    if(*base < 2 || *base > 10)			//if the base is out of range
      printf("\nError: Please enter a base in the range [2, 10]\n\n");
  }while(*base < 2 || *base > 10);

  i = 0;
  do
  {

    fail = 0;

    printf("Enter value #%d -> ", i + 1);
    scanf("%llu", &number);
    num = number;
    while (num != 0)
    {
      if (num % 10 == *base)
      {
        fail = 1;
      }
      num /= 10;
    }

    if (fail)
    {
      printf("\nError! Invalid digit for base %d\n\n", *base);
    }
    else
    {
      numbers[i] = number;
      i++;
    }

  }while(i < 10 );
  
  for (t = 0; t < SIZE; t++)
  {
    numbersOG[t] = numbers[t];
  }
  return;

}

/******************************************************************************
 * Function:    convertFromTen()
 * Description: converts a number from base ten to another base
 * Parameters:  number, long long, and the number that is inputted
 *              base, int, and what base the number is
 *              
 * Return:      retursn the amount of fours
 ******************************************************************************/

int convertFromTen(long long number, int base)
{

  int i;			//looping variable to find how many fours there are
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
  return fours;

}

/******************************************************************************
 * Function:    convertFromTenPrint()
 * Description: converts a number from base ten to another base and prints
 * Parameters:  number, long long, and the number that is inputted
 *              base, int, and what base the number is
 *              
 * Return:      None
 ******************************************************************************/

int convertFromTenPrint(long long number, int base)
{

  int i;      //looping variable to find how many fours there are
  int values;   //how many values there should be
  int exponent; //the exponential value that is updated
  int fours;      //how many fours there are
  int first;      //if it is first this will be 1
  int digit;      //the value of each digit
  long long number1;    //number that is used for the next loop
  int print;      //if it will be printed this will be 1
  int totalNum;
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
    if (first)
    {
      totalNum = digit;
      first = 0;
    }
    else
    {
      totalNum = totalNum * pow(10, (int)log10(digit)+1) + digit;
    }
  }

  return totalnum;

}
/******************************************************************************
 * Function:    convertToTen()
 * Description: converts a non-base 10 number to base 10
 * Parameters:  numbers[], long long, and the number array that is inputted
 *              base, int, and what base the number is
 *              
 * Return:      the new base ten number
 ******************************************************************************/

int convertToTen(long long numbers[],int base)
{

  long long total;				//this is the total value of the new digit
  int lastDig;			//this is the last digit of the original number
  int expValue;			//this is the exponential value
  int i;            //index variable for loop
  long long number; //copy of number being evaluated
  expValue = 0;
  total = 0;
  for(i = 0; i < SIZE; i++)
  {
    number = numbers[i];
    expValue = 0;
    total = 0;
    while (number)
    {
      lastDig = number % 10;
      total += lastDig * pow(base, expValue);
      expValue++;
      number /= 10;
    }
    numbers[i] = total;
  }
  return 1;

}

/******************************************************************************
 * Function:    outputs()
 * Description: converts a non-base 10 number to base 10
 * Parameters:  number, int, and the number that is inputted
 *              bases[], int, and what base arrays that corresponds to the number
 *              Fours[], int, and the number of 4s in the number that corresponds to number array
 *
 * Return:      Nothing
 ******************************************************************************/

void outputs(long long numbers[], int base, int bases[], int Fours[], int numbersOG[])
{

  int i;			// looping variable for the loop 
  int fours;	//counts how many have been printed
  int maxFours; //maximum amount of fours
  int maxBase;  //base that holds most fours
  int j;      //index variable for loop
  int k;      //index variable for loop
  int outputs[50];
  int number;
  int counter;
  counter = 0;
  for (j = 0; j < SIZE; j++)
  { 
    maxFours = count4(numbersOG[j]);
    for(i = 10; i > 4; i--)
    {
      fours = convertFromTen(numbers[j], i);
	  number = convertFromTenPrint(numbers[j], i)
      if (fours > maxFours)
      {
		outputs[counter] = number;
		bases[counter] = i;
		Fours[counter] = fours;
		counter++
		
      }
    }
  }
  printf("\nConversions with most fours:\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("###      Number      Base     Fours\n");
  for(k = 0; k < counter; k++)
  {
	printf("%d\n", outputs[k]);
  }
  return;

}
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