#include <iostream>
using namespace std;

int N, M;
char arr[500][500];
bool visited[500][500];

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
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == true) continue;
			int r = i, c = j, cnt = 0;
			while (true)
			{
				if (r < 0 || r >= N || c < 0 || c >= M) break;
				if (visited[r][c] == true)
				{
					if (arr[r][c] != 'E') cnt = 0;
					break;
				}
				visited[r][c] = true;
				cnt++;
				if (arr[r][c] == 'U') r--;
				else if (arr[r][c] == 'R') c++;
				else if (arr[r][c] == 'D') r++;
				else if (arr[r][c] == 'L') c--;
			}
			ans += cnt;
			if (cnt == 0) continue;
			r = i, c = j;
			for (int re = 0; re < cnt; re++)
			{
				char dir = arr[r][c];
				arr[r][c] = 'E';
				if (dir == 'U') r--;
				else if (dir == 'R') c++;
				else if (dir == 'D') r++;
				else if (dir == 'L') c--;
			}
		}
	}
	cout << ans;
}