#include <iostream>
using namespace std;
using ll = long long;
int N;
ll len[100'000], cost[100'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> len[i];
	}
	ll ans = 0;
	cin >> cost[0];
	ans = cost[0] * len[0];
	for (int i = 1; i < N; i++)
	{
		ll c;
		cin >> c;
		cost[i] = cost[i - 1] > c ? c : cost[i - 1];
		ans += cost[i] * len[i];
	}
	cout << ans;
}