/*
 * Name: Tyler Cromack
 * Date: 2/17/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#3 Wireless Service Provider
 * This program will find the best Wireless plan and calculate their monthly bill.
 * The Problem given allows for many logic errors. I've shown an example above the switch statement.
 */

#include<iomanip>
#include <iostream>
using namespace std;

int main ()
{
int data;	
char package;

double a = 29.99;
double b = 39.99;
double c = 49.99;
char doOver ='Y';

while (doOver == 'Y' || doOver == 'y')	
{
cout << "Welcome to Wireless Service Bill Calculator V1.0 By: Tyler Cromack\n\n";	
cout << "Package A: For $29.99 per month 2GB of data is provided."
		<< " Additonal data is $10.00 per GB.\n"
   		<<"Package B: For $39.99 per month 4GB of data is provided."
		<< " Additonal data is $5.00 per GB. \n"
		<<"Package C: For $49.99 per month unlimited data is provided.\n";
	
	cout << "\nPlease enter the letter of your internet package: "; cin >> package;
		
	while (package != 'A' && package !='a' && package !='B' && package !='b'&& package !='C' && package !='c')
		{
		cout << "\nINPUT MUST BE A LETTER A, B, or C!\n";
		cin.clear();
		cin.ignore(100 , '\n');
		cout << "\nPlease enter the letter of your internet package: "; cin >> package;
		}
			
	do
	{
		cout <<"\nPlease enter how much data you have used this month: "; 
		while (!(cin >> data))
		{
			cout << "\nINPUT MUST BE A NUMBER GREATER THAN 0 AND LESS THAN 51\n";
			cout << "\nPlease enter how much data you have used this month: ";
			cin.clear();
			cin.ignore(100 , '\n');
		} 
	
		if (data < 1 || data > 50)
		cout << "\nINPUT MUST BE A NUMBER GREATER THAN 0 AND LESS THAN 51\n";			
	} while(data < 1|| data > 50);
	
//The given Problem allows for logic errors to occur A and B variables are allowed to be negative 
//Ex. Customer has package B, Uses 3 GB of Data per billing cycle b = 39.99 + 5 * ( x - 4) therefore b = 39.99 + 5 * ( 3 - 4 ), data now is -1 allowing B to = 34.99 when b should = 39.99.
//Other values cause these logic errors as well, I used if statements to avoid as many as possible but many are still possible.
system("CLS");
cout << setprecision(2) << fixed;
switch(package)
{
	
	case 'a':
	case 'A':
		
		if (data < 2)
		{
			cout << "Your total cost is: $29.99";
		}
		else
		{
		a += 10 * (data - 2);
		cout << "Your total cost is: $" << a ;
		}
		if(a > b)
		{
			cout << "\n\nIf you switch to plan B you will save $" << a - b ;
		}
		else if(a > c)
		{
			cout << "\n\nIf you switch to plan C you will save $" << a - c ;
		}
		break;

	case 'b':
	case 'B':
			
		if (data < 4)
		{
			cout << "Your total cost is: $39.99";
		}
		else
		{	
		b += (5 * (data - 4));
		cout << "Your total cost is: $" << b;
		}
		if(b > a)
		{
			cout << "\n\nIf you switch to plan A you will save $" << b - a ;
		}
		else if(b > c)
		{
			cout << "\n\nIf you switch to plan C you will save $" << a - c ;
		}
		break;

	case 'c':
	case 'C':
			
		if (data < 6)
		{
			cout << "Your total cost is: $49.99";
		}
		else
		{
		a += 10 * (data - 2);	
		cout << "Your total cost is: $" << c ;
		}
		if(c > b)
		{
			cout << "\n\nIf you switch to plan B you will save $" << c - b ;
		}
		else if(c > a)
		{
			cout << "\n\nIf you switch to plan A you will save $" << c - a ;
		}
		break;
			
		default:
			cout << "\nINVALID INPUT! ";
		break;
}
	cout << "\n\nRun the program again? [y/N] "; cin >> doOver;
	cin.clear();
	cin.ignore(100 , '\n');
	system("CLS");
}
	system("PAUSE");
	return 0;
}
