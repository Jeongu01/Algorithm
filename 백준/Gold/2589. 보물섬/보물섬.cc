#include <iostream>
#include <queue>
using namespace std;

int N, M, ans;
char arr[50][50];
bool visited[50][50];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int bfs(int r, int c)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
	queue<int> q;
	visited[r][c] = true;
	q.push(r);
	q.push(c);
	int dist = -1;
	while (!q.empty())
	{
		dist++;
		int size = q.size() / 2;
		while (size--)
		{
			int curR = q.front(); q.pop();
			int curC = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nxtR = curR + dr[i];
				int nxtC = curC + dc[i];
				if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < M
					&& arr[nxtR][nxtC] == 'L' && visited[nxtR][nxtC] == false)
				{
					visited[nxtR][nxtC] = true;
					q.push(nxtR);
					q.push(nxtC);
				}
			}
		}
	}
	return dist;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = s.at(j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'W') continue;
			ans = max(ans, bfs(i, j));
		}
	}
	cout << ans;
}