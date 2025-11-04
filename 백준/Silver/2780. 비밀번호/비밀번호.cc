#include <iostream>
using namespace std;

#define MOD 1'234'567
int dp[1001][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 1000; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MOD;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % MOD;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
		dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MOD;
		dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MOD;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % MOD;
		dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MOD;
		dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
		dp[i][0] = dp[i - 1][7] % MOD;
	}

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int ans = 0;
		for (int i = 0; i < 10; i++)
		{
			ans += dp[N][i];
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}