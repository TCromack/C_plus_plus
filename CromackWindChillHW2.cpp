/*
 * Name: Tyler Cromack
 * Date: 2/11/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#2 Wind Chill
 * This program will find the Windchill from user input
 */
 
#include<iomanip>
#include <iostream>
#include <math.h>
using namespace std;

//Calculate WindChill function
double getWindChill(double temperature, double windSpeed)
{
    double calcChill (35.74 + (0.6215 * temperature) - (35.75 * pow(windSpeed,0.16)) + (0.4275 * temperature * pow(windSpeed,0.16)));
    return calcChill;
}

int main()
{
	double windSpeed, temperature, windChill;
	char doOver ='Y';
		
while (doOver == 'Y' || doOver == 'y')	
{
	cout << "Welcome to Wind Chill Calculator V1.0 By: Tyler Cromack\n\n";
	
//Prompts User for Temperature
	do
	{
		cout << "Enter the Temperature(Fahrenheit): ";
		while (!(cin >> temperature))
		{
			cout << "\nINPUT MUST BE A NUMBER!\n";
			cout << "\nEnter the Temperature(Fahrenheit): ";
			cin.clear();
			cin.ignore(100 , '\n');
		}
		
		if (temperature <=-58 || temperature >=41)
		cout << "\nTEMPERATURE MUST HAVE A VALUE BETWEEN -57 AND 40 FAHRENHEIT!\n\n";
	} while(temperature <= -58 || temperature >= 41);
	
//Prompts for User for Windspeed
	do
	{
		cout << "\nEnter the Wind Speed(Mph): ";
		while (!(cin >> windSpeed))
		{
			cout << "\nINPUT MUST BE A NUMBER!\n";
			cout << "\nEnter the Wind Speed(Mph): ";
			cin.clear();
			cin.ignore(100 , '\n');
		}	
		
		if (windSpeed <= 2)
		cout << "\nWIND SPEED MUST BE AT LEAST 3 MPH!\n";
	} while(windSpeed <= 2);
	
//Print WindChill
	windChill = getWindChill(temperature,windSpeed);
	system("CLS");
	cout << setprecision(2) << fixed;
	cout << "The Wind Chill is: " << windChill << " Fahrenheit\n";
	
//Ask if user wants to run program again	
	cout << "\nRun the program again? [y/N] "; cin >> doOver;
	cin.clear();
	cin.ignore(100 , '\n');
	system("CLS");	
}
	system("PAUSE");
	return 0;
}
