#include <iostream>
using namespace std;

int R, C, T, org = 0, nxt = 1, u_r, u_c, d_r, d_c;
int arr[2][50][50];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void clean()
{
	int up_dr[] = { -1, 0, 1, 0 };
	int up_dc[] = { 0, 1, 0, -1 };
	int down_dr[] = { 1, 0, -1, 0 };
	int down_dc[] = { 0, 1, 0, -1 };

	int i = 0;
	int cur_r = u_r - 1;
	int cur_c = u_c;
	while (i < 4)
	{
		int nxt_r = cur_r + up_dr[i];
		int nxt_c = cur_c + up_dc[i];
		if (0 <= nxt_r && nxt_r <= u_r && 0 <= nxt_c && nxt_c < C)
		{
			if (arr[nxt][nxt_r][nxt_c] == -1) arr[nxt][cur_r][cur_c] = 0;
			else arr[nxt][cur_r][cur_c] = arr[nxt][nxt_r][nxt_c];

			cur_r = nxt_r;
			cur_c = nxt_c;
		}
		else i++;
	}

	i = 0;
	cur_r = d_r + 1;
	cur_c = d_c;
	while (i < 4)
	{
		int nxt_r = cur_r + down_dr[i];
		int nxt_c = cur_c + down_dc[i];
		if (d_r <= nxt_r && nxt_r < R && 0 <= nxt_c && nxt_c < C)
		{
			if (arr[nxt][nxt_r][nxt_c] == -1) arr[nxt][cur_r][cur_c] = 0;
			else arr[nxt][cur_r][cur_c] = arr[nxt][nxt_r][nxt_c];

			cur_r = nxt_r;
			cur_c = nxt_c;
		}
		else i++;
	}
}

void spread()
{
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			arr[nxt][r][c] = arr[org][r][c] == -1 ? -1 : 0;
		}
	}

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (arr[nxt][r][c] == -1) continue;
			int cnt = 0, value = arr[org][r][c] / 5;
			for (int i = 0; i < 4; i++)
			{
				int side_r = r + dr[i];
				int side_c = c + dc[i];
				if (0 <= side_r && side_r < R && 0 <= side_c && side_c < C && arr[nxt][side_r][side_c] != -1)
				{
					cnt++;
					arr[nxt][side_r][side_c] += value;
				}
			}
			arr[nxt][r][c] += arr[org][r][c] - cnt * value;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> T;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> arr[0][r][c];
			if (arr[0][r][c] == -1)
			{
				if (u_r == 0) u_r = r;
				else d_r = r;
			}
		}
	}

	while (T--)
	{
		spread();
		clean();

		int temp = org;
		org = nxt;
		nxt = temp;
	}

	int ans = 2;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			ans += arr[org][r][c];
		}
	}
	cout << ans;
}