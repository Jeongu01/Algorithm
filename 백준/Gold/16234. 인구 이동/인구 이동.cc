#include <iostream>
#include <queue>
using namespace std;

int N, L, R, ans;
int arr[51][51];
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
queue<int> q, buff;

bool bfs()
{
	bool ret = false;
	bool visited[51][51] = { false, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == true) continue;
			int cnt = 0, sum = 0;
			q.push(i);
			q.push(j);
			visited[i][j] = true;
			while (!q.empty())
			{
				int curR = q.front(); q.pop();
				int curC = q.front(); q.pop();
				buff.push(curR);
				buff.push(curC);
				sum += arr[curR][curC];
				cnt++;
				for (int k = 0; k < 4; k++)
				{
					int nxtR = curR + dr[k];
					int nxtC = curC + dc[k];
					if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < N && visited[nxtR][nxtC] == false)
					{
						int diff = abs(arr[curR][curC] - arr[nxtR][nxtC]);
						if (L <= diff && diff <= R)
						{
							q.push(nxtR);
							q.push(nxtC);
							visited[nxtR][nxtC] = true;
						}
					}
				}
			}
			if (cnt > 1) ret = true;
			int popul = sum / cnt;
			while (!buff.empty())
			{
				int curR = buff.front(); buff.pop();
				int curC = buff.front(); buff.pop();
				arr[curR][curC] = popul;
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (bfs())
	{
		ans++;
	}
	cout << ans;
}