#include <iostream>

using namespace std;

int arr[4][4];

int whoWin(int p)
{
	for (int i = 1; i <= 3; i++)
	{
		if (arr[i][i] == p && i == 3) return p;
		if (arr[i][i] != p) break;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (arr[i][4 - i] == p && i == 3) return p;
		if (arr[i][4 - i] != p) break;
	}

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if (arr[i][j] == p && j == 3) return p;
			if (arr[i][j] != p) break;
		}

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if (arr[j][i] == p && j == 3) return p;
			if (arr[j][i] != p) break;
		}

	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int p = 0, cnt = 0;
	cin >> p;
	while (cnt++ < 9)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = p;


		if (whoWin(p) != 0) break;
		p = p == 1 ? 2 : 1;
	}
	if (cnt <= 9) cout << p;
	else cout << 0;
}