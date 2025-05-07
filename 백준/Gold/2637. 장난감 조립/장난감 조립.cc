#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int deg[101], need[101][101];
bool basic[101];
vector<int> wrk[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int X, Y, k;
		cin >> X >> Y >> k;
		deg[X]++;
		wrk[Y].push_back(X);
		need[X][Y] = k;
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		if (deg[i] == 0)
		{
			Q.push(i);
			basic[i] = true;
		}
	}

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (auto nxt : wrk[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0) Q.push(nxt);
			int k = need[nxt][cur];
			if (!basic[cur])
			{
				for (int i = 1; i < N; i++)
				{
					need[nxt][i] += need[cur][i] * k;
				}
				need[nxt][cur] = 0;
			}
		}
	}

	for (int i = 1; i < N; i++)
	{
		if (basic[i]) cout << i << " " << need[N][i] << "\n";
	}
}