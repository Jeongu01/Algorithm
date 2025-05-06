#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int N, M;
int deg[32001];
vector<int> adj[32001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		deg[B]++;
		adj[A].push_back(B);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (deg[i] == 0) pq.push(i);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		cout << cur << " ";
		pq.pop();
		for (auto nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0) pq.push(nxt);
		}
	}
}