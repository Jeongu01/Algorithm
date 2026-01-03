#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt, t;
bool arr[100][100];
bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

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
			if (arr[i][j] == true) cnt++;
		}
	}
	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visited[i][j] = false;
			}
		}
		queue<int> q;
		queue<int> delQ;
		q.push(0);
		q.push(0);
		visited[0][0] = true;
		t++;
		while (!q.empty())
		{
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
					if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < M &&
						visited[nxtR][nxtC] == false)
					{
						if (arr[nxtR][nxtC] == 0)
						{
							q.push(nxtR);
							q.push(nxtC);
							visited[nxtR][nxtC] = true;
						}
						else
						{
							delQ.push(nxtR);
							delQ.push(nxtC);
							visited[nxtR][nxtC] = true;
						}
					}
				}
			}
		}
		if (cnt == delQ.size() / 2)
		{
			cout << t << "\n" << cnt;
			return 0;
		}
		while (!delQ.empty())
		{
			int r = delQ.front(); delQ.pop();
			int c = delQ.front(); delQ.pop();
			arr[r][c] = 0;
			cnt--;
		}
	}
	
}