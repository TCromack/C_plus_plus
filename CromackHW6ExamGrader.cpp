/*
 * Name: Tyler Cromack
 * Date: 4/15/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#6 Exam Grader
 * This program will correct student exams and grade them.
 */
 
#include <iostream> 
#include <fstream>

using namespace std;

int main()
{
int count = 0;
int qCount = 0;
char correctAnswer[20];
char studentAnswer[20];
char result[4][5];

ifstream inFileCorrect;
inFileCorrect.open("Correct.txt");

if (inFileCorrect)
{
	for (int i=0;i<20;i++)
	{
   	 inFileCorrect>>correctAnswer[i];
	}
}

else
{
	cout<<"Correct.txt NOT FOUND!";
}

inFileCorrect.close();

ifstream inFileStudent;
inFileStudent.open("Student.txt");

if (inFileStudent)
{
	for (int j=0;j<20;j++)
	{
   	 inFileStudent>>studentAnswer[j];
	}
}

else
{
	cout<<"Student.txt NOT FOUND!";
}
	
inFileStudent.close();

cout << "Professor Burns Final Exam\n----------------------------";

for (int k=0;k<20;k++)
{ 
    qCount++;
    cout<<"\n"<<qCount<<")";
   
    if (correctAnswer[k]!=studentAnswer[k])
    {
		count++;
        cout << "\nCorrect Answer: " << correctAnswer[k];
        cout << "\nStudent Answer: " << studentAnswer[k] << " * " << endl;
    }
    
	else 
	{
    	cout << "\nCorrect Answer: " << correctAnswer[k];
        cout << "\nStudent Answer: " << studentAnswer[k] << endl;
	}
}
int percent = 5 * ( 20 - count );

cout << "----------------------------\n";
cout << "\nIncorrect Answers: " << count << endl;
cout << "\nPercentage of Correct Answers: " << percent << "%" << endl;

if (percent >= 70)
{
    cout << "\nCongratulations you passed the exam!\n";
}
else
{
    cout << "\nSorry you did not pass the exam\n";
}
system("PAUSE");
return 0;
}
