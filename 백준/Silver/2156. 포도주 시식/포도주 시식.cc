#include <iostream>
using namespace std;

int n;
int arr[10001];
int dp[10001][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}

	int ans = max(max(dp[n][0], dp[n][1]), dp[n][2]);
	cout << ans;
}