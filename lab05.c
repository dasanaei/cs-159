/******************************************************************************
* Assignment:  Lab 5
* Lab Section: 11453
* Description: This program takes inputs from the user and finds the flight speed in m/s and mach of an aircraft. It also outputs the flight regime. 
* Programmers: Dante Sanaei dsanaei@purdue.edu
*              Jessica Townsend townse23@purdue.edu
*              Michael Yu yu611@purdue.edu
******************************************************************************/
#include <stdio.h>
#include <math.h>
#define RHO_NOT 1.225
#define T_NOT 288.15
#define R  287
#define GAMMA 1.4
#define LAPSE -6.5 * pow(10,-3)
#define GRAVITY 9.81

void input(double *altitude, double *fAngle, double *zlAngle, double *wingSpan, double *wingChord, double *mass);
double getTemp(double);
double getDensity(double);
double getSound(double);
double getLiftC(double , double );
double getVelocity(double,double, double, double, double);
double getMach(double, double);
char getRegime(double );
void printOutput(double, double, double, double, double, char);

int main(void)
{
  //Initialization
  double altitude;							// Altitude of the flight (m)
  double fAngle;							// Flight angle of the wings (degrees)
  double zlAngle;							// zero-lift angle of the wings (degrees)
  double wingSpan;							// wing span (m)
  double wingChord;							// wing chord (m)
  double mass;								// mass of the aircraft (kg)
  double speedSound;						// speed of sound (m/s)
  double temperature;						// temperature (K)
  double density;							// density of the air (kg/m^3)
  double speed;								// speed of the aircraft (m/s)
  double mach;								// mach number
  char regime;								// Flight regime 
  double liftC;								// lift coefficient (radians)
  
  //Inputs
  input(&altitude, &fAngle, &zlAngle, &wingSpan, &wingChord, &mass);
  
  //Calculations
  temperature = getTemp(altitude);
  density = getDensity(temperature);
  speedSound = getSound(temperature);
  liftC = getLiftC(fAngle, zlAngle);
  speed = getVelocity(density, mass, wingSpan, wingChord, liftC);
  mach = getMach(speed, speedSound);
  regime = getRegime(mach);
  
  //output
  printOutput( temperature, speedSound, density, speed, mach, regime);
  
  return 0;
}

/******************************************************************************
* Function:    input()
* Description: Prints input commands and takes in the inputs from the user
* Parameters:  altitude, double, and Altitude of the flight (m)
*              fAngle, double, and Flight angle of the wings (degrees)
*			   zlAngle, double, and zero-lift angle of the wings (degrees)
*	   		   wingSpan, double, and wing span (m)
*			   wingChord, double, and wing chord (m)
*              Mass, double, and mass of the aircraft (kg)
* Return:      void
******************************************************************************/

void input(double *altitude, double *fAngle, double *zlAngle, double *wingSpan, double *wingChord, double *mass)
{
  printf("Enter flight altitude (m) -> ");
  scanf("%lf", altitude);
  printf("Enter flight angle (degrees) -> ");
  scanf("%lf", fAngle);
  printf("Enter zero-lift angle (degrees) -> ");
  scanf("%lf", zlAngle);
  printf("Enter wing span (meters) -> ");
  scanf("%lf", wingSpan);
  printf("Enter wing chord (meters) -> ");
  scanf("%lf", wingChord);
  printf("Enter aircraft mass (kg) -> ");
  scanf("%lf", mass);
  return;
}

/******************************************************************************
* Function:    getTemp()
* Description: find the temperature of the air
* Parameters:  altitude, double, and Altitude of the flight (m)
*            
* Return:      double and the temperature of the air
******************************************************************************/

double getTemp(double altitude)
{
  return T_NOT + LAPSE * altitude;
}

/******************************************************************************
* Function:    getDensity()
* Description: finds the density of the air 
* Parameters:  temperature, double, and air temperature (K)
*
* Return:      double and density of the air
******************************************************************************/

