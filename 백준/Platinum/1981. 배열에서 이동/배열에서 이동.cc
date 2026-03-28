#include <iostream>
#include <queue>
using namespace std;

int n, minA = 200, maxA;
int arr[100][100];
bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool bfs(int s, int e)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}

	queue<int> q;
	q.push(0);
	q.push(0);
	visited[0][0] = true;
	while (!q.empty())
	{
		int curR = q.front(); q.pop();
		int curC = q.front(); q.pop();
		if (curR == n - 1 && curC == n - 1) return true;
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (0 <= nxtR && nxtR < n && 0 <= nxtC && nxtC < n
				&& s <= arr[nxtR][nxtC] && arr[nxtR][nxtC] <= e && visited[nxtR][nxtC] == false)
			{
				visited[nxtR][nxtC] = true;
				q.push(nxtR);
				q.push(nxtC);
			}
		}
	}
	return false;
}

bool func(int v)
{
	for (int i = minA; i <= maxA - v; i++)
	{
		if (arr[0][0] < i || i + v < arr[0][0]
			|| arr[n - 1][n - 1] < i || i + v < arr[n - 1][n - 1])
			continue;
		if (bfs(i, i + v)) return true;
	}
	return false;
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
			cin >> arr[i][j];
			if (arr[i][j] < minA) minA = arr[i][j];
			if (maxA < arr[i][j]) maxA = arr[i][j];
		}
	}

	int start = 0, end = maxA - minA + 1;
	while (start < end)
	{
		int mid = (start + end) / 2;
		bool p = func(mid);
		if (p) end = mid;
		else start = mid + 1;
	}
	cout << end;
}