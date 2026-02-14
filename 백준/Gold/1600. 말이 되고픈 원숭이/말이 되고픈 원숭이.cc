#include<iostream>
#include <queue>
using namespace std;

int K, W, H;
bool arr[200][200];
int vst[200][200];
int drH[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dcH[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
int drM[] = { -1, 1, 0, 0 };
int dcM[] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> arr[i][j];
			vst[i][j] = 0x3f3f3f3f;
		}
	}

	int cnt = -1;
	queue<int> q;
	q.push(0);
	q.push(0);
	q.push(0);
	vst[0][0] = 0;
	while (!q.empty())
	{
		cnt++;
		int sz = q.size() / 3;
		while (sz--)
		{
			int curR = q.front(); q.pop();
			int curC = q.front(); q.pop();
			int curK = q.front(); q.pop();
			if (curR == H - 1 && curC == W - 1)
			{
				cout << cnt;
				return 0;
			}

			for (int i = 0; i < 4; i++)
			{
				int nxtR = curR + drM[i];
				int nxtC = curC + dcM[i];
				if (0 <= nxtR && nxtR < H && 0 <= nxtC && nxtC < W
					&& arr[nxtR][nxtC] == 0 && vst[nxtR][nxtC] > curK)
				{
					vst[nxtR][nxtC] = curK;
					q.push(nxtR);
					q.push(nxtC);
					q.push(curK);
				}
			}

			if (curK == K)
				continue;

			for (int i = 0; i < 8; i++)
			{
				int nxtR = curR + drH[i];
				int nxtC = curC + dcH[i];
				if (0 <= nxtR && nxtR < H && 0 <= nxtC && nxtC < W
					&& arr[nxtR][nxtC] == 0 && vst[nxtR][nxtC] > curK + 1)
				{
					vst[nxtR][nxtC] = curK + 1;
					q.push(nxtR);
					q.push(nxtC);
					q.push(curK + 1);
				}
			}
		}
	}

	cout << -1;
}