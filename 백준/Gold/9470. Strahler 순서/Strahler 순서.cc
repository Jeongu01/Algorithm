#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int K, M, P;
		cin >> K >> M >> P;
		
		vector<int> adj[1001];
		int deg[1001] = { 0, };
		int num[1001] = { 0, };
		int cnt[1001] = { 0, };

		for (int p = 0; p < P; p++)
		{
			int A, B;
			cin >> A >> B;
			adj[A].push_back(B);
			deg[B]++;
		}

		queue<int> Q;
		for (int i = 1; i <= M; i++)
		{
			if (deg[i] == 0)
			{
				Q.push(i);
				num[i] = 1;
				cnt[i] = 1;
			}
		}

		while (Q.empty() == false)
		{
			int cur = Q.front();
			Q.pop();
			for (auto nxt : adj[cur])
			{
				if (num[nxt] == num[cur]) cnt[nxt]++;
				else if (num[nxt] < num[cur])
				{
					num[nxt] = num[cur];
					cnt[nxt] = 1;
				}

				deg[nxt]--;
				if (deg[nxt] == 0)
				{
					if (cnt[nxt] > 1) num[nxt]++;
					Q.push(nxt);
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= M; i++)
		{
			ans = max(ans, num[i]);
		}
		cout << K << " " << ans << "\n";
	}

	return 0;
}