#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int N, M, rmCnt, maxSize, maxSumSize;
int arr[50][50];
short walls[50][50];
bool visited[50][50];

queue<int> q;
map<int, int> rmSize;
set<pair<int, int>> adj;

void checkRoom(int curR, int curC, int nxtR, int nxtC, int dir)
{
	if (visited[nxtR][nxtC] == false)
	{
		if (!(walls[curR][curC] & dir))
		{
			visited[nxtR][nxtC] = true;
			rmSize[rmCnt]++;
			arr[nxtR][nxtC] = rmCnt;
			q.push(nxtR);
			q.push(nxtC);
		}
	}
	else if (arr[nxtR][nxtC] != rmCnt) adj.insert({ arr[nxtR][nxtC], rmCnt });
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> walls[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == true) continue;
			rmCnt++;
			q.push(i);
			q.push(j);
			visited[i][j] = true;
			arr[i][j] = rmCnt;
			rmSize[rmCnt]++;
			while (!q.empty())
			{
				int curR = q.front(); q.pop();
				int curC = q.front(); q.pop();
				if (0 <= curC - 1) checkRoom(curR, curC, curR, curC - 1, 1);
				if (0 <= curR - 1) checkRoom(curR, curC, curR - 1, curC, 2);
				if (curC + 1 < N) checkRoom(curR, curC, curR, curC + 1, 4);
				if (curR + 1 < M) checkRoom(curR, curC, curR + 1, curC, 8);
			}
		}
	}

	for (auto s : rmSize)
	{
		maxSize = max(maxSize, s.second);
	}

	for (auto w : adj)
	{
		maxSumSize = max(maxSumSize, rmSize[w.first] + rmSize[w.second]);
	}

	cout << rmCnt << "\n";
	cout << maxSize << "\n";
	cout << maxSumSize;
}