double getDensity(double temperature)
{
  return pow((temperature / T_NOT), -(GRAVITY / (LAPSE * R) + 1)) * RHO_NOT;
}

/******************************************************************************
* Function:    getSound()
* Description: finds the speed of sound
* Parameters:  temperature, double, and air temperature (K)
*
* Return:      double and speed of sound in the air
******************************************************************************/

double getSound(double temperature)
{
  return sqrt(GAMMA * R * temperature);
}

/******************************************************************************
* Function:    getLiftC()
* Description: finds the coefficient of lift
* Parameters:  fAngle, double, and Flight angle of the wings (degrees)
*			   zlAngle, double, and zero lift angle of the wings (degrees)
* Return:      double and lift coefficient in degrees
******************************************************************************/

double getLiftC(double fAngle, double zlAngle)
{
  return 2 * M_PI * (fAngle - zlAngle);
}

/******************************************************************************
* Function:    getVelocity()
* Description: gets the speed of the aircraft in m/s
* Parameters:  density, double, density of air
*              mass, double, mass of the aircraft (kg)
*	   		   wingSpan, double, and wing span (m)
*			   wingChord, double, and wing chord (m)
*              liftC, double, and coefficient of lift in degrees
* Return:      void
******************************************************************************/

double getVelocity(double density, double mass, double span, double chord, double liftC)
{
  double lift;				// Lift of the aircraft (N)
  double surfaceArea;		// Surface area of the wings
  lift = GRAVITY * mass;
  surfaceArea = span * chord;
  return sqrt(lift / (.5 * density * (liftC * (M_PI / 180)) * surfaceArea));
}

/******************************************************************************
* Function:    getMach()
* Description: finds the mach number 
* Parameters:  velocity, double, and speed of the plane in m/s
*			   sound, double, and speed of sound in m/s
* Return:      double and mach number
******************************************************************************/

double getMach(double velocity, double sound)
{
  return velocity / sound;
}

/******************************************************************************
* Function:    getRegime()
* Description: finds the regime letter 
* Parameters:  mach, double, and mach number of the plane
*
* Return:      char and regime letter
******************************************************************************/

char getRegime(double mach)
{
  int Mach;				// Mach number multiplied by 10
  int bLetter;			// logical gate that will make the regime B
  int tLetterFINAL;		// logical gate that will make the regime T
  int Pletter;			// logical gate that will make the regime P
  int tLetterP1;		// Logical gate that is necessary for tLetterFinal to be true
  int tLetterP2;		// Logical gate that is necessary for tLetterFinal to be true
  int safety;			// Keeps the system from failing for numbers over 1.4
  
  Mach =  (int) (mach * 10);
  bLetter = -((Mach / 7) - 1);
  tLetterP1 = Mach / 7;
  tLetterP2 = -((Mach / 12) - 1);
  tLetterFINAL = tLetterP1 * tLetterP2;
  Pletter = Mach / 12;
  safety = -((Mach / 14) - 1);
  return 66 * bLetter * safety + 84 * tLetterFINAL * safety + 80 * Pletter;
}

/******************************************************************************
* Function:    printOutput()
* Description: Prints outputs of the code
* Parameters:  temperature, double, and temperature (K)
*              speedSound, double, and speed of sound in the air (m/s)
*			   density, double, and density of the air
*	   		   speed, double, and speed of the plane (m/s)
*			   mach, double, and mach number of the plane
*              regime, char, and the regime letter 
* Return:      void
******************************************************************************/

void printOutput(double temperature, double speedSound, double density, double speed, double mach, char regime)
{
  printf("\nAtmospheric details\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Temperature (K):%17.2lf\n", temperature);
  printf("Speed of Sound (m/s):%12.2lf\n", speedSound);
  printf("Density (kg/m^3):%16.2lf\n\n", density);
  printf("Flight details\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Flight Speed (m/s):%14.2lf\n", speed);
  printf("Mach Number:%21.2lf\n", mach);
  printf("Flight Regime:%19c\n", regime);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return;
}