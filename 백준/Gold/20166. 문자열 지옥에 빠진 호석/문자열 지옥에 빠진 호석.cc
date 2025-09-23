#include <iostream>
#include <map>
using namespace std;

int N, M, K, len, cnt;
char arr[11][11];
map<string, int> m;
string target;
int dr[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dc[] = { 0, 0, 1, -1, -1, 1, 1, -1 };

void dfs(int r, int c, int depth)
{
	if (arr[r][c] != target.at(depth)) return;
	if (depth == len - 1)
	{
		cnt++;
		return;
	}
	int nxtR, nxtC;
	for (int i = 0; i < 8; i++)
	{
		nxtR = r + dr[i];
		nxtC = c + dc[i];
		if (nxtR == -1) nxtR = N - 1;
		else if (nxtR == N) nxtR = 0;
		if (nxtC == -1) nxtC = M - 1;
		else if (nxtC == M) nxtC = 0;
		dfs(nxtR, nxtC, depth + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (K--)
	{
		cnt = 0;
		cin >> target;
		if (m.find(target) != m.end())
		{
			cout << m[target] << "\n";
			continue;
		}
		len = target.length();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				dfs(i, j, 0);
			}
		}
		cout << cnt << "\n";
		m.insert({ target, cnt });
	}
}