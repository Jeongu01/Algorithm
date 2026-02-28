#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cntVir, ans = 0x3f3f3f3f;
int org[50][50];
int arr[50][50];
int vir[10][2];
bool sel[10];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void run()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = org[i][j];
		}
	}

	queue<int> q;
	for (int i = 0; i < cntVir; i++)
	{
		if (sel[i] == true)
		{
			q.push(vir[i][0]);
			q.push(vir[i][1]);
		}
		else
		{
			arr[vir[i][0]][vir[i][1]] = 0;
		}
	}

	int t = -1;
	while (!q.empty())
	{
		t++;
		int size = q.size() / 2;
		while (size--)
		{
			int curR = q.front(); q.pop();
			int curC = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nxtR = curR + dr[i];
				int nxtC = curC + dc[i];
				if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < N
					&& arr[nxtR][nxtC] == 0)
				{
					arr[nxtR][nxtC] = 2;
					q.push(nxtR);
					q.push(nxtC);
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
				return;
		}
	}

	if (t == -1)
		t = 0;
	ans = min(ans, t);
}

void func(int depth, int idx)
{
	if (depth == M)
	{
		run();
	}

	for (int i = idx; i < cntVir; i++)
	{
		sel[i] = true;
		func(depth + 1, i + 1);
		sel[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> org[i][j];
			if (org[i][j] == 2)
			{
				vir[cntVir][0] = i;
				vir[cntVir][1] = j;
				cntVir++;
			}
		}
	}

	func(0, 0);
	if (ans == 0x3f3f3f3f)
		ans = -1;

	cout << ans;
}