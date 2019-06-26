/******************************************************************************
 * Assignment:  HW 07
 * Lab Section: 11453
 * Description: This program takes in coin and date information from the user and outputs data
 * Programmers: Dante Sanaei dsanaei@purdue.edu
 *
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#define MAXSIZE 50
void inputs();
void sort(int array[], int size);
void getCoin(int rawNum[], int count, int coins[]);
void uniqueDate(int rawNum[], int count);
void uniqueCoin(int rawNum[], int count);
void Swap(int *x, int *y);
void print(int rawNum[], int count);
void getDate(int rawNum[], int count, int dates[]);
void incompleteDate(int date[], int count, int coin[]);
void incompleteCoin(int date[], int count, int coin[]);

int main()
{	
  //inputs and calculations
  inputs();

  return 0;

}

/******************************************************************************
 * Function:    inputs()
 * Description: prompts user for inputs and stores them
 * Parameters:  
 *              
 * Return:      nothing
 ******************************************************************************/

void inputs()
{
  int coin[MAXSIZE];    //array of coins
  int date[MAXSIZE];    //array of dates
  int choice;           //which choice you have
  int i;                //index variable
  int count;            //real length of index
  int exit;             //exit variable
  exit = 1;
  count = 0;
  i = 0;

  printf("Enter data now -> "); 
  while(i < MAXSIZE && exit)        //input the numbers
  {
    scanf("%d", &coin[i]);
    if (coin[i] == -1)
      exit = 0;
    else
    {
      scanf("%d", &date[i]);
      count++;
    }
    i++;

  }
  printf("\n1. Display unique dates.\n2. Display unique denominations.\n3. Display incomplete set data for dates.\n4. Display incomplete set data for coins.\nEnter option for data set (size %d) -> ", count);

  scanf("%d", &choice);
  while(choice >= 5 || choice < 1)  //input validation
  {
    printf("\nError! Select a valid option from the menu above!\n");
    printf("\n1. Display unique dates.\n2. Display unique denominations.\n3. Display incomplete set data for dates.\n4. Display incomplete set data for coins.\nEnter option for data set (size %d) -> ", count);

    scanf("%d", &choice);
  }
  if(choice == 1)       //choice selection statements
  {
    uniqueDate(date, count);
  }
  else if(choice == 2)
  {
    uniqueCoin(coin,  count);
  }
  else if(choice == 3)
  {
    incompleteDate(date, count, coin);
  }
  else if(choice == 4)
  {
    incompleteCoin(date, count, coin);
  }
  return;

}

/******************************************************************************
 * Function:    sort()
 * Description: sorts an array
 * Parameters:  array[], int, and the number array that is inputted.
 *              counter, int, and the size of the array.
 *              
 * Return:      nothing
 ******************************************************************************/

void sort(int array[], int counter)
{

  int i;  //index array
  int j;  //index array
  int hold;   // temp hold array
  for (i = 0; i < counter; i++)
  {
    for(j = 0; j < counter - i - 1; j++)
    {
      if (array[j] < array[j + 1])
      {
        hold = array[j];
        array[j] = array[j + 1];
        array[j + 1] = hold;

      }
    }
  }
  return;

}

/******************************************************************************
 * Function:    uniqueDate()
 * Description: finds the unique datas
 * Parameters:  rawNum[], int, and the number array that is inputted.
 *              count, int, and the size of the array.
 *              
 * Return:      nothing
 ******************************************************************************/

void uniqueDate(int rawNum[], int count)
{

  int dates[MAXSIZE];     //array of dates
  int i;                  //index variable
  int k;      //index variable
  k = 0;  
  sort(rawNum, count);        //sorting
  for(i = 0; i < count; i++)      //for loop
  {
    if (i == 0)
    {
      dates[k] = rawNum[i];
      k++;
    }
    else if(rawNum[i] != rawNum[i - 1])
    {
      dates[k] = rawNum[i];
      k++;
    }
  }
  printf("\nUnique dates in set: ");
  for (i = 0; i < k; i++)       //for loop
  {
    printf("%d ", dates[i]);
  }
  printf("\n");
  return;
}

