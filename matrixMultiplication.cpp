/*
* Integer Matrix Multiplication Program
* Copyright Jafarov Makhlug
* 10/29/2021
*/
	
#include <iostream>
#include <vector>
using namespace std;

/*function prototypes*/
bool fill(vector<vector<int>>& A, vector<vector<int>>& B);
vector<vector<int>> multiplication(vector<vector<int>> A, vector<vector<int>> B);

int main()
{
	vector<vector<int>> A; //matrix A
	vector<vector<int>> B; //matrix B
	vector<vector<int>> result; //result of multiplication

	bool resultFillFunction;

	//function call for input
	do
	{
		resultFillFunction = fill(A, B);
	} while (!resultFillFunction);

	//performing the multiplication
	result = multiplication(A, B);

	//printing the result
	cout << "\n\n-----------------\nResult of the multiplication: \n\n";
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			cout << result[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\n-----------------\n";

	return (0);
}

bool fill(vector<vector<int>>& A, vector<vector<int>>& B)
{
	int rowA, columnA; //row and column sizes for matrix A
	int rowB, columnB; //row and column sizes for matrix B
	int input;

	cout << "Matrix A: " << endl;
	cout << "--> Row: ";
	cin >> rowA;
	cout << "--> Column: ";
	cin >> columnA;

	cout << endl << "Matrix B:" << endl;
	cout << "--> Row: ";
	cin >> rowB;
	cout << "--> Column: ";
	cin >> columnB;

	if (columnA != rowB)
	{
		cout << "\ncolumnA and rowB must be the same size!\n\n";
		cout << "------------------\n\n";
		return 0;
	}

	cout << "\n-------------\n\n";
	for (int i = 0; i < rowA; i++)
	{
		vector<int> tmp; //temporary vector to push back into the actual vector
		for (int j = 0; j < columnA; j++)
		{
			cout << "A(" << i << ", " << j << "): ";
			cin >> input;
			tmp.push_back(input);
		}
		A.push_back(tmp);
		tmp.clear(); //clearing the vector tmp
	}
	cout << "\n-------------\n\n";
	for (int i = 0; i < rowB; i++)
	{
		vector<int> tmp; //temporary vector to push back into the actual vector
		for (int j = 0; j < columnB; j++)
		{
			cout << "B(" << i << ", " << j << "): ";
			cin >> input;
			tmp.push_back(input);
		}
		B.push_back(tmp);
		tmp.clear(); //clearing the vector tmp
	}

	return 1;
}

vector<vector<int>> multiplication(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> result;
	int sum = 0;

	for (int rowA = 0; rowA < A.size(); rowA++)
	{
		vector<int> tmp;
		for (int colB= 0; colB < B[0].size(); colB++)
		{
			for (int colArowB = 0; colArowB < A[0].size(); colArowB++)
			{
				sum += A[rowA][colArowB] * B[colArowB][colB];
			}
			tmp.push_back(sum);
			sum = 0;
		}
		result.push_back(tmp);
		tmp.clear();
	}

	return result;
}

