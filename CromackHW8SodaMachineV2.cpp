/*
 * Name: Tyler Cromack
 * Date: 5/7/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#8 Soda Machine
 * This program will take input and simulate a Soft Drink Machine
 */

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Machine
{
string name;
double cost;
int num;
};

void count(Machine& d, string n , double c, int num);
int menu(Machine d[]);
void payment(double p);

int main()
{
	Machine drink[5];
	int choice = 0;
	double sales = 0;
	count(drink[0], "Cola", 0.85, 20);
	count(drink[1], "Root Beer", 0.75, 20);
	count(drink[2], "Lemon-Lime", 0.90, 20);
	count(drink[3], "Grape Soda", 0.80, 20);
	count(drink[4], "Cream Soda", 0.80, 20);
	choice = menu(drink);

	while(choice != 5)
	{
		payment(drink[choice].cost);
		sales += drink[choice].cost;
		drink[choice].num--;
		choice = menu(drink);
	}
	
	cout << "\nMachine Sales: $" << setprecision(2) << fixed << sales << "\n" << endl;

	for(int i = 0; i < 5; i++)
	{
		 if(drink[i].num == 0)
    	{
    		cout << drink[i].name << " IS SOLD OUT!" << endl;
		}
	}

	system("PAUSE");
	return 0;
}

void count(Machine& d, string n, double c, int num)
{
	d.cost = c;
	d.name = n;
	d.num = num;
}

int menu(Machine d[])
{ 
	int choice;
	
	bool soldout = true;
	while((choice < 1 || choice > 6) || soldout)
	{
		soldout = false;
		cout << "\n    Drink Name     Cost\t    #Inventory\n----------------------------------------\n";
	
		for(int i=0 ; i<5 ; i++)
		{
		cout << i+1<<".) " << setw(15) << left << d[i].name << setw(5);
		cout << setprecision(2) << fixed << d[i].cost << "\t" << d[i].num << endl;
		}
	
		cout << "6.) QUIT\n";
		cout << "\nEnter Choice: ";
		cin >> choice;
	
		if(choice == 6)
		{
			break;
		}
		
		if(choice < 1 || choice > 6)
		{	system("cls");
			cout << "\nINVALID INPUT!\n";
		}
		
		if(d[choice-1].num == 0)
		{	system("cls");
			cout << "\nSOLD OUT!\n";
			soldout = true;
		}
			
	}	
	return choice - 1;
}

void payment(double p)
{
	double pay;
	system("cls");
	cout << "The price is $" << setprecision(2) << fixed << p << endl;
	cout << "Enter payment amount: ";
	cin >> pay;
	
	while(pay < 0 || pay > 1|| pay < p)
	{
	system("cls");
	cout << "No change accepted over $1.00\n";
	cout << "Enter payment amount: ";
	cin >> pay;
	}
	
	cout << "Your change is: $" << setprecision(2) << fixed << pay - p << endl;
	return;
}
