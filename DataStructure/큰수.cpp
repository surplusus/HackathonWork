#include <iostream>
#include <string>
#include <array>
#include <sstream>
using namespace std;
#define ARRAY_SIZE 3

typedef array<int, ARRAY_SIZE> LargeInteger;

LargeInteger arrA = { 0 };
LargeInteger arrB = { 0 };
LargeInteger arrC = { 0 };

string PushPop(string input)
{
	string output;
	int strSize = input.size();

	while ((--strSize) >= 0)
		output += input[strSize];
	
	return output;
}

void ConvertArray(string input, LargeInteger* arr)
{
	int array_flag[ARRAY_SIZE+1];
	int inputSize = input.size();
	array_flag[0] = 0;
	for (int i = 1; i < ARRAY_SIZE+1; i++)
	{
		if (inputSize /= 9 > 0)
			array_flag[i] = 8 * i;
		else
		{
			array_flag[i] = 8 * i + (input.size() % 9);
			break;
		}
	}

	string s = input.substr(0, 9);
	int i = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		int exp = input.length() - 1 - i;
		i += (s[i] - '0') * pow(10, exp);
	}

}

int main()
{
	string a, b, c;


	cin >> a;
	a = PushPop(a);
	cout << a;
	cin >> b;
	b = PushPop(b);
	cout << b;
	ConvertArray(a, &arrA);

	return 0;
}