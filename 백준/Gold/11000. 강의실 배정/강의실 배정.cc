#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int S, T;
		cin >> S >> T;
		v.push_back({ S, T });
	}

	sort(v.begin(), v.end());
	priority_queue<int> pq;
	int ans = 0;
	for (auto e : v)
	{
		int s = e.first;
		int t = e.second;

		if (!pq.empty() && -pq.top() <= s)
		{
			pq.pop();
		}

		pq.push(-t);
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}