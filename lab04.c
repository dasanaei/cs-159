/******************************************************************************
 * Assignment:  Lab 04
 * Lab Section: Tuesday, 11:30, SC 189
 * Description: This program takes in user input of a a large and small circular orbit radius, and outputs the change in velocity at the insertion and arrival burns. Additionally it outputs the total change in velocity. 
 * Programmers: Dante Sanaei dsanaei@purdue.edu
 *              Benjamin Bridge bridgeb@purdue.edu
 *              Clayton Bennet benne184@purdue.edu
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#define AU 1.496 * pow(10,11)
#define Mu 1.327124 * pow(10,20)
double getRadiusM(double);
double getsemiMajorAxis(double, double);
double getCircular(double);
double getElliptical(double, double);
double add(double, double);
double subtract(double, double);
void printOutputs(double, double, double, double, double);
  
int main(void)
{
  //initializations
  double startRadiusAU;				// starting orbital radius (AU)
  double endRadiusAU;				// ending orbital radius (AU)
  double startRadiusM;				// starting orbital radius (m)
  double endRadiusM;				// ending orbital radius (m)
  double insBurn;					// change in velocity in order to preform an insertion burn (m/s)
  double arrBurn;					// change in velocity in order to preform an arrival burn (m/s)
  double deltaV;					// change in velocity of the entire Holman (m/s)
  
    
  //inputs
  printf("Enter starting orbital radius (AU) -> ");
  scanf("%lf", &startRadiusAU);
  printf("Enter ending orbital radius (AU) -> ");
  scanf("%lf", &endRadiusAU);
    
  //calculations
  startRadiusM = getRadiusM(startRadiusAU);
  endRadiusM = getRadiusM(endRadiusAU);
  insBurn = subtract(getElliptical(startRadiusM, getsemiMajorAxis(startRadiusM, endRadiusM)), getCircular(startRadiusM));
  arrBurn = subtract(getCircular(endRadiusM), getElliptical(endRadiusM, getsemiMajorAxis(startRadiusM, endRadiusM)));
  deltaV = add(insBurn, arrBurn);
  
  //outputs
  printOutputs(startRadiusM, endRadiusM, insBurn, arrBurn, deltaV);

  return 0;
}


/******************************************************************************
* Function:    getRadiusAU()
* Description: Converts AU to meters
* Parameters:  radiusAU, double, and radius in AU
*              
* Return:      double and radius in meters
******************************************************************************/
double getRadiusM(double radiusAU)
{
  return radiusAU * AU;
}

/******************************************************************************
* Function:    getsemiMajorAxis()
* Description: The function returns the semi major axis number (a)
* Parameters:  rPrime, double, and radius of larger orbit
*              R , double, and radius of smaller orbit
* Return:      double and semi major axis of the orbits
******************************************************************************/
double getsemiMajorAxis(double rPrime, double R)
{
  return ((rPrime + R) / 2);
}

/******************************************************************************
* Function:    getCircular()
* Description: this function returns the velocity of a circular orbit
* Parameters:  radius, double, and radius of the circular orbit
*            
* Return:      double and the velocity of a circular orbit
******************************************************************************/
double getCircular(double radius)
{
  return sqrt(Mu / radius);
}

/******************************************************************************
* Function:    getElliptical()
* Description: this function returns the velocity of an elliptical orbit
* Parameters:  radius, double, radius of the elliptical orbit
*              a, double, and semi major axis
* Return:      double and returns velocity of elliptical orbit
******************************************************************************/
double getElliptical(double radius, double a)
{
  return sqrt(Mu * ((2 / radius) - (1 / a)));
}

/******************************************************************************
* Function:    add()
* Description: this function adds two things together
* Parameters:  first, double, first input being added
*              second, double, second double being added
* Return:      double and two objects that have been added
******************************************************************************/
double add(double first, double second)
{
  return first + second;
}

/******************************************************************************
* Function:    subtract()
* Description: this function subtracts two things
* Parameters:  first, double, first input being subtracted
*              second, double, second double being subtracted
* Return:      double and two objects that have been subtracted
******************************************************************************/
double subtract(double first, double second)
{
  return first - second;
}

/******************************************************************************
* Function:    printOutputs()
* Description: this function prints all of the outputs
* Parameters:  startRadius, double, orbit radius of the starting point
*              endRadius, double, orbit radius of ending point
*			   insBurn, double, deltaV for insertion burn
*			   arrBurn, double, deltaV for arrival burn
*			   deltaV, double, total change in velocity
* Return:      double and two objects that have been added
******************************************************************************/
void printOutputs(double startRadius, double endRadius, double insBurn, double arrBurn, double deltaV)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Orbit Radius of starting planet from the Sun (m):%16.2e\n", startRadius);
  printf("Orbit Radius of destination planet from the Sun (m):%13.2e\n", endRadius);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Insertion burn change in velocity (m/s):%13.2lf\n", insBurn);
  printf("Arrival burn change in velocity (m/s):%15.2lf\n", arrBurn);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Change in velocity to complete the Hohmann transfer (m/s):%13.2lf\n", fabs(deltaV));
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return;
}