/******************************************************************************
 * Function:    uniqueCoin()
 * Description: finds the unique coins
 * Parameters:  rawNum[], int, and the number array that is inputted.
 *              count, int, and the size of the array.
 *              
 * Return:      nothing
 ******************************************************************************/

void uniqueCoin(int rawNum[], int count)
{

  int coins[MAXSIZE];     //array of coins
  int i;      //index variable
  int k;  //idnex variable
  k = 0;
  sort(rawNum, count);      //sorting
  for(i = 0; i < count; i++)      //getting array of coins
  {
    if (i == 0)
    {
      coins[k] = rawNum[i];
      k++;
    }
    else if(rawNum[i] != rawNum[i-1])
    {
      coins[k] = rawNum[i];
      k++;
    }
  }
  printf("\nUnique denominations in set: ");    //printing
  for (i = 0; i < k; i++)
  {
    printf("%d ", coins[i]);
  }
  printf("\n");
  return;

}

/******************************************************************************
 * Function:    incompleteDate()
 * Description: finds the incomplete dates
 * Parameters:  date[], int, and the date array
 *              count, int, and the size of the array.
 *              coin[], int, and the coin array.
 *              
 * Return:      nothing
 ******************************************************************************/

void incompleteDate(int date[], int count, int coin[])
{

  int maxNum;       //maximum number of count
  int counts[MAXSIZE][MAXSIZE];       //counts 2d array
  int new[MAXSIZE];       //new temporary array
  int i;    //index variable
  int j;  //index variable
  int k;    //idnex variable
  int t;    //index variable
  int m;      //index variable
  int hold; //temp hold variable
  int hold2;    //temp hold variable
  int o;      //index variable
  o = 0;
  t = 0;
  for (i = 0; i < count; i++)     //sorting step 1
  {
    for(j = 0; j < count - i - 1; j++)
    {
      if (date[j] < date[j + 1])
      {
        hold = date[j];
        date[j] = date[j + 1];
        date[j + 1] = hold;

        hold2 = coin[j];
        coin[j] = coin[j + 1];
        coin[j + 1] = hold2;
      }

    }
  }
  for (i = 0; i < count; i++)       //sorting step 2
  {
    for(j = 0; j < count - i - 1; j++)
    {
      if (date[j] == date[j + 1] && coin[j] > coin[j + 1])
      {
        hold = date[j];
        date[j] = date[j + 1];
        date[j + 1] = hold;

        hold2 = coin[j];
        coin[j] = coin[j + 1];
        coin[j + 1] = hold2;
      }

    }
  }
  m = 0;
  for(i = 0; i < count; i++)        //deleting duplicates
  {
    if (i == 0)
    {
      new[m] = date[i];
      m++;
    }
    else if(date[i] != date[i - 1] || coin[i] != coin[i - 1])
    {
      new[m] = date[i];
      m++;
    }
  }
  k = 0;
  maxNum = 0;
  //sort(new, m);
  //print(new, m);
  for (i = 0; i < m; i++)           //counting how many there are
  {
    if (i == 0)
    {
      counts[k][0] = 1;
      counts[k][1] = new[i];
    }
    else if(new[i] == new[i - 1])
    {
      counts[k][0]++;
      counts[k][1] = new[i];
    }
    else
    {
      k++;
      counts[k][0] = 1;
      counts[k][1] = new[i];
    }
  }
  for( j = 0; j < k + 1; j++)       //finding the maximum
  {
    if (counts[j][0] > maxNum)
    {
      maxNum = counts[j][0];
    }
  }
  for( j = 0; j < k + 1; j++)      //finding if they are all 1
  {
    if (counts[j][0] == 1)
    {
      t++;
    }
  }
  for (i = 0; i < k + 1; i++)   //printing
  {
    if(counts[i][0] < maxNum || t == k + 1)
    {
      o++;
    }
    //printf("%d %d\n", counts[i][0], counts[i][1]);
  }
  if(o)
  {
    printf("\nIncomplete sets for the following dates: ");
    for (i = 0; i < k + 1; i++)
    {
      if(counts[i][0] < maxNum || t == k + 1)
      {
        printf("%d ", counts[i][1]);
      }
      //printf("%d %d\n", counts[i][0], counts[i][1]);
    }
  }
  else
  {
    printf("\nThere are no incomplete sets of dates.");
  }
  printf("\n");
  return;

}

