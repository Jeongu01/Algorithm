#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[100][100];
long long dp[100][100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] == 0 || arr[i][j] == 0) continue;
			int dist = arr[i][j];
			if (i + dist < N) dp[i + dist][j] += dp[i][j];
			if (j + dist < N) dp[i][j + dist] += dp[i][j];
		}
	}
	cout << dp[N - 1][N - 1];
}