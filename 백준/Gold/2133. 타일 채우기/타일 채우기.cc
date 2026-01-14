#include <iostream>
using namespace std;

int dp[31];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	dp[2] = 3;
	for (int i = 4; i <= N; i+=2)
	{
		dp[i] += dp[i - 2] * 3;
		for (int j = i - 4; j >= 2; j-=2)
		{
			dp[i] += dp[j] * 2;
		}
		dp[i] += 2;
	}
	cout << dp[N];
}