/******************************************************************************
 * Assignment:  Homework 06
 * Lab Section: 11453
 * Description: This program takes in a range of numbers and calculates how many type 1 and type 2 numbers there are
 * Programmers: Dante Sanaei dsanaei@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
void inputs(int *firstNum, int *secondNum);
void calculations(int *typeOne, int *typeTwo, int firstNum, int secondNum);
void outputs(int firstNum, int secondNum, int typeOne, int typeTwo);
int main()
{

  //Initializations
  int firstNum;					//First number in the range
  int secondNum;					//Last number in the range
  int typeOne;					//How many type one numbers there are
  int typeTwo;					//How many type two numbers there are
  typeOne = 0;
  typeTwo = 0;
  firstNum = 0;
  secondNum = 0;

  //Inputs
  inputs(&firstNum, &secondNum);

  //Calculations
  calculations(&typeOne, &typeTwo, firstNum, secondNum);

  //Outputs
  outputs(firstNum,  secondNum, typeOne, typeTwo);

  return 0;

}

/******************************************************************************
 * Function:    inputs()
 * Description: prompts the user to input the starting and ending numbers
 * Parameters:  firstNum, int, and the starting number of the range
 *              secondNum, int, and the ending number of the range
 *              
 * Return:      nothing
 ******************************************************************************/

void inputs(int *firstNum, int *secondNum)
{

  do
  {

    if (*firstNum < 0)			//Checks if the first number is negative
    {
      printf("\nError! Starting value must be non-negative!!\n\n");
      printf("Enter starting value of range -> ");
      scanf("%d", firstNum);
      printf("Enter ending value of range -> ");
      scanf("%d", secondNum);
    }
    else if(*secondNum - *firstNum < 0)				//checks if the difference is negative
    {
      printf("\nError! Ending value must be >= %d\n\n", *firstNum);
      printf("Enter ending value of range -> ");
      scanf("%d", secondNum);
    }
    else if (*secondNum - *firstNum > 5000000)		//checks if the difference is greater than 5 million
    {
      printf("\nError! The maximum difference between start and end is 5000000\n\n");
      printf("Enter starting value of range -> ");
      scanf("%d", firstNum);
      printf("Enter ending value of range -> ");
      scanf("%d", secondNum);
    }
    else
    {
      printf("Enter starting value of range -> ");
      scanf("%d", firstNum);
      if (*firstNum >= 0)				//if the number is positive
      {
        printf("Enter ending value of range -> ");
        scanf("%d", secondNum);
      }
    }
  }while(*firstNum < 0 || *secondNum - *firstNum < 0 || *secondNum - *firstNum > 5000000);

  return;

}

/******************************************************************************
 * Function:    calculations()
 * Description: preforms the calculations and returns the counts of type 1 and 2
 * Parameters:  firstNum, int, and the starting number of the range
 *              secondNum, int, and the ending number of the range
 *              typeOne, int, and the amount of type 1 numbers
 *			   typeTwo, int, and the amount of type 2 numbers
 *
 * Return:      nothing
 ******************************************************************************/

void calculations(int *typeOne, int *typeTwo, int firstNum, int secondNum)
{

  int number;						//The number that will be analyzed in the for loop
  int digit;						//The last digit of the number
  int previousDigit;				//The second to last digit of the nmber
  int newNum;						//the number that will be manipulated in the while loops
  int thirdDig;					//the third to last digit in the number
  int countOne;					//the count of type one
  int breakVariable2;				//the break variable in the first while loop
  int countTwo;					//The count of type two
  int breakVariable;				//the break variable for the second while loop
  countOne = 0;
  breakVariable = 1;
  countTwo = 0;
  for (number = firstNum; number <= secondNum; number++)			//go through the entire range of numbers
  {
    newNum = number;
    breakVariable = 1;
    breakVariable2 = 1;
    //printf("%d\n", number);
    while (newNum > 9 && breakVariable)							//go through each number and analyze the digits
    {
      previousDigit = newNum % 10;
      digit =  (newNum % 100) / 10;
      thirdDig = (newNum % 1000) / 100;
      if (previousDigit == digit)
      {
        //printf("%d %d %d %d\n", previousDigit, digit, thirdDig, number);
        countOne++;
        breakVariable = 0;
        breakVariable2 = 0;
      }
      newNum /= 10;
    }
    newNum = number;
    breakVariable = 1;
    if (breakVariable2)
    {
      while(newNum > 9 && breakVariable)
      {
        previousDigit = newNum % 10;
        digit =  (newNum % 100) / 10;
        thirdDig = (newNum % 1000) / 100;
        if(thirdDig == previousDigit && newNum / 100 > 0)
        {
          countTwo++;
          breakVariable = 0;
        }
        newNum /= 10;
      }	
    }		

  }
  *typeOne = countOne;
  *typeTwo = countTwo;
  return;

}

/******************************************************************************
 * Function:    outputs()
 * Description: outputs the data that was found
 * Parameters:  firstNum, int, and the starting number of the range
 *              secondNum, int, and the ending number of the range
 *              typeOne, int, and the amount of type 1 numbers
 *			   typeTwo, int, and the amount of type 2 numbers
 *
 * Return:      nothing
 ******************************************************************************/

void outputs(int firstNum, int secondNum, int typeOne, int typeTwo)
{

  printf("\nFor data in the range: [%d, %d]\n", firstNum, secondNum);
  printf("Number of type-1 matches: %d\n", typeOne);
  printf("Number of type-2 matches: %d\n", typeTwo);
  return;

}
