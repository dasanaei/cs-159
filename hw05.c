/******************************************************************************
 * Assignment:  Homework 05
 * Lab Section: 11453
 * Description: This program takes in inputs from the user in order to calculate the work using an integral and trapezoidal sum
 * Programmers: Dante Sanaei dsanaei@purdue.edu
 ******************************************************************************/

#include <stdio.h>
#include <math.h>
void inputs(int *coeffA, int *coeffB, int *coeffC, int *lowerBound, int *upperBound, int *steps);
double getTrapSum(int coeffA, int coeffB, int coeffC, int lowerBound, int upperBound, int steps);
double forceFunction(int coeffA, int coeffB, int coeffC, double  x);
double forceFunctionIntegral(int coeffA, int coeffB, int coeffC, int  x);
double getIntegralSum(int coeffA, int coeffB, int coeffC, int lowerBound, int upperBound);
void outputs(double trapSum, double integralSum, int steps);

int main()
{

  //Initialization
  int coeffA;   //Coefficient of A
  int coeffB;   //Coefficent of B
  int coeffC;   //Coefficient of C
  int lowerBound;   //Lower bound value of work
  int upperBound;   //Upper bound value of work
  int steps;        //How many trapezoidal steps the user wants to use
  double trapSum;   //Work using trapezoidal sum approximation
  double integralSum;   //Work using an integral 

  //Inputs
  inputs(&coeffA, &coeffB, &coeffC, &lowerBound, &upperBound, &steps);

  //Calculations
  trapSum = getTrapSum(coeffA, coeffB, coeffC, lowerBound,  upperBound,  steps);
  integralSum = getIntegralSum(coeffA, coeffB, coeffC, lowerBound, upperBound);

  //Outputs
  outputs( trapSum,  integralSum,  steps);

  return 0;

}

/******************************************************************************
* Function:    inputs()
* Description: prompts user for inputs and stores them
* Parameters:  coeffA, int, and coefficient for A
*              coeffB, int, and coefficient for B
*              coeffC, int, and the coefficient for C
*              lowerBound, int, and the lower bound of the integral
*              upperBound, int, and the upper bound of the integral
*              steps, int, and the amount of steps user wants to use for trapezoid approximation
*              
* Return:      nothing
******************************************************************************/

void inputs(int *coeffA, int *coeffB, int *coeffC, int *lowerBound, int *upperBound, int *steps)
{

  //Print and get intputs
  printf("Enter coefficient A -> ");
  scanf("%d", coeffA);
  printf("Enter coefficient B -> ");
  scanf("%d", coeffB);
  printf("Enter coefficient C -> ");
  scanf("%d", coeffC);
  printf("Enter lower bound -> ");
  scanf("%d", lowerBound);

  //Check if upper bound is greater than the lower bound
  do
  {
    printf("Enter upper bound -> ");
    scanf("%d", upperBound);
    if (*upperBound <= *lowerBound)
    {  
      printf("\nError: upper bound must be greater than lower bound!\n\n");
    }

  } while(*upperBound <= *lowerBound);
  printf("Enter number of steps for trapezoidal sum -> ");
  scanf("%d", steps);
  return;

}

/******************************************************************************
* Function:    getTrapSum()
* Description: gets the trapezoid work approximation
* Parameters:  coeffA, int, and coefficient for A
*              coeffB, int, and coefficient for B
*              coeffC, int, and the coefficient for C
*              lowerBound, int, and the lower bound of the integral
*              upperBound, int, and the upper bound of the integral
*              steps, int, and the amount of steps user wants to use for trapezoid approximation
*              
* Return:      double trapezoid work approximation
******************************************************************************/

