/******************************************************************************
* Assignment:  Lab 8
* Lab Section: 11453
* Description: This program simulates a game of blackjack between a player and a dealer
* Programmers: Dante Sanaei dsanaei@purdue.edu
*              Jessica Townsend townse23@purdue.edu
*              Michael Yu yu611@purdue.edu
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
void input(int *seed);
void printHands(int seed,int *win,int *dealerTotal, int *userTotal);
void printNum(int num);
int convert(int num);
void drawCard(int *draw);
int handTwo(int draw, int userTotal);
void printScore(int dealerTotal,int userTotal);
void ifStatement(int win, int userTotal, int dealerTotal);

int main()
{

  // Initializations
  int seed;				//Seed for the random number generator
  int win;				//Number for if the user wins 
  int userTotal;		//total for the user
  int dealerTotal;		//total for the dealer
  
  // input and outputs
  input(&seed);
  printHands(seed, &win, &dealerTotal, &userTotal);
  ifStatement( win,  userTotal,  dealerTotal);
  return 0;
  
}

/******************************************************************************
* Function:    input()
* Description: asks for the seed from the user
* Parameters:  seed, int, and the seed for the random number generator
*
*              
* Return:      nothing
******************************************************************************/

void input(int *seed)
{

  printf("Enter seed -> ");
  scanf("%d", seed);
  return;
  
}

/******************************************************************************
* Function:    printHands()
* Description: prints the hands in the first part of the output
* Parameters:  seed, int, and the seed for the random number generator
*			   win, int, number for if the user wins
*			   dealerTotal, int, current dealer total
*			   userTotal, int, current user total
*              
* Return:      nothing
******************************************************************************/

void printHands(int seed,int *win,int *dealerTotal,int *userTotal)
{

  int dealer1;		//Dealer first random number
  int dealer2;		//Dealer second random number
  int dealer3;		//Dealer third random number
  int user1;		//user first random number
  int user2;		//user second random number
  int dealer1Real;	//Dealer converted card number
  int dealer2Real;	//Dealer converted card number
  int dealer3Real;	//Dealer converted card number
  int user1Real;	//User converted card number
  int user2Real;	//User converted card number
  srand(seed);
  dealer1 = rand() % 13 + 1;
  dealer2 = rand() % 13 + 1;
  user1 = rand() % 13 + 1;
  user2 = rand() % 13 + 1;
  dealer1Real = convert(dealer1);
  dealer2Real = convert(dealer2);
  user1Real = convert(user1);
  user2Real = convert(user2);
  *dealerTotal = dealer1Real + dealer2Real;
  printf("\nDealer's hand: ");
  printNum(dealer1);
  printNum(dealer2);
  printf("\nYour hand: ");
  printNum(user1);
  printNum(user2);
  *win = 1;
  printf("\n\n");
  while (*dealerTotal < 15)			//If the dealer total is less than 16 
  {
    dealer3 = rand() % 13 + 1;
    dealer3Real = convert(dealer3);
    *dealerTotal += dealer3Real;
    printf("The dealer draws another card: ");
    printNum(dealer3);
    printf("\n");
  }
  if (*dealerTotal == 21)			//If the dealer total is 21 (blackjack)
  {
    printf("Dealer Note: blackjack!\n\n");
  }
  else if(*dealerTotal > 21)			//If the dealer total is greater than 21 (bust)
  {
    printf("\nYou win: dealer bust\n\n");
    *win = 0;
  }
  else
  {
    printf("Dealer Note: hold.\n\n");
  }
  *userTotal = user1Real + user2Real;
  
}

/******************************************************************************
* Function:    printNum()
* Description: prints the number
* Parameters:  num, int, number that needs to be printed as a card
*
*              
* Return:      nothing
******************************************************************************/

void printNum(int num)
{

  switch(num)
  {
    case 11: 		//if 11
    printf("J ");
    break;
    case 12:  		//if 12
    printf("Q ");
    break;
    case 13:  		//if 13
    printf("K ");
    break;
    case 1:  		//if 1
    printf("A ");
    break;
    default: 		//default
    printf("%d ", num);
	
  }
}

/******************************************************************************
* Function:    convert()
* Description: converts the number to a card number
* Parameters:  num, int, number that needs to be printed as a card
*
*              
* Return:      nothing
******************************************************************************/

int convert(int num)
{

  if (num >= 11 && num <= 13)	// if the number is between 11 and 13
  {
    num = 10;
  }
  return num;
  
}

/******************************************************************************
* Function:    drawCard()
* Description: prints the number
* Parameters:  draw, int, 1 or 0 depending if the user wants to draw another card
*
*              
* Return:      nothing
******************************************************************************/

void drawCard(int *draw)
{

  printf("Number of cards to draw (0 or 1) -> ");
  scanf("%d", draw);
  return;
  
}

/******************************************************************************
* Function:    handTwo()
* Description: prints the hands in the first part of the output
* Parameters:  draw, int, 1 or 0 depending if the user wants to draw another card
*			   userTotal, int, current user total
*              
* Return:      returns the user total
******************************************************************************/

int handTwo( int draw, int userTotal)
{

  int user1;		//new card for the user
  int user1Real;	//converted card value for the user
  user1Real = 0;
  if (draw)				// if draw is 1
  {
    printf("\nYou draw another card: ");
    user1 = rand() % 13 + 1;
    printNum(user1);
    user1Real = convert(user1);
    if (userTotal + user1Real == 21)		// if the user total is 21 (blackjack)
    {
      printf("\nPlayer note: blackjack!\n");
    }
  }
  else						//if nothing happens
  {
    printf("\nPlayer note: hold.\n");
  }
  printf("\n");
  return user1Real;
  
}

/******************************************************************************
* Function:    printScore()
* Description: prints the hands in the first part of the output
* Parameters:  userTotal, int, current user total
*			   dealerTotal, int, current dealer total
*              
* Return:      nothing
******************************************************************************/

void printScore(int dealerTotal,int userTotal)
{

  if(userTotal > dealerTotal)		//if the user total is greater than dealer total
  {
    printf("You win: %d to %d\n", userTotal, dealerTotal);
  }
  else if (userTotal < dealerTotal)		//if the user total is less than dealer total
  {
    printf("The dealer wins: %d to %d\n", dealerTotal, userTotal);
  }
  else if(userTotal == dealerTotal)		//if the user total is the same as the dealer total
  {
    printf("It's a draw, score: %d\n", userTotal);
  }
  else				//redundant else
  {
    printf("\n");
  }
  
}

/******************************************************************************
* Function:    ifStatement()
* Description: prints the hands in the first part of the output
* Parameters:  win, int, number to see if user won
*			   dealerTotal, int, current dealer total
*              userTotal, int, current user total
*
* Return:      nothing
******************************************************************************/

void ifStatement(int win, int userTotal, int dealerTotal)
{

  int draw; //the number for if the user will continue to draw
  draw = 1;
  while (win && userTotal < 21 && draw == 1)		//if win is 1 then it continues
  {
    drawCard(&draw);
    userTotal += handTwo(draw, userTotal);
  }
  if (dealerTotal <= 21 && userTotal <= 21)
    printScore(dealerTotal, userTotal);
  if(userTotal > 21)		//if the user total is greater than 21
  {
    printf("Dealer wins: player bust\n");
  }
  return;
  
}
