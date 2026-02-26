#include <iostream>
using namespace std;

int n, m;
int arr[251][251];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = 0x3f3f3f3f;
		}
		arr[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, b;
		cin >> u >> v >> b;
		arr[u][v] = 0;
		if (b == 0) arr[v][u] = 1;
		else arr[v][u] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	int k;
	cin >> k;
	while (k--)
	{
		int s, e;
		cin >> s >> e;
		cout << arr[s][e] << "\n";
	}
}