/******************************************************************************
* Assignment:  HW03
* Lab Section: Tuesday, 11:20, SC 189
* Description: This lab takes inputs from a students averages and the weights for the class and it prints out their final scores and grades. 
* Programmers: Dante Sanaei dsanaei@purdue.edu

******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define PERFECT_SCORE 100.0
#define NO_SCORE 0.0
#define A_CUTOFF 90
#define B_CUTOFF 80
#define C_CUTOFF 70
#define D_CUTOFF 60
#define F_ASKII 70
#define PLUS 43
#define MINUS 45

int getPlus(double );
int getMinus(double );
int getCourseGrade(double);
int getLetter(int, int, int, int);
int getHundred(double );
int getF(double);
void printInput(double *hwWeight,double *hwAvg,double *labWeight,double *labAvg,double *quizWeight,double *quizAvg,double *midtWeight,double *midtAvg);
double getFinalWeight(double hwWeight, double quizWeight, double labWeight, double midtWeight);
double getPercent(double hwWeight, double quizWeight, double labWeight, double midtWeight, double hwAvg, double quizAvg, double labAvg, double midtAvg, double finalWeight, double score);
int getPrecision(double midtPercent);
void printOutput(double hwWeight, double hwAvg, double labWeight, double labAvg, double quizWeight, double quizAvg, double midtWeight, double midtAvg, double finalWeight, int precision, double perfectPercent, double midtPercent, double zeroPercent);

int main(void)
{
  //Initializations
  double hwWeight;        //Weight of the homework
  double hwAvg;           //Average homework grade
  double labWeight;       //Weight of the labs
  double labAvg;          //Average lab grade
  double quizWeight;      //Weight of the quizzes
  double quizAvg;         //Average quiz grade
  double midtWeight;      //Weight of the midterms
  double midtAvg;         //Average midterm grade
  double finalWeight;     //Weight of the final exam
  double perfectPercent;  //Final course grade for a perfect final exam score(100%)
  double midtPercent; 	  //Final course grade if final score is the same as the midterm average
  double zeroPercent; 	  //Final course grade if final score is 0%
  int precision;          //Precision of the final course percentage
  
  //Inputs
  printInput(&hwWeight, &hwAvg, &labWeight, &labAvg, &quizWeight, &quizAvg, &midtWeight, &midtAvg);

  //Calculations
  finalWeight = getFinalWeight( hwWeight, quizWeight,labWeight, midtWeight);
  perfectPercent = getPercent( hwWeight,  quizWeight, labWeight, midtWeight, hwAvg, quizAvg, labAvg, midtAvg, finalWeight, PERFECT_SCORE);
  midtPercent = getPercent( hwWeight, quizWeight, labWeight, midtWeight, hwAvg, quizAvg, labAvg, midtAvg, finalWeight, midtAvg);
  zeroPercent = getPercent( hwWeight, quizWeight, labWeight, midtWeight, hwAvg, quizAvg, labAvg, midtAvg, finalWeight, NO_SCORE);
  precision =  getPrecision(midtPercent);
 
  //Outputs
  printOutput(hwWeight, hwAvg, labWeight, labAvg, quizWeight, quizAvg, midtWeight, midtAvg, finalWeight, precision, perfectPercent, midtPercent, zeroPercent);

  return 0;
}
/******************************************************************************
* Function:    getPlus()
* Description: returns either 0 or 1 depending on if the grade has a +
* Parameters:  grade, double, and final course grade
*              
* Return:      int and returns 1 if grade has a +, and 0 if it does not
******************************************************************************/
int getPlus(double grade)
{
  int lastDigit;			//Last digit of the course grade
  int plus;					//logical plus operator
  lastDigit = (int) grade % 10;
  plus = lastDigit / 7;
  return plus; 
}
/******************************************************************************
* Function:    getMinus()
* Description: returns either 0 or 1 depending on if the grade has a -
* Parameters:  grade, double, and final course grade
*              
* Return:      int and returns 1 if grade has a -, and 0 if it does not
******************************************************************************/
int getMinus(double grade)
{
  int lastDigit;  				// Last digit of the course grade
  int modifiedDig;				// Modified Digit
  int minus;					// Minus logical operator
  int hundred;					// hundred logical operator
  lastDigit = (int) grade % 10;
  modifiedDig = 10 - lastDigit;
  minus = modifiedDig / 8;
  hundred = (int) grade / 100;
  hundred = abs(hundred - 1);
  return minus * hundred;
}
/******************************************************************************
* Function:    getHundred()
* Description: returns either 0 or 1 depending on if the grade is a 100
* Parameters:  grade, double, and final course grade
*              
* Return:      int and returns 1 if grade is 100, and 0 if it is not
******************************************************************************/
int getHundred(double grade)
{
  int hundred;					// Hundred logical operator
  hundred = (int) grade / 100;
  return hundred;
}
/******************************************************************************
* Function:    getCourseGrade()
* Description: returns course grade letter
* Parameters:  percentage, double, and percentage final grade
*              
* Return:      char and letter grade
******************************************************************************/
int getCourseGrade(double percentage)
{
  int totalPoints;				// Total points
  int gradePoints;				// Points for each grade
  int courseGrade;				// Course letter grade
  totalPoints = (int) percentage;
  gradePoints = totalPoints / A_CUTOFF;
  gradePoints += totalPoints / B_CUTOFF;
  gradePoints += totalPoints / C_CUTOFF;
  gradePoints += totalPoints / D_CUTOFF;
  courseGrade = F_ASKII - gradePoints;
  courseGrade -= totalPoints / D_CUTOFF;
  return courseGrade;
}  
/******************************************************************************
* Function:    getF()
* Description: returns either 0 or 1 depending on if the grade is an F
* Parameters:  percentage, double, and final course grade
*              
* Return:      int and returns 0 if grade is an F, and 1 if it does not
******************************************************************************/
int getF(double percentage)
{
  int totalPoints;				// total points of the student
  totalPoints = (int) percentage;
  return totalPoints / D_CUTOFF;
}
/******************************************************************************
* Function:    getLetter()
* Description: returns the plus or minus that accompanies the letter grade
* Parameters:  plus, int, and plus logical value
*              minus, int, and minus logical value
*			   hundred, int, and hundred logical value
*	   		   Ftrue, int, and Ftrue logical value
				
* Return:      int and returns plus or minus
******************************************************************************/
int getLetter(int plus, int minus, int hundred, int Ftrue)
{
  return (plus * PLUS + minus * MINUS + hundred * PLUS) * Ftrue;
}
/******************************************************************************
* Function:    printInput()
* Description: prints and scans user input
* Parameters:  hwWeight, double, and weight of homework
*              hwAvg, double, and average of HW grade
*			   labWeight, double, and weight of labs
*	   		   labAvg, double, and lab average
*			   quizWeight, double, and weight of quizzes
*              quizAvg, double, and average of quizzes
*			   midtWeight, double, and weight of midterms
*	   		   midtAvg, double, and midterm average			
* Return:      void and returns nothing
******************************************************************************/
void printInput(double *hwWeight,double *hwAvg,double *labWeight,double *labAvg,double *quizWeight,double *quizAvg,double *midtWeight,double *midtAvg)
{
  printf("Homework weight (%%)-> ");
  scanf("%lf", hwWeight);
  printf("Homework average -> ");
  scanf("%lf", hwAvg);
  printf("\nLab weight (%%)-> ");
  scanf("%lf", labWeight);
  printf("Lab average -> ");
  scanf("%lf", labAvg);
  printf("\nQuiz weight (%%)-> ");
  scanf("%lf", quizWeight);
  printf("Quiz average -> ");
  scanf("%lf", quizAvg);
  printf("\nMidterm weight (%%)-> ");
  scanf("%lf", midtWeight);
  printf("Midterm average -> ");
  scanf("%lf", midtAvg);
  return;
}
/******************************************************************************
* Function:    getFinalWeight()
* Description: gets final weight
* Parameters:  hwWeight, double, and weight of homework
*			   labWeight, double, and weight of labs
*			   quizWeight, double, and weight of quizzes
*			   midtWeight, double, and weight of midterms
* Return:      double and returns the final weight
******************************************************************************/
double getFinalWeight(double hwWeight, double quizWeight, double labWeight, double midtWeight)
{
  return 100 - hwWeight - quizWeight - labWeight - midtWeight;
}
/******************************************************************************
* Function:    printInput()
* Description: prints and scans user input
* Parameters:  hwWeight, double, and weight of homework
*              hwAvg, double, and average of HW grade
*			   labWeight, double, and weight of labs
*	   		   labAvg, double, and lab average
*			   quizWeight, double, and weight of quizzes
*              quizAvg, double, and average of quizzes
*			   midtWeight, double, and weight of midterms
*	   		   midtAvg, double, and midterm average	
*			   score, double, score that is factored in		
* Return:      double and returns percent score
******************************************************************************/
double getPercent(double hwWeight, double quizWeight, double labWeight, double midtWeight, double hwAvg, double quizAvg, double labAvg, double midtAvg, double finalWeight, double score)
{
  return (hwWeight / 100) * hwAvg + (labWeight / 100) * labAvg + (quizWeight / 100) * quizAvg + (midtWeight / 100) * midtAvg + (finalWeight / 100) * score;
}
/******************************************************************************
* Function:    getPrecision()
* Description: returns the int value of the precision of the course grade
* Parameters:  midtPercent, double, and midterm percentage
*              
* Return:      int and returns precision
******************************************************************************/
int getPrecision(double midtPercent)
{
  int decimalPlaceINT;					// Decimal Place of the integer
  decimalPlaceINT = midtPercent * 10;
  return (decimalPlaceINT % 10) / 2;
}  
/******************************************************************************
* Function:    printOutput()
* Description: prints the output of the program
* Parameters:  hwWeight, double, and weight of homework
*              hwAvg, double, and average of HW grade
*			   labWeight, double, and weight of labs
*	   		   labAvg, double, and lab average
*			   quizWeight, double, and weight of quizzes
*              quizAvg, double, and average of quizzes
*			   midtWeight, double, and weight of midterms
*	   		   midtAvg, double, and midterm average		
*			   precision, int, and precision of the course percentage
*              perfectPercent, double, percentage with perfect score
*              midtPercent, double, percentage with midterm score	
*              zeroPercent, double, percentage with zero score	
* Return:      void and returns nothing
******************************************************************************/
void printOutput(double hwWeight, double hwAvg, double labWeight, double labAvg, double quizWeight, double quizAvg, double midtWeight, double midtAvg, double finalWeight, int precision, double perfectPercent, double midtPercent, double zeroPercent)
{
  printf("\nCategory  Course Weight  Total Earned\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Homework:%9.1lf%%%13.1lf%%\n", hwWeight, hwAvg); 
  printf("Labs:%13.1lf%%%13.1lf%%\n", labWeight, labAvg); 
  printf("Quizzes:%10.1lf%%%13.1lf%%\n", quizWeight, quizAvg); 
  printf("Midterms:%9.1lf%%%13.1lf%%\n", midtWeight, midtAvg); 
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("          Course Weight  Total Earned  Course Percentage  Grade\n");
  printf("Final Exam:%7.1lf%%%13.1lf%%%16.*lf%%%11c%c\n", finalWeight, PERFECT_SCORE, precision, perfectPercent, getCourseGrade(perfectPercent), getLetter(getPlus(perfectPercent), getMinus(perfectPercent), getHundred(perfectPercent), getF(perfectPercent)));
  printf("Final Exam:%7.1lf%%%13.1lf%%%16.*lf%%%11c%c\n", finalWeight, midtAvg, precision, midtPercent, getCourseGrade(midtPercent), getLetter(getPlus(midtPercent), getMinus(midtPercent), getHundred(midtPercent), getF(midtPercent)));
  printf("Final Exam:%7.1lf%%%13.1lf%%%16.*lf%%%11c%c\n", finalWeight, NO_SCORE, precision, zeroPercent, getCourseGrade(zeroPercent), getLetter(getPlus(zeroPercent), getMinus(zeroPercent), getHundred(zeroPercent), getF(zeroPercent)));
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return;
}
  
  
  
  
  
  
