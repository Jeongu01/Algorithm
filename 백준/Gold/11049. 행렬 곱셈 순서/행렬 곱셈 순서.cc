#include <iostream>
#include <climits>
using namespace std;

int N;
int mat[500][2];
int dp[500][500];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> mat[i][0] >> mat[i][1];
	}

	for (int len = 1; len < N; len++)
	{
		for (int i = 0; i + len < N; i++)
		{
			int j = i + len;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j],
					dp[i][k] + dp[k + 1][j] + (mat[i][0] * mat[k][1] * mat[j][1]));
			}
		}
	}

	cout << dp[0][N - 1];
}