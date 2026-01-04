#include <iostream>
#include <queue>
using namespace std;

int N, M, T;
char arr[100][100];
bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void bfs(int r, int c)
{
	queue<int> q;
	q.push(r);
	q.push(c);
	visited[r][c] = true;
	while (!q.empty())
	{
		int curR = q.front(); q.pop();
		int curC = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < M &&
				visited[nxtR][nxtC] == false && arr[nxtR][nxtC] == '#')
			{
				visited[nxtR][nxtC] = true;
				q.push(nxtR);
				q.push(nxtC);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visited[i][j] = false;
			}
		}
		string str;
		for (int i = 0; i < N; i++)
		{
			cin >> str;
			for (int j = 0; j < M; j++)
			{
				arr[i][j] = str.at(j);
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] != '#') continue;
				if (visited[i][j] == true) continue;
				cnt++;
				bfs(i, j);
			}
		}
		cout << cnt << "\n";
	}
}