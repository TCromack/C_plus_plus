/*
 * Name: Tyler Cromack
 * Date: 3/2/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#4 Occurrence of Max Numbers
 * This program will find the Occurrence of the greatest Number and display it.
 */

#include <iostream>
using namespace std;

int main ()
{
char doOver ='Y';

while (doOver == 'Y' || doOver == 'y')	
{
		int max = 0;
        int count;
        int number;
        
		cout << "Welcome to Occurrence of Max Numbers V1.0 By: Tyler Cromack\n\n";
		cout << "Enter 0 to end the input!\n";
		cout << "-------------------------\n";
        
        do {
            cout<<"Enter number: "; cin >> number;
            if (number > max) 
			{
                
                max = number;
                count = 1;
            }
            else if (number == max) 
			{
                count++;
            }
        } while (number != 0);
		
		system("CLS");
	//Print result	
		if(max==0)
	 	{
          	cout << "The largest number is: " << max;
			cout << "\n\n" << max << " Occurs 1 time.\n";
    	}
    	else
		{
    		cout << "The largest number is: " << max;
			cout << "\n\n" << max << " Occurs " << count << " times.\n";
		}
	
	//Ask if user wants to run program again	
	cout << "\nRun the program again? [y/N] "; cin >> doOver;
	cin.clear();
	cin.ignore(100 , '\n');
	system("CLS");	
}
	system("PAUSE");
	return 0;
}
