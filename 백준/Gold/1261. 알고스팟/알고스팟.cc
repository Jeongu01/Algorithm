#include <iostream>
#include <deque>
using namespace std;

int N, M;
int arr[100][100];
int cnt[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = s.at(j) - '0';
			cnt[i][j] = -1;
		}
	}
	deque<int> dq;
	dq.push_back(0);
	dq.push_back(0);
	cnt[0][0] = 0;
	while (!dq.empty())
	{
		int curR = dq.front(); dq.pop_front();
		int curC = dq.front(); dq.pop_front();
		int wCnt = cnt[curR][curC];
		if (curR == M - 1 && curC == N - 1) break;
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (0 <= nxtR && nxtR < M && 0 <= nxtC && nxtC < N
				&& cnt[nxtR][nxtC] == -1)
			{
				if (arr[nxtR][nxtC] == 0)
				{
					cnt[nxtR][nxtC] = wCnt;
					dq.push_front(nxtC);
					dq.push_front(nxtR);
				}
				else if (arr[nxtR][nxtC] == 1)
				{
					cnt[nxtR][nxtC] = wCnt + 1;
					dq.push_back(nxtR);
					dq.push_back(nxtC);
				}
			}
		}
	}
	cout << cnt[M - 1][N - 1];
}