double getTrapSum(int coeffA, int coeffB, int coeffC, int lowerBound, int upperBound, int steps)
{

  double deltaX;    // Change in the x value
  double xValue;    // X value that is plugged into the Force equation
  double xValuePlusOne;   // X value after the current x Value for the force equation
  double totalWork;   //Total work of the equation
  double work;  //Work in 1 iteration
  int i;    //Number of interations
  deltaX = (double)(upperBound - lowerBound) / steps;
  totalWork = 0;
  for ( i = 0; i < steps; i++)
  {
    xValue = lowerBound + deltaX * i;
    xValuePlusOne = xValue + deltaX;
    work = ((double) (forceFunction(coeffA, coeffB, coeffC, xValue) + forceFunction(coeffA, coeffB, coeffC, xValuePlusOne)) / 2) * deltaX;
    totalWork += work; 
  }
  return totalWork;
}

/******************************************************************************
* Function:    forceFunction())
* Description: uses the force function and an x to find the force
* Parameters:  coeffA, int, and coefficient for A
*              coeffB, int, and coefficient for B
*              coeffC, int, and the coefficient for C
*              x, double, and the inputted x to use
*              
* Return:      double, and the Force 
******************************************************************************/

double forceFunction(int coeffA, int coeffB, int coeffC, double  x)
{
  double force;   //Force using the equation
  force = coeffA * pow(x,2) + coeffB * x + coeffC;
  return force;

}

/******************************************************************************
* Function:    forceFunctionIntegral()
* Description: uses the integral of force function to get a value
* Parameters:  coeffA, int, and coefficient for A
*              coeffB, int, and coefficient for B
*              coeffC, int, and the coefficient for C
*              x, int, and the inputted x to use
*              
* Return:      double, and the integration of force (work)
******************************************************************************/

double forceFunctionIntegral(int coeffA, int coeffB, int coeffC, int  x)
{

  return ((double)coeffA / 3) * (pow(x,3)) + ((double)coeffB / 2) * (pow(x,2)) + coeffC * x;

}

/******************************************************************************
* Function:    getIntegralSum()
* Description: gets the actual value of work with an integral
* Parameters:  coeffA, int, and coefficient for A
*              coeffB, int, and coefficient for B
*              coeffC, int, and the coefficient for C
*              lowerBound, int, and the lower bound of the integral
*              upperBound, int, and the upper bound of the integral
*              steps, int, and the amount of steps user wants to use for trapezoid approximation
*              
* Return:      double actual work value using integration
******************************************************************************/

double getIntegralSum(int coeffA, int coeffB, int coeffC, int lowerBound, int upperBound)
{

  double Adouble;       //Double version of A coefficient  
  double Bdouble;       //Double version of B coefficient
  double Cdouble;       //Double version of C coefficent
  double lb;            //Double version of lower bound
  double ub;            //Double version of upper bound
  double integralSum;   //work using integral
  Adouble = coeffA; 
  Bdouble = coeffB;
  Cdouble = coeffC; 
  lb = lowerBound;
  ub = upperBound;
  printf("\nIntegral of: (%.3lf) x^2 + (%.3lf) x + (%.3lf)\n", Adouble, Bdouble, Cdouble);
  printf("From x: %.3lf to %.3lf\n\n", lb, ub);
  integralSum = forceFunctionIntegral(coeffA, coeffB, coeffC, upperBound) - forceFunctionIntegral(coeffA, coeffB, coeffC, lowerBound);
  return integralSum;

}

/******************************************************************************
* Function:    outputs()
* Description: prints out the outputs to the screen
* Parameters:  trapSum, double, and summation using trapezoid method
*              integralSum, double, and actual work value using integration
*              steps, int, and amount of steps for the trapezoid method
*              
* Return:      double, and the Force 
******************************************************************************/

void outputs(double trapSum, double integralSum, int steps)
{

  double error;   //Percent error of the integral vs trapezoin methods
  error = ((trapSum - integralSum) / integralSum) * 100;
  printf("Using trapezoidal sum with %d steps: %.3lf\n", steps, trapSum);
  printf("Using exact equation: %.3lf\n", integralSum);
  printf("Trapezoidal sum error: %.2lf%%\n", error);

}