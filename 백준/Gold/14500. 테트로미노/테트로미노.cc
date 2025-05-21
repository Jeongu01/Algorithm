#include <iostream>
using namespace std;

int N, M, ans;
int arr[500][500];
bool visited[500][500];
int dr[] = { 1, -1, 0 ,0 };
int dc[] = { 0 ,0, 1, -1 };

void func(int r, int c, int depth, int point)
{
	if (depth == 4)
	{
		ans = max(ans, point);
		return;
	}
	visited[r][c] = true;
	for (int i = 0; i < 4; i++)
	{
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		if (0 <= next_r && next_r < N && 0 <= next_c && next_c < M && !visited[next_r][next_c])
		{
			visited[next_r][next_c] = true;
			func(next_r, next_c, depth + 1, point + arr[next_r][next_c]);
			visited[next_r][next_c] = false;
		}
	}
	visited[r][c] = false;
}

void Tfunc(int r, int c)
{
	if (c + 2 < M)
	{
		// ㅗ
		if (0 <= r - 1) ans = max(ans, arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r - 1][c + 1]);
		// ㅜ
		if (r + 1 < N) ans = max(ans, arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 1]);
	}
	if (r + 1 < N && 0 <= c - 1 && c + 1 < M)
	{
		ans = max(ans, arr[r][c] + arr[r + 1][c] + arr[r + 1][c - 1] + arr[r + 1][c + 1]);
		ans = max(ans, arr[r][c] + arr[r + 1][c] + arr[r][c - 1] + arr[r][c + 1]);

	}
	if (0 <= r - 1 && r + 1 < N && c + 1 < M)
	{
		// ㅓ
		ans = max(ans, arr[r][c] + arr[r][c + 1] + arr[r - 1][c + 1] + arr[r + 1][c + 1]);
		// ㅏ
		ans = max(ans, arr[r][c] + arr[r][c + 1] + arr[r - 1][c] + arr[r + 1][c]);
	}
}

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
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			func(i, j, 1, arr[i][j]);
			Tfunc(i, j);
		}
	}

	cout << ans;
}