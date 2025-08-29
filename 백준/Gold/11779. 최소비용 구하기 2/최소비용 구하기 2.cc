#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N, M;
vector<pair<int, int>> g[1001];
int dist[1001];
int par[1001];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = 0x3f3f3f3f;
		par[i] = -1;
	}

	for (int i = 0; i < M; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		g[s].push_back({ c, e });
	}

	int ts, te;
	cin >> ts >> te;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, ts });
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (cost > dist[cur]) continue;

		for (auto i : g[cur])
		{
			int nxt = i.second;
			int nxtCost = i.first + cost;
			if (dist[nxt] > nxtCost)
			{
				dist[nxt] = nxtCost;
				par[nxt] = cur;
				pq.push({ -nxtCost, nxt });
			}
		}
	}
	stack<int> s;
	int cur = te;
	s.push(cur);
	while (true)
	{
		int nxt = par[cur];
		s.push(nxt);
		if (nxt == ts) break;
		cur = nxt;
	}
	cout << dist[te] << "\n" << s.size() << "\n";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}