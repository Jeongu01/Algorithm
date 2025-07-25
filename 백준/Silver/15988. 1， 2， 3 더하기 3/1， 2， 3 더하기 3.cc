#include <iostream>
using namespace std;

long long dp[1'000'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1'000'000; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1'000'000'009;
	}

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}