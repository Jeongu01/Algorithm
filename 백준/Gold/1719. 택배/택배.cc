#include <iostream>
using namespace std;

int n, m;
int arr[201][201];
int nxt[201][201];

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
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] > c)
		{
			arr[a][b] = c;
			nxt[a][b] = b;
			arr[b][a] = c;
			nxt[b][a] = a;
		}
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
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (nxt[i][j] == 0) cout << "- ";
			else cout << nxt[i][j] << " ";
		}
		cout << "\n";
	}
}