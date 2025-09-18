#include <iostream>
#include <queue>
using namespace std;

int N, M, sr, sc, sd, er, ec, ed;
int arr[101][101];
bool visited[101][101][5];
queue<int> q;

void pushQueue(int r, int c, int d)
{
	if (visited[r][c][d] == false)
	{
		q.push(r);
		q.push(c);
		q.push(d);
		visited[r][c][d] = true;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> sr >> sc >> sd >> er >> ec >> ed;
	pushQueue(sr, sc, sd);
	int cnt = -1;
	while (!q.empty())
	{
		cnt++;
		int size = q.size() / 3;
		while (size--)
		{
			int curR = q.front(); q.pop();
			int curC = q.front(); q.pop();
			int curD = q.front(); q.pop();
			if (curR == er && curC == ec && curD == ed)
			{
				cout << cnt;
				return 0;
			}
			switch (curD)
			{
			case 1:
				if (curC + 1 <= M && arr[curR][curC + 1] == 0) { pushQueue(curR, curC + 1, curD);
					if (curC + 2 <= M && arr[curR][curC + 2] == 0) { pushQueue(curR, curC + 2, curD);
						if (curC + 3 <= M && arr[curR][curC + 3] == 0) pushQueue(curR, curC + 3, curD);
					}
				}
				pushQueue(curR, curC, 3);
				pushQueue(curR, curC, 4);
				break;
			case 2:
				if (1 <= curC - 1 && arr[curR][curC - 1] == 0) { pushQueue(curR, curC - 1, curD);
					if (1 <= curC - 2 && arr[curR][curC - 2] == 0) { pushQueue(curR, curC - 2, curD);
						if (1 <= curC - 3 && arr[curR][curC - 3] == 0) pushQueue(curR, curC - 3, curD);
					}
				}
				pushQueue(curR, curC, 3);
				pushQueue(curR, curC, 4);
				break;
			case 3:
				if (curR + 1 <= N && arr[curR + 1][curC] == 0) { pushQueue(curR + 1, curC, curD);
					if (curR + 2 <= N && arr[curR + 2][curC] == 0) { pushQueue(curR + 2, curC, curD);
						if (curR + 3 <= N && arr[curR + 3][curC] == 0) pushQueue(curR + 3, curC, curD);
					}
				}
				pushQueue(curR, curC, 1);
				pushQueue(curR, curC, 2);
				break;
			case 4:
				if (1 <= curR - 1 && arr[curR - 1][curC] == 0) { pushQueue(curR - 1, curC, curD);
					if (1 <= curR - 2 && arr[curR - 2][curC] == 0) { pushQueue(curR - 2, curC, curD);
						if (1 <= curR - 3 && arr[curR - 3][curC] == 0) pushQueue(curR - 3, curC, curD);
					}
				}
				pushQueue(curR, curC, 1);
				pushQueue(curR, curC, 2);
				break;
			}
		}
	}
}