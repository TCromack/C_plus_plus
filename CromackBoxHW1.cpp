/*
 * Name: Tyler Cromack
 * Date: 1/30/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#1 Rectangular Prism
 * This program will find the surface area of the rectangular prism
 */

#include <iostream>
#include <stdexcept>
using namespace std;

//***************************************************************************
//Surface Area Function
float getSurfaceArea(float length, float width, float height)
{
    return (2 *(length * width + length * height + width * height));
}

//***************************************************************************

int main()
{
float length,width,height,surfaceArea;

//Prompts for User for Input
cout << "Enter a positve non-zero integer for the dimensions of the rectangular prism.\n";

//Prompt for length and check to see if user input is valid 
cout << "\nLength: ";	cin >> length;
if (length < 0)
{
	throw invalid_argument("YOU HAVE ENTERED AN INTEGER VALUE THAT IS NOT A POSITIVE NON-ZERO INTEGER! \n\n\t   CLOSE THE PROGRAM AND TRY AGAIN!");
}

//Prompt for width and check to see if user input is valid 
cout << "\nWidth: "; cin >> width;
if (width < 0)
{
	throw invalid_argument("YOU HAVE ENTERED AN INTEGER VALUE THAT IS NOT A POSITIVE NON-ZERO INTEGER! \n\n\t   CLOSE THE PROGRAM AND TRY AGAIN!");
}

//Prompt for height and check to see if user input is valid 
cout << "\nHeight: "; cin >> height; 
if (height < 0)
{
	throw invalid_argument("YOU HAVE ENTERED AN INTEGER VALUE THAT IS NOT A POSITIVE NON-ZERO INTEGER! \n\n\t   CLOSE THE PROGRAM AND TRY AGAIN!");
}


surfaceArea = getSurfaceArea(length, width, height);

cout << "\nThe surface area of the rectangular prism = " << surfaceArea <<" units.\n" <<endl;

system("PAUSE");
return 0;
}


