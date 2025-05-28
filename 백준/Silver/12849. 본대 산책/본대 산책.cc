#include <iostream>
using namespace std;

int D;
int dp[8][100001];
bool g[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 0, 1, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 0, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> D;
	dp[0][0] = 1;
	for (int i = 1; i <= D; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (g[j][k])
				{
					dp[j][i] += dp[k][i - 1];
					dp[j][i] %= 1000000007;
				}
			}
		}
	}
	cout << dp[0][D];
}