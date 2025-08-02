#include <iostream>
#include <vector>
using namespace std;

vector<int> g[101];
bool visited[101];
int n, p1, p2, m, ans = -1;

void func(int cur, int depth)
{
	if (cur == p2) ans = depth;
	if (ans != -1) return;
	if (visited[cur] == true) return;
	visited[cur] = true;
	for (int nxt : g[cur])
	{
		if (!visited[nxt]) func(nxt, depth + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p1 >> p2 >> m;
	for (int i = 0; i < m; i++)
	{
		int p, c;
		cin >> p >> c;
		g[p].push_back(c);
		g[c].push_back(p);
	}
	func(p1, 0);
	cout << ans;
}