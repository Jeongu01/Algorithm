#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int N, M, num;
int arr[1000][1000];
bool visited[1000][1000];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
map<int, int> m;

int bfs(int r, int c)
{
	queue<int> q;
	q.push(r);
	q.push(c);
	arr[r][c] = num;
	int size = 1;
	while (!q.empty())
	{
		int curR = q.front(); q.pop();
		int curC = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < M && arr[nxtR][nxtC] == 1)
			{
				arr[nxtR][nxtC] = num;
				size++;
				q.push(nxtR);
				q.push(nxtC);
			}
		}
	}
	return size;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	num = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 1) continue;
			num++;
			int size = bfs(i, j);
			m.insert({ num, size });
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 0) continue;
			set<int> s;
			for (int k = 0; k < 4; k++)
			{
				int nxtR = i + dr[k];
				int nxtC = j + dc[k];
				if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < M && arr[nxtR][nxtC] != 0)
				{
					s.insert(arr[nxtR][nxtC]);
				}
			}
			int sum = 1;
			for (auto e : s)
			{
				sum += m[e];
			}
			ans = max(ans, sum);
		}
	}
	cout << ans;
}