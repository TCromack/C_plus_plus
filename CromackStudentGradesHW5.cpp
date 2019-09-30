/*
 * Name: Tyler Cromack
 * Date: 4/8/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#5 Student Grades
 * This program will calculate Student grade averages and display them.
 */

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

char calc_grade(float avg);

    int main()
    {
    	char c;
		char grade;
        char fName[20];
        char lName[20];
        int grades;
        int lines=-20;
        float avg;
        
        fstream inFile("Class.txt",ios::in);
        if(!inFile){cerr<<"FILE NOT FOUND!";exit(1);}

        fstream outFile("Grades.txt",ios::out);
        if(!outFile){cerr<<"ERROR CREATING FILE!";exit(1);}

		cout << "---------------------------------------------------------------------------------" << endl;
		cout << " Student                 Test1   Test2   Test3   Test4   Test5   Avg   Letter" << endl; 
		cout << "---------------------------------------------------------------------------------\n" << endl;
		outFile << "---------------------------------------------------------------------------------" << endl;
		outFile << " Student                 Test1   Test2   Test3   Test4   Test5   Avg   Letter" << endl; 
		outFile << "---------------------------------------------------------------------------------\n" << endl;

        while(inFile.get(c))
        {
		if(c=='\n') lines++;
		}
        inFile.clear();
        inFile.seekg(0);

        for(int i=1;i<lines;i++)
            {
            	double sum = 0;
                grade = calc_grade(avg);
                
                inFile>>fName;
                inFile>>lName;
                outFile<<fName<<" "<<lName<<"    ";
                cout<<fName<<" "<<lName<<"    ";;
                
				for(int j=0;j<5;j++)
                {
                    if(inFile>>grades)
                    {
					sum+=grades;
                    outFile<<" 	  " <<grades<<" ";
					cout <<" 	  " <<grades<<" ";
					}
                    
                }
                
                avg = sum / 5;
				cout <<"    "<<setw(3)<<avg<<"    "<<grade<<endl;
                outFile<<"    "<<avg<<"    "<<grade<<endl;
            }
        system("pause");
        return 0;
    }
    
char calc_grade(float finalGrade)
{

	char letterGrade;

 
   if (finalGrade < 60)
       letterGrade = 'F';
   else if (finalGrade < 70)
       letterGrade = 'D';
   else if (finalGrade < 80)
       letterGrade =  'C';
   else if (finalGrade < 90)
       letterGrade = 'B';
   else
       letterGrade = 'A';

 
	return letterGrade;

}
