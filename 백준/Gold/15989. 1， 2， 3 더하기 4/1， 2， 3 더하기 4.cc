#include <iostream>
using namespace std;

int dp[10'001][4];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n = a+b+c+d+e
	// a <= b <= c <= d <= e 가 되게 유도하기
	// dp[n][3] = dp[n-3][1] + dp[n-3][2] + dp[n-3][3]
	// dp[n][2] = dp[n-2][1] + dp[n-2][2]
	// dp[n][1] = dp[n-1][1]
	dp[1][1] = 1;						// 1
	dp[2][1] = dp[2][2] = 1;			// 1+1 / 2
	dp[3][1] = dp[3][2] = dp[3][3] = 1;	// 1+1+1 / 1+2 / 3
	for (int i = 4; i <= 10'000; i++)
	{
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][1] = dp[i - 1][1];
	}

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}
}