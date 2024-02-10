#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

void ReadSquare(vector<vector<int>>&);
void PrintMagicSquare(const vector<vector<int>>&);
bool IsSquareMagic(const vector<vector<int>>&, int&);
int RowSum(int Index, const vector<vector<int>>&);
int ColumnSum(int Jindex, const vector<vector<int>>&);
int FirstDiagonalSum(const vector<vector<int>>&);
int SecondDiagonalSum(const vector<vector<int>>&);

int main()
{
	vector<vector<int>> MagicSquare;

	ReadSquare(MagicSquare);
	PrintMagicSquare(MagicSquare);

	int MagicSum;
	if (IsSquareMagic(MagicSquare, MagicSum))
	{
		cout << endl;
		cout << "Magic Test passes -- the Magic Sum is " << MagicSum << endl;
	}
	else
	{
		cout << endl;
		cout << "Magic Test fails" << endl;
	}

	return 0;
}

void ReadSquare(vector<vector<int>>& Square)
{
	ifstream Input;
	vector<int> NumbersRead;
	Input.open("square11B.txt");
	cout << "Reading 'square11B.txt' file" << endl;
	int NextNumber;
	Input >> NextNumber;
	while (!Input.fail())
	{
		NumbersRead.push_back(NextNumber);
		Input >> NextNumber;
	}

	Input.close();

	assert(sqrt(NumbersRead.size()) == floor(sqrt(NumbersRead.size())));

	int NumbersBaseLength = static_cast<int>(sqrt(NumbersRead.size()));

	int NumberIndex = 0;
	for (int Index = 1; Index <= NumbersBaseLength; Index++)
	{
		vector<int> Row;
		for (int Jindex = 1; Jindex <= NumbersBaseLength; Jindex++)
		{
			Row.push_back(NumbersRead[NumberIndex]);
			NumberIndex++;
		}
		Square.push_back(Row);
	}

	return;
}

void PrintMagicSquare(const vector<vector<int>>& MagicSquare)
{
	cout << endl;
	for (int Index = 0; Index < MagicSquare.size(); Index++)
	{
		for (int Jindex = 0; Jindex < MagicSquare.size(); Jindex++)
		{
			if (MagicSquare[Index][Jindex] == 0)
			{
				cout << left << setw(6) << "~"
				     << "	";
			}
			else
			{
				cout << left << setw(6) << MagicSquare[Index][Jindex] << "	";
			}
		}
		cout << endl;
	}
	cout << endl;

	return;
}

bool IsSquareMagic(const vector<vector<int>>& MagicSquare, int& MagicSum)
{
	cout << "Checking for magic square" << endl;
	int SquareWidth = MagicSquare[0].size();
	int FirstRowSum = RowSum(0, MagicSquare);

	for (int Index = 1; Index < SquareWidth; Index++)
	{
		if (RowSum(Index, MagicSquare) != FirstRowSum || ColumnSum(Index, MagicSquare) != FirstRowSum)
		{
			return false;
		}
	}

	if (FirstDiagonalSum(MagicSquare) != FirstRowSum || SecondDiagonalSum(MagicSquare) != FirstRowSum)
	{
		return false;
	}

	MagicSum = FirstRowSum;
	return true;
}

int RowSum(int Index, const vector<vector<int>>& MagicSquare)
{
	int SquareWidth = MagicSquare[0].size();
	int CurrentSum = 0;
	for (int Jindex = 0; Jindex < SquareWidth; Jindex++)
	{
		CurrentSum += MagicSquare[Index][Jindex];
	}

	return CurrentSum;
}

int ColumnSum(int Index, const vector<vector<int>>& MagicSquare)
{
	int SquareWidth = MagicSquare[0].size();
	int CurrentSum = 0;
	for (int Jindex = 0; Jindex < SquareWidth; Jindex++)
	{
		CurrentSum += MagicSquare[Jindex][Index];
	}

	return CurrentSum;
}

int FirstDiagonalSum(const vector<vector<int>>& MagicSquare)
{
	int SquareWidth = MagicSquare[0].size();
	int CurrentSum = 0;
	for (int Index = 0; Index < SquareWidth; Index++)
	{
		CurrentSum += MagicSquare[Index][Index];
	}

	return CurrentSum;
}

int SecondDiagonalSum(const vector<vector<int>>& MagicSquare)
{
	int SquareWidth = MagicSquare[0].size();
	int CurrentSum = 0;
	for (int Index = SquareWidth - 1, Jindex = 0; Jindex < SquareWidth; Index--, Jindex++)
	{
		CurrentSum += MagicSquare[Index][Jindex];
	}

	return CurrentSum;
}
