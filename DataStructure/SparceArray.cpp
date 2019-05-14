#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	int col;
	int row;
	int value;
} Sparce;
Sparce a[101] = { 0 };

int main()
{
	int rowSize, colSize;
	int cntData = 0;
	string input;
	cin >> rowSize;
	a[0] = { rowSize, rowSize, 0 };
	for (int i = 0; i < rowSize; i++)
	{
		cin >> input;
		colSize = input.size();
		for (int j = 0; j < colSize; j++)
		{
			if (input[j] != '0')
			{
				cntData++;
				a[cntData].col = j;
				a[cntData].row = i;
				a[cntData].value = input[j] - 48;
			}
		}
	}
	a[0].value = cntData;
	for (int i = 0; i < cntData + 1; i++)
	{
		cout << "a[" << i << "]\t" << a[i].row << "\t" << a[i].col << "\t" << a[i].value << endl;
	}
	return 0;
}