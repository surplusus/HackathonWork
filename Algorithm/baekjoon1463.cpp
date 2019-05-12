// Baekjoon / problem / 1463
// 1로 만들기 (재귀적 DP활용)

#include <iostream>
using namespace std;

int N;
int dp[1000001];

int main()
{
	cin >> N;
	int count = 0;
	
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 3;
		
	for (int i = 6; i <= N; i++)
	{
		int cmp1 = 99, cmp2 = 99, cmp3 = 99;
		cmp1 = dp[i - 1] + 1;
		if (i % 2 == 0)	cmp2 = dp[i / 2] + 1;
		if (i % 3 == 0)	cmp3 = dp[i / 3] + 1;
		(cmp1 < cmp2) ? cmp2 = cmp1 : cmp2 = cmp2;
		(cmp2 < cmp3) ? (dp[i] = cmp2) : dp[i] = cmp3;
	}

	cout << dp[N];

	return 0;
}