// 매일프로그래밍
/*
문자열 배열(string array)이 주어지면, 제일 긴 공통된 접두사(prefix)의 길이를 찾으시오.
Given an array of strings, find the longest common prefix of all strings.
예제)
Input: [“apple”, “apps”, “ape”]
Output: 2 // “ap”
Input: [“hawaii”, “happy”]
Output: 2 // “ha”
Input: [“dog”, “dogs”, “doge”]
Output: 3 // “dog”
*/
#include <iostream>
#include <string>
using namespace std;

string *input = new string [10];

//  모든 문자안에서 비교하는 LCS(DP 이용)
//int LCS(int m, int n){
//	for (int i = 0; i <= m; i++)
//		c[i][0] = 0;
//	for (int j = 0; j <= n; j++)
//		c[0][j] = 0;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (x[i] == y[j])
//				c[i][j] = c[i - 1][j - 1] + 1;
//			else
//				c[i][j] = Math.max(c[i - 1][j], c[i][j - 1]);
//		}
//	}
//}

void LCS()
{
	int cntIn = 0;
	
	cin >> cntIn;
	for (int i = 0; i < cntIn; i++)
	{
		cin >> input[i];
	}

	int nEndFlag = cntIn;
	int stringIdx = 0;

	while (nEndFlag)
	{
		char tmp = input[0][stringIdx];
		for (int i = 0; i < cntIn; i++)
		{
			if (input[i][stringIdx] == tmp)
				--nEndFlag;
			else
				break;
		}
		if (nEndFlag == 0)
		{
			cout << tmp;
			nEndFlag = cntIn;
			stringIdx++;
		}
		else
			break;
	}

}

int main(void)
{
	LCS();
	delete[] input;
	return 0;
}