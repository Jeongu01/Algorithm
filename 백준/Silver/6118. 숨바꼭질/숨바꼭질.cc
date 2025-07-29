#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans;
vector<int> edges[20'001];
int dist[20'001];

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
		edges[A].push_back(B);
		edges[B].push_back(A);
	}

	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int size = q.size();
		ans++;
		while (size--)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : edges[cur])
			{
				if (dist[nxt] == 0 && nxt != 1)
				{
					dist[nxt] = ans;
					q.push(nxt);
				}
			}
		}
	}
	ans -= 1;
	int num = 0, cnt = 0;;
	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == ans)
		{
			cnt++;
			if (num == 0)
			{
				num = i;
			}
		}
	}
	cout << num << " " << ans << " " << cnt;
}