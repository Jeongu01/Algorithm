#include <iostream>
using namespace std;

int R, C, cntO, cntV, ansO, ansV;
char arr[250][250];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int r, int c)
{
	if (arr[r][c] == 'o') cntO++;
	else if (arr[r][c] == 'v') cntV++;
	arr[r][c] = '#';

	for (int i = 0; i < 4; i++)
	{
		int nxt_r = r + dr[i];
		int nxt_c = c + dc[i];
		if (0 <= nxt_r && nxt_r < R && 0 <= nxt_c && nxt_c < C)
		{
			if (arr[nxt_r][nxt_c] != '#') dfs(nxt_r, nxt_c);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = str.at(j);
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cntO = 0;
			cntV = 0;
			if (arr[i][j] != '#')
			{
				dfs(i, j);
				if (cntO > cntV) ansO += cntO;
				else ansV += cntV;
				cntO = 0;
				cntV = 0;
			}
		}
	}
	cout << ansO << " " << ansV;
}