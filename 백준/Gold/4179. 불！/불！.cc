#include <iostream>
#include <queue>
using namespace std;

int R, C;
char arr[1000][1000];
bool visited[1000][1000];
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	queue<int> jq;
	queue<int> fq;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> arr[r][c];
			if (arr[r][c] == 'J')
			{
				jq.push(r);
				jq.push(c);
			}
			else if (arr[r][c] == 'F')
			{
				fq.push(r);
				fq.push(c);
			}
		}
	}

	int t = 0;
	bool p = false;
	while (!jq.empty())
	{
		t++;
		int size = fq.size() / 2;
		while (size--)
		{
			int curR = fq.front();
			fq.pop();
			int curC = fq.front();
			fq.pop();
			for (int i = 0; i < 4; i++)
			{
				int nxtR = curR + dr[i];
				int nxtC = curC + dc[i];
				if ((0 <= nxtR && nxtR < R && 0 <= nxtC && nxtC < C) && (arr[nxtR][nxtC] == '.' || arr[nxtR][nxtC] == 'J'))
				{
					arr[nxtR][nxtC] = 'F';
					fq.push(nxtR);
					fq.push(nxtC);
				}
			}
		}

		size = jq.size() / 2;
		while (size--)
		{
			int curR = jq.front();
			jq.pop();
			int curC = jq.front();
			jq.pop();
			if (curR == 0 || curR == R - 1 || curC == 0 || curC == C - 1)
			{
				p = true;
				while (!jq.empty()) jq.pop();
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				int nxtR = curR + dr[i];
				int nxtC = curC + dc[i];
				if (0 <= nxtR && nxtR < R && 0 <= nxtC && nxtC < C && arr[nxtR][nxtC] == '.')
				{
					arr[nxtR][nxtC] = 'J';
					jq.push(nxtR);
					jq.push(nxtC);
				}
			}
		}


		
	}
	if (p) cout << t;
	else cout << "IMPOSSIBLE ";
}