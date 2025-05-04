#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dist[1001], deg[1001];
vector<int> adj[1001];

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		deg[B]++;
		adj[A].push_back(B);
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		if (deg[i] == 0) Q.push(i);
	}

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (auto nxt : adj[cur])
		{
			deg[nxt]--;
			dist[nxt] = max(dist[nxt], dist[cur] + 1);
			if (deg[nxt] == 0) Q.push(nxt);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << dist[i] + 1 << " ";
	}
}