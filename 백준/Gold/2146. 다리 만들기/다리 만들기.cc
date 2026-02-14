#include<iostream>
#include <queue>
using namespace std;

int N, num = 1, ans = 0x3f3f3f3f;
int arr[100][100];
bool vst[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void numbering(int r, int c)
{
	num++;
	queue<int> q;
	q.push(r);
	q.push(c);
	arr[r][c] = num;
	while (!q.empty())
	{
		int curR = q.front(); q.pop();
		int curC = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < N
				&& arr[nxtR][nxtC] == 1)
			{
				arr[nxtR][nxtC] = num;
				q.push(nxtR);
				q.push(nxtC);
			}
		}
	}
}

void buildBridge(int r, int c, int n)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vst[i][j] = false;

	int len = 0;
	queue<int> q;
	q.push(r);
	q.push(c);
	vst[r][c] = true;
	while (!q.empty())
	{
		len++;
		int sz = q.size() / 2;
		while (sz--)
		{
			int curR = q.front(); q.pop();
			int curC = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nxtR = curR + dr[i];
				int nxtC = curC + dc[i];
				if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < N
					&& vst[nxtR][nxtC] == false)
				{
					if (arr[nxtR][nxtC] == 0)
					{
						vst[nxtR][nxtC] = true;
						q.push(nxtR);
						q.push(nxtC);
					}
					else if (arr[nxtR][nxtC] != n)
					{
						ans = min(ans, len);
						return;
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 1)
				continue;
			numbering(i, j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0) continue;
			if (1 <= i && arr[i - 1][j] == 0) buildBridge(i - 1, j, arr[i][j]);
			if (i < N - 1 && arr[i + 1][j] == 0) buildBridge(i + 1, j, arr[i][j]);
			if (1 <= j && arr[i][j - 1] == 0) buildBridge(i, j - 1, arr[i][j]);
			if (j < N - 1 && arr[i][j + 1] == 0) buildBridge(i, j + 1, arr[i][j]);
		}
	}

	cout << ans;
}