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
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 3;
		
	for (int i = 4; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			dp[i] = dp[i / 3] + 1;
		}
		else
		{
			if (i % 2 == 0)
			{
				int comp1 = dp[i / 2] + 1;
				int comp2 = dp[i - 1] + 1;
				(comp1 < comp2) ? (dp[i] = comp1) : dp[i] = comp2;
			}
			else
			{
				dp[i] = dp[i - 1] + 1;
			}
		}
	}

	cout << dp[N];

	return 0;
}