#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, k, ans;
bool line[2][100001];
bool visited[2][100001];

void bfs()
{
	queue<pair<bool, int>> Q;
	Q.push(make_pair(false, 1));
	int time = 1;
	visited[0][1] = true;
	while (!Q.empty())
	{
		int size = Q.size();
		time++;
		while (size--)
		{
			pair<bool, int> cur = Q.front();
			Q.pop();
			bool lr = cur.first;
			int num = cur.second;
			if (num + k > N)
			{
				ans = 1;
				return;
			}
			if (!visited[lr][num + 1] && line[lr][num + 1])
			{
				Q.push(make_pair(lr, num + 1));
				visited[lr][num + 1] = true;
			}
			if (num - 1 >= time && !visited[lr][num - 1] && line[lr][num - 1])
			{
				Q.push(make_pair(lr, num - 1));
				visited[lr][num - 1] = true;
			}
			if (!visited[!lr][num + k] && line[!lr][num + k])
			{
				Q.push(make_pair(!lr, num + k));
				visited[!lr][num + k] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> k;
	string s;
	for (int i = 0; i < 2; i++)
	{
		cin >> s;
		for (int j = 1; j <= N; j++)
		{
			line[i][j] = s.at(j - 1) == '1' ? true : false;
		}
	}

	bfs();
	cout << ans;
}