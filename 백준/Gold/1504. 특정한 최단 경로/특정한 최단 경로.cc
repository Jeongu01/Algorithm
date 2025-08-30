#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, E;
vector<pair<int, int>> g[801];
int dist[3][801], v[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> E;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ c, b });
		g[b].push_back({ c, a });
	}
	v[0] = 1;
	cin >> v[1] >> v[2];

	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < 3; i++)
	{
		pq.push({ 0, v[i]});
		dist[i][v[i]] = 0;
		while (!pq.empty())
		{
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();

			if (cost > dist[i][cur]) continue;

			for (auto n : g[cur])
			{
				int nxt = n.second;
				int nxtCost = n.first + cost;
				if (dist[i][nxt] > nxtCost)
				{
					dist[i][nxt] = nxtCost;
					pq.push({ -nxtCost, nxt });
				}
			}
		}
	}

	int ans = 0x7f7f7f7f;
	if (dist[0][v[1]] != 0x3f3f3f3f && dist[1][v[2]] != 0x3f3f3f3f && dist[2][N] != 0x3f3f3f3f)
	{
		ans = min(ans, dist[0][v[1]] + dist[1][v[2]] + dist[2][N]);
	}
	if (dist[0][v[2]] != 0x3f3f3f3f && dist[1][N] != 0x3f3f3f3f && dist[2][v[1]] != 0x3f3f3f3f)
	{
		ans = min(ans, dist[0][v[2]] + dist[1][N] + dist[2][v[1]]);
	}
	if (ans == 0x7f7f7f7f) ans = -1;
	cout << ans;
}