/******************************************************************************
 * Function:    incompleteCoin()
 * Description: finds the incomplete dates
 * Parameters:  date[], int, and the date array
 *              count, int, and the size of the array.
 *              coin[], int, and the coin array.
 *              
 * Return:      nothing
 ******************************************************************************/

void incompleteCoin(int date[], int count, int coin[])
{

  int maxNum;     //maximum number
  int counts[MAXSIZE][MAXSIZE];   //counts 2d array holding amount and coin
  int new[MAXSIZE];   //temporary array
  int i;  //index variable
  int t;    //index variable
  int j;    //index variable
  int k;    //index variable
  int m;    //index variable
  int hold; //temp variable
  int hold2;  //temp variable
  int o;    //index variable
  t = 0;
  o = 0;
  for (i = 0; i < count; i++)   //sort step 1
  {
    for(j = 0; j < count - i - 1; j++)
    {
      if (date[j] < date[j + 1])
      {
        hold = date[j];
        date[j] = date[j + 1];
        date[j + 1] = hold;

        hold2 = coin[j];
        coin[j] = coin[j + 1];
        coin[j + 1] = hold2;
      }

    }
  }
  for (i = 0; i < count; i++)     //sort step 2
  {
    for(j = 0; j < count - i - 1; j++)
    {
      if (date[j] == date[j + 1] && coin[j] > coin[j + 1])
      {
        hold = date[j];
        date[j] = date[j + 1];
        date[j + 1] = hold;

        hold2 = coin[j];
        coin[j] = coin[j + 1];
        coin[j + 1] = hold2;
      }

    }
  }

  m = 0;
  for(i = 0; i < count; i++)    //delete duplicates
  {
    if (i == 0)
    {
      new[m] = coin[i];
      m++;
    }
    else if(date[i] != date[i - 1] || coin[i] != coin[i - 1])
    {
      new[m] = coin[i];
      m++;
    }
  }
  k = 0;
  maxNum = 0;
  sort(new, m);
  for (i = 0; i < m; i++)     //find the amount of each coin
  {
    if (i == 0)
    {
      counts[k][0] = 1;
      counts[k][1] = new[i];
    }
    else if(new[i] == new[i - 1])
    {
      counts[k][0]++;
      counts[k][1] = new[i];
    }
    else
    {
      k++;
      counts[k][0] = 1;
      counts[k][1] = new[i];
    }
  }
  for( j = 0; j < k + 1; j++)        //find the largest
  {
    if (counts[j][0] > maxNum)
    {
      maxNum = counts[j][0];
    }
  }
  for( j = 0; j < k + 1; j++)      //see if they are all 1
  {
    if (counts[j][0] == 1)
    {
      t++;
    }
  }
  for (i = 0; i < k + 1; i++)   //Printing
  {
    if(counts[i][0] < maxNum || t == k + 1)
    {
      o++;
    }
    //printf("%d %d\n", counts[i][0], counts[i][1]);
  }
  if(o)
  {
    printf("\nIncomplete sets for the following coins: ");
    for (i = 0; i < k + 1; i++)
    {
      if(counts[i][0] < maxNum || t == k + 1)
      {
        printf("%d ", counts[i][1]);
      }
      //printf("%d %d\n", counts[i][0], counts[i][1]);
    }
  }
  else
  {
    printf("\nThere are no incomplete sets of coins.");
  }
  printf("\n");
  return;

}
