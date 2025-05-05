#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int deg[1001];
vector<int> wrk[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int P; cin >> P;
		int s1, s2;
		cin >> s1;
		for (int i = 1; i < P; i++)
		{
			cin >> s2;
			wrk[s1].push_back(s2);
			deg[s2]++;
			s1 = s2;
		}
	}

	queue<int> Q;
	vector<int> ans;
	for (int i = 1; i <= N; i++)
		if (deg[i] == 0)
		{
			Q.push(i);
			ans.push_back(i);
		}

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (auto nxt : wrk[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0)
			{
				Q.push(nxt);
				ans.push_back(nxt);
			}
		}
	}

	if (ans.size() == N)
		for (auto a : ans)
			cout << a << "\n";
	else
		cout << 0;
}