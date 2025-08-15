#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

struct Edge
{
	int e, v;
	Edge(int e, int v) : e(e), v(v){}
	bool operator<(const Edge edge) const
	{
		return this->v > edge.v;
	}
};

int cost[50'001];
vector<Edge> edges[50'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		edges[s].push_back(Edge(e, v));
		edges[e].push_back(Edge(s, v));
	}
	for (int i = 2; i <= N; i++) cost[i] = 0x3f3f3f3f;

	priority_queue<Edge> pq;
	pq.push(Edge(1, 0));
	while (!pq.empty())
	{
		Edge cur = pq.top(); pq.pop();
		if (cur.v != cost[cur.e]) continue;
		for (Edge nxt : edges[cur.e])
		{
			if (cost[nxt.e] > cost[cur.e] + nxt.v)
			{
				cost[nxt.e] = cost[cur.e] + nxt.v;
				pq.push(Edge(nxt.e, cost[nxt.e]));
			}
		}
	}
	cout << cost[N];
}