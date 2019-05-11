// Baekjoon / problem / 2579
// 계단 오르기 (DP활용)

#include <iostream>
using namespace std;

int n, stair[301];
int index, dp[301];

int DP(int n)
{
	int comp1, comp2;
	if (n == 0) return 0;
	if (n == 1) return dp[1];
	if (n == 2) return dp[2];
	if (dp[n-3] != 0)
		comp1 = stair[n] + stair[n - 1] + dp[n - 3];
	else
		comp1 = stair[n] + stair[n - 1] + DP(n - 3);
	if (dp[n - 2] != 0)
		comp2 = stair[n] + dp[n - 2];
	else
		comp2 = stair[n] + DP(n - 2);
	if (comp1 > comp2)
		dp[n] = comp1;
	else
		dp[n] = comp2;
	return dp[n];
}

int main()
{
	cin >> n;
	index = n;
	stair[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}
	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	DP(n);
	cout << dp[n];
	return 0;
}