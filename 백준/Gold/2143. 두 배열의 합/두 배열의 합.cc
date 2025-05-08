#include <iostream>
#include <map>

using namespace std;

int T, n, m;
int arr[1001];
int pre[1001];
map<int, int> amap, bmap;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	for (int alen = 1; alen <= n; alen++)
	{
		for (int astart = 0; astart + alen <= n; astart++)
		{
			int a = pre[astart + alen] - pre[astart];
			amap[a]++;
		}
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin>> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	for (int blen = 1; blen <= m; blen++)
	{
		for (int bstart = 0; bstart + blen <= m; bstart++)
		{
			int b = pre[bstart + blen] - pre[bstart];
			bmap[b]++;
		}
	}

	long long ans = 0;
	for (auto a : amap)
	{
		int t1 = a.first;
		int t2 = T - t1;
		ans += (long long) a.second * bmap[t2];
	}

	cout << ans;
}