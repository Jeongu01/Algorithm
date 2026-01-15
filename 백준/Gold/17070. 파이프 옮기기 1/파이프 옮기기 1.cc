#include <iostream>
#include <queue>
using namespace std;

int N;
bool arr[17][17];
int dp[17][17][4];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][2][1] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 0)
			{
				dp[i][j][1] += dp[i][j - 1][1];
				dp[i][j][1] += dp[i][j - 1][3];

				dp[i][j][2] += dp[i - 1][j][2];
				dp[i][j][2] += dp[i - 1][j][3];

				if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0)
				{
					dp[i][j][3] += dp[i - 1][j - 1][1];
					dp[i][j][3] += dp[i - 1][j - 1][2];
					dp[i][j][3] += dp[i - 1][j - 1][3];
				}
			}
			
		}
	}

	cout << dp[N][N][1] + dp[N][N][2] + dp[N][N][3];
}