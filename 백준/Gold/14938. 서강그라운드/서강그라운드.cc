#include <iostream>
using namespace std;

int item[101];
int dist[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 0x3f3f3f3f;
		}
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] > m) continue;
			sum += item[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;
}