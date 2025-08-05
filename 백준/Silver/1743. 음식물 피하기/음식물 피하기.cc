#include <iostream>
using namespace std;

int N, M, K, s;
bool arr[101][101];
bool visited[101][101];

void dfs(int r, int c)
{
	if (visited[r][c] == true || arr[r][c] == false) return;
	visited[r][c] = true;
	s++;
	if (r - 1 > 0) dfs(r - 1, c);
	if (r + 1 <= N) dfs(r + 1, c);
	if (c - 1 > 0) dfs(r, c - 1);
	if (c + 1 <= M) dfs(r, c + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		arr[r][c] = true;
	}

	int ans = 0;
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			s = 0;
			if (arr[r][c] == true && visited[r][c] == false)
			{
				dfs(r, c);
				ans = max(ans, s);
			}
		}
	}
	cout << ans;
}