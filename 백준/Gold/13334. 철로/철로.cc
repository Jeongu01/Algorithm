#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int n;
pair<int, int> arr[100'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int h, o;
		cin >> h >> o;
		if (h > o)
		{
			int tmp = h;
			h = o;
			o = tmp;
		}
		arr[i] = { o, h };
	}
	int d;
	cin >> d;
	sort(arr, arr + n);
	int ans = 0, l = -0x3f3f3f3f, r = -0x3f3f3f3f;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int curL = arr[i].second, curR = arr[i].first;
		if (curR - curL > d) continue;
		pq.push(curL);
		if (curR > r)
		{
			r = curR;
			l = r - d;
			while (pq.top() < l)
				pq.pop();
		}
		int cnt = pq.size();
		ans = max(ans, cnt);
	}
	cout << ans;
}