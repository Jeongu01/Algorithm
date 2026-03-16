#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int arr[51][51];
int dr[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
queue<pair<int, int>> clouds;

void func(int d, int s)
{
	int cloudCnt = clouds.size();
	for (int i = 0; i < cloudCnt; i++)
	{
		auto cloud = clouds.front(); clouds.pop();
		int nxtR = (cloud.first + (dr[d] * s) % N + N - 1) % N + 1;
		int nxtC = (cloud.second + (dc[d] * s) % N + N - 1) % N + 1;
		clouds.push({ nxtR, nxtC });
		arr[nxtR][nxtC]++;
	}
	bool tmp[51][51];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			tmp[i][j] = false;
	for (int i = 0; i < cloudCnt; i++)
	{
		auto cloud = clouds.front(); clouds.pop();
		int r = cloud.first;
		int c = cloud.second;
		tmp[r][c] = true;
		if (r > 1 && c > 1 && arr[r - 1][c - 1] > 0) arr[r][c]++;
		if (r > 1 && c < N && arr[r - 1][c + 1] > 0) arr[r][c]++;
		if (r < N && c > 1 && arr[r + 1][c - 1] > 0) arr[r][c]++;
		if (r < N && c < N && arr[r + 1][c + 1] > 0) arr[r][c]++;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (tmp[i][j] == true) continue;
			if (arr[i][j] < 2) continue;
			clouds.push({ i, j });
			arr[i][j] -= 2;
		}
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
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	clouds.push({ N, 1 });
	clouds.push({ N, 2 });
	clouds.push({ N - 1, 1 });
	clouds.push({ N - 1, 2 });
	while (M--)
	{
		int d, s;
		cin >> d >> s;
		func(d, s);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ans += arr[i][j];
		}
	}
	cout << ans;
}