#include <iostream>
#include <queue>
using namespace std;

int N, M, virusCnt, roomCnt, ans = 0x3f3f3f3f;
int arr[50][50];
int visited[50][50];
pair<int, int> virus[10], pick[10];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void func(int depth, int start)
{
	if (depth == M)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visited[i][j] = false;
			}
		}
		queue<int> q, offQ;
		for (int i = 0; i < M; i++)
		{
			auto p = pick[i];
			int r = p.first;
			int c = p.second;
			visited[r][c] = true;
			q.push(r);
			q.push(c);
		}
		int t = 0, emptyCnt = 0;
		while (!q.empty())
		{
			if (emptyCnt == roomCnt) break;
			t++;
			int size = q.size();
			size /= 2;
			while (size--)
			{
				int curR = q.front(); q.pop();
				int curC = q.front(); q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nxtR = curR + dr[i];
					int nxtC = curC + dc[i];
					if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < N
						&& visited[nxtR][nxtC] == false && arr[nxtR][nxtC] != 1)
					{
						if (arr[nxtR][nxtC] == 0) emptyCnt++;
						visited[nxtR][nxtC] = true;
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
				if (visited[i][j] == false && arr[i][j] == 0) return;
			}
		}
		ans = min(ans, t);
		return;
	}

	for (int i = start; i < virusCnt; i++)
	{
		pick[depth] = virus[i];
		func(depth + 1, i + 1);
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
			cin >> arr[i][j];
			if (arr[i][j] == 2) virus[virusCnt++] = { i, j };
			else if (arr[i][j] == 0) roomCnt++;
		}
	}
	func(0, 0);
	if (ans == 0x3f3f3f3f) cout << -1;
	else cout << ans;
}