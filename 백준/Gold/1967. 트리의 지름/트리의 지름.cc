#include <iostream>
#include <vector>
using namespace std;

int n, maxW, leaf = 1;
vector<pair<int, int>> adj[10'001];
bool visited[10'001];

void func(int node, int w)
{
	if (maxW < w)
	{
		maxW = w;
		leaf = node;
	}
	for (auto nxt : adj[node])
	{
		int nxtNode = nxt.first;
		if (visited[nxtNode] == true) continue;
		int nxtWeight = nxt.second;
		visited[nxtNode] = true;
		func(nxtNode, w + nxtWeight);
		visited[nxtNode] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({ u, w });
		adj[u].push_back({ v, w });
	}
	visited[1] = true;
	func(1, 0);
	visited[1] = false;
	visited[leaf] = true;
	func(leaf, 0);
	visited[leaf] = false;
	cout << maxW;
}