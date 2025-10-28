#include <iostream>
using namespace std;

int N, K;
int dp[201];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	dp[N] = 1;
	for (int i = 1; i < K; i++)
	{
		for (int n = 0; n <= N; n++)
		{
			int sum = 0;
			for (int m = n; m <= N; m++)
			{
				sum += dp[m];
				sum %= 1'000'000'000;
			}
			dp[n] = sum;
		}
	}
	int ans = 0;
	for (int i = 0; i <= N; i++)
	{
		ans += dp[i];
		ans %= 1'000'000'000;
	}
	cout << ans;
}