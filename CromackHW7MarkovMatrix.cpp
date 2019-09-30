/*
 * Name: Tyler Cromack
 * Date: 4/23/2017
 * Course Number: CSC-101
 * Course Name: Introduction to Computer Science
 * Problem Number: HW#7 Markov Matrix
 * This program will take input and sort a possible Markov matrix
 */
#include <iostream> 

using namespace std;


const int sizeOfMatrix = 3;

bool isMarkovMatrix(double matrix [][sizeOfMatrix])
{
	bool isMarkov;
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		double sum = 0;
		for(int j = 0; j < sizeOfMatrix; j++)
		{
			sum += matrix[j][i];
			if (sum != 1)
			{
				isMarkov = false;
			}
			else
			{
				isMarkov = true;
			}
		}
	}
	return isMarkov;
}
	
void sortRows(double rMatrix[][sizeOfMatrix])
{
	cout << "\nThe raw-sorted array is: " << endl;
	
	for (int row = 0; row < sizeOfMatrix; row++ )
	{
		for (int col = 0; col < sizeOfMatrix; col++)
		{
			for (int i =  col + 1; i < sizeOfMatrix; i++)
			{
				if (rMatrix[row][i]< rMatrix[row][col])
				{
					double temp = rMatrix[row][col];
					rMatrix [row][col] = rMatrix[row][i];
					rMatrix[row][i] = temp;
				}
			}
		}
	}
	//print sorted Rows
	for (int row = 0; row < sizeOfMatrix; row++ )
	{
		for (int col = 0; col < sizeOfMatrix; col++)
		{
			cout << rMatrix[row][col] << "   ";
		}
		cout << endl;
	}
}

int main()
{
    double matrix[sizeOfMatrix][sizeOfMatrix];
    
    //Get input
    cout << "Enter a 3 x 3 matrix row by row: " << endl;
    
    for (int i = 0; i < sizeOfMatrix; ++i)
    {
    	cout << "Enter Row " << i + 1 << ":" << endl;
        for (int j = 0; j < sizeOfMatrix; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    
    if (isMarkovMatrix(matrix))
    {
        cout << "\nIt is a Markov matrix" << endl;
    }
    else
    {
        cout << "\nIt is Not a markov matrix" << endl;
    }
	cout << endl;
    //Print user matrix
    for (int i = 0; i < sizeOfMatrix; i++)
    { 
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			cout << "" << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	
   sortRows(matrix);
   system("PAUSE");
   return 0;
}
