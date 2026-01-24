#include <iostream>
#include <queue>
using namespace std;

int R, C, SR, SC;
char arr[50][50];
bool visited[50][50];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	queue<int> q, w;
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = s.at(j);
			if (arr[i][j] == 'S')
			{
				SR = i;
				SC = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == '*')
			{
				w.push(i);
				w.push(j);
			}
		}
	}

	q.push(SR);
	q.push(SC);
	visited[SR][SC] = true;
	int t = 0;
	while (!q.empty())
	{
		t++;
		int qSize = q.size() / 2;
		while (qSize--)
		{
			int curSR = q.front(); q.pop();
			int curSC = q.front(); q.pop();
			if (arr[curSR][curSC] != '.') continue;
			for (int i = 0; i < 4; i++)
			{
				int nxtSR = curSR + dr[i];
				int nxtSC = curSC + dc[i];
				if (0 <= nxtSR && nxtSR < R && 0 <= nxtSC && nxtSC < C
					&& visited[nxtSR][nxtSC] == false)
				{
					if (arr[nxtSR][nxtSC] == '.')
					{
						visited[nxtSR][nxtSC] = true;
						q.push(nxtSR);
						q.push(nxtSC);
					}
					else if (arr[nxtSR][nxtSC] == 'D')
					{
						cout << t;
						return 0;
					}
				}
			}
		}

		int wSize = w.size() / 2;
		while (wSize--)
		{
			int curWR = w.front(); w.pop();
			int curWC = w.front(); w.pop();
			for (int i = 0; i < 4; i++)
			{
				int nxtWR = curWR + dr[i];
				int nxtWC = curWC + dc[i];
				if (0 <= nxtWR && nxtWR < R && 0 <= nxtWC && nxtWC < C
					&& arr[nxtWR][nxtWC] == '.')
				{
					arr[nxtWR][nxtWC] = '*';
					w.push(nxtWR);
					w.push(nxtWC);
				}
			}
		}
	}
	cout << "KAKTUS";
}