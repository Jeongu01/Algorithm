#include <iostream>
#include <queue>
using namespace std;

int N, M;
int org[30][30];
int trg[30][30];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			cin >> org[i][j];
	int cpcuR = -1, cpcuC = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> trg[i][j];
			if (trg[i][j] != org[i][j])
			{
				cpcuR = i;
				cpcuC = j;
			}
		}
	}
	if (cpcuR == -1 && cpcuC == -1)
	{
		cout << "YES";
		return 0;
	}
	queue<int> q;
	q.push(cpcuR);
	q.push(cpcuC);
	int tnum = trg[cpcuR][cpcuC], onum = org[cpcuR][cpcuC];
	org[cpcuR][cpcuC] = tnum;
	while (!q.empty())
	{
		int curR = q.front(); q.pop();
		int curC = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < M && org[nxtR][nxtC] == onum)
			{
				org[nxtR][nxtC] = tnum;
				q.push(nxtR);
				q.push(nxtC);
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (trg[i][j] != org[i][j]) flag = false;
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";
}