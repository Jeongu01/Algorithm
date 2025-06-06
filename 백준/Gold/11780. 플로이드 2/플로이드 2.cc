#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<int> path;
int arr[101][101];
int nxt[101][101];

void findPath(int s, int e)
{
	int nxtCity = nxt[s][e];
	path.push(s);
	if (nxtCity == e) path.push(nxtCity);
	else findPath(nxtCity, e);
}

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

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
		nxt[a][b] = b;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
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
			if (arr[i][j] == 0x3f3f3f3f) cout << "0 ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (nxt[i][j] == 0)
			{
				cout << "0\n";
				continue;
			}
			findPath(i, j);
			cout << path.size() << " ";
			while (!path.empty())
			{
				cout << path.front() << " ";
				path.pop();
			}
			cout << "\n";
		}
	}
}