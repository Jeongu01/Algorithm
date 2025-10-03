#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr[1'000'001];
int dp[1'000'001][2];

void dfs(int cur, int parent)
{
	dp[cur][1] = 1;
	for (int nxt : arr[cur])
	{
		if (nxt == parent) continue;
		dfs(nxt, cur);
		dp[cur][0] += dp[nxt][1];
		dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	dfs(1, 0);
	cout << min(dp[1][0], dp[1][1]);
}