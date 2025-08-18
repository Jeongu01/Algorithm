#include <iostream>
using namespace std;

int N, K;
int pos[500][2];
int dp[500][500];
/*
dp[N][K] = 1에서 N로 가는 K개 스킵한 최단거리
dp[N][0] = 
	dp[N - 1][0] + (N-1부터 N까지 거리)
dp[N][1] = 
	dp[N - 1][1] + (N-1부터 N까지 거리)
	dp[N - 2][0] + (N-2부터 N까지 거리)
dp[N][2] = 
	dp[N - 1][2] + (N-1부터 N까지 거리)
	dp[N - 2][1] + (N-2부터 N까지 거리)
	dp[N - 3][0] + (N-3부터 N까지 거리)
*/

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> pos[i][0] >> pos[i][1];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			dp[i][j] = 0x3f3f3f3f;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			for (int k = 0; k <= j && k <= i - 1; k++)
			{
				dp[i][j] = min(dp[i][j], 
					dp[i - 1 - k][j - k] + abs(pos[i - 1 - k][0] - pos[i][0]) + abs(pos[i - 1 - k][1] - pos[i][1]));
			}
		}
	}

	cout << dp[N - 1][K];
}