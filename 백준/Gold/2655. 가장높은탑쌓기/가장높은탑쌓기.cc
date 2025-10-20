#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
struct Brick
{
	int n, s, h, w;
	bool operator<(const Brick brick) const
	{
		return brick.s < this->s;
	}
};
Brick bricks[101];
int dp[101];
int parent[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, h, w;
		cin >> s >> h >> w;
		Brick b;
		b.s = s;
		b.h = h;
		b.w = w;
		b.n = i + 1;
		bricks[i] = b;
	}
	sort(bricks, bricks + N);
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < N; i++)
	{
		dp[i] = bricks[i].h;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (bricks[i].w >= bricks[j].w) continue;
			if (dp[j] + bricks[i].h <= dp[i]) continue;
			dp[i] = dp[j] + bricks[i].h;
			parent[i] = j;
		}
	}
	int ans_h = 0, ans_n = 0;
	for (int i = 0; i < N; i++)
	{
		if (ans_h < dp[i])
		{
			ans_h = dp[i];
			ans_n = i;
		}
	}
	vector<int> ans;
	while (ans_n != -1)
	{
		ans.push_back(ans_n);
		ans_n = parent[ans_n];
	}
	cout << ans.size() << "\n";
	for (int i : ans)
	{
		cout << bricks[i].n << "\n";
	}
}