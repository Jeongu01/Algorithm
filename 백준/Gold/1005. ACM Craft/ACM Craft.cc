#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		vector<int> adj[1001];
		int deg[1001] = { 0, };
		int wrk[1001] = { 0, };
		int dis[1001] = { 0, };

		int N, K; cin >> N >> K;
		for (int n = 1; n <= N; n++)
			cin >> wrk[n];
		for (int k = 0; k < K; k++)
		{
			int X, Y; cin >> X >> Y;
			adj[X].push_back(Y);
			deg[Y]++;
		}

		queue<int> Q;
		for (int i = 1; i <= N; i++)
		{
			if (deg[i] == 0) Q.push(i);
		}

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();
			for (auto nxt : adj[cur])
			{
				dis[nxt] = max(dis[nxt], dis[cur] + wrk[cur]);
				if (--deg[nxt] == 0) Q.push(nxt);
			}
		}

		int W; cin >> W;
		cout << dis[W] + wrk[W] << endl;
	}
}