#include<iostream>
#include <queue>
using namespace std;

int n;
int bamboo[500][500];
int arr[500][500];

int dfs(int r, int c)
{
	int bb = bamboo[r][c];
	if (arr[r][c] != -1)
		return arr[r][c];
	arr[r][c] = 0;
	if (1 <= r && bamboo[r - 1][c] > bb) arr[r][c] = max(arr[r][c], dfs(r - 1, c) + 1);
	if (r < n - 1 && bamboo[r + 1][c] > bb) arr[r][c] = max(arr[r][c], dfs(r + 1, c) + 1);
	if (1 <= c && bamboo[r][c - 1] > bb) arr[r][c] = max(arr[r][c], dfs(r, c - 1) + 1);
	if (c < n - 1 && bamboo[r][c + 1] > bb) arr[r][c] = max(arr[r][c], dfs(r, c + 1) + 1);
	return arr[r][c];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> bamboo[i][j];
			arr[i][j] = -1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == -1)
				ans = max(ans, dfs(i, j) + 1);
		}
	}
	cout << ans;
}