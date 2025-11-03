#include <iostream>
#include <queue>
using namespace std;

int N, M, Hx, Hy, Ex, Ey;
bool arr[1001][1001];
bool visited[1001][1001][2];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	queue<int> q;
	q.push(Hx);
	q.push(Hy);
	q.push(0);
	int ans = -1;
	bool flag = false;
	while (!q.empty())
	{
		if (flag == true) break;
		int size = q.size();
		size /= 3;
		ans++;
		while (size--)
		{
			int curR = q.front(); q.pop();
			int curC = q.front(); q.pop();
			int magic = q.front(); q.pop();
			if (curR == Ex && curC == Ey)
			{
				flag = true;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				int nxtR = curR + dr[i];
				int nxtC = curC + dc[i];
				if (0 < nxtR && nxtR <= N && 0 < nxtC && nxtC <= M)
				{
					if (magic == 0)
					{
						if (arr[nxtR][nxtC] == 0 && visited[nxtR][nxtC][0] == false)
						{
							visited[nxtR][nxtC][0] = true;
							q.push(nxtR);
							q.push(nxtC);
							q.push(0);
						}
						if (arr[nxtR][nxtC] == 1 && visited[nxtR][nxtC][1] == false)
						{
							visited[nxtR][nxtC][1] = true;
							q.push(nxtR);
							q.push(nxtC);
							q.push(1);
						}
					}
					else
					{
						if (arr[nxtR][nxtC] == 0 && visited[nxtR][nxtC][1] == false)
						{
							visited[nxtR][nxtC][1] = true;
							q.push(nxtR);
							q.push(nxtC);
							q.push(1);
						}
					}
				}
			}
		}
	}
	if (flag == true) cout << ans;
	else cout << "-1";
}