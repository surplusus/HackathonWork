#include <iostream>
#include <string>
using namespace std;

string *input = new string [];

void LCS()
{
	int cntIn = 0;
	cin >> cntIn;
	
	while (cntIn--)
	{
		cin >> *(input + cntIn);
	}
	for (int i = 0; i < input->size(); i++)
	{
		cout << *(input + i) << endl;

	}
}

int Main(void)
{
	LCS();
	return 0;
}