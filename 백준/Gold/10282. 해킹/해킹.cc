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
	while (T--)
	{
		int n, d, c;
		cin >> n >> d >> c;
		vector<pair<int, int>> v[10'001];
		int cost[10'001];
		for (int i = 1; i <= n; i++) cost[i] = 0x3f3f3f3f;
		while (d--)
		{
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back(make_pair(a, s));
		}
		queue<int> q;
		q.push(c);

		cost[c] = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto e : v[cur])
			{
				int nxt = e.first;
				int t = e.second;
				if (cost[nxt] > cost[cur] + t)
				{
					cost[nxt] = cost[cur] + t;
					q.push(nxt);
				}
			}
		}
		int cnt = 0, time = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cost[i] != 0x3f3f3f3f)
			{
				cnt++;
				time = max(time, cost[i]);
			}
		}
		cout << cnt << " " << time << "\n";
	}
}