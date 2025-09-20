#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> arr[1001];
int idxs[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input;
			cin >> input;
			arr[i].push_back(input);
		}
		sort(arr[i].begin(), arr[i].end(), greater<int>());
	}
	priority_queue<pair<int, int>> pq;
	int minValue = 1'000'000'000, maxValue = 0;
	for (int i = 0; i < N; i++)
	{
		int value = arr[i][0];
		maxValue = max(maxValue, value);
		minValue = min(minValue, value);
		pq.push({ value, i });
	}
	int ans = maxValue - minValue;
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		int value = cur.first;
		int cls = cur.second;

		int idx = ++idxs[cls];
		if (idx >= M) break;
		int nxtValue = arr[cls][idx];
		pq.push({ nxtValue, cls });

		maxValue = pq.top().first;
		minValue = min(minValue, nxtValue);
		ans = min(ans, maxValue - minValue);
	}
	cout << ans;
}