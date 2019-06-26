/******************************************************************************
* Assignment:  HW04
* Lab Section: Tuesday, 11:20, SC 189
* Description: This lab takes the speed, time of departure, and distance and calculates the time of arrival.
* Programmers: Dante Sanaei dsanaei@purdue.edu

******************************************************************************/
#include <stdio.h>
void inputs(int *depHour, int *depMin, int *distance, int *speed);
void getDuration(int *hour, int *min, int distance, int speed);
int printTime(int hour, int min, int amorpm, int print);
void printDepTime(int hour, int min);
int getAMorPM(int hour);
void getArrival(int depHour, int depMin, int durHour, int durMin);
int main(void)
{
  //Initializations
  int depHour;		//Departure Hour
  int depMin;		//departure minute
  int distance;		//distance (kilometers)
  int speed;		//average speed (kph)
  int durHour;		//duration of the trip hours
  int durMin;		//duration of the trip minutes
  //inputs, calculations and outputs
  inputs( &depHour,  &depMin,  &distance,  &speed);
  getDuration(&durHour, &durMin, distance, speed);
  printDepTime(depHour, depMin);
  getArrival(depHour, depMin, durHour, durMin);
 
  return 0;
  
}

/******************************************************************************
* Function:    inputs()
* Description: prints the input strings and gets the user input
* Parameters:  depHour, int,  departure hour
*			   depMin, int, departure minute
*			   distance, int, distance of the trip
* 			   speed, int, speed of the trip
*              
* Return:      nothing
******************************************************************************/

void inputs(int *depHour, int *depMin, int *distance, int *speed)
{
	
  printf("Enter the hour of departure (0-23)-> ");
  scanf("%d", depHour);
  printf("Enter the minute of departure (0-59)-> ");
  scanf("%d", depMin);
  printf("Enter distance of trip (km)-> ");
  scanf("%d", distance);
  printf("Enter average travel speed (kph)-> ");
  scanf("%d", speed);
  printf("\n");
  return;
  
}

/******************************************************************************
* Function:    printTime()
* Description: prints the time in the notation 
* Parameters:  hour, int,   hour to print
*			   min, int,  minute to print
*			   amorpm, int, am or pm logical variable
* 			   print, int, print or not logical variable
*              
* Return:      new hour
******************************************************************************/

int printTime(int hour, int min, int amorpm, int print)
{
  switch(hour)			//Switch statement to convert the time inputed to the correct time printing standard
  {
    case 13:			//Case
    hour = 1;
    amorpm = 1;
    break;
    case 14:			//Case
    hour = 2;
    amorpm = 1;
    break;
    case 15:			//Case
    hour = 3;
    amorpm = 1;
    break;
    case 16:			//Case
    hour = 4;
    amorpm = 1;
    break;
    case 17:			//Case
    hour = 5;
    amorpm = 1;
    break;
    case 18:			//Case
    hour = 6;
    amorpm = 1;
    break;
    case 19:			//Case
    hour = 7;
    amorpm = 1;
    break;
    case 20:			//Case
    hour = 8;
    amorpm = 1;
    break;
    case 21:			//Case
    hour = 9;
    amorpm = 1;
    break;
    case 22:			//Case
    hour = 10;
    amorpm = 1;
    break;
    case 23:			//Case
    hour = 11;
    amorpm = 1;
    break;
    case 24:			//Case
    hour = 12;
    amorpm = 1;
    break;
  }
  if (print)	//If print is wanted 
  {
	  
    if (amorpm) 		//if it is PM
    {
      printf("%02d-%02d PM", hour, min);
    }
    else			//if AM
    {
      printf("%02d-%02d AM", hour, min);
    }
  }
  return hour;
  
}

/******************************************************************************
* Function:    getDuration()
* Description: prints the duration of the trip
* Parameters:  hour, int,   hour to print
*			   min, int,  minute to print
*			   distance, int, distance of the journey
* 			   speed, int, speed of the journey (average)
*              
* Return:      Nothing
******************************************************************************/

void getDuration(int *hour, int *min, int distance, int speed)
{
	
  double badTime;		//time in decimal form
  int decimalMin;		//minutes in decimal form
  badTime = (double)distance / speed;
  *hour = badTime;
  decimalMin = (int)(badTime * 1000) % 1000;
  *min = ((double)decimalMin / 1000) * 60;
  printf("Trip Duration: %d hour(s) and %d minute(s)\n", *hour, *min);
  return;
  
}

/******************************************************************************
* Function:    getArrival()
* Description: prints the arrival time of the user
* Parameters:  depHour, int,   hour of departure
*			   depMin, int,  minute of departure
*			   durHour, int, hour of duration
* 			   durMin, int, minute of duration
*              
* Return:      nothing
******************************************************************************/

void getArrival(int depHour, int depMin, int durHour, int durMin)
{
	
  int amorpm;		// am or pm logical variable
  int arrHour;		// arrival hour
  int arrMin;		//arrival minute
  int days;			//number of days it takes 
  int cycles;		//cycles from am to pm
  days = 0;
  amorpm = getAMorPM(depHour);
  depHour = printTime(depHour, depMin, amorpm, 0);
  arrHour = depHour + durHour;
  arrMin = depMin + durMin;
  if (arrMin >= 60)		//if the minutes are greater than 60
  {
    arrMin -= 60;
    arrHour++;
  }
  if (arrHour == 12 && !amorpm)		//if the hours are equal to 12 and am
  {
    amorpm = 1;
  }
  else if  (arrHour == 12 && amorpm)		//if the hours are equal to 12 and pm
  {
    amorpm = 0;
    days = 1;
  }
  else if (arrHour > 12 && arrHour < 24 && !amorpm)		//if the hours are greater than 12 and am
  {
    amorpm = 1;
    arrHour -= 12;
  }
  else if(arrHour > 12 && arrHour < 24 && amorpm)		//if the hours are greater than 12 and pm
  {
    amorpm = 0;
    days = 1;
    arrHour -= 12;
  }
  else if (arrHour >= 24 && !amorpm)		//if the hours are greater than 24 and am
  {
    cycles  = arrHour / 12;
    if(cycles % 2 != 0)
      amorpm = 1;
    arrHour -= (cycles) * 12;
    days = durHour / 12;
  }
  else if (arrHour >= 24 && amorpm)		//if the hours are greater than 24 and pm
  {
    cycles  = arrHour / 12;
    if(cycles % 2 != 0)
      amorpm = 0;
    arrHour -= (cycles) * 12;
    days = durHour / 12;
  }
  printf("Arrival Time: ");
  printTime(arrHour, arrMin, amorpm, 1);
  if (days == 1)				//if a full day has passed
    printf(" (next day)");
  if (days > 1)					// if more than 1 full days has passed
    printf(" (in %d days)", days);
  printf("\n");
  
}

/******************************************************************************
* Function:    getAMorPM()
* Description: gets the am or pm logical variable
* Parameters:  hour, int, hour to analyze
*              
* Return:      nothing
******************************************************************************/

int getAMorPM(int hour)
{
	
  int amorpm;		//am or pm logical variable
  if(hour > 12)		//if it is PM
    amorpm = 1;
  else 				//else it is AM
    amorpm = 0;
  return amorpm;
  
}  

/******************************************************************************
* Function:    printDepTime()
* Description: prints the departure time
* Parameters:  hour, int,   hour to print
*			   min, int,  minute to print
*              
* Return:      nothing
******************************************************************************/

void printDepTime(int hour, int min)
{
	
  printf("Departure Time: ");
  printTime(hour, min, getAMorPM(hour), 1);
  printf("\n");
  return;
  
}