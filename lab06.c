/******************************************************************************
* Assignment:  Lab 5
* Lab Section: 11453
* Description: This program takes 3 inputs from the user and does math on 2 operands. It then prints out the entire operation with words. 
* Programmers: Dante Sanaei dsanaei@purdue.edu
*              Jessica Townsend townse23@purdue.edu
*              Michael Yu yu611@purdue.edu
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
void input(int *selection, int *firstNum, int *secondNum);
void under20(int number);
void printNumber( int number);
void over20(int number);
void output(int selection, int firstNum, int secondNum);
void printMath(int selection);

int main()
{
	
  //Initializations
  int firstNum;					// First Operand inputed
  int secondNum;				// Second Operand inputed
  int selection;				// Operator Selection from the user
  
  //Input
  input(&selection, &firstNum, &secondNum);
  
  //Output
  output(selection, firstNum, secondNum);  
  
  return 0;
  
}

/******************************************************************************
* Function:    input()
* Description: prints the input strings and gets the user input
* Parameters:  selection, int, and operator selection
*			   firstNum, int, first Operand
*			   secondNum, int, second Operand
*              
* Return:      nothing
******************************************************************************/

void input(int *selection, int *firstNum, int *secondNum)
{
  printf("Available Operations\n\n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("5. Modulus\n");
  printf("Make your selection now -> ");
  scanf("%d", selection);
  printf("\nEnter operand #1 -> ");
  scanf("%d", firstNum);
  printf("Enter operand #2 -> ");
  scanf("%d", secondNum);
  return;
  
}

/******************************************************************************
* Function:    doMath()
* Description: does the math that the user wants
* Parameters:  selection, int, and operator selection
*			   firstNum, int, first Operand
*			   secondNum, int, second Operand
*              
* Return:      answer to the math
******************************************************************************/

int doMath(int selection, int firstNum, int secondNum)
{
  //Initializations
  int answer;				// The answer of the math operation
  
  //If statements
  if(selection == 1)
  {
    answer = firstNum + secondNum;		// Calculates the answer
  }
  if(selection == 2)
  {
    answer = firstNum - secondNum;		// Calculates the answer
  }
  if(selection == 3)
  {
    answer = firstNum * secondNum;		// Calculates the answer
  }
  if(selection == 4)
  {
    answer = firstNum / secondNum;		// Calculates the answer
  }
  if(selection == 5)
  {
    answer = firstNum % secondNum;		// Calculates the answer
  }
  else
  {
    answer = 0;		// Calculates the answer
  }
  return answer;
  
}

/******************************************************************************
* Function:    under20()
* Description: prints the number if it under 20
* Parameters:  number, int, number that is converted to a word
*              
* Return:      nothing
******************************************************************************/

void under20(int number)
{
  //selection statements
  switch(number)
  {
    case 0:			//Case
    printf("zero");	
    break;
    case 1:			//Case
    printf("one");
    break;
    case 2:			//Case
    printf("two");
    break;
    case 3:			//Case
    printf("three");
    break;
    case 4:			//Case
    printf("four");
    break;
    case 5:			//Case
    printf("five");
    break;
    case 6:			//Case
    printf("six");
    break;
    case 7:			//Case
    printf("seven");
    break;
    case 8:			//Case
    printf("eight");
    break;
    case 9:			//Case
    printf("nine");
    break;
    case 10:			//Case
    printf("ten");
    break;
    case 11:			//Case
    printf("eleven");
    break;
    case 12:			//Case
    printf("twelve");
    break;
    case 13:			//Case
    printf("thirteen");
    break;
    case 14:			//Case
    printf("fourteen");
    break;
    case 15:			//Case
    printf("fifteen");
    break;
    case 16:			//Case
    printf("sixteen");
    break;
    case 17:			//Case
    printf("seventeen");
    break;
    case 18:			//Case
    printf("eighteen");
    break;
    case 19:			//Case
    printf("nineteen");
    break;
    default:			//Case
    printf(" ");
    break;
  }
	
  return;
  
}

/******************************************************************************
* Function:    printNumber()
* Description: prints the number 
* Parameters:  number, int, number that is converted to a word
*              
* Return:      nothing
******************************************************************************/

void printNumber(int number)
{
  //Logic
  if (number < 20)
  {
    under20(number); 	//Finds the number
  }
  if (number >= 20 && number < 100)
  {
    over20(number); 	//Finds the number
  }
  if(number > 99)
  {
    printf("%d", number); 	//Finds the number
  }

  return;

}

/******************************************************************************
* Function:    over20()
* Description: prints the number if it over 20
* Parameters:  number, int, number that is converted to a word
*              
* Return:      nothing
******************************************************************************/

void over20(int number)
{
  //Initializations
  int digit1;		// First digit of number
  int digit2;		// Second digit of number
  
  //Calculations
  digit1 = number / 10;
  digit2 = number % 10;
  
  //Selection
  if(digit1 == 2) 	//Finds the number
  {
    printf("twenty"); 	//Finds the number
  }
  if(digit1 == 3)
  {
    printf("thirty"); 	//Finds the number
  }
  if(digit1 == 4)
  {
    printf("forty"); 	//Finds the number
  }
  if(digit1 == 5)
  {
    printf("fifty"); 	//Finds the number
  }
  if(digit1 == 6)
  {
    printf("sixty"); 	//Finds the number
  }
  if(digit1 == 7)
  {
    printf("seventy"); 	//Finds the number
  }
  if(digit1 == 8)
  {
    printf("eighty"); 	//Finds the number
  }
  if(digit1 == 9)
  {
    printf("ninety"); 	//Finds the number
  }
  if(digit2 != 0) 	//Finds the number
  {
    printf("-");
    switch(digit2)
    {
	  //This is a  comment
      case 1:			//Case
      printf("one");
      break;
      case 2:			//Case
      printf("two");
      break;
      case 3:			//Case
      printf("three");
      break;
      case 4:			//Case
      printf("four");
      break;
      case 5:			//Case
      printf("five");
      break;
      case 6:			//Case
      printf("six");
      break;
      case 7:			//Case
      printf("seven");
      break;
      case 8:			//Case
      printf("eight");
      break;
      case 9:			//Case
      printf("nine");
      break;
      default:			//Case
      printf(" ");
      break;
    }
  }
  return;
  
}

/******************************************************************************
* Function:    printMath()
* Description: prints the math operator
* Parameters:  selection, int, selected operator
*              
* Return:      nothing
******************************************************************************/

void printMath(int selection)
{
  //Selections
  switch(selection)
  {
    case 1:			//Case
    printf("plus");
    break;
    case 2:			//Case
    printf("minus");
    break;
    case 3:			//Case
    printf("times");
    break;
    case 4:			//Case
    printf("over");
    break;
    case 5:			//Case
    printf("mod");
    break;
    default:			//Case
    printf(" ");
    break;
  }
  return;
  
}

/******************************************************************************
* Function:    output()
* Description: prints the output of the function
* Parameters:  selection, int, and operator selection
*			   firstNum, int, first Operand
*			   secondNum, int, second Operand
*              
* Return:      nothing
******************************************************************************/

void output(int selection, int firstNum, int secondNum)
{
  printf("\nGenerated expression: ");
 
  if(firstNum < 0)
  {
    printf("negative ");		
  }
  printNumber(abs(firstNum));
  printf(" ");
  printMath(selection);
  printf(" ");
  if(secondNum < 0)
  {
    printf("negative ");		
  }
  printNumber(abs(secondNum));
  printf(" equals ");
  if(doMath(selection, firstNum, secondNum) < 0)
  {
    printf("negative ");
  }
  printNumber(abs(doMath(selection, firstNum, secondNum)));
  printf("\n");
  return;

}
